#include <opencv2/cudev/grid/reduce.hpp>
#include "reduce-rb.hpp"

using namespace Rice;

extern "C"
void Init_Reduce()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultGlobReducePolicy = define_class_under<cv::cudev::DefaultGlobReducePolicy>(rb_mCvCudev, "DefaultGlobReducePolicy");
}