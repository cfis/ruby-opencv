#include <opencv2/ximgproc/structured_edge_detection.hpp>
#include "structured_edge_detection-rb.hpp"

using namespace Rice;

extern "C"
void Init_StructuredEdgeDetection()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocRFFeatureGetter = define_class_under<cv::ximgproc::RFFeatureGetter, cv::Algorithm>(rb_mCvXimgproc, "RFFeatureGetter").
    define_method<void(cv::ximgproc::RFFeatureGetter::*)(const cv::Mat&, cv::Mat&, const int, const int, const int, const int, const int) const>("get_features", &cv::ximgproc::RFFeatureGetter::getFeatures);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::RFFeatureGetter>(*)()>("create_rf_feature_getter", &cv::ximgproc::createRFFeatureGetter);
  
  Class rb_cCvXimgprocStructuredEdgeDetection = define_class_under<cv::ximgproc::StructuredEdgeDetection, cv::Algorithm>(rb_mCvXimgproc, "StructuredEdgeDetection").
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("detect_edges", &cv::ximgproc::StructuredEdgeDetection::detectEdges).
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("compute_orientation", &cv::ximgproc::StructuredEdgeDetection::computeOrientation).
    define_method<void(cv::ximgproc::StructuredEdgeDetection::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int, float, bool) const>("edges_nms", &cv::ximgproc::StructuredEdgeDetection::edgesNms);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::StructuredEdgeDetection>(*)(const std::basic_string<char>&, cv::Ptr<const cv::ximgproc::RFFeatureGetter>)>("create_structured_edge_detection", &cv::ximgproc::createStructuredEdgeDetection);
}