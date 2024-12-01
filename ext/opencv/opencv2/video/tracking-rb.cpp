#include <opencv2/video/tracking.hpp>
#include "tracking-rb.hpp"

using namespace Rice;

extern "C"
void Init_Tracking()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<cv::RotatedRect(*)(const cv::_InputArray &, cv::Rect_<int>&, cv::TermCriteria)>("cam_shift", &cv::CamShift);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, cv::Rect_<int>&, cv::TermCriteria)>("mean_shift", &cv::meanShift);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, int, bool, int, int, bool)>("build_optical_flow_pyramid", &cv::buildOpticalFlowPyramid);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::Size_<int>, int, cv::TermCriteria, int, double)>("calc_optical_flow_pyr_lk", &cv::calcOpticalFlowPyrLK);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, double, int, int, int, int, double, int)>("calc_optical_flow_farneback", &cv::calcOpticalFlowFarneback);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, bool)>("estimate_rigid_transform", &cv::estimateRigidTransform);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("compute_ecc", &cv::computeECC);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, int, cv::TermCriteria, const cv::_InputArray &, int)>("find_transform_ecc", &cv::findTransformECC);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, int, cv::TermCriteria, const cv::_InputArray &)>("find_transform_ecc", &cv::findTransformECC);
  
  Class rb_cCvKalmanFilter = define_class_under<cv::KalmanFilter>(rb_mCv, "KalmanFilter").
    define_constructor(Constructor<cv::KalmanFilter>()).
    define_constructor(Constructor<cv::KalmanFilter, int, int, int, int>()).
    define_method<void(cv::KalmanFilter::*)(int, int, int, int)>("init", &cv::KalmanFilter::init).
    define_method<const cv::Mat&(cv::KalmanFilter::*)(const cv::Mat&)>("predict", &cv::KalmanFilter::predict).
    define_method<const cv::Mat&(cv::KalmanFilter::*)(const cv::Mat&)>("correct", &cv::KalmanFilter::correct).
    define_attr("state_pre", &cv::KalmanFilter::statePre).
    define_attr("state_post", &cv::KalmanFilter::statePost).
    define_attr("transition_matrix", &cv::KalmanFilter::transitionMatrix).
    define_attr("control_matrix", &cv::KalmanFilter::controlMatrix).
    define_attr("measurement_matrix", &cv::KalmanFilter::measurementMatrix).
    define_attr("process_noise_cov", &cv::KalmanFilter::processNoiseCov).
    define_attr("measurement_noise_cov", &cv::KalmanFilter::measurementNoiseCov).
    define_attr("error_cov_pre", &cv::KalmanFilter::errorCovPre).
    define_attr("gain", &cv::KalmanFilter::gain).
    define_attr("error_cov_post", &cv::KalmanFilter::errorCovPost).
    define_attr("temp1", &cv::KalmanFilter::temp1).
    define_attr("temp2", &cv::KalmanFilter::temp2).
    define_attr("temp3", &cv::KalmanFilter::temp3).
    define_attr("temp4", &cv::KalmanFilter::temp4).
    define_attr("temp5", &cv::KalmanFilter::temp5);
  
  rb_mCv.define_module_function<cv::Mat(*)(const std::basic_string<char>&)>("read_optical_flow", &cv::readOpticalFlow);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&, const cv::_InputArray &)>("write_optical_flow", &cv::writeOpticalFlow);
  
  Class rb_cCvDenseOpticalFlow = define_class_under<cv::DenseOpticalFlow, cv::Algorithm>(rb_mCv, "DenseOpticalFlow").
    define_method<void(cv::DenseOpticalFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &)>("calc", &cv::DenseOpticalFlow::calc).
    define_method<void(cv::DenseOpticalFlow::*)()>("collect_garbage", &cv::DenseOpticalFlow::collectGarbage);
  
  Class rb_cCvSparseOpticalFlow = define_class_under<cv::SparseOpticalFlow, cv::Algorithm>(rb_mCv, "SparseOpticalFlow").
    define_method<void(cv::SparseOpticalFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("calc", &cv::SparseOpticalFlow::calc);
  
  Class rb_cCvFarnebackOpticalFlow = define_class_under<cv::FarnebackOpticalFlow, cv::DenseOpticalFlow>(rb_mCv, "FarnebackOpticalFlow").
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_num_levels", &cv::FarnebackOpticalFlow::getNumLevels).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_num_levels", &cv::FarnebackOpticalFlow::setNumLevels).
    define_method<double(cv::FarnebackOpticalFlow::*)() const>("get_pyr_scale", &cv::FarnebackOpticalFlow::getPyrScale).
    define_method<void(cv::FarnebackOpticalFlow::*)(double)>("set_pyr_scale", &cv::FarnebackOpticalFlow::setPyrScale).
    define_method<bool(cv::FarnebackOpticalFlow::*)() const>("get_fast_pyramids", &cv::FarnebackOpticalFlow::getFastPyramids).
    define_method<void(cv::FarnebackOpticalFlow::*)(bool)>("set_fast_pyramids", &cv::FarnebackOpticalFlow::setFastPyramids).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_win_size", &cv::FarnebackOpticalFlow::getWinSize).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_win_size", &cv::FarnebackOpticalFlow::setWinSize).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_num_iters", &cv::FarnebackOpticalFlow::getNumIters).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_num_iters", &cv::FarnebackOpticalFlow::setNumIters).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_poly_n", &cv::FarnebackOpticalFlow::getPolyN).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_poly_n", &cv::FarnebackOpticalFlow::setPolyN).
    define_method<double(cv::FarnebackOpticalFlow::*)() const>("get_poly_sigma", &cv::FarnebackOpticalFlow::getPolySigma).
    define_method<void(cv::FarnebackOpticalFlow::*)(double)>("set_poly_sigma", &cv::FarnebackOpticalFlow::setPolySigma).
    define_method<int(cv::FarnebackOpticalFlow::*)() const>("get_flags", &cv::FarnebackOpticalFlow::getFlags).
    define_method<void(cv::FarnebackOpticalFlow::*)(int)>("set_flags", &cv::FarnebackOpticalFlow::setFlags).
    define_singleton_function<cv::Ptr<cv::FarnebackOpticalFlow>(*)(int, double, bool, int, int, int, double, int)>("create", &cv::FarnebackOpticalFlow::create);
  
  Class rb_cCvVariationalRefinement = define_class_under<cv::VariationalRefinement, cv::DenseOpticalFlow>(rb_mCv, "VariationalRefinement").
    define_method<void(cv::VariationalRefinement::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &)>("calc_uv", &cv::VariationalRefinement::calcUV).
    define_method<int(cv::VariationalRefinement::*)() const>("get_fixed_point_iterations", &cv::VariationalRefinement::getFixedPointIterations).
    define_method<void(cv::VariationalRefinement::*)(int)>("set_fixed_point_iterations", &cv::VariationalRefinement::setFixedPointIterations).
    define_method<int(cv::VariationalRefinement::*)() const>("get_sor_iterations", &cv::VariationalRefinement::getSorIterations).
    define_method<void(cv::VariationalRefinement::*)(int)>("set_sor_iterations", &cv::VariationalRefinement::setSorIterations).
    define_method<float(cv::VariationalRefinement::*)() const>("get_omega", &cv::VariationalRefinement::getOmega).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_omega", &cv::VariationalRefinement::setOmega).
    define_method<float(cv::VariationalRefinement::*)() const>("get_alpha", &cv::VariationalRefinement::getAlpha).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_alpha", &cv::VariationalRefinement::setAlpha).
    define_method<float(cv::VariationalRefinement::*)() const>("get_delta", &cv::VariationalRefinement::getDelta).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_delta", &cv::VariationalRefinement::setDelta).
    define_method<float(cv::VariationalRefinement::*)() const>("get_gamma", &cv::VariationalRefinement::getGamma).
    define_method<void(cv::VariationalRefinement::*)(float)>("set_gamma", &cv::VariationalRefinement::setGamma).
    define_singleton_function<cv::Ptr<cv::VariationalRefinement>(*)()>("create", &cv::VariationalRefinement::create);
  
  Class rb_cCvDISOpticalFlow = define_class_under<cv::DISOpticalFlow, cv::DenseOpticalFlow>(rb_mCv, "DISOpticalFlow").
    define_method<int(cv::DISOpticalFlow::*)() const>("get_finest_scale", &cv::DISOpticalFlow::getFinestScale).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_finest_scale", &cv::DISOpticalFlow::setFinestScale).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_patch_size", &cv::DISOpticalFlow::getPatchSize).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_patch_size", &cv::DISOpticalFlow::setPatchSize).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_patch_stride", &cv::DISOpticalFlow::getPatchStride).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_patch_stride", &cv::DISOpticalFlow::setPatchStride).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_gradient_descent_iterations", &cv::DISOpticalFlow::getGradientDescentIterations).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_gradient_descent_iterations", &cv::DISOpticalFlow::setGradientDescentIterations).
    define_method<int(cv::DISOpticalFlow::*)() const>("get_variational_refinement_iterations", &cv::DISOpticalFlow::getVariationalRefinementIterations).
    define_method<void(cv::DISOpticalFlow::*)(int)>("set_variational_refinement_iterations", &cv::DISOpticalFlow::setVariationalRefinementIterations).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_alpha", &cv::DISOpticalFlow::getVariationalRefinementAlpha).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_alpha", &cv::DISOpticalFlow::setVariationalRefinementAlpha).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_delta", &cv::DISOpticalFlow::getVariationalRefinementDelta).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_delta", &cv::DISOpticalFlow::setVariationalRefinementDelta).
    define_method<float(cv::DISOpticalFlow::*)() const>("get_variational_refinement_gamma", &cv::DISOpticalFlow::getVariationalRefinementGamma).
    define_method<void(cv::DISOpticalFlow::*)(float)>("set_variational_refinement_gamma", &cv::DISOpticalFlow::setVariationalRefinementGamma).
    define_method<bool(cv::DISOpticalFlow::*)() const>("get_use_mean_normalization", &cv::DISOpticalFlow::getUseMeanNormalization).
    define_method<void(cv::DISOpticalFlow::*)(bool)>("set_use_mean_normalization", &cv::DISOpticalFlow::setUseMeanNormalization).
    define_method<bool(cv::DISOpticalFlow::*)() const>("get_use_spatial_propagation", &cv::DISOpticalFlow::getUseSpatialPropagation).
    define_method<void(cv::DISOpticalFlow::*)(bool)>("set_use_spatial_propagation", &cv::DISOpticalFlow::setUseSpatialPropagation).
    define_singleton_function<cv::Ptr<cv::DISOpticalFlow>(*)(int)>("create", &cv::DISOpticalFlow::create);
  
  
  Class rb_cCvSparsePyrLKOpticalFlow = define_class_under<cv::SparsePyrLKOpticalFlow, cv::SparseOpticalFlow>(rb_mCv, "SparsePyrLKOpticalFlow").
    define_method<cv::Size_<int>(cv::SparsePyrLKOpticalFlow::*)() const>("get_win_size", &cv::SparsePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(cv::Size_<int>)>("set_win_size", &cv::SparsePyrLKOpticalFlow::setWinSize).
    define_method<int(cv::SparsePyrLKOpticalFlow::*)() const>("get_max_level", &cv::SparsePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::SparsePyrLKOpticalFlow::setMaxLevel).
    define_method<cv::TermCriteria(cv::SparsePyrLKOpticalFlow::*)() const>("get_term_criteria", &cv::SparsePyrLKOpticalFlow::getTermCriteria).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(cv::TermCriteria&)>("set_term_criteria", &cv::SparsePyrLKOpticalFlow::setTermCriteria).
    define_method<int(cv::SparsePyrLKOpticalFlow::*)() const>("get_flags", &cv::SparsePyrLKOpticalFlow::getFlags).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(int)>("set_flags", &cv::SparsePyrLKOpticalFlow::setFlags).
    define_method<double(cv::SparsePyrLKOpticalFlow::*)() const>("get_min_eig_threshold", &cv::SparsePyrLKOpticalFlow::getMinEigThreshold).
    define_method<void(cv::SparsePyrLKOpticalFlow::*)(double)>("set_min_eig_threshold", &cv::SparsePyrLKOpticalFlow::setMinEigThreshold).
    define_singleton_function<cv::Ptr<cv::SparsePyrLKOpticalFlow>(*)(cv::Size_<int>, int, cv::TermCriteria, int, double)>("create", &cv::SparsePyrLKOpticalFlow::create);
  
  Class rb_cCvTracker = define_class_under<cv::Tracker>(rb_mCv, "Tracker").
    define_constructor(Constructor<cv::Tracker>()).
    define_method<void(cv::Tracker::*)(const cv::_InputArray &, const cv::Rect_<int>&)>("init", &cv::Tracker::init).
    define_method<bool(cv::Tracker::*)(const cv::_InputArray &, cv::Rect_<int>&)>("update", &cv::Tracker::update);
  
  Class rb_cCvTrackerMIL = define_class_under<cv::TrackerMIL, cv::Tracker>(rb_mCv, "TrackerMIL").
    define_constructor(Constructor<cv::TrackerMIL>()).
    define_singleton_function<cv::Ptr<cv::TrackerMIL>(*)(const cv::TrackerMIL::Params&)>("create", &cv::TrackerMIL::create);
  
  Class rb_cCvTrackerMILParams = define_class_under<cv::TrackerMIL::Params>(rb_cCvTrackerMIL, "Params").
    define_constructor(Constructor<cv::TrackerMIL::Params>()).
    define_attr("sampler_init_in_radius", &cv::TrackerMIL::Params::samplerInitInRadius).
    define_attr("sampler_init_max_neg_num", &cv::TrackerMIL::Params::samplerInitMaxNegNum).
    define_attr("sampler_search_win_size", &cv::TrackerMIL::Params::samplerSearchWinSize).
    define_attr("sampler_track_in_radius", &cv::TrackerMIL::Params::samplerTrackInRadius).
    define_attr("sampler_track_max_pos_num", &cv::TrackerMIL::Params::samplerTrackMaxPosNum).
    define_attr("sampler_track_max_neg_num", &cv::TrackerMIL::Params::samplerTrackMaxNegNum).
    define_attr("feature_set_num_features", &cv::TrackerMIL::Params::featureSetNumFeatures);
  
  Class rb_cCvTrackerGOTURN = define_class_under<cv::TrackerGOTURN, cv::Tracker>(rb_mCv, "TrackerGOTURN").
    define_constructor(Constructor<cv::TrackerGOTURN>()).
    define_singleton_function<cv::Ptr<cv::TrackerGOTURN>(*)(const cv::TrackerGOTURN::Params&)>("create", &cv::TrackerGOTURN::create);
  
  Class rb_cCvTrackerGOTURNParams = define_class_under<cv::TrackerGOTURN::Params>(rb_cCvTrackerGOTURN, "Params").
    define_constructor(Constructor<cv::TrackerGOTURN::Params>()).
    define_attr("model_txt", &cv::TrackerGOTURN::Params::modelTxt).
    define_attr("model_bin", &cv::TrackerGOTURN::Params::modelBin);
  
  Class rb_cCvTrackerDaSiamRPN = define_class_under<cv::TrackerDaSiamRPN, cv::Tracker>(rb_mCv, "TrackerDaSiamRPN").
    define_constructor(Constructor<cv::TrackerDaSiamRPN>()).
    define_singleton_function<cv::Ptr<cv::TrackerDaSiamRPN>(*)(const cv::TrackerDaSiamRPN::Params&)>("create", &cv::TrackerDaSiamRPN::create).
    define_method<float(cv::TrackerDaSiamRPN::*)()>("get_tracking_score", &cv::TrackerDaSiamRPN::getTrackingScore);
  
  Class rb_cCvTrackerDaSiamRPNParams = define_class_under<cv::TrackerDaSiamRPN::Params>(rb_cCvTrackerDaSiamRPN, "Params").
    define_constructor(Constructor<cv::TrackerDaSiamRPN::Params>()).
    define_attr("model", &cv::TrackerDaSiamRPN::Params::model).
    define_attr("kernel_cls1", &cv::TrackerDaSiamRPN::Params::kernel_cls1).
    define_attr("kernel_r1", &cv::TrackerDaSiamRPN::Params::kernel_r1).
    define_attr("backend", &cv::TrackerDaSiamRPN::Params::backend).
    define_attr("target", &cv::TrackerDaSiamRPN::Params::target);
  
  Class rb_cCvTrackerNano = define_class_under<cv::TrackerNano, cv::Tracker>(rb_mCv, "TrackerNano").
    define_constructor(Constructor<cv::TrackerNano>()).
    define_singleton_function<cv::Ptr<cv::TrackerNano>(*)(const cv::TrackerNano::Params&)>("create", &cv::TrackerNano::create).
    define_method<float(cv::TrackerNano::*)()>("get_tracking_score", &cv::TrackerNano::getTrackingScore);
  
  Class rb_cCvTrackerNanoParams = define_class_under<cv::TrackerNano::Params>(rb_cCvTrackerNano, "Params").
    define_constructor(Constructor<cv::TrackerNano::Params>()).
    define_attr("backbone", &cv::TrackerNano::Params::backbone).
    define_attr("neckhead", &cv::TrackerNano::Params::neckhead).
    define_attr("backend", &cv::TrackerNano::Params::backend).
    define_attr("target", &cv::TrackerNano::Params::target);
}