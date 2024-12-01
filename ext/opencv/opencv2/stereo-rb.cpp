#include <opencv2/stereo.hpp>
#include "stereo-rb.hpp"

using namespace Rice;

extern "C"
void Init_Stereo()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStereo = define_module_under(rb_mCv, "Stereo");
  
  Class rb_cCvStereoStereoMatcher = define_class_under<cv::stereo::StereoMatcher, cv::Algorithm>(rb_mCvStereo, "StereoMatcher").
    define_method<void(cv::stereo::StereoMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::stereo::StereoMatcher::compute).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_min_disparity", &cv::stereo::StereoMatcher::getMinDisparity).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_min_disparity", &cv::stereo::StereoMatcher::setMinDisparity).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_num_disparities", &cv::stereo::StereoMatcher::getNumDisparities).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_num_disparities", &cv::stereo::StereoMatcher::setNumDisparities).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_block_size", &cv::stereo::StereoMatcher::getBlockSize).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_block_size", &cv::stereo::StereoMatcher::setBlockSize).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_speckle_window_size", &cv::stereo::StereoMatcher::getSpeckleWindowSize).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_speckle_window_size", &cv::stereo::StereoMatcher::setSpeckleWindowSize).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_speckle_range", &cv::stereo::StereoMatcher::getSpeckleRange).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_speckle_range", &cv::stereo::StereoMatcher::setSpeckleRange).
    define_method<int(cv::stereo::StereoMatcher::*)() const>("get_disp12_max_diff", &cv::stereo::StereoMatcher::getDisp12MaxDiff).
    define_method<void(cv::stereo::StereoMatcher::*)(int)>("set_disp12_max_diff", &cv::stereo::StereoMatcher::setDisp12MaxDiff);
  
  
  Class rb_cCvStereoStereoBinaryBM = define_class_under<cv::stereo::StereoBinaryBM, cv::stereo::StereoMatcher>(rb_mCvStereo, "StereoBinaryBM").
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_pre_filter_type", &cv::stereo::StereoBinaryBM::getPreFilterType).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_pre_filter_type", &cv::stereo::StereoBinaryBM::setPreFilterType).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_pre_filter_size", &cv::stereo::StereoBinaryBM::getPreFilterSize).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_pre_filter_size", &cv::stereo::StereoBinaryBM::setPreFilterSize).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_pre_filter_cap", &cv::stereo::StereoBinaryBM::getPreFilterCap).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_pre_filter_cap", &cv::stereo::StereoBinaryBM::setPreFilterCap).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_texture_threshold", &cv::stereo::StereoBinaryBM::getTextureThreshold).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_texture_threshold", &cv::stereo::StereoBinaryBM::setTextureThreshold).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_uniqueness_ratio", &cv::stereo::StereoBinaryBM::getUniquenessRatio).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_uniqueness_ratio", &cv::stereo::StereoBinaryBM::setUniquenessRatio).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_smaller_block_size", &cv::stereo::StereoBinaryBM::getSmallerBlockSize).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_smaller_block_size", &cv::stereo::StereoBinaryBM::setSmallerBlockSize).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_scalle_factor", &cv::stereo::StereoBinaryBM::getScalleFactor).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_scalle_factor", &cv::stereo::StereoBinaryBM::setScalleFactor).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_spekle_removal_technique", &cv::stereo::StereoBinaryBM::getSpekleRemovalTechnique).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_spekle_removal_technique", &cv::stereo::StereoBinaryBM::setSpekleRemovalTechnique).
    define_method<bool(cv::stereo::StereoBinaryBM::*)() const>("get_use_prefilter", &cv::stereo::StereoBinaryBM::getUsePrefilter).
    define_method<void(cv::stereo::StereoBinaryBM::*)(bool)>("set_use_prefilter", &cv::stereo::StereoBinaryBM::setUsePrefilter).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_binary_kernel_type", &cv::stereo::StereoBinaryBM::getBinaryKernelType).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_binary_kernel_type", &cv::stereo::StereoBinaryBM::setBinaryKernelType).
    define_method<int(cv::stereo::StereoBinaryBM::*)() const>("get_agregation_window_size", &cv::stereo::StereoBinaryBM::getAgregationWindowSize).
    define_method<void(cv::stereo::StereoBinaryBM::*)(int)>("set_agregation_window_size", &cv::stereo::StereoBinaryBM::setAgregationWindowSize).
    define_singleton_function<cv::Ptr<cv::stereo::StereoBinaryBM>(*)(int, int)>("create", &cv::stereo::StereoBinaryBM::create);
  
  
  Class rb_cCvStereoStereoBinarySGBM = define_class_under<cv::stereo::StereoBinarySGBM, cv::stereo::StereoMatcher>(rb_mCvStereo, "StereoBinarySGBM").
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_pre_filter_cap", &cv::stereo::StereoBinarySGBM::getPreFilterCap).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_pre_filter_cap", &cv::stereo::StereoBinarySGBM::setPreFilterCap).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_uniqueness_ratio", &cv::stereo::StereoBinarySGBM::getUniquenessRatio).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_uniqueness_ratio", &cv::stereo::StereoBinarySGBM::setUniquenessRatio).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_p1", &cv::stereo::StereoBinarySGBM::getP1).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_p1", &cv::stereo::StereoBinarySGBM::setP1).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_p2", &cv::stereo::StereoBinarySGBM::getP2).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_p2", &cv::stereo::StereoBinarySGBM::setP2).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_mode", &cv::stereo::StereoBinarySGBM::getMode).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_mode", &cv::stereo::StereoBinarySGBM::setMode).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_spekle_removal_technique", &cv::stereo::StereoBinarySGBM::getSpekleRemovalTechnique).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_spekle_removal_technique", &cv::stereo::StereoBinarySGBM::setSpekleRemovalTechnique).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_binary_kernel_type", &cv::stereo::StereoBinarySGBM::getBinaryKernelType).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_binary_kernel_type", &cv::stereo::StereoBinarySGBM::setBinaryKernelType).
    define_method<int(cv::stereo::StereoBinarySGBM::*)() const>("get_sub_pixel_interpolation_method", &cv::stereo::StereoBinarySGBM::getSubPixelInterpolationMethod).
    define_method<void(cv::stereo::StereoBinarySGBM::*)(int)>("set_sub_pixel_interpolation_method", &cv::stereo::StereoBinarySGBM::setSubPixelInterpolationMethod).
    define_singleton_function<cv::Ptr<cv::stereo::StereoBinarySGBM>(*)(int, int, int, int, int, int, int, int, int, int, int)>("create", &cv::stereo::StereoBinarySGBM::create);
}