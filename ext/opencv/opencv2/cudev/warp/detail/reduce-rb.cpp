#include <opencv2/cudev/warp/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

extern "C"
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevWarpReduceDetail = define_module_under(rb_mCvCudev, "WarpReduceDetail");
  
  Class rb_cCvCudevWarpReduceDetailWarpReductor = define_class_under<cv::cudev::warp_reduce_detail::WarpReductor>(rb_mCvCudevWarpReduceDetail, "WarpReductor");
}