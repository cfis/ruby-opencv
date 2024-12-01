#include <opencv2/ximgproc/edge_filter.hpp>
#include "edge_filter-rb.hpp"

using namespace Rice;

extern "C"
void Init_EdgeFilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Enum<cv::ximgproc::EdgeAwareFiltersList> rb_cCvXimgprocEdgeAwareFiltersList = define_enum<cv::ximgproc::EdgeAwareFiltersList>("EdgeAwareFiltersList", rb_mCvXimgproc).
    define_value("DTF_NC", cv::ximgproc::EdgeAwareFiltersList::DTF_NC).
    define_value("DTF_IC", cv::ximgproc::EdgeAwareFiltersList::DTF_IC).
    define_value("DTF_RF", cv::ximgproc::EdgeAwareFiltersList::DTF_RF).
    define_value("GUIDED_FILTER", cv::ximgproc::EdgeAwareFiltersList::GUIDED_FILTER).
    define_value("AM_FILTER", cv::ximgproc::EdgeAwareFiltersList::AM_FILTER);
  
  Class rb_cCvXimgprocDTFilter = define_class_under<cv::ximgproc::DTFilter, cv::Algorithm>(rb_mCvXimgproc, "DTFilter").
    define_method<void(cv::ximgproc::DTFilter::*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("filter", &cv::ximgproc::DTFilter::filter);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::DTFilter>(*)(const cv::_InputArray &, double, double, int, int)>("create_dt_filter", &cv::ximgproc::createDTFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, double, int, int)>("dt_filter", &cv::ximgproc::dtFilter);
  
  Class rb_cCvXimgprocGuidedFilter = define_class_under<cv::ximgproc::GuidedFilter, cv::Algorithm>(rb_mCvXimgproc, "GuidedFilter").
    define_method<void(cv::ximgproc::GuidedFilter::*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("filter", &cv::ximgproc::GuidedFilter::filter);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::GuidedFilter>(*)(const cv::_InputArray &, int, double)>("create_guided_filter", &cv::ximgproc::createGuidedFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double, int)>("guided_filter", &cv::ximgproc::guidedFilter);
  
  Class rb_cCvXimgprocAdaptiveManifoldFilter = define_class_under<cv::ximgproc::AdaptiveManifoldFilter, cv::Algorithm>(rb_mCvXimgproc, "AdaptiveManifoldFilter").
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("filter", &cv::ximgproc::AdaptiveManifoldFilter::filter).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)()>("collect_garbage", &cv::ximgproc::AdaptiveManifoldFilter::collectGarbage).
    define_singleton_function<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(*)()>("create", &cv::ximgproc::AdaptiveManifoldFilter::create).
    define_method<double(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_sigma_s", &cv::ximgproc::AdaptiveManifoldFilter::getSigmaS).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(double)>("set_sigma_s", &cv::ximgproc::AdaptiveManifoldFilter::setSigmaS).
    define_method<double(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_sigma_r", &cv::ximgproc::AdaptiveManifoldFilter::getSigmaR).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(double)>("set_sigma_r", &cv::ximgproc::AdaptiveManifoldFilter::setSigmaR).
    define_method<int(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_tree_height", &cv::ximgproc::AdaptiveManifoldFilter::getTreeHeight).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(int)>("set_tree_height", &cv::ximgproc::AdaptiveManifoldFilter::setTreeHeight).
    define_method<int(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_pca_iterations", &cv::ximgproc::AdaptiveManifoldFilter::getPCAIterations).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(int)>("set_pca_iterations", &cv::ximgproc::AdaptiveManifoldFilter::setPCAIterations).
    define_method<bool(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_adjust_outliers", &cv::ximgproc::AdaptiveManifoldFilter::getAdjustOutliers).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(bool)>("set_adjust_outliers", &cv::ximgproc::AdaptiveManifoldFilter::setAdjustOutliers).
    define_method<bool(cv::ximgproc::AdaptiveManifoldFilter::*)() const>("get_use_rng", &cv::ximgproc::AdaptiveManifoldFilter::getUseRNG).
    define_method<void(cv::ximgproc::AdaptiveManifoldFilter::*)(bool)>("set_use_rng", &cv::ximgproc::AdaptiveManifoldFilter::setUseRNG);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::AdaptiveManifoldFilter>(*)(double, double, bool)>("create_am_filter", &cv::ximgproc::createAMFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, double, bool)>("am_filter", &cv::ximgproc::amFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double, double, int)>("joint_bilateral_filter", &cv::ximgproc::jointBilateralFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, double, double)>("bilateral_texture_filter", &cv::ximgproc::bilateralTextureFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, int, int)>("rolling_guidance_filter", &cv::ximgproc::rollingGuidanceFilter);
  
  Class rb_cCvXimgprocFastBilateralSolverFilter = define_class_under<cv::ximgproc::FastBilateralSolverFilter, cv::Algorithm>(rb_mCvXimgproc, "FastBilateralSolverFilter").
    define_method<void(cv::ximgproc::FastBilateralSolverFilter::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("filter", &cv::ximgproc::FastBilateralSolverFilter::filter);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastBilateralSolverFilter>(*)(const cv::_InputArray &, double, double, double, double, int, double)>("create_fast_bilateral_solver_filter", &cv::ximgproc::createFastBilateralSolverFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, double, double, double, int, double)>("fast_bilateral_solver_filter", &cv::ximgproc::fastBilateralSolverFilter);
  
  Class rb_cCvXimgprocFastGlobalSmootherFilter = define_class_under<cv::ximgproc::FastGlobalSmootherFilter, cv::Algorithm>(rb_mCvXimgproc, "FastGlobalSmootherFilter").
    define_method<void(cv::ximgproc::FastGlobalSmootherFilter::*)(const cv::_InputArray &, const cv::_OutputArray &)>("filter", &cv::ximgproc::FastGlobalSmootherFilter::filter);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::FastGlobalSmootherFilter>(*)(const cv::_InputArray &, double, double, double, int)>("create_fast_global_smoother_filter", &cv::ximgproc::createFastGlobalSmootherFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, double, double, int)>("fast_global_smoother_filter", &cv::ximgproc::fastGlobalSmootherFilter);
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("l0_smooth", &cv::ximgproc::l0Smooth);
}