#include <opencv2/datasets/hpe_humaneva.hpp>
#include "hpe_humaneva-rb.hpp"

using namespace Rice;

extern "C"
void Init_HpeHumaneva()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsHPEHumanevaObj = define_class_under<cv::datasets::HPE_humanevaObj, cv::datasets::Object>(rb_mCvDatasets, "HPEHumanevaObj").
    define_attr("person", &cv::datasets::HPE_humanevaObj::person).
    define_attr("action", &cv::datasets::HPE_humanevaObj::action).
    define_attr("type1", &cv::datasets::HPE_humanevaObj::type1).
    define_attr("type2", &cv::datasets::HPE_humanevaObj::type2).
    define_attr("ofs", &cv::datasets::HPE_humanevaObj::ofs).
    define_attr("file_name", &cv::datasets::HPE_humanevaObj::fileName).
    define_attr("image_names", &cv::datasets::HPE_humanevaObj::imageNames);
  
  Enum<cv::datasets::datasetType> rb_cCvDatasetsDatasetType = define_enum<cv::datasets::datasetType>("DatasetType", rb_mCvDatasets).
    define_value("humaneva_1", cv::datasets::datasetType::humaneva_1).
    define_value("humaneva_2", cv::datasets::datasetType::humaneva_2);
  
  Class rb_cCvDatasetsHPEHumaneva = define_class_under<cv::datasets::HPE_humaneva, cv::datasets::Dataset>(rb_mCvDatasets, "HPEHumaneva").
    define_method<void(cv::datasets::HPE_humaneva::*)(const std::basic_string<char>&)>("load", &cv::datasets::HPE_humaneva::load).
    define_singleton_function<cv::Ptr<cv::datasets::HPE_humaneva>(*)(int)>("create", &cv::datasets::HPE_humaneva::create);
}