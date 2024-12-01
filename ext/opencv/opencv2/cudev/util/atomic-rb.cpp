#include <opencv2/cudev/util/atomic.hpp>
#include "atomic-rb.hpp"

using namespace Rice;

extern "C"
void Init_Atomic()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_add", &cv::cudev::atomicAdd);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int*, unsigned int)>("atomic_add", &cv::cudev::atomicAdd);
  
  rb_mCvCudev.define_module_function<float(*)(float*, float)>("atomic_add", &cv::cudev::atomicAdd);
  
  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_min", &cv::cudev::atomicMin);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int*, unsigned int)>("atomic_min", &cv::cudev::atomicMin);
  
  rb_mCvCudev.define_module_function<int(*)(int*, int)>("atomic_max", &cv::cudev::atomicMax);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int*, unsigned int)>("atomic_max", &cv::cudev::atomicMax);
}