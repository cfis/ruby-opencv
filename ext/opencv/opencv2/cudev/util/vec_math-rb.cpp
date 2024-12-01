#include <opencv2/cudev/util/vec_math.hpp>
#include "vec_math-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecMath()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevVecMathDetail = define_module_under(rb_mCvCudev, "VecMathDetail");
  
  
  rb_mCvCudevVecMathDetail.define_module_function<signed char(*)(signed char)>("abs_", &cv::cudev::vec_math_detail::abs_);
  
  rb_mCvCudevVecMathDetail.define_module_function<short(*)(short)>("abs_", &cv::cudev::vec_math_detail::abs_);
}