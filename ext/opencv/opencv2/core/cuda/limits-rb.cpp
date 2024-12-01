#include <sstream>
#include <opencv2/core/cuda/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void numeric_limits_builder(Data_Type_T& klass)
{
};


void Init_Limits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceNumericLimitsBool = define_class_under<cv::cuda::device::numeric_limits<bool>>(rb_mCvCudaDevice, "NumericLimitsBool").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<bool>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<bool>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsSignedChar = define_class_under<cv::cuda::device::numeric_limits<signed char>>(rb_mCvCudaDevice, "NumericLimitsSignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<signed char>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<signed char>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsignedChar = define_class_under<cv::cuda::device::numeric_limits<unsigned char>>(rb_mCvCudaDevice, "NumericLimitsUnsignedChar").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned char>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned char>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsShort = define_class_under<cv::cuda::device::numeric_limits<short>>(rb_mCvCudaDevice, "NumericLimitsShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<short>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<short>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsignedShort = define_class_under<cv::cuda::device::numeric_limits<unsigned short>>(rb_mCvCudaDevice, "NumericLimitsUnsignedShort").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned short>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned short>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsInt = define_class_under<cv::cuda::device::numeric_limits<int>>(rb_mCvCudaDevice, "NumericLimitsInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<int>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<int>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsUnsignedInt = define_class_under<cv::cuda::device::numeric_limits<unsigned int>>(rb_mCvCudaDevice, "NumericLimitsUnsignedInt").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<unsigned int>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<unsigned int>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsFloat = define_class_under<cv::cuda::device::numeric_limits<float>>(rb_mCvCudaDevice, "NumericLimitsFloat").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<float>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<float>::__forceinline__);
  
  Class rb_cCvCudaDeviceNumericLimitsDouble = define_class_under<cv::cuda::device::numeric_limits<double>>(rb_mCvCudaDevice, "NumericLimitsDouble").
    define_constructor(Constructor<cv::cuda::device::numeric_limits<double>>()).
    define_attr("__forceinline__", &cv::cuda::device::numeric_limits<double>::__forceinline__);

}