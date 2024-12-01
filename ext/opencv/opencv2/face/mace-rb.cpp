#include <opencv2/face/mace.hpp>
#include "mace-rb.hpp"

using namespace Rice;

extern "C"
void Init_Mace()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceMACE = define_class_under<cv::face::MACE, cv::Algorithm>(rb_mCvFace, "MACE").
    define_method<void(cv::face::MACE::*)(const std::basic_string<char>&)>("salt", &cv::face::MACE::salt).
    define_method<void(cv::face::MACE::*)(const cv::_InputArray &)>("train", &cv::face::MACE::train).
    define_method<bool(cv::face::MACE::*)(const cv::_InputArray &) const>("same", &cv::face::MACE::same).
    define_singleton_function<cv::Ptr<cv::face::MACE>(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("load", &cv::face::MACE::load).
    define_singleton_function<cv::Ptr<cv::face::MACE>(*)(int)>("create", &cv::face::MACE::create);
}