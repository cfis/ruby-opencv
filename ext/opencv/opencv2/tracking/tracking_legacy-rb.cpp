#include <opencv2/tracking/tracking_legacy.hpp>
#include "tracking_legacy-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrackingLegacy()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvLegacy = define_module_under(rb_mCv, "Legacy");
  
  Module rb_mCvLegacyTracking = define_module_under(rb_mCvLegacy, "Tracking");
  
  Class rb_cCvLegacyTracker = define_class_under<cv::legacy::Tracker, cv::Algorithm>(rb_mCvLegacyTracking, "Tracker").
    define_constructor(Constructor<cv::legacy::tracking::Tracker>()).
    define_method<bool(cv::legacy::tracking::Tracker::*)(const cv::_InputArray &, const cv::Rect_<double>&)>("init", &cv::legacy::tracking::Tracker::init).
    define_method<bool(cv::legacy::tracking::Tracker::*)(const cv::_InputArray &, cv::Rect_<double>&)>("update", &cv::legacy::tracking::Tracker::update).
    define_method<void(cv::legacy::tracking::Tracker::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::Tracker::read).
    define_method<void(cv::legacy::tracking::Tracker::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::Tracker::write);
  
  Class rb_cCvLegacyTrackerMIL = define_class_under<cv::legacy::TrackerMIL, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMIL").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMIL>(*)(const cv::legacy::TrackerMIL::Params&)>("create", &cv::legacy::tracking::TrackerMIL::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMIL>(*)()>("create", &cv::legacy::tracking::TrackerMIL::create);
  
  Class rb_cCvLegacyTrackerMILParams = define_class_under<cv::legacy::TrackerMIL::Params>(rb_cCvLegacyTrackerMIL, "Params").
    define_method<void(cv::legacy::tracking::TrackerMIL::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerMIL::Params::read).
    define_method<void(cv::legacy::tracking::TrackerMIL::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerMIL::Params::write);
  
  Class rb_cCvLegacyTrackerBoosting = define_class_under<cv::legacy::TrackerBoosting, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerBoosting").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerBoosting>(*)(const cv::legacy::TrackerBoosting::Params&)>("create", &cv::legacy::tracking::TrackerBoosting::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerBoosting>(*)()>("create", &cv::legacy::tracking::TrackerBoosting::create);
  
  Class rb_cCvLegacyTrackerBoostingParams = define_class_under<cv::legacy::TrackerBoosting::Params>(rb_cCvLegacyTrackerBoosting, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerBoosting::Params>()).
    define_attr("num_classifiers", &cv::legacy::tracking::TrackerBoosting::Params::numClassifiers).
    define_attr("sampler_overlap", &cv::legacy::tracking::TrackerBoosting::Params::samplerOverlap).
    define_attr("sampler_search_factor", &cv::legacy::tracking::TrackerBoosting::Params::samplerSearchFactor).
    define_attr("iteration_init", &cv::legacy::tracking::TrackerBoosting::Params::iterationInit).
    define_attr("feature_set_num_features", &cv::legacy::tracking::TrackerBoosting::Params::featureSetNumFeatures).
    define_method<void(cv::legacy::tracking::TrackerBoosting::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerBoosting::Params::read).
    define_method<void(cv::legacy::tracking::TrackerBoosting::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerBoosting::Params::write);
  
  Class rb_cCvLegacyTrackerMedianFlow = define_class_under<cv::legacy::TrackerMedianFlow, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMedianFlow").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMedianFlow>(*)(const cv::legacy::TrackerMedianFlow::Params&)>("create", &cv::legacy::tracking::TrackerMedianFlow::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMedianFlow>(*)()>("create", &cv::legacy::tracking::TrackerMedianFlow::create);
  
  Class rb_cCvLegacyTrackerMedianFlowParams = define_class_under<cv::legacy::TrackerMedianFlow::Params>(rb_cCvLegacyTrackerMedianFlow, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerMedianFlow::Params>()).
    define_attr("points_in_grid", &cv::legacy::tracking::TrackerMedianFlow::Params::pointsInGrid).
    define_attr("win_size", &cv::legacy::tracking::TrackerMedianFlow::Params::winSize).
    define_attr("max_level", &cv::legacy::tracking::TrackerMedianFlow::Params::maxLevel).
    define_attr("term_criteria", &cv::legacy::tracking::TrackerMedianFlow::Params::termCriteria).
    define_attr("win_size_ncc", &cv::legacy::tracking::TrackerMedianFlow::Params::winSizeNCC).
    define_attr("max_median_length_of_displacement_difference", &cv::legacy::tracking::TrackerMedianFlow::Params::maxMedianLengthOfDisplacementDifference).
    define_method<void(cv::legacy::tracking::TrackerMedianFlow::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerMedianFlow::Params::read).
    define_method<void(cv::legacy::tracking::TrackerMedianFlow::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerMedianFlow::Params::write);
  
  Class rb_cCvLegacyTrackerTLD = define_class_under<cv::legacy::TrackerTLD, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerTLD").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerTLD>(*)(const cv::legacy::TrackerTLD::Params&)>("create", &cv::legacy::tracking::TrackerTLD::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerTLD>(*)()>("create", &cv::legacy::tracking::TrackerTLD::create);
  
  Class rb_cCvLegacyTrackerTLDParams = define_class_under<cv::legacy::TrackerTLD::Params>(rb_cCvLegacyTrackerTLD, "Params").
    define_constructor(Constructor<cv::legacy::tracking::TrackerTLD::Params>()).
    define_method<void(cv::legacy::tracking::TrackerTLD::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerTLD::Params::read).
    define_method<void(cv::legacy::tracking::TrackerTLD::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerTLD::Params::write);
  
  Class rb_cCvLegacyTrackerKCF = define_class_under<cv::legacy::TrackerKCF, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerKCF").
    define_method<void(cv::legacy::tracking::TrackerKCF::*)(void (const Mat, const Rect, Mat &)*, bool)>("set_feature_extractor", &cv::legacy::tracking::TrackerKCF::setFeatureExtractor).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerKCF>(*)(const cv::legacy::TrackerKCF::Params&)>("create", &cv::legacy::tracking::TrackerKCF::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerKCF>(*)()>("create", &cv::legacy::tracking::TrackerKCF::create);
  
  Class rb_cCvLegacyTrackerKCFParams = define_class_under<cv::legacy::TrackerKCF::Params>(rb_cCvLegacyTrackerKCF, "Params").
    define_method<void(cv::legacy::tracking::TrackerKCF::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerKCF::Params::read).
    define_method<void(cv::legacy::tracking::TrackerKCF::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerKCF::Params::write);
  
  
  Class rb_cCvLegacyTrackerMOSSE = define_class_under<cv::legacy::TrackerMOSSE, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerMOSSE").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerMOSSE>(*)()>("create", &cv::legacy::tracking::TrackerMOSSE::create);
  
  Class rb_cCvLegacyMultiTracker = define_class_under<cv::legacy::MultiTracker, cv::Algorithm>(rb_mCvLegacyTracking, "MultiTracker").
    define_constructor(Constructor<cv::legacy::tracking::MultiTracker>()).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(cv::Ptr<cv::legacy::Tracker>, const cv::_InputArray &, const cv::Rect_<double>&)>("add", &cv::legacy::tracking::MultiTracker::add).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(std::vector<cv::Ptr<cv::legacy::Tracker>>, const cv::_InputArray &, std::vector<cv::Rect_<double>>)>("add", &cv::legacy::tracking::MultiTracker::add).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(const cv::_InputArray &)>("update", &cv::legacy::tracking::MultiTracker::update).
    define_method<bool(cv::legacy::tracking::MultiTracker::*)(const cv::_InputArray &, std::vector<cv::Rect_<double>>&)>("update", &cv::legacy::tracking::MultiTracker::update).
    define_method<const std::vector<cv::Rect_<double>>&(cv::legacy::tracking::MultiTracker::*)() const>("get_objects", &cv::legacy::tracking::MultiTracker::getObjects).
    define_singleton_function<cv::Ptr<cv::legacy::MultiTracker>(*)()>("create", &cv::legacy::tracking::MultiTracker::create);
  
  Class rb_cCvLegacyMultiTrackerAlt = define_class_under<cv::legacy::MultiTracker_Alt>(rb_mCvLegacyTracking, "MultiTrackerAlt").
    define_constructor(Constructor<cv::legacy::tracking::MultiTracker_Alt>()).
    define_method<bool(cv::legacy::tracking::MultiTracker_Alt::*)(const cv::_InputArray &, const cv::Rect_<double>&, cv::Ptr<cv::legacy::Tracker>)>("add_target", &cv::legacy::tracking::MultiTracker_Alt::addTarget).
    define_method<bool(cv::legacy::tracking::MultiTracker_Alt::*)(const cv::_InputArray &)>("update", &cv::legacy::tracking::MultiTracker_Alt::update).
    define_attr("target_num", &cv::legacy::tracking::MultiTracker_Alt::targetNum).
    define_attr("trackers", &cv::legacy::tracking::MultiTracker_Alt::trackers).
    define_attr("bounding_boxes", &cv::legacy::tracking::MultiTracker_Alt::boundingBoxes).
    define_attr("colors", &cv::legacy::tracking::MultiTracker_Alt::colors);
  
  Class rb_cCvLegacyMultiTrackerTLD = define_class_under<cv::legacy::MultiTrackerTLD, cv::legacy::MultiTracker_Alt>(rb_mCvLegacyTracking, "MultiTrackerTLD").
    define_method<bool(cv::legacy::tracking::MultiTrackerTLD::*)(const cv::_InputArray &)>("update_opt", &cv::legacy::tracking::MultiTrackerTLD::update_opt);
  
  Class rb_cCvLegacyTrackerCSRT = define_class_under<cv::legacy::TrackerCSRT, cv::legacy::Tracker>(rb_mCvLegacyTracking, "TrackerCSRT").
    define_singleton_function<cv::Ptr<cv::legacy::TrackerCSRT>(*)(const cv::legacy::TrackerCSRT::Params&)>("create", &cv::legacy::tracking::TrackerCSRT::create).
    define_singleton_function<cv::Ptr<cv::legacy::TrackerCSRT>(*)()>("create", &cv::legacy::tracking::TrackerCSRT::create).
    define_method<void(cv::legacy::tracking::TrackerCSRT::*)(const cv::_InputArray &)>("set_initial_mask", &cv::legacy::tracking::TrackerCSRT::setInitialMask);
  
  Class rb_cCvLegacyTrackerCSRTParams = define_class_under<cv::legacy::TrackerCSRT::Params>(rb_cCvLegacyTrackerCSRT, "Params").
    define_method<void(cv::legacy::tracking::TrackerCSRT::Params::*)(const cv::FileNode&)>("read", &cv::legacy::tracking::TrackerCSRT::Params::read).
    define_method<void(cv::legacy::tracking::TrackerCSRT::Params::*)(cv::FileStorage&) const>("write", &cv::legacy::tracking::TrackerCSRT::Params::write);
  
  rb_mCvLegacyTracking.define_module_function<int(*)(const cv::Ptr<cv::legacy::Tracker>&)>("upgrade_tracking_api", &cv::legacy::tracking::upgradeTrackingAPI);
}