#include <opencv2/core/cuda/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceUchar8 = define_class_under<cv::cuda::device::uchar8>(rb_mCvCudaDevice, "Uchar8").
    define_attr("a0", &cv::cuda::device::uchar8::a0).
    define_attr("a1", &cv::cuda::device::uchar8::a1).
    define_attr("a2", &cv::cuda::device::uchar8::a2).
    define_attr("a3", &cv::cuda::device::uchar8::a3).
    define_attr("a4", &cv::cuda::device::uchar8::a4).
    define_attr("a5", &cv::cuda::device::uchar8::a5).
    define_attr("a6", &cv::cuda::device::uchar8::a6).
    define_attr("a7", &cv::cuda::device::uchar8::a7);
  
  Class rb_cCvCudaDeviceChar8 = define_class_under<cv::cuda::device::char8>(rb_mCvCudaDevice, "Char8").
    define_attr("a0", &cv::cuda::device::char8::a0).
    define_attr("a1", &cv::cuda::device::char8::a1).
    define_attr("a2", &cv::cuda::device::char8::a2).
    define_attr("a3", &cv::cuda::device::char8::a3).
    define_attr("a4", &cv::cuda::device::char8::a4).
    define_attr("a5", &cv::cuda::device::char8::a5).
    define_attr("a6", &cv::cuda::device::char8::a6).
    define_attr("a7", &cv::cuda::device::char8::a7);
  
  Class rb_cCvCudaDeviceUshort8 = define_class_under<cv::cuda::device::ushort8>(rb_mCvCudaDevice, "Ushort8").
    define_attr("a0", &cv::cuda::device::ushort8::a0).
    define_attr("a1", &cv::cuda::device::ushort8::a1).
    define_attr("a2", &cv::cuda::device::ushort8::a2).
    define_attr("a3", &cv::cuda::device::ushort8::a3).
    define_attr("a4", &cv::cuda::device::ushort8::a4).
    define_attr("a5", &cv::cuda::device::ushort8::a5).
    define_attr("a6", &cv::cuda::device::ushort8::a6).
    define_attr("a7", &cv::cuda::device::ushort8::a7);
  
  Class rb_cCvCudaDeviceShort8 = define_class_under<cv::cuda::device::short8>(rb_mCvCudaDevice, "Short8").
    define_attr("a0", &cv::cuda::device::short8::a0).
    define_attr("a1", &cv::cuda::device::short8::a1).
    define_attr("a2", &cv::cuda::device::short8::a2).
    define_attr("a3", &cv::cuda::device::short8::a3).
    define_attr("a4", &cv::cuda::device::short8::a4).
    define_attr("a5", &cv::cuda::device::short8::a5).
    define_attr("a6", &cv::cuda::device::short8::a6).
    define_attr("a7", &cv::cuda::device::short8::a7);
  
  Class rb_cCvCudaDeviceUint8 = define_class_under<cv::cuda::device::uint8>(rb_mCvCudaDevice, "Uint8").
    define_attr("a0", &cv::cuda::device::uint8::a0).
    define_attr("a1", &cv::cuda::device::uint8::a1).
    define_attr("a2", &cv::cuda::device::uint8::a2).
    define_attr("a3", &cv::cuda::device::uint8::a3).
    define_attr("a4", &cv::cuda::device::uint8::a4).
    define_attr("a5", &cv::cuda::device::uint8::a5).
    define_attr("a6", &cv::cuda::device::uint8::a6).
    define_attr("a7", &cv::cuda::device::uint8::a7);
  
  Class rb_cCvCudaDeviceInt8 = define_class_under<cv::cuda::device::int8>(rb_mCvCudaDevice, "Int8").
    define_attr("a0", &cv::cuda::device::int8::a0).
    define_attr("a1", &cv::cuda::device::int8::a1).
    define_attr("a2", &cv::cuda::device::int8::a2).
    define_attr("a3", &cv::cuda::device::int8::a3).
    define_attr("a4", &cv::cuda::device::int8::a4).
    define_attr("a5", &cv::cuda::device::int8::a5).
    define_attr("a6", &cv::cuda::device::int8::a6).
    define_attr("a7", &cv::cuda::device::int8::a7);
  
  Class rb_cCvCudaDeviceFloat8 = define_class_under<cv::cuda::device::float8>(rb_mCvCudaDevice, "Float8").
    define_attr("a0", &cv::cuda::device::float8::a0).
    define_attr("a1", &cv::cuda::device::float8::a1).
    define_attr("a2", &cv::cuda::device::float8::a2).
    define_attr("a3", &cv::cuda::device::float8::a3).
    define_attr("a4", &cv::cuda::device::float8::a4).
    define_attr("a5", &cv::cuda::device::float8::a5).
    define_attr("a6", &cv::cuda::device::float8::a6).
    define_attr("a7", &cv::cuda::device::float8::a7);
  
  Class rb_cCvCudaDeviceDouble8 = define_class_under<cv::cuda::device::double8>(rb_mCvCudaDevice, "Double8").
    define_attr("a0", &cv::cuda::device::double8::a0).
    define_attr("a1", &cv::cuda::device::double8::a1).
    define_attr("a2", &cv::cuda::device::double8::a2).
    define_attr("a3", &cv::cuda::device::double8::a3).
    define_attr("a4", &cv::cuda::device::double8::a4).
    define_attr("a5", &cv::cuda::device::double8::a5).
    define_attr("a6", &cv::cuda::device::double8::a6).
    define_attr("a7", &cv::cuda::device::double8::a7);
  
  Class rb_cCvCudaDeviceTypeVecSchar, 1 = define_class_under<cv::cuda::device::TypeVec<schar, 1>>(rb_mCvCudaDevice, "TypeVecSchar, 1");
  
  
  Class rb_cCvCudaDeviceTypeVecSchar, 2 = define_class_under<cv::cuda::device::TypeVec<schar, 2>>(rb_mCvCudaDevice, "TypeVecSchar, 2");
  
  
  Class rb_cCvCudaDeviceTypeVecSchar, 3 = define_class_under<cv::cuda::device::TypeVec<schar, 3>>(rb_mCvCudaDevice, "TypeVecSchar, 3");
  
  
  Class rb_cCvCudaDeviceTypeVecSchar, 4 = define_class_under<cv::cuda::device::TypeVec<schar, 4>>(rb_mCvCudaDevice, "TypeVecSchar, 4");
  
  
  Class rb_cCvCudaDeviceTypeVecSchar, 8 = define_class_under<cv::cuda::device::TypeVec<schar, 8>>(rb_mCvCudaDevice, "TypeVecSchar, 8");
  
  
  Class rb_cCvCudaDeviceTypeVecBool, 1 = define_class_under<cv::cuda::device::TypeVec<bool, 1>>(rb_mCvCudaDevice, "TypeVecBool, 1");
  
  
  Class rb_cCvCudaDeviceTypeVecBool, 2 = define_class_under<cv::cuda::device::TypeVec<bool, 2>>(rb_mCvCudaDevice, "TypeVecBool, 2");
  
  
  Class rb_cCvCudaDeviceTypeVecBool, 3 = define_class_under<cv::cuda::device::TypeVec<bool, 3>>(rb_mCvCudaDevice, "TypeVecBool, 3");
  
  
  Class rb_cCvCudaDeviceTypeVecBool, 4 = define_class_under<cv::cuda::device::TypeVec<bool, 4>>(rb_mCvCudaDevice, "TypeVecBool, 4");
  
  
  Class rb_cCvCudaDeviceTypeVecBool, 8 = define_class_under<cv::cuda::device::TypeVec<bool, 8>>(rb_mCvCudaDevice, "TypeVecBool, 8");
  
  
  Class rb_cCvCudaDeviceVecTraitsChar = define_class_under<cv::cuda::device::VecTraits<char>>(rb_mCvCudaDevice, "VecTraitsChar").
    define_singleton_function<char(*)(char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<char(*)(char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<char(*)(const char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsSchar = define_class_under<cv::cuda::device::VecTraits<schar>>(rb_mCvCudaDevice, "VecTraitsSchar").
    define_singleton_function<signed char(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<signed char(*)(signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<signed char(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsChar1 = define_class_under<cv::cuda::device::VecTraits<char1>>(rb_mCvCudaDevice, "VecTraitsChar1").
    define_singleton_function<char1(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<char1(*)(signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<char1(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsChar2 = define_class_under<cv::cuda::device::VecTraits<char2>>(rb_mCvCudaDevice, "VecTraitsChar2").
    define_singleton_function<char2(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<char2(*)(signed char, signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<char2(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsChar3 = define_class_under<cv::cuda::device::VecTraits<char3>>(rb_mCvCudaDevice, "VecTraitsChar3").
    define_singleton_function<char3(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<char3(*)(signed char, signed char, signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<char3(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsChar4 = define_class_under<cv::cuda::device::VecTraits<char4>>(rb_mCvCudaDevice, "VecTraitsChar4").
    define_singleton_function<char4(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<char4(*)(signed char, signed char, signed char, signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<char4(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
  
  
  Class rb_cCvCudaDeviceVecTraitsChar8 = define_class_under<cv::cuda::device::VecTraits<char8>>(rb_mCvCudaDevice, "VecTraitsChar8").
    define_singleton_function<cv::cuda::device::char8(*)(signed char)>("all", &cv::cuda::device::VecTraits::all).
    define_singleton_function<cv::cuda::device::char8(*)(signed char, signed char, signed char, signed char, signed char, signed char, signed char, signed char)>("make", &cv::cuda::device::VecTraits::make).
    define_singleton_function<cv::cuda::device::char8(*)(const signed char*)>("make", &cv::cuda::device::VecTraits::make);
}