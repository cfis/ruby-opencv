#include <opencv2/face/bif.hpp>
#include "bif-rb.hpp"

using namespace Rice;

extern "C"
void Init_Bif()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceBIF = define_class_under<cv::face::BIF, cv::Algorithm>(rb_mCvFace, "BIF").
    define_method<int(cv::face::BIF::*)() const>("get_num_bands", &cv::face::BIF::getNumBands).
    define_method<int(cv::face::BIF::*)() const>("get_num_rotations", &cv::face::BIF::getNumRotations).
    define_method<void(cv::face::BIF::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("compute", &cv::face::BIF::compute).
    define_singleton_function<cv::Ptr<cv::face::BIF>(*)(int, int)>("create", &cv::face::BIF::create);
}