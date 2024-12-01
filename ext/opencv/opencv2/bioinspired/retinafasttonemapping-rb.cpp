#include <opencv2/bioinspired/retinafasttonemapping.hpp>
#include "retinafasttonemapping-rb.hpp"

using namespace Rice;

extern "C"
void Init_Retinafasttonemapping()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");
  
  Class rb_cCvBioinspiredRetinaFastToneMapping = define_class_under<cv::bioinspired::RetinaFastToneMapping, cv::Algorithm>(rb_mCvBioinspired, "RetinaFastToneMapping").
    define_method<void(cv::bioinspired::RetinaFastToneMapping::*)(const cv::_InputArray &, const cv::_OutputArray &)>("apply_fast_tone_mapping", &cv::bioinspired::RetinaFastToneMapping::applyFastToneMapping).
    define_method<void(cv::bioinspired::RetinaFastToneMapping::*)(const float, const float, const float)>("setup", &cv::bioinspired::RetinaFastToneMapping::setup).
    define_singleton_function<cv::Ptr<cv::bioinspired::RetinaFastToneMapping>(*)(cv::Size_<int>)>("create", &cv::bioinspired::RetinaFastToneMapping::create);
}