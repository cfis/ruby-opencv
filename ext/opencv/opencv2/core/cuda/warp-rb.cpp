#include <sstream>
#include <opencv2/core/cuda/warp.hpp>
#include "warp-rb.hpp"

using namespace Rice;



void Init_Warp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceWarp = define_class_under<cv::cuda::device::Warp>(rb_mCvCudaDevice, "Warp").
    define_constructor(Constructor<cv::cuda::device::Warp>());
  

}