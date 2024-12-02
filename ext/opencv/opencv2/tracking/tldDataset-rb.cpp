#include <opencv2/tracking/tldDataset.hpp>
#include "tldDataset-rb.hpp"

using namespace Rice;

extern "C"
void Init_TldDataset()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Module rb_mCvDetailTrackingTld = define_module_under(rb_mCvDetailTracking, "Tld");
  
  rb_mCvDetailTrackingTld.define_module_function<cv::Rect_<double>(*)(int, const char*, int)>("tld_init_dataset", &cv::detail::tracking::tld::tld_InitDataset);
  
  rb_mCvDetailTrackingTld.define_module_function<std::basic_string<char>(*)()>("tld_get_next_dataset_frame", &cv::detail::tracking::tld::tld_getNextDatasetFrame);
}