#include <opencv2/core/cuda/emulation.hpp>
#include "emulation-rb.hpp"

using namespace Rice;

extern "C"
void Init_Emulation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceEmulation = define_class_under<cv::cuda::device::Emulation>(rb_mCvCudaDevice, "Emulation").
    define_singleton_function<int(*)(int)>("syncthreads_or", &cv::cuda::device::Emulation::syncthreadsOr);
  
  Class rb_cCvCudaDeviceEmulationSmem = define_class_under<cv::cuda::device::Emulation::smem>(rb_cCvCudaDeviceEmulation, "Smem");
  
  
  
  Class rb_cCvCudaDeviceEmulationGlob = define_class_under<cv::cuda::device::Emulation::glob>(rb_cCvCudaDeviceEmulation, "Glob").
    define_singleton_function<int(*)(int*, int)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd).
    define_singleton_function<unsigned int(*)(unsigned int*, unsigned int)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd).
    define_singleton_function<float(*)(float*, float)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd).
    define_singleton_function<double(*)(double*, double)>("atomic_add", &cv::cuda::device::Emulation::glob::atomicAdd).
    define_singleton_function<int(*)(int*, int)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin).
    define_singleton_function<float(*)(float*, float)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin).
    define_singleton_function<double(*)(double*, double)>("atomic_min", &cv::cuda::device::Emulation::glob::atomicMin).
    define_singleton_function<int(*)(int*, int)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax).
    define_singleton_function<float(*)(float*, float)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax).
    define_singleton_function<double(*)(double*, double)>("atomic_max", &cv::cuda::device::Emulation::glob::atomicMax);
}