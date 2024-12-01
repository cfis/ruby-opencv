#include <opencv2/bgsegm.hpp>
#include "bgsegm-rb.hpp"

using namespace Rice;

extern "C"
void Init_Bgsegm()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBgsegm = define_module_under(rb_mCv, "Bgsegm");
  
  Class rb_cCvBgsegmBackgroundSubtractorMOG = define_class_under<cv::bgsegm::BackgroundSubtractorMOG, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorMOG").
    define_method<int(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_history", &cv::bgsegm::BackgroundSubtractorMOG::getHistory).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(int)>("set_history", &cv::bgsegm::BackgroundSubtractorMOG::setHistory).
    define_method<int(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_n_mixtures", &cv::bgsegm::BackgroundSubtractorMOG::getNMixtures).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(int)>("set_n_mixtures", &cv::bgsegm::BackgroundSubtractorMOG::setNMixtures).
    define_method<double(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_background_ratio", &cv::bgsegm::BackgroundSubtractorMOG::getBackgroundRatio).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(double)>("set_background_ratio", &cv::bgsegm::BackgroundSubtractorMOG::setBackgroundRatio).
    define_method<double(cv::bgsegm::BackgroundSubtractorMOG::*)() const>("get_noise_sigma", &cv::bgsegm::BackgroundSubtractorMOG::getNoiseSigma).
    define_method<void(cv::bgsegm::BackgroundSubtractorMOG::*)(double)>("set_noise_sigma", &cv::bgsegm::BackgroundSubtractorMOG::setNoiseSigma);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorMOG>(*)(int, int, double, double)>("create_background_subtractor_mog", &cv::bgsegm::createBackgroundSubtractorMOG);
  
  Class rb_cCvBgsegmBackgroundSubtractorGMG = define_class_under<cv::bgsegm::BackgroundSubtractorGMG, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorGMG").
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_max_features", &cv::bgsegm::BackgroundSubtractorGMG::getMaxFeatures).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_max_features", &cv::bgsegm::BackgroundSubtractorGMG::setMaxFeatures).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_default_learning_rate", &cv::bgsegm::BackgroundSubtractorGMG::getDefaultLearningRate).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_default_learning_rate", &cv::bgsegm::BackgroundSubtractorGMG::setDefaultLearningRate).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_num_frames", &cv::bgsegm::BackgroundSubtractorGMG::getNumFrames).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_num_frames", &cv::bgsegm::BackgroundSubtractorGMG::setNumFrames).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_quantization_levels", &cv::bgsegm::BackgroundSubtractorGMG::getQuantizationLevels).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_quantization_levels", &cv::bgsegm::BackgroundSubtractorGMG::setQuantizationLevels).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_background_prior", &cv::bgsegm::BackgroundSubtractorGMG::getBackgroundPrior).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_background_prior", &cv::bgsegm::BackgroundSubtractorGMG::setBackgroundPrior).
    define_method<int(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_smoothing_radius", &cv::bgsegm::BackgroundSubtractorGMG::getSmoothingRadius).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(int)>("set_smoothing_radius", &cv::bgsegm::BackgroundSubtractorGMG::setSmoothingRadius).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_decision_threshold", &cv::bgsegm::BackgroundSubtractorGMG::getDecisionThreshold).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_decision_threshold", &cv::bgsegm::BackgroundSubtractorGMG::setDecisionThreshold).
    define_method<bool(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_update_background_model", &cv::bgsegm::BackgroundSubtractorGMG::getUpdateBackgroundModel).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(bool)>("set_update_background_model", &cv::bgsegm::BackgroundSubtractorGMG::setUpdateBackgroundModel).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_min_val", &cv::bgsegm::BackgroundSubtractorGMG::getMinVal).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_min_val", &cv::bgsegm::BackgroundSubtractorGMG::setMinVal).
    define_method<double(cv::bgsegm::BackgroundSubtractorGMG::*)() const>("get_max_val", &cv::bgsegm::BackgroundSubtractorGMG::getMaxVal).
    define_method<void(cv::bgsegm::BackgroundSubtractorGMG::*)(double)>("set_max_val", &cv::bgsegm::BackgroundSubtractorGMG::setMaxVal);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorGMG>(*)(int, double)>("create_background_subtractor_gmg", &cv::bgsegm::createBackgroundSubtractorGMG);
  
  Class rb_cCvBgsegmBackgroundSubtractorCNT = define_class_under<cv::bgsegm::BackgroundSubtractorCNT, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorCNT").
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("apply", &cv::bgsegm::BackgroundSubtractorCNT::apply).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(const cv::_OutputArray &) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorCNT::getBackgroundImage).
    define_method<int(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_min_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::getMinPixelStability).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(int)>("set_min_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::setMinPixelStability).
    define_method<int(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_max_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::getMaxPixelStability).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(int)>("set_max_pixel_stability", &cv::bgsegm::BackgroundSubtractorCNT::setMaxPixelStability).
    define_method<bool(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_use_history", &cv::bgsegm::BackgroundSubtractorCNT::getUseHistory).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(bool)>("set_use_history", &cv::bgsegm::BackgroundSubtractorCNT::setUseHistory).
    define_method<bool(cv::bgsegm::BackgroundSubtractorCNT::*)() const>("get_is_parallel", &cv::bgsegm::BackgroundSubtractorCNT::getIsParallel).
    define_method<void(cv::bgsegm::BackgroundSubtractorCNT::*)(bool)>("set_is_parallel", &cv::bgsegm::BackgroundSubtractorCNT::setIsParallel);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorCNT>(*)(int, bool, int, bool)>("create_background_subtractor_cnt", &cv::bgsegm::createBackgroundSubtractorCNT);
  
  Enum<cv::bgsegm::LSBPCameraMotionCompensation> rb_cCvBgsegmLSBPCameraMotionCompensation = define_enum<cv::bgsegm::LSBPCameraMotionCompensation>("LSBPCameraMotionCompensation", rb_mCvBgsegm).
    define_value("LSBP_CAMERA_MOTION_COMPENSATION_NONE", cv::bgsegm::LSBPCameraMotionCompensation::LSBP_CAMERA_MOTION_COMPENSATION_NONE).
    define_value("LSBP_CAMERA_MOTION_COMPENSATION_LK", cv::bgsegm::LSBPCameraMotionCompensation::LSBP_CAMERA_MOTION_COMPENSATION_LK);
  
  Class rb_cCvBgsegmBackgroundSubtractorGSOC = define_class_under<cv::bgsegm::BackgroundSubtractorGSOC, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorGSOC").
    define_method<void(cv::bgsegm::BackgroundSubtractorGSOC::*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("apply", &cv::bgsegm::BackgroundSubtractorGSOC::apply).
    define_method<void(cv::bgsegm::BackgroundSubtractorGSOC::*)(const cv::_OutputArray &) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorGSOC::getBackgroundImage);
  
  Class rb_cCvBgsegmBackgroundSubtractorLSBP = define_class_under<cv::bgsegm::BackgroundSubtractorLSBP, cv::BackgroundSubtractor>(rb_mCvBgsegm, "BackgroundSubtractorLSBP").
    define_method<void(cv::bgsegm::BackgroundSubtractorLSBP::*)(const cv::_InputArray &, const cv::_OutputArray &, double)>("apply", &cv::bgsegm::BackgroundSubtractorLSBP::apply).
    define_method<void(cv::bgsegm::BackgroundSubtractorLSBP::*)(const cv::_OutputArray &) const>("get_background_image", &cv::bgsegm::BackgroundSubtractorLSBP::getBackgroundImage);
  
  Class rb_cCvBgsegmBackgroundSubtractorLSBPDesc = define_class_under<cv::bgsegm::BackgroundSubtractorLSBPDesc>(rb_mCvBgsegm, "BackgroundSubtractorLSBPDesc").
    define_singleton_function<void(*)(const cv::_OutputArray &, const cv::Mat&)>("calc_local_svd_values", &cv::bgsegm::BackgroundSubtractorLSBPDesc::calcLocalSVDValues).
    define_singleton_function<void(*)(const cv::_OutputArray &, const cv::Mat&, const cv::Point_<int>*)>("compute_from_local_svd_values", &cv::bgsegm::BackgroundSubtractorLSBPDesc::computeFromLocalSVDValues).
    define_singleton_function<void(*)(const cv::_OutputArray &, const cv::Mat&, const cv::Point_<int>*)>("compute", &cv::bgsegm::BackgroundSubtractorLSBPDesc::compute);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorGSOC>(*)(int, int, float, float, int, float, float, float, float, float, float)>("create_background_subtractor_gsoc", &cv::bgsegm::createBackgroundSubtractorGSOC);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::BackgroundSubtractorLSBP>(*)(int, int, int, float, float, float, float, float, float, float, float, int, int)>("create_background_subtractor_lsbp", &cv::bgsegm::createBackgroundSubtractorLSBP);
  
  Class rb_cCvBgsegmSyntheticSequenceGenerator = define_class_under<cv::bgsegm::SyntheticSequenceGenerator, cv::Algorithm>(rb_mCvBgsegm, "SyntheticSequenceGenerator").
    define_constructor(Constructor<cv::bgsegm::SyntheticSequenceGenerator, const cv::_InputArray &, const cv::_InputArray &, double, double, double, double>()).
    define_method<void(cv::bgsegm::SyntheticSequenceGenerator::*)(const cv::_OutputArray &, const cv::_OutputArray &)>("get_next_frame", &cv::bgsegm::SyntheticSequenceGenerator::getNextFrame);
  
  rb_mCvBgsegm.define_module_function<cv::Ptr<cv::bgsegm::SyntheticSequenceGenerator>(*)(const cv::_InputArray &, const cv::_InputArray &, double, double, double, double)>("create_synthetic_sequence_generator", &cv::bgsegm::createSyntheticSequenceGenerator);
}