#include <opencv2/cudev/block/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

extern "C"
void Init_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevBlockReduceKeyValDetail = define_module_under(rb_mCvCudev, "BlockReduceKeyValDetail");
}