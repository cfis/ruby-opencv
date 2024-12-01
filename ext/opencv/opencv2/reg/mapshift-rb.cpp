#include <opencv2/reg/mapshift.hpp>
#include "mapshift-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mapshift()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapShift = define_class_under<cv::reg::MapShift, cv::reg::Map>(rb_mCvReg, "MapShift").
    define_constructor(Constructor<cv::reg::MapShift>()).
    define_constructor(Constructor<cv::reg::MapShift, const cv::_InputArray &>()).
    define_method<void(cv::reg::MapShift::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("inverse_warp", &cv::reg::MapShift::inverseWarp).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapShift::*)() const>("inverse_map", &cv::reg::MapShift::inverseMap).
    define_method<void(cv::reg::MapShift::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::MapShift::compose).
    define_method<void(cv::reg::MapShift::*)(double)>("scale", &cv::reg::MapShift::scale).
    define_method<const cv::Vec<double, 2>&(cv::reg::MapShift::*)() const>("get_shift", &cv::reg::MapShift::getShift).
    define_method<void(cv::reg::MapShift::*)(const cv::_OutputArray &) const>("get_shift", &cv::reg::MapShift::getShift);
}