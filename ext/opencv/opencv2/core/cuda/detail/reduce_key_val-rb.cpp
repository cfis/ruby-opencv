#include <opencv2/core/cuda/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

extern "C"
void Init_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceReduceKeyValDetail = define_module_under(rb_mCvCudaDevice, "ReduceKeyValDetail");
}