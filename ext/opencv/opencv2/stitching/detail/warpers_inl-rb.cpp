#include <opencv2/stitching/detail/warpers_inl.hpp>
#include "warpers_inl-rb.hpp"

using namespace Rice;

extern "C"
void Init_WarpersInl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
}