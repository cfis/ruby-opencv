#include <opencv2/cudev/expr/unary_func.hpp>
#include "unary_func-rb.hpp"

using namespace Rice;

extern "C"
void Init_UnaryFunc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}