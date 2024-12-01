#include <opencv2/reg/mappergradeuclid.hpp>
#include "mappergradeuclid-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mappergradeuclid()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapperGradEuclid = define_class_under<cv::reg::MapperGradEuclid, cv::reg::Mapper>(rb_mCvReg, "MapperGradEuclid").
    define_constructor(Constructor<cv::reg::MapperGradEuclid>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradEuclid::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradEuclid::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradEuclid::*)() const>("get_map", &cv::reg::MapperGradEuclid::getMap);
}