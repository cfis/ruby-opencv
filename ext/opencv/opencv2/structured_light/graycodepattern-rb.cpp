#include <opencv2/structured_light/graycodepattern.hpp>
#include "graycodepattern-rb.hpp"

using namespace Rice;

extern "C"
void Init_Graycodepattern()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");
  
  Class rb_cCvStructuredLightGrayCodePattern = define_class_under<cv::structured_light::GrayCodePattern, cv::structured_light::StructuredLightPattern>(rb_mCvStructuredLight, "GrayCodePattern").
    define_singleton_function<cv::Ptr<cv::structured_light::GrayCodePattern>(*)(const cv::structured_light::GrayCodePattern::Params&)>("create", &cv::structured_light::GrayCodePattern::create).
    define_singleton_function<cv::Ptr<cv::structured_light::GrayCodePattern>(*)(int, int)>("create", &cv::structured_light::GrayCodePattern::create).
    define_method<unsigned long long(cv::structured_light::GrayCodePattern::*)() const>("get_number_of_pattern_images", &cv::structured_light::GrayCodePattern::getNumberOfPatternImages).
    define_method<void(cv::structured_light::GrayCodePattern::*)(unsigned long long)>("set_white_threshold", &cv::structured_light::GrayCodePattern::setWhiteThreshold).
    define_method<void(cv::structured_light::GrayCodePattern::*)(unsigned long long)>("set_black_threshold", &cv::structured_light::GrayCodePattern::setBlackThreshold).
    define_method<void(cv::structured_light::GrayCodePattern::*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &) const>("get_images_for_shadow_masks", &cv::structured_light::GrayCodePattern::getImagesForShadowMasks).
    define_method<bool(cv::structured_light::GrayCodePattern::*)(const cv::_InputArray &, int, int, cv::Point_<int>&) const>("get_proj_pixel", &cv::structured_light::GrayCodePattern::getProjPixel);
  
  Class rb_cCvStructuredLightGrayCodePatternParams = define_class_under<cv::structured_light::GrayCodePattern::Params>(rb_cCvStructuredLightGrayCodePattern, "Params").
    define_constructor(Constructor<cv::structured_light::GrayCodePattern::Params>()).
    define_attr("width", &cv::structured_light::GrayCodePattern::Params::width).
    define_attr("height", &cv::structured_light::GrayCodePattern::Params::height);
}