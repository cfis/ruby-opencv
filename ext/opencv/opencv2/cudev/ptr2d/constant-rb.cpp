#include <opencv2/cudev/ptr2d/constant.hpp>
#include "constant-rb.hpp"

using namespace Rice;

extern "C"
void Init_Constant()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}