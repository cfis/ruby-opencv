#include <opencv2/ximgproc/color_match.hpp>
#include "color_match-rb.hpp"

using namespace Rice;

extern "C"
void Init_ColorMatch()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("create_quaternion_image", &cv::ximgproc::createQuaternionImage);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("qconj", &cv::ximgproc::qconj);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("qunitary", &cv::ximgproc::qunitary);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("qmultiply", &cv::ximgproc::qmultiply);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, bool)>("qdft", &cv::ximgproc::qdft);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("color_match_template", &cv::ximgproc::colorMatchTemplate);
}