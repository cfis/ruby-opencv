#include <opencv2/cudev/grid/detail/integral.hpp>
#include "integral-rb.hpp"

using namespace Rice;

extern "C"
void Init_Integral()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevIntegralDetail = define_module_under(rb_mCvCudev, "IntegralDetail");
  
  rb_mCvCudevIntegralDetail.define_module_function<void(*)(const cv::cudev::GlobPtr<unsigned char>&, const cv::cudev::GlobPtr<int>&, int, int, CUstream_st *)>("integral", &cv::cudev::integral_detail::integral);
}