#include <opencv2/img_hash/phash.hpp>
#include "phash-rb.hpp"

using namespace Rice;

extern "C"
void Init_Phash()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");
  
  Class rb_cCvImgHashPHash = define_class_under<cv::img_hash::PHash, cv::img_hash::ImgHashBase>(rb_mCvImgHash, "PHash").
    define_singleton_function<cv::Ptr<cv::img_hash::PHash>(*)()>("create", &cv::img_hash::PHash::create).
    define_constructor(Constructor<cv::img_hash::PHash>());
  
  rb_mCvImgHash.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("p_hash", &cv::img_hash::pHash);
}