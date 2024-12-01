#include <opencv2/stitching/detail/exposure_compensate.hpp>
#include "exposure_compensate-rb.hpp"

using namespace Rice;

extern "C"
void Init_ExposureCompensate()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailExposureCompensator = define_class_under<cv::detail::ExposureCompensator>(rb_mCvDetail, "ExposureCompensator").
    define_constructor(Constructor<cv::detail::ExposureCompensator>()).
    define_singleton_function<cv::Ptr<cv::detail::ExposureCompensator>(*)(int)>("create_default", &cv::detail::ExposureCompensator::createDefault).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<cv::UMat>&)>("feed", &cv::detail::ExposureCompensator::feed).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::ExposureCompensator::feed).
    define_method<void(cv::detail::ExposureCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::ExposureCompensator::apply).
    define_method<void(cv::detail::ExposureCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::ExposureCompensator::getMatGains).
    define_method<void(cv::detail::ExposureCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::ExposureCompensator::setMatGains).
    define_method<void(cv::detail::ExposureCompensator::*)(bool)>("set_update_gain", &cv::detail::ExposureCompensator::setUpdateGain).
    define_method<bool(cv::detail::ExposureCompensator::*)()>("get_update_gain", &cv::detail::ExposureCompensator::getUpdateGain);
  
  
  Class rb_cCvDetailNoExposureCompensator = define_class_under<cv::detail::NoExposureCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "NoExposureCompensator").
    define_method<void(cv::detail::NoExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::NoExposureCompensator::feed).
    define_method<void(cv::detail::NoExposureCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::NoExposureCompensator::apply).
    define_method<void(cv::detail::NoExposureCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::NoExposureCompensator::getMatGains).
    define_method<void(cv::detail::NoExposureCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::NoExposureCompensator::setMatGains);
  
  Class rb_cCvDetailGainCompensator = define_class_under<cv::detail::GainCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "GainCompensator").
    define_constructor(Constructor<cv::detail::GainCompensator>()).
    define_constructor(Constructor<cv::detail::GainCompensator, int>()).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::GainCompensator::feed).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("single_feed", &cv::detail::GainCompensator::singleFeed).
    define_method<void(cv::detail::GainCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::GainCompensator::apply).
    define_method<void(cv::detail::GainCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::GainCompensator::getMatGains).
    define_method<void(cv::detail::GainCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::GainCompensator::setMatGains).
    define_method<void(cv::detail::GainCompensator::*)(int)>("set_nr_feeds", &cv::detail::GainCompensator::setNrFeeds).
    define_method<int(cv::detail::GainCompensator::*)()>("get_nr_feeds", &cv::detail::GainCompensator::getNrFeeds).
    define_method<void(cv::detail::GainCompensator::*)(double)>("set_similarity_threshold", &cv::detail::GainCompensator::setSimilarityThreshold).
    define_method<double(cv::detail::GainCompensator::*)() const>("get_similarity_threshold", &cv::detail::GainCompensator::getSimilarityThreshold).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&)>("prepare_similarity_mask", &cv::detail::GainCompensator::prepareSimilarityMask).
    define_method<std::vector<double>(cv::detail::GainCompensator::*)() const>("gains", &cv::detail::GainCompensator::gains);
  
  Class rb_cCvDetailChannelsCompensator = define_class_under<cv::detail::ChannelsCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "ChannelsCompensator").
    define_constructor(Constructor<cv::detail::ChannelsCompensator, int>()).
    define_method<void(cv::detail::ChannelsCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::ChannelsCompensator::feed).
    define_method<void(cv::detail::ChannelsCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::ChannelsCompensator::apply).
    define_method<void(cv::detail::ChannelsCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::ChannelsCompensator::getMatGains).
    define_method<void(cv::detail::ChannelsCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::ChannelsCompensator::setMatGains).
    define_method<void(cv::detail::ChannelsCompensator::*)(int)>("set_nr_feeds", &cv::detail::ChannelsCompensator::setNrFeeds).
    define_method<int(cv::detail::ChannelsCompensator::*)()>("get_nr_feeds", &cv::detail::ChannelsCompensator::getNrFeeds).
    define_method<void(cv::detail::ChannelsCompensator::*)(double)>("set_similarity_threshold", &cv::detail::ChannelsCompensator::setSimilarityThreshold).
    define_method<double(cv::detail::ChannelsCompensator::*)() const>("get_similarity_threshold", &cv::detail::ChannelsCompensator::getSimilarityThreshold).
    define_method<std::vector<cv::Scalar_<double>>(cv::detail::ChannelsCompensator::*)() const>("gains", &cv::detail::ChannelsCompensator::gains);
  
  Class rb_cCvDetailBlocksCompensator = define_class_under<cv::detail::BlocksCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "BlocksCompensator").
    define_constructor(Constructor<cv::detail::BlocksCompensator, int, int, int>()).
    define_method<void(cv::detail::BlocksCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::BlocksCompensator::apply).
    define_method<void(cv::detail::BlocksCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::BlocksCompensator::getMatGains).
    define_method<void(cv::detail::BlocksCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::BlocksCompensator::setMatGains).
    define_method<void(cv::detail::BlocksCompensator::*)(int)>("set_nr_feeds", &cv::detail::BlocksCompensator::setNrFeeds).
    define_method<int(cv::detail::BlocksCompensator::*)()>("get_nr_feeds", &cv::detail::BlocksCompensator::getNrFeeds).
    define_method<void(cv::detail::BlocksCompensator::*)(double)>("set_similarity_threshold", &cv::detail::BlocksCompensator::setSimilarityThreshold).
    define_method<double(cv::detail::BlocksCompensator::*)() const>("get_similarity_threshold", &cv::detail::BlocksCompensator::getSimilarityThreshold).
    define_method<void(cv::detail::BlocksCompensator::*)(int, int)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize).
    define_method<void(cv::detail::BlocksCompensator::*)(cv::Size_<int>)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize).
    define_method<cv::Size_<int>(cv::detail::BlocksCompensator::*)() const>("get_block_size", &cv::detail::BlocksCompensator::getBlockSize).
    define_method<void(cv::detail::BlocksCompensator::*)(int)>("set_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::setNrGainsFilteringIterations).
    define_method<int(cv::detail::BlocksCompensator::*)() const>("get_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::getNrGainsFilteringIterations);
  
  Class rb_cCvDetailBlocksGainCompensator = define_class_under<cv::detail::BlocksGainCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksGainCompensator").
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int>()).
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int, int>()).
    define_method<void(cv::detail::BlocksGainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::BlocksGainCompensator::feed).
    define_method<void(cv::detail::BlocksGainCompensator::*)(int, cv::Point_<int>, const cv::_InputOutputArray &, const cv::_InputArray &)>("apply", &cv::detail::BlocksGainCompensator::apply).
    define_method<void(cv::detail::BlocksGainCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::BlocksGainCompensator::getMatGains).
    define_method<void(cv::detail::BlocksGainCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::BlocksGainCompensator::setMatGains);
  
  Class rb_cCvDetailBlocksChannelsCompensator = define_class_under<cv::detail::BlocksChannelsCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksChannelsCompensator").
    define_constructor(Constructor<cv::detail::BlocksChannelsCompensator, int, int, int>()).
    define_method<void(cv::detail::BlocksChannelsCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::BlocksChannelsCompensator::feed);
}