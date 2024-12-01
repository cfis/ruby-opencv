#include <sstream>
#include <opencv2/objdetect/face.hpp>
#include "face-rb.hpp"

using namespace Rice;



void Init_Face()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvFaceDetectorYN = define_class_under<cv::FaceDetectorYN>(rb_mCv, "FaceDetectorYN").
    define_method<void(cv::FaceDetectorYN::*)(const cv::Size&)>("set_input_size", &cv::FaceDetectorYN::setInputSize,
      Arg("input_size")).
    define_method<cv::Size(cv::FaceDetectorYN::*)()>("get_input_size", &cv::FaceDetectorYN::getInputSize).
    define_method<void(cv::FaceDetectorYN::*)(float)>("set_score_threshold", &cv::FaceDetectorYN::setScoreThreshold,
      Arg("score_threshold")).
    define_method<float(cv::FaceDetectorYN::*)()>("get_score_threshold", &cv::FaceDetectorYN::getScoreThreshold).
    define_method<void(cv::FaceDetectorYN::*)(float)>("set_nms_threshold", &cv::FaceDetectorYN::setNMSThreshold,
      Arg("nms_threshold")).
    define_method<float(cv::FaceDetectorYN::*)()>("get_nms_threshold", &cv::FaceDetectorYN::getNMSThreshold).
    define_method<void(cv::FaceDetectorYN::*)(int)>("set_top_k", &cv::FaceDetectorYN::setTopK,
      Arg("top_k")).
    define_method<int(cv::FaceDetectorYN::*)()>("get_top_k", &cv::FaceDetectorYN::getTopK).
    define_method<int(cv::FaceDetectorYN::*)(cv::InputArray, cv::OutputArray)>("detect", &cv::FaceDetectorYN::detect,
      Arg("image"), Arg("faces")).
    define_singleton_function<cv::Ptr<cv::FaceDetectorYN>(*)(const cv::String&, const cv::String&, const cv::Size&, float, float, int, int, int)>("create", &cv::FaceDetectorYN::create,
      Arg("model"), Arg("config"), Arg("input_size"), Arg("score_threshold") = 0.9f, Arg("nms_threshold") = 0.3f, Arg("top_k") = 5000, Arg("backend_id") = 0, Arg("target_id") = 0).
    define_singleton_function<cv::Ptr<cv::FaceDetectorYN>(*)(const cv::String&, const std::vector<unsigned char>&, const std::vector<unsigned char>&, const cv::Size&, float, float, int, int, int)>("create", &cv::FaceDetectorYN::create,
      Arg("framework"), Arg("buffer_model"), Arg("buffer_config"), Arg("input_size"), Arg("score_threshold") = 0.9f, Arg("nms_threshold") = 0.3f, Arg("top_k") = 5000, Arg("backend_id") = 0, Arg("target_id") = 0);
  
  Class rb_cCvFaceRecognizerSF = define_class_under<cv::FaceRecognizerSF>(rb_mCv, "FaceRecognizerSF").
    define_method<void(cv::FaceRecognizerSF::*)(cv::InputArray, cv::InputArray, cv::OutputArray) const>("align_crop", &cv::FaceRecognizerSF::alignCrop,
      Arg("src_img"), Arg("face_box"), Arg("aligned_img")).
    define_method<void(cv::FaceRecognizerSF::*)(cv::InputArray, cv::OutputArray)>("feature", &cv::FaceRecognizerSF::feature,
      Arg("aligned_img"), Arg("face_feature")).
    define_method<double(cv::FaceRecognizerSF::*)(cv::InputArray, cv::InputArray, int) const>("match", &cv::FaceRecognizerSF::match,
      Arg("face_feature1"), Arg("face_feature2"), Arg("dis_type")).
    define_singleton_function<cv::Ptr<cv::FaceRecognizerSF>(*)(const cv::String&, const cv::String&, int, int)>("create", &cv::FaceRecognizerSF::create,
      Arg("model"), Arg("config"), Arg("backend_id") = 0, Arg("target_id") = 0);
  
  Enum<cv::FaceRecognizerSF::DisType> rb_cCvFaceRecognizerSFDisType = define_enum_under<cv::FaceRecognizerSF::DisType>("DisType", rb_cCvFaceRecognizerSF).
    define_value("FR_COSINE", cv::FaceRecognizerSF::DisType::FR_COSINE).
    define_value("FR_NORM_L2", cv::FaceRecognizerSF::DisType::FR_NORM_L2);

}