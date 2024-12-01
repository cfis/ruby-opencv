#include <opencv2/cudev/grid/reduce_to_vec.hpp>
#include "reduce_to_vec-rb.hpp"

using namespace Rice;

extern "C"
void Init_ReduceToVec()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultReduceToVecPolicy = define_class_under<cv::cudev::DefaultReduceToVecPolicy>(rb_mCvCudev, "DefaultReduceToVecPolicy");
}