#include <opencv2/datasets/or_sun.hpp>
#include "or_sun-rb.hpp"

using namespace Rice;

extern "C"
void Init_OrSun()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsORSunObj = define_class_under<cv::datasets::OR_sunObj, cv::datasets::Object>(rb_mCvDatasets, "ORSunObj").
    define_attr("label", &cv::datasets::OR_sunObj::label).
    define_attr("name", &cv::datasets::OR_sunObj::name);
  
  Class rb_cCvDatasetsORSun = define_class_under<cv::datasets::OR_sun, cv::datasets::Dataset>(rb_mCvDatasets, "ORSun").
    define_method<void(cv::datasets::OR_sun::*)(const std::basic_string<char>&)>("load", &cv::datasets::OR_sun::load).
    define_singleton_function<cv::Ptr<cv::datasets::OR_sun>(*)()>("create", &cv::datasets::OR_sun::create).
    define_attr("paths", &cv::datasets::OR_sun::paths);
}