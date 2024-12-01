#include <opencv2/cudev/ptr2d/deriv.hpp>
#include "deriv-rb.hpp"

using namespace Rice;

extern "C"
void Init_Deriv()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}