#include <opencv2/quality/qualitygmsd.hpp>
#include "qualitygmsd-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualitygmsd()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualityGMSD = define_class_under<cv::quality::QualityGMSD, cv::quality::QualityBase>(rb_mCvQuality, "QualityGMSD").
    define_method<cv::Scalar_<double>(cv::quality::QualityGMSD::*)(const cv::_InputArray &)>("compute", &cv::quality::QualityGMSD::compute).
    define_method<bool(cv::quality::QualityGMSD::*)() const>("empty", &cv::quality::QualityGMSD::empty).
    define_method<void(cv::quality::QualityGMSD::*)()>("clear", &cv::quality::QualityGMSD::clear).
    define_singleton_function<cv::Ptr<cv::quality::QualityGMSD>(*)(const cv::_InputArray &)>("create", &cv::quality::QualityGMSD::create).
    define_singleton_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::quality::QualityGMSD::compute).
    define_constructor(Constructor<cv::quality::QualityGMSD, cv::quality::QualityGMSD::_mat_data>());
  
  Class rb_cCvQualityQualityGMSDMatData = define_class_under<cv::quality::QualityGMSD::_mat_data>(rb_cCvQualityQualityGMSD, "MatData").
    define_attr("gradient_map", &cv::quality::QualityGMSD::_mat_data::gradient_map).
    define_attr("gradient_map_squared", &cv::quality::QualityGMSD::_mat_data::gradient_map_squared).
    define_constructor(Constructor<cv::quality::QualityGMSD::_mat_data>()).
    define_constructor(Constructor<cv::quality::QualityGMSD::_mat_data, const cv::UMat&>()).
    define_constructor(Constructor<cv::quality::QualityGMSD::_mat_data, const cv::_InputArray &>()).
    define_method<bool(cv::quality::QualityGMSD::_mat_data::*)() const>("empty", &cv::quality::QualityGMSD::_mat_data::empty).
    define_singleton_function<std::pair<cv::Scalar_<double>, cv::UMat>(*)(const cv::quality::QualityGMSD::_mat_data&, const cv::quality::QualityGMSD::_mat_data&)>("compute", &cv::quality::QualityGMSD::_mat_data::compute);
}