#include <opencv2/reg/mapperpyramid.hpp>
#include "mapperpyramid-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mapperpyramid()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperPyramid = define_class_under<cv::reg::MapperPyramid, cv::reg::Mapper>(rb_mCvReg, "MapperPyramid").
    define_constructor(Constructor<cv::reg::MapperPyramid, cv::Ptr<cv::reg::Mapper>>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperPyramid::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperPyramid::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperPyramid::*)() const>("get_map", &cv::reg::MapperPyramid::getMap).
    define_attr("num_lev_", &cv::reg::MapperPyramid::numLev_).
    define_attr("num_iter_per_scale_", &cv::reg::MapperPyramid::numIterPerScale_);
  
  Class rb_cCvRegMapTypeCaster = define_class_under<cv::reg::MapTypeCaster>(rb_mCvReg, "MapTypeCaster").
    define_singleton_function<cv::Ptr<cv::reg::MapAffine>(*)(cv::Ptr<cv::reg::Map>)>("to_affine", &cv::reg::MapTypeCaster::toAffine).
    define_singleton_function<cv::Ptr<cv::reg::MapShift>(*)(cv::Ptr<cv::reg::Map>)>("to_shift", &cv::reg::MapTypeCaster::toShift).
    define_singleton_function<cv::Ptr<cv::reg::MapProjec>(*)(cv::Ptr<cv::reg::Map>)>("to_projec", &cv::reg::MapTypeCaster::toProjec);
}