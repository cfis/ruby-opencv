#include <opencv2/cudev/functional/color_cvt.hpp>
#include "color_cvt-rb.hpp"

using namespace Rice;

extern "C"
void Init_ColorCvt()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}