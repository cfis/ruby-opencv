#include <opencv2/datasets/fr_adience.hpp>
#include "fr_adience-rb.hpp"

using namespace Rice;

extern "C"
void Init_FrAdience()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Enum<cv::datasets::genderType> rb_cCvDatasetsGenderType = define_enum<cv::datasets::genderType>("GenderType", rb_mCvDatasets).
    define_value("male", cv::datasets::genderType::male).
    define_value("female", cv::datasets::genderType::female).
    define_value("none", cv::datasets::genderType::none);
  
  Class rb_cCvDatasetsFRAdienceObj = define_class_under<cv::datasets::FR_adienceObj, cv::datasets::Object>(rb_mCvDatasets, "FRAdienceObj").
    define_attr("user_id", &cv::datasets::FR_adienceObj::user_id).
    define_attr("original_image", &cv::datasets::FR_adienceObj::original_image).
    define_attr("face_id", &cv::datasets::FR_adienceObj::face_id).
    define_attr("age", &cv::datasets::FR_adienceObj::age).
    define_attr("gender", &cv::datasets::FR_adienceObj::gender).
    define_attr("x", &cv::datasets::FR_adienceObj::x).
    define_attr("y", &cv::datasets::FR_adienceObj::y).
    define_attr("dx", &cv::datasets::FR_adienceObj::dx).
    define_attr("dy", &cv::datasets::FR_adienceObj::dy).
    define_attr("tilt_ang", &cv::datasets::FR_adienceObj::tilt_ang).
    define_attr("fiducial_yaw_angle", &cv::datasets::FR_adienceObj::fiducial_yaw_angle).
    define_attr("fiducial_score", &cv::datasets::FR_adienceObj::fiducial_score);
  
  Class rb_cCvDatasetsFRAdience = define_class_under<cv::datasets::FR_adience, cv::datasets::Dataset>(rb_mCvDatasets, "FRAdience").
    define_method<void(cv::datasets::FR_adience::*)(const std::basic_string<char>&)>("load", &cv::datasets::FR_adience::load).
    define_singleton_function<cv::Ptr<cv::datasets::FR_adience>(*)()>("create", &cv::datasets::FR_adience::create).
    define_attr("paths", &cv::datasets::FR_adience::paths);
}