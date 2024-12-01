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
};

template<typename Data_Type_T, typename T>
inline void Depth_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void Type_builder(Data_Type_T& klass)
{
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
  
  
  Class rb_cCvDataTypeUchar = define_class_under<cv::DataType<uchar>>(rb_mCv, "DataTypeUchar").
    define_constructor(Constructor<cv::DataType<uchar>>());
  
  
  Class rb_cCvDataTypeSchar = define_class_under<cv::DataType<schar>>(rb_mCv, "DataTypeSchar").
    define_constructor(Constructor<cv::DataType<schar>>());
  
  
  Class rb_cCvDataTypeChar = define_class_under<cv::DataType<char>>(rb_mCv, "DataTypeChar").
    define_constructor(Constructor<cv::DataType<char>>());
  
  
  Class rb_cCvDataTypeUshort = define_class_under<cv::DataType<ushort>>(rb_mCv, "DataTypeUshort").
    define_constructor(Constructor<cv::DataType<ushort>>());
  
  
  Class rb_cCvDataTypeShort = define_class_under<cv::DataType<short>>(rb_mCv, "DataTypeShort").
    define_constructor(Constructor<cv::DataType<short>>());
  
  
  Class rb_cCvDataTypeInt = define_class_under<cv::DataType<int>>(rb_mCv, "DataTypeInt").
    define_constructor(Constructor<cv::DataType<int>>());
  
  
  Class rb_cCvDataTypeFloat = define_class_under<cv::DataType<float>>(rb_mCv, "DataTypeFloat").
    define_constructor(Constructor<cv::DataType<float>>());
  
  
  Class rb_cCvDataTypeDouble = define_class_under<cv::DataType<double>>(rb_mCv, "DataTypeDouble").
    define_constructor(Constructor<cv::DataType<double>>());
  
  
  Class rb_cCvDataTypeHfloat = define_class_under<cv::DataType<cv::hfloat>>(rb_mCv, "DataTypeHfloat").
    define_constructor(Constructor<cv::DataType<cv::hfloat>>());
  
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  Module rb_mCvTraitsInternal = define_module_under(rb_mCvTraits, "Internal");
  

}