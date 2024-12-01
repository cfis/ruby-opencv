#include <opencv2/datasets/track_alov.hpp>
#include "track_alov-rb.hpp"

using namespace Rice;

extern "C"
void Init_TrackAlov()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsTRACKAlovObj = define_class_under<cv::datasets::TRACK_alovObj, cv::datasets::Object>(rb_mCvDatasets, "TRACKAlovObj").
    define_attr("id", &cv::datasets::TRACK_alovObj::id).
    define_attr("image_path", &cv::datasets::TRACK_alovObj::imagePath).
    define_attr("gtbb", &cv::datasets::TRACK_alovObj::gtbb);
  
  Class rb_cCvDatasetsTRACKAlov = define_class_under<cv::datasets::TRACK_alov, cv::datasets::Dataset>(rb_mCvDatasets, "TRACKAlov").
    define_singleton_function<cv::Ptr<cv::datasets::TRACK_alov>(*)()>("create", &cv::datasets::TRACK_alov::create).
    define_method<void(cv::datasets::TRACK_alov::*)(const std::basic_string<char>&)>("load", &cv::datasets::TRACK_alov::load).
    define_method<void(cv::datasets::TRACK_alov::*)(const std::basic_string<char>&)>("load_annotated_only", &cv::datasets::TRACK_alov::loadAnnotatedOnly).
    define_method<int(cv::datasets::TRACK_alov::*)()>("get_datasets_num", &cv::datasets::TRACK_alov::getDatasetsNum).
    define_method<int(cv::datasets::TRACK_alov::*)(int)>("get_dataset_length", &cv::datasets::TRACK_alov::getDatasetLength).
    define_method<bool(cv::datasets::TRACK_alov::*)(int)>("init_dataset", &cv::datasets::TRACK_alov::initDataset).
    define_method<bool(cv::datasets::TRACK_alov::*)(cv::Mat&)>("get_next_frame", &cv::datasets::TRACK_alov::getNextFrame).
    define_method<std::vector<cv::Point_<float>>(cv::datasets::TRACK_alov::*)()>("get_next_gt", &cv::datasets::TRACK_alov::getNextGT).
    define_method<bool(cv::datasets::TRACK_alov::*)(cv::Mat&, int, int)>("get_frame", &cv::datasets::TRACK_alov::getFrame).
    define_method<std::vector<cv::Point_<float>>(cv::datasets::TRACK_alov::*)(int, int)>("get_gt", &cv::datasets::TRACK_alov::getGT);
}