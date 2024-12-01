#include <opencv2/hfs.hpp>
#include "hfs-rb.hpp"

using namespace Rice;

extern "C"
void Init_Hfs()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHfs = define_module_under(rb_mCv, "Hfs");
  
  Class rb_cCvHfsHfsSegment = define_class_under<cv::hfs::HfsSegment, cv::Algorithm>(rb_mCvHfs, "HfsSegment").
    define_method<void(cv::hfs::HfsSegment::*)(float)>("set_seg_egb_threshold_i", &cv::hfs::HfsSegment::setSegEgbThresholdI).
    define_method<float(cv::hfs::HfsSegment::*)()>("get_seg_egb_threshold_i", &cv::hfs::HfsSegment::getSegEgbThresholdI).
    define_method<void(cv::hfs::HfsSegment::*)(int)>("set_min_region_size_i", &cv::hfs::HfsSegment::setMinRegionSizeI).
    define_method<int(cv::hfs::HfsSegment::*)()>("get_min_region_size_i", &cv::hfs::HfsSegment::getMinRegionSizeI).
    define_method<void(cv::hfs::HfsSegment::*)(float)>("set_seg_egb_threshold_ii", &cv::hfs::HfsSegment::setSegEgbThresholdII).
    define_method<float(cv::hfs::HfsSegment::*)()>("get_seg_egb_threshold_ii", &cv::hfs::HfsSegment::getSegEgbThresholdII).
    define_method<void(cv::hfs::HfsSegment::*)(int)>("set_min_region_size_ii", &cv::hfs::HfsSegment::setMinRegionSizeII).
    define_method<int(cv::hfs::HfsSegment::*)()>("get_min_region_size_ii", &cv::hfs::HfsSegment::getMinRegionSizeII).
    define_method<void(cv::hfs::HfsSegment::*)(float)>("set_spatial_weight", &cv::hfs::HfsSegment::setSpatialWeight).
    define_method<float(cv::hfs::HfsSegment::*)()>("get_spatial_weight", &cv::hfs::HfsSegment::getSpatialWeight).
    define_method<void(cv::hfs::HfsSegment::*)(int)>("set_slic_spixel_size", &cv::hfs::HfsSegment::setSlicSpixelSize).
    define_method<int(cv::hfs::HfsSegment::*)()>("get_slic_spixel_size", &cv::hfs::HfsSegment::getSlicSpixelSize).
    define_method<void(cv::hfs::HfsSegment::*)(int)>("set_num_slic_iter", &cv::hfs::HfsSegment::setNumSlicIter).
    define_method<int(cv::hfs::HfsSegment::*)()>("get_num_slic_iter", &cv::hfs::HfsSegment::getNumSlicIter).
    define_method<cv::Mat(cv::hfs::HfsSegment::*)(const cv::_InputArray &, bool)>("perform_segment_gpu", &cv::hfs::HfsSegment::performSegmentGpu).
    define_method<cv::Mat(cv::hfs::HfsSegment::*)(const cv::_InputArray &, bool)>("perform_segment_cpu", &cv::hfs::HfsSegment::performSegmentCpu).
    define_singleton_function<cv::Ptr<cv::hfs::HfsSegment>(*)(int, int, float, int, float, int, float, int, int)>("create", &cv::hfs::HfsSegment::create);
}