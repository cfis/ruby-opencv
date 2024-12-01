#include <opencv2/cudev/functional/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

extern "C"
void Init_Functional()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevAbsFuncUchar = define_class_under<cv::cudev::abs_func<uchar>, >(rb_mCvCudev, "AbsFuncUchar").
    define_method<unsigned char(cv::cudev::abs_func::*)(unsigned char) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncSchar = define_class_under<cv::cudev::abs_func<schar>, >(rb_mCvCudev, "AbsFuncSchar").
    define_method<signed char(cv::cudev::abs_func::*)(signed char) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncUshort = define_class_under<cv::cudev::abs_func<ushort>, >(rb_mCvCudev, "AbsFuncUshort").
    define_method<unsigned short(cv::cudev::abs_func::*)(unsigned short) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncShort = define_class_under<cv::cudev::abs_func<short>, >(rb_mCvCudev, "AbsFuncShort").
    define_method<short(cv::cudev::abs_func::*)(short) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncUint = define_class_under<cv::cudev::abs_func<uint>, >(rb_mCvCudev, "AbsFuncUint").
    define_method<unsigned int(cv::cudev::abs_func::*)(unsigned int) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncInt = define_class_under<cv::cudev::abs_func<int>, >(rb_mCvCudev, "AbsFuncInt").
    define_method<int(cv::cudev::abs_func::*)(int) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncFloat = define_class_under<cv::cudev::abs_func<float>, >(rb_mCvCudev, "AbsFuncFloat").
    define_method<float(cv::cudev::abs_func::*)(float) const>("operator()", &cv::cudev::abs_func::operator());
  
  Class rb_cCvCudevAbsFuncDouble = define_class_under<cv::cudev::abs_func<double>, >(rb_mCvCudev, "AbsFuncDouble").
    define_method<double(cv::cudev::abs_func::*)(double) const>("operator()", &cv::cudev::abs_func::operator());
  
  Module rb_mCvCudevFunctionalDetail = define_module_under(rb_mCvCudev, "FunctionalDetail");
  
  
  Class rb_cCvCudevPowFuncDouble = define_class_under<cv::cudev::pow_func<double>, >(rb_mCvCudev, "PowFuncDouble").
    define_method<double(cv::cudev::pow_func::*)(double, double) const>("operator()", &cv::cudev::pow_func::operator());
  
  Class rb_cCvCudevSaturateCastFp16FuncFloat, short = define_class_under<cv::cudev::saturate_cast_fp16_func<float, short>, >(rb_mCvCudev, "SaturateCastFp16FuncFloat, short").
    define_method<short(cv::cudev::saturate_cast_fp16_func::*)(float) const>("operator()", &cv::cudev::saturate_cast_fp16_func::operator());
  
  Class rb_cCvCudevSaturateCastFp16FuncShort, float = define_class_under<cv::cudev::saturate_cast_fp16_func<short, float>, >(rb_mCvCudev, "SaturateCastFp16FuncShort, float").
    define_method<float(cv::cudev::saturate_cast_fp16_func::*)(short) const>("operator()", &cv::cudev::saturate_cast_fp16_func::operator());
}