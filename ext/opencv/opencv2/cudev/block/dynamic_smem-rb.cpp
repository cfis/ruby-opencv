#include <opencv2/cudev/block/dynamic_smem.hpp>
#include "dynamic_smem-rb.hpp"

using namespace Rice;

extern "C"
void Init_DynamicSmem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDynamicSharedMemDouble = define_class_under<cv::cudev::DynamicSharedMem<double>>(rb_mCvCudev, "DynamicSharedMemDouble");
}