#include <opencv2/ximgproc/paillou_filter.hpp>
#include "paillou_filter-rb.hpp"

using namespace Rice;

extern "C"
void Init_PaillouFilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("gradient_paillou_y", &cv::ximgproc::GradientPaillouY);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("gradient_paillou_x", &cv::ximgproc::GradientPaillouX);
}