#include <opencv2/core/operations.hpp>
#include "operations-rb.hpp"

using namespace Rice;

extern "C"
void Init_Operations()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  
  rb_mCv.define_module_function<std::basic_string<char>(*)(const char*, ...)>("format", &cv::format);
}