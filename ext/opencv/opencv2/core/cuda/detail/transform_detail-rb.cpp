#include <opencv2/core/cuda/detail/transform_detail.hpp>
#include "transform_detail-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T, typename D, int shift>
inline void UnaryReadWriteTraits_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T1, typename T2, typename D, int shift>
inline void BinaryReadWriteTraits_builder(Data_Type_T& klass)
{
};


void Init_TransformDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceTransformDetail = define_module_under(rb_mCvCudaDevice, "TransformDetail");
  
  Class rb_cCvCudaDeviceTransformDetailOpUnroller1 = define_class_under<cv::cuda::device::transform_detail::OpUnroller<1>>(rb_mCvCudaDeviceTransformDetail, "OpUnroller1").
    define_constructor(Constructor<cv::cuda::device::transform_detail::OpUnroller<1>>());
  
  Class rb_cCvCudaDeviceTransformDetailOpUnroller2 = define_class_under<cv::cuda::device::transform_detail::OpUnroller<2>>(rb_mCvCudaDeviceTransformDetail, "OpUnroller2").
    define_constructor(Constructor<cv::cuda::device::transform_detail::OpUnroller<2>>());
  
  Class rb_cCvCudaDeviceTransformDetailOpUnroller3 = define_class_under<cv::cuda::device::transform_detail::OpUnroller<3>>(rb_mCvCudaDeviceTransformDetail, "OpUnroller3").
    define_constructor(Constructor<cv::cuda::device::transform_detail::OpUnroller<3>>());
  
  Class rb_cCvCudaDeviceTransformDetailOpUnroller4 = define_class_under<cv::cuda::device::transform_detail::OpUnroller<4>>(rb_mCvCudaDeviceTransformDetail, "OpUnroller4").
    define_constructor(Constructor<cv::cuda::device::transform_detail::OpUnroller<4>>());
  
  Class rb_cCvCudaDeviceTransformDetailOpUnroller8 = define_class_under<cv::cuda::device::transform_detail::OpUnroller<8>>(rb_mCvCudaDeviceTransformDetail, "OpUnroller8").
    define_constructor(Constructor<cv::cuda::device::transform_detail::OpUnroller<8>>());
  
  Class rb_cCvCudaDeviceTransformDetailTransformDispatcherFalse = define_class_under<cv::cuda::device::transform_detail::TransformDispatcher<false>>(rb_mCvCudaDeviceTransformDetail, "TransformDispatcherFalse").
    define_constructor(Constructor<cv::cuda::device::transform_detail::TransformDispatcher<false>>());
  
  Class rb_cCvCudaDeviceTransformDetailTransformDispatcherTrue = define_class_under<cv::cuda::device::transform_detail::TransformDispatcher<true>>(rb_mCvCudaDeviceTransformDetail, "TransformDispatcherTrue").
    define_constructor(Constructor<cv::cuda::device::transform_detail::TransformDispatcher<true>>());

}