#include <opencv2/core/cuda/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_TypeTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
}