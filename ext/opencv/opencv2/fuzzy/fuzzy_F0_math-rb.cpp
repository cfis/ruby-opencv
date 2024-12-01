#include <opencv2/fuzzy/fuzzy_F0_math.hpp>
#include "fuzzy_F0_math-rb.hpp"

using namespace Rice;

extern "C"
void Init_FuzzyF0Math()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("ft02_d_components", &cv::ft::FT02D_components);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int)>("ft02_d_inverse_ft", &cv::ft::FT02D_inverseFT);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("ft02_d_process", &cv::ft::FT02D_process);
  
  rb_mCvFt.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool)>("ft02_d_iteration", &cv::ft::FT02D_iteration);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const int, const cv::_OutputArray &)>("ft02_d_fl_process", &cv::ft::FT02D_FL_process);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const int, const cv::_OutputArray &)>("ft02_d_fl_process_float", &cv::ft::FT02D_FL_process_float);
}