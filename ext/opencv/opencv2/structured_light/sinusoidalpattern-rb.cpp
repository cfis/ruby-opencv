#include <opencv2/structured_light/sinusoidalpattern.hpp>
#include "sinusoidalpattern-rb.hpp"

using namespace Rice;

extern "C"
void Init_Sinusoidalpattern()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStructuredLight = define_module_under(rb_mCv, "StructuredLight");
  
  Class rb_cCvStructuredLightSinusoidalPattern = define_class_under<cv::structured_light::SinusoidalPattern, cv::structured_light::StructuredLightPattern>(rb_mCvStructuredLight, "SinusoidalPattern").
    define_singleton_function<cv::Ptr<cv::structured_light::SinusoidalPattern>(*)(cv::Ptr<cv::structured_light::SinusoidalPattern::Params>)>("create", &cv::structured_light::SinusoidalPattern::create).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("compute_phase_map", &cv::structured_light::SinusoidalPattern::computePhaseMap).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, const cv::_InputArray &)>("unwrap_phase_map", &cv::structured_light::SinusoidalPattern::unwrapPhaseMap).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("find_pro_cam_matches", &cv::structured_light::SinusoidalPattern::findProCamMatches).
    define_method<void(cv::structured_light::SinusoidalPattern::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("compute_data_modulation_term", &cv::structured_light::SinusoidalPattern::computeDataModulationTerm);
  
  Class rb_cCvStructuredLightSinusoidalPatternParams = define_class_under<cv::structured_light::SinusoidalPattern::Params>(rb_cCvStructuredLightSinusoidalPattern, "Params").
    define_constructor(Constructor<cv::structured_light::SinusoidalPattern::Params>()).
    define_attr("width", &cv::structured_light::SinusoidalPattern::Params::width).
    define_attr("height", &cv::structured_light::SinusoidalPattern::Params::height).
    define_attr("nbr_of_periods", &cv::structured_light::SinusoidalPattern::Params::nbrOfPeriods).
    define_attr("shift_value", &cv::structured_light::SinusoidalPattern::Params::shiftValue).
    define_attr("method_id", &cv::structured_light::SinusoidalPattern::Params::methodId).
    define_attr("nbr_of_pixels_between_markers", &cv::structured_light::SinusoidalPattern::Params::nbrOfPixelsBetweenMarkers).
    define_attr("horizontal", &cv::structured_light::SinusoidalPattern::Params::horizontal).
    define_attr("set_markers", &cv::structured_light::SinusoidalPattern::Params::setMarkers).
    define_attr("markers_location", &cv::structured_light::SinusoidalPattern::Params::markersLocation);
}