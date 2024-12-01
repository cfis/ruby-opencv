#include <opencv2/videostab/fast_marching_inl.hpp>
#include "fast_marching_inl-rb.hpp"

using namespace Rice;

extern "C"
void Init_FastMarchingInl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
}