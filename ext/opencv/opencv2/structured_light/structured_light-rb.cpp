#include <opencv2/structured_light/structured_light.hpp>
#include "structured_light-rb.hpp"

using namespace Rice;

extern "C"
void Init_StructuredLight()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");
  
  Class rb_cCvStructuredLightStructuredLightPattern = define_class_under<cv::structured_light::StructuredLightPattern, cv::Algorithm>(rb_mCvStructuredLight, "StructuredLightPattern").
    define_method<bool(cv::structured_light::StructuredLightPattern::*)(const cv::_OutputArray &)>("generate", &cv::structured_light::StructuredLightPattern::generate).
    define_method<bool(cv::structured_light::StructuredLightPattern::*)(const std::vector<std::vector<cv::Mat>>&, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, int) const>("decode", &cv::structured_light::StructuredLightPattern::decode);
}