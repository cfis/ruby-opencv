#include <opencv2/cudaobjdetect.hpp>
#include "cudaobjdetect-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudaobjdetect()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaHOG = define_class_under<cv::cuda::HOG, cv::Algorithm>(rb_mCvCuda, "HOG").
    define_singleton_function<cv::Ptr<cv::cuda::HOG>(*)(cv::Size_<int>, cv::Size_<int>, cv::Size_<int>, cv::Size_<int>, int)>("create", &cv::cuda::HOG::create).
    define_method<void(cv::cuda::HOG::*)(double)>("set_win_sigma", &cv::cuda::HOG::setWinSigma).
    define_method<double(cv::cuda::HOG::*)() const>("get_win_sigma", &cv::cuda::HOG::getWinSigma).
    define_method<void(cv::cuda::HOG::*)(double)>("set_l2_hys_threshold", &cv::cuda::HOG::setL2HysThreshold).
    define_method<double(cv::cuda::HOG::*)() const>("get_l2_hys_threshold", &cv::cuda::HOG::getL2HysThreshold).
    define_method<void(cv::cuda::HOG::*)(bool)>("set_gamma_correction", &cv::cuda::HOG::setGammaCorrection).
    define_method<bool(cv::cuda::HOG::*)() const>("get_gamma_correction", &cv::cuda::HOG::getGammaCorrection).
    define_method<void(cv::cuda::HOG::*)(int)>("set_num_levels", &cv::cuda::HOG::setNumLevels).
    define_method<int(cv::cuda::HOG::*)() const>("get_num_levels", &cv::cuda::HOG::getNumLevels).
    define_method<void(cv::cuda::HOG::*)(double)>("set_hit_threshold", &cv::cuda::HOG::setHitThreshold).
    define_method<double(cv::cuda::HOG::*)() const>("get_hit_threshold", &cv::cuda::HOG::getHitThreshold).
    define_method<void(cv::cuda::HOG::*)(cv::Size_<int>)>("set_win_stride", &cv::cuda::HOG::setWinStride).
    define_method<cv::Size_<int>(cv::cuda::HOG::*)() const>("get_win_stride", &cv::cuda::HOG::getWinStride).
    define_method<void(cv::cuda::HOG::*)(double)>("set_scale_factor", &cv::cuda::HOG::setScaleFactor).
    define_method<double(cv::cuda::HOG::*)() const>("get_scale_factor", &cv::cuda::HOG::getScaleFactor).
    define_method<void(cv::cuda::HOG::*)(int)>("set_group_threshold", &cv::cuda::HOG::setGroupThreshold).
    define_method<int(cv::cuda::HOG::*)() const>("get_group_threshold", &cv::cuda::HOG::getGroupThreshold).
    define_method<void(cv::cuda::HOG::*)(cv::HOGDescriptor::DescriptorStorageFormat)>("set_descriptor_format", &cv::cuda::HOG::setDescriptorFormat).
    define_method<cv::HOGDescriptor::DescriptorStorageFormat(cv::cuda::HOG::*)() const>("get_descriptor_format", &cv::cuda::HOG::getDescriptorFormat).
    define_method<unsigned long long(cv::cuda::HOG::*)() const>("get_descriptor_size", &cv::cuda::HOG::getDescriptorSize).
    define_method<unsigned long long(cv::cuda::HOG::*)() const>("get_block_histogram_size", &cv::cuda::HOG::getBlockHistogramSize).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &)>("set_svm_detector", &cv::cuda::HOG::setSVMDetector).
    define_method<cv::Mat(cv::cuda::HOG::*)() const>("get_default_people_detector", &cv::cuda::HOG::getDefaultPeopleDetector).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Point_<int>>&, std::vector<double>*)>("detect", &cv::cuda::HOG::detect).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Point_<int>>&, std::vector<double>&)>("detect", &cv::cuda::HOG::detect).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Point_<int>>&)>("detect_without_conf", &cv::cuda::HOG::detectWithoutConf).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&, std::vector<double>*)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&, std::vector<double>&)>("detect_multi_scale", &cv::cuda::HOG::detectMultiScale).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, std::vector<cv::Rect_<int>>&)>("detect_multi_scale_without_conf", &cv::cuda::HOG::detectMultiScaleWithoutConf).
    define_method<void(cv::cuda::HOG::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::HOG::compute);
  
  Class rb_cCvCudaCascadeClassifier = define_class_under<cv::cuda::CascadeClassifier, cv::Algorithm>(rb_mCvCuda, "CascadeClassifier").
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const std::basic_string<char>&)>("create", &cv::cuda::CascadeClassifier::create).
    define_singleton_function<cv::Ptr<cv::cuda::CascadeClassifier>(*)(const cv::FileStorage&)>("create", &cv::cuda::CascadeClassifier::create).
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::Size_<int>)>("set_max_object_size", &cv::cuda::CascadeClassifier::setMaxObjectSize).
    define_method<cv::Size_<int>(cv::cuda::CascadeClassifier::*)() const>("get_max_object_size", &cv::cuda::CascadeClassifier::getMaxObjectSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(cv::Size_<int>)>("set_min_object_size", &cv::cuda::CascadeClassifier::setMinObjectSize).
    define_method<cv::Size_<int>(cv::cuda::CascadeClassifier::*)() const>("get_min_object_size", &cv::cuda::CascadeClassifier::getMinObjectSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(double)>("set_scale_factor", &cv::cuda::CascadeClassifier::setScaleFactor).
    define_method<double(cv::cuda::CascadeClassifier::*)() const>("get_scale_factor", &cv::cuda::CascadeClassifier::getScaleFactor).
    define_method<void(cv::cuda::CascadeClassifier::*)(int)>("set_min_neighbors", &cv::cuda::CascadeClassifier::setMinNeighbors).
    define_method<int(cv::cuda::CascadeClassifier::*)() const>("get_min_neighbors", &cv::cuda::CascadeClassifier::getMinNeighbors).
    define_method<void(cv::cuda::CascadeClassifier::*)(bool)>("set_find_largest_object", &cv::cuda::CascadeClassifier::setFindLargestObject).
    define_method<bool(cv::cuda::CascadeClassifier::*)()>("get_find_largest_object", &cv::cuda::CascadeClassifier::getFindLargestObject).
    define_method<void(cv::cuda::CascadeClassifier::*)(int)>("set_max_num_objects", &cv::cuda::CascadeClassifier::setMaxNumObjects).
    define_method<int(cv::cuda::CascadeClassifier::*)() const>("get_max_num_objects", &cv::cuda::CascadeClassifier::getMaxNumObjects).
    define_method<cv::Size_<int>(cv::cuda::CascadeClassifier::*)() const>("get_classifier_size", &cv::cuda::CascadeClassifier::getClassifierSize).
    define_method<void(cv::cuda::CascadeClassifier::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect_multi_scale", &cv::cuda::CascadeClassifier::detectMultiScale).
    define_method<void(cv::cuda::CascadeClassifier::*)(const cv::_OutputArray &, std::vector<cv::Rect_<int>>&)>("convert", &cv::cuda::CascadeClassifier::convert);
}