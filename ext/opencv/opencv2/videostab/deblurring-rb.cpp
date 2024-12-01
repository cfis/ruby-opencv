#include <opencv2/videostab/deblurring.hpp>
#include "deblurring-rb.hpp"

using namespace Rice;

extern "C"
void Init_Deblurring()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  rb_mCvVideostab.define_module_function<float(*)(const cv::Mat&)>("calc_blurriness", &cv::videostab::calcBlurriness);
  
  Class rb_cCvVideostabDeblurerBase = define_class_under<cv::videostab::DeblurerBase>(rb_mCvVideostab, "DeblurerBase").
    define_constructor(Constructor<cv::videostab::DeblurerBase>()).
    define_method<void(cv::videostab::DeblurerBase::*)(int)>("set_radius", &cv::videostab::DeblurerBase::setRadius).
    define_method<int(cv::videostab::DeblurerBase::*)() const>("radius", &cv::videostab::DeblurerBase::radius).
    define_method<void(cv::videostab::DeblurerBase::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::DeblurerBase::deblur).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::DeblurerBase::setFrames).
    define_method<const std::vector<cv::Mat>&(cv::videostab::DeblurerBase::*)() const>("frames", &cv::videostab::DeblurerBase::frames).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::DeblurerBase::setMotions).
    define_method<const std::vector<cv::Mat>&(cv::videostab::DeblurerBase::*)() const>("motions", &cv::videostab::DeblurerBase::motions).
    define_method<void(cv::videostab::DeblurerBase::*)(const std::vector<float>&)>("set_blurriness_rates", &cv::videostab::DeblurerBase::setBlurrinessRates).
    define_method<const std::vector<float>&(cv::videostab::DeblurerBase::*)() const>("blurriness_rates", &cv::videostab::DeblurerBase::blurrinessRates);
  
  Class rb_cCvVideostabNullDeblurer = define_class_under<cv::videostab::NullDeblurer, cv::videostab::DeblurerBase>(rb_mCvVideostab, "NullDeblurer").
    define_method<void(cv::videostab::NullDeblurer::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::NullDeblurer::deblur);
  
  Class rb_cCvVideostabWeightingDeblurer = define_class_under<cv::videostab::WeightingDeblurer, cv::videostab::DeblurerBase>(rb_mCvVideostab, "WeightingDeblurer").
    define_constructor(Constructor<cv::videostab::WeightingDeblurer>()).
    define_method<void(cv::videostab::WeightingDeblurer::*)(float)>("set_sensitivity", &cv::videostab::WeightingDeblurer::setSensitivity).
    define_method<float(cv::videostab::WeightingDeblurer::*)() const>("sensitivity", &cv::videostab::WeightingDeblurer::sensitivity).
    define_method<void(cv::videostab::WeightingDeblurer::*)(int, cv::Mat&, const cv::Range&)>("deblur", &cv::videostab::WeightingDeblurer::deblur);
}