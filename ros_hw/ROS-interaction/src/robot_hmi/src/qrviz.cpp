#include "../include/robot_hmi/qrviz.hpp"

qrviz::qrviz(QVBoxLayout* layout)
{
    //创建rviz panel
    render_panel_ = new rviz::RenderPanel();
    //向layout添加，添加显示容器到ui界面
    layout->addWidget(render_panel_);
    //创建rviz控制对象
    manager_ = new rviz::VisualizationManager(render_panel_);  //官方存在bug
    tool_manager_ = manager_->getToolManager();//将tool_manager看成一个工具箱
    manager_->setFixedFrame("map");
    ROS_ASSERT(manager_!=NULL);

    //初始化render_panel,实现放大缩小等操作
    //需要放在startUpdate前
    render_panel_->initialize(manager_->getSceneManager(),manager_);

    //初始化rviz控制对象
    manager_->initialize();
    manager_->startUpdate();
    manager_->removeAllDisplays();

}
void qrviz::Set_FixedFrame(QString Frame_name)
{
    manager_ ->setFixedFrame(Frame_name);
    qDebug()<<manager_->getFixedFrame();
}
void qrviz::Display_Grid(int Cell_Count,QColor color,bool enable)
{
    //保证图层的唯一性
    if(Grid_!=NULL)
    {
        delete Grid_;
        Grid_=NULL;
    }
    //创建图层
    Grid_= manager_ ->createDisplay("rviz/Grid","myGrid",enable);
    //设置cell Count
    Grid_ ->subProp("Plane Cell Count")->setValue(Cell_Count);
    //设置颜色
    Grid_->subProp("Color")->setValue(color);
    //
    ROS_ASSERT(Grid_!=NULL);
}
void qrviz::Display_TF(bool enable)
{
    //保证图层的唯一性
    if(TF_!=NULL)
    {
        delete TF_;
        TF_=NULL;
    }
    //创建图层
    TF_ = manager_ ->createDisplay("rviz/TF","myTF",enable);
    ROS_ASSERT(TF_!=NULL);
}
void qrviz::Display_LaserScan(QString laser_topic,bool enable)
{
    //保证图层的唯一性
    if(LaserScan_!=NULL)
    {
        delete LaserScan_;
        LaserScan_=NULL;
    }
    //创建图层
    LaserScan_= manager_ ->createDisplay("rviz/LaserScan","myLaser",enable);
    //设置属性
    LaserScan_ ->subProp("Topic")->setValue(laser_topic);
    ROS_ASSERT(LaserScan_!=NULL);
}
void qrviz::Display_RobotModel(bool enable)
{
    //保证图层的唯一性
    if(RobotModel_!=NULL)
    {
        delete RobotModel_;
        RobotModel_=NULL;
    }
    //创建图层
    RobotModel_= manager_ ->createDisplay("rviz/RobotModel","myRobotModel",enable);
    ROS_ASSERT(RobotModel_!=NULL);
}
void qrviz::Display_Map(QString topic,QString color_scheme,bool enable)
{
    if(Map_!=NULL)
    {
        delete Map_;
        Map_=NULL;
    }
    Map_=manager_->createDisplay("rviz/Map","myMap",enable);

    ROS_ASSERT(Map_!=NULL);
    Map_->subProp("Topic")->setValue(topic);//注意引号内大小写、空格格式需要一致
    Map_->subProp("Color Scheme")->setValue(color_scheme);
}
void qrviz::Display_Path(QString topic,QColor color,bool enable)
{
    if(Path_!=NULL)
    {
        delete Path_;
        Path_=NULL;
    }
    Path_=manager_->createDisplay("rviz/Path","myPath",enable);

    ROS_ASSERT(Path_!=NULL);
    Path_->subProp("Topic")->setValue(topic);//注意引号内大小写、空格格式需要一致
    Path_->subProp("Color")->setValue(color);
}
void qrviz::Set_Start_Pose()
{
    rviz::Tool* current_tool_ = tool_manager_->addTool("rviz/SetInitialPose");
    //设置当前使用的工具
    tool_manager_ ->setCurrentTool(current_tool_);
}
void qrviz::Set_Goal_Pose()
{
    rviz::Tool* current_tool_ = tool_manager_->addTool("rviz/SetGoal");
    //获取属性容器
    rviz::Property* pro = current_tool_->getPropertyContainer();
    //设置发布导航目标点的topic
    pro->subProp("Topic")->setValue("/move_base_simple/goal");
    //设置当前使用的工具
    tool_manager_ ->setCurrentTool(current_tool_);
}
void qrviz::Display_Local_Map(QString costmap_Topic,QString cost_map_color,QString path_topic,QColor path_color,bool enable)
{
    if(Local_Map_!=NULL)
    {
        delete Local_Map_;
        Local_Map_=NULL;
    }
    if(Local_Path_!=NULL)
    {
        delete Local_Path_;
        Local_Path_=NULL;
    }
    Local_Map_ = manager_->createDisplay("rviz/Map","localmap",enable);
    ROS_ASSERT(Local_Map_!=NULL);
    Local_Path_ = manager_->createDisplay("rviz/Path","local_planner",enable);
    ROS_ASSERT(Local_Path_!=NULL);
    Local_Map_->subProp("Topic")->setValue(costmap_Topic);
    Local_Map_->subProp("Color Scheme")->setValue(cost_map_color);
    Local_Path_->subProp("Topic")->setValue(path_topic);
   // Local_Path_->subProp("Color")->setValue(path_color);  //更改颜色后会出现bug
}

void qrviz::Display_Global_Map(QString costmap_Topic,QString cost_map_color,QString path_topic,QColor path_color,bool enable)
{
    if(Global_Map_!=NULL)
    {
        delete Global_Map_;
        Global_Map_=NULL;
    }
    if(Global_Path_!=NULL)
    {
        delete Global_Path_;
        Global_Path_=NULL;
    }
    Global_Map_ = manager_->createDisplay("rviz/Map","globalmap",enable);
    ROS_ASSERT(Global_Map_!=NULL);
    Global_Path_ = manager_->createDisplay("rviz/Path","global_planner",enable);
    ROS_ASSERT(Global_Path_!=NULL);
    Global_Map_->subProp("Topic")->setValue(costmap_Topic);
    Global_Map_->subProp("Color Scheme")->setValue(cost_map_color);
    Global_Path_->subProp("Topic")->setValue(path_topic);
  //  Global_Path_->subProp("Color ")->setValue(path_color);
}

