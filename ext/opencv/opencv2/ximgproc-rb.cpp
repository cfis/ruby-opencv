#include <opencv2/ximgproc.hpp>
#include "ximgproc-rb.hpp"

using namespace Rice;

extern "C"
void Init_Ximgproc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Enum<cv::ximgproc::ThinningTypes> rb_cCvXimgprocThinningTypes = define_enum<cv::ximgproc::ThinningTypes>("ThinningTypes", rb_mCvXimgproc).
    define_value("THINNING_ZHANGSUEN", cv::ximgproc::ThinningTypes::THINNING_ZHANGSUEN).
    define_value("THINNING_GUOHALL", cv::ximgproc::ThinningTypes::THINNING_GUOHALL);
  
  Enum<cv::ximgproc::LocalBinarizationMethods> rb_cCvXimgprocLocalBinarizationMethods = define_enum<cv::ximgproc::LocalBinarizationMethods>("LocalBinarizationMethods", rb_mCvXimgproc).
    define_value("BINARIZATION_NIBLACK", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_NIBLACK).
    define_value("BINARIZATION_SAUVOLA", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_SAUVOLA).
    define_value("BINARIZATION_WOLF", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_WOLF).
    define_value("BINARIZATION_NICK", cv::ximgproc::LocalBinarizationMethods::BINARIZATION_NICK);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, int, int, double, int, double)>("ni_black_threshold", &cv::ximgproc::niBlackThreshold);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("thinning", &cv::ximgproc::thinning);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, int)>("anisotropic_diffusion", &cv::ximgproc::anisotropicDiffusion);
}