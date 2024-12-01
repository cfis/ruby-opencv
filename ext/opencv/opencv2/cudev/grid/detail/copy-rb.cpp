#include <opencv2/cudev/grid/detail/copy.hpp>
#include "copy-rb.hpp"

using namespace Rice;

extern "C"
void Init_Copy()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevGridCopyDetail = define_module_under(rb_mCvCudev, "GridCopyDetail");
  
  Class rb_cCvCudevGridCopyDetailUnroll0 = define_class_under<cv::cudev::grid_copy_detail::Unroll<0>>(rb_mCvCudevGridCopyDetail, "Unroll0");
}