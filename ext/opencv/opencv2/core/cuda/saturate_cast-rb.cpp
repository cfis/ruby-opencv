#include <opencv2/core/cuda/saturate_cast.hpp>
#include "saturate_cast-rb.hpp"

using namespace Rice;

extern "C"
void Init_SaturateCast()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(signed char)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(unsigned short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(unsigned int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned char(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(unsigned char)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(unsigned short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(unsigned int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<signed char(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(signed char)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(unsigned int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned short(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<short(*)(unsigned short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<short(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<short(*)(unsigned int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<short(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<short(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<int(*)(unsigned int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<int(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<int(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(signed char)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(short)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(int)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(float)>("saturate_cast", &cv::cuda::device::saturate_cast);
  
  rb_mCvCudaDevice.define_module_function<unsigned int(*)(double)>("saturate_cast", &cv::cuda::device::saturate_cast);
}