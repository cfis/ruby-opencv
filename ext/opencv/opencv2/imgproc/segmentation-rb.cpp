#include <opencv2/imgproc/segmentation.hpp>
#include "segmentation-rb.hpp"

using namespace Rice;

extern "C"
void Init_Segmentation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvSegmentation = define_module_under(rb_mCv, "Segmentation");
  
  Class rb_cCvSegmentationIntelligentScissorsMB = define_class_under<cv::segmentation::IntelligentScissorsMB>(rb_mCvSegmentation, "IntelligentScissorsMB").
    define_constructor(Constructor<cv::segmentation::IntelligentScissorsMB>()).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(float, float, float)>("set_weights", &cv::segmentation::IntelligentScissorsMB::setWeights).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(float)>("set_gradient_magnitude_max_limit", &cv::segmentation::IntelligentScissorsMB::setGradientMagnitudeMaxLimit).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(float)>("set_edge_feature_zero_crossing_parameters", &cv::segmentation::IntelligentScissorsMB::setEdgeFeatureZeroCrossingParameters).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(double, double, int, bool)>("set_edge_feature_canny_parameters", &cv::segmentation::IntelligentScissorsMB::setEdgeFeatureCannyParameters).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(const cv::_InputArray &)>("apply_image", &cv::segmentation::IntelligentScissorsMB::applyImage).
    define_method<cv::segmentation::IntelligentScissorsMB&(cv::segmentation::IntelligentScissorsMB::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("apply_image_features", &cv::segmentation::IntelligentScissorsMB::applyImageFeatures).
    define_method<void(cv::segmentation::IntelligentScissorsMB::*)(const cv::Point_<int>&)>("build_map", &cv::segmentation::IntelligentScissorsMB::buildMap).
    define_method<void(cv::segmentation::IntelligentScissorsMB::*)(const cv::Point_<int>&, const cv::_OutputArray &, bool) const>("get_contour", &cv::segmentation::IntelligentScissorsMB::getContour).
    define_method<cv::segmentation::IntelligentScissorsMB::Impl*(cv::segmentation::IntelligentScissorsMB::*)() const>("get_impl", &cv::segmentation::IntelligentScissorsMB::getImpl);
}