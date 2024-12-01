#include <opencv2/core/cuda/warp_shuffle.hpp>
#include "warp_shuffle-rb.hpp"

using namespace Rice;

extern "C"
void Init_WarpShuffle()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, int, int)>("shfl", &cv::cuda::device::shfl);
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, int, int)>("shfl", &cv::cuda::device::shfl);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int, int)>("shfl_down", &cv::cuda::device::shfl_down);
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, unsigned int, int)>("shfl_down", &cv::cuda::device::shfl_down);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(unsigned int, unsigned int, int)>("shfl_up", &cv::cuda::device::shfl_up);
  
  rb_mCvCudaDevice.define_module_function<double(*)(double, unsigned int, int)>("shfl_up", &cv::cuda::device::shfl_up);
}