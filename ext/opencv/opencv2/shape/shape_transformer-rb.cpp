#include <opencv2/shape/shape_transformer.hpp>
#include "shape_transformer-rb.hpp"

using namespace Rice;

extern "C"
void Init_ShapeTransformer()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvShapeTransformer = define_class_under<cv::ShapeTransformer, cv::Algorithm>(rb_mCv, "ShapeTransformer").
    define_method<void(cv::ShapeTransformer::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::DMatch>&)>("estimate_transformation", &cv::ShapeTransformer::estimateTransformation).
    define_method<float(cv::ShapeTransformer::*)(const cv::_InputArray &, const cv::_OutputArray &)>("apply_transformation", &cv::ShapeTransformer::applyTransformation).
    define_method<void(cv::ShapeTransformer::*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, const cv::Scalar_<double>&) const>("warp_image", &cv::ShapeTransformer::warpImage);
  
  Class rb_cCvThinPlateSplineShapeTransformer = define_class_under<cv::ThinPlateSplineShapeTransformer, cv::ShapeTransformer>(rb_mCv, "ThinPlateSplineShapeTransformer").
    define_method<void(cv::ThinPlateSplineShapeTransformer::*)(double)>("set_regularization_parameter", &cv::ThinPlateSplineShapeTransformer::setRegularizationParameter).
    define_method<double(cv::ThinPlateSplineShapeTransformer::*)() const>("get_regularization_parameter", &cv::ThinPlateSplineShapeTransformer::getRegularizationParameter);
  
  rb_mCv.define_module_function<cv::Ptr<cv::ThinPlateSplineShapeTransformer>(*)(double)>("create_thin_plate_spline_shape_transformer", &cv::createThinPlateSplineShapeTransformer);
  
  Class rb_cCvAffineTransformer = define_class_under<cv::AffineTransformer, cv::ShapeTransformer>(rb_mCv, "AffineTransformer").
    define_method<void(cv::AffineTransformer::*)(bool)>("set_full_affine", &cv::AffineTransformer::setFullAffine).
    define_method<bool(cv::AffineTransformer::*)() const>("get_full_affine", &cv::AffineTransformer::getFullAffine);
  
  rb_mCv.define_module_function<cv::Ptr<cv::AffineTransformer>(*)(bool)>("create_affine_transformer", &cv::createAffineTransformer);
}