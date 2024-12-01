#include <opencv2/shape/shape_distance.hpp>
#include "shape_distance-rb.hpp"

using namespace Rice;

extern "C"
void Init_ShapeDistance()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvShapeDistanceExtractor = define_class_under<cv::ShapeDistanceExtractor, cv::Algorithm>(rb_mCv, "ShapeDistanceExtractor").
    define_method<float(cv::ShapeDistanceExtractor::*)(const cv::_InputArray &, const cv::_InputArray &)>("compute_distance", &cv::ShapeDistanceExtractor::computeDistance);
  
  Class rb_cCvShapeContextDistanceExtractor = define_class_under<cv::ShapeContextDistanceExtractor, cv::ShapeDistanceExtractor>(rb_mCv, "ShapeContextDistanceExtractor").
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_angular_bins", &cv::ShapeContextDistanceExtractor::setAngularBins).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_angular_bins", &cv::ShapeContextDistanceExtractor::getAngularBins).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_radial_bins", &cv::ShapeContextDistanceExtractor::setRadialBins).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_radial_bins", &cv::ShapeContextDistanceExtractor::getRadialBins).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_inner_radius", &cv::ShapeContextDistanceExtractor::setInnerRadius).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_inner_radius", &cv::ShapeContextDistanceExtractor::getInnerRadius).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_outer_radius", &cv::ShapeContextDistanceExtractor::setOuterRadius).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_outer_radius", &cv::ShapeContextDistanceExtractor::getOuterRadius).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(bool)>("set_rotation_invariant", &cv::ShapeContextDistanceExtractor::setRotationInvariant).
    define_method<bool(cv::ShapeContextDistanceExtractor::*)() const>("get_rotation_invariant", &cv::ShapeContextDistanceExtractor::getRotationInvariant).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_shape_context_weight", &cv::ShapeContextDistanceExtractor::setShapeContextWeight).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_shape_context_weight", &cv::ShapeContextDistanceExtractor::getShapeContextWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_image_appearance_weight", &cv::ShapeContextDistanceExtractor::setImageAppearanceWeight).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_image_appearance_weight", &cv::ShapeContextDistanceExtractor::getImageAppearanceWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_bending_energy_weight", &cv::ShapeContextDistanceExtractor::setBendingEnergyWeight).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_bending_energy_weight", &cv::ShapeContextDistanceExtractor::getBendingEnergyWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(const cv::_InputArray &, const cv::_InputArray &)>("set_images", &cv::ShapeContextDistanceExtractor::setImages).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(const cv::_OutputArray &, const cv::_OutputArray &) const>("get_images", &cv::ShapeContextDistanceExtractor::getImages).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_iterations", &cv::ShapeContextDistanceExtractor::setIterations).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_iterations", &cv::ShapeContextDistanceExtractor::getIterations).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::Ptr<cv::HistogramCostExtractor>)>("set_cost_extractor", &cv::ShapeContextDistanceExtractor::setCostExtractor).
    define_method<cv::Ptr<cv::HistogramCostExtractor>(cv::ShapeContextDistanceExtractor::*)() const>("get_cost_extractor", &cv::ShapeContextDistanceExtractor::getCostExtractor).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_std_dev", &cv::ShapeContextDistanceExtractor::setStdDev).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_std_dev", &cv::ShapeContextDistanceExtractor::getStdDev).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::Ptr<cv::ShapeTransformer>)>("set_transform_algorithm", &cv::ShapeContextDistanceExtractor::setTransformAlgorithm).
    define_method<cv::Ptr<cv::ShapeTransformer>(cv::ShapeContextDistanceExtractor::*)() const>("get_transform_algorithm", &cv::ShapeContextDistanceExtractor::getTransformAlgorithm);
  
  rb_mCv.define_module_function<cv::Ptr<cv::ShapeContextDistanceExtractor>(*)(int, int, float, float, int, const cv::Ptr<cv::HistogramCostExtractor>&, const cv::Ptr<cv::ShapeTransformer>&)>("create_shape_context_distance_extractor", &cv::createShapeContextDistanceExtractor);
  
  Class rb_cCvHausdorffDistanceExtractor = define_class_under<cv::HausdorffDistanceExtractor, cv::ShapeDistanceExtractor>(rb_mCv, "HausdorffDistanceExtractor").
    define_method<void(cv::HausdorffDistanceExtractor::*)(int)>("set_distance_flag", &cv::HausdorffDistanceExtractor::setDistanceFlag).
    define_method<int(cv::HausdorffDistanceExtractor::*)() const>("get_distance_flag", &cv::HausdorffDistanceExtractor::getDistanceFlag).
    define_method<void(cv::HausdorffDistanceExtractor::*)(float)>("set_rank_proportion", &cv::HausdorffDistanceExtractor::setRankProportion).
    define_method<float(cv::HausdorffDistanceExtractor::*)() const>("get_rank_proportion", &cv::HausdorffDistanceExtractor::getRankProportion);
  
  rb_mCv.define_module_function<cv::Ptr<cv::HausdorffDistanceExtractor>(*)(int, float)>("create_hausdorff_distance_extractor", &cv::createHausdorffDistanceExtractor);
}