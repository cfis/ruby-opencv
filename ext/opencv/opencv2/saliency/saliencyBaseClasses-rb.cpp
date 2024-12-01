#include <opencv2/saliency/saliencyBaseClasses.hpp>
#include "saliencyBaseClasses-rb.hpp"

using namespace Rice;

extern "C"
void Init_SaliencyBaseClasses()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvSaliency = define_module_under(rb_mCv, "Saliency");
  
  Class rb_cCvSaliencySaliency = define_class_under<cv::saliency::Saliency, cv::Algorithm>(rb_mCvSaliency, "Saliency").
    define_method<bool(cv::saliency::Saliency::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_saliency", &cv::saliency::Saliency::computeSaliency);
  
  Class rb_cCvSaliencyStaticSaliency = define_class_under<cv::saliency::StaticSaliency, cv::saliency::Saliency>(rb_mCvSaliency, "StaticSaliency").
    define_method<bool(cv::saliency::StaticSaliency::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_binary_map", &cv::saliency::StaticSaliency::computeBinaryMap);
  
  Class rb_cCvSaliencyMotionSaliency = define_class_under<cv::saliency::MotionSaliency, cv::saliency::Saliency>(rb_mCvSaliency, "MotionSaliency");
  
  
  Class rb_cCvSaliencyObjectness = define_class_under<cv::saliency::Objectness, cv::saliency::Saliency>(rb_mCvSaliency, "Objectness");
}