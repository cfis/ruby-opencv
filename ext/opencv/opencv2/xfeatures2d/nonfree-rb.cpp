#include <opencv2/xfeatures2d/nonfree.hpp>
#include "nonfree-rb.hpp"

using namespace Rice;

extern "C"
void Init_Nonfree()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXfeatures2d = define_module_under(rb_mCv, "Xfeatures2d");
  
  Class rb_cCvXfeatures2dSURF = define_class_under<cv::xfeatures2d::SURF, cv::Feature2D>(rb_mCvXfeatures2d, "SURF").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::SURF>(*)(double, int, int, bool, bool)>("create", &cv::xfeatures2d::SURF::create).
    define_method<void(cv::xfeatures2d::SURF::*)(double)>("set_hessian_threshold", &cv::xfeatures2d::SURF::setHessianThreshold).
    define_method<double(cv::xfeatures2d::SURF::*)() const>("get_hessian_threshold", &cv::xfeatures2d::SURF::getHessianThreshold).
    define_method<void(cv::xfeatures2d::SURF::*)(int)>("set_n_octaves", &cv::xfeatures2d::SURF::setNOctaves).
    define_method<int(cv::xfeatures2d::SURF::*)() const>("get_n_octaves", &cv::xfeatures2d::SURF::getNOctaves).
    define_method<void(cv::xfeatures2d::SURF::*)(int)>("set_n_octave_layers", &cv::xfeatures2d::SURF::setNOctaveLayers).
    define_method<int(cv::xfeatures2d::SURF::*)() const>("get_n_octave_layers", &cv::xfeatures2d::SURF::getNOctaveLayers).
    define_method<void(cv::xfeatures2d::SURF::*)(bool)>("set_extended", &cv::xfeatures2d::SURF::setExtended).
    define_method<bool(cv::xfeatures2d::SURF::*)() const>("get_extended", &cv::xfeatures2d::SURF::getExtended).
    define_method<void(cv::xfeatures2d::SURF::*)(bool)>("set_upright", &cv::xfeatures2d::SURF::setUpright).
    define_method<bool(cv::xfeatures2d::SURF::*)() const>("get_upright", &cv::xfeatures2d::SURF::getUpright).
    define_method<std::basic_string<char>(cv::xfeatures2d::SURF::*)() const>("get_default_name", &cv::xfeatures2d::SURF::getDefaultName);
}