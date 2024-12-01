#include <opencv2/core/cuda/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

extern "C"
void Init_Limits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceNumericLimitsBool = define_class_under<cv::cuda::device::numeric_limits<bool>>(rb_mCvCudaDevice, "NumericLimitsBool").
    define_singleton_function<bool(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<bool(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsSigned char = define_class_under<cv::cuda::device::numeric_limits<signed char>>(rb_mCvCudaDevice, "NumericLimitsSigned char").
    define_singleton_function<signed char(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<signed char(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsigned char = define_class_under<cv::cuda::device::numeric_limits<unsigned char>>(rb_mCvCudaDevice, "NumericLimitsUnsigned char").
    define_singleton_function<unsigned char(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<unsigned char(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsShort = define_class_under<cv::cuda::device::numeric_limits<short>>(rb_mCvCudaDevice, "NumericLimitsShort").
    define_singleton_function<short(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<short(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsigned short = define_class_under<cv::cuda::device::numeric_limits<unsigned short>>(rb_mCvCudaDevice, "NumericLimitsUnsigned short").
    define_singleton_function<unsigned short(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<unsigned short(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsInt = define_class_under<cv::cuda::device::numeric_limits<int>>(rb_mCvCudaDevice, "NumericLimitsInt").
    define_singleton_function<int(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<int(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsigned int = define_class_under<cv::cuda::device::numeric_limits<unsigned int>>(rb_mCvCudaDevice, "NumericLimitsUnsigned int").
    define_singleton_function<unsigned int(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<unsigned int(*)()>("max", &cv::cuda::device::numeric_limits::max);
  
  Class rb_cCvCudaDeviceNumericLimitsFloat = define_class_under<cv::cuda::device::numeric_limits<float>>(rb_mCvCudaDevice, "NumericLimitsFloat").
    define_singleton_function<float(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<float(*)()>("max", &cv::cuda::device::numeric_limits::max).
    define_singleton_function<float(*)()>("epsilon", &cv::cuda::device::numeric_limits::epsilon);
  
  Class rb_cCvCudaDeviceNumericLimitsDouble = define_class_under<cv::cuda::device::numeric_limits<double>>(rb_mCvCudaDevice, "NumericLimitsDouble").
    define_singleton_function<double(*)()>("min", &cv::cuda::device::numeric_limits::min).
    define_singleton_function<double(*)()>("max", &cv::cuda::device::numeric_limits::max).
    define_singleton_function<double(*)()>("epsilon", &cv::cuda::device::numeric_limits::epsilon);
}