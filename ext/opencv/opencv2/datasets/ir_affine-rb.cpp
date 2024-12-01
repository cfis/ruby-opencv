#include <opencv2/datasets/ir_affine.hpp>
#include "ir_affine-rb.hpp"

using namespace Rice;

extern "C"
void Init_IrAffine()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsIRAffineObj = define_class_under<cv::datasets::IR_affineObj, cv::datasets::Object>(rb_mCvDatasets, "IRAffineObj").
    define_attr("image_name", &cv::datasets::IR_affineObj::imageName).
    define_attr("mat", &cv::datasets::IR_affineObj::mat);
  
  Class rb_cCvDatasetsIRAffine = define_class_under<cv::datasets::IR_affine, cv::datasets::Dataset>(rb_mCvDatasets, "IRAffine").
    define_method<void(cv::datasets::IR_affine::*)(const std::basic_string<char>&)>("load", &cv::datasets::IR_affine::load).
    define_singleton_function<cv::Ptr<cv::datasets::IR_affine>(*)()>("create", &cv::datasets::IR_affine::create);
}