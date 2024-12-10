#include <sstream>
#include <opencv2/core/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp>
inline void DataType_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename _Tp>
inline void DataDepth_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::DataDepth<_Tp>::value).
    define_constant("Fmt", (int)cv::DataDepth<_Tp>::fmt);
};

template<typename Data_Type_T, typename T>
inline void Depth_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::Depth<T>::value);
};

template<typename Data_Type_T, typename T>
inline void Type_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", (int)cv::traits::Type<T>::value);
};

template<typename Data_Type_T, typename T, bool available>
inline void SafeType_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, bool available>
inline void SafeFmt_builder(Data_Type_T& klass)
{
};


void Init_Traits()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvDataTypeBool = define_class_under<cv::DataType<bool>>(rb_mCv, "DataTypeBool").
    define_constructor(Constructor<cv::DataType<bool>>());
  
  rb_cCvDataTypeBool.define_constant("Generic_type", cv::DataType<bool>::generic_type);
  rb_cCvDataTypeBool.define_constant("Depth", cv::DataType<bool>::depth);
  rb_cCvDataTypeBool.define_constant("Channels", cv::DataType<bool>::channels);
  rb_cCvDataTypeBool.define_constant("Fmt", cv::DataType<bool>::fmt);
  rb_cCvDataTypeBool.define_constant("Type", cv::DataType<bool>::type);
  
  Class rb_cCvDataTypeUchar = define_class_under<cv::DataType<uchar>>(rb_mCv, "DataTypeUchar").
    define_constructor(Constructor<cv::DataType<uchar>>());
  
  rb_cCvDataTypeUchar.define_constant("Generic_type", cv::DataType<uchar>::generic_type);
  rb_cCvDataTypeUchar.define_constant("Depth", cv::DataType<uchar>::depth);
  rb_cCvDataTypeUchar.define_constant("Channels", cv::DataType<uchar>::channels);
  rb_cCvDataTypeUchar.define_constant("Fmt", cv::DataType<uchar>::fmt);
  rb_cCvDataTypeUchar.define_constant("Type", cv::DataType<uchar>::type);
  
  Class rb_cCvDataTypeSchar = define_class_under<cv::DataType<schar>>(rb_mCv, "DataTypeSchar").
    define_constructor(Constructor<cv::DataType<schar>>());
  
  rb_cCvDataTypeSchar.define_constant("Generic_type", cv::DataType<schar>::generic_type);
  rb_cCvDataTypeSchar.define_constant("Depth", cv::DataType<schar>::depth);
  rb_cCvDataTypeSchar.define_constant("Channels", cv::DataType<schar>::channels);
  rb_cCvDataTypeSchar.define_constant("Fmt", cv::DataType<schar>::fmt);
  rb_cCvDataTypeSchar.define_constant("Type", cv::DataType<schar>::type);
  
  Class rb_cCvDataTypeChar = define_class_under<cv::DataType<char>>(rb_mCv, "DataTypeChar").
    define_constructor(Constructor<cv::DataType<char>>());
  
  rb_cCvDataTypeChar.define_constant("Generic_type", cv::DataType<char>::generic_type);
  rb_cCvDataTypeChar.define_constant("Depth", cv::DataType<char>::depth);
  rb_cCvDataTypeChar.define_constant("Channels", cv::DataType<char>::channels);
  rb_cCvDataTypeChar.define_constant("Fmt", cv::DataType<char>::fmt);
  rb_cCvDataTypeChar.define_constant("Type", cv::DataType<char>::type);
  
  Class rb_cCvDataTypeUshort = define_class_under<cv::DataType<ushort>>(rb_mCv, "DataTypeUshort").
    define_constructor(Constructor<cv::DataType<ushort>>());
  
  rb_cCvDataTypeUshort.define_constant("Generic_type", cv::DataType<ushort>::generic_type);
  rb_cCvDataTypeUshort.define_constant("Depth", cv::DataType<ushort>::depth);
  rb_cCvDataTypeUshort.define_constant("Channels", cv::DataType<ushort>::channels);
  rb_cCvDataTypeUshort.define_constant("Fmt", cv::DataType<ushort>::fmt);
  rb_cCvDataTypeUshort.define_constant("Type", cv::DataType<ushort>::type);
  
  Class rb_cCvDataTypeShort = define_class_under<cv::DataType<short>>(rb_mCv, "DataTypeShort").
    define_constructor(Constructor<cv::DataType<short>>());
  
  rb_cCvDataTypeShort.define_constant("Generic_type", cv::DataType<short>::generic_type);
  rb_cCvDataTypeShort.define_constant("Depth", cv::DataType<short>::depth);
  rb_cCvDataTypeShort.define_constant("Channels", cv::DataType<short>::channels);
  rb_cCvDataTypeShort.define_constant("Fmt", cv::DataType<short>::fmt);
  rb_cCvDataTypeShort.define_constant("Type", cv::DataType<short>::type);
  
  Class rb_cCvDataTypeInt = define_class_under<cv::DataType<int>>(rb_mCv, "DataTypeInt").
    define_constructor(Constructor<cv::DataType<int>>());
  
  rb_cCvDataTypeInt.define_constant("Generic_type", cv::DataType<int>::generic_type);
  rb_cCvDataTypeInt.define_constant("Depth", cv::DataType<int>::depth);
  rb_cCvDataTypeInt.define_constant("Channels", cv::DataType<int>::channels);
  rb_cCvDataTypeInt.define_constant("Fmt", cv::DataType<int>::fmt);
  rb_cCvDataTypeInt.define_constant("Type", cv::DataType<int>::type);
  
  Class rb_cCvDataTypeFloat = define_class_under<cv::DataType<float>>(rb_mCv, "DataTypeFloat").
    define_constructor(Constructor<cv::DataType<float>>());
  
  rb_cCvDataTypeFloat.define_constant("Generic_type", cv::DataType<float>::generic_type);
  rb_cCvDataTypeFloat.define_constant("Depth", cv::DataType<float>::depth);
  rb_cCvDataTypeFloat.define_constant("Channels", cv::DataType<float>::channels);
  rb_cCvDataTypeFloat.define_constant("Fmt", cv::DataType<float>::fmt);
  rb_cCvDataTypeFloat.define_constant("Type", cv::DataType<float>::type);
  
  Class rb_cCvDataTypeDouble = define_class_under<cv::DataType<double>>(rb_mCv, "DataTypeDouble").
    define_constructor(Constructor<cv::DataType<double>>());
  
  rb_cCvDataTypeDouble.define_constant("Generic_type", cv::DataType<double>::generic_type);
  rb_cCvDataTypeDouble.define_constant("Depth", cv::DataType<double>::depth);
  rb_cCvDataTypeDouble.define_constant("Channels", cv::DataType<double>::channels);
  rb_cCvDataTypeDouble.define_constant("Fmt", cv::DataType<double>::fmt);
  rb_cCvDataTypeDouble.define_constant("Type", cv::DataType<double>::type);
  
  Class rb_cCvDataTypeHfloat = define_class_under<cv::DataType<cv::hfloat>>(rb_mCv, "DataTypeHfloat").
    define_constructor(Constructor<cv::DataType<cv::hfloat>>());
  
  rb_cCvDataTypeHfloat.define_constant("Generic_type", cv::DataType<hfloat>::generic_type);
  rb_cCvDataTypeHfloat.define_constant("Depth", cv::DataType<hfloat>::depth);
  rb_cCvDataTypeHfloat.define_constant("Channels", cv::DataType<hfloat>::channels);
  rb_cCvDataTypeHfloat.define_constant("Fmt", cv::DataType<hfloat>::fmt);
  rb_cCvDataTypeHfloat.define_constant("Type", cv::DataType<hfloat>::type);
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  Module rb_mCvTraitsInternal = define_module_under(rb_mCvTraits, "Internal");
  

}