#include <opencv2/objdetect/aruco_detector.hpp>
#include "aruco_detector-rb.hpp"

using namespace Rice;

extern "C"
void Init_ArucoDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  Enum<cv::aruco::CornerRefineMethod> rb_cCvArucoCornerRefineMethod = define_enum<cv::aruco::CornerRefineMethod>("CornerRefineMethod", rb_mCvAruco).
    define_value("CORNER_REFINE_NONE", cv::aruco::CornerRefineMethod::CORNER_REFINE_NONE).
    define_value("CORNER_REFINE_SUBPIX", cv::aruco::CornerRefineMethod::CORNER_REFINE_SUBPIX).
    define_value("CORNER_REFINE_CONTOUR", cv::aruco::CornerRefineMethod::CORNER_REFINE_CONTOUR).
    define_value("CORNER_REFINE_APRILTAG", cv::aruco::CornerRefineMethod::CORNER_REFINE_APRILTAG);
  
  Class rb_cCvArucoDetectorParameters = define_class_under<cv::aruco::DetectorParameters>(rb_mCvAruco, "DetectorParameters").
    define_constructor(Constructor<cv::aruco::DetectorParameters>()).
    define_method<bool(cv::aruco::DetectorParameters::*)(const cv::FileNode&)>("read_detector_parameters", &cv::aruco::DetectorParameters::readDetectorParameters).
    define_method<bool(cv::aruco::DetectorParameters::*)(cv::FileStorage&, const std::basic_string<char>&)>("write_detector_parameters", &cv::aruco::DetectorParameters::writeDetectorParameters).
    define_attr("adaptive_thresh_win_size_min", &cv::aruco::DetectorParameters::adaptiveThreshWinSizeMin).
    define_attr("adaptive_thresh_win_size_max", &cv::aruco::DetectorParameters::adaptiveThreshWinSizeMax).
    define_attr("adaptive_thresh_win_size_step", &cv::aruco::DetectorParameters::adaptiveThreshWinSizeStep).
    define_attr("adaptive_thresh_constant", &cv::aruco::DetectorParameters::adaptiveThreshConstant).
    define_attr("min_marker_perimeter_rate", &cv::aruco::DetectorParameters::minMarkerPerimeterRate).
    define_attr("max_marker_perimeter_rate", &cv::aruco::DetectorParameters::maxMarkerPerimeterRate).
    define_attr("polygonal_approx_accuracy_rate", &cv::aruco::DetectorParameters::polygonalApproxAccuracyRate).
    define_attr("min_corner_distance_rate", &cv::aruco::DetectorParameters::minCornerDistanceRate).
    define_attr("min_distance_to_border", &cv::aruco::DetectorParameters::minDistanceToBorder).
    define_attr("min_marker_distance_rate", &cv::aruco::DetectorParameters::minMarkerDistanceRate).
    define_attr("corner_refinement_method", &cv::aruco::DetectorParameters::cornerRefinementMethod).
    define_attr("corner_refinement_win_size", &cv::aruco::DetectorParameters::cornerRefinementWinSize).
    define_attr("corner_refinement_max_iterations", &cv::aruco::DetectorParameters::cornerRefinementMaxIterations).
    define_attr("corner_refinement_min_accuracy", &cv::aruco::DetectorParameters::cornerRefinementMinAccuracy).
    define_attr("marker_border_bits", &cv::aruco::DetectorParameters::markerBorderBits).
    define_attr("perspective_remove_pixel_per_cell", &cv::aruco::DetectorParameters::perspectiveRemovePixelPerCell).
    define_attr("perspective_remove_ignored_margin_per_cell", &cv::aruco::DetectorParameters::perspectiveRemoveIgnoredMarginPerCell).
    define_attr("max_erroneous_bits_in_border_rate", &cv::aruco::DetectorParameters::maxErroneousBitsInBorderRate).
    define_attr("min_otsu_std_dev", &cv::aruco::DetectorParameters::minOtsuStdDev).
    define_attr("error_correction_rate", &cv::aruco::DetectorParameters::errorCorrectionRate).
    define_attr("april_tag_quad_decimate", &cv::aruco::DetectorParameters::aprilTagQuadDecimate).
    define_attr("april_tag_quad_sigma", &cv::aruco::DetectorParameters::aprilTagQuadSigma).
    define_attr("april_tag_min_cluster_pixels", &cv::aruco::DetectorParameters::aprilTagMinClusterPixels).
    define_attr("april_tag_max_nmaxima", &cv::aruco::DetectorParameters::aprilTagMaxNmaxima).
    define_attr("april_tag_critical_rad", &cv::aruco::DetectorParameters::aprilTagCriticalRad).
    define_attr("april_tag_max_line_fit_mse", &cv::aruco::DetectorParameters::aprilTagMaxLineFitMse).
    define_attr("april_tag_min_white_black_diff", &cv::aruco::DetectorParameters::aprilTagMinWhiteBlackDiff).
    define_attr("april_tag_deglitch", &cv::aruco::DetectorParameters::aprilTagDeglitch).
    define_attr("detect_inverted_marker", &cv::aruco::DetectorParameters::detectInvertedMarker).
    define_attr("use_aruco3_detection", &cv::aruco::DetectorParameters::useAruco3Detection).
    define_attr("min_side_length_canonical_img", &cv::aruco::DetectorParameters::minSideLengthCanonicalImg).
    define_attr("min_marker_length_ratio_original_img", &cv::aruco::DetectorParameters::minMarkerLengthRatioOriginalImg);
  
  Class rb_cCvArucoRefineParameters = define_class_under<cv::aruco::RefineParameters>(rb_mCvAruco, "RefineParameters").
    define_constructor(Constructor<cv::aruco::RefineParameters, float, float, bool>()).
    define_method<bool(cv::aruco::RefineParameters::*)(const cv::FileNode&)>("read_refine_parameters", &cv::aruco::RefineParameters::readRefineParameters).
    define_method<bool(cv::aruco::RefineParameters::*)(cv::FileStorage&, const std::basic_string<char>&)>("write_refine_parameters", &cv::aruco::RefineParameters::writeRefineParameters).
    define_attr("min_rep_distance", &cv::aruco::RefineParameters::minRepDistance).
    define_attr("error_correction_rate", &cv::aruco::RefineParameters::errorCorrectionRate).
    define_attr("check_all_orders", &cv::aruco::RefineParameters::checkAllOrders);
  
  Class rb_cCvArucoArucoDetector = define_class_under<cv::aruco::ArucoDetector, cv::Algorithm>(rb_mCvAruco, "ArucoDetector").
    define_constructor(Constructor<cv::aruco::ArucoDetector, const cv::aruco::Dictionary&, const cv::aruco::DetectorParameters&, const cv::aruco::RefineParameters&>()).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &) const>("detect_markers", &cv::aruco::ArucoDetector::detectMarkers).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::_InputArray &, const cv::aruco::Board&, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &) const>("refine_detected_markers", &cv::aruco::ArucoDetector::refineDetectedMarkers).
    define_method<const cv::aruco::Dictionary&(cv::aruco::ArucoDetector::*)() const>("get_dictionary", &cv::aruco::ArucoDetector::getDictionary).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::aruco::Dictionary&)>("set_dictionary", &cv::aruco::ArucoDetector::setDictionary).
    define_method<const cv::aruco::DetectorParameters&(cv::aruco::ArucoDetector::*)() const>("get_detector_parameters", &cv::aruco::ArucoDetector::getDetectorParameters).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::aruco::DetectorParameters&)>("set_detector_parameters", &cv::aruco::ArucoDetector::setDetectorParameters).
    define_method<const cv::aruco::RefineParameters&(cv::aruco::ArucoDetector::*)() const>("get_refine_parameters", &cv::aruco::ArucoDetector::getRefineParameters).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::aruco::RefineParameters&)>("set_refine_parameters", &cv::aruco::ArucoDetector::setRefineParameters).
    define_method<void(cv::aruco::ArucoDetector::*)(cv::FileStorage&) const>("write", &cv::aruco::ArucoDetector::write).
    define_method<void(cv::aruco::ArucoDetector::*)(cv::FileStorage&, const std::basic_string<char>&)>("write", &cv::aruco::ArucoDetector::write).
    define_method<void(cv::aruco::ArucoDetector::*)(const cv::FileNode&)>("read", &cv::aruco::ArucoDetector::read);
  
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Scalar_<double>)>("draw_detected_markers", &cv::aruco::drawDetectedMarkers);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::aruco::Dictionary&, int, int, const cv::_OutputArray &, int)>("generate_image_marker", &cv::aruco::generateImageMarker);
}