#include <opencv2/datasets/msm_epfl.hpp>
#include "msm_epfl-rb.hpp"

using namespace Rice;

extern "C"
void Init_MsmEpfl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsCameraParam = define_class_under<cv::datasets::cameraParam>(rb_mCvDatasets, "CameraParam").
    define_attr("mat1", &cv::datasets::cameraParam::mat1).
    define_attr("mat2", &cv::datasets::cameraParam::mat2).
    define_attr("mat3", &cv::datasets::cameraParam::mat3).
    define_attr("mat4", &cv::datasets::cameraParam::mat4).
    define_attr("image_width", &cv::datasets::cameraParam::imageWidth).
    define_attr("image_height", &cv::datasets::cameraParam::imageHeight);
  
  Class rb_cCvDatasetsMSMEpflObj = define_class_under<cv::datasets::MSM_epflObj, cv::datasets::Object>(rb_mCvDatasets, "MSMEpflObj").
    define_attr("image_name", &cv::datasets::MSM_epflObj::imageName).
    define_attr("bounding", &cv::datasets::MSM_epflObj::bounding).
    define_attr("p", &cv::datasets::MSM_epflObj::p).
    define_attr("camera", &cv::datasets::MSM_epflObj::camera);
  
  Class rb_cCvDatasetsMSMEpfl = define_class_under<cv::datasets::MSM_epfl, cv::datasets::Dataset>(rb_mCvDatasets, "MSMEpfl").
    define_method<void(cv::datasets::MSM_epfl::*)(const std::basic_string<char>&)>("load", &cv::datasets::MSM_epfl::load).
    define_singleton_function<cv::Ptr<cv::datasets::MSM_epfl>(*)()>("create", &cv::datasets::MSM_epfl::create);
}