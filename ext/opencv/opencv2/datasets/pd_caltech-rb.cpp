#include <opencv2/datasets/pd_caltech.hpp>
#include "pd_caltech-rb.hpp"

using namespace Rice;

extern "C"
void Init_PdCaltech()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsPDCaltechObj = define_class_under<cv::datasets::PD_caltechObj, cv::datasets::Object>(rb_mCvDatasets, "PDCaltechObj").
    define_attr("name", &cv::datasets::PD_caltechObj::name).
    define_attr("image_names", &cv::datasets::PD_caltechObj::imageNames);
  
  Class rb_cCvDatasetsPDCaltech = define_class_under<cv::datasets::PD_caltech, cv::datasets::Dataset>(rb_mCvDatasets, "PDCaltech").
    define_method<void(cv::datasets::PD_caltech::*)(const std::basic_string<char>&)>("load", &cv::datasets::PD_caltech::load).
    define_singleton_function<cv::Ptr<cv::datasets::PD_caltech>(*)()>("create", &cv::datasets::PD_caltech::create);
}