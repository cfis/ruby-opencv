#include <opencv2/core/cuda_types.hpp>
#include "cuda_types-rb.hpp"

using namespace Rice;

extern "C"
void Init_CudaTypes()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
}