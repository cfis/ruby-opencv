#include <opencv2/datasets/ir_robot.hpp>
#include "ir_robot-rb.hpp"

using namespace Rice;

extern "C"
void Init_IrRobot()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsCameraPos = define_class_under<cv::datasets::cameraPos>(rb_mCvDatasets, "CameraPos").
    define_attr("images", &cv::datasets::cameraPos::images);
  
  Class rb_cCvDatasetsIRRobotObj = define_class_under<cv::datasets::IR_robotObj, cv::datasets::Object>(rb_mCvDatasets, "IRRobotObj").
    define_attr("name", &cv::datasets::IR_robotObj::name).
    define_attr("pos", &cv::datasets::IR_robotObj::pos);
  
  Class rb_cCvDatasetsIRRobot = define_class_under<cv::datasets::IR_robot, cv::datasets::Dataset>(rb_mCvDatasets, "IRRobot").
    define_method<void(cv::datasets::IR_robot::*)(const std::basic_string<char>&)>("load", &cv::datasets::IR_robot::load).
    define_singleton_function<cv::Ptr<cv::datasets::IR_robot>(*)()>("create", &cv::datasets::IR_robot::create);
}