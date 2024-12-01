#include <opencv2/cudev/util/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevMakeVecSchar, 1 = define_class_under<cv::cudev::MakeVec<schar, 1>>(rb_mCvCudev, "MakeVecSchar, 1");
  
  
  Class rb_cCvCudevMakeVecSchar, 2 = define_class_under<cv::cudev::MakeVec<schar, 2>>(rb_mCvCudev, "MakeVecSchar, 2");
  
  
  Class rb_cCvCudevMakeVecSchar, 3 = define_class_under<cv::cudev::MakeVec<schar, 3>>(rb_mCvCudev, "MakeVecSchar, 3");
  
  
  Class rb_cCvCudevMakeVecSchar, 4 = define_class_under<cv::cudev::MakeVec<schar, 4>>(rb_mCvCudev, "MakeVecSchar, 4");
  
  
  Class rb_cCvCudevMakeVecBool, 1 = define_class_under<cv::cudev::MakeVec<bool, 1>>(rb_mCvCudev, "MakeVecBool, 1");
  
  
  Class rb_cCvCudevMakeVecBool, 2 = define_class_under<cv::cudev::MakeVec<bool, 2>>(rb_mCvCudev, "MakeVecBool, 2");
  
  
  Class rb_cCvCudevMakeVecBool, 3 = define_class_under<cv::cudev::MakeVec<bool, 3>>(rb_mCvCudev, "MakeVecBool, 3");
  
  
  Class rb_cCvCudevMakeVecBool, 4 = define_class_under<cv::cudev::MakeVec<bool, 4>>(rb_mCvCudev, "MakeVecBool, 4");
  
  
  Class rb_cCvCudevVecTraitsSchar = define_class_under<cv::cudev::VecTraits<schar>>(rb_mCvCudev, "VecTraitsSchar").
    define_singleton_function<signed char(*)(signed char)>("all", &cv::cudev::VecTraits::all).
    define_singleton_function<signed char(*)(signed char)>("make", &cv::cudev::VecTraits::make).
    define_singleton_function<signed char(*)(const signed char*)>("make", &cv::cudev::VecTraits::make);
  
  
  Class rb_cCvCudevVecTraitsChar1 = define_class_under<cv::cudev::VecTraits<char1>>(rb_mCvCudev, "VecTraitsChar1").
    define_singleton_function<char1(*)(signed char)>("all", &cv::cudev::VecTraits::all).
    define_singleton_function<char1(*)(signed char)>("make", &cv::cudev::VecTraits::make).
    define_singleton_function<char1(*)(const signed char*)>("make", &cv::cudev::VecTraits::make);
  
  
  Class rb_cCvCudevVecTraitsChar2 = define_class_under<cv::cudev::VecTraits<char2>>(rb_mCvCudev, "VecTraitsChar2").
    define_singleton_function<char2(*)(signed char)>("all", &cv::cudev::VecTraits::all).
    define_singleton_function<char2(*)(signed char, signed char)>("make", &cv::cudev::VecTraits::make).
    define_singleton_function<char2(*)(const signed char*)>("make", &cv::cudev::VecTraits::make);
  
  
  Class rb_cCvCudevVecTraitsChar3 = define_class_under<cv::cudev::VecTraits<char3>>(rb_mCvCudev, "VecTraitsChar3").
    define_singleton_function<char3(*)(signed char)>("all", &cv::cudev::VecTraits::all).
    define_singleton_function<char3(*)(signed char, signed char, signed char)>("make", &cv::cudev::VecTraits::make).
    define_singleton_function<char3(*)(const signed char*)>("make", &cv::cudev::VecTraits::make);
  
  
  Class rb_cCvCudevVecTraitsChar4 = define_class_under<cv::cudev::VecTraits<char4>>(rb_mCvCudev, "VecTraitsChar4").
    define_singleton_function<char4(*)(signed char)>("all", &cv::cudev::VecTraits::all).
    define_singleton_function<char4(*)(signed char, signed char, signed char, signed char)>("make", &cv::cudev::VecTraits::make).
    define_singleton_function<char4(*)(const signed char*)>("make", &cv::cudev::VecTraits::make);
  
  
  Class rb_cCvDataTypeUint = define_class_under<cv::DataType<uint>>(rb_mCv, "DataTypeUint");
  
  
  
  Class rb_cCvDataTypeChar1 = define_class_under<cv::DataType<char1>>(rb_mCv, "DataTypeChar1");
  
  
  
  Class rb_cCvDataTypeChar2 = define_class_under<cv::DataType<char2>>(rb_mCv, "DataTypeChar2");
  
  
  
  Class rb_cCvDataTypeChar3 = define_class_under<cv::DataType<char3>>(rb_mCv, "DataTypeChar3");
  
  
  
  Class rb_cCvDataTypeChar4 = define_class_under<cv::DataType<char4>>(rb_mCv, "DataTypeChar4");
}