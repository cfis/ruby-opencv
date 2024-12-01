#include <opencv2/core/affine.hpp>
#include "affine-rb.hpp"

using namespace Rice;

extern "C"
void Init_Affine()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
}