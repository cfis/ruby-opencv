#include <opencv2/face/facemarkAAM.hpp>
#include "facemarkAAM-rb.hpp"

using namespace Rice;

extern "C"
void Init_FacemarkAAM()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceFacemarkAAM = define_class_under<cv::face::FacemarkAAM, cv::face::FacemarkTrain>(rb_mCvFace, "FacemarkAAM").
    define_method<bool(cv::face::FacemarkAAM::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const std::vector<cv::face::FacemarkAAM::Config>&)>("fit_config", &cv::face::FacemarkAAM::fitConfig).
    define_singleton_function<cv::Ptr<cv::face::FacemarkAAM>(*)(const cv::face::FacemarkAAM::Params&)>("create", &cv::face::FacemarkAAM::create);
  
  Class rb_cCvFaceFacemarkAAMParams = define_class_under<cv::face::FacemarkAAM::Params>(rb_cCvFaceFacemarkAAM, "Params").
    define_constructor(Constructor<cv::face::FacemarkAAM::Params>()).
    define_method<void(cv::face::FacemarkAAM::Params::*)(const cv::FileNode&)>("read", &cv::face::FacemarkAAM::Params::read).
    define_method<void(cv::face::FacemarkAAM::Params::*)(cv::FileStorage&) const>("write", &cv::face::FacemarkAAM::Params::write).
    define_attr("model_filename", &cv::face::FacemarkAAM::Params::model_filename).
    define_attr("m", &cv::face::FacemarkAAM::Params::m).
    define_attr("n", &cv::face::FacemarkAAM::Params::n).
    define_attr("n_iter", &cv::face::FacemarkAAM::Params::n_iter).
    define_attr("verbose", &cv::face::FacemarkAAM::Params::verbose).
    define_attr("save_model", &cv::face::FacemarkAAM::Params::save_model).
    define_attr("max_m", &cv::face::FacemarkAAM::Params::max_m).
    define_attr("max_n", &cv::face::FacemarkAAM::Params::max_n).
    define_attr("texture_max_m", &cv::face::FacemarkAAM::Params::texture_max_m).
    define_attr("scales", &cv::face::FacemarkAAM::Params::scales);
  
  Class rb_cCvFaceFacemarkAAMConfig = define_class_under<cv::face::FacemarkAAM::Config>(rb_cCvFaceFacemarkAAM, "Config").
    define_constructor(Constructor<cv::face::FacemarkAAM::Config, cv::Mat, cv::Point_<float>, float, int>()).
    define_attr("r", &cv::face::FacemarkAAM::Config::R).
    define_attr("t", &cv::face::FacemarkAAM::Config::t).
    define_attr("scale", &cv::face::FacemarkAAM::Config::scale).
    define_attr("model_scale_idx", &cv::face::FacemarkAAM::Config::model_scale_idx);
  
  Class rb_cCvFaceFacemarkAAMData = define_class_under<cv::face::FacemarkAAM::Data>(rb_cCvFaceFacemarkAAM, "Data").
    define_attr("s0", &cv::face::FacemarkAAM::Data::s0);
  
  Class rb_cCvFaceFacemarkAAMModel = define_class_under<cv::face::FacemarkAAM::Model>(rb_cCvFaceFacemarkAAM, "Model").
    define_attr("scales", &cv::face::FacemarkAAM::Model::scales).
    define_attr("triangles", &cv::face::FacemarkAAM::Model::triangles).
    define_attr("textures", &cv::face::FacemarkAAM::Model::textures).
    define_attr("s0", &cv::face::FacemarkAAM::Model::s0).
    define_attr("s", &cv::face::FacemarkAAM::Model::S).
    define_attr("q", &cv::face::FacemarkAAM::Model::Q);
  
  Class rb_cCvFaceFacemarkAAMModelTexture = define_class_under<cv::face::FacemarkAAM::Model::Texture>(rb_cCvFaceFacemarkAAMModel, "Texture").
    define_attr("max_m", &cv::face::FacemarkAAM::Model::Texture::max_m).
    define_attr("resolution", &cv::face::FacemarkAAM::Model::Texture::resolution).
    define_attr("a", &cv::face::FacemarkAAM::Model::Texture::A).
    define_attr("a0", &cv::face::FacemarkAAM::Model::Texture::A0).
    define_attr("aa", &cv::face::FacemarkAAM::Model::Texture::AA).
    define_attr("aa0", &cv::face::FacemarkAAM::Model::Texture::AA0).
    define_attr("texture_idx", &cv::face::FacemarkAAM::Model::Texture::textureIdx).
    define_attr("base_shape", &cv::face::FacemarkAAM::Model::Texture::base_shape).
    define_attr("ind1", &cv::face::FacemarkAAM::Model::Texture::ind1).
    define_attr("ind2", &cv::face::FacemarkAAM::Model::Texture::ind2);
}