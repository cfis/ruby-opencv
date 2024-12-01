#include <opencv2/quality/qualityssim.hpp>
#include "qualityssim-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualityssim()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualitySSIM = define_class_under<cv::quality::QualitySSIM, cv::quality::QualityBase>(rb_mCvQuality, "QualitySSIM").
    define_method<cv::Scalar_<double>(cv::quality::QualitySSIM::*)(const cv::_InputArray &)>("compute", &cv::quality::QualitySSIM::compute).
    define_method<bool(cv::quality::QualitySSIM::*)() const>("empty", &cv::quality::QualitySSIM::empty).
    define_method<void(cv::quality::QualitySSIM::*)()>("clear", &cv::quality::QualitySSIM::clear).
    define_singleton_function<cv::Ptr<cv::quality::QualitySSIM>(*)(const cv::_InputArray &)>("create", &cv::quality::QualitySSIM::create).
    define_singleton_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::quality::QualitySSIM::compute).
    define_constructor(Constructor<cv::quality::QualitySSIM, cv::quality::QualitySSIM::_mat_data>());
  
  Class rb_cCvQualityQualitySSIMMatData = define_class_under<cv::quality::QualitySSIM::_mat_data>(rb_cCvQualityQualitySSIM, "MatData").
    define_attr("i", &cv::quality::QualitySSIM::_mat_data::I).
    define_attr("i_2", &cv::quality::QualitySSIM::_mat_data::I_2).
    define_attr("mu", &cv::quality::QualitySSIM::_mat_data::mu).
    define_attr("mu_2", &cv::quality::QualitySSIM::_mat_data::mu_2).
    define_attr("sigma_2", &cv::quality::QualitySSIM::_mat_data::sigma_2).
    define_constructor(Constructor<cv::quality::QualitySSIM::_mat_data>()).
    define_constructor(Constructor<cv::quality::QualitySSIM::_mat_data, const cv::UMat&>()).
    define_constructor(Constructor<cv::quality::QualitySSIM::_mat_data, const cv::_InputArray &>()).
    define_method<bool(cv::quality::QualitySSIM::_mat_data::*)() const>("empty", &cv::quality::QualitySSIM::_mat_data::empty).
    define_singleton_function<std::pair<cv::Scalar_<double>, cv::UMat>(*)(const cv::quality::QualitySSIM::_mat_data&, const cv::quality::QualitySSIM::_mat_data&)>("compute", &cv::quality::QualitySSIM::_mat_data::compute);
}