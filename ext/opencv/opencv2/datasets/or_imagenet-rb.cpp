#include <opencv2/datasets/or_imagenet.hpp>
#include "or_imagenet-rb.hpp"

using namespace Rice;

extern "C"
void Init_OrImagenet()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsORImagenetObj = define_class_under<cv::datasets::OR_imagenetObj, cv::datasets::Object>(rb_mCvDatasets, "ORImagenetObj").
    define_attr("id", &cv::datasets::OR_imagenetObj::id).
    define_attr("image", &cv::datasets::OR_imagenetObj::image);
  
  Class rb_cCvDatasetsORImagenet = define_class_under<cv::datasets::OR_imagenet, cv::datasets::Dataset>(rb_mCvDatasets, "ORImagenet").
    define_method<void(cv::datasets::OR_imagenet::*)(const std::basic_string<char>&)>("load", &cv::datasets::OR_imagenet::load).
    define_singleton_function<cv::Ptr<cv::datasets::OR_imagenet>(*)()>("create", &cv::datasets::OR_imagenet::create);
}