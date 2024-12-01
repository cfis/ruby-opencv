#include <opencv2/ximgproc/ridgefilter.hpp>
#include "ridgefilter-rb.hpp"

using namespace Rice;

extern "C"
void Init_Ridgefilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocRidgeDetectionFilter = define_class_under<cv::ximgproc::RidgeDetectionFilter, cv::Algorithm>(rb_mCvXimgproc, "RidgeDetectionFilter").
    define_singleton_function<cv::Ptr<cv::ximgproc::RidgeDetectionFilter>(*)(int, int, int, int, int, double, double, int)>("create", &cv::ximgproc::RidgeDetectionFilter::create).
    define_method<void(cv::ximgproc::RidgeDetectionFilter::*)(const cv::_InputArray &, const cv::_OutputArray &)>("get_ridge_filtered_image", &cv::ximgproc::RidgeDetectionFilter::getRidgeFilteredImage);
}