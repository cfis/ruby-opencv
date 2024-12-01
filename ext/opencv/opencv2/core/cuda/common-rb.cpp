#include <sstream>
#include <opencv2/core/cuda/common.hpp>
#include "common-rb.hpp"

using namespace Rice;



void Init_Common()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}