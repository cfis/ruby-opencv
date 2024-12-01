#include <opencv2/intensity_transform.hpp>
#include "intensity_transform-rb.hpp"

using namespace Rice;

extern "C"
void Init_IntensityTransform()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvIntensityTransform = define_module_under(rb_mCv, "IntensityTransform");
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&)>("log_transform", &cv::intensity_transform::logTransform);
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&, const float)>("gamma_correction", &cv::intensity_transform::gammaCorrection);
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&)>("autoscaling", &cv::intensity_transform::autoscaling);
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::Mat, cv::Mat&, const int, const int, const int, const int)>("contrast_stretching", &cv::intensity_transform::contrastStretching);
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, float)>("bimef", &cv::intensity_transform::BIMEF);
  
  rb_mCvIntensityTransform.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, float, float)>("bimef", &cv::intensity_transform::BIMEF);
}