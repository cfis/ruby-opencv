#include <opencv2/datasets/slam_kitti.hpp>
#include "slam_kitti-rb.hpp"

using namespace Rice;

extern "C"
void Init_SlamKitti()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  Class rb_cCvDatasetsPose = define_class_under<cv::datasets::pose>(rb_mCvDatasets, "Pose").
    define_attr("elem", &cv::datasets::pose::elem);
  
  Class rb_cCvDatasetsSLAMKittiObj = define_class_under<cv::datasets::SLAM_kittiObj, cv::datasets::Object>(rb_mCvDatasets, "SLAMKittiObj").
    define_attr("name", &cv::datasets::SLAM_kittiObj::name).
    define_attr("images", &cv::datasets::SLAM_kittiObj::images).
    define_attr("velodyne", &cv::datasets::SLAM_kittiObj::velodyne).
    define_attr("times", &cv::datasets::SLAM_kittiObj::times).
    define_attr("p", &cv::datasets::SLAM_kittiObj::p).
    define_attr("poses_array", &cv::datasets::SLAM_kittiObj::posesArray);
  
  Class rb_cCvDatasetsSLAMKitti = define_class_under<cv::datasets::SLAM_kitti, cv::datasets::Dataset>(rb_mCvDatasets, "SLAMKitti").
    define_method<void(cv::datasets::SLAM_kitti::*)(const std::basic_string<char>&)>("load", &cv::datasets::SLAM_kitti::load).
    define_singleton_function<cv::Ptr<cv::datasets::SLAM_kitti>(*)()>("create", &cv::datasets::SLAM_kitti::create);
}