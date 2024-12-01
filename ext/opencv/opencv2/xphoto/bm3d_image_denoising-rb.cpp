#include <opencv2/xphoto/bm3d_image_denoising.hpp>
#include "bm3d_image_denoising-rb.hpp"

using namespace Rice;

extern "C"
void Init_Bm3dImageDenoising()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");
  
  Enum<cv::xphoto::TransformTypes> rb_cCvXphotoTransformTypes = define_enum<cv::xphoto::TransformTypes>("TransformTypes", rb_mCvXphoto).
    define_value("HAAR", cv::xphoto::TransformTypes::HAAR);
  
  Enum<cv::xphoto::Bm3dSteps> rb_cCvXphotoBm3dSteps = define_enum<cv::xphoto::Bm3dSteps>("Bm3dSteps", rb_mCvXphoto).
    define_value("BM3D_STEPALL", cv::xphoto::Bm3dSteps::BM3D_STEPALL).
    define_value("BM3D_STEP1", cv::xphoto::Bm3dSteps::BM3D_STEP1).
    define_value("BM3D_STEP2", cv::xphoto::Bm3dSteps::BM3D_STEP2);
  
  rb_mCvXphoto.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, float, int, int, int, int, int, int, float, int, int, int)>("bm3d_denoising", &cv::xphoto::bm3dDenoising);
  
  rb_mCvXphoto.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, int, int, int, int, int, int, float, int, int, int)>("bm3d_denoising", &cv::xphoto::bm3dDenoising);
}