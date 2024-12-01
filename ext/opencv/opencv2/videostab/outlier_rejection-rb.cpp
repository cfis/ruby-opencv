#include <opencv2/videostab/outlier_rejection.hpp>
#include "outlier_rejection-rb.hpp"

using namespace Rice;

extern "C"
void Init_OutlierRejection()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabIOutlierRejector = define_class_under<cv::videostab::IOutlierRejector>(rb_mCvVideostab, "IOutlierRejector").
    define_method<void(cv::videostab::IOutlierRejector::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("process", &cv::videostab::IOutlierRejector::process);
  
  Class rb_cCvVideostabNullOutlierRejector = define_class_under<cv::videostab::NullOutlierRejector, cv::videostab::IOutlierRejector>(rb_mCvVideostab, "NullOutlierRejector").
    define_method<void(cv::videostab::NullOutlierRejector::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("process", &cv::videostab::NullOutlierRejector::process);
  
  Class rb_cCvVideostabTranslationBasedLocalOutlierRejector = define_class_under<cv::videostab::TranslationBasedLocalOutlierRejector, cv::videostab::IOutlierRejector>(rb_mCvVideostab, "TranslationBasedLocalOutlierRejector").
    define_constructor(Constructor<cv::videostab::TranslationBasedLocalOutlierRejector>()).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::Size_<int>)>("set_cell_size", &cv::videostab::TranslationBasedLocalOutlierRejector::setCellSize).
    define_method<cv::Size_<int>(cv::videostab::TranslationBasedLocalOutlierRejector::*)() const>("cell_size", &cv::videostab::TranslationBasedLocalOutlierRejector::cellSize).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::videostab::RansacParams)>("set_ransac_params", &cv::videostab::TranslationBasedLocalOutlierRejector::setRansacParams).
    define_method<cv::videostab::RansacParams(cv::videostab::TranslationBasedLocalOutlierRejector::*)() const>("ransac_params", &cv::videostab::TranslationBasedLocalOutlierRejector::ransacParams).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("process", &cv::videostab::TranslationBasedLocalOutlierRejector::process);
}