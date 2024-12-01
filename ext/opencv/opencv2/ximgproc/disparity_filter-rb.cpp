#include <opencv2/ximgproc/disparity_filter.hpp>
#include "disparity_filter-rb.hpp"

using namespace Rice;

extern "C"
void Init_DisparityFilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocDisparityFilter = define_class_under<cv::ximgproc::DisparityFilter, cv::Algorithm>(rb_mCvXimgproc, "DisparityFilter").
    define_method<void(cv::ximgproc::DisparityFilter::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Rect_<int>, const cv::_InputArray &)>("filter", &cv::ximgproc::DisparityFilter::filter);
  
  Class rb_cCvXimgprocDisparityWLSFilter = define_class_under<cv::ximgproc::DisparityWLSFilter, cv::ximgproc::DisparityFilter>(rb_mCvXimgproc, "DisparityWLSFilter").
    define_method<double(cv::ximgproc::DisparityWLSFilter::*)()>("get_lambda", &cv::ximgproc::DisparityWLSFilter::getLambda).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(double)>("set_lambda", &cv::ximgproc::DisparityWLSFilter::setLambda).
    define_method<double(cv::ximgproc::DisparityWLSFilter::*)()>("get_sigma_color", &cv::ximgproc::DisparityWLSFilter::getSigmaColor).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(double)>("set_sigma_color", &cv::ximgproc::DisparityWLSFilter::setSigmaColor).
    define_method<int(cv::ximgproc::DisparityWLSFilter::*)()>("get_lr_cthresh", &cv::ximgproc::DisparityWLSFilter::getLRCthresh).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(int)>("set_lr_cthresh", &cv::ximgproc::DisparityWLSFilter::setLRCthresh).
    define_method<int(cv::ximgproc::DisparityWLSFilter::*)()>("get_depth_discontinuity_radius", &cv::ximgproc::DisparityWLSFilter::getDepthDiscontinuityRadius).
    define_method<void(cv::ximgproc::DisparityWLSFilter::*)(int)>("set_depth_discontinuity_radius", &cv::ximgproc::DisparityWLSFilter::setDepthDiscontinuityRadius).
    define_method<cv::Mat(cv::ximgproc::DisparityWLSFilter::*)()>("get_confidence_map", &cv::ximgproc::DisparityWLSFilter::getConfidenceMap).
    define_method<cv::Rect_<int>(cv::ximgproc::DisparityWLSFilter::*)()>("get_roi", &cv::ximgproc::DisparityWLSFilter::getROI);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DisparityWLSFilter>(*)(cv::Ptr<cv::StereoMatcher>)>("create_disparity_wls_filter", &cv::ximgproc::createDisparityWLSFilter);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::StereoMatcher>(*)(cv::Ptr<cv::StereoMatcher>)>("create_right_matcher", &cv::ximgproc::createRightMatcher);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DisparityWLSFilter>(*)(bool)>("create_disparity_wls_filter_generic", &cv::ximgproc::createDisparityWLSFilterGeneric);
  
  rb_mCvXimgproc.define_module_function<int(*)(std::basic_string<char>, const cv::_OutputArray &)>("read_gt", &cv::ximgproc::readGT);
  
  rb_mCvXimgproc.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Rect_<int>)>("compute_mse", &cv::ximgproc::computeMSE);
  
  rb_mCvXimgproc.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Rect_<int>, int)>("compute_bad_pixel_percent", &cv::ximgproc::computeBadPixelPercent);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("get_disparity_vis", &cv::ximgproc::getDisparityVis);
}