#include <opencv2/cudev/grid/copy.hpp>
#include "copy-rb.hpp"

using namespace Rice;

extern "C"
void Init_Copy()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultCopyPolicy = define_class_under<cv::cudev::DefaultCopyPolicy>(rb_mCvCudev, "DefaultCopyPolicy");
}