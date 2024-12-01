#include <opencv2/ccalib.hpp>
#include "ccalib-rb.hpp"

using namespace Rice;

extern "C"
void Init_Ccalib()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCcalib = define_module_under(rb_mCv, "Ccalib");
  
  Class rb_cCvCcalibCustomPattern = define_class_under<cv::ccalib::CustomPattern, cv::Algorithm>(rb_mCvCcalib, "CustomPattern").
    define_constructor(Constructor<cv::ccalib::CustomPattern>()).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::Size_<float>, const cv::_OutputArray &)>("create", &cv::ccalib::CustomPattern::create).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const double, const double, const bool, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("find_pattern", &cv::ccalib::CustomPattern::findPattern).
    define_method<bool(cv::ccalib::CustomPattern::*)()>("is_initialized", &cv::ccalib::CustomPattern::isInitialized).
    define_method<void(cv::ccalib::CustomPattern::*)(std::vector<cv::KeyPoint>&)>("get_pattern_points", &cv::ccalib::CustomPattern::getPatternPoints).
    define_method<double(cv::ccalib::CustomPattern::*)()>("get_pixel_size", &cv::ccalib::CustomPattern::getPixelSize).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::Feature2D>)>("set_feature_detector", &cv::ccalib::CustomPattern::setFeatureDetector).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::Feature2D>)>("set_descriptor_extractor", &cv::ccalib::CustomPattern::setDescriptorExtractor).
    define_method<bool(cv::ccalib::CustomPattern::*)(cv::Ptr<cv::DescriptorMatcher>)>("set_descriptor_matcher", &cv::ccalib::CustomPattern::setDescriptorMatcher).
    define_method<cv::Ptr<cv::Feature2D>(cv::ccalib::CustomPattern::*)()>("get_feature_detector", &cv::ccalib::CustomPattern::getFeatureDetector).
    define_method<cv::Ptr<cv::Feature2D>(cv::ccalib::CustomPattern::*)()>("get_descriptor_extractor", &cv::ccalib::CustomPattern::getDescriptorExtractor).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::ccalib::CustomPattern::*)()>("get_descriptor_matcher", &cv::ccalib::CustomPattern::getDescriptorMatcher).
    define_method<double(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate", &cv::ccalib::CustomPattern::calibrate).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool, int)>("find_rt", &cv::ccalib::CustomPattern::findRt).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool, int)>("find_rt", &cv::ccalib::CustomPattern::findRt).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool, int, float, int, const cv::_OutputArray &, int)>("find_rt_ransac", &cv::ccalib::CustomPattern::findRtRANSAC).
    define_method<bool(cv::ccalib::CustomPattern::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool, int, float, int, const cv::_OutputArray &, int)>("find_rt_ransac", &cv::ccalib::CustomPattern::findRtRANSAC).
    define_method<void(cv::ccalib::CustomPattern::*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, int)>("draw_orientation", &cv::ccalib::CustomPattern::drawOrientation);
}