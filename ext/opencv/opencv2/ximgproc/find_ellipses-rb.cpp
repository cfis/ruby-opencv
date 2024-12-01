#include <opencv2/ximgproc/find_ellipses.hpp>
#include "find_ellipses-rb.hpp"

using namespace Rice;

extern "C"
void Init_FindEllipses()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, float)>("find_ellipses", &cv::ximgproc::findEllipses);
}