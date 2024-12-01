#include <opencv2/rapid.hpp>
#include "rapid-rb.hpp"

using namespace Rice;

extern "C"
void Init_Rapid()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvRapid = define_module_under(rb_mCv, "Rapid");
  
  rb_mCvRapid.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("draw_correspondencies", &cv::rapid::drawCorrespondencies);
  
  rb_mCvRapid.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::Scalar_<double>&)>("draw_search_lines", &cv::rapid::drawSearchLines);
  
  rb_mCvRapid.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Scalar_<double>&, int, bool)>("draw_wireframe", &cv::rapid::drawWireframe);
  
  rb_mCvRapid.define_module_function<void(*)(int, int, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("extract_control_points", &cv::rapid::extractControlPoints);
  
  rb_mCvRapid.define_module_function<void(*)(int, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("extract_line_bundle", &cv::rapid::extractLineBundle);
  
  rb_mCvRapid.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("find_correspondencies", &cv::rapid::findCorrespondencies);
  
  rb_mCvRapid.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputOutputArray &, const cv::_InputArray &)>("convert_correspondencies", &cv::rapid::convertCorrespondencies);
  
  rb_mCvRapid.define_module_function<float(*)(const cv::_InputArray &, int, int, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, double*)>("rapid", &cv::rapid::rapid);
  
  Class rb_cCvRapidTracker = define_class_under<cv::rapid::Tracker, cv::Algorithm>(rb_mCvRapid, "Tracker").
    define_method<float(cv::rapid::Tracker::*)(const cv::_InputArray &, int, int, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::TermCriteria&)>("compute", &cv::rapid::Tracker::compute).
    define_method<void(cv::rapid::Tracker::*)()>("clear_state", &cv::rapid::Tracker::clearState);
  
  Class rb_cCvRapidRapid = define_class_under<cv::rapid::Rapid, cv::rapid::Tracker>(rb_mCvRapid, "Rapid").
    define_singleton_function<cv::Ptr<cv::rapid::Rapid>(*)(const cv::_InputArray &, const cv::_InputArray &)>("create", &cv::rapid::Rapid::create);
  
  Class rb_cCvRapidOLSTracker = define_class_under<cv::rapid::OLSTracker, cv::rapid::Tracker>(rb_mCvRapid, "OLSTracker").
    define_singleton_function<cv::Ptr<cv::rapid::OLSTracker>(*)(const cv::_InputArray &, const cv::_InputArray &, int, unsigned char)>("create", &cv::rapid::OLSTracker::create);
  
  Class rb_cCvRapidGOSTracker = define_class_under<cv::rapid::GOSTracker, cv::rapid::Tracker>(rb_mCvRapid, "GOSTracker").
    define_singleton_function<cv::Ptr<cv::rapid::OLSTracker>(*)(const cv::_InputArray &, const cv::_InputArray &, int, unsigned char)>("create", &cv::rapid::GOSTracker::create);
}