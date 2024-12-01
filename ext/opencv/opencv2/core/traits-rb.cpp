#include <opencv2/core/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

extern "C"
void Init_Traits()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvDataTypeBool = define_class_under<cv::DataType<bool>>(rb_mCv, "DataTypeBool");
  
  
  
  Class rb_cCvDataTypeUchar = define_class_under<cv::DataType<uchar>>(rb_mCv, "DataTypeUchar");
  
  
  
  Class rb_cCvDataTypeSchar = define_class_under<cv::DataType<schar>>(rb_mCv, "DataTypeSchar");
  
  
  
  Class rb_cCvDataTypeChar = define_class_under<cv::DataType<char>>(rb_mCv, "DataTypeChar");
  
  
  
  Class rb_cCvDataTypeUshort = define_class_under<cv::DataType<ushort>>(rb_mCv, "DataTypeUshort");
  
  
  
  Class rb_cCvDataTypeShort = define_class_under<cv::DataType<short>>(rb_mCv, "DataTypeShort");
  
  
  
  Class rb_cCvDataTypeInt = define_class_under<cv::DataType<int>>(rb_mCv, "DataTypeInt");
  
  
  
  Class rb_cCvDataTypeFloat = define_class_under<cv::DataType<float>>(rb_mCv, "DataTypeFloat");
  
  
  
  Class rb_cCvDataTypeDouble = define_class_under<cv::DataType<double>>(rb_mCv, "DataTypeDouble");
  
  
  
//  Class rb_cCvDataTypeFloat16T = define_class_under<cv::DataType<float16_t>>(rb_mCv, "DataTypeFloat16T");
  
  
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  Module rb_mCvTraitsInternal = define_module_under(rb_mCvTraits, "Internal");
}