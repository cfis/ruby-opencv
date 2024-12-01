#include <sstream>
#include <opencv2/objdetect/graphical_code_detector.hpp>
#include "graphical_code_detector-rb.hpp"

using namespace Rice;



void Init_GraphicalCodeDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvGraphicalCodeDetector = define_class_under<cv::GraphicalCodeDetector>(rb_mCv, "GraphicalCodeDetector").
    define_constructor(Constructor<cv::GraphicalCodeDetector>()).
    define_constructor(Constructor<cv::GraphicalCodeDetector, const cv::GraphicalCodeDetector&>(),
      Arg("")).
    define_constructor(Constructor<cv::GraphicalCodeDetector, cv::GraphicalCodeDetector&&>(),
      Arg("")).
    define_method<cv::GraphicalCodeDetector&(cv::GraphicalCodeDetector::*)(const cv::GraphicalCodeDetector&)>("=", &cv::GraphicalCodeDetector::operator=,
      Arg("")).
    define_method<cv::GraphicalCodeDetector&(cv::GraphicalCodeDetector::*)(cv::GraphicalCodeDetector&&)>("=", &cv::GraphicalCodeDetector::operator=,
      Arg("")).
    define_method<bool(cv::GraphicalCodeDetector::*)(cv::InputArray, cv::OutputArray) const>("detect?", &cv::GraphicalCodeDetector::detect,
      Arg("img"), Arg("points")).
    define_method<std::string(cv::GraphicalCodeDetector::*)(cv::InputArray, cv::InputArray, cv::OutputArray) const>("decode", &cv::GraphicalCodeDetector::decode,
      Arg("img"), Arg("points"), Arg("straight_code")).
    define_method<std::string(cv::GraphicalCodeDetector::*)(cv::InputArray, cv::OutputArray, cv::OutputArray) const>("detect_and_decode", &cv::GraphicalCodeDetector::detectAndDecode,
      Arg("img"), Arg("points"), Arg("straight_code")).
    define_method<bool(cv::GraphicalCodeDetector::*)(cv::InputArray, cv::OutputArray) const>("detect_multi?", &cv::GraphicalCodeDetector::detectMulti,
      Arg("img"), Arg("points")).
    define_method<bool(cv::GraphicalCodeDetector::*)(cv::InputArray, cv::InputArray, std::vector<std::basic_string<char>>&, cv::OutputArrayOfArrays) const>("decode_multi?", &cv::GraphicalCodeDetector::decodeMulti,
      Arg("img"), Arg("points"), Arg("decoded_info"), Arg("straight_code")).
    define_method<bool(cv::GraphicalCodeDetector::*)(cv::InputArray, std::vector<std::basic_string<char>>&, cv::OutputArray, cv::OutputArrayOfArrays) const>("detect_and_decode_multi?", &cv::GraphicalCodeDetector::detectAndDecodeMulti,
      Arg("img"), Arg("decoded_info"), Arg("points"), Arg("straight_code"));
  

}