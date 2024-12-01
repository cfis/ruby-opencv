#include <opencv2/core/cuda/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

extern "C"
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
}