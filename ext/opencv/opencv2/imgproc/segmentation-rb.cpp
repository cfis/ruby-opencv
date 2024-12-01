#include <opencv2/imgproc/segmentation.hpp>
#include "segmentation-rb.hpp"

using namespace Rice;



void Init_Segmentation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvSegmentation = define_module_under(rb_mCv, "Segmentation");
  
  Class rb_cCvSegmentationIntelligentScissorsMB = define_class_under<cv::segmentation::IntelligentScissorsMB>(rb_mCvSegmentation, "IntelligentScissorsMB").
    define_constructor(Constructor<cv::segmentation::IntelligentScissorsMB>()).
    define_method("set_weights", &cv::segmentation::IntelligentScissorsMB::setWeights,
      Arg("weight_non_edge"), Arg("weight_gradient_direction"), Arg("weight_gradient_magnitude")).
    define_method("set_gradient_magnitude_max_limit", &cv::segmentation::IntelligentScissorsMB::setGradientMagnitudeMaxLimit,
      Arg("gradient_magnitude_threshold_max") = static_cast<float>(0.0f)).
    define_method("set_edge_feature_zero_crossing_parameters", &cv::segmentation::IntelligentScissorsMB::setEdgeFeatureZeroCrossingParameters,
      Arg("gradient_magnitude_min_value") = static_cast<float>(0.0f)).
    define_method("set_edge_feature_canny_parameters", &cv::segmentation::IntelligentScissorsMB::setEdgeFeatureCannyParameters,
      Arg("threshold1"), Arg("threshold2"), Arg("aperture_size") = static_cast<int>(3), Arg("l2gradient") = static_cast<bool>(false)).
    define_method("apply_image", &cv::segmentation::IntelligentScissorsMB::applyImage,
      Arg("image")).
    define_method("apply_image_features", &cv::segmentation::IntelligentScissorsMB::applyImageFeatures,
      Arg("non_edge"), Arg("gradient_direction"), Arg("gradient_magnitude"), Arg("image") = static_cast<InputArray>(noArray())).
    define_method("build_map", &cv::segmentation::IntelligentScissorsMB::buildMap,
      Arg("source_pt")).
    define_method("get_contour", &cv::segmentation::IntelligentScissorsMB::getContour,
      Arg("target_pt"), Arg("contour"), Arg("backward") = static_cast<bool>(false)).
    define_method("get_impl", &cv::segmentation::IntelligentScissorsMB::getImpl);
  

}