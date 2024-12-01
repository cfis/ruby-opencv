#include <opencv2/quality/qualitypsnr.hpp>
#include "qualitypsnr-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualitypsnr()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualityPSNR = define_class_under<cv::quality::QualityPSNR, cv::quality::QualityBase>(rb_mCvQuality, "QualityPSNR").
    define_singleton_attr("MAX_PIXEL_VALUE_DEFAULT", &QualityPSNR::MAX_PIXEL_VALUE_DEFAULT).
    define_singleton_function<cv::Ptr<cv::quality::QualityPSNR>(*)(const cv::_InputArray &, double)>("create", &cv::quality::QualityPSNR::create).
    define_method<cv::Scalar_<double>(cv::quality::QualityPSNR::*)(const cv::_InputArray &)>("compute", &cv::quality::QualityPSNR::compute).
    define_method<bool(cv::quality::QualityPSNR::*)() const>("empty", &cv::quality::QualityPSNR::empty).
    define_method<void(cv::quality::QualityPSNR::*)()>("clear", &cv::quality::QualityPSNR::clear).
    define_singleton_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double)>("compute", &cv::quality::QualityPSNR::compute).
    define_method<double(cv::quality::QualityPSNR::*)() const>("get_max_pixel_value", &cv::quality::QualityPSNR::getMaxPixelValue).
    define_method<void(cv::quality::QualityPSNR::*)(double)>("set_max_pixel_value", &cv::quality::QualityPSNR::setMaxPixelValue).
    define_constructor(Constructor<cv::quality::QualityPSNR, cv::Ptr<cv::quality::QualityMSE>, double>());
}