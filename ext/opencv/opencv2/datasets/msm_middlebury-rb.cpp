#include <opencv2/datasets/msm_middlebury.hpp>
#include "msm_middlebury-rb.hpp"

using namespace Rice;

extern "C"
void Init_MsmMiddlebury()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsMSMMiddleburyObj = define_class_under<cv::datasets::MSM_middleburyObj, cv::datasets::Object>(rb_mCvDatasets, "MSMMiddleburyObj").
    define_attr("image_name", &cv::datasets::MSM_middleburyObj::imageName).
    define_attr("k", &cv::datasets::MSM_middleburyObj::k).
    define_attr("r", &cv::datasets::MSM_middleburyObj::r).
    define_attr("t", &cv::datasets::MSM_middleburyObj::t);
  
  Class rb_cCvDatasetsMSMMiddlebury = define_class_under<cv::datasets::MSM_middlebury, cv::datasets::Dataset>(rb_mCvDatasets, "MSMMiddlebury").
    define_method<void(cv::datasets::MSM_middlebury::*)(const std::basic_string<char>&)>("load", &cv::datasets::MSM_middlebury::load).
    define_singleton_function<cv::Ptr<cv::datasets::MSM_middlebury>(*)()>("create", &cv::datasets::MSM_middlebury::create);
}