#include <opencv2/ximgproc/sparse_match_interpolator.hpp>
#include "sparse_match_interpolator-rb.hpp"

using namespace Rice;

extern "C"
void Init_SparseMatchInterpolator()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocSparseMatchInterpolator = define_class_under<cv::ximgproc::SparseMatchInterpolator, cv::Algorithm>(rb_mCvXimgproc, "SparseMatchInterpolator").
    define_method<void(cv::ximgproc::SparseMatchInterpolator::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("interpolate", &cv::ximgproc::SparseMatchInterpolator::interpolate);
  
  Class rb_cCvXimgprocEdgeAwareInterpolator = define_class_under<cv::ximgproc::EdgeAwareInterpolator, cv::ximgproc::SparseMatchInterpolator>(rb_mCvXimgproc, "EdgeAwareInterpolator").
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(const cv::Mat&)>("set_cost_map", &cv::ximgproc::EdgeAwareInterpolator::setCostMap).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(int)>("set_k", &cv::ximgproc::EdgeAwareInterpolator::setK).
    define_method<int(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_k", &cv::ximgproc::EdgeAwareInterpolator::getK).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_sigma", &cv::ximgproc::EdgeAwareInterpolator::setSigma).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_sigma", &cv::ximgproc::EdgeAwareInterpolator::getSigma).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_lambda", &cv::ximgproc::EdgeAwareInterpolator::setLambda).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_lambda", &cv::ximgproc::EdgeAwareInterpolator::getLambda).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(bool)>("set_use_post_processing", &cv::ximgproc::EdgeAwareInterpolator::setUsePostProcessing).
    define_method<bool(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_use_post_processing", &cv::ximgproc::EdgeAwareInterpolator::getUsePostProcessing).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_fgs_lambda", &cv::ximgproc::EdgeAwareInterpolator::setFGSLambda).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_fgs_lambda", &cv::ximgproc::EdgeAwareInterpolator::getFGSLambda).
    define_method<void(cv::ximgproc::EdgeAwareInterpolator::*)(float)>("set_fgs_sigma", &cv::ximgproc::EdgeAwareInterpolator::setFGSSigma).
    define_method<float(cv::ximgproc::EdgeAwareInterpolator::*)()>("get_fgs_sigma", &cv::ximgproc::EdgeAwareInterpolator::getFGSSigma);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::EdgeAwareInterpolator>(*)()>("create_edge_aware_interpolator", &cv::ximgproc::createEdgeAwareInterpolator);
  
  Class rb_cCvXimgprocRICInterpolator = define_class_under<cv::ximgproc::RICInterpolator, cv::ximgproc::SparseMatchInterpolator>(rb_mCvXimgproc, "RICInterpolator").
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_k", &cv::ximgproc::RICInterpolator::setK).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_k", &cv::ximgproc::RICInterpolator::getK).
    define_method<void(cv::ximgproc::RICInterpolator::*)(const cv::Mat&)>("set_cost_map", &cv::ximgproc::RICInterpolator::setCostMap).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_size", &cv::ximgproc::RICInterpolator::setSuperpixelSize).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_size", &cv::ximgproc::RICInterpolator::getSuperpixelSize).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_nn_cnt", &cv::ximgproc::RICInterpolator::setSuperpixelNNCnt).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_nn_cnt", &cv::ximgproc::RICInterpolator::getSuperpixelNNCnt).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_superpixel_ruler", &cv::ximgproc::RICInterpolator::setSuperpixelRuler).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_ruler", &cv::ximgproc::RICInterpolator::getSuperpixelRuler).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_superpixel_mode", &cv::ximgproc::RICInterpolator::setSuperpixelMode).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_superpixel_mode", &cv::ximgproc::RICInterpolator::getSuperpixelMode).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_alpha", &cv::ximgproc::RICInterpolator::setAlpha).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_alpha", &cv::ximgproc::RICInterpolator::getAlpha).
    define_method<void(cv::ximgproc::RICInterpolator::*)(int)>("set_model_iter", &cv::ximgproc::RICInterpolator::setModelIter).
    define_method<int(cv::ximgproc::RICInterpolator::*)() const>("get_model_iter", &cv::ximgproc::RICInterpolator::getModelIter).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_refine_models", &cv::ximgproc::RICInterpolator::setRefineModels).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_refine_models", &cv::ximgproc::RICInterpolator::getRefineModels).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_max_flow", &cv::ximgproc::RICInterpolator::setMaxFlow).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_max_flow", &cv::ximgproc::RICInterpolator::getMaxFlow).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_use_variational_refinement", &cv::ximgproc::RICInterpolator::setUseVariationalRefinement).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_use_variational_refinement", &cv::ximgproc::RICInterpolator::getUseVariationalRefinement).
    define_method<void(cv::ximgproc::RICInterpolator::*)(bool)>("set_use_global_smoother_filter", &cv::ximgproc::RICInterpolator::setUseGlobalSmootherFilter).
    define_method<bool(cv::ximgproc::RICInterpolator::*)() const>("get_use_global_smoother_filter", &cv::ximgproc::RICInterpolator::getUseGlobalSmootherFilter).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_fgs_lambda", &cv::ximgproc::RICInterpolator::setFGSLambda).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_fgs_lambda", &cv::ximgproc::RICInterpolator::getFGSLambda).
    define_method<void(cv::ximgproc::RICInterpolator::*)(float)>("set_fgs_sigma", &cv::ximgproc::RICInterpolator::setFGSSigma).
    define_method<float(cv::ximgproc::RICInterpolator::*)() const>("get_fgs_sigma", &cv::ximgproc::RICInterpolator::getFGSSigma);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::RICInterpolator>(*)()>("create_ric_interpolator", &cv::ximgproc::createRICInterpolator);
}