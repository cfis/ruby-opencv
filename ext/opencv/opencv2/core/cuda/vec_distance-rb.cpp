#include <opencv2/core/cuda/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecDistance()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceL1DistFloat = define_class_under<cv::cuda::device::L1Dist<float>>(rb_mCvCudaDevice, "L1DistFloat").
    define_constructor(Constructor<cv::cuda::device::L1Dist>()).
    define_method<void(cv::cuda::device::L1Dist::*)(float, float)>("reduce_iter", &cv::cuda::device::L1Dist::reduceIter).
    define_attr("my_sum", &cv::cuda::device::L1Dist::mySum);
  
  Class rb_cCvCudaDeviceL2Dist = define_class_under<cv::cuda::device::L2Dist>(rb_mCvCudaDevice, "L2Dist").
    define_constructor(Constructor<cv::cuda::device::L2Dist>()).
    define_method<void(cv::cuda::device::L2Dist::*)(float, float)>("reduce_iter", &cv::cuda::device::L2Dist::reduceIter).
    define_attr("my_sum", &cv::cuda::device::L2Dist::mySum);
  
  Class rb_cCvCudaDeviceHammingDist = define_class_under<cv::cuda::device::HammingDist>(rb_mCvCudaDevice, "HammingDist").
    define_constructor(Constructor<cv::cuda::device::HammingDist>()).
    define_method<void(cv::cuda::device::HammingDist::*)(int, int)>("reduce_iter", &cv::cuda::device::HammingDist::reduceIter).
    define_attr("my_sum", &cv::cuda::device::HammingDist::mySum);
}