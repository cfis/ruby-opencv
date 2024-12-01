#include <opencv2/cudabgsegm.hpp>
#include "cudabgsegm-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudabgsegm()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaBackgroundSubtractorMOG = define_class_under<cv::cuda::BackgroundSubtractorMOG, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorMOG").
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(const cv::_InputArray &, const cv::_OutputArray &, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorMOG::apply).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(const cv::_OutputArray &, cv::cuda::Stream&) const>("get_background_image", &cv::cuda::BackgroundSubtractorMOG::getBackgroundImage).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(cv::cuda::GpuMat&, cv::cuda::Stream&)>("get_background_image", &cv::cuda::BackgroundSubtractorMOG::getBackgroundImage).
    define_method<int(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_history", &cv::cuda::BackgroundSubtractorMOG::getHistory).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(int)>("set_history", &cv::cuda::BackgroundSubtractorMOG::setHistory).
    define_method<int(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_n_mixtures", &cv::cuda::BackgroundSubtractorMOG::getNMixtures).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(int)>("set_n_mixtures", &cv::cuda::BackgroundSubtractorMOG::setNMixtures).
    define_method<double(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_background_ratio", &cv::cuda::BackgroundSubtractorMOG::getBackgroundRatio).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(double)>("set_background_ratio", &cv::cuda::BackgroundSubtractorMOG::setBackgroundRatio).
    define_method<double(cv::cuda::BackgroundSubtractorMOG::*)() const>("get_noise_sigma", &cv::cuda::BackgroundSubtractorMOG::getNoiseSigma).
    define_method<void(cv::cuda::BackgroundSubtractorMOG::*)(double)>("set_noise_sigma", &cv::cuda::BackgroundSubtractorMOG::setNoiseSigma);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorMOG>(*)(int, int, double, double)>("create_background_subtractor_mog", &cv::cuda::createBackgroundSubtractorMOG);
  
  Class rb_cCvCudaBackgroundSubtractorMOG2 = define_class_under<cv::cuda::BackgroundSubtractorMOG2, cv::BackgroundSubtractorMOG2>(rb_mCvCuda, "BackgroundSubtractorMOG2").
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(const cv::_InputArray &, const cv::_OutputArray &, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorMOG2::apply).
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(const cv::_OutputArray &, cv::cuda::Stream&) const>("get_background_image", &cv::cuda::BackgroundSubtractorMOG2::getBackgroundImage).
    define_method<void(cv::cuda::BackgroundSubtractorMOG2::*)(cv::cuda::GpuMat&, cv::cuda::Stream&)>("get_background_image", &cv::cuda::BackgroundSubtractorMOG2::getBackgroundImage);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorMOG2>(*)(int, double, bool)>("create_background_subtractor_mog2", &cv::cuda::createBackgroundSubtractorMOG2);
}