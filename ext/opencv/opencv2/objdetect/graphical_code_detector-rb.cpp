#include <opencv2/objdetect/graphical_code_detector.hpp>
#include "graphical_code_detector-rb.hpp"

using namespace Rice;

extern "C"
void Init_GraphicalCodeDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvGraphicalCodeDetector = define_class_under<cv::GraphicalCodeDetector>(rb_mCv, "GraphicalCodeDetector").
    define_constructor(Constructor<cv::GraphicalCodeDetector>()).
    define_constructor(Constructor<cv::GraphicalCodeDetector, const cv::GraphicalCodeDetector&>()).
    define_constructor(Constructor<cv::GraphicalCodeDetector, cv::GraphicalCodeDetector&&>()).
    define_method<cv::GraphicalCodeDetector&(cv::GraphicalCodeDetector::*)(const cv::GraphicalCodeDetector&)>("operator=", &cv::GraphicalCodeDetector::operator=).
    define_method<cv::GraphicalCodeDetector&(cv::GraphicalCodeDetector::*)(cv::GraphicalCodeDetector&&)>("operator=", &cv::GraphicalCodeDetector::operator=).
    define_method<bool(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("detect", &cv::GraphicalCodeDetector::detect).
    define_method<std::basic_string<char>(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &) const>("decode", &cv::GraphicalCodeDetector::decode).
    define_method<std::basic_string<char>(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &) const>("detect_and_decode", &cv::GraphicalCodeDetector::detectAndDecode).
    define_method<bool(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("detect_multi", &cv::GraphicalCodeDetector::detectMulti).
    define_method<bool(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::basic_string<char>>&, const cv::_OutputArray &) const>("decode_multi", &cv::GraphicalCodeDetector::decodeMulti).
    define_method<bool(cv::GraphicalCodeDetector::*)(const cv::_InputArray &, std::vector<std::basic_string<char>>&, const cv::_OutputArray &, const cv::_OutputArray &) const>("detect_and_decode_multi", &cv::GraphicalCodeDetector::detectAndDecodeMulti);
}