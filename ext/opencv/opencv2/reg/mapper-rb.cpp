#include <opencv2/reg/mapper.hpp>
#include "mapper-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mapper()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");
  
  Class rb_cCvRegMapper = define_class_under<cv::reg::Mapper>(rb_mCvReg, "Mapper").
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Mapper::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::Mapper::calculate).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Mapper::*)() const>("get_map", &cv::reg::Mapper::getMap);
}