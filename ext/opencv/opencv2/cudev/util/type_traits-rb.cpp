#include <opencv2/cudev/util/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_TypeTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevNullType = define_class_under<cv::cudev::NullType>(rb_mCvCudev, "NullType");
}