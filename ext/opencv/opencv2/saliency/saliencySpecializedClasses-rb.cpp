#include <opencv2/saliency/saliencySpecializedClasses.hpp>
#include "saliencySpecializedClasses-rb.hpp"

using namespace Rice;

extern "C"
void Init_SaliencySpecializedClasses()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvSaliency = define_module_under(rb_mCv, "Saliency");
  
  Class rb_cCvSaliencyStaticSaliencySpectralResidual = define_class_under<cv::saliency::StaticSaliencySpectralResidual, cv::saliency::StaticSaliency>(rb_mCvSaliency, "StaticSaliencySpectralResidual").
    define_constructor(Constructor<cv::saliency::StaticSaliencySpectralResidual>()).
    define_singleton_function<cv::Ptr<cv::saliency::StaticSaliencySpectralResidual>(*)()>("create", &cv::saliency::StaticSaliencySpectralResidual::create).
    define_method<bool(cv::saliency::StaticSaliencySpectralResidual::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_saliency", &cv::saliency::StaticSaliencySpectralResidual::computeSaliency).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(const cv::FileNode&)>("read", &cv::saliency::StaticSaliencySpectralResidual::read).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(cv::FileStorage&) const>("write", &cv::saliency::StaticSaliencySpectralResidual::write).
    define_method<int(cv::saliency::StaticSaliencySpectralResidual::*)() const>("get_image_width", &cv::saliency::StaticSaliencySpectralResidual::getImageWidth).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(int)>("set_image_width", &cv::saliency::StaticSaliencySpectralResidual::setImageWidth).
    define_method<int(cv::saliency::StaticSaliencySpectralResidual::*)() const>("get_image_height", &cv::saliency::StaticSaliencySpectralResidual::getImageHeight).
    define_method<void(cv::saliency::StaticSaliencySpectralResidual::*)(int)>("set_image_height", &cv::saliency::StaticSaliencySpectralResidual::setImageHeight);
  
  Class rb_cCvSaliencyStaticSaliencyFineGrained = define_class_under<cv::saliency::StaticSaliencyFineGrained, cv::saliency::StaticSaliency>(rb_mCvSaliency, "StaticSaliencyFineGrained").
    define_constructor(Constructor<cv::saliency::StaticSaliencyFineGrained>()).
    define_singleton_function<cv::Ptr<cv::saliency::StaticSaliencyFineGrained>(*)()>("create", &cv::saliency::StaticSaliencyFineGrained::create).
    define_method<bool(cv::saliency::StaticSaliencyFineGrained::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_saliency", &cv::saliency::StaticSaliencyFineGrained::computeSaliency);
  
  Class rb_cCvSaliencyMotionSaliencyBinWangApr2014 = define_class_under<cv::saliency::MotionSaliencyBinWangApr2014, cv::saliency::MotionSaliency>(rb_mCvSaliency, "MotionSaliencyBinWangApr2014").
    define_constructor(Constructor<cv::saliency::MotionSaliencyBinWangApr2014>()).
    define_singleton_function<cv::Ptr<cv::saliency::MotionSaliencyBinWangApr2014>(*)()>("create", &cv::saliency::MotionSaliencyBinWangApr2014::create).
    define_method<bool(cv::saliency::MotionSaliencyBinWangApr2014::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_saliency", &cv::saliency::MotionSaliencyBinWangApr2014::computeSaliency).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int, int)>("set_imagesize", &cv::saliency::MotionSaliencyBinWangApr2014::setImagesize).
    define_method<bool(cv::saliency::MotionSaliencyBinWangApr2014::*)()>("init", &cv::saliency::MotionSaliencyBinWangApr2014::init).
    define_method<int(cv::saliency::MotionSaliencyBinWangApr2014::*)() const>("get_image_width", &cv::saliency::MotionSaliencyBinWangApr2014::getImageWidth).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int)>("set_image_width", &cv::saliency::MotionSaliencyBinWangApr2014::setImageWidth).
    define_method<int(cv::saliency::MotionSaliencyBinWangApr2014::*)() const>("get_image_height", &cv::saliency::MotionSaliencyBinWangApr2014::getImageHeight).
    define_method<void(cv::saliency::MotionSaliencyBinWangApr2014::*)(int)>("set_image_height", &cv::saliency::MotionSaliencyBinWangApr2014::setImageHeight);
  
  Class rb_cCvSaliencyObjectnessBING = define_class_under<cv::saliency::ObjectnessBING, cv::saliency::Objectness>(rb_mCvSaliency, "ObjectnessBING").
    define_constructor(Constructor<cv::saliency::ObjectnessBING>()).
    define_singleton_function<cv::Ptr<cv::saliency::ObjectnessBING>(*)()>("create", &cv::saliency::ObjectnessBING::create).
    define_method<bool(cv::saliency::ObjectnessBING::*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_saliency", &cv::saliency::ObjectnessBING::computeSaliency).
    define_method<void(cv::saliency::ObjectnessBING::*)()>("read", &cv::saliency::ObjectnessBING::read).
    define_method<void(cv::saliency::ObjectnessBING::*)() const>("write", &cv::saliency::ObjectnessBING::write).
    define_method<std::vector<float>(cv::saliency::ObjectnessBING::*)()>("getobjectness_values", &cv::saliency::ObjectnessBING::getobjectnessValues).
    define_method<void(cv::saliency::ObjectnessBING::*)(const std::basic_string<char>&)>("set_training_path", &cv::saliency::ObjectnessBING::setTrainingPath).
    define_method<void(cv::saliency::ObjectnessBING::*)(const std::basic_string<char>&)>("set_bb_res_dir", &cv::saliency::ObjectnessBING::setBBResDir).
    define_method<double(cv::saliency::ObjectnessBING::*)() const>("get_base", &cv::saliency::ObjectnessBING::getBase).
    define_method<void(cv::saliency::ObjectnessBING::*)(double)>("set_base", &cv::saliency::ObjectnessBING::setBase).
    define_method<int(cv::saliency::ObjectnessBING::*)() const>("get_nss", &cv::saliency::ObjectnessBING::getNSS).
    define_method<void(cv::saliency::ObjectnessBING::*)(int)>("set_nss", &cv::saliency::ObjectnessBING::setNSS).
    define_method<int(cv::saliency::ObjectnessBING::*)() const>("get_w", &cv::saliency::ObjectnessBING::getW).
    define_method<void(cv::saliency::ObjectnessBING::*)(int)>("set_w", &cv::saliency::ObjectnessBING::setW);
  
  Class rb_cCvSaliencyObjectnessBINGFilterTIG = define_class_under<cv::saliency::ObjectnessBING::FilterTIG>(rb_cCvSaliencyObjectnessBING, "FilterTIG").
    define_method<void(cv::saliency::ObjectnessBING::FilterTIG::*)(cv::Mat&)>("update", &cv::saliency::ObjectnessBING::FilterTIG::update).
    define_method<cv::Mat(cv::saliency::ObjectnessBING::FilterTIG::*)(const cv::Mat&)>("match_template", &cv::saliency::ObjectnessBING::FilterTIG::matchTemplate).
    define_method<float(cv::saliency::ObjectnessBING::FilterTIG::*)(long long, long long, long long, long long)>("dot", &cv::saliency::ObjectnessBING::FilterTIG::dot).
    define_method<void(cv::saliency::ObjectnessBING::FilterTIG::*)(cv::Mat&)>("reconstruct", &cv::saliency::ObjectnessBING::FilterTIG::reconstruct);
}