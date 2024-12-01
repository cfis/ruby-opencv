#include <sstream>
#include <opencv2/core/bindings_utils.hpp>
#include "bindings_utils-rb.hpp"

using namespace Rice;



void Init_BindingsUtils()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputArray)>("dump_input_array", &cv::utils::dumpInputArray,
    Arg("argument"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputArrayOfArrays)>("dump_input_array_of_arrays", &cv::utils::dumpInputArrayOfArrays,
    Arg("argument"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputOutputArray)>("dump_input_output_array", &cv::utils::dumpInputOutputArray,
    Arg("argument"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(cv::InputOutputArrayOfArrays)>("dump_input_output_array_of_arrays", &cv::utils::dumpInputOutputArrayOfArrays,
    Arg("argument"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<int>&)>("dump_vector_of_int", &cv::utils::dumpVectorOfInt,
    Arg("vec"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<double>&)>("dump_vector_of_double", &cv::utils::dumpVectorOfDouble,
    Arg("vec"));
  
  rb_mCvUtils.define_module_function<cv::String(*)(const std::vector<cv::Rect_<int>>&)>("dump_vector_of_rect", &cv::utils::dumpVectorOfRect,
    Arg("vec"));
  
  Class rb_cCvUtilsClassWithKeywordProperties = define_class_under<cv::utils::ClassWithKeywordProperties>(rb_mCvUtils, "ClassWithKeywordProperties").
    define_attr("lambda", &cv::utils::ClassWithKeywordProperties::lambda).
    define_attr("except", &cv::utils::ClassWithKeywordProperties::except).
    define_constructor(Constructor<cv::utils::ClassWithKeywordProperties, int, int>(),
      Arg("lambda_arg") = 24, Arg("except_arg") = 42);
  
  Class rb_cCvUtilsFunctionParams = define_class_under<cv::utils::FunctionParams>(rb_mCvUtils, "FunctionParams").
    define_constructor(Constructor<cv::utils::FunctionParams>()).
    define_attr("lambda", &cv::utils::FunctionParams::lambda).
    define_attr("sigma", &cv::utils::FunctionParams::sigma).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(int) noexcept>("set_lambda", &cv::utils::FunctionParams::setLambda,
      Arg("value")).
    define_method<cv::utils::FunctionParams&(cv::utils::FunctionParams::*)(float) noexcept>("set_sigma", &cv::utils::FunctionParams::setSigma,
      Arg("value"));
  
  Module rb_mCvUtilsNested = define_module_under(rb_mCvUtils, "Nested");
  
  Class rb_cCvUtilsNestedOriginalClassName = define_class_under<cv::utils::nested::OriginalClassName>(rb_mCvUtilsNested, "OriginalClassName").
    define_constructor(Constructor<cv::utils::nested::OriginalClassName, const cv::utils::nested::OriginalClassName::Params&>(),
      Arg("params")).
    define_method<int(cv::utils::nested::OriginalClassName::*)() const>("get_int_param", &cv::utils::nested::OriginalClassName::getIntParam).
    define_method<float(cv::utils::nested::OriginalClassName::*)() const>("get_float_param", &cv::utils::nested::OriginalClassName::getFloatParam).
    define_singleton_function<std::string(*)()>("original_name", &cv::utils::nested::OriginalClassName::originalName).
    define_singleton_function<cv::Ptr<cv::utils::nested::OriginalClassName>(*)(const cv::utils::nested::OriginalClassName::Params&)>("create", &cv::utils::nested::OriginalClassName::create,
      Arg("params"));
  
  Class rb_cCvUtilsNestedOriginalClassNameParams = define_class_under<cv::utils::nested::OriginalClassName::Params>(rb_cCvUtilsNestedOriginalClassName, "Params").
    define_attr("int_value", &cv::utils::nested::OriginalClassName::Params::int_value).
    define_attr("float_value", &cv::utils::nested::OriginalClassName::Params::float_value).
    define_constructor(Constructor<cv::utils::nested::OriginalClassName::Params, int, float>(),
      Arg("int_param") = 123, Arg("float_param") = 3.5f);
  
  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");
  
  rb_mCvUtilsFs.define_module_function<cv::String(*)()>("get_cache_directory_for_downloads", &cv::utils::fs::getCacheDirectoryForDownloads);

}