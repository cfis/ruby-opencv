#include <opencv2/cudev/expr/binary_func.hpp>
#include "binary_func-rb.hpp"

using namespace Rice;

extern "C"
void Init_BinaryFunc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}