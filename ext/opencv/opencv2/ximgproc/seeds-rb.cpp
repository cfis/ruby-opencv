#include <opencv2/ximgproc/seeds.hpp>
#include "seeds-rb.hpp"

using namespace Rice;

extern "C"
void Init_Seeds()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocSuperpixelSEEDS = define_class_under<cv::ximgproc::SuperpixelSEEDS, cv::Algorithm>(rb_mCvXimgproc, "SuperpixelSEEDS").
    define_method<int(cv::ximgproc::SuperpixelSEEDS::*)()>("get_number_of_superpixels", &cv::ximgproc::SuperpixelSEEDS::getNumberOfSuperpixels).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(const cv::_InputArray &, int)>("iterate", &cv::ximgproc::SuperpixelSEEDS::iterate).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(const cv::_OutputArray &)>("get_labels", &cv::ximgproc::SuperpixelSEEDS::getLabels).
    define_method<void(cv::ximgproc::SuperpixelSEEDS::*)(const cv::_OutputArray &, bool)>("get_label_contour_mask", &cv::ximgproc::SuperpixelSEEDS::getLabelContourMask);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::SuperpixelSEEDS>(*)(int, int, int, int, int, int, int, bool)>("create_superpixel_seeds", &cv::ximgproc::createSuperpixelSEEDS);
}