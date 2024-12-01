#include <opencv2/stitching/detail/util_inl.hpp>
#include "util_inl-rb.hpp"

using namespace Rice;

extern "C"
void Init_UtilInl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
}