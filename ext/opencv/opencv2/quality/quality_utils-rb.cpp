#include <opencv2/quality/quality_utils.hpp>
#include "quality_utils-rb.hpp"

using namespace Rice;

extern "C"
void Init_QualityUtils()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Module rb_mCvQualityQualityUtils = define_module_under(rb_mCvQuality, "QualityUtils");
  
  rb_mCvQualityQualityUtils.define_module_function<cv::Mat(*)(const cv::Mat&)>("get_column_range", &cv::quality::quality_utils::get_column_range);
}