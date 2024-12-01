#include <opencv2/core/cuda/common.hpp>
#include "common-rb.hpp"

using namespace Rice;

extern "C"
void Init_Common()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<int(*)(int, int)>("div_up", &cv::cuda::device::divUp);
}