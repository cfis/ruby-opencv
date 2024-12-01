#include <opencv2/optflow/rlofflow.hpp>
#include "rlofflow-rb.hpp"

using namespace Rice;

extern "C"
void Init_Rlofflow()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");
  
  Enum<cv::optflow::SupportRegionType> rb_cCvOptflowSupportRegionType = define_enum<cv::optflow::SupportRegionType>("SupportRegionType", rb_mCvOptflow).
    define_value("SR_FIXED", cv::optflow::SupportRegionType::SR_FIXED).
    define_value("SR_CROSS", cv::optflow::SupportRegionType::SR_CROSS);
  
  Enum<cv::optflow::SolverType> rb_cCvOptflowSolverType = define_enum<cv::optflow::SolverType>("SolverType", rb_mCvOptflow).
    define_value("ST_STANDART", cv::optflow::SolverType::ST_STANDART).
    define_value("ST_BILINEAR", cv::optflow::SolverType::ST_BILINEAR);
  
  Enum<cv::optflow::InterpolationType> rb_cCvOptflowInterpolationType = define_enum<cv::optflow::InterpolationType>("InterpolationType", rb_mCvOptflow).
    define_value("INTERP_GEO", cv::optflow::InterpolationType::INTERP_GEO).
    define_value("INTERP_EPIC", cv::optflow::InterpolationType::INTERP_EPIC).
    define_value("INTERP_RIC", cv::optflow::InterpolationType::INTERP_RIC);
  
  Class rb_cCvOptflowRLOFOpticalFlowParameter = define_class_under<cv::optflow::RLOFOpticalFlowParameter>(rb_mCvOptflow, "RLOFOpticalFlowParameter").
    define_constructor(Constructor<cv::optflow::RLOFOpticalFlowParameter>()).
    define_attr("solver_type", &cv::optflow::RLOFOpticalFlowParameter::solverType).
    define_attr("support_region_type", &cv::optflow::RLOFOpticalFlowParameter::supportRegionType).
    define_attr("norm_sigma0", &cv::optflow::RLOFOpticalFlowParameter::normSigma0).
    define_attr("norm_sigma1", &cv::optflow::RLOFOpticalFlowParameter::normSigma1).
    define_attr("small_win_size", &cv::optflow::RLOFOpticalFlowParameter::smallWinSize).
    define_attr("large_win_size", &cv::optflow::RLOFOpticalFlowParameter::largeWinSize).
    define_attr("cross_segmentation_threshold", &cv::optflow::RLOFOpticalFlowParameter::crossSegmentationThreshold).
    define_attr("max_level", &cv::optflow::RLOFOpticalFlowParameter::maxLevel).
    define_attr("use_initial_flow", &cv::optflow::RLOFOpticalFlowParameter::useInitialFlow).
    define_attr("use_illumination_model", &cv::optflow::RLOFOpticalFlowParameter::useIlluminationModel).
    define_attr("use_global_motion_prior", &cv::optflow::RLOFOpticalFlowParameter::useGlobalMotionPrior).
    define_attr("max_iteration", &cv::optflow::RLOFOpticalFlowParameter::maxIteration).
    define_attr("min_eigen_value", &cv::optflow::RLOFOpticalFlowParameter::minEigenValue).
    define_attr("global_motion_ransac_threshold", &cv::optflow::RLOFOpticalFlowParameter::globalMotionRansacThreshold).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(bool)>("set_use_m_estimator", &cv::optflow::RLOFOpticalFlowParameter::setUseMEstimator).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(cv::optflow::SolverType)>("set_solver_type", &cv::optflow::RLOFOpticalFlowParameter::setSolverType).
    define_method<cv::optflow::SolverType(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_solver_type", &cv::optflow::RLOFOpticalFlowParameter::getSolverType).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(cv::optflow::SupportRegionType)>("set_support_region_type", &cv::optflow::RLOFOpticalFlowParameter::setSupportRegionType).
    define_method<cv::optflow::SupportRegionType(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_support_region_type", &cv::optflow::RLOFOpticalFlowParameter::getSupportRegionType).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(float)>("set_norm_sigma0", &cv::optflow::RLOFOpticalFlowParameter::setNormSigma0).
    define_method<float(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_norm_sigma0", &cv::optflow::RLOFOpticalFlowParameter::getNormSigma0).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(float)>("set_norm_sigma1", &cv::optflow::RLOFOpticalFlowParameter::setNormSigma1).
    define_method<float(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_norm_sigma1", &cv::optflow::RLOFOpticalFlowParameter::getNormSigma1).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(int)>("set_small_win_size", &cv::optflow::RLOFOpticalFlowParameter::setSmallWinSize).
    define_method<int(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_small_win_size", &cv::optflow::RLOFOpticalFlowParameter::getSmallWinSize).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(int)>("set_large_win_size", &cv::optflow::RLOFOpticalFlowParameter::setLargeWinSize).
    define_method<int(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_large_win_size", &cv::optflow::RLOFOpticalFlowParameter::getLargeWinSize).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(int)>("set_cross_segmentation_threshold", &cv::optflow::RLOFOpticalFlowParameter::setCrossSegmentationThreshold).
    define_method<int(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_cross_segmentation_threshold", &cv::optflow::RLOFOpticalFlowParameter::getCrossSegmentationThreshold).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(int)>("set_max_level", &cv::optflow::RLOFOpticalFlowParameter::setMaxLevel).
    define_method<int(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_max_level", &cv::optflow::RLOFOpticalFlowParameter::getMaxLevel).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(bool)>("set_use_initial_flow", &cv::optflow::RLOFOpticalFlowParameter::setUseInitialFlow).
    define_method<bool(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_use_initial_flow", &cv::optflow::RLOFOpticalFlowParameter::getUseInitialFlow).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(bool)>("set_use_illumination_model", &cv::optflow::RLOFOpticalFlowParameter::setUseIlluminationModel).
    define_method<bool(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_use_illumination_model", &cv::optflow::RLOFOpticalFlowParameter::getUseIlluminationModel).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(bool)>("set_use_global_motion_prior", &cv::optflow::RLOFOpticalFlowParameter::setUseGlobalMotionPrior).
    define_method<bool(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_use_global_motion_prior", &cv::optflow::RLOFOpticalFlowParameter::getUseGlobalMotionPrior).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(int)>("set_max_iteration", &cv::optflow::RLOFOpticalFlowParameter::setMaxIteration).
    define_method<int(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_max_iteration", &cv::optflow::RLOFOpticalFlowParameter::getMaxIteration).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(float)>("set_min_eigen_value", &cv::optflow::RLOFOpticalFlowParameter::setMinEigenValue).
    define_method<float(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_min_eigen_value", &cv::optflow::RLOFOpticalFlowParameter::getMinEigenValue).
    define_method<void(cv::optflow::RLOFOpticalFlowParameter::*)(float)>("set_global_motion_ransac_threshold", &cv::optflow::RLOFOpticalFlowParameter::setGlobalMotionRansacThreshold).
    define_method<float(cv::optflow::RLOFOpticalFlowParameter::*)() const>("get_global_motion_ransac_threshold", &cv::optflow::RLOFOpticalFlowParameter::getGlobalMotionRansacThreshold).
    define_singleton_function<cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>(*)()>("create", &cv::optflow::RLOFOpticalFlowParameter::create);
  
  Class rb_cCvOptflowDenseRLOFOpticalFlow = define_class_under<cv::optflow::DenseRLOFOpticalFlow, cv::DenseOpticalFlow>(rb_mCvOptflow, "DenseRLOFOpticalFlow").
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>)>("set_rlof_optical_flow_parameter", &cv::optflow::DenseRLOFOpticalFlow::setRLOFOpticalFlowParameter).
    define_method<cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_rlof_optical_flow_parameter", &cv::optflow::DenseRLOFOpticalFlow::getRLOFOpticalFlowParameter).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(float)>("set_forward_backward", &cv::optflow::DenseRLOFOpticalFlow::setForwardBackward).
    define_method<float(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_forward_backward", &cv::optflow::DenseRLOFOpticalFlow::getForwardBackward).
    define_method<cv::Size_<int>(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_grid_step", &cv::optflow::DenseRLOFOpticalFlow::getGridStep).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(cv::Size_<int>)>("set_grid_step", &cv::optflow::DenseRLOFOpticalFlow::setGridStep).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(cv::optflow::InterpolationType)>("set_interpolation", &cv::optflow::DenseRLOFOpticalFlow::setInterpolation).
    define_method<cv::optflow::InterpolationType(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_interpolation", &cv::optflow::DenseRLOFOpticalFlow::getInterpolation).
    define_method<int(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_epick", &cv::optflow::DenseRLOFOpticalFlow::getEPICK).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(int)>("set_epick", &cv::optflow::DenseRLOFOpticalFlow::setEPICK).
    define_method<float(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_epic_sigma", &cv::optflow::DenseRLOFOpticalFlow::getEPICSigma).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(float)>("set_epic_sigma", &cv::optflow::DenseRLOFOpticalFlow::setEPICSigma).
    define_method<float(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_epic_lambda", &cv::optflow::DenseRLOFOpticalFlow::getEPICLambda).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(float)>("set_epic_lambda", &cv::optflow::DenseRLOFOpticalFlow::setEPICLambda).
    define_method<float(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_fgs_lambda", &cv::optflow::DenseRLOFOpticalFlow::getFgsLambda).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(float)>("set_fgs_lambda", &cv::optflow::DenseRLOFOpticalFlow::setFgsLambda).
    define_method<float(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_fgs_sigma", &cv::optflow::DenseRLOFOpticalFlow::getFgsSigma).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(float)>("set_fgs_sigma", &cv::optflow::DenseRLOFOpticalFlow::setFgsSigma).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(bool)>("set_use_post_proc", &cv::optflow::DenseRLOFOpticalFlow::setUsePostProc).
    define_method<bool(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_use_post_proc", &cv::optflow::DenseRLOFOpticalFlow::getUsePostProc).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(bool)>("set_use_variational_refinement", &cv::optflow::DenseRLOFOpticalFlow::setUseVariationalRefinement).
    define_method<bool(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_use_variational_refinement", &cv::optflow::DenseRLOFOpticalFlow::getUseVariationalRefinement).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(int)>("set_ricsp_size", &cv::optflow::DenseRLOFOpticalFlow::setRICSPSize).
    define_method<int(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_ricsp_size", &cv::optflow::DenseRLOFOpticalFlow::getRICSPSize).
    define_method<void(cv::optflow::DenseRLOFOpticalFlow::*)(int)>("set_ricslic_type", &cv::optflow::DenseRLOFOpticalFlow::setRICSLICType).
    define_method<int(cv::optflow::DenseRLOFOpticalFlow::*)() const>("get_ricslic_type", &cv::optflow::DenseRLOFOpticalFlow::getRICSLICType).
    define_singleton_function<cv::Ptr<cv::optflow::DenseRLOFOpticalFlow>(*)(cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>, float, cv::Size_<int>, cv::optflow::InterpolationType, int, float, float, int, int, bool, float, float, bool)>("create", &cv::optflow::DenseRLOFOpticalFlow::create);
  
  Class rb_cCvOptflowSparseRLOFOpticalFlow = define_class_under<cv::optflow::SparseRLOFOpticalFlow, cv::SparseOpticalFlow>(rb_mCvOptflow, "SparseRLOFOpticalFlow").
    define_method<void(cv::optflow::SparseRLOFOpticalFlow::*)(cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>)>("set_rlof_optical_flow_parameter", &cv::optflow::SparseRLOFOpticalFlow::setRLOFOpticalFlowParameter).
    define_method<cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>(cv::optflow::SparseRLOFOpticalFlow::*)() const>("get_rlof_optical_flow_parameter", &cv::optflow::SparseRLOFOpticalFlow::getRLOFOpticalFlowParameter).
    define_method<void(cv::optflow::SparseRLOFOpticalFlow::*)(float)>("set_forward_backward", &cv::optflow::SparseRLOFOpticalFlow::setForwardBackward).
    define_method<float(cv::optflow::SparseRLOFOpticalFlow::*)() const>("get_forward_backward", &cv::optflow::SparseRLOFOpticalFlow::getForwardBackward).
    define_singleton_function<cv::Ptr<cv::optflow::SparseRLOFOpticalFlow>(*)(cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>, float)>("create", &cv::optflow::SparseRLOFOpticalFlow::create);
  
  rb_mCvOptflow.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>, float, cv::Size_<int>, cv::optflow::InterpolationType, int, float, float, int, int, bool, float, float, bool)>("calc_optical_flow_dense_rlof", &cv::optflow::calcOpticalFlowDenseRLOF);
  
  rb_mCvOptflow.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::Ptr<cv::optflow::RLOFOpticalFlowParameter>, float)>("calc_optical_flow_sparse_rlof", &cv::optflow::calcOpticalFlowSparseRLOF);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_dense_rlof", &cv::optflow::createOptFlow_DenseRLOF);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::SparseOpticalFlow>(*)()>("create_opt_flow_sparse_rlof", &cv::optflow::createOptFlow_SparseRLOF);
}