#include <opencv2/core/va_intel.hpp>
#include "va_intel-rb.hpp"

using namespace Rice;

extern "C"
void Init_VaIntel()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVaIntel = define_module_under(rb_mCv, "VaIntel");
  
  Module rb_mCvVaIntelOcl = define_module_under(rb_mCvVaIntel, "Ocl");
  
  rb_mCvVaIntelOcl.define_module_function<cv::ocl::Context&(*)(void *, bool)>("initialize_context_from_va", &cv::va_intel::ocl::initializeContextFromVA);
  
  rb_mCvVaIntel.define_module_function<void(*)(void *, const cv::_InputArray &, unsigned int, cv::Size_<int>)>("convert_to_va_surface", &cv::va_intel::convertToVASurface);
  
  rb_mCvVaIntel.define_module_function<void(*)(void *, unsigned int, cv::Size_<int>, const cv::_OutputArray &)>("convert_from_va_surface", &cv::va_intel::convertFromVASurface);
}