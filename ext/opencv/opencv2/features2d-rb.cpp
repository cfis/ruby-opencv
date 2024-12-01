#include <opencv2/features2d.hpp>
#include "features2d-rb.hpp"

using namespace Rice;

extern "C"
void Init_Features2d()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvKeyPointsFilter = define_class_under<cv::KeyPointsFilter>(rb_mCv, "KeyPointsFilter").
    define_constructor(Constructor<cv::KeyPointsFilter>()).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, cv::Size_<int>, int)>("run_by_image_border", &cv::KeyPointsFilter::runByImageBorder).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, float, float)>("run_by_keypoint_size", &cv::KeyPointsFilter::runByKeypointSize).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, const cv::Mat&)>("run_by_pixels_mask", &cv::KeyPointsFilter::runByPixelsMask).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, std::vector<std::vector<cv::Point_<int>>>&, const cv::Mat&)>("run_by_pixels_mask2_vector_point", &cv::KeyPointsFilter::runByPixelsMask2VectorPoint).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&)>("remove_duplicated", &cv::KeyPointsFilter::removeDuplicated).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&)>("remove_duplicated_sorted", &cv::KeyPointsFilter::removeDuplicatedSorted).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, int)>("retain_best", &cv::KeyPointsFilter::retainBest);
  
  Class rb_cCvFeature2D = define_class_under<cv::Feature2D, cv::Algorithm>(rb_mCv, "Feature2D").
    define_method<void(cv::Feature2D::*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, const cv::_InputArray &)>("detect", &cv::Feature2D::detect).
    define_method<void(cv::Feature2D::*)(const cv::_InputArray &, std::vector<std::vector<cv::KeyPoint>>&, const cv::_InputArray &)>("detect", &cv::Feature2D::detect).
    define_method<void(cv::Feature2D::*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, const cv::_OutputArray &)>("compute", &cv::Feature2D::compute).
    define_method<void(cv::Feature2D::*)(const cv::_InputArray &, std::vector<std::vector<cv::KeyPoint>>&, const cv::_OutputArray &)>("compute", &cv::Feature2D::compute).
    define_method<void(cv::Feature2D::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::KeyPoint>&, const cv::_OutputArray &, bool)>("detect_and_compute", &cv::Feature2D::detectAndCompute).
    define_method<int(cv::Feature2D::*)() const>("descriptor_size", &cv::Feature2D::descriptorSize).
    define_method<int(cv::Feature2D::*)() const>("descriptor_type", &cv::Feature2D::descriptorType).
    define_method<int(cv::Feature2D::*)() const>("default_norm", &cv::Feature2D::defaultNorm).
    define_method<void(cv::Feature2D::*)(const std::basic_string<char>&) const>("write", &cv::Feature2D::write).
    define_method<void(cv::Feature2D::*)(const std::basic_string<char>&)>("read", &cv::Feature2D::read).
    define_method<void(cv::Feature2D::*)(cv::FileStorage&) const>("write", &cv::Feature2D::write).
    define_method<void(cv::Feature2D::*)(const cv::FileNode&)>("read", &cv::Feature2D::read).
    define_method<bool(cv::Feature2D::*)() const>("empty", &cv::Feature2D::empty).
    define_method<std::basic_string<char>(cv::Feature2D::*)() const>("get_default_name", &cv::Feature2D::getDefaultName).
    define_method<void(cv::Feature2D::*)(cv::FileStorage&, const std::basic_string<char>&) const>("write", &cv::Feature2D::write).
    define_method<void(cv::Feature2D::*)(const cv::Ptr<cv::FileStorage>&, const std::basic_string<char>&) const>("write", &cv::Feature2D::write);
  
  Class rb_cCvAffineFeature = define_class_under<cv::AffineFeature, cv::Feature2D>(rb_mCv, "AffineFeature").
    define_singleton_function<cv::Ptr<cv::AffineFeature>(*)(const cv::Ptr<cv::Feature2D>&, int, int, float, float)>("create", &cv::AffineFeature::create).
    define_method<void(cv::AffineFeature::*)(const std::vector<float>&, const std::vector<float>&)>("set_view_params", &cv::AffineFeature::setViewParams).
    define_method<void(cv::AffineFeature::*)(std::vector<float>&, std::vector<float>&) const>("get_view_params", &cv::AffineFeature::getViewParams).
    define_method<std::basic_string<char>(cv::AffineFeature::*)() const>("get_default_name", &cv::AffineFeature::getDefaultName);
  
  Class rb_cCvSIFT = define_class_under<cv::SIFT, cv::Feature2D>(rb_mCv, "SIFT").
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, bool)>("create", &cv::SIFT::create).
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, int, bool)>("create", &cv::SIFT::create).
    define_method<std::basic_string<char>(cv::SIFT::*)() const>("get_default_name", &cv::SIFT::getDefaultName).
    define_method<void(cv::SIFT::*)(int)>("set_n_features", &cv::SIFT::setNFeatures).
    define_method<int(cv::SIFT::*)() const>("get_n_features", &cv::SIFT::getNFeatures).
    define_method<void(cv::SIFT::*)(int)>("set_n_octave_layers", &cv::SIFT::setNOctaveLayers).
    define_method<int(cv::SIFT::*)() const>("get_n_octave_layers", &cv::SIFT::getNOctaveLayers).
    define_method<void(cv::SIFT::*)(double)>("set_contrast_threshold", &cv::SIFT::setContrastThreshold).
    define_method<double(cv::SIFT::*)() const>("get_contrast_threshold", &cv::SIFT::getContrastThreshold).
    define_method<void(cv::SIFT::*)(double)>("set_edge_threshold", &cv::SIFT::setEdgeThreshold).
    define_method<double(cv::SIFT::*)() const>("get_edge_threshold", &cv::SIFT::getEdgeThreshold).
    define_method<void(cv::SIFT::*)(double)>("set_sigma", &cv::SIFT::setSigma).
    define_method<double(cv::SIFT::*)() const>("get_sigma", &cv::SIFT::getSigma);
  
  Class rb_cCvBRISK = define_class_under<cv::BRISK, cv::Feature2D>(rb_mCv, "BRISK").
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, float)>("create", &cv::BRISK::create).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create).
    define_method<std::basic_string<char>(cv::BRISK::*)() const>("get_default_name", &cv::BRISK::getDefaultName).
    define_method<void(cv::BRISK::*)(int)>("set_threshold", &cv::BRISK::setThreshold).
    define_method<int(cv::BRISK::*)() const>("get_threshold", &cv::BRISK::getThreshold).
    define_method<void(cv::BRISK::*)(int)>("set_octaves", &cv::BRISK::setOctaves).
    define_method<int(cv::BRISK::*)() const>("get_octaves", &cv::BRISK::getOctaves).
    define_method<void(cv::BRISK::*)(float)>("set_pattern_scale", &cv::BRISK::setPatternScale).
    define_method<float(cv::BRISK::*)() const>("get_pattern_scale", &cv::BRISK::getPatternScale);
  
  Class rb_cCvORB = define_class_under<cv::ORB, cv::Feature2D>(rb_mCv, "ORB").
    define_singleton_attr("KBytes", &ORB::kBytes).
    define_singleton_function<cv::Ptr<cv::ORB>(*)(int, float, int, int, int, int, cv::ORB::ScoreType, int, int)>("create", &cv::ORB::create).
    define_method<void(cv::ORB::*)(int)>("set_max_features", &cv::ORB::setMaxFeatures).
    define_method<int(cv::ORB::*)() const>("get_max_features", &cv::ORB::getMaxFeatures).
    define_method<void(cv::ORB::*)(double)>("set_scale_factor", &cv::ORB::setScaleFactor).
    define_method<double(cv::ORB::*)() const>("get_scale_factor", &cv::ORB::getScaleFactor).
    define_method<void(cv::ORB::*)(int)>("set_n_levels", &cv::ORB::setNLevels).
    define_method<int(cv::ORB::*)() const>("get_n_levels", &cv::ORB::getNLevels).
    define_method<void(cv::ORB::*)(int)>("set_edge_threshold", &cv::ORB::setEdgeThreshold).
    define_method<int(cv::ORB::*)() const>("get_edge_threshold", &cv::ORB::getEdgeThreshold).
    define_method<void(cv::ORB::*)(int)>("set_first_level", &cv::ORB::setFirstLevel).
    define_method<int(cv::ORB::*)() const>("get_first_level", &cv::ORB::getFirstLevel).
    define_method<void(cv::ORB::*)(int)>("set_wta_k", &cv::ORB::setWTA_K).
    define_method<int(cv::ORB::*)() const>("get_wta_k", &cv::ORB::getWTA_K).
    define_method<void(cv::ORB::*)(cv::ORB::ScoreType)>("set_score_type", &cv::ORB::setScoreType).
    define_method<cv::ORB::ScoreType(cv::ORB::*)() const>("get_score_type", &cv::ORB::getScoreType).
    define_method<void(cv::ORB::*)(int)>("set_patch_size", &cv::ORB::setPatchSize).
    define_method<int(cv::ORB::*)() const>("get_patch_size", &cv::ORB::getPatchSize).
    define_method<void(cv::ORB::*)(int)>("set_fast_threshold", &cv::ORB::setFastThreshold).
    define_method<int(cv::ORB::*)() const>("get_fast_threshold", &cv::ORB::getFastThreshold).
    define_method<std::basic_string<char>(cv::ORB::*)() const>("get_default_name", &cv::ORB::getDefaultName);
  
  Enum<cv::ORB::ScoreType> rb_cCvORBScoreType = define_enum<cv::ORB::ScoreType>("ScoreType", rb_cCvORB).
    define_value("HARRIS_SCORE", cv::ORB::ScoreType::HARRIS_SCORE).
    define_value("FAST_SCORE", cv::ORB::ScoreType::FAST_SCORE);
  
  Class rb_cCvMSER = define_class_under<cv::MSER, cv::Feature2D>(rb_mCv, "MSER").
    define_singleton_function<cv::Ptr<cv::MSER>(*)(int, int, int, double, double, int, double, double, int)>("create", &cv::MSER::create).
    define_method<void(cv::MSER::*)(const cv::_InputArray &, std::vector<std::vector<cv::Point_<int>>>&, std::vector<cv::Rect_<int>>&)>("detect_regions", &cv::MSER::detectRegions).
    define_method<void(cv::MSER::*)(int)>("set_delta", &cv::MSER::setDelta).
    define_method<int(cv::MSER::*)() const>("get_delta", &cv::MSER::getDelta).
    define_method<void(cv::MSER::*)(int)>("set_min_area", &cv::MSER::setMinArea).
    define_method<int(cv::MSER::*)() const>("get_min_area", &cv::MSER::getMinArea).
    define_method<void(cv::MSER::*)(int)>("set_max_area", &cv::MSER::setMaxArea).
    define_method<int(cv::MSER::*)() const>("get_max_area", &cv::MSER::getMaxArea).
    define_method<void(cv::MSER::*)(double)>("set_max_variation", &cv::MSER::setMaxVariation).
    define_method<double(cv::MSER::*)() const>("get_max_variation", &cv::MSER::getMaxVariation).
    define_method<void(cv::MSER::*)(double)>("set_min_diversity", &cv::MSER::setMinDiversity).
    define_method<double(cv::MSER::*)() const>("get_min_diversity", &cv::MSER::getMinDiversity).
    define_method<void(cv::MSER::*)(int)>("set_max_evolution", &cv::MSER::setMaxEvolution).
    define_method<int(cv::MSER::*)() const>("get_max_evolution", &cv::MSER::getMaxEvolution).
    define_method<void(cv::MSER::*)(double)>("set_area_threshold", &cv::MSER::setAreaThreshold).
    define_method<double(cv::MSER::*)() const>("get_area_threshold", &cv::MSER::getAreaThreshold).
    define_method<void(cv::MSER::*)(double)>("set_min_margin", &cv::MSER::setMinMargin).
    define_method<double(cv::MSER::*)() const>("get_min_margin", &cv::MSER::getMinMargin).
    define_method<void(cv::MSER::*)(int)>("set_edge_blur_size", &cv::MSER::setEdgeBlurSize).
    define_method<int(cv::MSER::*)() const>("get_edge_blur_size", &cv::MSER::getEdgeBlurSize).
    define_method<void(cv::MSER::*)(bool)>("set_pass2_only", &cv::MSER::setPass2Only).
    define_method<bool(cv::MSER::*)() const>("get_pass2_only", &cv::MSER::getPass2Only).
    define_method<std::basic_string<char>(cv::MSER::*)() const>("get_default_name", &cv::MSER::getDefaultName);
  
  Class rb_cCvFastFeatureDetector = define_class_under<cv::FastFeatureDetector, cv::Feature2D>(rb_mCv, "FastFeatureDetector").
    define_singleton_function<cv::Ptr<cv::FastFeatureDetector>(*)(int, bool, cv::FastFeatureDetector::DetectorType)>("create", &cv::FastFeatureDetector::create).
    define_method<void(cv::FastFeatureDetector::*)(int)>("set_threshold", &cv::FastFeatureDetector::setThreshold).
    define_method<int(cv::FastFeatureDetector::*)() const>("get_threshold", &cv::FastFeatureDetector::getThreshold).
    define_method<void(cv::FastFeatureDetector::*)(bool)>("set_nonmax_suppression", &cv::FastFeatureDetector::setNonmaxSuppression).
    define_method<bool(cv::FastFeatureDetector::*)() const>("get_nonmax_suppression", &cv::FastFeatureDetector::getNonmaxSuppression).
    define_method<void(cv::FastFeatureDetector::*)(cv::FastFeatureDetector::DetectorType)>("set_type", &cv::FastFeatureDetector::setType).
    define_method<cv::FastFeatureDetector::DetectorType(cv::FastFeatureDetector::*)() const>("get_type", &cv::FastFeatureDetector::getType).
    define_method<std::basic_string<char>(cv::FastFeatureDetector::*)() const>("get_default_name", &cv::FastFeatureDetector::getDefaultName);
  
  Enum<cv::FastFeatureDetector::DetectorType> rb_cCvFastFeatureDetectorDetectorType = define_enum<cv::FastFeatureDetector::DetectorType>("DetectorType", rb_cCvFastFeatureDetector).
    define_value("TYPE_5_8", cv::FastFeatureDetector::DetectorType::TYPE_5_8).
    define_value("TYPE_7_12", cv::FastFeatureDetector::DetectorType::TYPE_7_12).
    define_value("TYPE_9_16", cv::FastFeatureDetector::DetectorType::TYPE_9_16);
  
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, int, bool)>("fast", &cv::FAST);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, int, bool, cv::FastFeatureDetector::DetectorType)>("fast", &cv::FAST);
  
  Class rb_cCvAgastFeatureDetector = define_class_under<cv::AgastFeatureDetector, cv::Feature2D>(rb_mCv, "AgastFeatureDetector").
    define_singleton_function<cv::Ptr<cv::AgastFeatureDetector>(*)(int, bool, cv::AgastFeatureDetector::DetectorType)>("create", &cv::AgastFeatureDetector::create).
    define_method<void(cv::AgastFeatureDetector::*)(int)>("set_threshold", &cv::AgastFeatureDetector::setThreshold).
    define_method<int(cv::AgastFeatureDetector::*)() const>("get_threshold", &cv::AgastFeatureDetector::getThreshold).
    define_method<void(cv::AgastFeatureDetector::*)(bool)>("set_nonmax_suppression", &cv::AgastFeatureDetector::setNonmaxSuppression).
    define_method<bool(cv::AgastFeatureDetector::*)() const>("get_nonmax_suppression", &cv::AgastFeatureDetector::getNonmaxSuppression).
    define_method<void(cv::AgastFeatureDetector::*)(cv::AgastFeatureDetector::DetectorType)>("set_type", &cv::AgastFeatureDetector::setType).
    define_method<cv::AgastFeatureDetector::DetectorType(cv::AgastFeatureDetector::*)() const>("get_type", &cv::AgastFeatureDetector::getType).
    define_method<std::basic_string<char>(cv::AgastFeatureDetector::*)() const>("get_default_name", &cv::AgastFeatureDetector::getDefaultName);
  
  Enum<cv::AgastFeatureDetector::DetectorType> rb_cCvAgastFeatureDetectorDetectorType = define_enum<cv::AgastFeatureDetector::DetectorType>("DetectorType", rb_cCvAgastFeatureDetector).
    define_value("AGAST_5_8", cv::AgastFeatureDetector::DetectorType::AGAST_5_8).
    define_value("AGAST_7_12d", cv::AgastFeatureDetector::DetectorType::AGAST_7_12d).
    define_value("AGAST_7_12s", cv::AgastFeatureDetector::DetectorType::AGAST_7_12s).
    define_value("OAST_9_16", cv::AgastFeatureDetector::DetectorType::OAST_9_16);
  
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, int, bool)>("agast", &cv::AGAST);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, int, bool, cv::AgastFeatureDetector::DetectorType)>("agast", &cv::AGAST);
  
  Class rb_cCvGFTTDetector = define_class_under<cv::GFTTDetector, cv::Feature2D>(rb_mCv, "GFTTDetector").
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, bool, double)>("create", &cv::GFTTDetector::create).
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, int, bool, double)>("create", &cv::GFTTDetector::create).
    define_method<void(cv::GFTTDetector::*)(int)>("set_max_features", &cv::GFTTDetector::setMaxFeatures).
    define_method<int(cv::GFTTDetector::*)() const>("get_max_features", &cv::GFTTDetector::getMaxFeatures).
    define_method<void(cv::GFTTDetector::*)(double)>("set_quality_level", &cv::GFTTDetector::setQualityLevel).
    define_method<double(cv::GFTTDetector::*)() const>("get_quality_level", &cv::GFTTDetector::getQualityLevel).
    define_method<void(cv::GFTTDetector::*)(double)>("set_min_distance", &cv::GFTTDetector::setMinDistance).
    define_method<double(cv::GFTTDetector::*)() const>("get_min_distance", &cv::GFTTDetector::getMinDistance).
    define_method<void(cv::GFTTDetector::*)(int)>("set_block_size", &cv::GFTTDetector::setBlockSize).
    define_method<int(cv::GFTTDetector::*)() const>("get_block_size", &cv::GFTTDetector::getBlockSize).
    define_method<void(cv::GFTTDetector::*)(int)>("set_gradient_size", &cv::GFTTDetector::setGradientSize).
    define_method<int(cv::GFTTDetector::*)()>("get_gradient_size", &cv::GFTTDetector::getGradientSize).
    define_method<void(cv::GFTTDetector::*)(bool)>("set_harris_detector", &cv::GFTTDetector::setHarrisDetector).
    define_method<bool(cv::GFTTDetector::*)() const>("get_harris_detector", &cv::GFTTDetector::getHarrisDetector).
    define_method<void(cv::GFTTDetector::*)(double)>("set_k", &cv::GFTTDetector::setK).
    define_method<double(cv::GFTTDetector::*)() const>("get_k", &cv::GFTTDetector::getK).
    define_method<std::basic_string<char>(cv::GFTTDetector::*)() const>("get_default_name", &cv::GFTTDetector::getDefaultName);
  
  Class rb_cCvSimpleBlobDetector = define_class_under<cv::SimpleBlobDetector, cv::Feature2D>(rb_mCv, "SimpleBlobDetector").
    define_singleton_function<cv::Ptr<cv::SimpleBlobDetector>(*)(const cv::SimpleBlobDetector::Params&)>("create", &cv::SimpleBlobDetector::create).
    define_method<void(cv::SimpleBlobDetector::*)(const cv::SimpleBlobDetector::Params&)>("set_params", &cv::SimpleBlobDetector::setParams).
    define_method<cv::SimpleBlobDetector::Params(cv::SimpleBlobDetector::*)() const>("get_params", &cv::SimpleBlobDetector::getParams).
    define_method<std::basic_string<char>(cv::SimpleBlobDetector::*)() const>("get_default_name", &cv::SimpleBlobDetector::getDefaultName).
    define_method<const std::vector<std::vector<cv::Point_<int>>>&(cv::SimpleBlobDetector::*)() const>("get_blob_contours", &cv::SimpleBlobDetector::getBlobContours);
  
  Class rb_cCvSimpleBlobDetectorParams = define_class_under<cv::SimpleBlobDetector::Params>(rb_cCvSimpleBlobDetector, "Params").
    define_constructor(Constructor<cv::SimpleBlobDetector::Params>()).
    define_attr("threshold_step", &cv::SimpleBlobDetector::Params::thresholdStep).
    define_attr("min_threshold", &cv::SimpleBlobDetector::Params::minThreshold).
    define_attr("max_threshold", &cv::SimpleBlobDetector::Params::maxThreshold).
    define_attr("min_repeatability", &cv::SimpleBlobDetector::Params::minRepeatability).
    define_attr("min_dist_between_blobs", &cv::SimpleBlobDetector::Params::minDistBetweenBlobs).
    define_attr("filter_by_color", &cv::SimpleBlobDetector::Params::filterByColor).
    define_attr("blob_color", &cv::SimpleBlobDetector::Params::blobColor).
    define_attr("filter_by_area", &cv::SimpleBlobDetector::Params::filterByArea).
    define_attr("min_area", &cv::SimpleBlobDetector::Params::minArea).
    define_attr("max_area", &cv::SimpleBlobDetector::Params::maxArea).
    define_attr("filter_by_circularity", &cv::SimpleBlobDetector::Params::filterByCircularity).
    define_attr("min_circularity", &cv::SimpleBlobDetector::Params::minCircularity).
    define_attr("max_circularity", &cv::SimpleBlobDetector::Params::maxCircularity).
    define_attr("filter_by_inertia", &cv::SimpleBlobDetector::Params::filterByInertia).
    define_attr("min_inertia_ratio", &cv::SimpleBlobDetector::Params::minInertiaRatio).
    define_attr("max_inertia_ratio", &cv::SimpleBlobDetector::Params::maxInertiaRatio).
    define_attr("filter_by_convexity", &cv::SimpleBlobDetector::Params::filterByConvexity).
    define_attr("min_convexity", &cv::SimpleBlobDetector::Params::minConvexity).
    define_attr("max_convexity", &cv::SimpleBlobDetector::Params::maxConvexity).
    define_attr("collect_contours", &cv::SimpleBlobDetector::Params::collectContours).
    define_method<void(cv::SimpleBlobDetector::Params::*)(const cv::FileNode&)>("read", &cv::SimpleBlobDetector::Params::read).
    define_method<void(cv::SimpleBlobDetector::Params::*)(cv::FileStorage&) const>("write", &cv::SimpleBlobDetector::Params::write);
  
  Class rb_cCvKAZE = define_class_under<cv::KAZE, cv::Feature2D>(rb_mCv, "KAZE").
    define_singleton_function<cv::Ptr<cv::KAZE>(*)(bool, bool, float, int, int, cv::KAZE::DiffusivityType)>("create", &cv::KAZE::create).
    define_method<void(cv::KAZE::*)(bool)>("set_extended", &cv::KAZE::setExtended).
    define_method<bool(cv::KAZE::*)() const>("get_extended", &cv::KAZE::getExtended).
    define_method<void(cv::KAZE::*)(bool)>("set_upright", &cv::KAZE::setUpright).
    define_method<bool(cv::KAZE::*)() const>("get_upright", &cv::KAZE::getUpright).
    define_method<void(cv::KAZE::*)(double)>("set_threshold", &cv::KAZE::setThreshold).
    define_method<double(cv::KAZE::*)() const>("get_threshold", &cv::KAZE::getThreshold).
    define_method<void(cv::KAZE::*)(int)>("set_n_octaves", &cv::KAZE::setNOctaves).
    define_method<int(cv::KAZE::*)() const>("get_n_octaves", &cv::KAZE::getNOctaves).
    define_method<void(cv::KAZE::*)(int)>("set_n_octave_layers", &cv::KAZE::setNOctaveLayers).
    define_method<int(cv::KAZE::*)() const>("get_n_octave_layers", &cv::KAZE::getNOctaveLayers).
    define_method<void(cv::KAZE::*)(cv::KAZE::DiffusivityType)>("set_diffusivity", &cv::KAZE::setDiffusivity).
    define_method<cv::KAZE::DiffusivityType(cv::KAZE::*)() const>("get_diffusivity", &cv::KAZE::getDiffusivity).
    define_method<std::basic_string<char>(cv::KAZE::*)() const>("get_default_name", &cv::KAZE::getDefaultName);
  
  Enum<cv::KAZE::DiffusivityType> rb_cCvKAZEDiffusivityType = define_enum<cv::KAZE::DiffusivityType>("DiffusivityType", rb_cCvKAZE).
    define_value("DIFF_PM_G1", cv::KAZE::DiffusivityType::DIFF_PM_G1).
    define_value("DIFF_PM_G2", cv::KAZE::DiffusivityType::DIFF_PM_G2).
    define_value("DIFF_WEICKERT", cv::KAZE::DiffusivityType::DIFF_WEICKERT).
    define_value("DIFF_CHARBONNIER", cv::KAZE::DiffusivityType::DIFF_CHARBONNIER);
  
  Class rb_cCvAKAZE = define_class_under<cv::AKAZE, cv::Feature2D>(rb_mCv, "AKAZE").
    define_singleton_function<cv::Ptr<cv::AKAZE>(*)(cv::AKAZE::DescriptorType, int, int, float, int, int, cv::KAZE::DiffusivityType)>("create", &cv::AKAZE::create).
    define_method<void(cv::AKAZE::*)(cv::AKAZE::DescriptorType)>("set_descriptor_type", &cv::AKAZE::setDescriptorType).
    define_method<cv::AKAZE::DescriptorType(cv::AKAZE::*)() const>("get_descriptor_type", &cv::AKAZE::getDescriptorType).
    define_method<void(cv::AKAZE::*)(int)>("set_descriptor_size", &cv::AKAZE::setDescriptorSize).
    define_method<int(cv::AKAZE::*)() const>("get_descriptor_size", &cv::AKAZE::getDescriptorSize).
    define_method<void(cv::AKAZE::*)(int)>("set_descriptor_channels", &cv::AKAZE::setDescriptorChannels).
    define_method<int(cv::AKAZE::*)() const>("get_descriptor_channels", &cv::AKAZE::getDescriptorChannels).
    define_method<void(cv::AKAZE::*)(double)>("set_threshold", &cv::AKAZE::setThreshold).
    define_method<double(cv::AKAZE::*)() const>("get_threshold", &cv::AKAZE::getThreshold).
    define_method<void(cv::AKAZE::*)(int)>("set_n_octaves", &cv::AKAZE::setNOctaves).
    define_method<int(cv::AKAZE::*)() const>("get_n_octaves", &cv::AKAZE::getNOctaves).
    define_method<void(cv::AKAZE::*)(int)>("set_n_octave_layers", &cv::AKAZE::setNOctaveLayers).
    define_method<int(cv::AKAZE::*)() const>("get_n_octave_layers", &cv::AKAZE::getNOctaveLayers).
    define_method<void(cv::AKAZE::*)(cv::KAZE::DiffusivityType)>("set_diffusivity", &cv::AKAZE::setDiffusivity).
    define_method<cv::KAZE::DiffusivityType(cv::AKAZE::*)() const>("get_diffusivity", &cv::AKAZE::getDiffusivity).
    define_method<std::basic_string<char>(cv::AKAZE::*)() const>("get_default_name", &cv::AKAZE::getDefaultName);
  
  Enum<cv::AKAZE::DescriptorType> rb_cCvAKAZEDescriptorType = define_enum<cv::AKAZE::DescriptorType>("DescriptorType", rb_cCvAKAZE).
    define_value("DESCRIPTOR_KAZE_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE_UPRIGHT).
    define_value("DESCRIPTOR_KAZE", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE).
    define_value("DESCRIPTOR_MLDB_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB_UPRIGHT).
    define_value("DESCRIPTOR_MLDB", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB);
  
  Class rb_cCvAccumulatorUnsigned char = define_class_under<cv::Accumulator<unsigned char>>(rb_mCv, "AccumulatorUnsigned char");
  
  
  Class rb_cCvAccumulatorUnsigned short = define_class_under<cv::Accumulator<unsigned short>>(rb_mCv, "AccumulatorUnsigned short");
  
  
  Class rb_cCvAccumulatorChar = define_class_under<cv::Accumulator<char>>(rb_mCv, "AccumulatorChar");
  
  
  Class rb_cCvAccumulatorShort = define_class_under<cv::Accumulator<short>>(rb_mCv, "AccumulatorShort");
  
  
  Class rb_cCvDescriptorMatcher = define_class_under<cv::DescriptorMatcher, cv::Algorithm>(rb_mCv, "DescriptorMatcher").
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &)>("add", &cv::DescriptorMatcher::add).
    define_method<const std::vector<cv::Mat>&(cv::DescriptorMatcher::*)() const>("get_train_descriptors", &cv::DescriptorMatcher::getTrainDescriptors).
    define_method<void(cv::DescriptorMatcher::*)()>("clear", &cv::DescriptorMatcher::clear).
    define_method<bool(cv::DescriptorMatcher::*)() const>("empty", &cv::DescriptorMatcher::empty).
    define_method<bool(cv::DescriptorMatcher::*)() const>("is_mask_supported", &cv::DescriptorMatcher::isMaskSupported).
    define_method<void(cv::DescriptorMatcher::*)()>("train", &cv::DescriptorMatcher::train).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::DMatch>&, const cv::_InputArray &) const>("match", &cv::DescriptorMatcher::match).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, int, const cv::_InputArray &, bool) const>("knn_match", &cv::DescriptorMatcher::knnMatch).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, float, const cv::_InputArray &, bool) const>("radius_match", &cv::DescriptorMatcher::radiusMatch).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<cv::DMatch>&, const cv::_InputArray &)>("match", &cv::DescriptorMatcher::match).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, int, const cv::_InputArray &, bool)>("knn_match", &cv::DescriptorMatcher::knnMatch).
    define_method<void(cv::DescriptorMatcher::*)(const cv::_InputArray &, std::vector<std::vector<cv::DMatch>>&, float, const cv::_InputArray &, bool)>("radius_match", &cv::DescriptorMatcher::radiusMatch).
    define_method<void(cv::DescriptorMatcher::*)(const std::basic_string<char>&) const>("write", &cv::DescriptorMatcher::write).
    define_method<void(cv::DescriptorMatcher::*)(const std::basic_string<char>&)>("read", &cv::DescriptorMatcher::read).
    define_method<void(cv::DescriptorMatcher::*)(const cv::FileNode&)>("read", &cv::DescriptorMatcher::read).
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&) const>("write", &cv::DescriptorMatcher::write).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::DescriptorMatcher::*)(bool) const>("clone", &cv::DescriptorMatcher::clone).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const std::basic_string<char>&)>("create", &cv::DescriptorMatcher::create).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const cv::DescriptorMatcher::MatcherType&)>("create", &cv::DescriptorMatcher::create).
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&, const std::basic_string<char>&) const>("write", &cv::DescriptorMatcher::write).
    define_method<void(cv::DescriptorMatcher::*)(const cv::Ptr<cv::FileStorage>&, const std::basic_string<char>&) const>("write", &cv::DescriptorMatcher::write);
  
  Class rb_cCvDescriptorMatcherDescriptorCollection = define_class_under<cv::DescriptorMatcher::DescriptorCollection>(rb_cCvDescriptorMatcher, "DescriptorCollection").
    define_constructor(Constructor<cv::DescriptorMatcher::DescriptorCollection>()).
    define_constructor(Constructor<cv::DescriptorMatcher::DescriptorCollection, const cv::DescriptorMatcher::DescriptorCollection&>()).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)(const std::vector<cv::Mat>&)>("set", &cv::DescriptorMatcher::DescriptorCollection::set).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)()>("clear", &cv::DescriptorMatcher::DescriptorCollection::clear).
    define_method<const cv::Mat&(cv::DescriptorMatcher::DescriptorCollection::*)() const>("get_descriptors", &cv::DescriptorMatcher::DescriptorCollection::getDescriptors).
    define_method<cv::Mat(cv::DescriptorMatcher::DescriptorCollection::*)(int, int) const>("get_descriptor", &cv::DescriptorMatcher::DescriptorCollection::getDescriptor).
    define_method<cv::Mat(cv::DescriptorMatcher::DescriptorCollection::*)(int) const>("get_descriptor", &cv::DescriptorMatcher::DescriptorCollection::getDescriptor).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)(int, int&, int&) const>("get_local_idx", &cv::DescriptorMatcher::DescriptorCollection::getLocalIdx).
    define_method<int(cv::DescriptorMatcher::DescriptorCollection::*)() const>("size", &cv::DescriptorMatcher::DescriptorCollection::size);
  
  Enum<cv::DescriptorMatcher::MatcherType> rb_cCvDescriptorMatcherMatcherType = define_enum<cv::DescriptorMatcher::MatcherType>("MatcherType", rb_cCvDescriptorMatcher).
    define_value("FLANNBASED", cv::DescriptorMatcher::MatcherType::FLANNBASED).
    define_value("BRUTEFORCE", cv::DescriptorMatcher::MatcherType::BRUTEFORCE).
    define_value("BRUTEFORCE_L1", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_L1).
    define_value("BRUTEFORCE_HAMMING", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMING).
    define_value("BRUTEFORCE_HAMMINGLUT", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMINGLUT).
    define_value("BRUTEFORCE_SL2", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_SL2);
  
  Class rb_cCvBFMatcher = define_class_under<cv::BFMatcher, cv::DescriptorMatcher>(rb_mCv, "BFMatcher").
    define_constructor(Constructor<cv::BFMatcher, int, bool>()).
    define_method<bool(cv::BFMatcher::*)() const>("is_mask_supported", &cv::BFMatcher::isMaskSupported).
    define_singleton_function<cv::Ptr<cv::BFMatcher>(*)(int, bool)>("create", &cv::BFMatcher::create).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::BFMatcher::*)(bool) const>("clone", &cv::BFMatcher::clone);
  
  Class rb_cCvFlannBasedMatcher = define_class_under<cv::FlannBasedMatcher, cv::DescriptorMatcher>(rb_mCv, "FlannBasedMatcher").
    define_constructor(Constructor<cv::FlannBasedMatcher, const cv::Ptr<cv::flann::IndexParams>&, const cv::Ptr<cv::flann::SearchParams>&>()).
    define_method<void(cv::FlannBasedMatcher::*)(const cv::_InputArray &)>("add", &cv::FlannBasedMatcher::add).
    define_method<void(cv::FlannBasedMatcher::*)()>("clear", &cv::FlannBasedMatcher::clear).
    define_method<void(cv::FlannBasedMatcher::*)(const cv::FileNode&)>("read", &cv::FlannBasedMatcher::read).
    define_method<void(cv::FlannBasedMatcher::*)(cv::FileStorage&) const>("write", &cv::FlannBasedMatcher::write).
    define_method<void(cv::FlannBasedMatcher::*)()>("train", &cv::FlannBasedMatcher::train).
    define_method<bool(cv::FlannBasedMatcher::*)() const>("is_mask_supported", &cv::FlannBasedMatcher::isMaskSupported).
    define_singleton_function<cv::Ptr<cv::FlannBasedMatcher>(*)()>("create", &cv::FlannBasedMatcher::create).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::FlannBasedMatcher::*)(bool) const>("clone", &cv::FlannBasedMatcher::clone);
  
  Enum<cv::DrawMatchesFlags> rb_cCvDrawMatchesFlags = define_enum<cv::DrawMatchesFlags>("DrawMatchesFlags", rb_mCv).
    define_value("DEFAULT", cv::DrawMatchesFlags::DEFAULT).
    define_value("DRAW_OVER_OUTIMG", cv::DrawMatchesFlags::DRAW_OVER_OUTIMG).
    define_value("NOT_DRAW_SINGLE_POINTS", cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS).
    define_value("DRAW_RICH_KEYPOINTS", cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const cv::_InputOutputArray &, const cv::Scalar_<double>&, cv::DrawMatchesFlags)>("draw_keypoints", &cv::drawKeypoints);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, const cv::_InputOutputArray &, const cv::Scalar_<double>&, const cv::Scalar_<double>&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, const cv::_InputOutputArray &, const int, const cv::Scalar_<double>&, const cv::Scalar_<double>&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const cv::_InputArray &, const std::vector<cv::KeyPoint>&, const std::vector<std::vector<cv::DMatch>>&, const cv::_InputOutputArray &, const cv::Scalar_<double>&, const cv::Scalar_<double>&, const std::vector<std::vector<char>>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, std::vector<cv::KeyPoint>*, std::vector<cv::KeyPoint>*, float&, int&, const cv::Ptr<cv::Feature2D>&)>("evaluate_feature_detector", &cv::evaluateFeatureDetector);
  
  rb_mCv.define_module_function<void(*)(const std::vector<std::vector<cv::DMatch>>&, const std::vector<std::vector<unsigned char>>&, std::vector<cv::Point_<float>>&)>("compute_recall_precision_curve", &cv::computeRecallPrecisionCurve);
  
  rb_mCv.define_module_function<float(*)(const std::vector<cv::Point_<float>>&, float)>("get_recall", &cv::getRecall);
  
  rb_mCv.define_module_function<int(*)(const std::vector<cv::Point_<float>>&, float)>("get_nearest_point", &cv::getNearestPoint);
  
  Class rb_cCvBOWTrainer = define_class_under<cv::BOWTrainer>(rb_mCv, "BOWTrainer").
    define_constructor(Constructor<cv::BOWTrainer>()).
    define_method<void(cv::BOWTrainer::*)(const cv::Mat&)>("add", &cv::BOWTrainer::add).
    define_method<const std::vector<cv::Mat>&(cv::BOWTrainer::*)() const>("get_descriptors", &cv::BOWTrainer::getDescriptors).
    define_method<int(cv::BOWTrainer::*)() const>("descriptors_count", &cv::BOWTrainer::descriptorsCount).
    define_method<void(cv::BOWTrainer::*)()>("clear", &cv::BOWTrainer::clear).
    define_method<cv::Mat(cv::BOWTrainer::*)() const>("cluster", &cv::BOWTrainer::cluster).
    define_method<cv::Mat(cv::BOWTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWTrainer::cluster);
  
  Class rb_cCvBOWKMeansTrainer = define_class_under<cv::BOWKMeansTrainer, cv::BOWTrainer>(rb_mCv, "BOWKMeansTrainer").
    define_constructor(Constructor<cv::BOWKMeansTrainer, int, const cv::TermCriteria&, int, int>()).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)() const>("cluster", &cv::BOWKMeansTrainer::cluster).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWKMeansTrainer::cluster);
  
  Class rb_cCvBOWImgDescriptorExtractor = define_class_under<cv::BOWImgDescriptorExtractor>(rb_mCv, "BOWImgDescriptorExtractor").
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::Feature2D>&, const cv::Ptr<cv::DescriptorMatcher>&>()).
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::DescriptorMatcher>&>()).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::Mat&)>("set_vocabulary", &cv::BOWImgDescriptorExtractor::setVocabulary).
    define_method<const cv::Mat&(cv::BOWImgDescriptorExtractor::*)() const>("get_vocabulary", &cv::BOWImgDescriptorExtractor::getVocabulary).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::_InputArray &, std::vector<cv::KeyPoint>&, const cv::_OutputArray &, std::vector<std::vector<int>>*, cv::Mat*)>("compute", &cv::BOWImgDescriptorExtractor::compute).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::_InputArray &, const cv::_OutputArray &, std::vector<std::vector<int>>*)>("compute", &cv::BOWImgDescriptorExtractor::compute).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::Mat&, std::vector<cv::KeyPoint>&, cv::Mat&)>("compute2", &cv::BOWImgDescriptorExtractor::compute2).
    define_method<int(cv::BOWImgDescriptorExtractor::*)() const>("descriptor_size", &cv::BOWImgDescriptorExtractor::descriptorSize).
    define_method<int(cv::BOWImgDescriptorExtractor::*)() const>("descriptor_type", &cv::BOWImgDescriptorExtractor::descriptorType);
}