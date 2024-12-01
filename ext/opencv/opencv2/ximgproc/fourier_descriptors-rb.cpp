#include <opencv2/ximgproc/fourier_descriptors.hpp>
#include "fourier_descriptors-rb.hpp"

using namespace Rice;

extern "C"
void Init_FourierDescriptors()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocContourFitting = define_class_under<cv::ximgproc::ContourFitting, cv::Algorithm>(rb_mCvXimgproc, "ContourFitting").
    define_constructor(Constructor<cv::ximgproc::ContourFitting, int, int>()).
    define_method<void(cv::ximgproc::ContourFitting::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double*, bool)>("estimate_transformation", &cv::ximgproc::ContourFitting::estimateTransformation).
    define_method<void(cv::ximgproc::ContourFitting::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double&, bool)>("estimate_transformation", &cv::ximgproc::ContourFitting::estimateTransformation).
    define_method<void(cv::ximgproc::ContourFitting::*)(int)>("set_ctr_size", &cv::ximgproc::ContourFitting::setCtrSize).
    define_method<void(cv::ximgproc::ContourFitting::*)(int)>("set_fd_size", &cv::ximgproc::ContourFitting::setFDSize).
    define_method<int(cv::ximgproc::ContourFitting::*)()>("get_ctr_size", &cv::ximgproc::ContourFitting::getCtrSize).
    define_method<int(cv::ximgproc::ContourFitting::*)()>("get_fd_size", &cv::ximgproc::ContourFitting::getFDSize);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("fourier_descriptor", &cv::ximgproc::fourierDescriptor);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool)>("transform_fd", &cv::ximgproc::transformFD);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("contour_sampling", &cv::ximgproc::contourSampling);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::ContourFitting>(*)(int, int)>("create_contour_fitting", &cv::ximgproc::createContourFitting);
}