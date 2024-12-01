#include <opencv2/stitching/detail/timelapsers.hpp>
#include "timelapsers-rb.hpp"

using namespace Rice;

extern "C"
void Init_Timelapsers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailTimelapser = define_class_under<cv::detail::Timelapser>(rb_mCvDetail, "Timelapser").
    define_singleton_function<cv::Ptr<cv::detail::Timelapser>(*)(int)>("create_default", &cv::detail::Timelapser::createDefault).
    define_method<void(cv::detail::Timelapser::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("initialize", &cv::detail::Timelapser::initialize).
    define_method<void(cv::detail::Timelapser::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>)>("process", &cv::detail::Timelapser::process).
    define_method<const cv::UMat&(cv::detail::Timelapser::*)()>("get_dst", &cv::detail::Timelapser::getDst);
  
  
  Class rb_cCvDetailTimelapserCrop = define_class_under<cv::detail::TimelapserCrop, cv::detail::Timelapser>(rb_mCvDetail, "TimelapserCrop").
    define_method<void(cv::detail::TimelapserCrop::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("initialize", &cv::detail::TimelapserCrop::initialize);
}