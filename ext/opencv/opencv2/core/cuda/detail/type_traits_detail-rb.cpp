#include <sstream>
#include <opencv2/core/cuda/detail/type_traits_detail.hpp>
#include "type_traits_detail-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, bool , typename T1, typename T2>
inline void Select_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsSignedIntergral_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsUnsignedIntegral_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsIntegral_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsFloat_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void IsVec_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void AddParameterType_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void ReferenceTraits_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void PointerTraits_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void UnConst_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename U>
inline void UnVolatile_builder(Data_Type_T& klass)
{
};


void Init_TypeTraitsDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceTypeTraitsDetail = define_module_under(rb_mCvCudaDevice, "TypeTraitsDetail");
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralSchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<char>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralChar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<char>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<bool>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralBool").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<bool>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<float>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatFloat").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<float>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<double>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatDouble").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<double>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>());
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cuda::device::type_traits_detail::AddParameterType<void>>(rb_mCvCudaDeviceTypeTraitsDetail, "AddParameterTypeVoid").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::AddParameterType<void>>());

}