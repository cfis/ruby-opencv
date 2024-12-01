#include <opencv2/cudev/ptr2d/remap.hpp>
#include "remap-rb.hpp"

using namespace Rice;

extern "C"
void Init_Remap()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}