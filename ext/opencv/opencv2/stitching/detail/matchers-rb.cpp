#include <opencv2/stitching/detail/matchers.hpp>
#include "matchers-rb.hpp"

using namespace Rice;

extern "C"
void Init_Matchers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailImageFeatures = define_class_under<cv::detail::ImageFeatures>(rb_mCvDetail, "ImageFeatures").
    define_attr("img_idx", &cv::detail::ImageFeatures::img_idx).
    define_attr("img_size", &cv::detail::ImageFeatures::img_size).
    define_attr("keypoints", &cv::detail::ImageFeatures::keypoints).
    define_attr("descriptors", &cv::detail::ImageFeatures::descriptors).
    define_method<std::vector<cv::KeyPoint>(cv::detail::ImageFeatures::*)()>("get_keypoints", &cv::detail::ImageFeatures::getKeypoints);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::Ptr<cv::Feature2D>&, const cv::_InputArray &, std::vector<cv::detail::ImageFeatures>&, const cv::_InputArray &)>("compute_image_features", &cv::detail::computeImageFeatures);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::Ptr<cv::Feature2D>&, const cv::_InputArray &, cv::detail::ImageFeatures&, const cv::_InputArray &)>("compute_image_features", &cv::detail::computeImageFeatures);
  
  Class rb_cCvDetailMatchesInfo = define_class_under<cv::detail::MatchesInfo>(rb_mCvDetail, "MatchesInfo").
    define_constructor(Constructor<cv::detail::MatchesInfo>()).
    define_constructor(Constructor<cv::detail::MatchesInfo, const cv::detail::MatchesInfo&>()).
    define_method<cv::detail::MatchesInfo&(cv::detail::MatchesInfo::*)(const cv::detail::MatchesInfo&)>("operator=", &cv::detail::MatchesInfo::operator=).
    define_attr("src_img_idx", &cv::detail::MatchesInfo::src_img_idx).
    define_attr("dst_img_idx", &cv::detail::MatchesInfo::dst_img_idx).
    define_attr("matches", &cv::detail::MatchesInfo::matches).
    define_attr("inliers_mask", &cv::detail::MatchesInfo::inliers_mask).
    define_attr("num_inliers", &cv::detail::MatchesInfo::num_inliers).
    define_attr("h", &cv::detail::MatchesInfo::H).
    define_attr("confidence", &cv::detail::MatchesInfo::confidence).
    define_method<std::vector<cv::DMatch>(cv::detail::MatchesInfo::*)()>("get_matches", &cv::detail::MatchesInfo::getMatches).
    define_method<std::vector<unsigned char>(cv::detail::MatchesInfo::*)()>("get_inliers", &cv::detail::MatchesInfo::getInliers);
  
  Class rb_cCvDetailFeaturesMatcher = define_class_under<cv::detail::FeaturesMatcher>(rb_mCvDetail, "FeaturesMatcher").
    define_method<void(cv::detail::FeaturesMatcher::*)(const cv::detail::ImageFeatures&, const cv::detail::ImageFeatures&, cv::detail::MatchesInfo&)>("operator()", &cv::detail::FeaturesMatcher::operator()).
    define_method<void(cv::detail::FeaturesMatcher::*)(const std::vector<cv::detail::ImageFeatures>&, std::vector<cv::detail::MatchesInfo>&, const cv::UMat&)>("operator()", &cv::detail::FeaturesMatcher::operator()).
    define_method<bool(cv::detail::FeaturesMatcher::*)() const>("is_thread_safe", &cv::detail::FeaturesMatcher::isThreadSafe).
    define_method<void(cv::detail::FeaturesMatcher::*)()>("collect_garbage", &cv::detail::FeaturesMatcher::collectGarbage).
    define_constructor(Constructor<cv::detail::FeaturesMatcher, bool>());
  
  Class rb_cCvDetailBestOf2NearestMatcher = define_class_under<cv::detail::BestOf2NearestMatcher, cv::detail::FeaturesMatcher>(rb_mCvDetail, "BestOf2NearestMatcher").
    define_constructor(Constructor<cv::detail::BestOf2NearestMatcher, bool, float, int, int, double>()).
    define_method<void(cv::detail::BestOf2NearestMatcher::*)()>("collect_garbage", &cv::detail::BestOf2NearestMatcher::collectGarbage).
    define_singleton_function<cv::Ptr<cv::detail::BestOf2NearestMatcher>(*)(bool, float, int, int, double)>("create", &cv::detail::BestOf2NearestMatcher::create);
  
  Class rb_cCvDetailBestOf2NearestRangeMatcher = define_class_under<cv::detail::BestOf2NearestRangeMatcher, cv::detail::BestOf2NearestMatcher>(rb_mCvDetail, "BestOf2NearestRangeMatcher").
    define_constructor(Constructor<cv::detail::BestOf2NearestRangeMatcher, int, bool, float, int, int>());
  
  Class rb_cCvDetailAffineBestOf2NearestMatcher = define_class_under<cv::detail::AffineBestOf2NearestMatcher, cv::detail::BestOf2NearestMatcher>(rb_mCvDetail, "AffineBestOf2NearestMatcher").
    define_constructor(Constructor<cv::detail::AffineBestOf2NearestMatcher, bool, bool, float, int>());
}