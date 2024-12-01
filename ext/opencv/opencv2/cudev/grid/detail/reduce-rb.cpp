#include <opencv2/cudev/grid/detail/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

extern "C"
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevGridReduceDetail = define_module_under(rb_mCvCudev, "GridReduceDetail");
  
  Class rb_cCvCudevGridReduceDetailUnroll1 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<1>>(rb_mCvCudevGridReduceDetail, "Unroll1");
  
  
  Class rb_cCvCudevGridReduceDetailUnroll2 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<2>>(rb_mCvCudevGridReduceDetail, "Unroll2");
  
  
  Class rb_cCvCudevGridReduceDetailUnroll3 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<3>>(rb_mCvCudevGridReduceDetail, "Unroll3");
  
  
  Class rb_cCvCudevGridReduceDetailUnroll4 = define_class_under<cv::cudev::grid_reduce_detail::Unroll<4>>(rb_mCvCudevGridReduceDetail, "Unroll4");
  
  
  Class rb_cCvCudevGridReduceDetailBoth = define_class_under<cv::cudev::grid_reduce_detail::both>(rb_mCvCudevGridReduceDetail, "Both");
}