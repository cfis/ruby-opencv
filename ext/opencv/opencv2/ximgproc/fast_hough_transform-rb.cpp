#include <opencv2/ximgproc/fast_hough_transform.hpp>
#include "fast_hough_transform-rb.hpp"

using namespace Rice;

extern "C"
void Init_FastHoughTransform()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Enum<cv::ximgproc::AngleRangeOption> rb_cCvXimgprocAngleRangeOption = define_enum<cv::ximgproc::AngleRangeOption>("AngleRangeOption", rb_mCvXimgproc).
    define_value("ARO_0_45", cv::ximgproc::AngleRangeOption::ARO_0_45).
    define_value("ARO_45_90", cv::ximgproc::AngleRangeOption::ARO_45_90).
    define_value("ARO_90_135", cv::ximgproc::AngleRangeOption::ARO_90_135).
    define_value("ARO_315_0", cv::ximgproc::AngleRangeOption::ARO_315_0).
    define_value("ARO_315_45", cv::ximgproc::AngleRangeOption::ARO_315_45).
    define_value("ARO_45_135", cv::ximgproc::AngleRangeOption::ARO_45_135).
    define_value("ARO_315_135", cv::ximgproc::AngleRangeOption::ARO_315_135).
    define_value("ARO_CTR_HOR", cv::ximgproc::AngleRangeOption::ARO_CTR_HOR).
    define_value("ARO_CTR_VER", cv::ximgproc::AngleRangeOption::ARO_CTR_VER);
  
  Enum<cv::ximgproc::HoughOp> rb_cCvXimgprocHoughOp = define_enum<cv::ximgproc::HoughOp>("HoughOp", rb_mCvXimgproc).
    define_value("FHT_MIN", cv::ximgproc::HoughOp::FHT_MIN).
    define_value("FHT_MAX", cv::ximgproc::HoughOp::FHT_MAX).
    define_value("FHT_ADD", cv::ximgproc::HoughOp::FHT_ADD).
    define_value("FHT_AVE", cv::ximgproc::HoughOp::FHT_AVE);
  
  Enum<cv::ximgproc::HoughDeskewOption> rb_cCvXimgprocHoughDeskewOption = define_enum<cv::ximgproc::HoughDeskewOption>("HoughDeskewOption", rb_mCvXimgproc).
    define_value("HDO_RAW", cv::ximgproc::HoughDeskewOption::HDO_RAW).
    define_value("HDO_DESKEW", cv::ximgproc::HoughDeskewOption::HDO_DESKEW);
  
  Enum<cv::ximgproc::RulesOption> rb_cCvXimgprocRulesOption = define_enum<cv::ximgproc::RulesOption>("RulesOption", rb_mCvXimgproc).
    define_value("RO_STRICT", cv::ximgproc::RulesOption::RO_STRICT).
    define_value("RO_IGNORE_BORDERS", cv::ximgproc::RulesOption::RO_IGNORE_BORDERS);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, int)>("fast_hough_transform", &cv::ximgproc::FastHoughTransform);
  
  rb_mCvXimgproc.define_module_function<cv::Vec<int, 4>(*)(const cv::Point_<int>&, const cv::_InputArray &, int, int, int)>("hough_point2_line", &cv::ximgproc::HoughPoint2Line);
}