#include <opencv2/face/facerec.hpp>
#include "facerec-rb.hpp"

using namespace Rice;

extern "C"
void Init_Facerec()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceBasicFaceRecognizer = define_class_under<cv::face::BasicFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "BasicFaceRecognizer").
    define_method<int(cv::face::BasicFaceRecognizer::*)() const>("get_num_components", &cv::face::BasicFaceRecognizer::getNumComponents).
    define_method<void(cv::face::BasicFaceRecognizer::*)(int)>("set_num_components", &cv::face::BasicFaceRecognizer::setNumComponents).
    define_method<double(cv::face::BasicFaceRecognizer::*)() const>("get_threshold", &cv::face::BasicFaceRecognizer::getThreshold).
    define_method<void(cv::face::BasicFaceRecognizer::*)(double)>("set_threshold", &cv::face::BasicFaceRecognizer::setThreshold).
    define_method<std::vector<cv::Mat>(cv::face::BasicFaceRecognizer::*)() const>("get_projections", &cv::face::BasicFaceRecognizer::getProjections).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_labels", &cv::face::BasicFaceRecognizer::getLabels).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_eigen_values", &cv::face::BasicFaceRecognizer::getEigenValues).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_eigen_vectors", &cv::face::BasicFaceRecognizer::getEigenVectors).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_mean", &cv::face::BasicFaceRecognizer::getMean).
    define_method<void(cv::face::BasicFaceRecognizer::*)(const cv::FileNode&)>("read", &cv::face::BasicFaceRecognizer::read).
    define_method<void(cv::face::BasicFaceRecognizer::*)(cv::FileStorage&) const>("write", &cv::face::BasicFaceRecognizer::write).
    define_method<bool(cv::face::BasicFaceRecognizer::*)() const>("empty", &cv::face::BasicFaceRecognizer::empty);
  
  Class rb_cCvFaceEigenFaceRecognizer = define_class_under<cv::face::EigenFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "EigenFaceRecognizer").
    define_singleton_function<cv::Ptr<cv::face::EigenFaceRecognizer>(*)(int, double)>("create", &cv::face::EigenFaceRecognizer::create);
  
  Class rb_cCvFaceFisherFaceRecognizer = define_class_under<cv::face::FisherFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "FisherFaceRecognizer").
    define_singleton_function<cv::Ptr<cv::face::FisherFaceRecognizer>(*)(int, double)>("create", &cv::face::FisherFaceRecognizer::create);
  
  Class rb_cCvFaceLBPHFaceRecognizer = define_class_under<cv::face::LBPHFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "LBPHFaceRecognizer").
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_grid_x", &cv::face::LBPHFaceRecognizer::getGridX).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_grid_x", &cv::face::LBPHFaceRecognizer::setGridX).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_grid_y", &cv::face::LBPHFaceRecognizer::getGridY).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_grid_y", &cv::face::LBPHFaceRecognizer::setGridY).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_radius", &cv::face::LBPHFaceRecognizer::getRadius).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_radius", &cv::face::LBPHFaceRecognizer::setRadius).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_neighbors", &cv::face::LBPHFaceRecognizer::getNeighbors).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_neighbors", &cv::face::LBPHFaceRecognizer::setNeighbors).
    define_method<double(cv::face::LBPHFaceRecognizer::*)() const>("get_threshold", &cv::face::LBPHFaceRecognizer::getThreshold).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(double)>("set_threshold", &cv::face::LBPHFaceRecognizer::setThreshold).
    define_method<std::vector<cv::Mat>(cv::face::LBPHFaceRecognizer::*)() const>("get_histograms", &cv::face::LBPHFaceRecognizer::getHistograms).
    define_method<cv::Mat(cv::face::LBPHFaceRecognizer::*)() const>("get_labels", &cv::face::LBPHFaceRecognizer::getLabels).
    define_singleton_function<cv::Ptr<cv::face::LBPHFaceRecognizer>(*)(int, int, int, int, double)>("create", &cv::face::LBPHFaceRecognizer::create);
}