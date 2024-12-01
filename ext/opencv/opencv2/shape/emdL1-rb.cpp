#include <opencv2/shape/emdL1.hpp>
#include "emdL1-rb.hpp"

using namespace Rice;

extern "C"
void Init_EmdL1()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &)>("emdl1", &cv::EMDL1);
}