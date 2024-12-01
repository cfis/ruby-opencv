#include <opencv2/cudev/expr/expr.hpp>
#include "expr-rb.hpp"

using namespace Rice;

extern "C"
void Init_Expr()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}