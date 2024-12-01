#include <opencv2/optflow/motempl.hpp>
#include "motempl-rb.hpp"

using namespace Rice;

extern "C"
void Init_Motempl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvMotempl = define_module_under(rb_mCv, "Motempl");
  
  rb_mCvMotempl.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, double, double)>("update_motion_history", &cv::motempl::updateMotionHistory);
  
  rb_mCvMotempl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, double, int)>("calc_motion_gradient", &cv::motempl::calcMotionGradient);
  
  rb_mCvMotempl.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, double)>("calc_global_orientation", &cv::motempl::calcGlobalOrientation);
  
  rb_mCvMotempl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, std::vector<cv::Rect_<int>>&, double, double)>("segment_motion", &cv::motempl::segmentMotion);
}