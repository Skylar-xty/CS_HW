/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/robot_hmi/main_window.hpp"
#include <QComboBox>
/*****************************************************************************
** Namespaces
*****************************************************************************/

// namespace class1_ros_qt_demo {
namespace robot_hmi{
using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
	ui.view_logging->setModel(qnode.loggingModel());
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }

    //add
    connect(ui.horizontalSlider_linear,SIGNAL(valueChanged(int)),this,SLOT(slot_linear_value_change(int)));
    connect(ui.horizontalSlider_raw,SIGNAL(valueChanged(int)),this,SLOT(slot_raw_value_change(int)));

    connect(ui.pushButton_i,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_j,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_l,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_m,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_dh,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_d,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_u,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));
    connect(ui.pushButton_o,SIGNAL(clicked()),this,SLOT(slot_pushbtn_click()));

    connect(&qnode,SIGNAL(speed_vel(float,float)),this,SLOT(slot_update_dashboard(float,float)));


    //init ui
    speed_x_dashBoard = new CCtrlDashBoard(ui.widget_speed_x);
    speed_y_dashBoard = new CCtrlDashBoard(ui.widget_speed_y);
    speed_x_dashBoard->setGeometry(ui.widget_speed_x->rect()); //dashBoard大小和widget相同
    speed_y_dashBoard->setGeometry(ui.widget_speed_y->rect());
    speed_x_dashBoard->setValue(0);
    speed_y_dashBoard->setValue(0);

    ///header
    ui.treeWidget->setHeaderLabels(QStringList()<<"key"<<"value");
    ////不将header隐藏
    ui.treeWidget->setHeaderHidden(false);

    ///Global options
    QTreeWidgetItem* Global = new QTreeWidgetItem(QStringList()<<"Global Options");
    Global->setIcon(0,QIcon("://images/options.png"));

    ui.treeWidget->addTopLevelItem(Global);
    Global->setExpanded(true);   //设置成展开状态

    ///FixFrame
    ///
    QTreeWidgetItem* Fixed_frame = new QTreeWidgetItem(QStringList()<<"Fixed Frame");
    fixed_box = new QComboBox();

    fixed_box->addItem("map");
    fixed_box->setMaximumWidth(150);
    fixed_box->setEditable(true);
    //按F1查看帮助文档
    connect(fixed_box,SIGNAL(currentTextChanged(QString)),this,SLOT(slot_treewidget_value_change(QString)));

    ///将Fixed Frame作为Global options的子结点
    Global->addChild(Fixed_frame);
    ui.treeWidget->setItemWidget(Fixed_frame,1,fixed_box);

    //Grid
    QTreeWidgetItem* Grid = new QTreeWidgetItem(QStringList()<<"Grid");
    //设置图标
    Grid->setIcon(0,QIcon("://images/grid.png"));

    //checkbox
    QCheckBox* Grid_Check= new QCheckBox();
    //添加top节点
    ui.treeWidget->addTopLevelItem(Grid);
    //添加checkbox
    ui.treeWidget->setItemWidget(Grid,1,Grid_Check);
    //设置grid默认展开状态
    Grid->setExpanded(true);

    //添加Cell Count子结点
    QTreeWidgetItem* Cell_Count = new QTreeWidgetItem(QStringList()<<"Plane Cell Count");
    Grid->addChild(Cell_Count);

    //
    Cell_Count_Box=new QSpinBox();
    Cell_Count_Box->setValue(13);
    //设置Spinbox的宽度
    Cell_Count_Box->setMaximumWidth(150);
    ui.treeWidget->setItemWidget(Cell_Count,1,Cell_Count_Box);
    //添加color子结点
    QTreeWidgetItem* Grid_Color = new QTreeWidgetItem(QStringList()<<"Color");
    Grid->addChild(Grid_Color);
    //color添加ComboBox
    Grid_Color_Box = new QComboBox();
    Grid_Color_Box->addItem("160;160;160");
    //设置ComboBox可编辑
    Grid_Color_Box->setEditable(true);
    //设置ComboBox的宽度
    Grid_Color_Box->setMaximumWidth(150);
    ui.treeWidget->setItemWidget(Grid_Color,1,Grid_Color_Box);

    //checkbox
    //QCheckBox* Grid_Check = new QCheckBox();
    connect(Grid_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_grid(int)));

    //TF ui
    QTreeWidgetItem* TF = new QTreeWidgetItem(QStringList()<<"TF");
    //设置图标
    TF->setIcon(0,QIcon("://images/TF.png"));
    //checkbox
    TF_Check = new QCheckBox();
    connect(TF_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_tf(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(TF);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(TF,1,TF_Check);

    //laserScan
    QTreeWidgetItem* LaserScan = new QTreeWidgetItem(QStringList()<<"LaserScan");
    //设置图标
    LaserScan->setIcon(0,QIcon("://images/LaserScan.png"));
    //checkbox
    QCheckBox* Laser_Check = new QCheckBox();
    connect(Laser_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_laser(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(LaserScan);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(LaserScan,1,Laser_Check);
    //laser topic
    QTreeWidgetItem* LaserTopic = new QTreeWidgetItem(QStringList()<<"Topic");
    Laser_Topic_box = new QComboBox();
    Laser_Topic_box -> addItem("/scan");
    Laser_Topic_box -> setEditable(true);
    Laser_Topic_box ->setMaximumWidth(150);
    LaserScan ->addChild(LaserTopic);
    ui.treeWidget->setItemWidget(LaserTopic,1,Laser_Topic_box);

    //RobotModel
    QTreeWidgetItem* RobotModel= new QTreeWidgetItem(QStringList()<<"RobotModel");
    //设置图标
    RobotModel->setIcon(0,QIcon("://images/RobotModel.png"));
    //checkbox
    RobotModel_Check = new QCheckBox();
    connect(RobotModel_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_RobotModel(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(RobotModel);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(RobotModel,1,RobotModel_Check);

    //Map
    QTreeWidgetItem* Map= new QTreeWidgetItem(QStringList()<<"Map");
    //设置图标
    Map->setIcon(0,QIcon("://images/Map.png"));
    //checkbox
    QCheckBox* Map_Check = new QCheckBox();
    connect(Map_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Map(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(Map);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(Map,1,Map_Check);
    //Map topic
    QTreeWidgetItem* MapTopic = new QTreeWidgetItem(QStringList()<<"Topic");
    Map_Topic_box = new QComboBox();
    Map_Topic_box -> addItem("/map");
    Map_Topic_box -> setEditable(true);
    Map_Topic_box ->setMaximumWidth(150);
    Map ->addChild(MapTopic);
    ui.treeWidget->setItemWidget(MapTopic,1,Map_Topic_box);
    //Map color scheme
    QTreeWidgetItem* MapColorScheme = new QTreeWidgetItem(QStringList()<<"Color Scheme");
    Map_Color_Topic_box = new QComboBox();
    Map_Color_Topic_box -> addItem("map");
    Map_Color_Topic_box -> addItem("costmap");
    Map_Color_Topic_box -> addItem("raw");
    Map_Color_Topic_box -> setMaximumWidth(150);
    Map ->addChild(MapColorScheme);
    ui.treeWidget->setItemWidget(MapColorScheme,1,Map_Color_Topic_box);

    //Path
    QTreeWidgetItem* Path= new QTreeWidgetItem(QStringList()<<"Path");
    //设置图标
    Path->setIcon(0,QIcon("://images/Path.png"));
    //checkbox
    QCheckBox* Path_Check = new QCheckBox();
    connect(Path_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_Path(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(Path);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(Path,1,Path_Check);
    //Map topic
    QTreeWidgetItem* PathTopic = new QTreeWidgetItem(QStringList()<<"Topic");
    Path_Topic_box = new QComboBox();
    Path_Topic_box -> addItem("/move_base/DWAPlannerROS/local_plan");
    Path_Topic_box -> setEditable(true);
    Path_Topic_box ->setMaximumWidth(150);
    Path ->addChild(PathTopic);
    ui.treeWidget->setItemWidget(PathTopic,1,Path_Topic_box);
    //Path color scheme
    QTreeWidgetItem* PathColorTopic = new QTreeWidgetItem(QStringList()<<"Color");
    Path_Color_Topic_box = new QComboBox();
    Path_Color_Topic_box -> addItem("0;12;255");
    Path_Color_Topic_box -> setEditable(true);
    Path_Color_Topic_box -> setMaximumWidth(150);
    Path ->addChild(PathColorTopic);
    ui.treeWidget->setItemWidget(PathColorTopic,1,Path_Color_Topic_box);

    //set start pose
    connect(ui.set_start_btn,SIGNAL(clicked()),this,SLOT(slot_set_start_pose()));
    connect(ui.set_goal_btn,SIGNAL(clicked()),this,SLOT(slot_set_goal_pose()));

    //机器人navigate相关ui
    //Global Map
    QTreeWidgetItem* GlobalMap= new QTreeWidgetItem(QStringList()<<"Global Map");
    //设置图标
    GlobalMap->setIcon(0,QIcon("://images/default_package_icon.png"));
    //checkbox
    GlobalMap_Check = new QCheckBox();
    connect(GlobalMap_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_global_map(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(GlobalMap);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(GlobalMap,1,GlobalMap_Check);

    //Global CostMap
    QTreeWidgetItem* Global_CostMap= new QTreeWidgetItem(QStringList()<<"Costmap");
    //设置图标
    Global_CostMap->setIcon(0,QIcon("://images/Map.png"));
    //Global Map 添加子结点
    GlobalMap->addChild(Global_CostMap);
    //Map topic
    QTreeWidgetItem* Global_CostMap_Topic = new QTreeWidgetItem(QStringList()<<"Topic");
    Global_CostMap_Topic_box = new QComboBox();
    Global_CostMap_Topic_box -> addItem("/move_base/global_costmap/costmap");
    Global_CostMap_Topic_box -> setEditable(true);
    Global_CostMap_Topic_box ->setMaximumWidth(150);
    Global_CostMap->addChild(Global_CostMap_Topic);
    ui.treeWidget->setItemWidget(Global_CostMap_Topic,1,Global_CostMap_Topic_box);
    //Map color scheme
    QTreeWidgetItem* GlobalMapColorTopic = new QTreeWidgetItem(QStringList()<<"Color Scheme");
    GlobalMapColorScheme_box = new QComboBox();
    GlobalMapColorScheme_box -> addItem("costmap");
    GlobalMapColorScheme_box -> addItem("map");
    GlobalMapColorScheme_box -> addItem("raw");
    GlobalMapColorScheme_box -> setMaximumWidth(150);
    Global_CostMap ->addChild(GlobalMapColorTopic);
    ui.treeWidget->setItemWidget(GlobalMapColorTopic,1,GlobalMapColorScheme_box);

    //Globalplanner
    //Path
    QTreeWidgetItem* Global_Planner= new QTreeWidgetItem(QStringList()<<"Planner");
    //设置图标
    Global_Planner->setIcon(0,QIcon("://images/Path.png"));
    //向Global Map添加Path Top节点
    GlobalMap->addChild(Global_Planner);
    //Path topic
    QTreeWidgetItem* Global_Planner_Topic = new QTreeWidgetItem(QStringList()<<"Topic");
    Global_Planner_Topic_box = new QComboBox();
    Global_Planner_Topic_box -> addItem("/move_base/DWAPlannerROS/global_plan");
    Global_Planner_Topic_box -> setEditable(true);
    Global_Planner_Topic_box ->setMaximumWidth(150);
    Global_Planner->addChild(Global_Planner_Topic);
    ui.treeWidget->setItemWidget(Global_Planner_Topic,1,Global_Planner_Topic_box);
    //Path color scheme
    QTreeWidgetItem* Global_Planner_Color_Scheme = new QTreeWidgetItem(QStringList()<<"Color");
    Global_Planner_Color_box = new QComboBox();
    Global_Planner_Color_box -> addItem("255;0;0");
    Global_Planner_Color_box -> setEditable(true);
    Global_Planner_Color_box -> setMaximumWidth(150);
    Global_Planner->addChild(Global_Planner_Color_Scheme);
    ui.treeWidget->setItemWidget(Global_Planner_Color_Scheme,1,Global_Planner_Color_box);

    //Local Map
    QTreeWidgetItem* LocalMap= new QTreeWidgetItem(QStringList()<<"Local Map");
    //设置图标
    LocalMap->setIcon(0,QIcon("://images/default_package_icon.png"));
    //checkbox
    LocalMap_Check = new QCheckBox();
    connect(LocalMap_Check,SIGNAL(stateChanged(int)),this,SLOT(slot_display_local_map(int)));
    //向Treewidget添加TF top节点
    ui.treeWidget->addTopLevelItem(LocalMap);
    //向TF添加checkbox
    ui.treeWidget->setItemWidget(LocalMap,1,LocalMap_Check);


    //Local CostMap
    QTreeWidgetItem* Local_CostMap= new QTreeWidgetItem(QStringList()<<"Costmap");
    //设置图标
    Local_CostMap->setIcon(0,QIcon("://images/Map.png"));
    //Global Map 添加子结点
    LocalMap->addChild(Local_CostMap);
    //Map topic
    QTreeWidgetItem* Local_CostMap_Topic = new QTreeWidgetItem(QStringList()<<"Topic");
    Local_CostMap_Topic_box = new QComboBox();
    Local_CostMap_Topic_box -> addItem("/move_base/local_costmap/costmap");
    Local_CostMap_Topic_box -> setEditable(true);
    Local_CostMap_Topic_box ->setMaximumWidth(150);
    Local_CostMap->addChild(Local_CostMap_Topic);
    ui.treeWidget->setItemWidget(Local_CostMap_Topic,1,Local_CostMap_Topic_box);
    //Map color scheme
    QTreeWidgetItem* LocalMapColorTopic = new QTreeWidgetItem(QStringList()<<"Color Scheme");
    LocalMapColorScheme_box = new QComboBox();
    LocalMapColorScheme_box -> addItem("costmap");
    LocalMapColorScheme_box -> addItem("map");
    LocalMapColorScheme_box -> addItem("raw");
    LocalMapColorScheme_box -> setMaximumWidth(150);
    Local_CostMap ->addChild(LocalMapColorTopic);
    ui.treeWidget->setItemWidget(LocalMapColorTopic,1,LocalMapColorScheme_box);

    //local planner
    //Globalplanner
    //Path
    QTreeWidgetItem*  Local_Planner= new QTreeWidgetItem(QStringList()<<"Planner");
    //设置图标
    Local_Planner->setIcon(0,QIcon("://images/Path.png"));
    //向Global Map添加Path Top节点
    LocalMap->addChild(Local_Planner);
    //Path topic
    QTreeWidgetItem* Local_Planner_Topic = new QTreeWidgetItem(QStringList()<<"Topic");
    Local_Planner_Topic_box = new QComboBox();
    Local_Planner_Topic_box -> addItem("/move_base/DWAPlannerROS/local_plan");
    Local_Planner_Topic_box -> setEditable(true);
    Local_Planner_Topic_box ->setMaximumWidth(150);
    Local_Planner->addChild(Local_Planner_Topic);
    ui.treeWidget->setItemWidget(Local_Planner_Topic,1,Local_Planner_Topic_box);
    //Path color scheme
    QTreeWidgetItem* Local_Planner_Color_Scheme = new QTreeWidgetItem(QStringList()<<"Color");
    Local_Planner_Color_box = new QComboBox();
    Local_Planner_Color_box -> addItem("255;0;0");
    Local_Planner_Color_box -> setEditable(true);
    Local_Planner_Color_box -> setMaximumWidth(150);
    Local_Planner->addChild(Local_Planner_Color_Scheme);
    ui.treeWidget->setItemWidget(Local_Planner_Color_Scheme,1,Local_Planner_Color_box);

    connect(&qnode,SIGNAL(position(double,double,double)),this,SLOT(slot_update_pose(double,double,double)));

    connect(ui.set_return_pos_btn,SIGNAL(clicked()),this,SLOT(slot_set_return_pos()));
    connect(ui.return_btn,SIGNAL(clicked()),this,SLOT(slot_return()));

}
void MainWindow::slot_set_return_pos()
{
    ui.return_x->setText(ui.return_x->text());
    ui.return_y->setText(ui.return_y->text());
    ui.return_z->setText(ui.return_z->text());
}

void MainWindow::slot_return()
{
    qnode.set_goal(ui.return_x->text().toDouble(),ui.return_y->text().toDouble(),ui.return_z->text().toDouble());
}
void MainWindow::slot_update_pose(double x,double y,double z)
{
    //更新ui显示
    ui.pos_x ->setText(QString::number(x));
    ui.pos_y ->setText(QString::number(y));
    ui.pos_z ->setText(QString::number(z));
}
void MainWindow::slot_display_local_map(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Local_Planner_Color_box->currentText().split(";");
    QColor color = QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    my_rviz->Display_Local_Map(Local_CostMap_Topic_box->currentText(),LocalMapColorScheme_box->currentText(),Local_Planner_Topic_box->currentText(),color,enable);
}
void MainWindow::slot_display_global_map(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Global_Planner_Color_box->currentText().split(";");
    QColor color = QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    my_rviz->Display_Global_Map(Global_CostMap_Topic_box->currentText(),GlobalMapColorScheme_box->currentText(),Global_Planner_Topic_box->currentText(),color,enable);
}


void MainWindow::slot_set_start_pose()
{
    my_rviz->Set_Start_Pose();
}
void MainWindow::slot_set_goal_pose()
{
    my_rviz->Set_Goal_Pose();
}
void MainWindow::slot_display_Path(int state)
{
    bool enable = state>1?true:false;
    QStringList qli=Path_Color_Topic_box->currentText().split(";");
    QColor color = QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    my_rviz->Display_Path(Path_Topic_box->currentText(),color,enable);
}
void MainWindow::slot_display_Map(int state)
{
    bool enable = state>1?true:false;
    my_rviz->Display_Map(Map_Topic_box->currentText(),Map_Color_Topic_box->currentText(),enable);
}
void MainWindow::slot_display_RobotModel(int state)
{
    bool enable = state>1?true:false;
    my_rviz ->Display_RobotModel(enable);
}
void MainWindow::slot_display_laser(int state)
{
    bool enable=state>1?true:false;
    my_rviz->Display_LaserScan(Laser_Topic_box->currentText(),enable);
}
void MainWindow::slot_display_tf(int state)
{
    bool enable = state>1?true:false;
    my_rviz->Display_TF(enable);
}
void MainWindow::slot_display_grid(int state)
{
    bool enable=state>1?true:false;
    QStringList qli=Grid_Color_Box->currentText().split(";");
    QColor color = QColor(qli[0].toInt(),qli[1].toInt(),qli[2].toInt());
    my_rviz->Display_Grid(Cell_Count_Box->text().toInt(),color,enable);
}
void MainWindow::slot_treewidget_value_change(QString)
{
    my_rviz->Set_FixedFrame(fixed_box->currentText());
}
void MainWindow::slot_update_dashboard(float x,float y)
{
    //设置正反向：
    ui.label_dir_x->setText(x>0?"正向":"反向");
    ui.label_dir_y->setText(y>0?"正向":"反向");
    speed_x_dashBoard->setValue(abs(x)*100);//单位转换
    speed_y_dashBoard->setValue(abs(y)*100);
}

void MainWindow::slot_linear_value_change(int value)
{
    ui.label_linear->setText(QString::number(value));
}
void MainWindow::slot_raw_value_change(int value)
{
    ui.label_raw->setText(QString::number(value));
}
void MainWindow::slot_pushbtn_click()
{
    QPushButton* btn=qobject_cast<QPushButton*> (sender());
    qDebug()<<btn->text();
    //
    char k = btn->text().toStdString()[0];
    bool is_all = ui.checkBox->isChecked();
    float linear = ui.label_linear->text().toFloat()*0.01;
    float angular = ui.label_raw->text().toFloat()*0.01;

    switch(k){
        case 'i':
            qnode.set_cmd_vel(is_all?'I':'i',linear,angular);
            break;
        case 'u':
            qnode.set_cmd_vel(is_all?'U':'u',linear,angular);
            break;
        case 'o':
            qnode.set_cmd_vel(is_all?'O':'o',linear,angular);
            break;
        case 'j':
            qnode.set_cmd_vel(is_all?'J':'j',linear,angular);
            break;
        case 'l':
            qnode.set_cmd_vel(is_all?'L':'l',linear,angular);
            break;
        case 'm':
            qnode.set_cmd_vel(is_all?'M':'m',linear,angular);
            break;
        case ',':
            qnode.set_cmd_vel(is_all?'<':',',linear,angular);
            break;
        case '.':
            qnode.set_cmd_vel(is_all?'>':'.',linear,angular);
            break;
        }

}
MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
            ui.treeWidget->setEnabled(true);
            my_rviz = new qrviz(ui.Layout_rviz);
        }
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
            ui.treeWidget->setEnabled(true);
            my_rviz = new qrviz(ui.Layout_rviz);
		}
	}
}


void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    // QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
	QSettings settings("Qt-Ros Package","robot_hmi");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    // QSettings settings("Qt-Ros Package", "class1_ros_qt_demo");
	QSettings settings("Qt-Ros Package", "robot_hmi");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}

//===================================
test::test()
{
    f.open("/home/skylar-xty/Add_Pan/ROS1/ROS--interaction-software-development/ROS-interaction/src/robot_hmi/resources/goal.txt",ios::in);
    if(!f) cout<<"file open error!"<<endl;
    else
    {
        while(!f.eof())
        {
            getline(f,s);
            n=s.find(" ",0);
            s1=s.substr(0,n);
            a.insert(pair<string,string>(s1,s));
        }
    }
}
test::~test()
{
    f.close();
}
string test::Find(string word)//改造：有返回值
{
    string temp;
    p=a.find(word);
    if(p!=a.end())
        temp=p->second;
    else
        temp="no word!";
    return temp;
}
double test::str2double(string s)
{
    double temp;
    stringstream ss;
    //===========转换过程============
    ss<<s;
    ss>>temp;
    return temp;
}
void test::Find2(string ss)
{
    string temp = ",";
    int pos = 0;
    while(true)
    {
        double loc;
        if(ss.find(temp,pos)!=string::npos)
        {
            n1 = ss.find(temp,pos);
            n2 = ss.find(temp,n1+1);
            ss2 = ss.substr(n1+1,n2-n1-1);
            loc = str2double(ss2);
            target.push_back(loc);
            pos = n2;
            if(pos+1>=ss.size())break;
        }
        else break;
    }
}
void test::browse()
{
    for(t_p=target.begin();t_p!=target.end();t_p++)
    {
        cout<<*t_p<<',';
    }
}
string qstr2cstr(QString qs)
{
    QByteArray cdata = qs.toLocal8Bit();
    return string(cdata);
}
QString cstr2qstr(string cs)
{
    return QString::fromLocal8Bit(cs.data());
}
void robot_hmi::MainWindow::set_target(list<double>tt)
{
    int cnt;
    double x,y,z;
    list<double>::iterator t_p;
    for(t_p=tt.begin(),cnt=0;cnt<3;cnt++,t_p++)
    {

        switch(cnt){
        case 0:
            x=*(t_p);
            ui.return_x->setText(QString::number(x));
            break;
        case 1:
            y=*(t_p);
            ui.return_y->setText(QString::number(y));
            break;
        case 2:
            z=*(t_p);
            ui.return_z->setText(QString::number(z));
            break;
        default:
            break;
        }
    }
    cout<<"Let set_goal!"<<endl;
    qnode.set_goal(x,y,z);
}
void robot_hmi::MainWindow::on_send_btn_clicked()
{
    QString qs;
    qs=ui.lineEdit->text();
    string s;
    s=qstr2cstr(qs);
    test t;
    s=t.Find(s);
    //cout<<s<<endl;
    t.Find2(s);
    cout<<"find"<<endl;
    t.browse();
    cout<<"browse"<<endl;
    set_target(t.target);
    qs=cstr2qstr(s);
    ui.textEdit->setText(qs);
}
