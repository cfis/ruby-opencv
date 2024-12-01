#include <opencv2/img_hash/radial_variance_hash.hpp>
#include "radial_variance_hash-rb.hpp"

using namespace Rice;

extern "C"
void Init_RadialVarianceHash()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");
  
  Class rb_cCvImgHashRadialVarianceHash = define_class_under<cv::img_hash::RadialVarianceHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "RadialVarianceHash").
    define_singleton_function<cv::Ptr<cv::img_hash::RadialVarianceHash>(*)(double, int)>("create", &cv::img_hash::RadialVarianceHash::create).
    define_method<int(cv::img_hash::RadialVarianceHash::*)() const>("get_num_of_angle_line", &cv::img_hash::RadialVarianceHash::getNumOfAngleLine).
    define_method<double(cv::img_hash::RadialVarianceHash::*)() const>("get_sigma", &cv::img_hash::RadialVarianceHash::getSigma).
    define_method<void(cv::img_hash::RadialVarianceHash::*)(int)>("set_num_of_angle_line", &cv::img_hash::RadialVarianceHash::setNumOfAngleLine).
    define_method<void(cv::img_hash::RadialVarianceHash::*)(double)>("set_sigma", &cv::img_hash::RadialVarianceHash::setSigma).
    define_method<std::vector<double>(cv::img_hash::RadialVarianceHash::*)()>("get_features", &cv::img_hash::RadialVarianceHash::getFeatures).
    define_method<cv::Mat(cv::img_hash::RadialVarianceHash::*)()>("get_hash", &cv::img_hash::RadialVarianceHash::getHash).
    define_method<cv::Mat(cv::img_hash::RadialVarianceHash::*)(const cv::Mat&)>("get_pix_per_line", &cv::img_hash::RadialVarianceHash::getPixPerLine).
    define_method<cv::Mat(cv::img_hash::RadialVarianceHash::*)()>("get_projection", &cv::img_hash::RadialVarianceHash::getProjection).
    define_constructor(Constructor<cv::img_hash::RadialVarianceHash>());
  
  rb_mCvImgHash.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, int)>("radial_variance_hash", &cv::img_hash::radialVarianceHash);
}