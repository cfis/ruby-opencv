#include <opencv2/core/fast_math.hpp>
#include "fast_math-rb.hpp"

using namespace Rice;



void Init_FastMath()
{
  Class(rb_cObject).define_constant("OPENCV_USE_FASTMATH_BUILTINS", OPENCV_USE_FASTMATH_BUILTINS);
  
  define_global_function("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function("cv_is_na_n", &cvIsNaN,
    Arg("value"));
  
  define_global_function("cv_is_inf", &cvIsInf,
    Arg("value"));
  
  define_global_function("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function("cv_round", &cvRound,
    Arg("value"));
  
  define_global_function("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function("cv_floor", &cvFloor,
    Arg("value"));
  
  define_global_function("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function("cv_ceil", &cvCeil,
    Arg("value"));
  
  define_global_function("cv_is_na_n", &cvIsNaN,
    Arg("value"));
  
  define_global_function("cv_is_inf", &cvIsInf,
    Arg("value"));

}