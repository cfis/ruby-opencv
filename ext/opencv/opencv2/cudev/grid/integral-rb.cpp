#include <opencv2/cudev/grid/integral.hpp>
#include "integral-rb.hpp"

using namespace Rice;

extern "C"
void Init_Integral()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}