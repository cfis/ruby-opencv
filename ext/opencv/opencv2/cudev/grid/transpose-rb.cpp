#include <opencv2/cudev/grid/transpose.hpp>
#include "transpose-rb.hpp"

using namespace Rice;

extern "C"
void Init_Transpose()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultTransposePolicy = define_class_under<cv::cudev::DefaultTransposePolicy>(rb_mCvCudev, "DefaultTransposePolicy");
}