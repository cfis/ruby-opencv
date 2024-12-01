#include <opencv2/img_hash/marr_hildreth_hash.hpp>
#include "marr_hildreth_hash-rb.hpp"

using namespace Rice;

extern "C"
void Init_MarrHildrethHash()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");
  
  Class rb_cCvImgHashMarrHildrethHash = define_class_under<cv::img_hash::MarrHildrethHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "MarrHildrethHash").
    define_method<float(cv::img_hash::MarrHildrethHash::*)() const>("get_alpha", &cv::img_hash::MarrHildrethHash::getAlpha).
    define_method<float(cv::img_hash::MarrHildrethHash::*)() const>("get_scale", &cv::img_hash::MarrHildrethHash::getScale).
    define_method<void(cv::img_hash::MarrHildrethHash::*)(float, float)>("set_kernel_param", &cv::img_hash::MarrHildrethHash::setKernelParam).
    define_singleton_function<cv::Ptr<cv::img_hash::MarrHildrethHash>(*)(float, float)>("create", &cv::img_hash::MarrHildrethHash::create).
    define_constructor(Constructor<cv::img_hash::MarrHildrethHash>());
  
  rb_mCvImgHash.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float)>("marr_hildreth_hash", &cv::img_hash::marrHildrethHash);
}