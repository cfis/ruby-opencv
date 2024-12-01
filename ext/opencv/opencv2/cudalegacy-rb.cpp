#include <opencv2/cudalegacy.hpp>
#include "cudalegacy-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudalegacy()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaImagePyramid = define_class_under<cv::cuda::ImagePyramid, cv::Algorithm>(rb_mCvCuda, "ImagePyramid").
    define_method<void(cv::cuda::ImagePyramid::*)(const cv::_OutputArray &, cv::Size_<int>, cv::cuda::Stream&) const>("get_layer", &cv::cuda::ImagePyramid::getLayer);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::ImagePyramid>(*)(const cv::_InputArray &, int, cv::cuda::Stream&)>("create_image_pyramid", &cv::cuda::createImagePyramid);
  
  Class rb_cCvCudaBackgroundSubtractorGMG = define_class_under<cv::cuda::BackgroundSubtractorGMG, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorGMG").
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(const cv::_InputArray &, const cv::_OutputArray &, double, cv::cuda::Stream&)>("apply", &cv::cuda::BackgroundSubtractorGMG::apply).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_max_features", &cv::cuda::BackgroundSubtractorGMG::getMaxFeatures).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_max_features", &cv::cuda::BackgroundSubtractorGMG::setMaxFeatures).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_default_learning_rate", &cv::cuda::BackgroundSubtractorGMG::getDefaultLearningRate).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_default_learning_rate", &cv::cuda::BackgroundSubtractorGMG::setDefaultLearningRate).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_num_frames", &cv::cuda::BackgroundSubtractorGMG::getNumFrames).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_num_frames", &cv::cuda::BackgroundSubtractorGMG::setNumFrames).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_quantization_levels", &cv::cuda::BackgroundSubtractorGMG::getQuantizationLevels).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_quantization_levels", &cv::cuda::BackgroundSubtractorGMG::setQuantizationLevels).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_background_prior", &cv::cuda::BackgroundSubtractorGMG::getBackgroundPrior).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_background_prior", &cv::cuda::BackgroundSubtractorGMG::setBackgroundPrior).
    define_method<int(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_smoothing_radius", &cv::cuda::BackgroundSubtractorGMG::getSmoothingRadius).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(int)>("set_smoothing_radius", &cv::cuda::BackgroundSubtractorGMG::setSmoothingRadius).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_decision_threshold", &cv::cuda::BackgroundSubtractorGMG::getDecisionThreshold).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_decision_threshold", &cv::cuda::BackgroundSubtractorGMG::setDecisionThreshold).
    define_method<bool(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_update_background_model", &cv::cuda::BackgroundSubtractorGMG::getUpdateBackgroundModel).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(bool)>("set_update_background_model", &cv::cuda::BackgroundSubtractorGMG::setUpdateBackgroundModel).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_min_val", &cv::cuda::BackgroundSubtractorGMG::getMinVal).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_min_val", &cv::cuda::BackgroundSubtractorGMG::setMinVal).
    define_method<double(cv::cuda::BackgroundSubtractorGMG::*)() const>("get_max_val", &cv::cuda::BackgroundSubtractorGMG::getMaxVal).
    define_method<void(cv::cuda::BackgroundSubtractorGMG::*)(double)>("set_max_val", &cv::cuda::BackgroundSubtractorGMG::setMaxVal);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorGMG>(*)(int, double)>("create_background_subtractor_gmg", &cv::cuda::createBackgroundSubtractorGMG);
  
  Class rb_cCvCudaBackgroundSubtractorFGD = define_class_under<cv::cuda::BackgroundSubtractorFGD, cv::BackgroundSubtractor>(rb_mCvCuda, "BackgroundSubtractorFGD").
    define_method<void(cv::cuda::BackgroundSubtractorFGD::*)(const cv::_OutputArray &)>("get_foreground_regions", &cv::cuda::BackgroundSubtractorFGD::getForegroundRegions);
  
  Class rb_cCvCudaFGDParams = define_class_under<cv::cuda::FGDParams>(rb_mCvCuda, "FGDParams").
    define_attr("lc", &cv::cuda::FGDParams::Lc).
    define_attr("n1c", &cv::cuda::FGDParams::N1c).
    define_attr("n2c", &cv::cuda::FGDParams::N2c).
    define_attr("lcc", &cv::cuda::FGDParams::Lcc).
    define_attr("n1cc", &cv::cuda::FGDParams::N1cc).
    define_attr("n2cc", &cv::cuda::FGDParams::N2cc).
    define_attr("is_obj_without_holes", &cv::cuda::FGDParams::is_obj_without_holes).
    define_attr("perform_morphing", &cv::cuda::FGDParams::perform_morphing).
    define_attr("alpha1", &cv::cuda::FGDParams::alpha1).
    define_attr("alpha2", &cv::cuda::FGDParams::alpha2).
    define_attr("alpha3", &cv::cuda::FGDParams::alpha3).
    define_attr("delta", &cv::cuda::FGDParams::delta).
    define_attr("t", &cv::cuda::FGDParams::T).
    define_attr("min_area", &cv::cuda::FGDParams::minArea).
    define_constructor(Constructor<cv::cuda::FGDParams>());
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::BackgroundSubtractorFGD>(*)(const cv::cuda::FGDParams&)>("create_background_subtractor_fgd", &cv::cuda::createBackgroundSubtractorFGD);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::Size_<int>, cv::Size_<int>, cv::Size_<int>, bool, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("calc_optical_flow_bm", &cv::cuda::calcOpticalFlowBM);
  
  Class rb_cCvCudaFastOpticalFlowBM = define_class_under<cv::cuda::FastOpticalFlowBM>(rb_mCvCuda, "FastOpticalFlowBM").
    define_method<void(cv::cuda::FastOpticalFlowBM::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, int, int, cv::cuda::Stream&)>("operator()", &cv::cuda::FastOpticalFlowBM::operator());
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, float, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("interpolate_frames", &cv::cuda::interpolateFrames);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("create_optical_flow_needle_map", &cv::cuda::createOpticalFlowNeedleMap);
  
  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("graphcut", &cv::cuda::graphcut);
  
  rb_mCvCuda.define_module_function<void(*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("graphcut", &cv::cuda::graphcut);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, const cv::Scalar_<double>&, const cv::Scalar_<double>&, cv::cuda::Stream&)>("connectivity_mask", &cv::cuda::connectivityMask);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, int, cv::cuda::Stream&)>("label_components", &cv::cuda::labelComponents);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::Mat&, const cv::Mat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("transform_points", &cv::cuda::transformPoints);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("project_points", &cv::cuda::projectPoints);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::Mat&, cv::Mat&, bool, int, float, int, std::vector<int>*)>("solve_pn_p_ransac", &cv::cuda::solvePnPRansac);
}