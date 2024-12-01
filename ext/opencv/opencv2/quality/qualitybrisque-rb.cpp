#include <opencv2/quality/qualitybrisque.hpp>
#include "qualitybrisque-rb.hpp"

using namespace Rice;

extern "C"
void Init_Qualitybrisque()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvQuality = define_module_under(rb_mCv, "Quality");
  
  Class rb_cCvQualityQualityBRISQUE = define_class_under<cv::quality::QualityBRISQUE, cv::quality::QualityBase>(rb_mCvQuality, "QualityBRISQUE").
    define_method<cv::Scalar_<double>(cv::quality::QualityBRISQUE::*)(const cv::_InputArray &)>("compute", &cv::quality::QualityBRISQUE::compute).
    define_singleton_function<cv::Ptr<cv::quality::QualityBRISQUE>(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("create", &cv::quality::QualityBRISQUE::create).
    define_singleton_function<cv::Ptr<cv::quality::QualityBRISQUE>(*)(const cv::Ptr<cv::ml::SVM>&, const cv::Mat&)>("create", &cv::quality::QualityBRISQUE::create).
    define_singleton_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const std::basic_string<char>&, const std::basic_string<char>&)>("compute", &cv::quality::QualityBRISQUE::compute).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("compute_features", &cv::quality::QualityBRISQUE::computeFeatures).
    define_constructor(Constructor<cv::quality::QualityBRISQUE, const std::basic_string<char>&, const std::basic_string<char>&>()).
    define_constructor(Constructor<cv::quality::QualityBRISQUE, const cv::Ptr<cv::ml::SVM>&, const cv::Mat&>());
}