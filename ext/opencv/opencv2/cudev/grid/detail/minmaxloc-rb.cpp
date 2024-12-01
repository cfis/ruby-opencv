#include <opencv2/cudev/grid/detail/minmaxloc.hpp>
#include "minmaxloc-rb.hpp"

using namespace Rice;

extern "C"
void Init_Minmaxloc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevGridMinmaxlocDetail = define_module_under(rb_mCvCudev, "GridMinmaxlocDetail");
}