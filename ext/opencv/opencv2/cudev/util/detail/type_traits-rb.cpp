#include <opencv2/cudev/util/detail/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_TypeTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevTypeTraitsDetail = define_module_under(rb_mCvCudev, "TypeTraitsDetail");
  
  Class rb_cCvCudevTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralSchar");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralShort");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralInt");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUchar");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUshort");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUint");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsIntegralChar = define_class_under<cv::cudev::type_traits_detail::IsIntegral<char>>(rb_mCvCudevTypeTraitsDetail, "IsIntegralChar");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsIntegralBool = define_class_under<cv::cudev::type_traits_detail::IsIntegral<bool>>(rb_mCvCudevTypeTraitsDetail, "IsIntegralBool");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsFloatFloat = define_class_under<cv::cudev::type_traits_detail::IsFloat<float>>(rb_mCvCudevTypeTraitsDetail, "IsFloatFloat");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsFloatDouble = define_class_under<cv::cudev::type_traits_detail::IsFloat<double>>(rb_mCvCudevTypeTraitsDetail, "IsFloatDouble");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUchar1 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUchar2 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUchar3 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUchar4 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecChar1 = define_class_under<cv::cudev::type_traits_detail::IsVec<char1>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecChar2 = define_class_under<cv::cudev::type_traits_detail::IsVec<char2>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecChar3 = define_class_under<cv::cudev::type_traits_detail::IsVec<char3>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecChar4 = define_class_under<cv::cudev::type_traits_detail::IsVec<char4>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUshort1 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUshort2 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUshort3 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUshort4 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecShort1 = define_class_under<cv::cudev::type_traits_detail::IsVec<short1>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecShort2 = define_class_under<cv::cudev::type_traits_detail::IsVec<short2>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecShort3 = define_class_under<cv::cudev::type_traits_detail::IsVec<short3>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecShort4 = define_class_under<cv::cudev::type_traits_detail::IsVec<short4>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUint1 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUint2 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUint3 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecUint4 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecInt1 = define_class_under<cv::cudev::type_traits_detail::IsVec<int1>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecInt2 = define_class_under<cv::cudev::type_traits_detail::IsVec<int2>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecInt3 = define_class_under<cv::cudev::type_traits_detail::IsVec<int3>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecInt4 = define_class_under<cv::cudev::type_traits_detail::IsVec<int4>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecFloat1 = define_class_under<cv::cudev::type_traits_detail::IsVec<float1>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecFloat2 = define_class_under<cv::cudev::type_traits_detail::IsVec<float2>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecFloat3 = define_class_under<cv::cudev::type_traits_detail::IsVec<float3>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecFloat4 = define_class_under<cv::cudev::type_traits_detail::IsVec<float4>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecDouble1 = define_class_under<cv::cudev::type_traits_detail::IsVec<double1>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble1");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecDouble2 = define_class_under<cv::cudev::type_traits_detail::IsVec<double2>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble2");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecDouble3 = define_class_under<cv::cudev::type_traits_detail::IsVec<double3>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble3");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailIsVecDouble4 = define_class_under<cv::cudev::type_traits_detail::IsVec<double4>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble4");
  
  
  
  Class rb_cCvCudevTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cudev::type_traits_detail::AddParameterType<void>>(rb_mCvCudevTypeTraitsDetail, "AddParameterTypeVoid");
  
  
  Class rb_cCvCudevTypeTraitsDetailLargerDepthFloat, float = define_class_under<cv::cudev::type_traits_detail::LargerDepth<float, float>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthFloat, float");
  
  
  Class rb_cCvCudevTypeTraitsDetailLargerDepthFloat, double = define_class_under<cv::cudev::type_traits_detail::LargerDepth<float, double>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthFloat, double");
  
  
  Class rb_cCvCudevTypeTraitsDetailLargerDepthDouble, float = define_class_under<cv::cudev::type_traits_detail::LargerDepth<double, float>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthDouble, float");
  
  
  Class rb_cCvCudevTypeTraitsDetailLargerDepthDouble, double = define_class_under<cv::cudev::type_traits_detail::LargerDepth<double, double>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthDouble, double");
}