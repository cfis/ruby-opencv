#include <opencv2/img_hash/color_moment_hash.hpp>
#include "color_moment_hash-rb.hpp"

using namespace Rice;

extern "C"
void Init_ColorMomentHash()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");
  
  Class rb_cCvImgHashColorMomentHash = define_class_under<cv::img_hash::ColorMomentHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "ColorMomentHash").
    define_singleton_function<cv::Ptr<cv::img_hash::ColorMomentHash>(*)()>("create", &cv::img_hash::ColorMomentHash::create).
    define_constructor(Constructor<cv::img_hash::ColorMomentHash>());
  
  rb_mCvImgHash.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("color_moment_hash", &cv::img_hash::colorMomentHash);
}