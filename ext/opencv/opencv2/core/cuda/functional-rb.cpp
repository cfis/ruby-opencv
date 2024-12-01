#include <opencv2/core/cuda/functional.hpp>
#include "functional-rb.hpp"

using namespace Rice;

extern "C"
void Init_Functional()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceAbsFuncUnsigned char = define_class_under<cv::cuda::device::abs_func<unsigned char>, >(rb_mCvCudaDevice, "AbsFuncUnsigned char").
    define_method<unsigned char(cv::cuda::device::abs_func::*)(unsigned char) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<unsigned char>&>());
  
  Class rb_cCvCudaDeviceAbsFuncSigned char = define_class_under<cv::cuda::device::abs_func<signed char>, >(rb_mCvCudaDevice, "AbsFuncSigned char").
    define_method<signed char(cv::cuda::device::abs_func::*)(signed char) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<signed char>&>());
  
  Class rb_cCvCudaDeviceAbsFuncChar = define_class_under<cv::cuda::device::abs_func<char>, >(rb_mCvCudaDevice, "AbsFuncChar").
    define_method<char(cv::cuda::device::abs_func::*)(char) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<char>&>());
  
  Class rb_cCvCudaDeviceAbsFuncUnsigned short = define_class_under<cv::cuda::device::abs_func<unsigned short>, >(rb_mCvCudaDevice, "AbsFuncUnsigned short").
    define_method<unsigned short(cv::cuda::device::abs_func::*)(unsigned short) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<unsigned short>&>());
  
  Class rb_cCvCudaDeviceAbsFuncShort = define_class_under<cv::cuda::device::abs_func<short>, >(rb_mCvCudaDevice, "AbsFuncShort").
    define_method<short(cv::cuda::device::abs_func::*)(short) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<short>&>());
  
  Class rb_cCvCudaDeviceAbsFuncUnsigned int = define_class_under<cv::cuda::device::abs_func<unsigned int>, >(rb_mCvCudaDevice, "AbsFuncUnsigned int").
    define_method<unsigned int(cv::cuda::device::abs_func::*)(unsigned int) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<unsigned int>&>());
  
  Class rb_cCvCudaDeviceAbsFuncInt = define_class_under<cv::cuda::device::abs_func<int>, >(rb_mCvCudaDevice, "AbsFuncInt").
    define_method<int(cv::cuda::device::abs_func::*)(int) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<int>&>());
  
  Class rb_cCvCudaDeviceAbsFuncFloat = define_class_under<cv::cuda::device::abs_func<float>, >(rb_mCvCudaDevice, "AbsFuncFloat").
    define_method<float(cv::cuda::device::abs_func::*)(float) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<float>&>());
  
  Class rb_cCvCudaDeviceAbsFuncDouble = define_class_under<cv::cuda::device::abs_func<double>, >(rb_mCvCudaDevice, "AbsFuncDouble").
    define_method<double(cv::cuda::device::abs_func::*)(double) const>("operator()", &cv::cuda::device::abs_func::operator()).
    define_constructor(Constructor<cv::cuda::device::abs_func>()).
    define_constructor(Constructor<cv::cuda::device::abs_func, const cv::cuda::device::abs_func<double>&>());
  
  Module rb_mCvCudaDeviceFunctionalDetail = define_module_under(rb_mCvCudaDevice, "FunctionalDetail");
}