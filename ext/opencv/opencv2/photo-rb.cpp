#include <opencv2/photo.hpp>
#include "photo-rb.hpp"

using namespace Rice;

extern "C"
void Init_Photo()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, int)>("inpaint", &cv::inpaint);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising", &cv::fastNlMeansDenoising);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, int, int)>("fast_nl_means_denoising_colored", &cv::fastNlMeansDenoisingColored);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, float, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, const std::vector<float>&, int, int, int)>("fast_nl_means_denoising_multi", &cv::fastNlMeansDenoisingMulti);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, float, float, int, int)>("fast_nl_means_denoising_colored_multi", &cv::fastNlMeansDenoisingColoredMulti);
  
  rb_mCv.define_module_function<void(*)(const std::vector<cv::Mat>&, cv::Mat&, double, int)>("denoise_tvl1", &cv::denoise_TVL1);
  
  Class rb_cCvTonemap = define_class_under<cv::Tonemap, cv::Algorithm>(rb_mCv, "Tonemap").
    define_method<void(cv::Tonemap::*)(const cv::_InputArray &, const cv::_OutputArray &)>("process", &cv::Tonemap::process).
    define_method<float(cv::Tonemap::*)() const>("get_gamma", &cv::Tonemap::getGamma).
    define_method<void(cv::Tonemap::*)(float)>("set_gamma", &cv::Tonemap::setGamma);
  
  rb_mCv.define_module_function<cv::Ptr<cv::Tonemap>(*)(float)>("create_tonemap", &cv::createTonemap);
  
  Class rb_cCvTonemapDrago = define_class_under<cv::TonemapDrago, cv::Tonemap>(rb_mCv, "TonemapDrago").
    define_method<float(cv::TonemapDrago::*)() const>("get_saturation", &cv::TonemapDrago::getSaturation).
    define_method<void(cv::TonemapDrago::*)(float)>("set_saturation", &cv::TonemapDrago::setSaturation).
    define_method<float(cv::TonemapDrago::*)() const>("get_bias", &cv::TonemapDrago::getBias).
    define_method<void(cv::TonemapDrago::*)(float)>("set_bias", &cv::TonemapDrago::setBias);
  
  rb_mCv.define_module_function<cv::Ptr<cv::TonemapDrago>(*)(float, float, float)>("create_tonemap_drago", &cv::createTonemapDrago);
  
  Class rb_cCvTonemapReinhard = define_class_under<cv::TonemapReinhard, cv::Tonemap>(rb_mCv, "TonemapReinhard").
    define_method<float(cv::TonemapReinhard::*)() const>("get_intensity", &cv::TonemapReinhard::getIntensity).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_intensity", &cv::TonemapReinhard::setIntensity).
    define_method<float(cv::TonemapReinhard::*)() const>("get_light_adaptation", &cv::TonemapReinhard::getLightAdaptation).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_light_adaptation", &cv::TonemapReinhard::setLightAdaptation).
    define_method<float(cv::TonemapReinhard::*)() const>("get_color_adaptation", &cv::TonemapReinhard::getColorAdaptation).
    define_method<void(cv::TonemapReinhard::*)(float)>("set_color_adaptation", &cv::TonemapReinhard::setColorAdaptation);
  
  rb_mCv.define_module_function<cv::Ptr<cv::TonemapReinhard>(*)(float, float, float, float)>("create_tonemap_reinhard", &cv::createTonemapReinhard);
  
  Class rb_cCvTonemapMantiuk = define_class_under<cv::TonemapMantiuk, cv::Tonemap>(rb_mCv, "TonemapMantiuk").
    define_method<float(cv::TonemapMantiuk::*)() const>("get_scale", &cv::TonemapMantiuk::getScale).
    define_method<void(cv::TonemapMantiuk::*)(float)>("set_scale", &cv::TonemapMantiuk::setScale).
    define_method<float(cv::TonemapMantiuk::*)() const>("get_saturation", &cv::TonemapMantiuk::getSaturation).
    define_method<void(cv::TonemapMantiuk::*)(float)>("set_saturation", &cv::TonemapMantiuk::setSaturation);
  
  rb_mCv.define_module_function<cv::Ptr<cv::TonemapMantiuk>(*)(float, float, float)>("create_tonemap_mantiuk", &cv::createTonemapMantiuk);
  
  Class rb_cCvAlignExposures = define_class_under<cv::AlignExposures, cv::Algorithm>(rb_mCv, "AlignExposures").
    define_method<void(cv::AlignExposures::*)(const cv::_InputArray &, std::vector<cv::Mat>&, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::AlignExposures::process);
  
  Class rb_cCvAlignMTB = define_class_under<cv::AlignMTB, cv::AlignExposures>(rb_mCv, "AlignMTB").
    define_method<void(cv::AlignMTB::*)(const cv::_InputArray &, std::vector<cv::Mat>&, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::AlignMTB::process).
    define_method<void(cv::AlignMTB::*)(const cv::_InputArray &, std::vector<cv::Mat>&)>("process", &cv::AlignMTB::process).
    define_method<cv::Point_<int>(cv::AlignMTB::*)(const cv::_InputArray &, const cv::_InputArray &)>("calculate_shift", &cv::AlignMTB::calculateShift).
    define_method<void(cv::AlignMTB::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::Point_<int>)>("shift_mat", &cv::AlignMTB::shiftMat).
    define_method<void(cv::AlignMTB::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("compute_bitmaps", &cv::AlignMTB::computeBitmaps).
    define_method<int(cv::AlignMTB::*)() const>("get_max_bits", &cv::AlignMTB::getMaxBits).
    define_method<void(cv::AlignMTB::*)(int)>("set_max_bits", &cv::AlignMTB::setMaxBits).
    define_method<int(cv::AlignMTB::*)() const>("get_exclude_range", &cv::AlignMTB::getExcludeRange).
    define_method<void(cv::AlignMTB::*)(int)>("set_exclude_range", &cv::AlignMTB::setExcludeRange).
    define_method<bool(cv::AlignMTB::*)() const>("get_cut", &cv::AlignMTB::getCut).
    define_method<void(cv::AlignMTB::*)(bool)>("set_cut", &cv::AlignMTB::setCut);
  
  rb_mCv.define_module_function<cv::Ptr<cv::AlignMTB>(*)(int, int, bool)>("create_align_mtb", &cv::createAlignMTB);
  
  Class rb_cCvCalibrateCRF = define_class_under<cv::CalibrateCRF, cv::Algorithm>(rb_mCv, "CalibrateCRF").
    define_method<void(cv::CalibrateCRF::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("process", &cv::CalibrateCRF::process);
  
  Class rb_cCvCalibrateDebevec = define_class_under<cv::CalibrateDebevec, cv::CalibrateCRF>(rb_mCv, "CalibrateDebevec").
    define_method<float(cv::CalibrateDebevec::*)() const>("get_lambda", &cv::CalibrateDebevec::getLambda).
    define_method<void(cv::CalibrateDebevec::*)(float)>("set_lambda", &cv::CalibrateDebevec::setLambda).
    define_method<int(cv::CalibrateDebevec::*)() const>("get_samples", &cv::CalibrateDebevec::getSamples).
    define_method<void(cv::CalibrateDebevec::*)(int)>("set_samples", &cv::CalibrateDebevec::setSamples).
    define_method<bool(cv::CalibrateDebevec::*)() const>("get_random", &cv::CalibrateDebevec::getRandom).
    define_method<void(cv::CalibrateDebevec::*)(bool)>("set_random", &cv::CalibrateDebevec::setRandom);
  
  rb_mCv.define_module_function<cv::Ptr<cv::CalibrateDebevec>(*)(int, float, bool)>("create_calibrate_debevec", &cv::createCalibrateDebevec);
  
  Class rb_cCvCalibrateRobertson = define_class_under<cv::CalibrateRobertson, cv::CalibrateCRF>(rb_mCv, "CalibrateRobertson").
    define_method<int(cv::CalibrateRobertson::*)() const>("get_max_iter", &cv::CalibrateRobertson::getMaxIter).
    define_method<void(cv::CalibrateRobertson::*)(int)>("set_max_iter", &cv::CalibrateRobertson::setMaxIter).
    define_method<float(cv::CalibrateRobertson::*)() const>("get_threshold", &cv::CalibrateRobertson::getThreshold).
    define_method<void(cv::CalibrateRobertson::*)(float)>("set_threshold", &cv::CalibrateRobertson::setThreshold).
    define_method<cv::Mat(cv::CalibrateRobertson::*)() const>("get_radiance", &cv::CalibrateRobertson::getRadiance);
  
  rb_mCv.define_module_function<cv::Ptr<cv::CalibrateRobertson>(*)(int, float)>("create_calibrate_robertson", &cv::createCalibrateRobertson);
  
  Class rb_cCvMergeExposures = define_class_under<cv::MergeExposures, cv::Algorithm>(rb_mCv, "MergeExposures").
    define_method<void(cv::MergeExposures::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::MergeExposures::process);
  
  Class rb_cCvMergeDebevec = define_class_under<cv::MergeDebevec, cv::MergeExposures>(rb_mCv, "MergeDebevec").
    define_method<void(cv::MergeDebevec::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::MergeDebevec::process).
    define_method<void(cv::MergeDebevec::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("process", &cv::MergeDebevec::process);
  
  rb_mCv.define_module_function<cv::Ptr<cv::MergeDebevec>(*)()>("create_merge_debevec", &cv::createMergeDebevec);
  
  Class rb_cCvMergeMertens = define_class_under<cv::MergeMertens, cv::MergeExposures>(rb_mCv, "MergeMertens").
    define_method<void(cv::MergeMertens::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::MergeMertens::process).
    define_method<void(cv::MergeMertens::*)(const cv::_InputArray &, const cv::_OutputArray &)>("process", &cv::MergeMertens::process).
    define_method<float(cv::MergeMertens::*)() const>("get_contrast_weight", &cv::MergeMertens::getContrastWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_contrast_weight", &cv::MergeMertens::setContrastWeight).
    define_method<float(cv::MergeMertens::*)() const>("get_saturation_weight", &cv::MergeMertens::getSaturationWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_saturation_weight", &cv::MergeMertens::setSaturationWeight).
    define_method<float(cv::MergeMertens::*)() const>("get_exposure_weight", &cv::MergeMertens::getExposureWeight).
    define_method<void(cv::MergeMertens::*)(float)>("set_exposure_weight", &cv::MergeMertens::setExposureWeight);
  
  rb_mCv.define_module_function<cv::Ptr<cv::MergeMertens>(*)(float, float, float)>("create_merge_mertens", &cv::createMergeMertens);
  
  Class rb_cCvMergeRobertson = define_class_under<cv::MergeRobertson, cv::MergeExposures>(rb_mCv, "MergeRobertson").
    define_method<void(cv::MergeRobertson::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("process", &cv::MergeRobertson::process).
    define_method<void(cv::MergeRobertson::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("process", &cv::MergeRobertson::process);
  
  rb_mCv.define_module_function<cv::Ptr<cv::MergeRobertson>(*)()>("create_merge_robertson", &cv::createMergeRobertson);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("decolor", &cv::decolor);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>, const cv::_OutputArray &, int)>("seamless_clone", &cv::seamlessClone);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, float, float, float)>("color_change", &cv::colorChange);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, float, float)>("illumination_change", &cv::illuminationChange);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, float, float, int)>("texture_flattening", &cv::textureFlattening);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, float, float)>("edge_preserving_filter", &cv::edgePreservingFilter);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float)>("detail_enhance", &cv::detailEnhance);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, float, float, float)>("pencil_sketch", &cv::pencilSketch);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float)>("stylization", &cv::stylization);
}