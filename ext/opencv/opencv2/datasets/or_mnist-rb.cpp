#include <opencv2/datasets/or_mnist.hpp>
#include "or_mnist-rb.hpp"

using namespace Rice;

extern "C"
void Init_OrMnist()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsORMnistObj = define_class_under<cv::datasets::OR_mnistObj, cv::datasets::Object>(rb_mCvDatasets, "ORMnistObj").
    define_attr("label", &cv::datasets::OR_mnistObj::label).
    define_attr("image", &cv::datasets::OR_mnistObj::image);
  
  Class rb_cCvDatasetsORMnist = define_class_under<cv::datasets::OR_mnist, cv::datasets::Dataset>(rb_mCvDatasets, "ORMnist").
    define_method<void(cv::datasets::OR_mnist::*)(const std::basic_string<char>&)>("load", &cv::datasets::OR_mnist::load).
    define_singleton_function<cv::Ptr<cv::datasets::OR_mnist>(*)()>("create", &cv::datasets::OR_mnist::create);
}