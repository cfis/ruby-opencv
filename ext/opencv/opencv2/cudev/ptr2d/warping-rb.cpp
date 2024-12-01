#include <opencv2/cudev/ptr2d/warping.hpp>
#include "warping-rb.hpp"

using namespace Rice;

extern "C"
void Init_Warping()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevAffineMapPtr = define_class_under<cv::cudev::AffineMapPtr>(rb_mCvCudev, "AffineMapPtr").
    define_attr("warp_mat", &cv::cudev::AffineMapPtr::warpMat).
    define_method<float2(cv::cudev::AffineMapPtr::*)(float, float) const>("operator()", &cv::cudev::AffineMapPtr::operator());
  
  Class rb_cCvCudevAffineMapPtrSz = define_class_under<cv::cudev::AffineMapPtrSz, cv::cudev::AffineMapPtr>(rb_mCvCudev, "AffineMapPtrSz").
    define_attr("rows", &cv::cudev::AffineMapPtrSz::rows).
    define_attr("cols", &cv::cudev::AffineMapPtrSz::cols);
  
  Class rb_cCvCudevPtrTraitsAffineMapPtrSz = define_class_under<cv::cudev::PtrTraits<AffineMapPtrSz>, >(rb_mCvCudev, "PtrTraitsAffineMapPtrSz");
  
  
  Class rb_cCvCudevPerspectiveMapPtr = define_class_under<cv::cudev::PerspectiveMapPtr>(rb_mCvCudev, "PerspectiveMapPtr").
    define_attr("warp_mat", &cv::cudev::PerspectiveMapPtr::warpMat).
    define_method<float2(cv::cudev::PerspectiveMapPtr::*)(float, float) const>("operator()", &cv::cudev::PerspectiveMapPtr::operator());
  
  Class rb_cCvCudevPerspectiveMapPtrSz = define_class_under<cv::cudev::PerspectiveMapPtrSz, cv::cudev::PerspectiveMapPtr>(rb_mCvCudev, "PerspectiveMapPtrSz").
    define_attr("rows", &cv::cudev::PerspectiveMapPtrSz::rows).
    define_attr("cols", &cv::cudev::PerspectiveMapPtrSz::cols);
  
  Class rb_cCvCudevPtrTraitsPerspectiveMapPtrSz = define_class_under<cv::cudev::PtrTraits<PerspectiveMapPtrSz>, >(rb_mCvCudev, "PtrTraitsPerspectiveMapPtrSz");
}