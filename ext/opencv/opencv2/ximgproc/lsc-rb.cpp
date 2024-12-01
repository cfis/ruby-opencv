#include <opencv2/ximgproc/lsc.hpp>
#include "lsc-rb.hpp"

using namespace Rice;

extern "C"
void Init_Lsc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocSuperpixelLSC = define_class_under<cv::ximgproc::SuperpixelLSC, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelLSC").
    define_method<int(cv::ximgproc::SuperpixelLSC::*)() const>("get_number_of_superpixels", &cv::ximgproc::SuperpixelLSC::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(int)>("iterate", &cv::ximgproc::SuperpixelLSC::iterate).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(const cv::_OutputArray &) const>("get_labels", &cv::ximgproc::SuperpixelLSC::getLabels).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(const cv::_OutputArray &, bool) const>("get_label_contour_mask", &cv::ximgproc::SuperpixelLSC::getLabelContourMask).
    define_method<void(cv::ximgproc::SuperpixelLSC::*)(int)>("enforce_label_connectivity", &cv::ximgproc::SuperpixelLSC::enforceLabelConnectivity);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelLSC>(*)(const cv::_InputArray &, int, float)>("create_superpixel_lsc", &cv::ximgproc::createSuperpixelLSC);
}