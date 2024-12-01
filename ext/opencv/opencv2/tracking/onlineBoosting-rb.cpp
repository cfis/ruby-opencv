#include <opencv2/tracking/onlineBoosting.hpp>
#include "onlineBoosting-rb.hpp"

using namespace Rice;

extern "C"
void Init_OnlineBoosting()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Module rb_mCvDetailTrackingOnlineBoosting = define_module_under(rb_mCvDetailTracking, "OnlineBoosting");
  
  Class rb_cCvDetailStrongClassifierDirectSelection = define_class_under<cv::detail::StrongClassifierDirectSelection>(rb_mCvDetailTrackingOnlineBoosting, "StrongClassifierDirectSelection").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::StrongClassifierDirectSelection, int, int, cv::Size_<int>, const cv::Rect_<int>&, bool, int>()).
    define_method<void(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("init_base_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::initBaseClassifier).
    define_method<bool(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const cv::Mat&, int, float)>("update", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::update).
    define_method<float(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const cv::Mat&)>("eval", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::eval).
    define_method<std::vector<int>(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("get_selected_weak_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getSelectedWeakClassifier).
    define_method<float(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(const std::vector<cv::Mat>&, const cv::Rect_<int>&, int&)>("classify_smooth", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::classifySmooth).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)()>("get_num_base_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getNumBaseClassifier).
    define_method<cv::Size_<int>(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_patch_size", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getPatchSize).
    define_method<cv::Rect_<int>(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_roi", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getROI).
    define_method<bool(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_use_feature_exchange", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getUseFeatureExchange).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_replaced_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getReplacedClassifier).
    define_method<void(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)(int)>("replace_weak_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::replaceWeakClassifier).
    define_method<int(cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::*)() const>("get_swapped_classifier", &cv::detail::tracking::online_boosting::StrongClassifierDirectSelection::getSwappedClassifier);
  
  Class rb_cCvDetailBaseClassifier = define_class_under<cv::detail::BaseClassifier>(rb_mCvDetailTrackingOnlineBoosting, "BaseClassifier").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::BaseClassifier, int, int>()).
    define_constructor(Constructor<cv::detail::tracking::online_boosting::BaseClassifier, int, int, cv::detail::WeakClassifierHaarFeature**>()).
    define_method<cv::detail::WeakClassifierHaarFeature**(cv::detail::tracking::online_boosting::BaseClassifier::*)()>("get_reference_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getReferenceWeakClassifier).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(const cv::Mat&, int, float, std::vector<bool>&)>("train_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::trainClassifier).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(std::vector<bool>&, float, std::vector<float>&)>("select_best_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::selectBestClassifier).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(const std::vector<float>&)>("compute_replace_weakest_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::computeReplaceWeakestClassifier).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(int, int)>("replace_classifier_statistic", &cv::detail::tracking::online_boosting::BaseClassifier::replaceClassifierStatistic).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)()>("get_idx_of_new_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getIdxOfNewWeakClassifier).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)(const cv::Mat&)>("eval", &cv::detail::tracking::online_boosting::BaseClassifier::eval).
    define_method<float(cv::detail::tracking::online_boosting::BaseClassifier::*)(int)>("get_error", &cv::detail::tracking::online_boosting::BaseClassifier::getError).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(float*)>("get_errors", &cv::detail::tracking::online_boosting::BaseClassifier::getErrors).
    define_method<int(cv::detail::tracking::online_boosting::BaseClassifier::*)() const>("get_selected_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::getSelectedClassifier).
    define_method<void(cv::detail::tracking::online_boosting::BaseClassifier::*)(int)>("replace_weak_classifier", &cv::detail::tracking::online_boosting::BaseClassifier::replaceWeakClassifier);
  
  Class rb_cCvDetailEstimatedGaussDistribution = define_class_under<cv::detail::EstimatedGaussDistribution>(rb_mCvDetailTrackingOnlineBoosting, "EstimatedGaussDistribution").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::EstimatedGaussDistribution>()).
    define_constructor(Constructor<cv::detail::tracking::online_boosting::EstimatedGaussDistribution, float, float, float, float>()).
    define_method<void(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)(float)>("update", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::update).
    define_method<float(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)()>("get_mean", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::getMean).
    define_method<float(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)()>("get_sigma", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::getSigma).
    define_method<void(cv::detail::tracking::online_boosting::EstimatedGaussDistribution::*)(float, float)>("set_values", &cv::detail::tracking::online_boosting::EstimatedGaussDistribution::setValues);
  
  Class rb_cCvDetailWeakClassifierHaarFeature = define_class_under<cv::detail::WeakClassifierHaarFeature>(rb_mCvDetailTrackingOnlineBoosting, "WeakClassifierHaarFeature").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::WeakClassifierHaarFeature>()).
    define_method<bool(cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::*)(float, int)>("update", &cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::update).
    define_method<int(cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::*)(float)>("eval", &cv::detail::tracking::online_boosting::WeakClassifierHaarFeature::eval);
  
  Class rb_cCvDetailDetector = define_class_under<cv::detail::Detector>(rb_mCvDetailTrackingOnlineBoosting, "Detector").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::Detector, cv::detail::StrongClassifierDirectSelection*>()).
    define_method<void(cv::detail::tracking::online_boosting::Detector::*)(const std::vector<cv::Mat>&, float)>("classify_smooth", &cv::detail::tracking::online_boosting::Detector::classifySmooth).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)()>("get_num_detections", &cv::detail::tracking::online_boosting::Detector::getNumDetections).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_confidence", &cv::detail::tracking::online_boosting::Detector::getConfidence).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_confidence_of_detection", &cv::detail::tracking::online_boosting::Detector::getConfidenceOfDetection).
    define_method<float(cv::detail::tracking::online_boosting::Detector::*)()>("get_confidence_of_best_detection", &cv::detail::tracking::online_boosting::Detector::getConfidenceOfBestDetection).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)()>("get_patch_idx_of_best_detection", &cv::detail::tracking::online_boosting::Detector::getPatchIdxOfBestDetection).
    define_method<int(cv::detail::tracking::online_boosting::Detector::*)(int)>("get_patch_idx_of_detection", &cv::detail::tracking::online_boosting::Detector::getPatchIdxOfDetection).
    define_method<const std::vector<int>&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_idx_detections", &cv::detail::tracking::online_boosting::Detector::getIdxDetections).
    define_method<const std::vector<float>&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_confidences", &cv::detail::tracking::online_boosting::Detector::getConfidences).
    define_method<const cv::Mat&(cv::detail::tracking::online_boosting::Detector::*)() const>("get_conf_image_display", &cv::detail::tracking::online_boosting::Detector::getConfImageDisplay);
  
  Class rb_cCvDetailClassifierThreshold = define_class_under<cv::detail::ClassifierThreshold>(rb_mCvDetailTrackingOnlineBoosting, "ClassifierThreshold").
    define_constructor(Constructor<cv::detail::tracking::online_boosting::ClassifierThreshold, cv::detail::EstimatedGaussDistribution*, cv::detail::EstimatedGaussDistribution*>()).
    define_method<void(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(float, int)>("update", &cv::detail::tracking::online_boosting::ClassifierThreshold::update).
    define_method<int(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(float)>("eval", &cv::detail::tracking::online_boosting::ClassifierThreshold::eval).
    define_method<void*(cv::detail::tracking::online_boosting::ClassifierThreshold::*)(int)>("get_distribution", &cv::detail::tracking::online_boosting::ClassifierThreshold::getDistribution);
}