#include <opencv2/face/facemark.hpp>
#include "facemark-rb.hpp"

using namespace Rice;

extern "C"
void Init_Facemark()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceFacemark = define_class_under<cv::face::Facemark, cv::Algorithm>(rb_mCvFace, "Facemark").
    define_method<void(cv::face::Facemark::*)(std::basic_string<char>)>("load_model", &cv::face::Facemark::loadModel).
    define_method<bool(cv::face::Facemark::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("fit", &cv::face::Facemark::fit);
  
  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_aam", &cv::face::createFacemarkAAM);
  
  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_lbf", &cv::face::createFacemarkLBF);
  
  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_kazemi", &cv::face::createFacemarkKazemi);
}