#include <opencv2/cudaoptflow.hpp>
#include "cudaoptflow-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudaoptflow()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaDenseOpticalFlow = define_class_under<cv::cuda::DenseOpticalFlow, cv::Algorithm>(rb_mCvCuda, "DenseOpticalFlow").
    define_method<void(cv::cuda::DenseOpticalFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, cv::cuda::Stream&)>("calc", &cv::cuda::DenseOpticalFlow::calc);
  
  Class rb_cCvCudaSparseOpticalFlow = define_class_under<cv::cuda::SparseOpticalFlow, cv::Algorithm>(rb_mCvCuda, "SparseOpticalFlow").
    define_method<void(cv::cuda::SparseOpticalFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("calc", &cv::cuda::SparseOpticalFlow::calc);
  
  Class rb_cCvCudaNvidiaHWOpticalFlow = define_class_under<cv::cuda::NvidiaHWOpticalFlow, cv::Algorithm>(rb_mCvCuda, "NvidiaHWOpticalFlow").
    define_method<void(cv::cuda::NvidiaHWOpticalFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, cv::cuda::Stream&, const cv::_InputArray &, const cv::_OutputArray &)>("calc", &cv::cuda::NvidiaHWOpticalFlow::calc).
    define_method<void(cv::cuda::NvidiaHWOpticalFlow::*)()>("collect_garbage", &cv::cuda::NvidiaHWOpticalFlow::collectGarbage).
    define_method<int(cv::cuda::NvidiaHWOpticalFlow::*)() const>("get_grid_size", &cv::cuda::NvidiaHWOpticalFlow::getGridSize);
  
  Class rb_cCvCudaBroxOpticalFlow = define_class_under<cv::cuda::BroxOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "BroxOpticalFlow").
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_flow_smoothness", &cv::cuda::BroxOpticalFlow::getFlowSmoothness).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_flow_smoothness", &cv::cuda::BroxOpticalFlow::setFlowSmoothness).
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_gradient_constancy_importance", &cv::cuda::BroxOpticalFlow::getGradientConstancyImportance).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_gradient_constancy_importance", &cv::cuda::BroxOpticalFlow::setGradientConstancyImportance).
    define_method<double(cv::cuda::BroxOpticalFlow::*)() const>("get_pyramid_scale_factor", &cv::cuda::BroxOpticalFlow::getPyramidScaleFactor).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(double)>("set_pyramid_scale_factor", &cv::cuda::BroxOpticalFlow::setPyramidScaleFactor).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_inner_iterations", &cv::cuda::BroxOpticalFlow::getInnerIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_inner_iterations", &cv::cuda::BroxOpticalFlow::setInnerIterations).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_outer_iterations", &cv::cuda::BroxOpticalFlow::getOuterIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_outer_iterations", &cv::cuda::BroxOpticalFlow::setOuterIterations).
    define_method<int(cv::cuda::BroxOpticalFlow::*)() const>("get_solver_iterations", &cv::cuda::BroxOpticalFlow::getSolverIterations).
    define_method<void(cv::cuda::BroxOpticalFlow::*)(int)>("set_solver_iterations", &cv::cuda::BroxOpticalFlow::setSolverIterations).
    define_singleton_function<cv::Ptr<cv::cuda::BroxOpticalFlow>(*)(double, double, double, int, int, int)>("create", &cv::cuda::BroxOpticalFlow::create);
  
  Class rb_cCvCudaSparsePyrLKOpticalFlow = define_class_under<cv::cuda::SparsePyrLKOpticalFlow, cv::cuda::SparseOpticalFlow>(rb_mCvCuda, "SparsePyrLKOpticalFlow").
    define_method<cv::Size_<int>(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_win_size", &cv::cuda::SparsePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(cv::Size_<int>)>("set_win_size", &cv::cuda::SparsePyrLKOpticalFlow::setWinSize).
    define_method<int(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_max_level", &cv::cuda::SparsePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::cuda::SparsePyrLKOpticalFlow::setMaxLevel).
    define_method<int(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_num_iters", &cv::cuda::SparsePyrLKOpticalFlow::getNumIters).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::SparsePyrLKOpticalFlow::setNumIters).
    define_method<bool(cv::cuda::SparsePyrLKOpticalFlow::*)() const>("get_use_initial_flow", &cv::cuda::SparsePyrLKOpticalFlow::getUseInitialFlow).
    define_method<void(cv::cuda::SparsePyrLKOpticalFlow::*)(bool)>("set_use_initial_flow", &cv::cuda::SparsePyrLKOpticalFlow::setUseInitialFlow).
    define_singleton_function<cv::Ptr<cv::cuda::SparsePyrLKOpticalFlow>(*)(cv::Size_<int>, int, int, bool)>("create", &cv::cuda::SparsePyrLKOpticalFlow::create);
  
  Class rb_cCvCudaDensePyrLKOpticalFlow = define_class_under<cv::cuda::DensePyrLKOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "DensePyrLKOpticalFlow").
    define_method<cv::Size_<int>(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_win_size", &cv::cuda::DensePyrLKOpticalFlow::getWinSize).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(cv::Size_<int>)>("set_win_size", &cv::cuda::DensePyrLKOpticalFlow::setWinSize).
    define_method<int(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_max_level", &cv::cuda::DensePyrLKOpticalFlow::getMaxLevel).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(int)>("set_max_level", &cv::cuda::DensePyrLKOpticalFlow::setMaxLevel).
    define_method<int(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_num_iters", &cv::cuda::DensePyrLKOpticalFlow::getNumIters).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::DensePyrLKOpticalFlow::setNumIters).
    define_method<bool(cv::cuda::DensePyrLKOpticalFlow::*)() const>("get_use_initial_flow", &cv::cuda::DensePyrLKOpticalFlow::getUseInitialFlow).
    define_method<void(cv::cuda::DensePyrLKOpticalFlow::*)(bool)>("set_use_initial_flow", &cv::cuda::DensePyrLKOpticalFlow::setUseInitialFlow).
    define_singleton_function<cv::Ptr<cv::cuda::DensePyrLKOpticalFlow>(*)(cv::Size_<int>, int, int, bool)>("create", &cv::cuda::DensePyrLKOpticalFlow::create);
  
  Class rb_cCvCudaFarnebackOpticalFlow = define_class_under<cv::cuda::FarnebackOpticalFlow, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "FarnebackOpticalFlow").
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_num_levels", &cv::cuda::FarnebackOpticalFlow::getNumLevels).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_num_levels", &cv::cuda::FarnebackOpticalFlow::setNumLevels).
    define_method<double(cv::cuda::FarnebackOpticalFlow::*)() const>("get_pyr_scale", &cv::cuda::FarnebackOpticalFlow::getPyrScale).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(double)>("set_pyr_scale", &cv::cuda::FarnebackOpticalFlow::setPyrScale).
    define_method<bool(cv::cuda::FarnebackOpticalFlow::*)() const>("get_fast_pyramids", &cv::cuda::FarnebackOpticalFlow::getFastPyramids).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(bool)>("set_fast_pyramids", &cv::cuda::FarnebackOpticalFlow::setFastPyramids).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_win_size", &cv::cuda::FarnebackOpticalFlow::getWinSize).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_win_size", &cv::cuda::FarnebackOpticalFlow::setWinSize).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_num_iters", &cv::cuda::FarnebackOpticalFlow::getNumIters).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_num_iters", &cv::cuda::FarnebackOpticalFlow::setNumIters).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_poly_n", &cv::cuda::FarnebackOpticalFlow::getPolyN).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_poly_n", &cv::cuda::FarnebackOpticalFlow::setPolyN).
    define_method<double(cv::cuda::FarnebackOpticalFlow::*)() const>("get_poly_sigma", &cv::cuda::FarnebackOpticalFlow::getPolySigma).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(double)>("set_poly_sigma", &cv::cuda::FarnebackOpticalFlow::setPolySigma).
    define_method<int(cv::cuda::FarnebackOpticalFlow::*)() const>("get_flags", &cv::cuda::FarnebackOpticalFlow::getFlags).
    define_method<void(cv::cuda::FarnebackOpticalFlow::*)(int)>("set_flags", &cv::cuda::FarnebackOpticalFlow::setFlags).
    define_singleton_function<cv::Ptr<cv::cuda::FarnebackOpticalFlow>(*)(int, double, bool, int, int, int, double, int)>("create", &cv::cuda::FarnebackOpticalFlow::create);
  
  Class rb_cCvCudaOpticalFlowDualTVL1 = define_class_under<cv::cuda::OpticalFlowDual_TVL1, cv::cuda::DenseOpticalFlow>(rb_mCvCuda, "OpticalFlowDualTVL1").
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_tau", &cv::cuda::OpticalFlowDual_TVL1::getTau).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_tau", &cv::cuda::OpticalFlowDual_TVL1::setTau).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_lambda", &cv::cuda::OpticalFlowDual_TVL1::getLambda).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_lambda", &cv::cuda::OpticalFlowDual_TVL1::setLambda).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_gamma", &cv::cuda::OpticalFlowDual_TVL1::getGamma).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_gamma", &cv::cuda::OpticalFlowDual_TVL1::setGamma).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_theta", &cv::cuda::OpticalFlowDual_TVL1::getTheta).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_theta", &cv::cuda::OpticalFlowDual_TVL1::setTheta).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_scales", &cv::cuda::OpticalFlowDual_TVL1::getNumScales).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_scales", &cv::cuda::OpticalFlowDual_TVL1::setNumScales).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_warps", &cv::cuda::OpticalFlowDual_TVL1::getNumWarps).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_warps", &cv::cuda::OpticalFlowDual_TVL1::setNumWarps).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_epsilon", &cv::cuda::OpticalFlowDual_TVL1::getEpsilon).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_epsilon", &cv::cuda::OpticalFlowDual_TVL1::setEpsilon).
    define_method<int(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_num_iterations", &cv::cuda::OpticalFlowDual_TVL1::getNumIterations).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(int)>("set_num_iterations", &cv::cuda::OpticalFlowDual_TVL1::setNumIterations).
    define_method<double(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_scale_step", &cv::cuda::OpticalFlowDual_TVL1::getScaleStep).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(double)>("set_scale_step", &cv::cuda::OpticalFlowDual_TVL1::setScaleStep).
    define_method<bool(cv::cuda::OpticalFlowDual_TVL1::*)() const>("get_use_initial_flow", &cv::cuda::OpticalFlowDual_TVL1::getUseInitialFlow).
    define_method<void(cv::cuda::OpticalFlowDual_TVL1::*)(bool)>("set_use_initial_flow", &cv::cuda::OpticalFlowDual_TVL1::setUseInitialFlow).
    define_singleton_function<cv::Ptr<cv::cuda::OpticalFlowDual_TVL1>(*)(double, double, double, int, int, double, int, double, double, bool)>("create", &cv::cuda::OpticalFlowDual_TVL1::create);
  
  Class rb_cCvCudaNvidiaOpticalFlow10 = define_class_under<cv::cuda::NvidiaOpticalFlow_1_0, cv::cuda::NvidiaHWOpticalFlow>(rb_mCvCuda, "NvidiaOpticalFlow10").
    define_method<void(cv::cuda::NvidiaOpticalFlow_1_0::*)(const cv::_InputArray &, cv::Size_<int>, int, const cv::_InputOutputArray &)>("up_sampler", &cv::cuda::NvidiaOpticalFlow_1_0::upSampler).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_1_0>(*)(cv::Size_<int>, cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_1_0::create);
  
  Enum<cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL> rb_cCvCudaNvidiaOpticalFlow10NVIDIAOFPERFLEVEL = define_enum<cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL>("NVIDIA_OF_PERF_LEVEL", rb_cCvCudaNvidiaOpticalFlow10).
    define_value("NV_OF_PERF_LEVEL_UNDEFINED", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_UNDEFINED).
    define_value("NV_OF_PERF_LEVEL_SLOW", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW).
    define_value("NV_OF_PERF_LEVEL_MEDIUM", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MEDIUM).
    define_value("NV_OF_PERF_LEVEL_FAST", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_FAST).
    define_value("NV_OF_PERF_LEVEL_MAX", cv::cuda::NvidiaOpticalFlow_1_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MAX);
  
  Class rb_cCvCudaNvidiaOpticalFlow20 = define_class_under<cv::cuda::NvidiaOpticalFlow_2_0, cv::cuda::NvidiaHWOpticalFlow>(rb_mCvCuda, "NvidiaOpticalFlow20").
    define_method<void(cv::cuda::NvidiaOpticalFlow_2_0::*)(const cv::_InputArray &, const cv::_InputOutputArray &)>("convert_to_float", &cv::cuda::NvidiaOpticalFlow_2_0::convertToFloat).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_2_0>(*)(cv::Size_<int>, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_2_0::create).
    define_singleton_function<cv::Ptr<cv::cuda::NvidiaOpticalFlow_2_0>(*)(cv::Size_<int>, std::vector<cv::Rect_<int>>, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE, cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE, bool, bool, bool, int, cv::cuda::Stream&, cv::cuda::Stream&)>("create", &cv::cuda::NvidiaOpticalFlow_2_0::create);
  
  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFPERFLEVEL = define_enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL>("NVIDIA_OF_PERF_LEVEL", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_PERF_LEVEL_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_UNDEFINED).
    define_value("NV_OF_PERF_LEVEL_SLOW", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_SLOW).
    define_value("NV_OF_PERF_LEVEL_MEDIUM", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MEDIUM).
    define_value("NV_OF_PERF_LEVEL_FAST", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_FAST).
    define_value("NV_OF_PERF_LEVEL_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_PERF_LEVEL::NV_OF_PERF_LEVEL_MAX);
  
  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFOUTPUTVECTORGRIDSIZE = define_enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE>("NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_UNDEFINED).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_1", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_1).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_2", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_2).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_4", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_4).
    define_value("NV_OF_OUTPUT_VECTOR_GRID_SIZE_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_OUTPUT_VECTOR_GRID_SIZE::NV_OF_OUTPUT_VECTOR_GRID_SIZE_MAX);
  
  Enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE> rb_cCvCudaNvidiaOpticalFlow20NVIDIAOFHINTVECTORGRIDSIZE = define_enum<cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE>("NVIDIA_OF_HINT_VECTOR_GRID_SIZE", rb_cCvCudaNvidiaOpticalFlow20).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_UNDEFINED", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_UNDEFINED).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_1", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_1).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_2", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_2).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_4", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_4).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_8", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_8).
    define_value("NV_OF_HINT_VECTOR_GRID_SIZE_MAX", cv::cuda::NvidiaOpticalFlow_2_0::NVIDIA_OF_HINT_VECTOR_GRID_SIZE::NV_OF_HINT_VECTOR_GRID_SIZE_MAX);
}