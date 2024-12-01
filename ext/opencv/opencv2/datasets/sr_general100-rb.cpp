#include <opencv2/datasets/sr_general100.hpp>
#include "sr_general100-rb.hpp"

using namespace Rice;

extern "C"
void Init_SrGeneral100()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsSRGeneral100Obj = define_class_under<cv::datasets::SR_general100Obj, cv::datasets::Object>(rb_mCvDatasets, "SRGeneral100Obj").
    define_attr("image_name", &cv::datasets::SR_general100Obj::imageName);
  
  Class rb_cCvDatasetsSRGeneral100 = define_class_under<cv::datasets::SR_general100, cv::datasets::Dataset>(rb_mCvDatasets, "SRGeneral100").
    define_method<void(cv::datasets::SR_general100::*)(const std::basic_string<char>&)>("load", &cv::datasets::SR_general100::load).
    define_singleton_function<cv::Ptr<cv::datasets::SR_general100>(*)()>("create", &cv::datasets::SR_general100::create);
}