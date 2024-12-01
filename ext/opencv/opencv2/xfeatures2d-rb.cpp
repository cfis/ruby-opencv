#include <opencv2/xfeatures2d.hpp>
#include "xfeatures2d-rb.hpp"

using namespace Rice;

extern "C"
void Init_Xfeatures2d()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXfeatures2d = define_module_under(rb_mCv, "Xfeatures2d");
  
  Class rb_cCvXfeatures2dFREAK = define_class_under<cv::xfeatures2d::FREAK, cv::Feature2D>(rb_mCvXfeatures2d, "FREAK").
    define_singleton_attr("NB_SCALES", &FREAK::NB_SCALES).
    define_singleton_attr("NB_PAIRS", &FREAK::NB_PAIRS).
    define_singleton_attr("NB_ORIENPAIRS", &FREAK::NB_ORIENPAIRS).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::FREAK>(*)(bool, bool, float, int, const std::vector<int>&)>("create", &cv::xfeatures2d::FREAK::create).
    define_method<void(cv::xfeatures2d::FREAK::*)(bool)>("set_orientation_normalized", &cv::xfeatures2d::FREAK::setOrientationNormalized).
    define_method<bool(cv::xfeatures2d::FREAK::*)() const>("get_orientation_normalized", &cv::xfeatures2d::FREAK::getOrientationNormalized).
    define_method<void(cv::xfeatures2d::FREAK::*)(bool)>("set_scale_normalized", &cv::xfeatures2d::FREAK::setScaleNormalized).
    define_method<bool(cv::xfeatures2d::FREAK::*)() const>("get_scale_normalized", &cv::xfeatures2d::FREAK::getScaleNormalized).
    define_method<void(cv::xfeatures2d::FREAK::*)(double)>("set_pattern_scale", &cv::xfeatures2d::FREAK::setPatternScale).
    define_method<double(cv::xfeatures2d::FREAK::*)() const>("get_pattern_scale", &cv::xfeatures2d::FREAK::getPatternScale).
    define_method<void(cv::xfeatures2d::FREAK::*)(int)>("set_n_octaves", &cv::xfeatures2d::FREAK::setNOctaves).
    define_method<int(cv::xfeatures2d::FREAK::*)() const>("get_n_octaves", &cv::xfeatures2d::FREAK::getNOctaves).
    define_method<std::basic_string<char>(cv::xfeatures2d::FREAK::*)() const>("get_default_name", &cv::xfeatures2d::FREAK::getDefaultName);
  
  Class rb_cCvXfeatures2dStarDetector = define_class_under<cv::xfeatures2d::StarDetector, cv::Feature2D>(rb_mCvXfeatures2d, "StarDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::StarDetector>(*)(int, int, int, int, int)>("create", &cv::xfeatures2d::StarDetector::create).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_max_size", &cv::xfeatures2d::StarDetector::setMaxSize).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_max_size", &cv::xfeatures2d::StarDetector::getMaxSize).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_response_threshold", &cv::xfeatures2d::StarDetector::setResponseThreshold).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_response_threshold", &cv::xfeatures2d::StarDetector::getResponseThreshold).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_line_threshold_projected", &cv::xfeatures2d::StarDetector::setLineThresholdProjected).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_line_threshold_projected", &cv::xfeatures2d::StarDetector::getLineThresholdProjected).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_line_threshold_binarized", &cv::xfeatures2d::StarDetector::setLineThresholdBinarized).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_line_threshold_binarized", &cv::xfeatures2d::StarDetector::getLineThresholdBinarized).
    define_method<void(cv::xfeatures2d::StarDetector::*)(int)>("set_suppress_nonmax_size", &cv::xfeatures2d::StarDetector::setSuppressNonmaxSize).
    define_method<int(cv::xfeatures2d::StarDetector::*)() const>("get_suppress_nonmax_size", &cv::xfeatures2d::StarDetector::getSuppressNonmaxSize).
    define_method<std::basic_string<char>(cv::xfeatures2d::StarDetector::*)() const>("get_default_name", &cv::xfeatures2d::StarDetector::getDefaultName);
  
  Class rb_cCvXfeatures2dBriefDescriptorExtractor = define_class_under<cv::xfeatures2d::BriefDescriptorExtractor, cv::Feature2D>(rb_mCvXfeatures2d, "BriefDescriptorExtractor").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BriefDescriptorExtractor>(*)(int, bool)>("create", &cv::xfeatures2d::BriefDescriptorExtractor::create).
    define_method<void(cv::xfeatures2d::BriefDescriptorExtractor::*)(int)>("set_descriptor_size", &cv::xfeatures2d::BriefDescriptorExtractor::setDescriptorSize).
    define_method<int(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_descriptor_size", &cv::xfeatures2d::BriefDescriptorExtractor::getDescriptorSize).
    define_method<void(cv::xfeatures2d::BriefDescriptorExtractor::*)(bool)>("set_use_orientation", &cv::xfeatures2d::BriefDescriptorExtractor::setUseOrientation).
    define_method<bool(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_use_orientation", &cv::xfeatures2d::BriefDescriptorExtractor::getUseOrientation).
    define_method<std::basic_string<char>(cv::xfeatures2d::BriefDescriptorExtractor::*)() const>("get_default_name", &cv::xfeatures2d::BriefDescriptorExtractor::getDefaultName);
  
  Class rb_cCvXfeatures2dLUCID = define_class_under<cv::xfeatures2d::LUCID, cv::Feature2D>(rb_mCvXfeatures2d, "LUCID").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::LUCID>(*)(const int, const int)>("create", &cv::xfeatures2d::LUCID::create).
    define_method<void(cv::xfeatures2d::LUCID::*)(int)>("set_lucid_kernel", &cv::xfeatures2d::LUCID::setLucidKernel).
    define_method<int(cv::xfeatures2d::LUCID::*)() const>("get_lucid_kernel", &cv::xfeatures2d::LUCID::getLucidKernel).
    define_method<void(cv::xfeatures2d::LUCID::*)(int)>("set_blur_kernel", &cv::xfeatures2d::LUCID::setBlurKernel).
    define_method<int(cv::xfeatures2d::LUCID::*)() const>("get_blur_kernel", &cv::xfeatures2d::LUCID::getBlurKernel).
    define_method<std::basic_string<char>(cv::xfeatures2d::LUCID::*)() const>("get_default_name", &cv::xfeatures2d::LUCID::getDefaultName);
  
  Class rb_cCvXfeatures2dLATCH = define_class_under<cv::xfeatures2d::LATCH, cv::Feature2D>(rb_mCvXfeatures2d, "LATCH").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::LATCH>(*)(int, bool, int, double)>("create", &cv::xfeatures2d::LATCH::create).
    define_method<void(cv::xfeatures2d::LATCH::*)(int)>("set_bytes", &cv::xfeatures2d::LATCH::setBytes).
    define_method<int(cv::xfeatures2d::LATCH::*)() const>("get_bytes", &cv::xfeatures2d::LATCH::getBytes).
    define_method<void(cv::xfeatures2d::LATCH::*)(bool)>("set_rotation_invariance", &cv::xfeatures2d::LATCH::setRotationInvariance).
    define_method<bool(cv::xfeatures2d::LATCH::*)() const>("get_rotation_invariance", &cv::xfeatures2d::LATCH::getRotationInvariance).
    define_method<void(cv::xfeatures2d::LATCH::*)(int)>("set_half_ss_dsize", &cv::xfeatures2d::LATCH::setHalfSSDsize).
    define_method<int(cv::xfeatures2d::LATCH::*)() const>("get_half_ss_dsize", &cv::xfeatures2d::LATCH::getHalfSSDsize).
    define_method<void(cv::xfeatures2d::LATCH::*)(double)>("set_sigma", &cv::xfeatures2d::LATCH::setSigma).
    define_method<double(cv::xfeatures2d::LATCH::*)() const>("get_sigma", &cv::xfeatures2d::LATCH::getSigma).
    define_method<std::basic_string<char>(cv::xfeatures2d::LATCH::*)() const>("get_default_name", &cv::xfeatures2d::LATCH::getDefaultName);
  
  Class rb_cCvXfeatures2dBEBLID = define_class_under<cv::xfeatures2d::BEBLID, cv::Feature2D>(rb_mCvXfeatures2d, "BEBLID").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BEBLID>(*)(float, int)>("create", &cv::xfeatures2d::BEBLID::create).
    define_method<void(cv::xfeatures2d::BEBLID::*)(float)>("set_scale_factor", &cv::xfeatures2d::BEBLID::setScaleFactor).
    define_method<float(cv::xfeatures2d::BEBLID::*)() const>("get_scale_factor", &cv::xfeatures2d::BEBLID::getScaleFactor).
    define_method<std::basic_string<char>(cv::xfeatures2d::BEBLID::*)() const>("get_default_name", &cv::xfeatures2d::BEBLID::getDefaultName);
  
  Enum<cv::xfeatures2d::BEBLID::BeblidSize> rb_cCvXfeatures2dBEBLIDBeblidSize = define_enum<cv::xfeatures2d::BEBLID::BeblidSize>("BeblidSize", rb_cCvXfeatures2dBEBLID).
    define_value("SIZE_512_BITS", cv::xfeatures2d::BEBLID::BeblidSize::SIZE_512_BITS).
    define_value("SIZE_256_BITS", cv::xfeatures2d::BEBLID::BeblidSize::SIZE_256_BITS);
  
  Class rb_cCvXfeatures2dTEBLID = define_class_under<cv::xfeatures2d::TEBLID, cv::Feature2D>(rb_mCvXfeatures2d, "TEBLID").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::TEBLID>(*)(float, int)>("create", &cv::xfeatures2d::TEBLID::create).
    define_method<std::basic_string<char>(cv::xfeatures2d::TEBLID::*)() const>("get_default_name", &cv::xfeatures2d::TEBLID::getDefaultName);
  
  Enum<cv::xfeatures2d::TEBLID::TeblidSize> rb_cCvXfeatures2dTEBLIDTeblidSize = define_enum<cv::xfeatures2d::TEBLID::TeblidSize>("TeblidSize", rb_cCvXfeatures2dTEBLID).
    define_value("SIZE_256_BITS", cv::xfeatures2d::TEBLID::TeblidSize::SIZE_256_BITS).
    define_value("SIZE_512_BITS", cv::xfeatures2d::TEBLID::TeblidSize::SIZE_512_BITS);
  
  Class rb_cCvXfeatures2dDAISY = define_class_under<cv::xfeatures2d::DAISY, cv::Feature2D>(rb_mCvXfeatures2d, "DAISY").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::DAISY>(*)(float, int, int, int, cv::xfeatures2d::DAISY::NormalizationType, const cv::_InputArray &, bool, bool)>("create", &cv::xfeatures2d::DAISY::create).
    define_method<void(cv::xfeatures2d::DAISY::*)(float)>("set_radius", &cv::xfeatures2d::DAISY::setRadius).
    define_method<float(cv::xfeatures2d::DAISY::*)() const>("get_radius", &cv::xfeatures2d::DAISY::getRadius).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_radius", &cv::xfeatures2d::DAISY::setQRadius).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_radius", &cv::xfeatures2d::DAISY::getQRadius).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_theta", &cv::xfeatures2d::DAISY::setQTheta).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_theta", &cv::xfeatures2d::DAISY::getQTheta).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_q_hist", &cv::xfeatures2d::DAISY::setQHist).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_q_hist", &cv::xfeatures2d::DAISY::getQHist).
    define_method<void(cv::xfeatures2d::DAISY::*)(int)>("set_norm", &cv::xfeatures2d::DAISY::setNorm).
    define_method<int(cv::xfeatures2d::DAISY::*)() const>("get_norm", &cv::xfeatures2d::DAISY::getNorm).
    define_method<void(cv::xfeatures2d::DAISY::*)(const cv::_InputArray &)>("set_h", &cv::xfeatures2d::DAISY::setH).
    define_method<cv::Mat(cv::xfeatures2d::DAISY::*)() const>("get_h", &cv::xfeatures2d::DAISY::getH).
    define_method<void(cv::xfeatures2d::DAISY::*)(bool)>("set_interpolation", &cv::xfeatures2d::DAISY::setInterpolation).
    define_method<bool(cv::xfeatures2d::DAISY::*)() const>("get_interpolation", &cv::xfeatures2d::DAISY::getInterpolation).
    define_method<void(cv::xfeatures2d::DAISY::*)(bool)>("set_use_orientation", &cv::xfeatures2d::DAISY::setUseOrientation).
    define_method<bool(cv::xfeatures2d::DAISY::*)() const>("get_use_orientation", &cv::xfeatures2d::DAISY::getUseOrientation).
    define_method<std::basic_string<char>(cv::xfeatures2d::DAISY::*)() const>("get_default_name", &cv::xfeatures2d::DAISY::getDefaultName).
    define_method<void(cv::xfeatures2d::DAISY::*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, const cv::_OutputArray &)>("compute", &cv::xfeatures2d::DAISY::compute).
    define_method<void(cv::xfeatures2d::DAISY::*)(const cv::_InputArray &, std::vector<std::vector<cv::KeyPoint>>&, const cv::_OutputArray &)>("compute", &cv::xfeatures2d::DAISY::compute).
    define_method<void(cv::xfeatures2d::DAISY::*)(const cv::_InputArray &, cv::Rect_<int>, const cv::_OutputArray &)>("compute", &cv::xfeatures2d::DAISY::compute).
    define_method<void(cv::xfeatures2d::DAISY::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::xfeatures2d::DAISY::compute).
    define_method<void(cv::xfeatures2d::DAISY::*)(double, double, int, float*) const>("get_descriptor", &cv::xfeatures2d::DAISY::GetDescriptor).
    define_method<bool(cv::xfeatures2d::DAISY::*)(double, double, int, float*, double*) const>("get_descriptor", &cv::xfeatures2d::DAISY::GetDescriptor).
    define_method<void(cv::xfeatures2d::DAISY::*)(double, double, int, float*) const>("get_unnormalized_descriptor", &cv::xfeatures2d::DAISY::GetUnnormalizedDescriptor).
    define_method<bool(cv::xfeatures2d::DAISY::*)(double, double, int, float*, double*) const>("get_unnormalized_descriptor", &cv::xfeatures2d::DAISY::GetUnnormalizedDescriptor);
  
  Enum<cv::xfeatures2d::DAISY::NormalizationType> rb_cCvXfeatures2dDAISYNormalizationType = define_enum<cv::xfeatures2d::DAISY::NormalizationType>("NormalizationType", rb_cCvXfeatures2dDAISY).
    define_value("NRM_NONE", cv::xfeatures2d::DAISY::NormalizationType::NRM_NONE).
    define_value("NRM_PARTIAL", cv::xfeatures2d::DAISY::NormalizationType::NRM_PARTIAL).
    define_value("NRM_FULL", cv::xfeatures2d::DAISY::NormalizationType::NRM_FULL).
    define_value("NRM_SIFT", cv::xfeatures2d::DAISY::NormalizationType::NRM_SIFT);
  
  Class rb_cCvXfeatures2dMSDDetector = define_class_under<cv::xfeatures2d::MSDDetector, cv::Feature2D>(rb_mCvXfeatures2d, "MSDDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::MSDDetector>(*)(int, int, int, int, float, int, float, int, bool)>("create", &cv::xfeatures2d::MSDDetector::create).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_patch_radius", &cv::xfeatures2d::MSDDetector::setPatchRadius).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_patch_radius", &cv::xfeatures2d::MSDDetector::getPatchRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_search_area_radius", &cv::xfeatures2d::MSDDetector::setSearchAreaRadius).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_search_area_radius", &cv::xfeatures2d::MSDDetector::getSearchAreaRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_nms_radius", &cv::xfeatures2d::MSDDetector::setNmsRadius).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_nms_radius", &cv::xfeatures2d::MSDDetector::getNmsRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_nms_scale_radius", &cv::xfeatures2d::MSDDetector::setNmsScaleRadius).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_nms_scale_radius", &cv::xfeatures2d::MSDDetector::getNmsScaleRadius).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(float)>("set_th_saliency", &cv::xfeatures2d::MSDDetector::setThSaliency).
    define_method<float(cv::xfeatures2d::MSDDetector::*)() const>("get_th_saliency", &cv::xfeatures2d::MSDDetector::getThSaliency).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_knn", &cv::xfeatures2d::MSDDetector::setKNN).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_knn", &cv::xfeatures2d::MSDDetector::getKNN).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(float)>("set_scale_factor", &cv::xfeatures2d::MSDDetector::setScaleFactor).
    define_method<float(cv::xfeatures2d::MSDDetector::*)() const>("get_scale_factor", &cv::xfeatures2d::MSDDetector::getScaleFactor).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(int)>("set_n_scales", &cv::xfeatures2d::MSDDetector::setNScales).
    define_method<int(cv::xfeatures2d::MSDDetector::*)() const>("get_n_scales", &cv::xfeatures2d::MSDDetector::getNScales).
    define_method<void(cv::xfeatures2d::MSDDetector::*)(bool)>("set_compute_orientation", &cv::xfeatures2d::MSDDetector::setComputeOrientation).
    define_method<bool(cv::xfeatures2d::MSDDetector::*)() const>("get_compute_orientation", &cv::xfeatures2d::MSDDetector::getComputeOrientation).
    define_method<std::basic_string<char>(cv::xfeatures2d::MSDDetector::*)() const>("get_default_name", &cv::xfeatures2d::MSDDetector::getDefaultName);
  
  Class rb_cCvXfeatures2dVGG = define_class_under<cv::xfeatures2d::VGG, cv::Feature2D>(rb_mCvXfeatures2d, "VGG").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::VGG>(*)(int, float, bool, bool, float, bool)>("create", &cv::xfeatures2d::VGG::create).
    define_method<std::basic_string<char>(cv::xfeatures2d::VGG::*)() const>("get_default_name", &cv::xfeatures2d::VGG::getDefaultName).
    define_method<void(cv::xfeatures2d::VGG::*)(const float)>("set_sigma", &cv::xfeatures2d::VGG::setSigma).
    define_method<float(cv::xfeatures2d::VGG::*)() const>("get_sigma", &cv::xfeatures2d::VGG::getSigma).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_normalize_image", &cv::xfeatures2d::VGG::setUseNormalizeImage).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_normalize_image", &cv::xfeatures2d::VGG::getUseNormalizeImage).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_scale_orientation", &cv::xfeatures2d::VGG::setUseScaleOrientation).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_scale_orientation", &cv::xfeatures2d::VGG::getUseScaleOrientation).
    define_method<void(cv::xfeatures2d::VGG::*)(const float)>("set_scale_factor", &cv::xfeatures2d::VGG::setScaleFactor).
    define_method<float(cv::xfeatures2d::VGG::*)() const>("get_scale_factor", &cv::xfeatures2d::VGG::getScaleFactor).
    define_method<void(cv::xfeatures2d::VGG::*)(const bool)>("set_use_normalize_descriptor", &cv::xfeatures2d::VGG::setUseNormalizeDescriptor).
    define_method<bool(cv::xfeatures2d::VGG::*)() const>("get_use_normalize_descriptor", &cv::xfeatures2d::VGG::getUseNormalizeDescriptor);
  
  
  Class rb_cCvXfeatures2dBoostDesc = define_class_under<cv::xfeatures2d::BoostDesc, cv::Feature2D>(rb_mCvXfeatures2d, "BoostDesc").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::BoostDesc>(*)(int, bool, float)>("create", &cv::xfeatures2d::BoostDesc::create).
    define_method<std::basic_string<char>(cv::xfeatures2d::BoostDesc::*)() const>("get_default_name", &cv::xfeatures2d::BoostDesc::getDefaultName).
    define_method<void(cv::xfeatures2d::BoostDesc::*)(const bool)>("set_use_scale_orientation", &cv::xfeatures2d::BoostDesc::setUseScaleOrientation).
    define_method<bool(cv::xfeatures2d::BoostDesc::*)() const>("get_use_scale_orientation", &cv::xfeatures2d::BoostDesc::getUseScaleOrientation).
    define_method<void(cv::xfeatures2d::BoostDesc::*)(const float)>("set_scale_factor", &cv::xfeatures2d::BoostDesc::setScaleFactor).
    define_method<float(cv::xfeatures2d::BoostDesc::*)() const>("get_scale_factor", &cv::xfeatures2d::BoostDesc::getScaleFactor);
  
  
  Class rb_cCvXfeatures2dPCTSignatures = define_class_under<cv::xfeatures2d::PCTSignatures, cv::Algorithm>(rb_mCvXfeatures2d, "PCTSignatures").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const int, const int, const int)>("create", &cv::xfeatures2d::PCTSignatures::create).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const std::vector<cv::Point_<float>>&, const int)>("create", &cv::xfeatures2d::PCTSignatures::create).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignatures>(*)(const std::vector<cv::Point_<float>>&, const std::vector<int>&)>("create", &cv::xfeatures2d::PCTSignatures::create).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("compute_signature", &cv::xfeatures2d::PCTSignatures::computeSignature).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&) const>("compute_signatures", &cv::xfeatures2d::PCTSignatures::computeSignatures).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, float, int)>("draw_signature", &cv::xfeatures2d::PCTSignatures::drawSignature).
    define_singleton_function<void(*)(std::vector<cv::Point_<float>>&, const int, int)>("generate_init_points", &cv::xfeatures2d::PCTSignatures::generateInitPoints).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_sample_count", &cv::xfeatures2d::PCTSignatures::getSampleCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_grayscale_bits", &cv::xfeatures2d::PCTSignatures::getGrayscaleBits).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_grayscale_bits", &cv::xfeatures2d::PCTSignatures::setGrayscaleBits).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_window_radius", &cv::xfeatures2d::PCTSignatures::getWindowRadius).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_window_radius", &cv::xfeatures2d::PCTSignatures::setWindowRadius).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_x", &cv::xfeatures2d::PCTSignatures::getWeightX).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_x", &cv::xfeatures2d::PCTSignatures::setWeightX).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_y", &cv::xfeatures2d::PCTSignatures::getWeightY).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_y", &cv::xfeatures2d::PCTSignatures::setWeightY).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_l", &cv::xfeatures2d::PCTSignatures::getWeightL).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_l", &cv::xfeatures2d::PCTSignatures::setWeightL).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_a", &cv::xfeatures2d::PCTSignatures::getWeightA).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_a", &cv::xfeatures2d::PCTSignatures::setWeightA).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_b", &cv::xfeatures2d::PCTSignatures::getWeightB).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_b", &cv::xfeatures2d::PCTSignatures::setWeightB).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_contrast", &cv::xfeatures2d::PCTSignatures::getWeightContrast).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_contrast", &cv::xfeatures2d::PCTSignatures::setWeightContrast).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_weight_entropy", &cv::xfeatures2d::PCTSignatures::getWeightEntropy).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_weight_entropy", &cv::xfeatures2d::PCTSignatures::setWeightEntropy).
    define_method<std::vector<cv::Point_<float>>(cv::xfeatures2d::PCTSignatures::*)() const>("get_sampling_points", &cv::xfeatures2d::PCTSignatures::getSamplingPoints).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int, float)>("set_weight", &cv::xfeatures2d::PCTSignatures::setWeight).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<float>&)>("set_weights", &cv::xfeatures2d::PCTSignatures::setWeights).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int, float)>("set_translation", &cv::xfeatures2d::PCTSignatures::setTranslation).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(const std::vector<float>&)>("set_translations", &cv::xfeatures2d::PCTSignatures::setTranslations).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(std::vector<cv::Point_<float>>)>("set_sampling_points", &cv::xfeatures2d::PCTSignatures::setSamplingPoints).
    define_method<std::vector<int>(cv::xfeatures2d::PCTSignatures::*)() const>("get_init_seed_indexes", &cv::xfeatures2d::PCTSignatures::getInitSeedIndexes).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(std::vector<int>)>("set_init_seed_indexes", &cv::xfeatures2d::PCTSignatures::setInitSeedIndexes).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_init_seed_count", &cv::xfeatures2d::PCTSignatures::getInitSeedCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_iteration_count", &cv::xfeatures2d::PCTSignatures::getIterationCount).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_iteration_count", &cv::xfeatures2d::PCTSignatures::setIterationCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_max_clusters_count", &cv::xfeatures2d::PCTSignatures::getMaxClustersCount).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_max_clusters_count", &cv::xfeatures2d::PCTSignatures::setMaxClustersCount).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_cluster_min_size", &cv::xfeatures2d::PCTSignatures::getClusterMinSize).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_cluster_min_size", &cv::xfeatures2d::PCTSignatures::setClusterMinSize).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_joining_distance", &cv::xfeatures2d::PCTSignatures::getJoiningDistance).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_joining_distance", &cv::xfeatures2d::PCTSignatures::setJoiningDistance).
    define_method<float(cv::xfeatures2d::PCTSignatures::*)() const>("get_drop_threshold", &cv::xfeatures2d::PCTSignatures::getDropThreshold).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(float)>("set_drop_threshold", &cv::xfeatures2d::PCTSignatures::setDropThreshold).
    define_method<int(cv::xfeatures2d::PCTSignatures::*)() const>("get_distance_function", &cv::xfeatures2d::PCTSignatures::getDistanceFunction).
    define_method<void(cv::xfeatures2d::PCTSignatures::*)(int)>("set_distance_function", &cv::xfeatures2d::PCTSignatures::setDistanceFunction);
  
  Enum<cv::xfeatures2d::PCTSignatures::DistanceFunction> rb_cCvXfeatures2dPCTSignaturesDistanceFunction = define_enum<cv::xfeatures2d::PCTSignatures::DistanceFunction>("DistanceFunction", rb_cCvXfeatures2dPCTSignatures).
    define_value("L0_25", cv::xfeatures2d::PCTSignatures::DistanceFunction::L0_25).
    define_value("L0_5", cv::xfeatures2d::PCTSignatures::DistanceFunction::L0_5).
    define_value("L1", cv::xfeatures2d::PCTSignatures::DistanceFunction::L1).
    define_value("L2", cv::xfeatures2d::PCTSignatures::DistanceFunction::L2).
    define_value("L2SQUARED", cv::xfeatures2d::PCTSignatures::DistanceFunction::L2SQUARED).
    define_value("L5", cv::xfeatures2d::PCTSignatures::DistanceFunction::L5).
    define_value("L_INFINITY", cv::xfeatures2d::PCTSignatures::DistanceFunction::L_INFINITY);
  
  Enum<cv::xfeatures2d::PCTSignatures::PointDistribution> rb_cCvXfeatures2dPCTSignaturesPointDistribution = define_enum<cv::xfeatures2d::PCTSignatures::PointDistribution>("PointDistribution", rb_cCvXfeatures2dPCTSignatures).
    define_value("UNIFORM", cv::xfeatures2d::PCTSignatures::PointDistribution::UNIFORM).
    define_value("REGULAR", cv::xfeatures2d::PCTSignatures::PointDistribution::REGULAR).
    define_value("NORMAL", cv::xfeatures2d::PCTSignatures::PointDistribution::NORMAL);
  
  Enum<cv::xfeatures2d::PCTSignatures::SimilarityFunction> rb_cCvXfeatures2dPCTSignaturesSimilarityFunction = define_enum<cv::xfeatures2d::PCTSignatures::SimilarityFunction>("SimilarityFunction", rb_cCvXfeatures2dPCTSignatures).
    define_value("MINUS", cv::xfeatures2d::PCTSignatures::SimilarityFunction::MINUS).
    define_value("GAUSSIAN", cv::xfeatures2d::PCTSignatures::SimilarityFunction::GAUSSIAN).
    define_value("HEURISTIC", cv::xfeatures2d::PCTSignatures::SimilarityFunction::HEURISTIC);
  
  Class rb_cCvXfeatures2dPCTSignaturesSQFD = define_class_under<cv::xfeatures2d::PCTSignaturesSQFD, cv::Algorithm>(rb_mCvXfeatures2d, "PCTSignaturesSQFD").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::PCTSignaturesSQFD>(*)(const int, const int, const float)>("create", &cv::xfeatures2d::PCTSignaturesSQFD::create).
    define_method<float(cv::xfeatures2d::PCTSignaturesSQFD::*)(const cv::_InputArray &, const cv::_InputArray &) const>("compute_quadratic_form_distance", &cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistance).
    define_method<void(cv::xfeatures2d::PCTSignaturesSQFD::*)(const cv::Mat&, const std::vector<cv::Mat>&, std::vector<float>&) const>("compute_quadratic_form_distances", &cv::xfeatures2d::PCTSignaturesSQFD::computeQuadraticFormDistances);
  
  Class rb_cCvXfeatures2dEllipticKeyPoint = define_class_under<cv::xfeatures2d::Elliptic_KeyPoint, cv::KeyPoint>(rb_mCvXfeatures2d, "EllipticKeyPoint").
    define_attr("axes", &cv::xfeatures2d::Elliptic_KeyPoint::axes).
    define_attr("si", &cv::xfeatures2d::Elliptic_KeyPoint::si).
    define_attr("transf", &cv::xfeatures2d::Elliptic_KeyPoint::transf).
    define_constructor(Constructor<cv::xfeatures2d::Elliptic_KeyPoint>()).
    define_constructor(Constructor<cv::xfeatures2d::Elliptic_KeyPoint, cv::Point_<float>, float, cv::Size_<int>, float, float>());
  
  Class rb_cCvXfeatures2dHarrisLaplaceFeatureDetector = define_class_under<cv::xfeatures2d::HarrisLaplaceFeatureDetector, cv::Feature2D>(rb_mCvXfeatures2d, "HarrisLaplaceFeatureDetector").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::HarrisLaplaceFeatureDetector>(*)(int, float, float, int, int)>("create", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::create).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_num_octaves", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumOctaves).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_num_octaves", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumOctaves).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(float)>("set_corn_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setCornThresh).
    define_method<float(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_corn_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getCornThresh).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(float)>("set_dog_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setDOGThresh).
    define_method<float(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_dog_thresh", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDOGThresh).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_max_corners", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setMaxCorners).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_max_corners", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getMaxCorners).
    define_method<void(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)(int)>("set_num_layers", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::setNumLayers).
    define_method<int(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_num_layers", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getNumLayers).
    define_method<std::basic_string<char>(cv::xfeatures2d::HarrisLaplaceFeatureDetector::*)() const>("get_default_name", &cv::xfeatures2d::HarrisLaplaceFeatureDetector::getDefaultName);
  
  Class rb_cCvXfeatures2dAffineFeature2D = define_class_under<cv::xfeatures2d::AffineFeature2D, cv::Feature2D>(rb_mCvXfeatures2d, "AffineFeature2D").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::AffineFeature2D>(*)(cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>)>("create", &cv::xfeatures2d::AffineFeature2D::create).
    define_singleton_function<cv::Ptr<cv::xfeatures2d::AffineFeature2D>(*)(cv::Ptr<cv::Feature2D>)>("create", &cv::xfeatures2d::AffineFeature2D::create).
    define_method<void(cv::xfeatures2d::AffineFeature2D::*)(const cv::_InputArray &, std::vector<cv::xfeatures2d::Elliptic_KeyPoint>&, const cv::_InputArray &)>("detect", &cv::xfeatures2d::AffineFeature2D::detect).
    define_method<void(cv::xfeatures2d::AffineFeature2D::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::xfeatures2d::Elliptic_KeyPoint>&, const cv::_OutputArray &, bool)>("detect_and_compute", &cv::xfeatures2d::AffineFeature2D::detectAndCompute);
  
  Class rb_cCvXfeatures2dTBMR = define_class_under<cv::xfeatures2d::TBMR, cv::xfeatures2d::AffineFeature2D>(rb_mCvXfeatures2d, "TBMR").
    define_singleton_function<cv::Ptr<cv::xfeatures2d::TBMR>(*)(int, float, float, int)>("create", &cv::xfeatures2d::TBMR::create).
    define_method<void(cv::xfeatures2d::TBMR::*)(int)>("set_min_area", &cv::xfeatures2d::TBMR::setMinArea).
    define_method<int(cv::xfeatures2d::TBMR::*)() const>("get_min_area", &cv::xfeatures2d::TBMR::getMinArea).
    define_method<void(cv::xfeatures2d::TBMR::*)(float)>("set_max_area_relative", &cv::xfeatures2d::TBMR::setMaxAreaRelative).
    define_method<float(cv::xfeatures2d::TBMR::*)() const>("get_max_area_relative", &cv::xfeatures2d::TBMR::getMaxAreaRelative).
    define_method<void(cv::xfeatures2d::TBMR::*)(float)>("set_scale_factor", &cv::xfeatures2d::TBMR::setScaleFactor).
    define_method<float(cv::xfeatures2d::TBMR::*)() const>("get_scale_factor", &cv::xfeatures2d::TBMR::getScaleFactor).
    define_method<void(cv::xfeatures2d::TBMR::*)(int)>("set_n_scales", &cv::xfeatures2d::TBMR::setNScales).
    define_method<int(cv::xfeatures2d::TBMR::*)() const>("get_n_scales", &cv::xfeatures2d::TBMR::getNScales);
  
  rb_mCvXfeatures2d.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, int, bool, cv::FastFeatureDetector::DetectorType)>("fast_for_point_set", &cv::xfeatures2d::FASTForPointSet);
  
  rb_mCvXfeatures2d.define_module_function<void(*)(const cv::Size_<int>&, const cv::Size_<int>&, const std::vector<cv::KeyPoint>&, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, std::vector<cv::DMatch>&, const bool, const bool, const double)>("match_gms", &cv::xfeatures2d::matchGMS);
  
  rb_mCvXfeatures2d.define_module_function<void(*)(const std::vector<cv::KeyPoint>&, const std::vector<cv::KeyPoint>&, const std::vector<int>&, const std::vector<int>&, std::vector<cv::DMatch>&)>("match_logos", &cv::xfeatures2d::matchLOGOS);
}