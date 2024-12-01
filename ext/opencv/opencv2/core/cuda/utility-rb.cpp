#include <opencv2/core/cuda/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

extern "C"
void Init_Utility()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceThrustAllocator = define_class_under<cv::cuda::device::ThrustAllocator>(rb_mCvCudaDevice, "ThrustAllocator").
    define_method<unsigned char*(cv::cuda::device::ThrustAllocator::*)(unsigned long long)>("allocate", &cv::cuda::device::ThrustAllocator::allocate).
    define_method<void(cv::cuda::device::ThrustAllocator::*)(unsigned char*, unsigned long long)>("deallocate", &cv::cuda::device::ThrustAllocator::deallocate).
    define_singleton_function<cv::cuda::device::ThrustAllocator&(*)()>("get_allocator", &cv::cuda::device::ThrustAllocator::getAllocator).
    define_singleton_function<void(*)(cv::cuda::device::ThrustAllocator*)>("set_allocator", &cv::cuda::device::ThrustAllocator::setAllocator);
  
  Class rb_cCvCudaDeviceSingleMask = define_class_under<cv::cuda::device::SingleMask>(rb_mCvCudaDevice, "SingleMask").
    define_constructor(Constructor<cv::cuda::device::SingleMask, cv::cuda::PtrStep<unsigned char>>()).
    define_constructor(Constructor<cv::cuda::device::SingleMask, const cv::cuda::device::SingleMask&>()).
    define_method<bool(cv::cuda::device::SingleMask::*)(int, int) const>("operator()", &cv::cuda::device::SingleMask::operator()).
    define_attr("mask", &cv::cuda::device::SingleMask::mask);
  
  Class rb_cCvCudaDeviceSingleMaskChannels = define_class_under<cv::cuda::device::SingleMaskChannels>(rb_mCvCudaDevice, "SingleMaskChannels").
    define_constructor(Constructor<cv::cuda::device::SingleMaskChannels, cv::cuda::PtrStep<unsigned char>, int>()).
    define_constructor(Constructor<cv::cuda::device::SingleMaskChannels, const cv::cuda::device::SingleMaskChannels&>()).
    define_method<bool(cv::cuda::device::SingleMaskChannels::*)(int, int) const>("operator()", &cv::cuda::device::SingleMaskChannels::operator()).
    define_attr("mask", &cv::cuda::device::SingleMaskChannels::mask).
    define_attr("channels", &cv::cuda::device::SingleMaskChannels::channels);
  
  Class rb_cCvCudaDeviceMaskCollection = define_class_under<cv::cuda::device::MaskCollection>(rb_mCvCudaDevice, "MaskCollection").
    define_constructor(Constructor<cv::cuda::device::MaskCollection, cv::cuda::PtrStep<unsigned char>*>()).
    define_constructor(Constructor<cv::cuda::device::MaskCollection, const cv::cuda::device::MaskCollection&>()).
    define_method<void(cv::cuda::device::MaskCollection::*)()>("next", &cv::cuda::device::MaskCollection::next).
    define_method<void(cv::cuda::device::MaskCollection::*)(int)>("set_mask", &cv::cuda::device::MaskCollection::setMask).
    define_method<bool(cv::cuda::device::MaskCollection::*)(int, int) const>("operator()", &cv::cuda::device::MaskCollection::operator()).
    define_attr("mask_collection", &cv::cuda::device::MaskCollection::maskCollection).
    define_attr("cur_mask", &cv::cuda::device::MaskCollection::curMask);
  
  Class rb_cCvCudaDeviceWithOutMask = define_class_under<cv::cuda::device::WithOutMask>(rb_mCvCudaDevice, "WithOutMask").
    define_constructor(Constructor<cv::cuda::device::WithOutMask>()).
    define_constructor(Constructor<cv::cuda::device::WithOutMask, const cv::cuda::device::WithOutMask&>()).
    define_method<void(cv::cuda::device::WithOutMask::*)() const>("next", &cv::cuda::device::WithOutMask::next).
    define_method<void(cv::cuda::device::WithOutMask::*)(int) const>("set_mask", &cv::cuda::device::WithOutMask::setMask).
    define_method<bool(cv::cuda::device::WithOutMask::*)(int, int) const>("operator()", &cv::cuda::device::WithOutMask::operator()).
    define_method<bool(cv::cuda::device::WithOutMask::*)(int, int, int) const>("operator()", &cv::cuda::device::WithOutMask::operator()).
    define_singleton_function<bool(*)(int, int)>("check", &cv::cuda::device::WithOutMask::check).
    define_singleton_function<bool(*)(int, int, int)>("check", &cv::cuda::device::WithOutMask::check);
}