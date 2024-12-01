#include <opencv2/cudev/ptr2d/extrapolation.hpp>
#include "extrapolation-rb.hpp"

using namespace Rice;

extern "C"
void Init_Extrapolation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevBrdReplicate = define_class_under<cv::cudev::BrdReplicate>(rb_mCvCudev, "BrdReplicate").
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReplicate::idx_low).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReplicate::idx_high);
  
  Class rb_cCvCudevBrdReflect101 = define_class_under<cv::cudev::BrdReflect101>(rb_mCvCudev, "BrdReflect101").
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReflect101::idx_low).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReflect101::idx_high);
  
  Class rb_cCvCudevBrdReflect = define_class_under<cv::cudev::BrdReflect>(rb_mCvCudev, "BrdReflect").
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdReflect::idx_low).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdReflect::idx_high);
  
  Class rb_cCvCudevBrdWrap = define_class_under<cv::cudev::BrdWrap>(rb_mCvCudev, "BrdWrap").
    define_singleton_function<int(*)(int, int)>("idx_low", &cv::cudev::BrdWrap::idx_low).
    define_singleton_function<int(*)(int, int)>("idx_high", &cv::cudev::BrdWrap::idx_high);
}