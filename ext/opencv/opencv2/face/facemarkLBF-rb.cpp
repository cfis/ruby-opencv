#include <opencv2/face/facemarkLBF.hpp>
#include "facemarkLBF-rb.hpp"

using namespace Rice;

extern "C"
void Init_FacemarkLBF()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceFacemarkLBF = define_class_under<cv::face::FacemarkLBF, cv::face::FacemarkTrain>(rb_mCvFace, "FacemarkLBF").
    define_singleton_function<cv::Ptr<cv::face::FacemarkLBF>(*)(const cv::face::FacemarkLBF::Params&)>("create", &cv::face::FacemarkLBF::create);
  
  Class rb_cCvFaceFacemarkLBFBBox = define_class_under<cv::face::FacemarkLBF::BBox>(rb_cCvFaceFacemarkLBF, "BBox").
    define_constructor(Constructor<cv::face::FacemarkLBF::BBox>()).
    define_constructor(Constructor<cv::face::FacemarkLBF::BBox, double, double, double, double>()).
    define_method<cv::Mat(cv::face::FacemarkLBF::BBox::*)(const cv::Mat&) const>("project", &cv::face::FacemarkLBF::BBox::project).
    define_method<cv::Mat(cv::face::FacemarkLBF::BBox::*)(const cv::Mat&) const>("reproject", &cv::face::FacemarkLBF::BBox::reproject).
    define_attr("x", &cv::face::FacemarkLBF::BBox::x).
    define_attr("y", &cv::face::FacemarkLBF::BBox::y).
    define_attr("x_center", &cv::face::FacemarkLBF::BBox::x_center).
    define_attr("y_center", &cv::face::FacemarkLBF::BBox::y_center).
    define_attr("x_scale", &cv::face::FacemarkLBF::BBox::x_scale).
    define_attr("y_scale", &cv::face::FacemarkLBF::BBox::y_scale).
    define_attr("width", &cv::face::FacemarkLBF::BBox::width).
    define_attr("height", &cv::face::FacemarkLBF::BBox::height);
  
  Class rb_cCvFaceFacemarkLBFParams = define_class_under<cv::face::FacemarkLBF::Params>(rb_cCvFaceFacemarkLBF, "Params").
    define_constructor(Constructor<cv::face::FacemarkLBF::Params>()).
    define_attr("shape_offset", &cv::face::FacemarkLBF::Params::shape_offset).
    define_attr("cascade_face", &cv::face::FacemarkLBF::Params::cascade_face).
    define_attr("verbose", &cv::face::FacemarkLBF::Params::verbose).
    define_attr("n_landmarks", &cv::face::FacemarkLBF::Params::n_landmarks).
    define_attr("init_shape_n", &cv::face::FacemarkLBF::Params::initShape_n).
    define_attr("stages_n", &cv::face::FacemarkLBF::Params::stages_n).
    define_attr("tree_n", &cv::face::FacemarkLBF::Params::tree_n).
    define_attr("tree_depth", &cv::face::FacemarkLBF::Params::tree_depth).
    define_attr("bagging_overlap", &cv::face::FacemarkLBF::Params::bagging_overlap).
    define_attr("model_filename", &cv::face::FacemarkLBF::Params::model_filename).
    define_attr("save_model", &cv::face::FacemarkLBF::Params::save_model).
    define_attr("seed", &cv::face::FacemarkLBF::Params::seed).
    define_attr("feats_m", &cv::face::FacemarkLBF::Params::feats_m).
    define_attr("radius_m", &cv::face::FacemarkLBF::Params::radius_m).
    define_attr("pupils", &cv::face::FacemarkLBF::Params::pupils).
    define_attr("detect_roi", &cv::face::FacemarkLBF::Params::detectROI).
    define_method<void(cv::face::FacemarkLBF::Params::*)(const cv::FileNode&)>("read", &cv::face::FacemarkLBF::Params::read).
    define_method<void(cv::face::FacemarkLBF::Params::*)(cv::FileStorage&) const>("write", &cv::face::FacemarkLBF::Params::write);
}