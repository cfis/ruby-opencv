#include <opencv2/ximgproc/deriche_filter.hpp>
#include "deriche_filter-rb.hpp"

using namespace Rice;

extern "C"
void Init_DericheFilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("gradient_deriche_y", &cv::ximgproc::GradientDericheY);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("gradient_deriche_x", &cv::ximgproc::GradientDericheX);
}