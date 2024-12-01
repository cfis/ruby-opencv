#include <opencv2/tracking/tracking_by_matching.hpp>
#include "tracking_by_matching-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrackingByMatching()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Module rb_mCvDetailTrackingTbm = define_module_under(rb_mCvDetailTracking, "Tbm");
  
  Class rb_cCvDetailTbmTrackedObject = define_class_under<cv::detail::tbm::TrackedObject>(rb_mCvDetailTrackingTbm, "TrackedObject").
    define_attr("rect", &cv::detail::tracking::tbm::TrackedObject::rect).
    define_attr("confidence", &cv::detail::tracking::tbm::TrackedObject::confidence).
    define_attr("frame_idx", &cv::detail::tracking::tbm::TrackedObject::frame_idx).
    define_attr("object_id", &cv::detail::tracking::tbm::TrackedObject::object_id).
    define_attr("timestamp", &cv::detail::tracking::tbm::TrackedObject::timestamp).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackedObject>()).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackedObject, const cv::Rect_<int>&, float, int, int>());
  
  rb_mCvDetailTrackingTbm.define_module_function<bool(*)(const cv::detail::tbm::TrackedObject&, const cv::detail::tbm::TrackedObject&)>("operator==", &cv::detail::tracking::tbm::operator==);
  
  rb_mCvDetailTrackingTbm.define_module_function<bool(*)(const cv::detail::tbm::TrackedObject&, const cv::detail::tbm::TrackedObject&)>("operator!=", &cv::detail::tracking::tbm::operator!=);
  
  Class rb_cCvDetailTbmIImageDescriptor = define_class_under<cv::detail::tbm::IImageDescriptor>(rb_mCvDetailTrackingTbm, "IImageDescriptor").
    define_method<cv::Size_<int>(cv::detail::tracking::tbm::IImageDescriptor::*)() const>("size", &cv::detail::tracking::tbm::IImageDescriptor::size).
    define_method<void(cv::detail::tracking::tbm::IImageDescriptor::*)(const cv::Mat&, cv::Mat&)>("compute", &cv::detail::tracking::tbm::IImageDescriptor::compute).
    define_method<void(cv::detail::tracking::tbm::IImageDescriptor::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::IImageDescriptor::compute);
  
  Class rb_cCvDetailTbmResizedImageDescriptor = define_class_under<cv::detail::tbm::ResizedImageDescriptor, cv::detail::tbm::IImageDescriptor>(rb_mCvDetailTrackingTbm, "ResizedImageDescriptor").
    define_constructor(Constructor<cv::detail::tracking::tbm::ResizedImageDescriptor, const cv::Size_<int>&, const cv::InterpolationFlags>()).
    define_method<cv::Size_<int>(cv::detail::tracking::tbm::ResizedImageDescriptor::*)() const>("size", &cv::detail::tracking::tbm::ResizedImageDescriptor::size).
    define_method<void(cv::detail::tracking::tbm::ResizedImageDescriptor::*)(const cv::Mat&, cv::Mat&)>("compute", &cv::detail::tracking::tbm::ResizedImageDescriptor::compute).
    define_method<void(cv::detail::tracking::tbm::ResizedImageDescriptor::*)(const std::vector<cv::Mat>&, std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::ResizedImageDescriptor::compute);
  
  Class rb_cCvDetailTbmIDescriptorDistance = define_class_under<cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "IDescriptorDistance").
    define_method<float(cv::detail::tracking::tbm::IDescriptorDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::IDescriptorDistance::compute).
    define_method<std::vector<float>(cv::detail::tracking::tbm::IDescriptorDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::IDescriptorDistance::compute);
  
  Class rb_cCvDetailTbmCosDistance = define_class_under<cv::detail::tbm::CosDistance, cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "CosDistance").
    define_constructor(Constructor<cv::detail::tracking::tbm::CosDistance, const cv::Size_<int>&>()).
    define_method<float(cv::detail::tracking::tbm::CosDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::CosDistance::compute).
    define_method<std::vector<float>(cv::detail::tracking::tbm::CosDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::CosDistance::compute);
  
  Class rb_cCvDetailTbmMatchTemplateDistance = define_class_under<cv::detail::tbm::MatchTemplateDistance, cv::detail::tbm::IDescriptorDistance>(rb_mCvDetailTrackingTbm, "MatchTemplateDistance").
    define_constructor(Constructor<cv::detail::tracking::tbm::MatchTemplateDistance, int, float, float>()).
    define_method<float(cv::detail::tracking::tbm::MatchTemplateDistance::*)(const cv::Mat&, const cv::Mat&)>("compute", &cv::detail::tracking::tbm::MatchTemplateDistance::compute).
    define_method<std::vector<float>(cv::detail::tracking::tbm::MatchTemplateDistance::*)(const std::vector<cv::Mat>&, const std::vector<cv::Mat>&)>("compute", &cv::detail::tracking::tbm::MatchTemplateDistance::compute);
  
  Class rb_cCvDetailTbmTrackerParams = define_class_under<cv::detail::tbm::TrackerParams>(rb_mCvDetailTrackingTbm, "TrackerParams").
    define_attr("min_track_duration", &cv::detail::tracking::tbm::TrackerParams::min_track_duration).
    define_attr("forget_delay", &cv::detail::tracking::tbm::TrackerParams::forget_delay).
    define_attr("aff_thr_fast", &cv::detail::tracking::tbm::TrackerParams::aff_thr_fast).
    define_attr("aff_thr_strong", &cv::detail::tracking::tbm::TrackerParams::aff_thr_strong).
    define_attr("shape_affinity_w", &cv::detail::tracking::tbm::TrackerParams::shape_affinity_w).
    define_attr("motion_affinity_w", &cv::detail::tracking::tbm::TrackerParams::motion_affinity_w).
    define_attr("time_affinity_w", &cv::detail::tracking::tbm::TrackerParams::time_affinity_w).
    define_attr("min_det_conf", &cv::detail::tracking::tbm::TrackerParams::min_det_conf).
    define_attr("bbox_aspect_ratios_range", &cv::detail::tracking::tbm::TrackerParams::bbox_aspect_ratios_range).
    define_attr("bbox_heights_range", &cv::detail::tracking::tbm::TrackerParams::bbox_heights_range).
    define_attr("predict", &cv::detail::tracking::tbm::TrackerParams::predict).
    define_attr("strong_affinity_thr", &cv::detail::tracking::tbm::TrackerParams::strong_affinity_thr).
    define_attr("reid_thr", &cv::detail::tracking::tbm::TrackerParams::reid_thr).
    define_attr("drop_forgotten_tracks", &cv::detail::tracking::tbm::TrackerParams::drop_forgotten_tracks).
    define_attr("max_num_objects_in_track", &cv::detail::tracking::tbm::TrackerParams::max_num_objects_in_track).
    define_constructor(Constructor<cv::detail::tracking::tbm::TrackerParams>());
  
  Class rb_cCvDetailTbmTrack = define_class_under<cv::detail::tbm::Track>(rb_mCvDetailTrackingTbm, "Track").
    define_constructor(Constructor<cv::detail::tracking::tbm::Track, const std::deque<cv::detail::tbm::TrackedObject>&, const cv::Mat&, const cv::Mat&, const cv::Mat&>()).
    define_method<bool(cv::detail::tracking::tbm::Track::*)() const>("empty", &cv::detail::tracking::tbm::Track::empty).
    define_method<unsigned long long(cv::detail::tracking::tbm::Track::*)() const>("size", &cv::detail::tracking::tbm::Track::size).
    define_method<const cv::detail::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)(unsigned long long) const>("operator[]", &cv::detail::tracking::tbm::Track::operator[]).
    define_method<cv::detail::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)(unsigned long long)>("operator[]", &cv::detail::tracking::tbm::Track::operator[]).
    define_method<const cv::detail::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)() const>("back", &cv::detail::tracking::tbm::Track::back).
    define_method<cv::detail::tbm::TrackedObject&(cv::detail::tracking::tbm::Track::*)()>("back", &cv::detail::tracking::tbm::Track::back).
    define_attr("objects", &cv::detail::tracking::tbm::Track::objects).
    define_attr("predicted_rect", &cv::detail::tracking::tbm::Track::predicted_rect).
    define_attr("last_image", &cv::detail::tracking::tbm::Track::last_image).
    define_attr("descriptor_fast", &cv::detail::tracking::tbm::Track::descriptor_fast).
    define_attr("descriptor_strong", &cv::detail::tracking::tbm::Track::descriptor_strong).
    define_attr("lost", &cv::detail::tracking::tbm::Track::lost).
    define_attr("first_object", &cv::detail::tracking::tbm::Track::first_object).
    define_attr("length", &cv::detail::tracking::tbm::Track::length);
  
  Class rb_cCvDetailTbmITrackerByMatching = define_class_under<cv::detail::tbm::ITrackerByMatching>(rb_mCvDetailTrackingTbm, "ITrackerByMatching").
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::Mat&, const std::deque<cv::detail::tbm::TrackedObject>&, unsigned long long)>("process", &cv::detail::tracking::tbm::ITrackerByMatching::process).
    define_method<const cv::detail::tbm::TrackerParams&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("params", &cv::detail::tracking::tbm::ITrackerByMatching::params).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::detail::tbm::TrackerParams&)>("set_params", &cv::detail::tracking::tbm::ITrackerByMatching::setParams).
    define_method<const std::shared_ptr<cv::detail::tbm::IImageDescriptor>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("descriptor_fast", &cv::detail::tracking::tbm::ITrackerByMatching::descriptorFast).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const std::shared_ptr<cv::detail::tbm::IImageDescriptor>&)>("set_descriptor_fast", &cv::detail::tracking::tbm::ITrackerByMatching::setDescriptorFast).
    define_method<const std::shared_ptr<cv::detail::tbm::IImageDescriptor>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("descriptor_strong", &cv::detail::tracking::tbm::ITrackerByMatching::descriptorStrong).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const std::shared_ptr<cv::detail::tbm::IImageDescriptor>&)>("set_descriptor_strong", &cv::detail::tracking::tbm::ITrackerByMatching::setDescriptorStrong).
    define_method<const std::shared_ptr<cv::detail::tbm::IDescriptorDistance>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("distance_fast", &cv::detail::tracking::tbm::ITrackerByMatching::distanceFast).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const std::shared_ptr<cv::detail::tbm::IDescriptorDistance>&)>("set_distance_fast", &cv::detail::tracking::tbm::ITrackerByMatching::setDistanceFast).
    define_method<const std::shared_ptr<cv::detail::tbm::IDescriptorDistance>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("distance_strong", &cv::detail::tracking::tbm::ITrackerByMatching::distanceStrong).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(const std::shared_ptr<cv::detail::tbm::IDescriptorDistance>&)>("set_distance_strong", &cv::detail::tracking::tbm::ITrackerByMatching::setDistanceStrong).
    define_method<unsigned long long(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("count", &cv::detail::tracking::tbm::ITrackerByMatching::count).
    define_method<std::unordered_map<unsigned long long, std::vector<cv::Point_<int>>>(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("get_active_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::getActiveTracks).
    define_method<std::deque<cv::detail::tbm::TrackedObject>(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("tracked_detections", &cv::detail::tracking::tbm::ITrackerByMatching::trackedDetections).
    define_method<cv::Mat(cv::detail::tracking::tbm::ITrackerByMatching::*)(const cv::Mat&)>("draw_active_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::drawActiveTracks).
    define_method<bool(cv::detail::tracking::tbm::ITrackerByMatching::*)(unsigned long long) const>("is_track_forgotten", &cv::detail::tracking::tbm::ITrackerByMatching::isTrackForgotten).
    define_method<const std::unordered_map<unsigned long long, cv::detail::tbm::Track>&(cv::detail::tracking::tbm::ITrackerByMatching::*)() const>("tracks", &cv::detail::tracking::tbm::ITrackerByMatching::tracks).
    define_method<bool(cv::detail::tracking::tbm::ITrackerByMatching::*)(unsigned long long) const>("is_track_valid", &cv::detail::tracking::tbm::ITrackerByMatching::isTrackValid).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)()>("drop_forgotten_tracks", &cv::detail::tracking::tbm::ITrackerByMatching::dropForgottenTracks).
    define_method<void(cv::detail::tracking::tbm::ITrackerByMatching::*)(unsigned long long)>("drop_forgotten_track", &cv::detail::tracking::tbm::ITrackerByMatching::dropForgottenTrack);
  
  rb_mCvDetailTrackingTbm.define_module_function<cv::Ptr<cv::detail::tbm::ITrackerByMatching>(*)(const cv::detail::tbm::TrackerParams&)>("create_tracker_by_matching", &cv::detail::tracking::tbm::createTrackerByMatching);
}