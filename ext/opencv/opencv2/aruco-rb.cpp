#include <opencv2/aruco.hpp>
#include "aruco-rb.hpp"

using namespace Rice;

extern "C"
void Init_Aruco()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputArray &, const cv::Ptr<cv::aruco::Dictionary>&, const cv::_OutputArray &, const cv::_OutputArray &, const cv::Ptr<cv::aruco::DetectorParameters>&, const cv::_OutputArray &)>("detect_markers", &cv::aruco::detectMarkers);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputArray &, const cv::Ptr<cv::aruco::Board>&, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, float, float, bool, const cv::_OutputArray &, const cv::Ptr<cv::aruco::DetectorParameters>&)>("refine_detected_markers", &cv::aruco::refineDetectedMarkers);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::Ptr<cv::aruco::Board>&, cv::Size_<int>, const cv::_OutputArray &, int, int)>("draw_planar_board", &cv::aruco::drawPlanarBoard);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::Ptr<cv::aruco::Board>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("get_board_object_and_image_points", &cv::aruco::getBoardObjectAndImagePoints);
  
  rb_mCvAruco.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::Board>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool)>("estimate_pose_board", &cv::aruco::estimatePoseBoard);
  
  rb_mCvAruco.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::CharucoBoard>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, bool)>("estimate_pose_charuco_board", &cv::aruco::estimatePoseCharucoBoard);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputArray &, float, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::Ptr<cv::aruco::EstimateParameters>&)>("estimate_pose_single_markers", &cv::aruco::estimatePoseSingleMarkers);
  
  rb_mCvAruco.define_module_function<bool(*)(const cv::Ptr<cv::aruco::CharucoBoard>&, const cv::_InputArray &)>("test_charuco_corners_collinear", &cv::aruco::testCharucoCornersCollinear);
}