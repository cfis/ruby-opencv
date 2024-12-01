#include <opencv2/videostab/inpainting.hpp>
#include "inpainting-rb.hpp"

using namespace Rice;

extern "C"
void Init_Inpainting()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabInpainterBase = define_class_under<cv::videostab::InpainterBase>(rb_mCvVideostab, "InpainterBase").
    define_constructor(Constructor<cv::videostab::InpainterBase>()).
    define_method<void(cv::videostab::InpainterBase::*)(int)>("set_radius", &cv::videostab::InpainterBase::setRadius).
    define_method<int(cv::videostab::InpainterBase::*)() const>("radius", &cv::videostab::InpainterBase::radius).
    define_method<void(cv::videostab::InpainterBase::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::InpainterBase::setMotionModel).
    define_method<cv::videostab::MotionModel(cv::videostab::InpainterBase::*)() const>("motion_model", &cv::videostab::InpainterBase::motionModel).
    define_method<void(cv::videostab::InpainterBase::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::InpainterBase::inpaint).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::InpainterBase::setFrames).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("frames", &cv::videostab::InpainterBase::frames).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::InpainterBase::setMotions).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("motions", &cv::videostab::InpainterBase::motions).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_stabilized_frames", &cv::videostab::InpainterBase::setStabilizedFrames).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("stabilized_frames", &cv::videostab::InpainterBase::stabilizedFrames).
    define_method<void(cv::videostab::InpainterBase::*)(const std::vector<cv::Mat>&)>("set_stabilization_motions", &cv::videostab::InpainterBase::setStabilizationMotions).
    define_method<const std::vector<cv::Mat>&(cv::videostab::InpainterBase::*)() const>("stabilization_motions", &cv::videostab::InpainterBase::stabilizationMotions);
  
  Class rb_cCvVideostabNullInpainter = define_class_under<cv::videostab::NullInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "NullInpainter").
    define_method<void(cv::videostab::NullInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::NullInpainter::inpaint);
  
  Class rb_cCvVideostabInpaintingPipeline = define_class_under<cv::videostab::InpaintingPipeline, cv::videostab::InpainterBase>(rb_mCvVideostab, "InpaintingPipeline").
    define_method<void(cv::videostab::InpaintingPipeline::*)(cv::Ptr<cv::videostab::InpainterBase>)>("push_back", &cv::videostab::InpaintingPipeline::pushBack).
    define_method<bool(cv::videostab::InpaintingPipeline::*)() const>("empty", &cv::videostab::InpaintingPipeline::empty).
    define_method<void(cv::videostab::InpaintingPipeline::*)(int)>("set_radius", &cv::videostab::InpaintingPipeline::setRadius).
    define_method<void(cv::videostab::InpaintingPipeline::*)(cv::videostab::MotionModel)>("set_motion_model", &cv::videostab::InpaintingPipeline::setMotionModel).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_frames", &cv::videostab::InpaintingPipeline::setFrames).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_motions", &cv::videostab::InpaintingPipeline::setMotions).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_stabilized_frames", &cv::videostab::InpaintingPipeline::setStabilizedFrames).
    define_method<void(cv::videostab::InpaintingPipeline::*)(const std::vector<cv::Mat>&)>("set_stabilization_motions", &cv::videostab::InpaintingPipeline::setStabilizationMotions).
    define_method<void(cv::videostab::InpaintingPipeline::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::InpaintingPipeline::inpaint);
  
  Class rb_cCvVideostabConsistentMosaicInpainter = define_class_under<cv::videostab::ConsistentMosaicInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ConsistentMosaicInpainter").
    define_constructor(Constructor<cv::videostab::ConsistentMosaicInpainter>()).
    define_method<void(cv::videostab::ConsistentMosaicInpainter::*)(float)>("set_stdev_thresh", &cv::videostab::ConsistentMosaicInpainter::setStdevThresh).
    define_method<float(cv::videostab::ConsistentMosaicInpainter::*)() const>("stdev_thresh", &cv::videostab::ConsistentMosaicInpainter::stdevThresh).
    define_method<void(cv::videostab::ConsistentMosaicInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ConsistentMosaicInpainter::inpaint);
  
  Class rb_cCvVideostabMotionInpainter = define_class_under<cv::videostab::MotionInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "MotionInpainter").
    define_constructor(Constructor<cv::videostab::MotionInpainter>()).
    define_method<void(cv::videostab::MotionInpainter::*)(cv::Ptr<cv::videostab::IDenseOptFlowEstimator>)>("set_opt_flow_estimator", &cv::videostab::MotionInpainter::setOptFlowEstimator).
    define_method<cv::Ptr<cv::videostab::IDenseOptFlowEstimator>(cv::videostab::MotionInpainter::*)() const>("opt_flow_estimator", &cv::videostab::MotionInpainter::optFlowEstimator).
    define_method<void(cv::videostab::MotionInpainter::*)(float)>("set_flow_error_threshold", &cv::videostab::MotionInpainter::setFlowErrorThreshold).
    define_method<float(cv::videostab::MotionInpainter::*)() const>("flow_error_threshold", &cv::videostab::MotionInpainter::flowErrorThreshold).
    define_method<void(cv::videostab::MotionInpainter::*)(float)>("set_dist_threshold", &cv::videostab::MotionInpainter::setDistThreshold).
    define_method<float(cv::videostab::MotionInpainter::*)() const>("dist_thresh", &cv::videostab::MotionInpainter::distThresh).
    define_method<void(cv::videostab::MotionInpainter::*)(int)>("set_border_mode", &cv::videostab::MotionInpainter::setBorderMode).
    define_method<int(cv::videostab::MotionInpainter::*)() const>("border_mode", &cv::videostab::MotionInpainter::borderMode).
    define_method<void(cv::videostab::MotionInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::MotionInpainter::inpaint);
  
  Class rb_cCvVideostabColorAverageInpainter = define_class_under<cv::videostab::ColorAverageInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ColorAverageInpainter").
    define_method<void(cv::videostab::ColorAverageInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ColorAverageInpainter::inpaint);
  
  Class rb_cCvVideostabColorInpainter = define_class_under<cv::videostab::ColorInpainter, cv::videostab::InpainterBase>(rb_mCvVideostab, "ColorInpainter").
    define_constructor(Constructor<cv::videostab::ColorInpainter, int, double>()).
    define_method<void(cv::videostab::ColorInpainter::*)(int, cv::Mat&, cv::Mat&)>("inpaint", &cv::videostab::ColorInpainter::inpaint);
  
  rb_mCvVideostab.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, float, const cv::Mat&, const cv::Mat&, cv::Mat&)>("calc_flow_mask", &cv::videostab::calcFlowMask);
  
  rb_mCvVideostab.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, const cv::Mat&, float, cv::Mat&, cv::Mat&)>("complete_frame_according_to_flow", &cv::videostab::completeFrameAccordingToFlow);
}