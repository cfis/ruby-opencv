#include <opencv2/objdetect/detection_based_tracker.hpp>
#include "detection_based_tracker-rb.hpp"

using namespace Rice;



void Init_DetectionBasedTracker()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvDetectionBasedTracker = define_class_under<cv::DetectionBasedTracker>(rb_mCv, "DetectionBasedTracker").
    define_constructor(Constructor<cv::DetectionBasedTracker, cv::Ptr<cv::DetectionBasedTracker::IDetector>, cv::Ptr<cv::DetectionBasedTracker::IDetector>, const cv::DetectionBasedTracker::Parameters&>(),
      Arg("main_detector"), Arg("tracking_detector"), Arg("params")).
    define_method("run?", &cv::DetectionBasedTracker::run).
    define_method("stop", &cv::DetectionBasedTracker::stop).
    define_method("reset_tracking", &cv::DetectionBasedTracker::resetTracking).
    define_method("process", &cv::DetectionBasedTracker::process,
      Arg("image_gray")).
    define_method("set_parameters?", &cv::DetectionBasedTracker::setParameters,
      Arg("params")).
    define_method("get_parameters", &cv::DetectionBasedTracker::getParameters).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::Rect_<int>>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<std::pair<cv::Rect_<int>, int>>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method<void(cv::DetectionBasedTracker::*)(std::vector<cv::DetectionBasedTracker::ExtObject>&) const>("get_objects", &cv::DetectionBasedTracker::getObjects,
      Arg("result")).
    define_method("add_object", &cv::DetectionBasedTracker::addObject,
      Arg("location"));
  
  Class rb_cCvDetectionBasedTrackerIDetector = define_class_under<cv::DetectionBasedTracker::IDetector>(rb_cCvDetectionBasedTracker, "IDetector").
    define_method("detect", &cv::DetectionBasedTracker::IDetector::detect,
      Arg("image"), Arg("objects")).
    define_method("set_min_object_size", &cv::DetectionBasedTracker::IDetector::setMinObjectSize,
      Arg("min")).
    define_method("set_max_object_size", &cv::DetectionBasedTracker::IDetector::setMaxObjectSize,
      Arg("max")).
    define_method("get_min_object_size", &cv::DetectionBasedTracker::IDetector::getMinObjectSize).
    define_method("get_max_object_size", &cv::DetectionBasedTracker::IDetector::getMaxObjectSize).
    define_method("get_scale_factor", &cv::DetectionBasedTracker::IDetector::getScaleFactor).
    define_method("set_scale_factor", &cv::DetectionBasedTracker::IDetector::setScaleFactor,
      Arg("value")).
    define_method("get_min_neighbours", &cv::DetectionBasedTracker::IDetector::getMinNeighbours).
    define_method("set_min_neighbours", &cv::DetectionBasedTracker::IDetector::setMinNeighbours,
      Arg("value"));
  
  
  Class rb_cCvDetectionBasedTrackerParameters = define_class_under<cv::DetectionBasedTracker::Parameters>(rb_cCvDetectionBasedTracker, "Parameters").
    define_attr("max_track_lifetime", &cv::DetectionBasedTracker::Parameters::maxTrackLifetime).
    define_attr("min_detection_period", &cv::DetectionBasedTracker::Parameters::minDetectionPeriod).
    define_constructor(Constructor<cv::DetectionBasedTracker::Parameters>());
  
  Class rb_cCvDetectionBasedTrackerExtObject = define_class_under<cv::DetectionBasedTracker::ExtObject>(rb_cCvDetectionBasedTracker, "ExtObject").
    define_attr("id", &cv::DetectionBasedTracker::ExtObject::id).
    define_attr("location", &cv::DetectionBasedTracker::ExtObject::location).
    define_attr("status", &cv::DetectionBasedTracker::ExtObject::status).
    define_constructor(Constructor<cv::DetectionBasedTracker::ExtObject, int, cv::Rect, cv::DetectionBasedTracker::ObjectStatus>(),
      Arg("_id"), Arg("_location"), Arg("_status"));
  
  Class rb_cCvDetectionBasedTrackerInnerParameters = define_class_under<cv::DetectionBasedTracker::InnerParameters>(rb_cCvDetectionBasedTracker, "InnerParameters").
    define_attr("num_last_positions_to_track", &cv::DetectionBasedTracker::InnerParameters::numLastPositionsToTrack).
    define_attr("num_steps_to_wait_before_first_show", &cv::DetectionBasedTracker::InnerParameters::numStepsToWaitBeforeFirstShow).
    define_attr("num_steps_to_track_without_detecting_if_object_has_not_been_shown", &cv::DetectionBasedTracker::InnerParameters::numStepsToTrackWithoutDetectingIfObjectHasNotBeenShown).
    define_attr("num_steps_to_show_without_detecting", &cv::DetectionBasedTracker::InnerParameters::numStepsToShowWithoutDetecting).
    define_attr("coeff_tracking_window_size", &cv::DetectionBasedTracker::InnerParameters::coeffTrackingWindowSize).
    define_attr("coeff_object_size_to_track", &cv::DetectionBasedTracker::InnerParameters::coeffObjectSizeToTrack).
    define_attr("coeff_object_speed_using_in_prediction", &cv::DetectionBasedTracker::InnerParameters::coeffObjectSpeedUsingInPrediction).
    define_constructor(Constructor<cv::DetectionBasedTracker::InnerParameters>());
  
  Class rb_cCvDetectionBasedTrackerTrackedObject = define_class_under<cv::DetectionBasedTracker::TrackedObject>(rb_cCvDetectionBasedTracker, "TrackedObject").
    define_attr("last_positions", &cv::DetectionBasedTracker::TrackedObject::lastPositions).
    define_attr("num_detected_frames", &cv::DetectionBasedTracker::TrackedObject::numDetectedFrames).
    define_attr("num_frames_not_detected", &cv::DetectionBasedTracker::TrackedObject::numFramesNotDetected).
    define_attr("id", &cv::DetectionBasedTracker::TrackedObject::id).
    define_constructor(Constructor<cv::DetectionBasedTracker::TrackedObject, const cv::Rect&>(),
      Arg("rect")).
    define_singleton_function("get_next_id", &cv::DetectionBasedTracker::TrackedObject::getNextId);
  
  Enum<cv::DetectionBasedTracker::ObjectStatus> rb_cCvDetectionBasedTrackerObjectStatus = define_enum_under<cv::DetectionBasedTracker::ObjectStatus>("ObjectStatus", rb_cCvDetectionBasedTracker).
    define_value("DETECTED_NOT_SHOWN_YET", cv::DetectionBasedTracker::ObjectStatus::DETECTED_NOT_SHOWN_YET).
    define_value("DETECTED", cv::DetectionBasedTracker::ObjectStatus::DETECTED).
    define_value("DETECTED_TEMPORARY_LOST", cv::DetectionBasedTracker::ObjectStatus::DETECTED_TEMPORARY_LOST).
    define_value("WRONG_OBJECT", cv::DetectionBasedTracker::ObjectStatus::WRONG_OBJECT);

}