#include <opencv2/reg/mappergradproj.hpp>
#include "mappergradproj-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mappergradproj()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperGradProj = define_class_under<cv::reg::MapperGradProj, cv::reg::Mapper>(rb_mCvReg, "MapperGradProj").
    define_constructor(Constructor<cv::reg::MapperGradProj>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradProj::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradProj::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradProj::*)() const>("get_map", &cv::reg::MapperGradProj::getMap);
}