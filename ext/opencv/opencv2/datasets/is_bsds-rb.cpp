#include <opencv2/datasets/is_bsds.hpp>
#include "is_bsds-rb.hpp"

using namespace Rice;

extern "C"
void Init_IsBsds()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsISBsdsObj = define_class_under<cv::datasets::IS_bsdsObj, cv::datasets::Object>(rb_mCvDatasets, "ISBsdsObj").
    define_attr("name", &cv::datasets::IS_bsdsObj::name);
  
  Class rb_cCvDatasetsISBsds = define_class_under<cv::datasets::IS_bsds, cv::datasets::Dataset>(rb_mCvDatasets, "ISBsds").
    define_method<void(cv::datasets::IS_bsds::*)(const std::basic_string<char>&)>("load", &cv::datasets::IS_bsds::load).
    define_singleton_function<cv::Ptr<cv::datasets::IS_bsds>(*)()>("create", &cv::datasets::IS_bsds::create);
}