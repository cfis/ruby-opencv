#include <opencv2/cudev/expr/color.hpp>
#include "color-rb.hpp"

using namespace Rice;

extern "C"
void Init_Color()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}