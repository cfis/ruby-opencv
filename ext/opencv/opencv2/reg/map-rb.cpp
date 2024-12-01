#include <opencv2/reg/map.hpp>
#include "map-rb.hpp"

using namespace Rice;

extern "C"
void Init_Map()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMap = define_class_under<cv::reg::Map>(rb_mCvReg, "Map").
    define_method<void(cv::reg::Map::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("warp", &cv::reg::Map::warp).
    define_method<void(cv::reg::Map::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("inverse_warp", &cv::reg::Map::inverseWarp).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Map::*)() const>("inverse_map", &cv::reg::Map::inverseMap).
    define_method<void(cv::reg::Map::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::Map::compose).
    define_method<void(cv::reg::Map::*)(double)>("scale", &cv::reg::Map::scale);
}