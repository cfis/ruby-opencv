#include <opencv2/face.hpp>
#include "face-rb.hpp"

using namespace Rice;

extern "C"
void Init_Face()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceFaceRecognizer = define_class_under<cv::face::FaceRecognizer, cv::Algorithm>(rb_mCvFace, "FaceRecognizer").
    define_method<void(cv::face::FaceRecognizer::*)(const cv::_InputArray &, const cv::_InputArray &)>("train", &cv::face::FaceRecognizer::train).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::_InputArray &, const cv::_InputArray &)>("update", &cv::face::FaceRecognizer::update).
    define_method<int(cv::face::FaceRecognizer::*)(const cv::_InputArray &) const>("predict", &cv::face::FaceRecognizer::predict).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::_InputArray &, int&, double&) const>("predict", &cv::face::FaceRecognizer::predict).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::_InputArray &, cv::Ptr<cv::face::PredictCollector>) const>("predict", &cv::face::FaceRecognizer::predict).
    define_method<void(cv::face::FaceRecognizer::*)(const std::basic_string<char>&) const>("write", &cv::face::FaceRecognizer::write).
    define_method<void(cv::face::FaceRecognizer::*)(const std::basic_string<char>&)>("read", &cv::face::FaceRecognizer::read).
    define_method<void(cv::face::FaceRecognizer::*)(cv::FileStorage&) const>("write", &cv::face::FaceRecognizer::write).
    define_method<void(cv::face::FaceRecognizer::*)(const cv::FileNode&)>("read", &cv::face::FaceRecognizer::read).
    define_method<bool(cv::face::FaceRecognizer::*)() const>("empty", &cv::face::FaceRecognizer::empty).
    define_method<void(cv::face::FaceRecognizer::*)(int, const std::basic_string<char>&)>("set_label_info", &cv::face::FaceRecognizer::setLabelInfo).
    define_method<std::basic_string<char>(cv::face::FaceRecognizer::*)(int) const>("get_label_info", &cv::face::FaceRecognizer::getLabelInfo).
    define_method<std::vector<int>(cv::face::FaceRecognizer::*)(const std::basic_string<char>&) const>("get_labels_by_string", &cv::face::FaceRecognizer::getLabelsByString).
    define_method<double(cv::face::FaceRecognizer::*)() const>("get_threshold", &cv::face::FaceRecognizer::getThreshold).
    define_method<void(cv::face::FaceRecognizer::*)(double)>("set_threshold", &cv::face::FaceRecognizer::setThreshold);
}