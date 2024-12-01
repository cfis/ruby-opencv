#include <opencv2/videostab/optical_flow.hpp>
#include "optical_flow-rb.hpp"

using namespace Rice;

extern "C"
void Init_OpticalFlow()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabISparseOptFlowEstimator = define_class_under<cv::videostab::ISparseOptFlowEstimator>(rb_mCvVideostab, "ISparseOptFlowEstimator").
    define_method<void(cv::videostab::ISparseOptFlowEstimator::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("run", &cv::videostab::ISparseOptFlowEstimator::run);
  
  Class rb_cCvVideostabIDenseOptFlowEstimator = define_class_under<cv::videostab::IDenseOptFlowEstimator>(rb_mCvVideostab, "IDenseOptFlowEstimator").
    define_method<void(cv::videostab::IDenseOptFlowEstimator::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &)>("run", &cv::videostab::IDenseOptFlowEstimator::run);
  
  Class rb_cCvVideostabPyrLkOptFlowEstimatorBase = define_class_under<cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "PyrLkOptFlowEstimatorBase").
    define_constructor(Constructor<cv::videostab::PyrLkOptFlowEstimatorBase>()).
    define_method<void(cv::videostab::PyrLkOptFlowEstimatorBase::*)(cv::Size_<int>)>("set_win_size", &cv::videostab::PyrLkOptFlowEstimatorBase::setWinSize).
    define_method<cv::Size_<int>(cv::videostab::PyrLkOptFlowEstimatorBase::*)() const>("win_size", &cv::videostab::PyrLkOptFlowEstimatorBase::winSize).
    define_method<void(cv::videostab::PyrLkOptFlowEstimatorBase::*)(int)>("set_max_level", &cv::videostab::PyrLkOptFlowEstimatorBase::setMaxLevel).
    define_method<int(cv::videostab::PyrLkOptFlowEstimatorBase::*)() const>("max_level", &cv::videostab::PyrLkOptFlowEstimatorBase::maxLevel);
  
  Class rb_cCvVideostabSparsePyrLkOptFlowEstimator = define_class_under<cv::videostab::SparsePyrLkOptFlowEstimator, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "SparsePyrLkOptFlowEstimator").
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimator::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("run", &cv::videostab::SparsePyrLkOptFlowEstimator::run);
  
  Class rb_cCvVideostabSparsePyrLkOptFlowEstimatorGpu = define_class_under<cv::videostab::SparsePyrLkOptFlowEstimatorGpu, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "SparsePyrLkOptFlowEstimatorGpu").
    define_constructor(Constructor<cv::videostab::SparsePyrLkOptFlowEstimatorGpu>()).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run);
  
  Class rb_cCvVideostabDensePyrLkOptFlowEstimatorGpu = define_class_under<cv::videostab::DensePyrLkOptFlowEstimatorGpu, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "DensePyrLkOptFlowEstimatorGpu").
    define_constructor(Constructor<cv::videostab::DensePyrLkOptFlowEstimatorGpu>()).
    define_method<void(cv::videostab::DensePyrLkOptFlowEstimatorGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &)>("run", &cv::videostab::DensePyrLkOptFlowEstimatorGpu::run);
}