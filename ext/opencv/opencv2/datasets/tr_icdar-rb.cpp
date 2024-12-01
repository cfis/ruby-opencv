#include <opencv2/datasets/tr_icdar.hpp>
#include "tr_icdar-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrIcdar()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsWord = define_class_under<cv::datasets::word>(rb_mCvDatasets, "Word").
    define_attr("value", &cv::datasets::word::value).
    define_attr("height", &cv::datasets::word::height).
    define_attr("width", &cv::datasets::word::width).
    define_attr("x", &cv::datasets::word::x).
    define_attr("y", &cv::datasets::word::y);
  
  Class rb_cCvDatasetsTRIcdarObj = define_class_under<cv::datasets::TR_icdarObj, cv::datasets::Object>(rb_mCvDatasets, "TRIcdarObj").
    define_attr("file_name", &cv::datasets::TR_icdarObj::fileName).
    define_attr("lex100", &cv::datasets::TR_icdarObj::lex100).
    define_attr("lex_full", &cv::datasets::TR_icdarObj::lexFull).
    define_attr("words", &cv::datasets::TR_icdarObj::words);
  
  Class rb_cCvDatasetsTRIcdar = define_class_under<cv::datasets::TR_icdar, cv::datasets::Dataset>(rb_mCvDatasets, "TRIcdar").
    define_method<void(cv::datasets::TR_icdar::*)(const std::basic_string<char>&)>("load", &cv::datasets::TR_icdar::load).
    define_singleton_function<cv::Ptr<cv::datasets::TR_icdar>(*)()>("create", &cv::datasets::TR_icdar::create);
}