#include <opencv2/cudev/grid/transform.hpp>
#include "transform-rb.hpp"

using namespace Rice;

extern "C"
void Init_Transform()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultTransformPolicy = define_class_under<cv::cudev::DefaultTransformPolicy>(rb_mCvCudev, "DefaultTransformPolicy");
}