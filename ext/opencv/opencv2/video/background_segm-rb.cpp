#include <opencv2/video/background_segm.hpp>
#include "background_segm-rb.hpp"

using namespace Rice;

extern "C"
void Init_BackgroundSegm()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvBackgroundSubtractor = define_class_under<cv::BackgroundSubtractor, cv::Algorithm>(rb_mCv, "BackgroundSubtractor").
    define_method<void(cv::BackgroundSubtractor::*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("apply", &cv::BackgroundSubtractor::apply).
    define_method<void(cv::BackgroundSubtractor::*)(const cv::_OutputArray &) const>("get_background_image", &cv::BackgroundSubtractor::getBackgroundImage);
  
  Class rb_cCvBackgroundSubtractorMOG2 = define_class_under<cv::BackgroundSubtractorMOG2, cv::BackgroundSubtractor>(rb_mCv, "BackgroundSubtractorMOG2").
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_history", &cv::BackgroundSubtractorMOG2::getHistory).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_history", &cv::BackgroundSubtractorMOG2::setHistory).
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_n_mixtures", &cv::BackgroundSubtractorMOG2::getNMixtures).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_n_mixtures", &cv::BackgroundSubtractorMOG2::setNMixtures).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_background_ratio", &cv::BackgroundSubtractorMOG2::getBackgroundRatio).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_background_ratio", &cv::BackgroundSubtractorMOG2::setBackgroundRatio).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_threshold", &cv::BackgroundSubtractorMOG2::getVarThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_threshold", &cv::BackgroundSubtractorMOG2::setVarThreshold).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_threshold_gen", &cv::BackgroundSubtractorMOG2::getVarThresholdGen).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_threshold_gen", &cv::BackgroundSubtractorMOG2::setVarThresholdGen).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_init", &cv::BackgroundSubtractorMOG2::getVarInit).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_init", &cv::BackgroundSubtractorMOG2::setVarInit).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_min", &cv::BackgroundSubtractorMOG2::getVarMin).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_min", &cv::BackgroundSubtractorMOG2::setVarMin).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_var_max", &cv::BackgroundSubtractorMOG2::getVarMax).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_var_max", &cv::BackgroundSubtractorMOG2::setVarMax).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_complexity_reduction_threshold", &cv::BackgroundSubtractorMOG2::getComplexityReductionThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_complexity_reduction_threshold", &cv::BackgroundSubtractorMOG2::setComplexityReductionThreshold).
    define_method<bool(cv::BackgroundSubtractorMOG2::*)() const>("get_detect_shadows", &cv::BackgroundSubtractorMOG2::getDetectShadows).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(bool)>("set_detect_shadows", &cv::BackgroundSubtractorMOG2::setDetectShadows).
    define_method<int(cv::BackgroundSubtractorMOG2::*)() const>("get_shadow_value", &cv::BackgroundSubtractorMOG2::getShadowValue).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(int)>("set_shadow_value", &cv::BackgroundSubtractorMOG2::setShadowValue).
    define_method<double(cv::BackgroundSubtractorMOG2::*)() const>("get_shadow_threshold", &cv::BackgroundSubtractorMOG2::getShadowThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(double)>("set_shadow_threshold", &cv::BackgroundSubtractorMOG2::setShadowThreshold).
    define_method<void(cv::BackgroundSubtractorMOG2::*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("apply", &cv::BackgroundSubtractorMOG2::apply);
  
  rb_mCv.define_module_function<cv::Ptr<cv::BackgroundSubtractorMOG2>(*)(int, double, bool)>("create_background_subtractor_mog2", &cv::createBackgroundSubtractorMOG2);
  
  Class rb_cCvBackgroundSubtractorKNN = define_class_under<cv::BackgroundSubtractorKNN, cv::BackgroundSubtractor>(rb_mCv, "BackgroundSubtractorKNN").
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_history", &cv::BackgroundSubtractorKNN::getHistory).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_history", &cv::BackgroundSubtractorKNN::setHistory).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_n_samples", &cv::BackgroundSubtractorKNN::getNSamples).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_n_samples", &cv::BackgroundSubtractorKNN::setNSamples).
    define_method<double(cv::BackgroundSubtractorKNN::*)() const>("get_dist2_threshold", &cv::BackgroundSubtractorKNN::getDist2Threshold).
    define_method<void(cv::BackgroundSubtractorKNN::*)(double)>("set_dist2_threshold", &cv::BackgroundSubtractorKNN::setDist2Threshold).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("getk_nn_samples", &cv::BackgroundSubtractorKNN::getkNNSamples).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("setk_nn_samples", &cv::BackgroundSubtractorKNN::setkNNSamples).
    define_method<bool(cv::BackgroundSubtractorKNN::*)() const>("get_detect_shadows", &cv::BackgroundSubtractorKNN::getDetectShadows).
    define_method<void(cv::BackgroundSubtractorKNN::*)(bool)>("set_detect_shadows", &cv::BackgroundSubtractorKNN::setDetectShadows).
    define_method<int(cv::BackgroundSubtractorKNN::*)() const>("get_shadow_value", &cv::BackgroundSubtractorKNN::getShadowValue).
    define_method<void(cv::BackgroundSubtractorKNN::*)(int)>("set_shadow_value", &cv::BackgroundSubtractorKNN::setShadowValue).
    define_method<double(cv::BackgroundSubtractorKNN::*)() const>("get_shadow_threshold", &cv::BackgroundSubtractorKNN::getShadowThreshold).
    define_method<void(cv::BackgroundSubtractorKNN::*)(double)>("set_shadow_threshold", &cv::BackgroundSubtractorKNN::setShadowThreshold);
  
  rb_mCv.define_module_function<cv::Ptr<cv::BackgroundSubtractorKNN>(*)(int, double, bool)>("create_background_subtractor_knn", &cv::createBackgroundSubtractorKNN);
}