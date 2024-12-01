#include <opencv2/cudev/ptr2d/gpumat.hpp>
#include "gpumat-rb.hpp"

using namespace Rice;

extern "C"
void Init_Gpumat()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}