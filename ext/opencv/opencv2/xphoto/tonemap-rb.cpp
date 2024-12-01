#include <opencv2/xphoto/tonemap.hpp>
#include "tonemap-rb.hpp"

using namespace Rice;

extern "C"
void Init_Tonemap()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");
  
  Class rb_cCvXphotoTonemapDurand = define_class_under<cv::xphoto::TonemapDurand, cv::Tonemap>(rb_mCvXphoto, "TonemapDurand").
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_saturation", &cv::xphoto::TonemapDurand::getSaturation).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_saturation", &cv::xphoto::TonemapDurand::setSaturation).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_contrast", &cv::xphoto::TonemapDurand::getContrast).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_contrast", &cv::xphoto::TonemapDurand::setContrast).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_sigma_space", &cv::xphoto::TonemapDurand::getSigmaSpace).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_sigma_space", &cv::xphoto::TonemapDurand::setSigmaSpace).
    define_method<float(cv::xphoto::TonemapDurand::*)() const>("get_sigma_color", &cv::xphoto::TonemapDurand::getSigmaColor).
    define_method<void(cv::xphoto::TonemapDurand::*)(float)>("set_sigma_color", &cv::xphoto::TonemapDurand::setSigmaColor);
  
  rb_mCvXphoto.define_module_function<cv::Ptr<cv::xphoto::TonemapDurand>(*)(float, float, float, float, float)>("create_tonemap_durand", &cv::xphoto::createTonemapDurand);
}