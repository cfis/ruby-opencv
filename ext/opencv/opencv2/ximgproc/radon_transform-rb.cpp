#include <opencv2/ximgproc/radon_transform.hpp>
#include "radon_transform-rb.hpp"

using namespace Rice;

extern "C"
void Init_RadonTransform()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, double, bool, bool)>("radon_transform", &cv::ximgproc::RadonTransform);
}