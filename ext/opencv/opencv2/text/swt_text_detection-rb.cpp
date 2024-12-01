#include <opencv2/text/swt_text_detection.hpp>
#include "swt_text_detection-rb.hpp"

using namespace Rice;

extern "C"
void Init_SwtTextDetection()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvText = define_module_under(rb_mCv, "Text");
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&, bool, const cv::_OutputArray&, const cv::_OutputArray&)>("detect_text_swt", &cv::text::detectTextSWT);
}