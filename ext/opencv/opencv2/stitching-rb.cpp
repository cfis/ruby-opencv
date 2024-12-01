#include <opencv2/stitching.hpp>
#include "stitching-rb.hpp"

using namespace Rice;

extern "C"
void Init_Stitching()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvStitcher = define_class_under<cv::Stitcher>(rb_mCv, "Stitcher").
    define_singleton_attr("ORIG_RESOL", &Stitcher::ORIG_RESOL).
    define_singleton_function<cv::Ptr<cv::Stitcher>(*)(cv::Stitcher::Mode)>("create", &cv::Stitcher::create).
    define_method<double(cv::Stitcher::*)() const>("registration_resol", &cv::Stitcher::registrationResol).
    define_method<void(cv::Stitcher::*)(double)>("set_registration_resol", &cv::Stitcher::setRegistrationResol).
    define_method<double(cv::Stitcher::*)() const>("seam_estimation_resol", &cv::Stitcher::seamEstimationResol).
    define_method<void(cv::Stitcher::*)(double)>("set_seam_estimation_resol", &cv::Stitcher::setSeamEstimationResol).
    define_method<double(cv::Stitcher::*)() const>("compositing_resol", &cv::Stitcher::compositingResol).
    define_method<void(cv::Stitcher::*)(double)>("set_compositing_resol", &cv::Stitcher::setCompositingResol).
    define_method<double(cv::Stitcher::*)() const>("pano_confidence_thresh", &cv::Stitcher::panoConfidenceThresh).
    define_method<void(cv::Stitcher::*)(double)>("set_pano_confidence_thresh", &cv::Stitcher::setPanoConfidenceThresh).
    define_method<bool(cv::Stitcher::*)() const>("wave_correction", &cv::Stitcher::waveCorrection).
    define_method<void(cv::Stitcher::*)(bool)>("set_wave_correction", &cv::Stitcher::setWaveCorrection).
    define_method<cv::InterpolationFlags(cv::Stitcher::*)() const>("interpolation_flags", &cv::Stitcher::interpolationFlags).
    define_method<void(cv::Stitcher::*)(cv::InterpolationFlags)>("set_interpolation_flags", &cv::Stitcher::setInterpolationFlags).
    define_method<cv::detail::WaveCorrectKind(cv::Stitcher::*)() const>("wave_correct_kind", &cv::Stitcher::waveCorrectKind).
    define_method<void(cv::Stitcher::*)(cv::detail::WaveCorrectKind)>("set_wave_correct_kind", &cv::Stitcher::setWaveCorrectKind).
    define_method<cv::Ptr<cv::Feature2D>(cv::Stitcher::*)()>("features_finder", &cv::Stitcher::featuresFinder).
    define_method<cv::Ptr<cv::Feature2D>(cv::Stitcher::*)() const>("features_finder", &cv::Stitcher::featuresFinder).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::Feature2D>)>("set_features_finder", &cv::Stitcher::setFeaturesFinder).
    define_method<cv::Ptr<cv::detail::FeaturesMatcher>(cv::Stitcher::*)()>("features_matcher", &cv::Stitcher::featuresMatcher).
    define_method<cv::Ptr<cv::detail::FeaturesMatcher>(cv::Stitcher::*)() const>("features_matcher", &cv::Stitcher::featuresMatcher).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::FeaturesMatcher>)>("set_features_matcher", &cv::Stitcher::setFeaturesMatcher).
    define_method<const cv::UMat&(cv::Stitcher::*)() const>("matching_mask", &cv::Stitcher::matchingMask).
    define_method<void(cv::Stitcher::*)(const cv::UMat&)>("set_matching_mask", &cv::Stitcher::setMatchingMask).
    define_method<cv::Ptr<cv::detail::BundleAdjusterBase>(cv::Stitcher::*)()>("bundle_adjuster", &cv::Stitcher::bundleAdjuster).
    define_method<const cv::Ptr<cv::detail::BundleAdjusterBase>(cv::Stitcher::*)() const>("bundle_adjuster", &cv::Stitcher::bundleAdjuster).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::BundleAdjusterBase>)>("set_bundle_adjuster", &cv::Stitcher::setBundleAdjuster).
    define_method<cv::Ptr<cv::detail::Estimator>(cv::Stitcher::*)()>("estimator", &cv::Stitcher::estimator).
    define_method<const cv::Ptr<cv::detail::Estimator>(cv::Stitcher::*)() const>("estimator", &cv::Stitcher::estimator).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::Estimator>)>("set_estimator", &cv::Stitcher::setEstimator).
    define_method<cv::Ptr<cv::WarperCreator>(cv::Stitcher::*)()>("warper", &cv::Stitcher::warper).
    define_method<const cv::Ptr<cv::WarperCreator>(cv::Stitcher::*)() const>("warper", &cv::Stitcher::warper).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::WarperCreator>)>("set_warper", &cv::Stitcher::setWarper).
    define_method<cv::Ptr<cv::detail::ExposureCompensator>(cv::Stitcher::*)()>("exposure_compensator", &cv::Stitcher::exposureCompensator).
    define_method<const cv::Ptr<cv::detail::ExposureCompensator>(cv::Stitcher::*)() const>("exposure_compensator", &cv::Stitcher::exposureCompensator).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::ExposureCompensator>)>("set_exposure_compensator", &cv::Stitcher::setExposureCompensator).
    define_method<cv::Ptr<cv::detail::SeamFinder>(cv::Stitcher::*)()>("seam_finder", &cv::Stitcher::seamFinder).
    define_method<const cv::Ptr<cv::detail::SeamFinder>(cv::Stitcher::*)() const>("seam_finder", &cv::Stitcher::seamFinder).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::SeamFinder>)>("set_seam_finder", &cv::Stitcher::setSeamFinder).
    define_method<cv::Ptr<cv::detail::Blender>(cv::Stitcher::*)()>("blender", &cv::Stitcher::blender).
    define_method<const cv::Ptr<cv::detail::Blender>(cv::Stitcher::*)() const>("blender", &cv::Stitcher::blender).
    define_method<void(cv::Stitcher::*)(cv::Ptr<cv::detail::Blender>)>("set_blender", &cv::Stitcher::setBlender).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const cv::_InputArray &)>("estimate_transform", &cv::Stitcher::estimateTransform).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const std::vector<cv::detail::CameraParams>&, const std::vector<int>&)>("set_transform", &cv::Stitcher::setTransform).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const std::vector<cv::detail::CameraParams>&)>("set_transform", &cv::Stitcher::setTransform).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_OutputArray &)>("compose_panorama", &cv::Stitcher::composePanorama).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compose_panorama", &cv::Stitcher::composePanorama).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const cv::_OutputArray &)>("stitch", &cv::Stitcher::stitch).
    define_method<cv::Stitcher::Status(cv::Stitcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("stitch", &cv::Stitcher::stitch).
    define_method<std::vector<int>(cv::Stitcher::*)() const>("component", &cv::Stitcher::component).
    define_method<std::vector<cv::detail::CameraParams>(cv::Stitcher::*)() const>("cameras", &cv::Stitcher::cameras).
    define_method<double(cv::Stitcher::*)() const>("work_scale", &cv::Stitcher::workScale).
    define_method<cv::UMat(cv::Stitcher::*)() const>("result_mask", &cv::Stitcher::resultMask);
  
  Enum<cv::Stitcher::Status> rb_cCvStitcherStatus = define_enum<cv::Stitcher::Status>("Status", rb_cCvStitcher).
    define_value("OK", cv::Stitcher::Status::OK).
    define_value("ERR_NEED_MORE_IMGS", cv::Stitcher::Status::ERR_NEED_MORE_IMGS).
    define_value("ERR_HOMOGRAPHY_EST_FAIL", cv::Stitcher::Status::ERR_HOMOGRAPHY_EST_FAIL).
    define_value("ERR_CAMERA_PARAMS_ADJUST_FAIL", cv::Stitcher::Status::ERR_CAMERA_PARAMS_ADJUST_FAIL);
  
  Enum<cv::Stitcher::Mode> rb_cCvStitcherMode = define_enum<cv::Stitcher::Mode>("Mode", rb_cCvStitcher).
    define_value("PANORAMA", cv::Stitcher::Mode::PANORAMA).
    define_value("SCANS", cv::Stitcher::Mode::SCANS);
  
  rb_mCv.define_module_function<cv::Ptr<cv::Stitcher>(*)(bool)>("create_stitcher", &cv::createStitcher);
  
  rb_mCv.define_module_function<cv::Ptr<cv::Stitcher>(*)(bool)>("create_stitcher_scans", &cv::createStitcherScans);
}