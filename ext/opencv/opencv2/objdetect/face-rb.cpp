#include <opencv2/objdetect/face.hpp>
#include "face-rb.hpp"

using namespace Rice;

extern "C"
void Init_Face()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvFaceDetectorYN = define_class_under<cv::FaceDetectorYN>(rb_mCv, "FaceDetectorYN").
    define_method<void(cv::FaceDetectorYN::*)(const cv::Size_<int>&)>("set_input_size", &cv::FaceDetectorYN::setInputSize).
    define_method<cv::Size_<int>(cv::FaceDetectorYN::*)()>("get_input_size", &cv::FaceDetectorYN::getInputSize).
    define_method<void(cv::FaceDetectorYN::*)(float)>("set_score_threshold", &cv::FaceDetectorYN::setScoreThreshold).
    define_method<float(cv::FaceDetectorYN::*)()>("get_score_threshold", &cv::FaceDetectorYN::getScoreThreshold).
    define_method<void(cv::FaceDetectorYN::*)(float)>("set_nms_threshold", &cv::FaceDetectorYN::setNMSThreshold).
    define_method<float(cv::FaceDetectorYN::*)()>("get_nms_threshold", &cv::FaceDetectorYN::getNMSThreshold).
    define_method<void(cv::FaceDetectorYN::*)(int)>("set_top_k", &cv::FaceDetectorYN::setTopK).
    define_method<int(cv::FaceDetectorYN::*)()>("get_top_k", &cv::FaceDetectorYN::getTopK).
    define_method<int(cv::FaceDetectorYN::*)(const cv::_InputArray &, const cv::_OutputArray &)>("detect", &cv::FaceDetectorYN::detect).
    define_singleton_function<cv::Ptr<cv::FaceDetectorYN>(*)(const std::basic_string<char>&, const std::basic_string<char>&, const cv::Size_<int>&, float, float, int, int, int)>("create", &cv::FaceDetectorYN::create);
  
  Class rb_cCvFaceRecognizerSF = define_class_under<cv::FaceRecognizerSF>(rb_mCv, "FaceRecognizerSF").
    define_method<void(cv::FaceRecognizerSF::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &) const>("align_crop", &cv::FaceRecognizerSF::alignCrop).
    define_method<void(cv::FaceRecognizerSF::*)(const cv::_InputArray &, const cv::_OutputArray &)>("feature", &cv::FaceRecognizerSF::feature).
    define_method<double(cv::FaceRecognizerSF::*)(const cv::_InputArray &, const cv::_InputArray &, int) const>("match", &cv::FaceRecognizerSF::match).
    define_singleton_function<cv::Ptr<cv::FaceRecognizerSF>(*)(const std::basic_string<char>&, const std::basic_string<char>&, int, int)>("create", &cv::FaceRecognizerSF::create);
  
  Enum<cv::FaceRecognizerSF::DisType> rb_cCvFaceRecognizerSFDisType = define_enum<cv::FaceRecognizerSF::DisType>("DisType", rb_cCvFaceRecognizerSF).
    define_value("FR_COSINE", cv::FaceRecognizerSF::DisType::FR_COSINE).
    define_value("FR_NORM_L2", cv::FaceRecognizerSF::DisType::FR_NORM_L2);
}