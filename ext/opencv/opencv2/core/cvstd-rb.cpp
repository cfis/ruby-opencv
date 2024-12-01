#include <opencv2/core/cvstd.hpp>
#include "cvstd-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cvstd()
{
  Module rb_mCv = define_module("Cv");
  
  
//  rb_mCv.define_module_function<void*(*)(unsigned long long)>("fast_malloc", &cv::fastMalloc);
  
  //rb_mCv.define_module_function<void(*)(void*)>("fast_free", &cv::fastFree);
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
}