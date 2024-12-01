#include <opencv2/datasets/dataset.hpp>
#include "dataset-rb.hpp"

using namespace Rice;

extern "C"
void Init_Dataset()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsObject = define_class_under<cv::datasets::Object>(rb_mCvDatasets, "Object");
  
  
  Class rb_cCvDatasetsDataset = define_class_under<cv::datasets::Dataset>(rb_mCvDatasets, "Dataset").
    define_constructor(Constructor<cv::datasets::Dataset>()).
    define_method<void(cv::datasets::Dataset::*)(const std::basic_string<char>&)>("load", &cv::datasets::Dataset::load).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_train", &cv::datasets::Dataset::getTrain).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_test", &cv::datasets::Dataset::getTest).
    define_method<std::vector<cv::Ptr<cv::datasets::Object>>&(cv::datasets::Dataset::*)(int)>("get_validation", &cv::datasets::Dataset::getValidation).
    define_method<int(cv::datasets::Dataset::*)() const>("get_num_splits", &cv::datasets::Dataset::getNumSplits);
}