#include <opencv2/reg/mappergradaffine.hpp>
#include "mappergradaffine-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mappergradaffine()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperGradAffine = define_class_under<cv::reg::MapperGradAffine, cv::reg::Mapper>(rb_mCvReg, "MapperGradAffine").
    define_constructor(Constructor<cv::reg::MapperGradAffine>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradAffine::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradAffine::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradAffine::*)() const>("get_map", &cv::reg::MapperGradAffine::getMap);
}