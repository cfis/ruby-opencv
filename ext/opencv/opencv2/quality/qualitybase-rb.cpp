#include <opencv2/quality/qualitybase.hpp>
#include "qualitybase-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualitybase()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualityBase = define_class_under<cv::quality::QualityBase, cv::Algorithm>(rb_mCvQuality, "QualityBase").
    define_method<cv::Scalar_<double>(cv::quality::QualityBase::*)(const cv::_InputArray &)>("compute", &cv::quality::QualityBase::compute).
    define_method<void(cv::quality::QualityBase::*)(const cv::_OutputArray &) const>("get_quality_map", &cv::quality::QualityBase::getQualityMap).
    define_method<void(cv::quality::QualityBase::*)()>("clear", &cv::quality::QualityBase::clear).
    define_method<bool(cv::quality::QualityBase::*)() const>("empty", &cv::quality::QualityBase::empty);
}