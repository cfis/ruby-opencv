#include <opencv2/ximgproc/estimated_covariance.hpp>
#include "estimated_covariance-rb.hpp"

using namespace Rice;

extern "C"
void Init_EstimatedCovariance()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("covariance_estimation", &cv::ximgproc::covarianceEstimation);
}