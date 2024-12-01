#include <opencv2/cudev/grid/detail/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

extern "C"
void Init_Transform()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevGridTransformDetail = define_module_under(rb_mCvCudev, "GridTransformDetail");
  
  Class rb_cCvCudevGridTransformDetailOpUnroller1 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<1>>(rb_mCvCudevGridTransformDetail, "OpUnroller1");
  
  
  Class rb_cCvCudevGridTransformDetailOpUnroller2 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<2>>(rb_mCvCudevGridTransformDetail, "OpUnroller2");
  
  
  Class rb_cCvCudevGridTransformDetailOpUnroller3 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<3>>(rb_mCvCudevGridTransformDetail, "OpUnroller3");
  
  
  Class rb_cCvCudevGridTransformDetailOpUnroller4 = define_class_under<cv::cudev::grid_transform_detail::OpUnroller<4>>(rb_mCvCudevGridTransformDetail, "OpUnroller4");
  
  
  Class rb_cCvCudevGridTransformDetailUnroll0 = define_class_under<cv::cudev::grid_transform_detail::Unroll<0>>(rb_mCvCudevGridTransformDetail, "Unroll0");
}