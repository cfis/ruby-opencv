#include <opencv2/objdetect/charuco_detector.hpp>
#include "charuco_detector-rb.hpp"

using namespace Rice;

extern "C"
void Init_CharucoDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  Class rb_cCvArucoCharucoParameters = define_class_under<cv::aruco::CharucoParameters>(rb_mCvAruco, "CharucoParameters").
    define_constructor(Constructor<cv::aruco::CharucoParameters>()).
    define_attr("camera_matrix", &cv::aruco::CharucoParameters::cameraMatrix).
    define_attr("dist_coeffs", &cv::aruco::CharucoParameters::distCoeffs).
    define_attr("min_markers", &cv::aruco::CharucoParameters::minMarkers).
    define_attr("try_refine_markers", &cv::aruco::CharucoParameters::tryRefineMarkers);
  
  Class rb_cCvArucoCharucoDetector = define_class_under<cv::aruco::CharucoDetector, cv::Algorithm>(rb_mCvAruco, "CharucoDetector").
    define_constructor(Constructor<cv::aruco::CharucoDetector, const cv::aruco::CharucoBoard&, const cv::aruco::CharucoParameters&, const cv::aruco::DetectorParameters&, const cv::aruco::RefineParameters&>()).
    define_method<const cv::aruco::CharucoBoard&(cv::aruco::CharucoDetector::*)() const>("get_board", &cv::aruco::CharucoDetector::getBoard).
    define_method<void(cv::aruco::CharucoDetector::*)(const cv::aruco::CharucoBoard&)>("set_board", &cv::aruco::CharucoDetector::setBoard).
    define_method<const cv::aruco::CharucoParameters&(cv::aruco::CharucoDetector::*)() const>("get_charuco_parameters", &cv::aruco::CharucoDetector::getCharucoParameters).
    define_method<void(cv::aruco::CharucoDetector::*)(cv::aruco::CharucoParameters&)>("set_charuco_parameters", &cv::aruco::CharucoDetector::setCharucoParameters).
    define_method<const cv::aruco::DetectorParameters&(cv::aruco::CharucoDetector::*)() const>("get_detector_parameters", &cv::aruco::CharucoDetector::getDetectorParameters).
    define_method<void(cv::aruco::CharucoDetector::*)(const cv::aruco::DetectorParameters&)>("set_detector_parameters", &cv::aruco::CharucoDetector::setDetectorParameters).
    define_method<const cv::aruco::RefineParameters&(cv::aruco::CharucoDetector::*)() const>("get_refine_parameters", &cv::aruco::CharucoDetector::getRefineParameters).
    define_method<void(cv::aruco::CharucoDetector::*)(const cv::aruco::RefineParameters&)>("set_refine_parameters", &cv::aruco::CharucoDetector::setRefineParameters).
    define_method<void(cv::aruco::CharucoDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &) const>("detect_board", &cv::aruco::CharucoDetector::detectBoard).
    define_method<void(cv::aruco::CharucoDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &) const>("detect_diamonds", &cv::aruco::CharucoDetector::detectDiamonds);
  
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Scalar_<double>)>("draw_detected_corners_charuco", &cv::aruco::drawDetectedCornersCharuco);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Scalar_<double>)>("draw_detected_diamonds", &cv::aruco::drawDetectedDiamonds);
}