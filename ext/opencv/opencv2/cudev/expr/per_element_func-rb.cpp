#include <opencv2/cudev/expr/per_element_func.hpp>
#include "per_element_func-rb.hpp"

using namespace Rice;

extern "C"
void Init_PerElementFunc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}