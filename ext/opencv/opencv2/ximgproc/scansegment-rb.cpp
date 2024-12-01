#include <opencv2/ximgproc/scansegment.hpp>
#include "scansegment-rb.hpp"

using namespace Rice;

extern "C"
void Init_Scansegment()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocScanSegment = define_class_under<cv::ximgproc::ScanSegment, cv::Algorithm>(rb_mCvXimgproc, "ScanSegment").
    define_method<int(cv::ximgproc::ScanSegment::*)()>("get_number_of_superpixels", &cv::ximgproc::ScanSegment::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::ScanSegment::*)(const cv::_InputArray &)>("iterate", &cv::ximgproc::ScanSegment::iterate).
    define_method<void(cv::ximgproc::ScanSegment::*)(const cv::_OutputArray &)>("get_labels", &cv::ximgproc::ScanSegment::getLabels).
    define_method<void(cv::ximgproc::ScanSegment::*)(const cv::_OutputArray &, bool)>("get_label_contour_mask", &cv::ximgproc::ScanSegment::getLabelContourMask);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::ScanSegment>(*)(int, int, int, int, bool)>("create_scan_segment", &cv::ximgproc::createScanSegment);
}