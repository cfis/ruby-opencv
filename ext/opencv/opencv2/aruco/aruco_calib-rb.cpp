#include <opencv2/aruco/aruco_calib.hpp>
#include "aruco_calib-rb.hpp"

using namespace Rice;

extern "C"
void Init_ArucoCalib()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  Enum<cv::aruco::PatternPositionType> rb_cCvArucoPatternPositionType = define_enum<cv::aruco::PatternPositionType>("PatternPositionType", rb_mCvAruco).
    define_value("ARUCO_CCW_CENTER", cv::aruco::PatternPositionType::ARUCO_CCW_CENTER).
    define_value("ARUCO_CW_TOP_LEFT_CORNER", cv::aruco::PatternPositionType::ARUCO_CW_TOP_LEFT_CORNER);
  
  Class rb_cCvArucoEstimateParameters = define_class_under<cv::aruco::EstimateParameters>(rb_mCvAruco, "EstimateParameters").
    define_attr("pattern", &cv::aruco::EstimateParameters::pattern).
    define_attr("use_extrinsic_guess", &cv::aruco::EstimateParameters::useExtrinsicGuess).
    define_attr("solve_pn_p_method", &cv::aruco::EstimateParameters::solvePnPMethod).
    define_constructor(Constructor<cv::aruco::EstimateParameters>());
  
  rb_mCvAruco.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::Board>&, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::TermCriteria&)>("calibrate_camera_aruco", &cv::aruco::calibrateCameraAruco);
  
  rb_mCvAruco.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::Board>&, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::TermCriteria&)>("calibrate_camera_aruco", &cv::aruco::calibrateCameraAruco);
  
  rb_mCvAruco.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::CharucoBoard>&, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::TermCriteria&)>("calibrate_camera_charuco", &cv::aruco::calibrateCameraCharuco);
  
  rb_mCvAruco.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::CharucoBoard>&, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::TermCriteria&)>("calibrate_camera_charuco", &cv::aruco::calibrateCameraCharuco);
}