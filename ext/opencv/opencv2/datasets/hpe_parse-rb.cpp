#include <opencv2/datasets/hpe_parse.hpp>
#include "hpe_parse-rb.hpp"

using namespace Rice;

extern "C"
void Init_HpeParse()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsHPEParseObj = define_class_under<cv::datasets::HPE_parseObj, cv::datasets::Object>(rb_mCvDatasets, "HPEParseObj").
    define_attr("name", &cv::datasets::HPE_parseObj::name);
  
  Class rb_cCvDatasetsHPEParse = define_class_under<cv::datasets::HPE_parse, cv::datasets::Dataset>(rb_mCvDatasets, "HPEParse").
    define_method<void(cv::datasets::HPE_parse::*)(const std::basic_string<char>&)>("load", &cv::datasets::HPE_parse::load).
    define_singleton_function<cv::Ptr<cv::datasets::HPE_parse>(*)()>("create", &cv::datasets::HPE_parse::create);
}