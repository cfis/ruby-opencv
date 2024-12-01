#include <opencv2/videostab/fast_marching.hpp>
#include "fast_marching-rb.hpp"

using namespace Rice;

extern "C"
void Init_FastMarching()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabFastMarchingMethod = define_class_under<cv::videostab::FastMarchingMethod>(rb_mCvVideostab, "FastMarchingMethod").
    define_constructor(Constructor<cv::videostab::FastMarchingMethod>()).
    define_method<cv::Mat(cv::videostab::FastMarchingMethod::*)() const>("distance_map", &cv::videostab::FastMarchingMethod::distanceMap);
  
  Class rb_cCvVideostabFastMarchingMethodDXY = define_class_under<cv::videostab::FastMarchingMethod::DXY>(rb_cCvVideostabFastMarchingMethod, "DXY").
    define_attr("dist", &cv::videostab::FastMarchingMethod::DXY::dist).
    define_attr("x", &cv::videostab::FastMarchingMethod::DXY::x).
    define_attr("y", &cv::videostab::FastMarchingMethod::DXY::y).
    define_constructor(Constructor<cv::videostab::FastMarchingMethod::DXY>()).
    define_constructor(Constructor<cv::videostab::FastMarchingMethod::DXY, float, int, int>()).
    define_method<bool(cv::videostab::FastMarchingMethod::DXY::*)(const cv::videostab::FastMarchingMethod::DXY&) const>("operator<", &cv::videostab::FastMarchingMethod::DXY::operator<);
}