#include <opencv2/core/cuda/vec_math.hpp>
#include "vec_math-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecMath()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceVecMathDetail = define_module_under(rb_mCvCudaDevice, "VecMathDetail");
}