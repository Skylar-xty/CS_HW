/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QTabWidget *tab_manager;
    QWidget *tab_status;
    QGroupBox *groupBox_12;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QListView *view_logging;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QWidget *widget_speed_x;
    QWidget *widget_speed_y;
    QLabel *label_6;
    QLabel *label_dir_x;
    QLabel *label_7;
    QLabel *label_dir_y;
    QWidget *tab;
    QWidget *layoutWidget2;
    QVBoxLayout *Layout_rviz;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *set_start_btn;
    QPushButton *set_goal_btn;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *set_return_pos_btn;
    QPushButton *return_btn;
    QTabWidget *tabWidget;
    QWidget *tab_7;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_4;
    QCheckBox *checkbox_remember_settings;
    QLabel *label_17;
    QCheckBox *checkbox_use_environment;
    QLineEdit *line_edit_master;
    QLabel *label_18;
    QLineEdit *line_edit_topic;
    QLineEdit *line_edit_host;
    QPushButton *button_connect;
    QLabel *label_19;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_u;
    QPushButton *pushButton_i;
    QPushButton *pushButton_o;
    QPushButton *pushButton_l;
    QPushButton *pushButton_dh;
    QCheckBox *checkBox;
    QPushButton *pushButton_j;
    QPushButton *pushButton_d;
    QPushButton *pushButton_m;
    QWidget *layoutWidget_5;
    QFormLayout *formLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_20;
    QSlider *horizontalSlider_linear;
    QLabel *label_linear;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_21;
    QSlider *horizontalSlider_raw;
    QLabel *label_raw;
    QWidget *tab_8;
    QLineEdit *lineEdit;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *send_btn;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTreeWidget *treeWidget;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *label_9;
    QProgressBar *progressBar;
    QLabel *label_10;
    QLabel *label_power_vel;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *return_x;
    QLabel *label_12;
    QLabel *return_y;
    QLabel *label_13;
    QLabel *return_z;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *pos_x;
    QLabel *label_3;
    QLabel *pos_y;
    QLabel *label_5;
    QLabel *pos_z;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1102, 775);
        MainWindowDesign->setMinimumSize(QSize(1000, 500));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tab_manager = new QTabWidget(centralwidget);
        tab_manager->setObjectName(QString::fromUtf8("tab_manager"));
        tab_manager->setGeometry(QRect(-1, -1, 671, 631));
        tab_manager->setMinimumSize(QSize(100, 0));
        tab_manager->setLocale(QLocale(QLocale::English, QLocale::Australia));
        tab_status = new QWidget();
        tab_status->setObjectName(QString::fromUtf8("tab_status"));
        groupBox_12 = new QGroupBox(tab_status);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(0, 9, 641, 671));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_12->sizePolicy().hasHeightForWidth());
        groupBox_12->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(groupBox_12);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 391, 616, 204));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        view_logging = new QListView(layoutWidget);
        view_logging->setObjectName(QString::fromUtf8("view_logging"));

        horizontalLayout_5->addWidget(view_logging);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        horizontalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        layoutWidget1 = new QWidget(groupBox_12);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(31, 31, 608, 331));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_speed_x = new QWidget(layoutWidget1);
        widget_speed_x->setObjectName(QString::fromUtf8("widget_speed_x"));
        widget_speed_x->setMinimumSize(QSize(300, 300));

        gridLayout_2->addWidget(widget_speed_x, 0, 0, 1, 2);

        widget_speed_y = new QWidget(layoutWidget1);
        widget_speed_y->setObjectName(QString::fromUtf8("widget_speed_y"));
        widget_speed_y->setMinimumSize(QSize(300, 300));

        gridLayout_2->addWidget(widget_speed_y, 0, 2, 1, 2);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_dir_x = new QLabel(layoutWidget1);
        label_dir_x->setObjectName(QString::fromUtf8("label_dir_x"));

        gridLayout_2->addWidget(label_dir_x, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 2, 1, 1);

        label_dir_y = new QLabel(layoutWidget1);
        label_dir_y->setObjectName(QString::fromUtf8("label_dir_y"));

        gridLayout_2->addWidget(label_dir_y, 1, 3, 1, 1);

        tab_manager->addTab(tab_status, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        layoutWidget2 = new QWidget(tab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 43, 641, 551));
        Layout_rviz = new QVBoxLayout(layoutWidget2);
        Layout_rviz->setObjectName(QString::fromUtf8("Layout_rviz"));
        Layout_rviz->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(tab);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(11, 11, 641, 35));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        set_start_btn = new QPushButton(layoutWidget3);
        set_start_btn->setObjectName(QString::fromUtf8("set_start_btn"));
        set_start_btn->setMinimumSize(QSize(150, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/cursor_pos.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_start_btn->setIcon(icon1);

        horizontalLayout_2->addWidget(set_start_btn);

        set_goal_btn = new QPushButton(layoutWidget3);
        set_goal_btn->setObjectName(QString::fromUtf8("set_goal_btn"));
        set_goal_btn->setMinimumSize(QSize(150, 0));
        set_goal_btn->setIcon(icon1);

        horizontalLayout_2->addWidget(set_goal_btn);


        horizontalLayout_11->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        set_return_pos_btn = new QPushButton(layoutWidget3);
        set_return_pos_btn->setObjectName(QString::fromUtf8("set_return_pos_btn"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/set_return.png"), QSize(), QIcon::Normal, QIcon::Off);
        set_return_pos_btn->setIcon(icon2);

        horizontalLayout_7->addWidget(set_return_pos_btn);

        return_btn = new QPushButton(layoutWidget3);
        return_btn->setObjectName(QString::fromUtf8("return_btn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        return_btn->setIcon(icon3);

        horizontalLayout_7->addWidget(return_btn);


        horizontalLayout_11->addLayout(horizontalLayout_7);

        tab_manager->addTab(tab, QString());
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(670, 50, 431, 581));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        groupBox_7 = new QGroupBox(tab_7);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 0, 421, 301));
        verticalLayout_6 = new QVBoxLayout(groupBox_7);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        gridLayout_4 = new QGridLayout(groupBox_8);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        checkbox_remember_settings = new QCheckBox(groupBox_8);
        checkbox_remember_settings->setObjectName(QString::fromUtf8("checkbox_remember_settings"));
        checkbox_remember_settings->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(checkbox_remember_settings, 7, 0, 1, 2);

        label_17 = new QLabel(groupBox_8);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFrameShape(QFrame::StyledPanel);
        label_17->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(label_17, 2, 0, 1, 1);

        checkbox_use_environment = new QCheckBox(groupBox_8);
        checkbox_use_environment->setObjectName(QString::fromUtf8("checkbox_use_environment"));
        checkbox_use_environment->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(checkbox_use_environment, 6, 0, 1, 2);

        line_edit_master = new QLineEdit(groupBox_8);
        line_edit_master->setObjectName(QString::fromUtf8("line_edit_master"));

        gridLayout_4->addWidget(line_edit_master, 1, 0, 1, 2);

        label_18 = new QLabel(groupBox_8);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setFrameShape(QFrame::StyledPanel);
        label_18->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(label_18, 0, 0, 1, 1);

        line_edit_topic = new QLineEdit(groupBox_8);
        line_edit_topic->setObjectName(QString::fromUtf8("line_edit_topic"));
        line_edit_topic->setEnabled(false);

        gridLayout_4->addWidget(line_edit_topic, 5, 0, 1, 2);

        line_edit_host = new QLineEdit(groupBox_8);
        line_edit_host->setObjectName(QString::fromUtf8("line_edit_host"));

        gridLayout_4->addWidget(line_edit_host, 3, 0, 1, 2);

        button_connect = new QPushButton(groupBox_8);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy1);

        gridLayout_4->addWidget(button_connect, 9, 1, 1, 1);

        label_19 = new QLabel(groupBox_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setFrameShape(QFrame::StyledPanel);
        label_19->setFrameShadow(QFrame::Raised);

        gridLayout_4->addWidget(label_19, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 10, 0, 1, 1);


        verticalLayout_6->addWidget(groupBox_8);

        pushButton_u = new QPushButton(tab_7);
        pushButton_u->setObjectName(QString::fromUtf8("pushButton_u"));
        pushButton_u->setGeometry(QRect(20, 310, 77, 25));
        pushButton_i = new QPushButton(tab_7);
        pushButton_i->setObjectName(QString::fromUtf8("pushButton_i"));
        pushButton_i->setGeometry(QRect(101, 310, 78, 25));
        pushButton_o = new QPushButton(tab_7);
        pushButton_o->setObjectName(QString::fromUtf8("pushButton_o"));
        pushButton_o->setGeometry(QRect(183, 310, 77, 25));
        pushButton_l = new QPushButton(tab_7);
        pushButton_l->setObjectName(QString::fromUtf8("pushButton_l"));
        pushButton_l->setGeometry(QRect(200, 340, 80, 25));
        pushButton_dh = new QPushButton(tab_7);
        pushButton_dh->setObjectName(QString::fromUtf8("pushButton_dh"));
        pushButton_dh->setGeometry(QRect(101, 370, 78, 25));
        checkBox = new QCheckBox(tab_7);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(104, 340, 92, 29));
        pushButton_j = new QPushButton(tab_7);
        pushButton_j->setObjectName(QString::fromUtf8("pushButton_j"));
        pushButton_j->setGeometry(QRect(20, 340, 80, 25));
        pushButton_d = new QPushButton(tab_7);
        pushButton_d->setObjectName(QString::fromUtf8("pushButton_d"));
        pushButton_d->setGeometry(QRect(183, 370, 77, 25));
        pushButton_m = new QPushButton(tab_7);
        pushButton_m->setObjectName(QString::fromUtf8("pushButton_m"));
        pushButton_m->setGeometry(QRect(20, 370, 77, 25));
        layoutWidget_5 = new QWidget(tab_7);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 400, 171, 71));
        formLayout_3 = new QFormLayout(layoutWidget_5);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_20 = new QLabel(layoutWidget_5);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_8->addWidget(label_20);

        horizontalSlider_linear = new QSlider(layoutWidget_5);
        horizontalSlider_linear->setObjectName(QString::fromUtf8("horizontalSlider_linear"));
        horizontalSlider_linear->setMaximum(100);
        horizontalSlider_linear->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(horizontalSlider_linear);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, horizontalLayout_8);

        label_linear = new QLabel(layoutWidget_5);
        label_linear->setObjectName(QString::fromUtf8("label_linear"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, label_linear);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_21 = new QLabel(layoutWidget_5);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_9->addWidget(label_21);

        horizontalSlider_raw = new QSlider(layoutWidget_5);
        horizontalSlider_raw->setObjectName(QString::fromUtf8("horizontalSlider_raw"));
        horizontalSlider_raw->setMaximum(100);
        horizontalSlider_raw->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_raw);


        formLayout_3->setLayout(1, QFormLayout::LabelRole, horizontalLayout_9);

        label_raw = new QLabel(layoutWidget_5);
        label_raw->setObjectName(QString::fromUtf8("label_raw"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, label_raw);

        tabWidget->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        lineEdit = new QLineEdit(tab_8);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 60, 113, 25));
        label_14 = new QLabel(tab_8);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 60, 111, 17));
        label_15 = new QLabel(tab_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 170, 111, 21));
        send_btn = new QPushButton(tab_8);
        send_btn->setObjectName(QString::fromUtf8("send_btn"));
        send_btn->setGeometry(QRect(310, 60, 89, 25));
        textEdit = new QTextEdit(tab_8);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(170, 170, 231, 211));
        tabWidget->addTab(tab_8, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        treeWidget = new QTreeWidget(tab_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(2, 27, 431, 521));
        treeWidget->header()->setMinimumSectionSize(150);
        treeWidget->header()->setDefaultSectionSize(150);
        layoutWidget4 = new QWidget(tab_2);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(3, 3, 91, 27));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget4);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setMinimumSize(QSize(25, 25));
        label_22->setPixmap(QPixmap(QString::fromUtf8(":/images/display.png")));

        horizontalLayout_10->addWidget(label_22);

        label_23 = new QLabel(layoutWidget4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_10->addWidget(label_23);

        tabWidget->addTab(tab_2, QString());
        layoutWidget_4 = new QWidget(centralwidget);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(670, 20, 308, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        label_9 = new QLabel(layoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(32, 32));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/images/power.png")));

        horizontalLayout->addWidget(label_9);

        progressBar = new QProgressBar(layoutWidget_4);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        horizontalLayout->addWidget(progressBar);

        label_10 = new QLabel(layoutWidget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(32, 32));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/images/power-v.png")));

        horizontalLayout->addWidget(label_10);

        label_power_vel = new QLabel(layoutWidget_4);
        label_power_vel->setObjectName(QString::fromUtf8("label_power_vel"));

        horizontalLayout->addWidget(label_power_vel);

        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(440, 630, 371, 25));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_6->addWidget(label_11);

        return_x = new QLabel(layoutWidget_2);
        return_x->setObjectName(QString::fromUtf8("return_x"));

        horizontalLayout_6->addWidget(return_x);

        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_6->addWidget(label_12);

        return_y = new QLabel(layoutWidget_2);
        return_y->setObjectName(QString::fromUtf8("return_y"));

        horizontalLayout_6->addWidget(return_y);

        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);

        return_z = new QLabel(layoutWidget_2);
        return_z->setObjectName(QString::fromUtf8("return_z"));

        horizontalLayout_6->addWidget(return_z);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 630, 371, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget5);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        label_2 = new QLabel(layoutWidget5);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        pos_x = new QLabel(layoutWidget5);
        pos_x->setObjectName(QString::fromUtf8("pos_x"));

        horizontalLayout_3->addWidget(pos_x);

        label_3 = new QLabel(layoutWidget5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        pos_y = new QLabel(layoutWidget5);
        pos_y->setObjectName(QString::fromUtf8("pos_y"));

        horizontalLayout_3->addWidget(pos_y);

        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        pos_z = new QLabel(layoutWidget5);
        pos_z->setObjectName(QString::fromUtf8("pos_z"));

        horizontalLayout_3->addWidget(pos_z);

        MainWindowDesign->setCentralWidget(centralwidget);
        tabWidget->raise();
        tab_manager->raise();
        layoutWidget_4->raise();
        layoutWidget_2->raise();
        layoutWidget->raise();
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1102, 28));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        tab_manager->setCurrentIndex(0);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", nullptr));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", nullptr));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", nullptr));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", nullptr));
        groupBox_12->setTitle(QApplication::translate("MainWindowDesign", "Logging", nullptr));
        label_6->setText(QApplication::translate("MainWindowDesign", "x\350\275\264\347\272\277\351\200\237\345\272\246", nullptr));
        label_dir_x->setText(QApplication::translate("MainWindowDesign", "\346\255\243\345\220\221", nullptr));
        label_7->setText(QApplication::translate("MainWindowDesign", "y\350\275\264\347\272\277\351\200\237\345\272\246", nullptr));
        label_dir_y->setText(QApplication::translate("MainWindowDesign", "\346\255\243\345\220\221", nullptr));
        tab_manager->setTabText(tab_manager->indexOf(tab_status), QApplication::translate("MainWindowDesign", "Ros Communications", nullptr));
        set_start_btn->setText(QApplication::translate("MainWindowDesign", "2D Pose Estimate", nullptr));
        set_goal_btn->setText(QApplication::translate("MainWindowDesign", "2D Nav Goal", nullptr));
        set_return_pos_btn->setText(QApplication::translate("MainWindowDesign", "\350\256\276\347\275\256\350\277\224\350\210\252\347\202\271", nullptr));
        return_btn->setText(QApplication::translate("MainWindowDesign", "\350\277\224\350\210\252", nullptr));
        tab_manager->setTabText(tab_manager->indexOf(tab), QApplication::translate("MainWindowDesign", "rviz", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindowDesign", "GroupBox", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindowDesign", "Ros Master", nullptr));
        checkbox_remember_settings->setText(QApplication::translate("MainWindowDesign", "Remember settings on startup", nullptr));
        label_17->setText(QApplication::translate("MainWindowDesign", "Ros IP", nullptr));
        checkbox_use_environment->setText(QApplication::translate("MainWindowDesign", "Use environment variables", nullptr));
        line_edit_master->setText(QApplication::translate("MainWindowDesign", "http://192.168.1.2:11311/", nullptr));
        label_18->setText(QApplication::translate("MainWindowDesign", "Ros Master Url", nullptr));
        line_edit_topic->setText(QApplication::translate("MainWindowDesign", "unused", nullptr));
        line_edit_host->setText(QApplication::translate("MainWindowDesign", "192.168.1.67", nullptr));
#ifndef QT_NO_TOOLTIP
        button_connect->setToolTip(QApplication::translate("MainWindowDesign", "Set the target to the current joint trajectory state.", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        button_connect->setStatusTip(QApplication::translate("MainWindowDesign", "Clear all waypoints and set the target to the current joint trajectory state.", nullptr));
#endif // QT_NO_STATUSTIP
        button_connect->setText(QApplication::translate("MainWindowDesign", "Connect", nullptr));
        label_19->setText(QApplication::translate("MainWindowDesign", "Ros Hostname", nullptr));
        pushButton_u->setText(QApplication::translate("MainWindowDesign", "u", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_u->setShortcut(QApplication::translate("MainWindowDesign", "U", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_i->setText(QApplication::translate("MainWindowDesign", "i", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_i->setShortcut(QApplication::translate("MainWindowDesign", "I", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_o->setText(QApplication::translate("MainWindowDesign", "o", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_o->setShortcut(QApplication::translate("MainWindowDesign", "O", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_l->setText(QApplication::translate("MainWindowDesign", "l", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_l->setShortcut(QApplication::translate("MainWindowDesign", "L", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_dh->setText(QApplication::translate("MainWindowDesign", ",", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_dh->setShortcut(QApplication::translate("MainWindowDesign", ",", nullptr));
#endif // QT_NO_SHORTCUT
        checkBox->setText(QApplication::translate("MainWindowDesign", "\345\205\250\345\220\221\350\275\256\346\250\241\345\274\217", nullptr));
        pushButton_j->setText(QApplication::translate("MainWindowDesign", "j", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_j->setShortcut(QApplication::translate("MainWindowDesign", "J", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_d->setText(QApplication::translate("MainWindowDesign", ".", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_d->setShortcut(QApplication::translate("MainWindowDesign", ".", nullptr));
#endif // QT_NO_SHORTCUT
        pushButton_m->setText(QApplication::translate("MainWindowDesign", "m", nullptr));
#ifndef QT_NO_SHORTCUT
        pushButton_m->setShortcut(QApplication::translate("MainWindowDesign", "M", nullptr));
#endif // QT_NO_SHORTCUT
        label_20->setText(QApplication::translate("MainWindowDesign", "\347\272\277\351\200\237\345\272\246:", nullptr));
        label_linear->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label_21->setText(QApplication::translate("MainWindowDesign", "\350\247\222\351\200\237\345\272\246:", nullptr));
        label_raw->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindowDesign", "Main page", nullptr));
        label_14->setText(QApplication::translate("MainWindowDesign", "\350\257\267\350\276\223\345\205\245\347\233\256\346\240\207\347\202\271\357\274\232", nullptr));
        label_15->setText(QApplication::translate("MainWindowDesign", "\345\275\223\345\211\215\347\233\256\346\240\207\347\202\271\345\234\250\357\274\232", nullptr));
        send_btn->setText(QApplication::translate("MainWindowDesign", "\345\217\221\351\200\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_8), QApplication::translate("MainWindowDesign", "Send Target", nullptr));
        label_22->setText(QString());
        label_23->setText(QApplication::translate("MainWindowDesign", "Displays", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowDesign", "rviz", nullptr));
        label_8->setText(QApplication::translate("MainWindowDesign", "\347\224\265\346\261\240\347\224\265\351\207\217\357\274\232", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_power_vel->setText(QApplication::translate("MainWindowDesign", "00.00V", nullptr));
        label_4->setText(QApplication::translate("MainWindowDesign", "\347\233\256\346\240\207\347\202\271\345\235\220\346\240\207\357\274\232", nullptr));
        label_11->setText(QApplication::translate("MainWindowDesign", "X\357\274\232", nullptr));
        return_x->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label_12->setText(QApplication::translate("MainWindowDesign", "Y:", nullptr));
        return_y->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label_13->setText(QApplication::translate("MainWindowDesign", "Z:", nullptr));
        return_z->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label->setText(QApplication::translate("MainWindowDesign", "\345\235\220\346\240\207\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MainWindowDesign", "X\357\274\232", nullptr));
        pos_x->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label_3->setText(QApplication::translate("MainWindowDesign", "Y:", nullptr));
        pos_y->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        label_5->setText(QApplication::translate("MainWindowDesign", "Z:", nullptr));
        pos_z->setText(QApplication::translate("MainWindowDesign", "0", nullptr));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
