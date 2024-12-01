#include <opencv2/optflow.hpp>
#include "optflow-rb.hpp"

using namespace Rice;

extern "C"
void Init_Optflow()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");
  
  rb_mCvOptflow.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("calc_optical_flow_sf", &cv::optflow::calcOpticalFlowSF);
  
  rb_mCvOptflow.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int, int, double, double, int, double, double, double, int, double, double, double)>("calc_optical_flow_sf", &cv::optflow::calcOpticalFlowSF);
  
  rb_mCvOptflow.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, int, float, bool, float, float)>("calc_optical_flow_sparse_to_dense", &cv::optflow::calcOpticalFlowSparseToDense);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_deep_flow", &cv::optflow::createOptFlow_DeepFlow);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_simple_flow", &cv::optflow::createOptFlow_SimpleFlow);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_farneback", &cv::optflow::createOptFlow_Farneback);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_sparse_to_dense", &cv::optflow::createOptFlow_SparseToDense);
  
  Class rb_cCvOptflowDualTVL1OpticalFlow = define_class_under<cv::optflow::DualTVL1OpticalFlow, cv::DenseOpticalFlow>(rb_mCvOptflow, "DualTVL1OpticalFlow").
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_tau", &cv::optflow::DualTVL1OpticalFlow::getTau).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_tau", &cv::optflow::DualTVL1OpticalFlow::setTau).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_lambda", &cv::optflow::DualTVL1OpticalFlow::getLambda).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_lambda", &cv::optflow::DualTVL1OpticalFlow::setLambda).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_theta", &cv::optflow::DualTVL1OpticalFlow::getTheta).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_theta", &cv::optflow::DualTVL1OpticalFlow::setTheta).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_gamma", &cv::optflow::DualTVL1OpticalFlow::getGamma).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_gamma", &cv::optflow::DualTVL1OpticalFlow::setGamma).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_scales_number", &cv::optflow::DualTVL1OpticalFlow::getScalesNumber).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_scales_number", &cv::optflow::DualTVL1OpticalFlow::setScalesNumber).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_warpings_number", &cv::optflow::DualTVL1OpticalFlow::getWarpingsNumber).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_warpings_number", &cv::optflow::DualTVL1OpticalFlow::setWarpingsNumber).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_epsilon", &cv::optflow::DualTVL1OpticalFlow::getEpsilon).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_epsilon", &cv::optflow::DualTVL1OpticalFlow::setEpsilon).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_inner_iterations", &cv::optflow::DualTVL1OpticalFlow::getInnerIterations).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_inner_iterations", &cv::optflow::DualTVL1OpticalFlow::setInnerIterations).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_outer_iterations", &cv::optflow::DualTVL1OpticalFlow::getOuterIterations).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_outer_iterations", &cv::optflow::DualTVL1OpticalFlow::setOuterIterations).
    define_method<bool(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_use_initial_flow", &cv::optflow::DualTVL1OpticalFlow::getUseInitialFlow).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(bool)>("set_use_initial_flow", &cv::optflow::DualTVL1OpticalFlow::setUseInitialFlow).
    define_method<double(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_scale_step", &cv::optflow::DualTVL1OpticalFlow::getScaleStep).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(double)>("set_scale_step", &cv::optflow::DualTVL1OpticalFlow::setScaleStep).
    define_method<int(cv::optflow::DualTVL1OpticalFlow::*)() const>("get_median_filtering", &cv::optflow::DualTVL1OpticalFlow::getMedianFiltering).
    define_method<void(cv::optflow::DualTVL1OpticalFlow::*)(int)>("set_median_filtering", &cv::optflow::DualTVL1OpticalFlow::setMedianFiltering).
    define_singleton_function<cv::Ptr<cv::optflow::DualTVL1OpticalFlow>(*)(double, double, double, int, int, double, int, int, double, double, int, bool)>("create", &cv::optflow::DualTVL1OpticalFlow::create);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::optflow::DualTVL1OpticalFlow>(*)()>("create_opt_flow_dual_tvl1", &cv::optflow::createOptFlow_DualTVL1);
}