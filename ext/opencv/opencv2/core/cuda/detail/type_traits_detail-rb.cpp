#include <opencv2/core/cuda/detail/type_traits_detail.hpp>
#include "type_traits_detail-rb.hpp"

using namespace Rice;

extern "C"
void Init_TypeTraitsDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceTypeTraitsDetail = define_module_under(rb_mCvCudaDevice, "TypeTraitsDetail");
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralSchar");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralChar1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<char1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralChar1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<char>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralChar");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<bool>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralBool");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<float>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatFloat");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<double>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatDouble");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecChar1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecChar2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecChar3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecChar4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecChar8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecShort1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecShort2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecShort3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecShort4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecShort8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUint1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUint2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUint3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUint4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecUint8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecInt1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecInt2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecInt3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecInt4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecInt8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble1");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble2");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble3");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble4");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble8");
  
  
  
  Class rb_cCvCudaDeviceTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cuda::device::type_traits_detail::AddParameterType<void>>(rb_mCvCudaDeviceTypeTraitsDetail, "AddParameterTypeVoid");
}