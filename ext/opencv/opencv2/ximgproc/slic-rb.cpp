#include <opencv2/ximgproc/slic.hpp>
#include "slic-rb.hpp"

using namespace Rice;

extern "C"
void Init_Slic()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Enum<cv::ximgproc::SLICType> rb_cCvXimgprocSLICType = define_enum<cv::ximgproc::SLICType>("SLICType", rb_mCvXimgproc).
    define_value("SLIC", cv::ximgproc::SLICType::SLIC).
    define_value("SLICO", cv::ximgproc::SLICType::SLICO).
    define_value("MSLIC", cv::ximgproc::SLICType::MSLIC);
  
  Class rb_cCvXimgprocSuperpixelSLIC = define_class_under<cv::ximgproc::SuperpixelSLIC, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelSLIC").
    define_method<int(cv::ximgproc::SuperpixelSLIC::*)() const>("get_number_of_superpixels", &cv::ximgproc::SuperpixelSLIC::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(int)>("iterate", &cv::ximgproc::SuperpixelSLIC::iterate).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(const cv::_OutputArray &) const>("get_labels", &cv::ximgproc::SuperpixelSLIC::getLabels).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(const cv::_OutputArray &, bool) const>("get_label_contour_mask", &cv::ximgproc::SuperpixelSLIC::getLabelContourMask).
    define_method<void(cv::ximgproc::SuperpixelSLIC::*)(int)>("enforce_label_connectivity", &cv::ximgproc::SuperpixelSLIC::enforceLabelConnectivity);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelSLIC>(*)(const cv::_InputArray &, int, int, float)>("create_superpixel_slic", &cv::ximgproc::createSuperpixelSLIC);
}