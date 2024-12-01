#include <opencv2/core/cuda/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

extern "C"
void Init_DynamicSmem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceDynamicSharedMemDouble = define_class_under<cv::cuda::device::DynamicSharedMem<double>>(rb_mCvCudaDevice, "DynamicSharedMemDouble");
}