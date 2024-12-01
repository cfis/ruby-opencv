#include <opencv2/face/face_alignment.hpp>
#include "face_alignment-rb.hpp"

using namespace Rice;

extern "C"
void Init_FaceAlignment()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceFacemarkKazemi = define_class_under<cv::face::FacemarkKazemi, cv::face::Facemark>(rb_mCvFace, "FacemarkKazemi").
    define_singleton_function<cv::Ptr<cv::face::FacemarkKazemi>(*)(const cv::face::FacemarkKazemi::Params&)>("create", &cv::face::FacemarkKazemi::create).
    define_method<bool(cv::face::FacemarkKazemi::*)(std::vector<cv::Mat>&, std::vector<std::vector<cv::Point_<float>>>&, std::basic_string<char>, cv::Size_<int>, std::basic_string<char>)>("training", &cv::face::FacemarkKazemi::training).
    define_method<bool(cv::face::FacemarkKazemi::*)(bool (InputArray, OutputArray, void *)*, void*)>("set_face_detector", &cv::face::FacemarkKazemi::setFaceDetector).
    define_method<bool(cv::face::FacemarkKazemi::*)(const cv::_InputArray &, const cv::_OutputArray &)>("get_faces", &cv::face::FacemarkKazemi::getFaces);
  
  Class rb_cCvFaceFacemarkKazemiParams = define_class_under<cv::face::FacemarkKazemi::Params>(rb_cCvFaceFacemarkKazemi, "Params").
    define_constructor(Constructor<cv::face::FacemarkKazemi::Params>()).
    define_attr("cascade_depth", &cv::face::FacemarkKazemi::Params::cascade_depth).
    define_attr("tree_depth", &cv::face::FacemarkKazemi::Params::tree_depth).
    define_attr("num_trees_per_cascade_level", &cv::face::FacemarkKazemi::Params::num_trees_per_cascade_level).
    define_attr("learning_rate", &cv::face::FacemarkKazemi::Params::learning_rate).
    define_attr("oversampling_amount", &cv::face::FacemarkKazemi::Params::oversampling_amount).
    define_attr("num_test_coordinates", &cv::face::FacemarkKazemi::Params::num_test_coordinates).
    define_attr("lambda", &cv::face::FacemarkKazemi::Params::lambda).
    define_attr("num_test_splits", &cv::face::FacemarkKazemi::Params::num_test_splits).
    define_attr("configfile", &cv::face::FacemarkKazemi::Params::configfile);
}