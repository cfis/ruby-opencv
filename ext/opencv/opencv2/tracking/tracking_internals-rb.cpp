#include <opencv2/tracking/tracking_internals.hpp>
#include "tracking_internals-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrackingInternals()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Class rb_cCvDetailTrackerContribFeature = define_class_under<cv::detail::TrackerContribFeature, cv::detail::TrackerFeature>(rb_mCvDetailTracking, "TrackerContribFeature").
    define_singleton_function<cv::Ptr<cv::detail::TrackerContribFeature>(*)(const std::basic_string<char>&)>("create", &cv::detail::tracking::TrackerContribFeature::create).
    define_method<void(cv::detail::tracking::TrackerContribFeature::*)(cv::Mat&, int)>("selection", &cv::detail::tracking::TrackerContribFeature::selection).
    define_method<std::basic_string<char>(cv::detail::tracking::TrackerContribFeature::*)() const>("get_class_name", &cv::detail::tracking::TrackerContribFeature::getClassName);
  
  Class rb_cCvDetailTrackerContribFeatureSet = define_class_under<cv::detail::TrackerContribFeatureSet>(rb_mCvDetailTracking, "TrackerContribFeatureSet").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribFeatureSet>()).
    define_method<void(cv::detail::tracking::TrackerContribFeatureSet::*)(const std::vector<cv::Mat>&)>("extraction", &cv::detail::tracking::TrackerContribFeatureSet::extraction).
    define_method<void(cv::detail::tracking::TrackerContribFeatureSet::*)()>("selection", &cv::detail::tracking::TrackerContribFeatureSet::selection).
    define_method<void(cv::detail::tracking::TrackerContribFeatureSet::*)()>("remove_outliers", &cv::detail::tracking::TrackerContribFeatureSet::removeOutliers).
    define_method<bool(cv::detail::tracking::TrackerContribFeatureSet::*)(std::basic_string<char>)>("add_tracker_feature", &cv::detail::tracking::TrackerContribFeatureSet::addTrackerFeature).
    define_method<bool(cv::detail::tracking::TrackerContribFeatureSet::*)(cv::Ptr<cv::detail::TrackerContribFeature>&)>("add_tracker_feature", &cv::detail::tracking::TrackerContribFeatureSet::addTrackerFeature).
    define_method<const std::vector<std::pair<std::basic_string<char>, cv::Ptr<cv::detail::TrackerContribFeature>>>&(cv::detail::tracking::TrackerContribFeatureSet::*)() const>("get_tracker_feature", &cv::detail::tracking::TrackerContribFeatureSet::getTrackerFeature).
    define_method<const std::vector<cv::Mat>&(cv::detail::tracking::TrackerContribFeatureSet::*)() const>("get_responses", &cv::detail::tracking::TrackerContribFeatureSet::getResponses);
  
  Class rb_cCvDetailTrackerContribSamplerAlgorithm = define_class_under<cv::detail::TrackerContribSamplerAlgorithm, cv::detail::TrackerSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerContribSamplerAlgorithm").
    define_singleton_function<cv::Ptr<cv::detail::TrackerContribSamplerAlgorithm>(*)(const std::basic_string<char>&)>("create", &cv::detail::tracking::TrackerContribSamplerAlgorithm::create).
    define_method<bool(cv::detail::tracking::TrackerContribSamplerAlgorithm::*)(const cv::Mat&, const cv::Rect_<int>&, std::vector<cv::Mat>&)>("sampling", &cv::detail::tracking::TrackerContribSamplerAlgorithm::sampling).
    define_method<std::basic_string<char>(cv::detail::tracking::TrackerContribSamplerAlgorithm::*)() const>("get_class_name", &cv::detail::tracking::TrackerContribSamplerAlgorithm::getClassName);
  
  Class rb_cCvDetailTrackerContribSampler = define_class_under<cv::detail::TrackerContribSampler>(rb_mCvDetailTracking, "TrackerContribSampler").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribSampler>()).
    define_method<void(cv::detail::tracking::TrackerContribSampler::*)(const cv::Mat&, cv::Rect_<int>)>("sampling", &cv::detail::tracking::TrackerContribSampler::sampling).
    define_method<const std::vector<std::pair<std::basic_string<char>, cv::Ptr<cv::detail::TrackerContribSamplerAlgorithm>>>&(cv::detail::tracking::TrackerContribSampler::*)() const>("get_samplers", &cv::detail::tracking::TrackerContribSampler::getSamplers).
    define_method<const std::vector<cv::Mat>&(cv::detail::tracking::TrackerContribSampler::*)() const>("get_samples", &cv::detail::tracking::TrackerContribSampler::getSamples).
    define_method<bool(cv::detail::tracking::TrackerContribSampler::*)(std::basic_string<char>)>("add_tracker_sampler_algorithm", &cv::detail::tracking::TrackerContribSampler::addTrackerSamplerAlgorithm).
    define_method<bool(cv::detail::tracking::TrackerContribSampler::*)(cv::Ptr<cv::detail::TrackerContribSamplerAlgorithm>&)>("add_tracker_sampler_algorithm", &cv::detail::tracking::TrackerContribSampler::addTrackerSamplerAlgorithm);
  
  Class rb_cCvDetailTrackerStateEstimatorAdaBoosting = define_class_under<cv::detail::TrackerStateEstimatorAdaBoosting, cv::detail::TrackerStateEstimator>(rb_mCvDetailTracking, "TrackerStateEstimatorAdaBoosting").
    define_constructor(Constructor<cv::detail::tracking::TrackerStateEstimatorAdaBoosting, int, int, int, cv::Size_<int>, const cv::Rect_<int>&>()).
    define_method<cv::Rect_<int>(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)() const>("get_sample_roi", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::getSampleROI).
    define_method<void(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)(const cv::Rect_<int>&)>("set_sample_roi", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::setSampleROI).
    define_method<void(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)(std::vector<std::pair<cv::Ptr<cv::detail::TrackerTargetState>, float>>&)>("set_current_confidence_map", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::setCurrentConfidenceMap).
    define_method<std::vector<int>(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)()>("compute_selected_weak_classifier", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::computeSelectedWeakClassifier).
    define_method<std::vector<int>(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)()>("compute_replaced_classifier", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::computeReplacedClassifier).
    define_method<std::vector<int>(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::*)()>("compute_swapped_classifier", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::computeSwappedClassifier);
  
  Class rb_cCvDetailTrackerStateEstimatorAdaBoostingTrackerAdaBoostingTargetState = define_class_under<cv::detail::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState, cv::detail::TrackerTargetState>(rb_cCvDetailTrackerStateEstimatorAdaBoosting, "TrackerAdaBoostingTargetState").
    define_constructor(Constructor<cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState, const cv::Point_<float>&, int, int, bool, const cv::Mat&>()).
    define_method<void(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::*)(const cv::Mat&)>("set_target_responses", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::setTargetResponses).
    define_method<void(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::*)(bool)>("set_target_fg", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::setTargetFg).
    define_method<cv::Mat(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::*)() const>("get_target_responses", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::getTargetResponses).
    define_method<bool(cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::*)() const>("is_target_fg", &cv::detail::tracking::TrackerStateEstimatorAdaBoosting::TrackerAdaBoostingTargetState::isTargetFg);
  
  Class rb_cCvDetailTrackerStateEstimatorSVM = define_class_under<cv::detail::TrackerStateEstimatorSVM, cv::detail::TrackerStateEstimator>(rb_mCvDetailTracking, "TrackerStateEstimatorSVM").
    define_constructor(Constructor<cv::detail::tracking::TrackerStateEstimatorSVM>());
  
  Class rb_cCvDetailTrackerContribSamplerCSC = define_class_under<cv::detail::TrackerContribSamplerCSC, cv::detail::TrackerContribSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerContribSamplerCSC").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribSamplerCSC, const cv::detail::TrackerContribSamplerCSC::Params&>()).
    define_method<void(cv::detail::tracking::TrackerContribSamplerCSC::*)(int)>("set_mode", &cv::detail::tracking::TrackerContribSamplerCSC::setMode);
  
  Class rb_cCvDetailTrackerContribSamplerCSCParams = define_class_under<cv::detail::TrackerContribSamplerCSC::Params>(rb_cCvDetailTrackerContribSamplerCSC, "Params").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribSamplerCSC::Params>()).
    define_attr("init_in_rad", &cv::detail::tracking::TrackerContribSamplerCSC::Params::initInRad).
    define_attr("track_in_pos_rad", &cv::detail::tracking::TrackerContribSamplerCSC::Params::trackInPosRad).
    define_attr("search_win_size", &cv::detail::tracking::TrackerContribSamplerCSC::Params::searchWinSize).
    define_attr("init_max_neg_num", &cv::detail::tracking::TrackerContribSamplerCSC::Params::initMaxNegNum).
    define_attr("track_max_pos_num", &cv::detail::tracking::TrackerContribSamplerCSC::Params::trackMaxPosNum).
    define_attr("track_max_neg_num", &cv::detail::tracking::TrackerContribSamplerCSC::Params::trackMaxNegNum);
  
  
  Class rb_cCvDetailTrackerSamplerCS = define_class_under<cv::detail::TrackerSamplerCS, cv::detail::TrackerContribSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerCS").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerCS, const cv::detail::TrackerSamplerCS::Params&>()).
    define_method<void(cv::detail::tracking::TrackerSamplerCS::*)(int)>("set_mode", &cv::detail::tracking::TrackerSamplerCS::setMode).
    define_method<bool(cv::detail::tracking::TrackerSamplerCS::*)(const cv::Mat&, cv::Rect_<int>, std::vector<cv::Mat>&)>("sampling_impl", &cv::detail::tracking::TrackerSamplerCS::samplingImpl).
    define_method<cv::Rect_<int>(cv::detail::tracking::TrackerSamplerCS::*)() const>("get_roi", &cv::detail::tracking::TrackerSamplerCS::getROI);
  
  Class rb_cCvDetailTrackerSamplerCSParams = define_class_under<cv::detail::TrackerSamplerCS::Params>(rb_cCvDetailTrackerSamplerCS, "Params").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerCS::Params>()).
    define_attr("overlap", &cv::detail::tracking::TrackerSamplerCS::Params::overlap).
    define_attr("search_factor", &cv::detail::tracking::TrackerSamplerCS::Params::searchFactor);
  
  
  Class rb_cCvDetailTrackerSamplerPF = define_class_under<cv::detail::TrackerSamplerPF, cv::detail::TrackerContribSamplerAlgorithm>(rb_mCvDetailTracking, "TrackerSamplerPF").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerPF, const cv::Mat&, const cv::detail::TrackerSamplerPF::Params&>());
  
  Class rb_cCvDetailTrackerSamplerPFParams = define_class_under<cv::detail::TrackerSamplerPF::Params>(rb_cCvDetailTrackerSamplerPF, "Params").
    define_constructor(Constructor<cv::detail::tracking::TrackerSamplerPF::Params>()).
    define_attr("iteration_num", &cv::detail::tracking::TrackerSamplerPF::Params::iterationNum).
    define_attr("particles_num", &cv::detail::tracking::TrackerSamplerPF::Params::particlesNum).
    define_attr("alpha", &cv::detail::tracking::TrackerSamplerPF::Params::alpha).
    define_attr("std", &cv::detail::tracking::TrackerSamplerPF::Params::std);
  
  Class rb_cCvDetailTrackerFeatureFeature2d = define_class_under<cv::detail::TrackerFeatureFeature2d, cv::detail::TrackerContribFeature>(rb_mCvDetailTracking, "TrackerFeatureFeature2d").
    define_constructor(Constructor<cv::detail::tracking::TrackerFeatureFeature2d, std::basic_string<char>, std::basic_string<char>>()).
    define_method<void(cv::detail::tracking::TrackerFeatureFeature2d::*)(cv::Mat&, int)>("selection", &cv::detail::tracking::TrackerFeatureFeature2d::selection);
  
  Class rb_cCvDetailTrackerFeatureHOG = define_class_under<cv::detail::TrackerFeatureHOG, cv::detail::TrackerContribFeature>(rb_mCvDetailTracking, "TrackerFeatureHOG").
    define_constructor(Constructor<cv::detail::tracking::TrackerFeatureHOG>()).
    define_method<void(cv::detail::tracking::TrackerFeatureHOG::*)(cv::Mat&, int)>("selection", &cv::detail::tracking::TrackerFeatureHOG::selection);
  
  Class rb_cCvDetailTrackerContribFeatureHAAR = define_class_under<cv::detail::TrackerContribFeatureHAAR, cv::detail::TrackerContribFeature>(rb_mCvDetailTracking, "TrackerContribFeatureHAAR").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribFeatureHAAR, const cv::detail::TrackerContribFeatureHAAR::Params&>()).
    define_method<bool(cv::detail::tracking::TrackerContribFeatureHAAR::*)(const std::vector<int>, const std::vector<cv::Mat>&, cv::Mat&)>("extract_selected", &cv::detail::tracking::TrackerContribFeatureHAAR::extractSelected).
    define_method<void(cv::detail::tracking::TrackerContribFeatureHAAR::*)(cv::Mat&, int)>("selection", &cv::detail::tracking::TrackerContribFeatureHAAR::selection).
    define_method<bool(cv::detail::tracking::TrackerContribFeatureHAAR::*)(int, int)>("swap_feature", &cv::detail::tracking::TrackerContribFeatureHAAR::swapFeature).
    define_method<bool(cv::detail::tracking::TrackerContribFeatureHAAR::*)(int, cv::detail::CvHaarEvaluator::FeatureHaar&)>("swap_feature", &cv::detail::tracking::TrackerContribFeatureHAAR::swapFeature).
    define_method<cv::detail::CvHaarEvaluator::FeatureHaar&(cv::detail::tracking::TrackerContribFeatureHAAR::*)(int)>("get_feature_at", &cv::detail::tracking::TrackerContribFeatureHAAR::getFeatureAt);
  
  Class rb_cCvDetailTrackerContribFeatureHAARParams = define_class_under<cv::detail::TrackerContribFeatureHAAR::Params>(rb_cCvDetailTrackerContribFeatureHAAR, "Params").
    define_constructor(Constructor<cv::detail::tracking::TrackerContribFeatureHAAR::Params>()).
    define_attr("num_features", &cv::detail::tracking::TrackerContribFeatureHAAR::Params::numFeatures).
    define_attr("rect_size", &cv::detail::tracking::TrackerContribFeatureHAAR::Params::rectSize).
    define_attr("is_integral", &cv::detail::tracking::TrackerContribFeatureHAAR::Params::isIntegral);
  
  Class rb_cCvDetailTrackerFeatureLBP = define_class_under<cv::detail::TrackerFeatureLBP, cv::detail::TrackerContribFeature>(rb_mCvDetailTracking, "TrackerFeatureLBP").
    define_constructor(Constructor<cv::detail::tracking::TrackerFeatureLBP>()).
    define_method<void(cv::detail::tracking::TrackerFeatureLBP::*)(cv::Mat&, int)>("selection", &cv::detail::tracking::TrackerFeatureLBP::selection);
}