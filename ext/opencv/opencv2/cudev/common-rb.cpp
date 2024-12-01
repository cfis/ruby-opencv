#include <opencv2/cudev/common.hpp>
#include "common-rb.hpp"

using namespace Rice;

extern "C"
void Init_Common()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  rb_mCvCudev.define_module_function<void(*)(cudaError, const char*, const int, const char*)>("check_cuda_error", &cv::cudev::checkCudaError);
  
  rb_mCvCudev.define_module_function<int(*)(int, int)>("div_up", &cv::cudev::divUp);
}