#include <opencv2/cudev/ptr2d/interpolation.hpp>
#include "interpolation-rb.hpp"

using namespace Rice;

extern "C"
void Init_Interpolation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}