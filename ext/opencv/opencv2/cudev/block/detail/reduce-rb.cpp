#include <opencv2/cudev/block/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

extern "C"
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevBlockReduceDetail = define_module_under(rb_mCvCudev, "BlockReduceDetail");
}