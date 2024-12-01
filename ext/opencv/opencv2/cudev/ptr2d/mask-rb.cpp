#include <opencv2/cudev/ptr2d/mask.hpp>
#include "mask-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mask()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevWithOutMask = define_class_under<cv::cudev::WithOutMask>(rb_mCvCudev, "WithOutMask").
    define_method<bool(cv::cudev::WithOutMask::*)(int, int) const>("operator()", &cv::cudev::WithOutMask::operator());
}