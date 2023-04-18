/**
 * @file /include/class1_ros_qt_demo/main_window.hpp
 *
 * @brief Qt based gui for class1_ros_qt_demo.
 *
 * @date November 2010
 **/

#ifndef robot_hmi_MAIN_WINDOW_H
#define robot_hmi_MAIN_WINDOW_H
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtWidgets/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "CCtrlDashBoard.h"
#include <QComboBox>
#include "qrviz.hpp"
#include <QSpinBox>
#include <QProcess>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <list>
using namespace std;
/*****************************************************************************
** Namespace
*****************************************************************************/

class test
{
private:
    string s,s1;
    string::size_type n;
    ifstream f;
    string::size_type n1,n2;
    string ss2;
    map<string,string>a;
    map<string,string>::iterator p;
public:
    list<double> target;
    list<double>::iterator t_p;
    test();
    ~test();
    string Find(string word);//改造：有返回值
    void Find2(string ss);
    double str2double(string s);
    void browse();
};

namespace robot_hmi{
/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();
    ros::Publisher goal_pub_main;
public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

    //add
    void slot_linear_value_change(int);
    void slot_raw_value_change(int);
    void slot_pushbtn_click();
    void slot_update_dashboard(float,float);

    void slot_treewidget_value_change(QString);
    void slot_display_grid(int);
    void slot_display_tf(int);
    void slot_display_laser(int);
    void slot_display_RobotModel(int);
    void slot_display_Map(int);
    void slot_display_Path(int);

    void slot_set_start_pose();
    void slot_set_goal_pose();

    void slot_display_local_map(int state);
    void slot_display_global_map(int state);

    void slot_update_pose(double,double,double);
    void slot_set_return_pos();
    void slot_return();

    void set_target(list<double>tt);
private slots:
    void on_send_btn_clicked();


private:
	Ui::MainWindowDesign ui;
	QNode qnode;
    CCtrlDashBoard* speed_x_dashBoard;
    CCtrlDashBoard* speed_y_dashBoard;

    qrviz* my_rviz;
    QComboBox* fixed_box;
    QSpinBox* Cell_Count_Box;
    QComboBox* Grid_Color_Box;
    QCheckBox* TF_Check;
    QComboBox* Laser_Topic_box;
    QCheckBox* RobotModel_Check;
    QComboBox* Map_Topic_box ;
    QComboBox* Map_Color_Topic_box;
    QComboBox* Path_Topic_box;
    QComboBox* Path_Color_Topic_box;

    QCheckBox* GlobalMap_Check;
    QComboBox* Global_CostMap_Topic_box;
    QComboBox* GlobalMapColorScheme_box;

    QComboBox* Global_Planner_Topic_box;
    QComboBox* Global_Planner_Color_box;

    QCheckBox* LocalMap_Check;
    QComboBox* Local_CostMap_Topic_box;
    QComboBox* LocalMapColorScheme_box;

    QComboBox* Local_Planner_Topic_box;
    QComboBox* Local_Planner_Color_box;

};


}


#endif
