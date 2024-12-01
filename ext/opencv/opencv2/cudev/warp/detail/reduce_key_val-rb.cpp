#include <opencv2/cudev/warp/detail/reduce_key_val.hpp>
#include "reduce_key_val-rb.hpp"

using namespace Rice;

extern "C"
void Init_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevWarpReduceKeyValDetail = define_module_under(rb_mCvCudev, "WarpReduceKeyValDetail");
  
  Class rb_cCvCudevWarpReduceKeyValDetailWarpReductor = define_class_under<cv::cudev::warp_reduce_key_val_detail::WarpReductor>(rb_mCvCudevWarpReduceKeyValDetail, "WarpReductor");
}