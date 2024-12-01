#include <opencv2/reg/mapprojec.hpp>
#include "mapprojec-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mapprojec()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapProjec = define_class_under<cv::reg::MapProjec, cv::reg::Map>(rb_mCvReg, "MapProjec").
    define_constructor(Constructor<cv::reg::MapProjec>()).
    define_constructor(Constructor<cv::reg::MapProjec, const cv::_InputArray &>()).
    define_method<void(cv::reg::MapProjec::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("inverse_warp", &cv::reg::MapProjec::inverseWarp).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapProjec::*)() const>("inverse_map", &cv::reg::MapProjec::inverseMap).
    define_method<void(cv::reg::MapProjec::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::MapProjec::compose).
    define_method<void(cv::reg::MapProjec::*)(double)>("scale", &cv::reg::MapProjec::scale).
    define_method<const cv::Matx<double, 3, 3>&(cv::reg::MapProjec::*)() const>("get_proj_tr", &cv::reg::MapProjec::getProjTr).
    define_method<void(cv::reg::MapProjec::*)(const cv::_OutputArray &) const>("get_proj_tr", &cv::reg::MapProjec::getProjTr).
    define_method<void(cv::reg::MapProjec::*)()>("normalize", &cv::reg::MapProjec::normalize);
}