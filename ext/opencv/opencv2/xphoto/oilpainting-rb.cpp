#include <opencv2/xphoto/oilpainting.hpp>
#include "oilpainting-rb.hpp"

using namespace Rice;

extern "C"
void Init_Oilpainting()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");
  
  rb_mCvXphoto.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("oil_painting", &cv::xphoto::oilPainting);
  
  rb_mCvXphoto.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("oil_painting", &cv::xphoto::oilPainting);
}