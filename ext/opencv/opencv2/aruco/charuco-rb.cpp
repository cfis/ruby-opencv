#include <opencv2/aruco/charuco.hpp>
#include "charuco-rb.hpp"

using namespace Rice;

extern "C"
void Init_Charuco()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  rb_mCvAruco.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Ptr<cv::aruco::CharucoBoard>&, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, int)>("interpolate_corners_charuco", &cv::aruco::interpolateCornersCharuco);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, float, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::aruco::Dictionary>)>("detect_charuco_diamond", &cv::aruco::detectCharucoDiamond);
  
  rb_mCvAruco.define_module_function<void(*)(const cv::Ptr<cv::aruco::Dictionary>&, cv::Vec<int, 4>, int, int, const cv::_OutputArray &, int, int)>("draw_charuco_diamond", &cv::aruco::drawCharucoDiamond);
}