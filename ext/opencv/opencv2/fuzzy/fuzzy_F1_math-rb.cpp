#include <opencv2/fuzzy/fuzzy_F1_math.hpp>
#include "fuzzy_F1_math-rb.hpp"

using namespace Rice;

extern "C"
void Init_FuzzyF1Math()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("ft12_d_components", &cv::ft::FT12D_components);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("ft12_d_polynomial", &cv::ft::FT12D_polynomial);
  
  rb_mCvFt.define_module_function<void(*)(int, const cv::_OutputArray &, const int)>("ft12_d_create_polynom_matrix_vertical", &cv::ft::FT12D_createPolynomMatrixVertical);
  
  rb_mCvFt.define_module_function<void(*)(int, const cv::_OutputArray &, const int)>("ft12_d_create_polynom_matrix_horizontal", &cv::ft::FT12D_createPolynomMatrixHorizontal);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("ft12_d_process", &cv::ft::FT12D_process);
  
  rb_mCvFt.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int)>("ft12_d_inverse_ft", &cv::ft::FT12D_inverseFT);
}