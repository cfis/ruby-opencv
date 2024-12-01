#include <opencv2/text/textDetector.hpp>
#include "textDetector-rb.hpp"

using namespace Rice;

extern "C"
void Init_TextDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvText = define_module_under(rb_mCv, "Text");
  
  Class rb_cCvTextTextDetector = define_class_under<cv::text::TextDetector>(rb_mCvText, "TextDetector").
    define_method<void(cv::text::TextDetector::*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&, std::vector<float>&)>("detect", &cv::text::TextDetector::detect);
  
  Class rb_cCvTextTextDetectorCNN = define_class_under<cv::text::TextDetectorCNN, cv::text::TextDetector>(rb_mCvText, "TextDetectorCNN").
    define_method<void(cv::text::TextDetectorCNN::*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&, std::vector<float>&)>("detect", &cv::text::TextDetectorCNN::detect).
    define_singleton_function<cv::Ptr<cv::text::TextDetectorCNN>(*)(const std::basic_string<char>&, const std::basic_string<char>&, std::vector<cv::Size_<int>>)>("create", &cv::text::TextDetectorCNN::create).
    define_singleton_function<cv::Ptr<cv::text::TextDetectorCNN>(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("create", &cv::text::TextDetectorCNN::create);
}