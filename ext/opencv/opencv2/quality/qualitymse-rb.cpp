#include <opencv2/quality/qualitymse.hpp>
#include "qualitymse-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualitymse()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualityMSE = define_class_under<cv::quality::QualityMSE, cv::quality::QualityBase>(rb_mCvQuality, "QualityMSE").
    define_method<cv::Scalar_<double>(cv::quality::QualityMSE::*)(const cv::_InputArray &)>("compute", &cv::quality::QualityMSE::compute).
    define_method<bool(cv::quality::QualityMSE::*)() const>("empty", &cv::quality::QualityMSE::empty).
    define_method<void(cv::quality::QualityMSE::*)()>("clear", &cv::quality::QualityMSE::clear).
    define_singleton_function<cv::Ptr<cv::quality::QualityMSE>(*)(const cv::_InputArray &)>("create", &cv::quality::QualityMSE::create).
    define_singleton_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::quality::QualityMSE::compute).
    define_constructor(Constructor<cv::quality::QualityMSE, cv::UMat>());
}