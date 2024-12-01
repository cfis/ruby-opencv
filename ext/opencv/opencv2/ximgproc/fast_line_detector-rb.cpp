#include <opencv2/ximgproc/fast_line_detector.hpp>
#include "fast_line_detector-rb.hpp"

using namespace Rice;

extern "C"
void Init_FastLineDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocFastLineDetector = define_class_under<cv::ximgproc::FastLineDetector, cv::Algorithm>(rb_mCvXimgproc, "FastLineDetector").
    define_method<void(cv::ximgproc::FastLineDetector::*)(const cv::_InputArray &, const cv::_OutputArray &)>("detect", &cv::ximgproc::FastLineDetector::detect).
    define_method<void(cv::ximgproc::FastLineDetector::*)(const cv::_InputOutputArray &, const cv::_InputArray &, bool, cv::Scalar_<double>, int)>("draw_segments", &cv::ximgproc::FastLineDetector::drawSegments);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastLineDetector>(*)(int, float, double, double, int, bool)>("create_fast_line_detector", &cv::ximgproc::createFastLineDetector);
}