#include <opencv2/xobjdetect.hpp>
#include "xobjdetect-rb.hpp"

using namespace Rice;

extern "C"
void Init_Xobjdetect()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXobjdetect = define_module_under(rb_mCv, "Xobjdetect");
  
  Class rb_cCvXobjdetectWBDetector = define_class_under<cv::xobjdetect::WBDetector>(rb_mCvXobjdetect, "WBDetector").
    define_method<void(cv::xobjdetect::WBDetector::*)(const cv::FileNode&)>("read", &cv::xobjdetect::WBDetector::read).
    define_method<void(cv::xobjdetect::WBDetector::*)(cv::FileStorage&) const>("write", &cv::xobjdetect::WBDetector::write).
    define_method<void(cv::xobjdetect::WBDetector::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("train", &cv::xobjdetect::WBDetector::train).
    define_method<void(cv::xobjdetect::WBDetector::*)(const cv::Mat&, std::vector<cv::Rect_<int>>&, std::vector<double>&)>("detect", &cv::xobjdetect::WBDetector::detect).
    define_singleton_function<cv::Ptr<cv::xobjdetect::WBDetector>(*)()>("create", &cv::xobjdetect::WBDetector::create);
}