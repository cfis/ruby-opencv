#include <opencv2/videostab/global_motion.hpp>
#include "global_motion-rb.hpp"

using namespace Rice;

extern "C"
void Init_GlobalMotion()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  rb_mCvVideostab.define_module_function<cv::Mat(*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &, int, float*)>("estimate_global_motion_least_squares", &cv::videostab::estimateGlobalMotionLeastSquares);
  
  rb_mCvVideostab.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, int, const cv::videostab::RansacParams&, float*, int*)>("estimate_global_motion_ransac", &cv::videostab::estimateGlobalMotionRansac);
  
  Class rb_cCvVideostabMotionEstimatorBase = define_class_under<cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorBase").
    define_method<void(cv::videostab::MotionEstimatorBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::MotionEstimatorBase::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::MotionEstimatorBase::*)() const>("motion_model", &cv::videostab::MotionEstimatorBase::motionModel).
    define_method<cv::Mat(cv::videostab::MotionEstimatorBase::*)(const cv::_InputArray &, const cv::_InputArray &, bool*)>("estimate", &cv::videostab::MotionEstimatorBase::estimate).
    define_constructor(Constructor<cv::videostab::MotionEstimatorBase, cv::videostab::MotionModel>());
  
  Class rb_cCvVideostabMotionEstimatorRansacL2 = define_class_under<cv::videostab::MotionEstimatorRansacL2, cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorRansacL2").
    define_constructor(Constructor<cv::videostab::MotionEstimatorRansacL2, cv::videostab::MotionModel>()).
    define_method<void(cv::videostab::MotionEstimatorRansacL2::*)(const cv::videostab::RansacParams&)>("set_ransac_params", &cv::videostab::MotionEstimatorRansacL2::setRansacParams).
    define_method<cv::videostab::RansacParams(cv::videostab::MotionEstimatorRansacL2::*)() const>("ransac_params", &cv::videostab::MotionEstimatorRansacL2::ransacParams).
    define_method<void(cv::videostab::MotionEstimatorRansacL2::*)(float)>("set_min_inlier_ratio", &cv::videostab::MotionEstimatorRansacL2::setMinInlierRatio).
    define_method<float(cv::videostab::MotionEstimatorRansacL2::*)() const>("min_inlier_ratio", &cv::videostab::MotionEstimatorRansacL2::minInlierRatio).
    define_method<cv::Mat(cv::videostab::MotionEstimatorRansacL2::*)(const cv::_InputArray &, const cv::_InputArray &, bool*)>("estimate", &cv::videostab::MotionEstimatorRansacL2::estimate);
  
  Class rb_cCvVideostabMotionEstimatorL1 = define_class_under<cv::videostab::MotionEstimatorL1, cv::videostab::MotionEstimatorBase>(rb_mCvVideostab, "MotionEstimatorL1").
    define_constructor(Constructor<cv::videostab::MotionEstimatorL1, cv::videostab::MotionModel>()).
    define_method<cv::Mat(cv::videostab::MotionEstimatorL1::*)(const cv::_InputArray &, const cv::_InputArray &, bool*)>("estimate", &cv::videostab::MotionEstimatorL1::estimate);
  
  Class rb_cCvVideostabImageMotionEstimatorBase = define_class_under<cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "ImageMotionEstimatorBase").
    define_method<void(cv::videostab::ImageMotionEstimatorBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::ImageMotionEstimatorBase::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::ImageMotionEstimatorBase::*)() const>("motion_model", &cv::videostab::ImageMotionEstimatorBase::motionModel).
    define_method<void(cv::videostab::ImageMotionEstimatorBase::*)(const cv::_InputArray &)>("set_frame_mask", &cv::videostab::ImageMotionEstimatorBase::setFrameMask).
    define_method<cv::Mat(cv::videostab::ImageMotionEstimatorBase::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::ImageMotionEstimatorBase::estimate).
    define_constructor(Constructor<cv::videostab::ImageMotionEstimatorBase, cv::videostab::MotionModel>());
  
  Class rb_cCvVideostabFromFileMotionReader = define_class_under<cv::videostab::FromFileMotionReader, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "FromFileMotionReader").
    define_constructor(Constructor<cv::videostab::FromFileMotionReader, const std::basic_string<char>&>()).
    define_method<cv::Mat(cv::videostab::FromFileMotionReader::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::FromFileMotionReader::estimate);
  
  Class rb_cCvVideostabToFileMotionWriter = define_class_under<cv::videostab::ToFileMotionWriter, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "ToFileMotionWriter").
    define_constructor(Constructor<cv::videostab::ToFileMotionWriter, const std::basic_string<char>&, cv::Ptr<cv::videostab::ImageMotionEstimatorBase>>()).
    define_method<void(cv::videostab::ToFileMotionWriter::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::ToFileMotionWriter::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::ToFileMotionWriter::*)() const>("motion_model", &cv::videostab::ToFileMotionWriter::motionModel).
    define_method<void(cv::videostab::ToFileMotionWriter::*)(const cv::_InputArray &)>("set_frame_mask", &cv::videostab::ToFileMotionWriter::setFrameMask).
    define_method<cv::Mat(cv::videostab::ToFileMotionWriter::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::ToFileMotionWriter::estimate);
  
  Class rb_cCvVideostabKeypointBasedMotionEstimator = define_class_under<cv::videostab::KeypointBasedMotionEstimator, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "KeypointBasedMotionEstimator").
    define_constructor(Constructor<cv::videostab::KeypointBasedMotionEstimator, cv::Ptr<cv::videostab::MotionEstimatorBase>>()).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::KeypointBasedMotionEstimator::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::KeypointBasedMotionEstimator::*)() const>("motion_model", &cv::videostab::KeypointBasedMotionEstimator::motionModel).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::Feature2D>)>("set_detector", &cv::videostab::KeypointBasedMotionEstimator::setDetector).
    define_method<cv::Ptr<cv::Feature2D>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("detector", &cv::videostab::KeypointBasedMotionEstimator::detector).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::videostab::ISparseOptFlowEstimator>)>("set_optical_flow_estimator", &cv::videostab::KeypointBasedMotionEstimator::setOpticalFlowEstimator).
    define_method<cv::Ptr<cv::videostab::ISparseOptFlowEstimator>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("optical_flow_estimator", &cv::videostab::KeypointBasedMotionEstimator::opticalFlowEstimator).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(cv::Ptr<cv::videostab::IOutlierRejector>)>("set_outlier_rejector", &cv::videostab::KeypointBasedMotionEstimator::setOutlierRejector).
    define_method<cv::Ptr<cv::videostab::IOutlierRejector>(cv::videostab::KeypointBasedMotionEstimator::*)() const>("outlier_rejector", &cv::videostab::KeypointBasedMotionEstimator::outlierRejector).
    define_method<void(cv::videostab::KeypointBasedMotionEstimator::*)(const cv::_InputArray &)>("set_frame_mask", &cv::videostab::KeypointBasedMotionEstimator::setFrameMask).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimator::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimator::estimate).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimator::*)(const cv::_InputArray &, const cv::_InputArray &, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimator::estimate);
  
  Class rb_cCvVideostabKeypointBasedMotionEstimatorGpu = define_class_under<cv::videostab::KeypointBasedMotionEstimatorGpu, cv::videostab::ImageMotionEstimatorBase>(rb_mCvVideostab, "KeypointBasedMotionEstimatorGpu").
    define_constructor(Constructor<cv::videostab::KeypointBasedMotionEstimatorGpu, cv::Ptr<cv::videostab::MotionEstimatorBase>>()).
    define_method<void(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::KeypointBasedMotionEstimatorGpu::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::KeypointBasedMotionEstimatorGpu::*)() const>("motion_model", &cv::videostab::KeypointBasedMotionEstimatorGpu::motionModel).
    define_method<void(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(cv::Ptr<cv::videostab::IOutlierRejector>)>("set_outlier_rejector", &cv::videostab::KeypointBasedMotionEstimatorGpu::setOutlierRejector).
    define_method<cv::Ptr<cv::videostab::IOutlierRejector>(cv::videostab::KeypointBasedMotionEstimatorGpu::*)() const>("outlier_rejector", &cv::videostab::KeypointBasedMotionEstimatorGpu::outlierRejector).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(const cv::Mat&, const cv::Mat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimatorGpu::estimate).
    define_method<cv::Mat(cv::videostab::KeypointBasedMotionEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, bool*)>("estimate", &cv::videostab::KeypointBasedMotionEstimatorGpu::estimate);
  
  rb_mCvVideostab.define_module_function<cv::Mat(*)(int, int, const std::vector<cv::Mat>&)>("get_motion", &cv::videostab::getMotion);
}