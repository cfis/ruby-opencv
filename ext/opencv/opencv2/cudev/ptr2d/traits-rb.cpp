#include <opencv2/cudev/ptr2d/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_Traits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}