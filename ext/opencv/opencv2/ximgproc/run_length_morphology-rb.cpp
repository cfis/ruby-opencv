#include <opencv2/ximgproc/run_length_morphology.hpp>
#include "run_length_morphology-rb.hpp"

using namespace Rice;

extern "C"
void Init_RunLengthMorphology()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Module rb_mCvXimgprocRl = define_module_under(rb_mCvXimgproc, "Rl");
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, int)>("threshold", &cv::ximgproc::rl::threshold);
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Point_<int>)>("dilate", &cv::ximgproc::rl::dilate);
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, bool, cv::Point_<int>)>("erode", &cv::ximgproc::rl::erode);
  
  rb_mCvXimgprocRl.define_module_function<cv::Mat(*)(int, cv::Size_<int>)>("get_structuring_element", &cv::ximgproc::rl::getStructuringElement);
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::Scalar_<double>&)>("paint", &cv::ximgproc::rl::paint);
  
  rb_mCvXimgprocRl.define_module_function<bool(*)(const cv::_InputArray &)>("is_rl_morphology_possible", &cv::ximgproc::rl::isRLMorphologyPossible);
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const std::vector<cv::Point3_<int>>&, const cv::_OutputArray &, cv::Size_<int>)>("create_rle_image", &cv::ximgproc::rl::createRLEImage);
  
  rb_mCvXimgprocRl.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, bool, cv::Point_<int>)>("morphology_ex", &cv::ximgproc::rl::morphologyEx);
}