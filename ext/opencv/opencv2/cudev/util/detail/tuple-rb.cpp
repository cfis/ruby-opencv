#include <opencv2/cudev/util/detail/tuple.hpp>
#include "tuple-rb.hpp"

using namespace Rice;

extern "C"
void Init_Tuple()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevTupleDetail = define_module_under(rb_mCvCudev, "TupleDetail");
}