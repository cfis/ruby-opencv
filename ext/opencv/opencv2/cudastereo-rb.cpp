#include <opencv2/cudastereo.hpp>
#include "cudastereo-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudastereo()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaStereoBM = define_class_under<cv::cuda::StereoBM, cv::StereoBM>(rb_mCvCuda, "StereoBM").
    define_method<void(cv::cuda::StereoBM::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBM::compute);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoBM>(*)(int, int)>("create_stereo_bm", &cv::cuda::createStereoBM);
  
  Class rb_cCvCudaStereoBeliefPropagation = define_class_under<cv::cuda::StereoBeliefPropagation, cv::StereoMatcher>(rb_mCvCuda, "StereoBeliefPropagation").
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBeliefPropagation::compute).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::StereoBeliefPropagation::compute).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_num_iters", &cv::cuda::StereoBeliefPropagation::getNumIters).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_num_iters", &cv::cuda::StereoBeliefPropagation::setNumIters).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_num_levels", &cv::cuda::StereoBeliefPropagation::getNumLevels).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_num_levels", &cv::cuda::StereoBeliefPropagation::setNumLevels).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_max_data_term", &cv::cuda::StereoBeliefPropagation::getMaxDataTerm).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_max_data_term", &cv::cuda::StereoBeliefPropagation::setMaxDataTerm).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_data_weight", &cv::cuda::StereoBeliefPropagation::getDataWeight).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_data_weight", &cv::cuda::StereoBeliefPropagation::setDataWeight).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_max_disc_term", &cv::cuda::StereoBeliefPropagation::getMaxDiscTerm).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_max_disc_term", &cv::cuda::StereoBeliefPropagation::setMaxDiscTerm).
    define_method<double(cv::cuda::StereoBeliefPropagation::*)() const>("get_disc_single_jump", &cv::cuda::StereoBeliefPropagation::getDiscSingleJump).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(double)>("set_disc_single_jump", &cv::cuda::StereoBeliefPropagation::setDiscSingleJump).
    define_method<int(cv::cuda::StereoBeliefPropagation::*)() const>("get_msg_type", &cv::cuda::StereoBeliefPropagation::getMsgType).
    define_method<void(cv::cuda::StereoBeliefPropagation::*)(int)>("set_msg_type", &cv::cuda::StereoBeliefPropagation::setMsgType).
    define_singleton_function<void(*)(int, int, int&, int&, int&)>("estimate_recommended_params", &cv::cuda::StereoBeliefPropagation::estimateRecommendedParams);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoBeliefPropagation>(*)(int, int, int, int)>("create_stereo_belief_propagation", &cv::cuda::createStereoBeliefPropagation);
  
  Class rb_cCvCudaStereoConstantSpaceBP = define_class_under<cv::cuda::StereoConstantSpaceBP, cv::cuda::StereoBeliefPropagation>(rb_mCvCuda, "StereoConstantSpaceBP").
    define_method<int(cv::cuda::StereoConstantSpaceBP::*)() const>("get_nr_plane", &cv::cuda::StereoConstantSpaceBP::getNrPlane).
    define_method<void(cv::cuda::StereoConstantSpaceBP::*)(int)>("set_nr_plane", &cv::cuda::StereoConstantSpaceBP::setNrPlane).
    define_method<bool(cv::cuda::StereoConstantSpaceBP::*)() const>("get_use_local_init_data_cost", &cv::cuda::StereoConstantSpaceBP::getUseLocalInitDataCost).
    define_method<void(cv::cuda::StereoConstantSpaceBP::*)(bool)>("set_use_local_init_data_cost", &cv::cuda::StereoConstantSpaceBP::setUseLocalInitDataCost).
    define_singleton_function<void(*)(int, int, int&, int&, int&, int&)>("estimate_recommended_params", &cv::cuda::StereoConstantSpaceBP::estimateRecommendedParams);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoConstantSpaceBP>(*)(int, int, int, int, int)>("create_stereo_constant_space_bp", &cv::cuda::createStereoConstantSpaceBP);
  
  Class rb_cCvCudaStereoSGM = define_class_under<cv::cuda::StereoSGM, cv::StereoSGBM>(rb_mCvCuda, "StereoSGM").
    define_method<void(cv::cuda::StereoSGM::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::cuda::StereoSGM::compute).
    define_method<void(cv::cuda::StereoSGM::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::StereoSGM::compute);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::StereoSGM>(*)(int, int, int, int, int, int)>("create_stereo_sgm", &cv::cuda::createStereoSGM);
  
  Class rb_cCvCudaDisparityBilateralFilter = define_class_under<cv::cuda::DisparityBilateralFilter, cv::Algorithm>(rb_mCvCuda, "DisparityBilateralFilter").
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("apply", &cv::cuda::DisparityBilateralFilter::apply).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_num_disparities", &cv::cuda::DisparityBilateralFilter::getNumDisparities).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_num_disparities", &cv::cuda::DisparityBilateralFilter::setNumDisparities).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_radius", &cv::cuda::DisparityBilateralFilter::getRadius).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_radius", &cv::cuda::DisparityBilateralFilter::setRadius).
    define_method<int(cv::cuda::DisparityBilateralFilter::*)() const>("get_num_iters", &cv::cuda::DisparityBilateralFilter::getNumIters).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(int)>("set_num_iters", &cv::cuda::DisparityBilateralFilter::setNumIters).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_edge_threshold", &cv::cuda::DisparityBilateralFilter::getEdgeThreshold).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_edge_threshold", &cv::cuda::DisparityBilateralFilter::setEdgeThreshold).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_max_disc_threshold", &cv::cuda::DisparityBilateralFilter::getMaxDiscThreshold).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_max_disc_threshold", &cv::cuda::DisparityBilateralFilter::setMaxDiscThreshold).
    define_method<double(cv::cuda::DisparityBilateralFilter::*)() const>("get_sigma_range", &cv::cuda::DisparityBilateralFilter::getSigmaRange).
    define_method<void(cv::cuda::DisparityBilateralFilter::*)(double)>("set_sigma_range", &cv::cuda::DisparityBilateralFilter::setSigmaRange);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::DisparityBilateralFilter>(*)(int, int, int)>("create_disparity_bilateral_filter", &cv::cuda::createDisparityBilateralFilter);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, int, cv::cuda::Stream&)>("reproject_image_to3_d", &cv::cuda::reprojectImageTo3D);
  
  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat, cv::cuda::GpuMat&, cv::Mat, int, cv::cuda::Stream&)>("reproject_image_to3_d", &cv::cuda::reprojectImageTo3D);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, cv::cuda::Stream&)>("draw_color_disp", &cv::cuda::drawColorDisp);
}