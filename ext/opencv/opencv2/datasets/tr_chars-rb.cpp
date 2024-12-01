#include <opencv2/datasets/tr_chars.hpp>
#include "tr_chars-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrChars()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsTRCharsObj = define_class_under<cv::datasets::TR_charsObj, cv::datasets::Object>(rb_mCvDatasets, "TRCharsObj").
    define_attr("img_name", &cv::datasets::TR_charsObj::imgName).
    define_attr("label", &cv::datasets::TR_charsObj::label);
  
  Class rb_cCvDatasetsTRChars = define_class_under<cv::datasets::TR_chars, cv::datasets::Dataset>(rb_mCvDatasets, "TRChars").
    define_method<void(cv::datasets::TR_chars::*)(const std::basic_string<char>&)>("load", &cv::datasets::TR_chars::load).
    define_singleton_function<cv::Ptr<cv::datasets::TR_chars>(*)()>("create", &cv::datasets::TR_chars::create);
}