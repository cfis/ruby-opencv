#include <opencv2/cudev/grid/detail/transpose.hpp>
#include "transpose-rb.hpp"

using namespace Rice;

extern "C"
void Init_Transpose()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevTransposeDetail = define_module_under(rb_mCvCudev, "TransposeDetail");
}