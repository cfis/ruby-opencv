#include <opencv2/reg/mappergradshift.hpp>
#include "mappergradshift-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mappergradshift()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperGradShift = define_class_under<cv::reg::MapperGradShift, cv::reg::Mapper>(rb_mCvReg, "MapperGradShift").
    define_constructor(Constructor<cv::reg::MapperGradShift>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradShift::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradShift::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradShift::*)() const>("get_map", &cv::reg::MapperGradShift::getMap);
}