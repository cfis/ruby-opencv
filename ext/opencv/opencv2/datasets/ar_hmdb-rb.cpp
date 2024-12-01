#include <opencv2/datasets/ar_hmdb.hpp>
#include "ar_hmdb-rb.hpp"

using namespace Rice;

extern "C"
void Init_ArHmdb()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsARHmdbObj = define_class_under<cv::datasets::AR_hmdbObj, cv::datasets::Object>(rb_mCvDatasets, "ARHmdbObj").
    define_attr("id", &cv::datasets::AR_hmdbObj::id).
    define_attr("name", &cv::datasets::AR_hmdbObj::name).
    define_attr("video_name", &cv::datasets::AR_hmdbObj::videoName);
  
  Class rb_cCvDatasetsARHmdb = define_class_under<cv::datasets::AR_hmdb, cv::datasets::Dataset>(rb_mCvDatasets, "ARHmdb").
    define_method<void(cv::datasets::AR_hmdb::*)(const std::basic_string<char>&)>("load", &cv::datasets::AR_hmdb::load).
    define_singleton_function<cv::Ptr<cv::datasets::AR_hmdb>(*)()>("create", &cv::datasets::AR_hmdb::create);
}