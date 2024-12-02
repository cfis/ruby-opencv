#include <opencv2/cudev/grid/pyramids.hpp>
#include "pyramids-rb.hpp"

using namespace Rice;

extern "C"
void Init_Pyramids()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}