#include <opencv2/videostab/motion_stabilizing.hpp>
#include "motion_stabilizing-rb.hpp"

using namespace Rice;

extern "C"
void Init_MotionStabilizing()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabIMotionStabilizer = define_class_under<cv::videostab::IMotionStabilizer>(rb_mCvVideostab, "IMotionStabilizer").
    define_method<void(cv::videostab::IMotionStabilizer::*)(int, const std::vector<cv::Mat>&, const cv::Range&, cv::Mat*)>("stabilize", &cv::videostab::IMotionStabilizer::stabilize);
  
  Class rb_cCvVideostabMotionStabilizationPipeline = define_class_under<cv::videostab::MotionStabilizationPipeline, cv::videostab::IMotionStabilizer>(rb_mCvVideostab, "MotionStabilizationPipeline").
    define_method<void(cv::videostab::MotionStabilizationPipeline::*)(cv::Ptr<cv::videostab::IMotionStabilizer>)>("push_back", &cv::videostab::MotionStabilizationPipeline::pushBack).
    define_method<bool(cv::videostab::MotionStabilizationPipeline::*)() const>("empty", &cv::videostab::MotionStabilizationPipeline::empty).
    define_method<void(cv::videostab::MotionStabilizationPipeline::*)(int, const std::vector<cv::Mat>&, const cv::Range&, cv::Mat*)>("stabilize", &cv::videostab::MotionStabilizationPipeline::stabilize);
  
  Class rb_cCvVideostabMotionFilterBase = define_class_under<cv::videostab::MotionFilterBase, cv::videostab::IMotionStabilizer>(rb_mCvVideostab, "MotionFilterBase").
    define_method<cv::Mat(cv::videostab::MotionFilterBase::*)(int, const std::vector<cv::Mat>&, const cv::Range&)>("stabilize", &cv::videostab::MotionFilterBase::stabilize).
    define_method<void(cv::videostab::MotionFilterBase::*)(int, const std::vector<cv::Mat>&, const cv::Range&, cv::Mat*)>("stabilize", &cv::videostab::MotionFilterBase::stabilize);
  
  Class rb_cCvVideostabGaussianMotionFilter = define_class_under<cv::videostab::GaussianMotionFilter, cv::videostab::MotionFilterBase>(rb_mCvVideostab, "GaussianMotionFilter").
    define_constructor(Constructor<cv::videostab::GaussianMotionFilter, int, float>()).
    define_method<void(cv::videostab::GaussianMotionFilter::*)(int, float)>("set_params", &cv::videostab::GaussianMotionFilter::setParams).
    define_method<int(cv::videostab::GaussianMotionFilter::*)() const>("radius", &cv::videostab::GaussianMotionFilter::radius).
    define_method<float(cv::videostab::GaussianMotionFilter::*)() const>("stdev", &cv::videostab::GaussianMotionFilter::stdev).
    define_method<cv::Mat(cv::videostab::GaussianMotionFilter::*)(int, const std::vector<cv::Mat>&, const cv::Range&)>("stabilize", &cv::videostab::GaussianMotionFilter::stabilize);
  
  Class rb_cCvVideostabLpMotionStabilizer = define_class_under<cv::videostab::LpMotionStabilizer, cv::videostab::IMotionStabilizer>(rb_mCvVideostab, "LpMotionStabilizer").
    define_constructor(Constructor<cv::videostab::LpMotionStabilizer, cv::videostab::MotionModel>()).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::LpMotionStabilizer::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::LpMotionStabilizer::*)() const>("motion_model", &cv::videostab::LpMotionStabilizer::motionModel).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(cv::Size_<int>)>("set_frame_size", &cv::videostab::LpMotionStabilizer::setFrameSize).
    define_method<cv::Size_<int>(cv::videostab::LpMotionStabilizer::*)() const>("frame_size", &cv::videostab::LpMotionStabilizer::frameSize).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(float)>("set_trim_ratio", &cv::videostab::LpMotionStabilizer::setTrimRatio).
    define_method<float(cv::videostab::LpMotionStabilizer::*)() const>("trim_ratio", &cv::videostab::LpMotionStabilizer::trimRatio).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(float)>("set_weight1", &cv::videostab::LpMotionStabilizer::setWeight1).
    define_method<float(cv::videostab::LpMotionStabilizer::*)() const>("weight1", &cv::videostab::LpMotionStabilizer::weight1).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(float)>("set_weight2", &cv::videostab::LpMotionStabilizer::setWeight2).
    define_method<float(cv::videostab::LpMotionStabilizer::*)() const>("weight2", &cv::videostab::LpMotionStabilizer::weight2).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(float)>("set_weight3", &cv::videostab::LpMotionStabilizer::setWeight3).
    define_method<float(cv::videostab::LpMotionStabilizer::*)() const>("weight3", &cv::videostab::LpMotionStabilizer::weight3).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(float)>("set_weight4", &cv::videostab::LpMotionStabilizer::setWeight4).
    define_method<float(cv::videostab::LpMotionStabilizer::*)() const>("weight4", &cv::videostab::LpMotionStabilizer::weight4).
    define_method<void(cv::videostab::LpMotionStabilizer::*)(int, const std::vector<cv::Mat>&, const cv::Range&, cv::Mat*)>("stabilize", &cv::videostab::LpMotionStabilizer::stabilize);
  
  rb_mCvVideostab.define_module_function<cv::Mat(*)(const cv::Mat&, cv::Size_<int>, float)>("ensure_inclusion_constraint", &cv::videostab::ensureInclusionConstraint);
  
  rb_mCvVideostab.define_module_function<float(*)(const cv::Mat&, cv::Size_<int>)>("estimate_optimal_trim_ratio", &cv::videostab::estimateOptimalTrimRatio);
}