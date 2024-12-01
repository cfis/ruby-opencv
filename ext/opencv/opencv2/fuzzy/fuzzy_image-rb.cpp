#include <opencv2/fuzzy/fuzzy_image.hpp>
#include "fuzzy_image-rb.hpp"

using namespace Rice;

extern "C"
void Init_FuzzyImage()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const int)>("create_kernel", &cv::ft::createKernel);
  
  rb_mCvFt.define_module_function<void(*)(int, int, const cv::_OutputArray &, const int)>("create_kernel", &cv::ft::createKernel);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("inpaint", &cv::ft::inpaint);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("filter", &cv::ft::filter);
}