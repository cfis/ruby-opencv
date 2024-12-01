#include <opencv2/face/facemark_train.hpp>
#include "facemark_train-rb.hpp"

using namespace Rice;

extern "C"
void Init_FacemarkTrain()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFace = define_module_under(rb_mCv, "Face");
  
  Class rb_cCvFaceCParams = define_class_under<cv::face::CParams>(rb_mCvFace, "CParams").
    define_attr("cascade", &cv::face::CParams::cascade).
    define_attr("scale_factor", &cv::face::CParams::scaleFactor).
    define_attr("min_neighbors", &cv::face::CParams::minNeighbors).
    define_attr("min_size", &cv::face::CParams::minSize).
    define_attr("max_size", &cv::face::CParams::maxSize).
    define_constructor(Constructor<cv::face::CParams, std::basic_string<char>, double, int, cv::Size_<int>, cv::Size_<int>>()).
    define_attr("face_cascade", &cv::face::CParams::face_cascade);
  
  rb_mCvFace.define_module_function<bool(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::face::CParams*)>("get_faces", &cv::face::getFaces);
  
  rb_mCvFace.define_module_function<bool(*)(const cv::_InputArray &, const cv::_OutputArray &, const std::basic_string<char>&)>("get_faces_haar", &cv::face::getFacesHAAR);
  
  rb_mCvFace.define_module_function<bool(*)(std::basic_string<char>, std::basic_string<char>, std::vector<std::basic_string<char>>&, std::vector<std::basic_string<char>>&)>("load_dataset_list", &cv::face::loadDatasetList);
  
  rb_mCvFace.define_module_function<bool(*)(std::basic_string<char>, std::vector<std::basic_string<char>>&, const cv::_OutputArray &, char, float)>("load_training_data", &cv::face::loadTrainingData);
  
  rb_mCvFace.define_module_function<bool(*)(std::basic_string<char>, std::basic_string<char>, std::vector<std::basic_string<char>>&, const cv::_OutputArray &, float)>("load_training_data", &cv::face::loadTrainingData);
  
  rb_mCvFace.define_module_function<bool(*)(std::vector<std::basic_string<char>>, std::vector<std::vector<cv::Point_<float>>>&, std::vector<std::basic_string<char>>&)>("load_training_data", &cv::face::loadTrainingData);
  
  rb_mCvFace.define_module_function<bool(*)(std::basic_string<char>, const cv::_OutputArray &, float)>("load_face_points", &cv::face::loadFacePoints);
  
  rb_mCvFace.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, cv::Scalar_<double>)>("draw_facemarks", &cv::face::drawFacemarks);
  
  Class rb_cCvFaceFacemarkTrain = define_class_under<cv::face::FacemarkTrain, cv::face::Facemark>(rb_mCvFace, "FacemarkTrain").
    define_method<bool(cv::face::FacemarkTrain::*)(const cv::_InputArray &, const cv::_InputArray &)>("add_training_sample", &cv::face::FacemarkTrain::addTrainingSample).
    define_method<void(cv::face::FacemarkTrain::*)(void*)>("training", &cv::face::FacemarkTrain::training).
    define_method<bool(cv::face::FacemarkTrain::*)(bool (*)(const cv::_InputArray &, const cv::_OutputArray &, void *), void*)>("set_face_detector", &cv::face::FacemarkTrain::setFaceDetector).
    define_method<bool(cv::face::FacemarkTrain::*)(const cv::_InputArray &, const cv::_OutputArray &)>("get_faces", &cv::face::FacemarkTrain::getFaces).
    define_method<bool(cv::face::FacemarkTrain::*)(void*)>("get_data", &cv::face::FacemarkTrain::getData);
}