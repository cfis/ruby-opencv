#include <opencv2/dpm.hpp>
#include "dpm-rb.hpp"

using namespace Rice;

extern "C"
void Init_Dpm()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDpm = define_module_under(rb_mCv, "Dpm");
  
  Class rb_cCvDpmDPMDetector = define_class_under<cv::dpm::DPMDetector>(rb_mCvDpm, "DPMDetector").
    define_method<bool(cv::dpm::DPMDetector::*)() const>("is_empty", &cv::dpm::DPMDetector::isEmpty).
    define_method<void(cv::dpm::DPMDetector::*)(cv::Mat&, std::vector<cv::dpm::DPMDetector::ObjectDetection>&)>("detect", &cv::dpm::DPMDetector::detect).
    define_method<const std::vector<std::basic_string<char>>&(cv::dpm::DPMDetector::*)() const>("get_class_names", &cv::dpm::DPMDetector::getClassNames).
    define_method<unsigned long long(cv::dpm::DPMDetector::*)() const>("get_class_count", &cv::dpm::DPMDetector::getClassCount).
    define_singleton_function<cv::Ptr<cv::dpm::DPMDetector>(*)(const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&)>("create", &cv::dpm::DPMDetector::create);
  
  Class rb_cCvDpmDPMDetectorObjectDetection = define_class_under<cv::dpm::DPMDetector::ObjectDetection>(rb_cCvDpmDPMDetector, "ObjectDetection").
    define_constructor(Constructor<cv::dpm::DPMDetector::ObjectDetection>()).
    define_constructor(Constructor<cv::dpm::DPMDetector::ObjectDetection, const cv::Rect_<int>&, float, int>()).
    define_attr("rect", &cv::dpm::DPMDetector::ObjectDetection::rect).
    define_attr("score", &cv::dpm::DPMDetector::ObjectDetection::score).
    define_attr("class_id", &cv::dpm::DPMDetector::ObjectDetection::classID);
}