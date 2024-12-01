#include <opencv2/core/cuda/filters.hpp>
#include "filters-rb.hpp"

using namespace Rice;

extern "C"
void Init_Filters()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
}