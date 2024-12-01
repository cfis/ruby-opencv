#include <opencv2/img_hash/img_hash_base.hpp>
#include "img_hash_base-rb.hpp"

using namespace Rice;

extern "C"
void Init_ImgHashBase()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvImgHash = define_module_under(rb_mCv, "ImgHash");
  
  Class rb_cCvImgHashImgHashBase = define_class_under<cv::img_hash::ImgHashBase, cv::Algorithm>(rb_mCvImgHash, "ImgHashBase").
    define_method<void(cv::img_hash::ImgHashBase::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::img_hash::ImgHashBase::compute).
    define_method<double(cv::img_hash::ImgHashBase::*)(const cv::_InputArray &, const cv::_InputArray &) const>("compare", &cv::img_hash::ImgHashBase::compare).
    define_constructor(Constructor<cv::img_hash::ImgHashBase>());
}