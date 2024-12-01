#include <opencv2/cudafeatures2d.hpp>
#include "cudafeatures2d-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudafeatures2d()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaDescriptorMatcher = define_class_under<cv::cuda::DescriptorMatcher, cv::Algorithm>(rb_mCvCuda, "DescriptorMatcher").
    define_singleton_function<cv::Ptr<cv::cuda::DescriptorMatcher>(*)(int)>("create_bf_matcher", &cv::cuda::DescriptorMatcher::createBFMatcher).
    define_method<bool(cv::cuda::DescriptorMatcher::*)() const>("is_mask_supported", &cv::cuda::DescriptorMatcher::isMaskSupported).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const std::vector<cv::cuda::GpuMat>&)>("add", &cv::cuda::DescriptorMatcher::add).
    define_method<const std::vector<cv::cuda::GpuMat>&(cv::cuda::DescriptorMatcher::*)() const>("get_train_descriptors", &cv::cuda::DescriptorMatcher::getTrainDescriptors).
    define_method<void(cv::cuda::DescriptorMatcher::*)()>("clear", &cv::cuda::DescriptorMatcher::clear).
    define_method<bool(cv::cuda::DescriptorMatcher::*)() const>("empty", &cv::cuda::DescriptorMatcher::empty).
    define_method<void(cv::cuda::DescriptorMatcher::*)()>("train", &cv::cuda::DescriptorMatcher::train).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::DMatch>&, const cv::_InputArray &)>("match", &cv::cuda::DescriptorMatcher::match).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<cv::DMatch>&, const std::vector<cv::cuda::GpuMat>&)>("match", &cv::cuda::DescriptorMatcher::match).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("match_async", &cv::cuda::DescriptorMatcher::matchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_OutputArray &, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("match_async", &cv::cuda::DescriptorMatcher::matchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<cv::DMatch>&)>("match_convert", &cv::cuda::DescriptorMatcher::matchConvert).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, int, const cv::_InputArray &, bool)>("knn_match", &cv::cuda::DescriptorMatcher::knnMatch).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, int, const std::vector<cv::cuda::GpuMat>&, bool)>("knn_match", &cv::cuda::DescriptorMatcher::knnMatch).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, cv::cuda::Stream&)>("knn_match_async", &cv::cuda::DescriptorMatcher::knnMatchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_OutputArray &, int, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("knn_match_async", &cv::cuda::DescriptorMatcher::knnMatchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, bool)>("knn_match_convert", &cv::cuda::DescriptorMatcher::knnMatchConvert).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, float, const cv::_InputArray &, bool)>("radius_match", &cv::cuda::DescriptorMatcher::radiusMatch).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, float, const std::vector<cv::cuda::GpuMat>&, bool)>("radius_match", &cv::cuda::DescriptorMatcher::radiusMatch).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, float, const cv::_InputArray &, cv::cuda::Stream&)>("radius_match_async", &cv::cuda::DescriptorMatcher::radiusMatchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_OutputArray &, float, const std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("radius_match_async", &cv::cuda::DescriptorMatcher::radiusMatchAsync).
    define_method<void(cv::cuda::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, bool)>("radius_match_convert", &cv::cuda::DescriptorMatcher::radiusMatchConvert);
  
  Class rb_cCvCudaFeature2DAsync = define_class_under<cv::cuda::Feature2DAsync, cv::Feature2D>(rb_mCvCuda, "Feature2DAsync").
    define_method<void(cv::cuda::Feature2DAsync::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("detect_async", &cv::cuda::Feature2DAsync::detectAsync).
    define_method<void(cv::cuda::Feature2DAsync::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute_async", &cv::cuda::Feature2DAsync::computeAsync).
    define_method<void(cv::cuda::Feature2DAsync::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("detect_and_compute_async", &cv::cuda::Feature2DAsync::detectAndComputeAsync).
    define_method<void(cv::cuda::Feature2DAsync::*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&)>("convert", &cv::cuda::Feature2DAsync::convert);
  
  Class rb_cCvCudaFastFeatureDetector = define_class_under<cv::cuda::FastFeatureDetector, cv::cuda::Feature2DAsync>(rb_mCvCuda, "FastFeatureDetector").
    define_singleton_attr("LOCATION_ROW", &FastFeatureDetector::LOCATION_ROW).
    define_singleton_attr("RESPONSE_ROW", &FastFeatureDetector::RESPONSE_ROW).
    define_singleton_attr("ROWS_COUNT", &FastFeatureDetector::ROWS_COUNT).
    define_singleton_attr("FEATURE_SIZE", &FastFeatureDetector::FEATURE_SIZE).
    define_singleton_function<cv::Ptr<cv::cuda::FastFeatureDetector>(*)(int, bool, int, int)>("create", &cv::cuda::FastFeatureDetector::create).
    define_method<void(cv::cuda::FastFeatureDetector::*)(int)>("set_threshold", &cv::cuda::FastFeatureDetector::setThreshold).
    define_method<void(cv::cuda::FastFeatureDetector::*)(int)>("set_max_num_points", &cv::cuda::FastFeatureDetector::setMaxNumPoints).
    define_method<int(cv::cuda::FastFeatureDetector::*)() const>("get_max_num_points", &cv::cuda::FastFeatureDetector::getMaxNumPoints);
  
  Class rb_cCvCudaORB = define_class_under<cv::cuda::ORB, cv::cuda::Feature2DAsync>(rb_mCvCuda, "ORB").
    define_singleton_attr("X_ROW", &ORB::X_ROW).
    define_singleton_attr("Y_ROW", &ORB::Y_ROW).
    define_singleton_attr("RESPONSE_ROW", &ORB::RESPONSE_ROW).
    define_singleton_attr("ANGLE_ROW", &ORB::ANGLE_ROW).
    define_singleton_attr("OCTAVE_ROW", &ORB::OCTAVE_ROW).
    define_singleton_attr("SIZE_ROW", &ORB::SIZE_ROW).
    define_singleton_attr("ROWS_COUNT", &ORB::ROWS_COUNT).
    define_singleton_function<cv::Ptr<cv::cuda::ORB>(*)(int, float, int, int, int, int, int, int, int, bool)>("create", &cv::cuda::ORB::create).
    define_method<void(cv::cuda::ORB::*)(int)>("set_max_features", &cv::cuda::ORB::setMaxFeatures).
    define_method<int(cv::cuda::ORB::*)() const>("get_max_features", &cv::cuda::ORB::getMaxFeatures).
    define_method<void(cv::cuda::ORB::*)(double)>("set_scale_factor", &cv::cuda::ORB::setScaleFactor).
    define_method<double(cv::cuda::ORB::*)() const>("get_scale_factor", &cv::cuda::ORB::getScaleFactor).
    define_method<void(cv::cuda::ORB::*)(int)>("set_n_levels", &cv::cuda::ORB::setNLevels).
    define_method<int(cv::cuda::ORB::*)() const>("get_n_levels", &cv::cuda::ORB::getNLevels).
    define_method<void(cv::cuda::ORB::*)(int)>("set_edge_threshold", &cv::cuda::ORB::setEdgeThreshold).
    define_method<int(cv::cuda::ORB::*)() const>("get_edge_threshold", &cv::cuda::ORB::getEdgeThreshold).
    define_method<void(cv::cuda::ORB::*)(int)>("set_first_level", &cv::cuda::ORB::setFirstLevel).
    define_method<int(cv::cuda::ORB::*)() const>("get_first_level", &cv::cuda::ORB::getFirstLevel).
    define_method<void(cv::cuda::ORB::*)(int)>("set_wta_k", &cv::cuda::ORB::setWTA_K).
    define_method<int(cv::cuda::ORB::*)() const>("get_wta_k", &cv::cuda::ORB::getWTA_K).
    define_method<void(cv::cuda::ORB::*)(int)>("set_score_type", &cv::cuda::ORB::setScoreType).
    define_method<int(cv::cuda::ORB::*)() const>("get_score_type", &cv::cuda::ORB::getScoreType).
    define_method<void(cv::cuda::ORB::*)(int)>("set_patch_size", &cv::cuda::ORB::setPatchSize).
    define_method<int(cv::cuda::ORB::*)() const>("get_patch_size", &cv::cuda::ORB::getPatchSize).
    define_method<void(cv::cuda::ORB::*)(int)>("set_fast_threshold", &cv::cuda::ORB::setFastThreshold).
    define_method<int(cv::cuda::ORB::*)() const>("get_fast_threshold", &cv::cuda::ORB::getFastThreshold).
    define_method<void(cv::cuda::ORB::*)(bool)>("set_blur_for_descriptor", &cv::cuda::ORB::setBlurForDescriptor).
    define_method<bool(cv::cuda::ORB::*)() const>("get_blur_for_descriptor", &cv::cuda::ORB::getBlurForDescriptor);
}