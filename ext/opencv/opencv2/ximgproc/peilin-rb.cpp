#include <opencv2/ximgproc/peilin.hpp>
#include "peilin-rb.hpp"

using namespace Rice;

extern "C"
void Init_Peilin()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<cv::Matx<double, 2, 3>(*)(const cv::_InputArray &)>("pei_lin_normalization", &cv::ximgproc::PeiLinNormalization);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("pei_lin_normalization", &cv::ximgproc::PeiLinNormalization);
}