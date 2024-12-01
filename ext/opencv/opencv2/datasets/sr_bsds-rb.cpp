#include <opencv2/datasets/sr_bsds.hpp>
#include "sr_bsds-rb.hpp"

using namespace Rice;

extern "C"
void Init_SrBsds()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsSRBsdsObj = define_class_under<cv::datasets::SR_bsdsObj, cv::datasets::Object>(rb_mCvDatasets, "SRBsdsObj").
    define_attr("image_name", &cv::datasets::SR_bsdsObj::imageName);
  
  Class rb_cCvDatasetsSRBsds = define_class_under<cv::datasets::SR_bsds, cv::datasets::Dataset>(rb_mCvDatasets, "SRBsds").
    define_method<void(cv::datasets::SR_bsds::*)(const std::basic_string<char>&)>("load", &cv::datasets::SR_bsds::load).
    define_singleton_function<cv::Ptr<cv::datasets::SR_bsds>(*)()>("create", &cv::datasets::SR_bsds::create);
}