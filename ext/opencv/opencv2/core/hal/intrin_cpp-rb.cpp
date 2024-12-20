#include <sstream>
#include <opencv2/core/hal/intrin_cpp.hpp>
#include "intrin_cpp-rb.hpp"

using namespace Rice;



void Init_IntrinCpp()
{
  Class(rb_cObject).define_constant("CV_SIMD128_CPP", CV_SIMD128_CPP);
  Class(rb_cObject).define_constant("CV_SIMD256", CV_SIMD256);
  Class(rb_cObject).define_constant("CV_SIMD512", CV_SIMD512);
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<int(*)(const cv::hfloat*)>("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)()>("v_cleanup", &cv::v_cleanup);

}