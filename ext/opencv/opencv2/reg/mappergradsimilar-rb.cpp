#include <opencv2/reg/mappergradsimilar.hpp>
#include "mappergradsimilar-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mappergradsimilar()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperGradSimilar = define_class_under<cv::reg::MapperGradSimilar, cv::reg::Mapper>(rb_mCvReg, "MapperGradSimilar").
    define_constructor(Constructor<cv::reg::MapperGradSimilar>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradSimilar::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradSimilar::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradSimilar::*)() const>("get_map", &cv::reg::MapperGradSimilar::getMap);
}