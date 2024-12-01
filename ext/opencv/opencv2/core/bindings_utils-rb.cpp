#include <opencv2/core/bindings_utils.hpp>
#include "bindings_utils-rb.hpp"

using namespace Rice;

extern "C"
void Init_BindingsUtils()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const cv::_InputArray &)>("dump_input_array", &cv::utils::dumpInputArray);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const cv::_InputArray &)>("dump_input_array_of_arrays", &cv::utils::dumpInputArrayOfArrays);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const cv::_InputOutputArray &)>("dump_input_output_array", &cv::utils::dumpInputOutputArray);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const cv::_InputOutputArray &)>("dump_input_output_array_of_arrays", &cv::utils::dumpInputOutputArrayOfArrays);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const std::vector<int>&)>("dump_vector_of_int", &cv::utils::dumpVectorOfInt);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const std::vector<double>&)>("dump_vector_of_double", &cv::utils::dumpVectorOfDouble);
  
  rb_mCvUtils.define_module_function<std::basic_string<char>(*)(const std::vector<cv::Rect_<int>>&)>("dump_vector_of_rect", &cv::utils::dumpVectorOfRect);
  
  Class rb_cCvUtilsClassWithKeywordProperties = define_class_under<cv::utils::ClassWithKeywordProperties>(rb_mCvUtils, "ClassWithKeywordProperties").
    define_attr("lambda", &cv::utils::ClassWithKeywordProperties::lambda).
    define_attr("except", &cv::utils::ClassWithKeywordProperties::except).
    define_constructor(Constructor<cv::utils::ClassWithKeywordProperties, int, int>());
  
  Class rb_cCvUtilsFunctionParams = define_class_under<cv::utils::FunctionParams>(rb_mCvUtils, "FunctionParams").
    define_attr("lambda", &cv::utils::FunctionParams::lambda).
    define_attr("sigma", &cv::utils::FunctionParams::sigma).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(int) noexcept>("set_lambda", &cv::utils::FunctionParams::setLambda).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(float) noexcept>("set_sigma", &cv::utils::FunctionParams::setSigma);
  
  Module rb_mCvUtilsNested = define_module_under(rb_mCvUtils, "Nested");
  
  Class rb_cCvUtilsNestedOriginalClassName = define_class_under<cv::utils::nested::OriginalClassName>(rb_mCvUtilsNested, "OriginalClassName").
    define_constructor(Constructor<cv::utils::nested::OriginalClassName, const cv::utils::nested::OriginalClassName::Params&>()).
    define_method<int(cv::utils::nested::OriginalClassName::*)() const>("get_int_param", &cv::utils::nested::OriginalClassName::getIntParam).
    define_method<float(cv::utils::nested::OriginalClassName::*)() const>("get_float_param", &cv::utils::nested::OriginalClassName::getFloatParam).
    define_singleton_function<std::basic_string<char>(*)()>("original_name", &cv::utils::nested::OriginalClassName::originalName).
    define_singleton_function<cv::Ptr<cv::utils::nested::OriginalClassName>(*)(const cv::utils::nested::OriginalClassName::Params&)>("create", &cv::utils::nested::OriginalClassName::create);
  
  Class rb_cCvUtilsNestedOriginalClassNameParams = define_class_under<cv::utils::nested::OriginalClassName::Params>(rb_cCvUtilsNestedOriginalClassName, "Params").
    define_attr("int_value", &cv::utils::nested::OriginalClassName::Params::int_value).
    define_attr("float_value", &cv::utils::nested::OriginalClassName::Params::float_value).
    define_constructor(Constructor<cv::utils::nested::OriginalClassName::Params, int, float>());
  
  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<char>(*)()>("get_cache_directory_for_downloads", &cv::utils::fs::getCacheDirectoryForDownloads);
}