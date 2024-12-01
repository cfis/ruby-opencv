#include <opencv2/shape/hist_cost.hpp>
#include "hist_cost-rb.hpp"

using namespace Rice;

extern "C"
void Init_HistCost()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvHistogramCostExtractor = define_class_under<cv::HistogramCostExtractor, cv::Algorithm>(rb_mCv, "HistogramCostExtractor").
    define_method<void(cv::HistogramCostExtractor::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("build_cost_matrix", &cv::HistogramCostExtractor::buildCostMatrix).
    define_method<void(cv::HistogramCostExtractor::*)(int)>("set_n_dummies", &cv::HistogramCostExtractor::setNDummies).
    define_method<int(cv::HistogramCostExtractor::*)() const>("get_n_dummies", &cv::HistogramCostExtractor::getNDummies).
    define_method<void(cv::HistogramCostExtractor::*)(float)>("set_default_cost", &cv::HistogramCostExtractor::setDefaultCost).
    define_method<float(cv::HistogramCostExtractor::*)() const>("get_default_cost", &cv::HistogramCostExtractor::getDefaultCost);
  
  Class rb_cCvNormHistogramCostExtractor = define_class_under<cv::NormHistogramCostExtractor, cv::HistogramCostExtractor>(rb_mCv, "NormHistogramCostExtractor").
    define_method<void(cv::NormHistogramCostExtractor::*)(int)>("set_norm_flag", &cv::NormHistogramCostExtractor::setNormFlag).
    define_method<int(cv::NormHistogramCostExtractor::*)() const>("get_norm_flag", &cv::NormHistogramCostExtractor::getNormFlag);
  
  rb_mCv.define_module_function<cv::Ptr<cv::HistogramCostExtractor>(*)(int, int, float)>("create_norm_histogram_cost_extractor", &cv::createNormHistogramCostExtractor);
  
  Class rb_cCvEMDHistogramCostExtractor = define_class_under<cv::EMDHistogramCostExtractor, cv::HistogramCostExtractor>(rb_mCv, "EMDHistogramCostExtractor").
    define_method<void(cv::EMDHistogramCostExtractor::*)(int)>("set_norm_flag", &cv::EMDHistogramCostExtractor::setNormFlag).
    define_method<int(cv::EMDHistogramCostExtractor::*)() const>("get_norm_flag", &cv::EMDHistogramCostExtractor::getNormFlag);
  
  rb_mCv.define_module_function<cv::Ptr<cv::HistogramCostExtractor>(*)(int, int, float)>("create_emd_histogram_cost_extractor", &cv::createEMDHistogramCostExtractor);
  
  Class rb_cCvChiHistogramCostExtractor = define_class_under<cv::ChiHistogramCostExtractor, cv::HistogramCostExtractor>(rb_mCv, "ChiHistogramCostExtractor");
  
  
  rb_mCv.define_module_function<cv::Ptr<cv::HistogramCostExtractor>(*)(int, float)>("create_chi_histogram_cost_extractor", &cv::createChiHistogramCostExtractor);
  
  Class rb_cCvEMDL1HistogramCostExtractor = define_class_under<cv::EMDL1HistogramCostExtractor, cv::HistogramCostExtractor>(rb_mCv, "EMDL1HistogramCostExtractor");
  
  
  rb_mCv.define_module_function<cv::Ptr<cv::HistogramCostExtractor>(*)(int, float)>("create_emdl1_histogram_cost_extractor", &cv::createEMDL1HistogramCostExtractor);
}