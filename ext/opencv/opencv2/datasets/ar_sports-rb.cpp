#include <opencv2/datasets/ar_sports.hpp>
#include "ar_sports-rb.hpp"

using namespace Rice;

extern "C"
void Init_ArSports()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsARSportsObj = define_class_under<cv::datasets::AR_sportsObj, cv::datasets::Object>(rb_mCvDatasets, "ARSportsObj").
    define_attr("video_url", &cv::datasets::AR_sportsObj::videoUrl).
    define_attr("labels", &cv::datasets::AR_sportsObj::labels);
  
  Class rb_cCvDatasetsARSports = define_class_under<cv::datasets::AR_sports, cv::datasets::Dataset>(rb_mCvDatasets, "ARSports").
    define_method<void(cv::datasets::AR_sports::*)(const std::basic_string<char>&)>("load", &cv::datasets::AR_sports::load).
    define_singleton_function<cv::Ptr<cv::datasets::AR_sports>(*)()>("create", &cv::datasets::AR_sports::create);
}