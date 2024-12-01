#include <sstream>
#include <opencv2/features2d.hpp>
#include "features2d-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void Accumulator_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void SL2_builder(Data_Type_T& klass)
{
  klass.template define_method<cv::SL2<T>::ResultType(cv::SL2<T>::*)(const T*, const T*, int) const>("()", &cv::SL2<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L2_builder(Data_Type_T& klass)
{
  klass.template define_method<cv::L2<T>::ResultType(cv::L2<T>::*)(const T*, const T*, int) const>("()", &cv::L2<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};

template<typename Data_Type_T, typename T>
inline void L1_builder(Data_Type_T& klass)
{
  klass.template define_method<cv::L1<T>::ResultType(cv::L1<T>::*)(const T*, const T*, int) const>("()", &cv::L1<T>::operator(),
      Arg("a"), Arg("b"), Arg("size"));
};


void Init_Features2d()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvKeyPointsFilter = define_class_under<cv::KeyPointsFilter>(rb_mCv, "KeyPointsFilter").
    define_constructor(Constructor<cv::KeyPointsFilter>()).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, cv::Size, int)>("run_by_image_border", &cv::KeyPointsFilter::runByImageBorder,
      Arg("keypoints"), Arg("image_size"), Arg("border_size")).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, float, float)>("run_by_keypoint_size", &cv::KeyPointsFilter::runByKeypointSize,
      Arg("keypoints"), Arg("min_size"), Arg("max_size") = NULL).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, const cv::Mat&)>("run_by_pixels_mask", &cv::KeyPointsFilter::runByPixelsMask,
      Arg("keypoints"), Arg("mask")).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, std::vector<std::vector<cv::Point_<int>>>&, const cv::Mat&)>("run_by_pixels_mask2_vector_point", &cv::KeyPointsFilter::runByPixelsMask2VectorPoint,
      Arg("keypoints"), Arg("remove_from"), Arg("mask")).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&)>("remove_duplicated", &cv::KeyPointsFilter::removeDuplicated,
      Arg("keypoints")).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&)>("remove_duplicated_sorted", &cv::KeyPointsFilter::removeDuplicatedSorted,
      Arg("keypoints")).
    define_singleton_function<void(*)(std::vector<cv::KeyPoint>&, int)>("retain_best", &cv::KeyPointsFilter::retainBest,
      Arg("keypoints"), Arg("npoints"));
  
  Class rb_cCvFeature2D = define_class_under<cv::Feature2D, cv::Algorithm>(rb_mCv, "Feature2D").
    define_constructor(Constructor<cv::Feature2D>()).
    define_method<void(cv::Feature2D::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::InputArray)>("detect", &cv::Feature2D::detect,
      Arg("image"), Arg("keypoints"), Arg("mask")).
    define_method<void(cv::Feature2D::*)(cv::InputArrayOfArrays, std::vector<std::vector<cv::KeyPoint>>&, cv::InputArrayOfArrays)>("detect", &cv::Feature2D::detect,
      Arg("images"), Arg("keypoints"), Arg("masks")).
    define_method<void(cv::Feature2D::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray)>("compute", &cv::Feature2D::compute,
      Arg("image"), Arg("keypoints"), Arg("descriptors")).
    define_method<void(cv::Feature2D::*)(cv::InputArrayOfArrays, std::vector<std::vector<cv::KeyPoint>>&, cv::OutputArrayOfArrays)>("compute", &cv::Feature2D::compute,
      Arg("images"), Arg("keypoints"), Arg("descriptors")).
    define_method<void(cv::Feature2D::*)(cv::InputArray, cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray, bool)>("detect_and_compute", &cv::Feature2D::detectAndCompute,
      Arg("image"), Arg("mask"), Arg("keypoints"), Arg("descriptors"), Arg("use_provided_keypoints")).
    define_method<int(cv::Feature2D::*)() const>("descriptor_size", &cv::Feature2D::descriptorSize).
    define_method<int(cv::Feature2D::*)() const>("descriptor_type", &cv::Feature2D::descriptorType).
    define_method<int(cv::Feature2D::*)() const>("default_norm", &cv::Feature2D::defaultNorm).
    define_method<void(cv::Feature2D::*)(const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("file_name")).
    define_method<void(cv::Feature2D::*)(const cv::String&)>("read", &cv::Feature2D::read,
      Arg("file_name")).
    define_method<void(cv::Feature2D::*)(cv::FileStorage&) const>("write", &cv::Feature2D::write,
      Arg("")).
    define_method<void(cv::Feature2D::*)(const cv::FileNode&)>("read", &cv::Feature2D::read,
      Arg("")).
    define_method<bool(cv::Feature2D::*)() const>("empty?", &cv::Feature2D::empty).
    define_method<cv::String(cv::Feature2D::*)() const>("get_default_name", &cv::Feature2D::getDefaultName).
    define_method<void(cv::Feature2D::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("fs"), Arg("name")).
    define_method<void(cv::Feature2D::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::Feature2D::write,
      Arg("fs"), Arg("name"));
  
  Class rb_cCvAffineFeature = define_class_under<cv::AffineFeature, cv::Feature2D>(rb_mCv, "AffineFeature").
    define_singleton_function<cv::Ptr<cv::AffineFeature>(*)(const cv::Ptr<cv::Feature2D>&, int, int, float, float)>("create", &cv::AffineFeature::create,
      Arg("backend"), Arg("max_tilt") = 5, Arg("min_tilt") = 0, Arg("tilt_step") = 1.4142135623730951f, Arg("rotate_step_base") = 72).
    define_method<void(cv::AffineFeature::*)(const std::vector<float>&, const std::vector<float>&)>("set_view_params", &cv::AffineFeature::setViewParams,
      Arg("tilts"), Arg("rolls")).
    define_method<void(cv::AffineFeature::*)(std::vector<float>&, std::vector<float>&) const>("get_view_params", &cv::AffineFeature::getViewParams,
      Arg("tilts"), Arg("rolls")).
    define_method<cv::String(cv::AffineFeature::*)() const>("get_default_name", &cv::AffineFeature::getDefaultName);
  
  Class rb_cCvSIFT = define_class_under<cv::SIFT, cv::Feature2D>(rb_mCv, "SIFT").
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, bool)>("create", &cv::SIFT::create,
      Arg("nfeatures") = 0, Arg("n_octave_layers") = 3, Arg("contrast_threshold") = 0.04, Arg("edge_threshold") = 10, Arg("sigma") = 1.6, Arg("enable_precise_upscale")).
    define_singleton_function<cv::Ptr<cv::SIFT>(*)(int, int, double, double, double, int, bool)>("create", &cv::SIFT::create,
      Arg("nfeatures"), Arg("n_octave_layers"), Arg("contrast_threshold"), Arg("edge_threshold"), Arg("sigma"), Arg("descriptor_type"), Arg("enable_precise_upscale")).
    define_method<cv::String(cv::SIFT::*)() const>("get_default_name", &cv::SIFT::getDefaultName).
    define_method<void(cv::SIFT::*)(int)>("set_n_features", &cv::SIFT::setNFeatures,
      Arg("max_features")).
    define_method<int(cv::SIFT::*)() const>("get_n_features", &cv::SIFT::getNFeatures).
    define_method<void(cv::SIFT::*)(int)>("set_n_octave_layers", &cv::SIFT::setNOctaveLayers,
      Arg("n_octave_layers")).
    define_method<int(cv::SIFT::*)() const>("get_n_octave_layers", &cv::SIFT::getNOctaveLayers).
    define_method<void(cv::SIFT::*)(double)>("set_contrast_threshold", &cv::SIFT::setContrastThreshold,
      Arg("contrast_threshold")).
    define_method<double(cv::SIFT::*)() const>("get_contrast_threshold", &cv::SIFT::getContrastThreshold).
    define_method<void(cv::SIFT::*)(double)>("set_edge_threshold", &cv::SIFT::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method<double(cv::SIFT::*)() const>("get_edge_threshold", &cv::SIFT::getEdgeThreshold).
    define_method<void(cv::SIFT::*)(double)>("set_sigma", &cv::SIFT::setSigma,
      Arg("sigma")).
    define_method<double(cv::SIFT::*)() const>("get_sigma", &cv::SIFT::getSigma);
  
  Class rb_cCvBRISK = define_class_under<cv::BRISK, cv::Feature2D>(rb_mCv, "BRISK").
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, float)>("create", &cv::BRISK::create,
      Arg("thresh") = 30, Arg("octaves") = 3, Arg("pattern_scale") = 1.0f).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create,
      Arg("radius_list"), Arg("number_list"), Arg("d_max") = 5.85f, Arg("d_min") = 8.2f, Arg("index_change")).
    define_singleton_function<cv::Ptr<cv::BRISK>(*)(int, int, const std::vector<float>&, const std::vector<int>&, float, float, const std::vector<int>&)>("create", &cv::BRISK::create,
      Arg("thresh"), Arg("octaves"), Arg("radius_list"), Arg("number_list"), Arg("d_max") = 5.85f, Arg("d_min") = 8.2f, Arg("index_change")).
    define_method<cv::String(cv::BRISK::*)() const>("get_default_name", &cv::BRISK::getDefaultName).
    define_method<void(cv::BRISK::*)(int)>("set_threshold", &cv::BRISK::setThreshold,
      Arg("threshold")).
    define_method<int(cv::BRISK::*)() const>("get_threshold", &cv::BRISK::getThreshold).
    define_method<void(cv::BRISK::*)(int)>("set_octaves", &cv::BRISK::setOctaves,
      Arg("octaves")).
    define_method<int(cv::BRISK::*)() const>("get_octaves", &cv::BRISK::getOctaves).
    define_method<void(cv::BRISK::*)(float)>("set_pattern_scale", &cv::BRISK::setPatternScale,
      Arg("pattern_scale")).
    define_method<float(cv::BRISK::*)() const>("get_pattern_scale", &cv::BRISK::getPatternScale);
  
  Class rb_cCvORB = define_class_under<cv::ORB, cv::Feature2D>(rb_mCv, "ORB").
    define_singleton_attr("KBytes", &ORB::kBytes).
    define_singleton_function<cv::Ptr<cv::ORB>(*)(int, float, int, int, int, int, cv::ORB::ScoreType, int, int)>("create", &cv::ORB::create,
      Arg("nfeatures") = 500, Arg("scale_factor") = 1.2f, Arg("nlevels") = 8, Arg("edge_threshold") = 31, Arg("first_level") = 0, Arg("wta_k") = 2, Arg("score_type"), Arg("patch_size") = 31, Arg("fast_threshold") = 20).
    define_method<void(cv::ORB::*)(int)>("set_max_features", &cv::ORB::setMaxFeatures,
      Arg("max_features")).
    define_method<int(cv::ORB::*)() const>("get_max_features", &cv::ORB::getMaxFeatures).
    define_method<void(cv::ORB::*)(double)>("set_scale_factor", &cv::ORB::setScaleFactor,
      Arg("scale_factor")).
    define_method<double(cv::ORB::*)() const>("get_scale_factor", &cv::ORB::getScaleFactor).
    define_method<void(cv::ORB::*)(int)>("set_n_levels", &cv::ORB::setNLevels,
      Arg("nlevels")).
    define_method<int(cv::ORB::*)() const>("get_n_levels", &cv::ORB::getNLevels).
    define_method<void(cv::ORB::*)(int)>("set_edge_threshold", &cv::ORB::setEdgeThreshold,
      Arg("edge_threshold")).
    define_method<int(cv::ORB::*)() const>("get_edge_threshold", &cv::ORB::getEdgeThreshold).
    define_method<void(cv::ORB::*)(int)>("set_first_level", &cv::ORB::setFirstLevel,
      Arg("first_level")).
    define_method<int(cv::ORB::*)() const>("get_first_level", &cv::ORB::getFirstLevel).
    define_method<void(cv::ORB::*)(int)>("set_wta_k", &cv::ORB::setWTA_K,
      Arg("wta_k")).
    define_method<int(cv::ORB::*)() const>("get_wta_k", &cv::ORB::getWTA_K).
    define_method<void(cv::ORB::*)(cv::ORB::ScoreType)>("set_score_type", &cv::ORB::setScoreType,
      Arg("score_type")).
    define_method<cv::ORB::ScoreType(cv::ORB::*)() const>("get_score_type", &cv::ORB::getScoreType).
    define_method<void(cv::ORB::*)(int)>("set_patch_size", &cv::ORB::setPatchSize,
      Arg("patch_size")).
    define_method<int(cv::ORB::*)() const>("get_patch_size", &cv::ORB::getPatchSize).
    define_method<void(cv::ORB::*)(int)>("set_fast_threshold", &cv::ORB::setFastThreshold,
      Arg("fast_threshold")).
    define_method<int(cv::ORB::*)() const>("get_fast_threshold", &cv::ORB::getFastThreshold).
    define_method<cv::String(cv::ORB::*)() const>("get_default_name", &cv::ORB::getDefaultName);
  
  Enum<cv::ORB::ScoreType> rb_cCvORBScoreType = define_enum_under<cv::ORB::ScoreType>("ScoreType", rb_cCvORB).
    define_value("HARRIS_SCORE", cv::ORB::ScoreType::HARRIS_SCORE).
    define_value("FAST_SCORE", cv::ORB::ScoreType::FAST_SCORE);
  
  Class rb_cCvMSER = define_class_under<cv::MSER, cv::Feature2D>(rb_mCv, "MSER").
    define_singleton_function<cv::Ptr<cv::MSER>(*)(int, int, int, double, double, int, double, double, int)>("create", &cv::MSER::create,
      Arg("delta") = 5, Arg("min_area") = 60, Arg("max_area") = 14400, Arg("max_variation") = 0.25, Arg("min_diversity") = .2, Arg("max_evolution") = 200, Arg("area_threshold") = 1.01, Arg("min_margin") = 0.003, Arg("edge_blur_size") = 5).
    define_method<void(cv::MSER::*)(cv::InputArray, std::vector<std::vector<cv::Point_<int>>>&, std::vector<cv::Rect_<int>>&)>("detect_regions", &cv::MSER::detectRegions,
      Arg("image"), Arg("msers"), Arg("bboxes")).
    define_method<void(cv::MSER::*)(int)>("set_delta", &cv::MSER::setDelta,
      Arg("delta")).
    define_method<int(cv::MSER::*)() const>("get_delta", &cv::MSER::getDelta).
    define_method<void(cv::MSER::*)(int)>("set_min_area", &cv::MSER::setMinArea,
      Arg("min_area")).
    define_method<int(cv::MSER::*)() const>("get_min_area", &cv::MSER::getMinArea).
    define_method<void(cv::MSER::*)(int)>("set_max_area", &cv::MSER::setMaxArea,
      Arg("max_area")).
    define_method<int(cv::MSER::*)() const>("get_max_area", &cv::MSER::getMaxArea).
    define_method<void(cv::MSER::*)(double)>("set_max_variation", &cv::MSER::setMaxVariation,
      Arg("max_variation")).
    define_method<double(cv::MSER::*)() const>("get_max_variation", &cv::MSER::getMaxVariation).
    define_method<void(cv::MSER::*)(double)>("set_min_diversity", &cv::MSER::setMinDiversity,
      Arg("min_diversity")).
    define_method<double(cv::MSER::*)() const>("get_min_diversity", &cv::MSER::getMinDiversity).
    define_method<void(cv::MSER::*)(int)>("set_max_evolution", &cv::MSER::setMaxEvolution,
      Arg("max_evolution")).
    define_method<int(cv::MSER::*)() const>("get_max_evolution", &cv::MSER::getMaxEvolution).
    define_method<void(cv::MSER::*)(double)>("set_area_threshold", &cv::MSER::setAreaThreshold,
      Arg("area_threshold")).
    define_method<double(cv::MSER::*)() const>("get_area_threshold", &cv::MSER::getAreaThreshold).
    define_method<void(cv::MSER::*)(double)>("set_min_margin", &cv::MSER::setMinMargin,
      Arg("min_margin")).
    define_method<double(cv::MSER::*)() const>("get_min_margin", &cv::MSER::getMinMargin).
    define_method<void(cv::MSER::*)(int)>("set_edge_blur_size", &cv::MSER::setEdgeBlurSize,
      Arg("edge_blur_size")).
    define_method<int(cv::MSER::*)() const>("get_edge_blur_size", &cv::MSER::getEdgeBlurSize).
    define_method<void(cv::MSER::*)(bool)>("set_pass2_only", &cv::MSER::setPass2Only,
      Arg("f")).
    define_method<bool(cv::MSER::*)() const>("get_pass2_only?", &cv::MSER::getPass2Only).
    define_method<cv::String(cv::MSER::*)() const>("get_default_name", &cv::MSER::getDefaultName);
  
  Class rb_cCvFastFeatureDetector = define_class_under<cv::FastFeatureDetector, cv::Feature2D>(rb_mCv, "FastFeatureDetector").
    define_singleton_function<cv::Ptr<cv::FastFeatureDetector>(*)(int, bool, cv::FastFeatureDetector::DetectorType)>("create", &cv::FastFeatureDetector::create,
      Arg("threshold") = 10, Arg("nonmax_suppression"), Arg("type")).
    define_method<void(cv::FastFeatureDetector::*)(int)>("set_threshold", &cv::FastFeatureDetector::setThreshold,
      Arg("threshold")).
    define_method<int(cv::FastFeatureDetector::*)() const>("get_threshold", &cv::FastFeatureDetector::getThreshold).
    define_method<void(cv::FastFeatureDetector::*)(bool)>("set_nonmax_suppression", &cv::FastFeatureDetector::setNonmaxSuppression,
      Arg("f")).
    define_method<bool(cv::FastFeatureDetector::*)() const>("get_nonmax_suppression?", &cv::FastFeatureDetector::getNonmaxSuppression).
    define_method<void(cv::FastFeatureDetector::*)(cv::FastFeatureDetector::DetectorType)>("set_type", &cv::FastFeatureDetector::setType,
      Arg("type")).
    define_method<cv::FastFeatureDetector::DetectorType(cv::FastFeatureDetector::*)() const>("get_type", &cv::FastFeatureDetector::getType).
    define_method<cv::String(cv::FastFeatureDetector::*)() const>("get_default_name", &cv::FastFeatureDetector::getDefaultName);
  
  Enum<cv::FastFeatureDetector::DetectorType> rb_cCvFastFeatureDetectorDetectorType = define_enum_under<cv::FastFeatureDetector::DetectorType>("DetectorType", rb_cCvFastFeatureDetector).
    define_value("TYPE_5_8", cv::FastFeatureDetector::DetectorType::TYPE_5_8).
    define_value("TYPE_7_12", cv::FastFeatureDetector::DetectorType::TYPE_7_12).
    define_value("TYPE_9_16", cv::FastFeatureDetector::DetectorType::TYPE_9_16);
  
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool)>("fast", &cv::FAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool, cv::FastFeatureDetector::DetectorType)>("fast", &cv::FAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"), Arg("type"));
  
  Class rb_cCvAgastFeatureDetector = define_class_under<cv::AgastFeatureDetector, cv::Feature2D>(rb_mCv, "AgastFeatureDetector").
    define_singleton_function<cv::Ptr<cv::AgastFeatureDetector>(*)(int, bool, cv::AgastFeatureDetector::DetectorType)>("create", &cv::AgastFeatureDetector::create,
      Arg("threshold") = 10, Arg("nonmax_suppression"), Arg("type")).
    define_method<void(cv::AgastFeatureDetector::*)(int)>("set_threshold", &cv::AgastFeatureDetector::setThreshold,
      Arg("threshold")).
    define_method<int(cv::AgastFeatureDetector::*)() const>("get_threshold", &cv::AgastFeatureDetector::getThreshold).
    define_method<void(cv::AgastFeatureDetector::*)(bool)>("set_nonmax_suppression", &cv::AgastFeatureDetector::setNonmaxSuppression,
      Arg("f")).
    define_method<bool(cv::AgastFeatureDetector::*)() const>("get_nonmax_suppression?", &cv::AgastFeatureDetector::getNonmaxSuppression).
    define_method<void(cv::AgastFeatureDetector::*)(cv::AgastFeatureDetector::DetectorType)>("set_type", &cv::AgastFeatureDetector::setType,
      Arg("type")).
    define_method<cv::AgastFeatureDetector::DetectorType(cv::AgastFeatureDetector::*)() const>("get_type", &cv::AgastFeatureDetector::getType).
    define_method<cv::String(cv::AgastFeatureDetector::*)() const>("get_default_name", &cv::AgastFeatureDetector::getDefaultName);
  
  Enum<cv::AgastFeatureDetector::DetectorType> rb_cCvAgastFeatureDetectorDetectorType = define_enum_under<cv::AgastFeatureDetector::DetectorType>("DetectorType", rb_cCvAgastFeatureDetector).
    define_value("AGAST_5_8", cv::AgastFeatureDetector::DetectorType::AGAST_5_8).
    define_value("AGAST_7_12d", cv::AgastFeatureDetector::DetectorType::AGAST_7_12d).
    define_value("AGAST_7_12s", cv::AgastFeatureDetector::DetectorType::AGAST_7_12s).
    define_value("OAST_9_16", cv::AgastFeatureDetector::DetectorType::OAST_9_16);
  
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool)>("agast", &cv::AGAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, std::vector<cv::KeyPoint>&, int, bool, cv::AgastFeatureDetector::DetectorType)>("agast", &cv::AGAST,
    Arg("image"), Arg("keypoints"), Arg("threshold"), Arg("nonmax_suppression"), Arg("type"));
  
  Class rb_cCvGFTTDetector = define_class_under<cv::GFTTDetector, cv::Feature2D>(rb_mCv, "GFTTDetector").
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, bool, double)>("create", &cv::GFTTDetector::create,
      Arg("max_corners") = 1000, Arg("quality_level") = 0.01, Arg("min_distance") = 1, Arg("block_size") = 3, Arg("use_harris_detector"), Arg("k") = 0.04).
    define_singleton_function<cv::Ptr<cv::GFTTDetector>(*)(int, double, double, int, int, bool, double)>("create", &cv::GFTTDetector::create,
      Arg("max_corners"), Arg("quality_level"), Arg("min_distance"), Arg("block_size"), Arg("gradiant_size"), Arg("use_harris_detector"), Arg("k") = 0.04).
    define_method<void(cv::GFTTDetector::*)(int)>("set_max_features", &cv::GFTTDetector::setMaxFeatures,
      Arg("max_features")).
    define_method<int(cv::GFTTDetector::*)() const>("get_max_features", &cv::GFTTDetector::getMaxFeatures).
    define_method<void(cv::GFTTDetector::*)(double)>("set_quality_level", &cv::GFTTDetector::setQualityLevel,
      Arg("qlevel")).
    define_method<double(cv::GFTTDetector::*)() const>("get_quality_level", &cv::GFTTDetector::getQualityLevel).
    define_method<void(cv::GFTTDetector::*)(double)>("set_min_distance", &cv::GFTTDetector::setMinDistance,
      Arg("min_distance")).
    define_method<double(cv::GFTTDetector::*)() const>("get_min_distance", &cv::GFTTDetector::getMinDistance).
    define_method<void(cv::GFTTDetector::*)(int)>("set_block_size", &cv::GFTTDetector::setBlockSize,
      Arg("block_size")).
    define_method<int(cv::GFTTDetector::*)() const>("get_block_size", &cv::GFTTDetector::getBlockSize).
    define_method<void(cv::GFTTDetector::*)(int)>("set_gradient_size", &cv::GFTTDetector::setGradientSize,
      Arg("gradient_size_")).
    define_method<int(cv::GFTTDetector::*)()>("get_gradient_size", &cv::GFTTDetector::getGradientSize).
    define_method<void(cv::GFTTDetector::*)(bool)>("set_harris_detector", &cv::GFTTDetector::setHarrisDetector,
      Arg("val")).
    define_method<bool(cv::GFTTDetector::*)() const>("get_harris_detector?", &cv::GFTTDetector::getHarrisDetector).
    define_method<void(cv::GFTTDetector::*)(double)>("set_k", &cv::GFTTDetector::setK,
      Arg("k")).
    define_method<double(cv::GFTTDetector::*)() const>("get_k", &cv::GFTTDetector::getK).
    define_method<cv::String(cv::GFTTDetector::*)() const>("get_default_name", &cv::GFTTDetector::getDefaultName);
  
  Class rb_cCvSimpleBlobDetector = define_class_under<cv::SimpleBlobDetector, cv::Feature2D>(rb_mCv, "SimpleBlobDetector").
    define_singleton_function<cv::Ptr<cv::SimpleBlobDetector>(*)(const cv::SimpleBlobDetector::Params&)>("create", &cv::SimpleBlobDetector::create,
      Arg("parameters")).
    define_method<void(cv::SimpleBlobDetector::*)(const cv::SimpleBlobDetector::Params&)>("set_params", &cv::SimpleBlobDetector::setParams,
      Arg("params")).
    define_method<cv::SimpleBlobDetector::Params(cv::SimpleBlobDetector::*)() const>("get_params", &cv::SimpleBlobDetector::getParams).
    define_method<cv::String(cv::SimpleBlobDetector::*)() const>("get_default_name", &cv::SimpleBlobDetector::getDefaultName).
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
    define_method<void(cv::SimpleBlobDetector::Params::*)(const cv::FileNode&)>("read", &cv::SimpleBlobDetector::Params::read,
      Arg("fn")).
    define_method<void(cv::SimpleBlobDetector::Params::*)(cv::FileStorage&) const>("write", &cv::SimpleBlobDetector::Params::write,
      Arg("fs"));
  
  Class rb_cCvKAZE = define_class_under<cv::KAZE, cv::Feature2D>(rb_mCv, "KAZE").
    define_singleton_function<cv::Ptr<cv::KAZE>(*)(bool, bool, float, int, int, cv::KAZE::DiffusivityType)>("create", &cv::KAZE::create,
      Arg("extended"), Arg("upright"), Arg("threshold") = 0.001f, Arg("n_octaves") = 4, Arg("n_octave_layers") = 4, Arg("diffusivity")).
    define_method<void(cv::KAZE::*)(bool)>("set_extended", &cv::KAZE::setExtended,
      Arg("extended")).
    define_method<bool(cv::KAZE::*)() const>("get_extended?", &cv::KAZE::getExtended).
    define_method<void(cv::KAZE::*)(bool)>("set_upright", &cv::KAZE::setUpright,
      Arg("upright")).
    define_method<bool(cv::KAZE::*)() const>("get_upright?", &cv::KAZE::getUpright).
    define_method<void(cv::KAZE::*)(double)>("set_threshold", &cv::KAZE::setThreshold,
      Arg("threshold")).
    define_method<double(cv::KAZE::*)() const>("get_threshold", &cv::KAZE::getThreshold).
    define_method<void(cv::KAZE::*)(int)>("set_n_octaves", &cv::KAZE::setNOctaves,
      Arg("octaves")).
    define_method<int(cv::KAZE::*)() const>("get_n_octaves", &cv::KAZE::getNOctaves).
    define_method<void(cv::KAZE::*)(int)>("set_n_octave_layers", &cv::KAZE::setNOctaveLayers,
      Arg("octave_layers")).
    define_method<int(cv::KAZE::*)() const>("get_n_octave_layers", &cv::KAZE::getNOctaveLayers).
    define_method<void(cv::KAZE::*)(cv::KAZE::DiffusivityType)>("set_diffusivity", &cv::KAZE::setDiffusivity,
      Arg("diff")).
    define_method<cv::KAZE::DiffusivityType(cv::KAZE::*)() const>("get_diffusivity", &cv::KAZE::getDiffusivity).
    define_method<cv::String(cv::KAZE::*)() const>("get_default_name", &cv::KAZE::getDefaultName);
  
  Enum<cv::KAZE::DiffusivityType> rb_cCvKAZEDiffusivityType = define_enum_under<cv::KAZE::DiffusivityType>("DiffusivityType", rb_cCvKAZE).
    define_value("DIFF_PM_G1", cv::KAZE::DiffusivityType::DIFF_PM_G1).
    define_value("DIFF_PM_G2", cv::KAZE::DiffusivityType::DIFF_PM_G2).
    define_value("DIFF_WEICKERT", cv::KAZE::DiffusivityType::DIFF_WEICKERT).
    define_value("DIFF_CHARBONNIER", cv::KAZE::DiffusivityType::DIFF_CHARBONNIER);
  
  Class rb_cCvAKAZE = define_class_under<cv::AKAZE, cv::Feature2D>(rb_mCv, "AKAZE").
    define_singleton_function<cv::Ptr<cv::AKAZE>(*)(cv::AKAZE::DescriptorType, int, int, float, int, int, cv::KAZE::DiffusivityType, int)>("create", &cv::AKAZE::create,
      Arg("descriptor_type"), Arg("descriptor_size") = 0, Arg("descriptor_channels") = 3, Arg("threshold") = 0.001f, Arg("n_octaves") = 4, Arg("n_octave_layers") = 4, Arg("diffusivity"), Arg("max_points") = -1).
    define_method<void(cv::AKAZE::*)(cv::AKAZE::DescriptorType)>("set_descriptor_type", &cv::AKAZE::setDescriptorType,
      Arg("dtype")).
    define_method<cv::AKAZE::DescriptorType(cv::AKAZE::*)() const>("get_descriptor_type", &cv::AKAZE::getDescriptorType).
    define_method<void(cv::AKAZE::*)(int)>("set_descriptor_size", &cv::AKAZE::setDescriptorSize,
      Arg("dsize")).
    define_method<int(cv::AKAZE::*)() const>("get_descriptor_size", &cv::AKAZE::getDescriptorSize).
    define_method<void(cv::AKAZE::*)(int)>("set_descriptor_channels", &cv::AKAZE::setDescriptorChannels,
      Arg("dch")).
    define_method<int(cv::AKAZE::*)() const>("get_descriptor_channels", &cv::AKAZE::getDescriptorChannels).
    define_method<void(cv::AKAZE::*)(double)>("set_threshold", &cv::AKAZE::setThreshold,
      Arg("threshold")).
    define_method<double(cv::AKAZE::*)() const>("get_threshold", &cv::AKAZE::getThreshold).
    define_method<void(cv::AKAZE::*)(int)>("set_n_octaves", &cv::AKAZE::setNOctaves,
      Arg("octaves")).
    define_method<int(cv::AKAZE::*)() const>("get_n_octaves", &cv::AKAZE::getNOctaves).
    define_method<void(cv::AKAZE::*)(int)>("set_n_octave_layers", &cv::AKAZE::setNOctaveLayers,
      Arg("octave_layers")).
    define_method<int(cv::AKAZE::*)() const>("get_n_octave_layers", &cv::AKAZE::getNOctaveLayers).
    define_method<void(cv::AKAZE::*)(cv::KAZE::DiffusivityType)>("set_diffusivity", &cv::AKAZE::setDiffusivity,
      Arg("diff")).
    define_method<cv::KAZE::DiffusivityType(cv::AKAZE::*)() const>("get_diffusivity", &cv::AKAZE::getDiffusivity).
    define_method<cv::String(cv::AKAZE::*)() const>("get_default_name", &cv::AKAZE::getDefaultName).
    define_method<void(cv::AKAZE::*)(int)>("set_max_points", &cv::AKAZE::setMaxPoints,
      Arg("max_points")).
    define_method<int(cv::AKAZE::*)() const>("get_max_points", &cv::AKAZE::getMaxPoints);
  
  Enum<cv::AKAZE::DescriptorType> rb_cCvAKAZEDescriptorType = define_enum_under<cv::AKAZE::DescriptorType>("DescriptorType", rb_cCvAKAZE).
    define_value("DESCRIPTOR_KAZE_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE_UPRIGHT).
    define_value("DESCRIPTOR_KAZE", cv::AKAZE::DescriptorType::DESCRIPTOR_KAZE).
    define_value("DESCRIPTOR_MLDB_UPRIGHT", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB_UPRIGHT).
    define_value("DESCRIPTOR_MLDB", cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB);
  
  Class rb_cCvAccumulatorUnsignedChar = define_class_under<cv::Accumulator<unsigned char>>(rb_mCv, "AccumulatorUnsignedChar").
    define_constructor(Constructor<cv::Accumulator<unsigned char>>());
  
  Class rb_cCvAccumulatorUnsignedShort = define_class_under<cv::Accumulator<unsigned short>>(rb_mCv, "AccumulatorUnsignedShort").
    define_constructor(Constructor<cv::Accumulator<unsigned short>>());
  
  Class rb_cCvAccumulatorChar = define_class_under<cv::Accumulator<char>>(rb_mCv, "AccumulatorChar").
    define_constructor(Constructor<cv::Accumulator<char>>());
  
  Class rb_cCvAccumulatorShort = define_class_under<cv::Accumulator<short>>(rb_mCv, "AccumulatorShort").
    define_constructor(Constructor<cv::Accumulator<short>>());
  
  Class rb_cCvDescriptorMatcher = define_class_under<cv::DescriptorMatcher, cv::Algorithm>(rb_mCv, "DescriptorMatcher").
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArrayOfArrays)>("add", &cv::DescriptorMatcher::add,
      Arg("descriptors")).
    define_method<const std::vector<cv::Mat>&(cv::DescriptorMatcher::*)() const>("get_train_descriptors", &cv::DescriptorMatcher::getTrainDescriptors).
    define_method<void(cv::DescriptorMatcher::*)()>("clear", &cv::DescriptorMatcher::clear).
    define_method<bool(cv::DescriptorMatcher::*)() const>("empty?", &cv::DescriptorMatcher::empty).
    define_method<bool(cv::DescriptorMatcher::*)() const>("is_mask_supported?", &cv::DescriptorMatcher::isMaskSupported).
    define_method<void(cv::DescriptorMatcher::*)()>("train", &cv::DescriptorMatcher::train).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<cv::DMatch>&, cv::InputArray) const>("match", &cv::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("mask")).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, cv::InputArray, bool) const>("knn_match", &cv::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("k"), Arg("mask"), Arg("compact_result")).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, cv::InputArray, bool) const>("radius_match", &cv::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("max_distance"), Arg("mask"), Arg("compact_result")).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<cv::DMatch>&, cv::InputArrayOfArrays)>("match", &cv::DescriptorMatcher::match,
      Arg("query_descriptors"), Arg("matches"), Arg("masks")).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, int, cv::InputArrayOfArrays, bool)>("knn_match", &cv::DescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("k"), Arg("masks"), Arg("compact_result")).
    define_method<void(cv::DescriptorMatcher::*)(cv::InputArray, std::vector<std::vector<cv::DMatch>>&, float, cv::InputArrayOfArrays, bool)>("radius_match", &cv::DescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("max_distance"), Arg("masks"), Arg("compact_result")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("file_name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::String&)>("read", &cv::DescriptorMatcher::read,
      Arg("file_name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::FileNode&)>("read", &cv::DescriptorMatcher::read,
      Arg("")).
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&) const>("write", &cv::DescriptorMatcher::write,
      Arg("")).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::DescriptorMatcher::*)(bool) const>("clone", &cv::DescriptorMatcher::clone,
      Arg("empty_train_data")).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const cv::String&)>("create", &cv::DescriptorMatcher::create,
      Arg("descriptor_matcher_type")).
    define_singleton_function<cv::Ptr<cv::DescriptorMatcher>(*)(const cv::DescriptorMatcher::MatcherType&)>("create", &cv::DescriptorMatcher::create,
      Arg("matcher_type")).
    define_method<void(cv::DescriptorMatcher::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("fs"), Arg("name")).
    define_method<void(cv::DescriptorMatcher::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::DescriptorMatcher::write,
      Arg("fs"), Arg("name"));
  
  Class rb_cCvDescriptorMatcherDescriptorCollection = define_class_under<cv::DescriptorMatcher::DescriptorCollection>(rb_cCvDescriptorMatcher, "DescriptorCollection").
    define_constructor(Constructor<cv::DescriptorMatcher::DescriptorCollection>()).
    define_constructor(Constructor<cv::DescriptorMatcher::DescriptorCollection, const cv::DescriptorMatcher::DescriptorCollection&>(),
      Arg("collection")).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)(const std::vector<cv::Mat>&)>("set", &cv::DescriptorMatcher::DescriptorCollection::set,
      Arg("descriptors")).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)()>("clear", &cv::DescriptorMatcher::DescriptorCollection::clear).
    define_method<const cv::Mat&(cv::DescriptorMatcher::DescriptorCollection::*)() const>("get_descriptors", &cv::DescriptorMatcher::DescriptorCollection::getDescriptors).
    define_method<cv::Mat(cv::DescriptorMatcher::DescriptorCollection::*)(int, int) const>("get_descriptor", &cv::DescriptorMatcher::DescriptorCollection::getDescriptor,
      Arg("img_idx"), Arg("local_desc_idx")).
    define_method<cv::Mat(cv::DescriptorMatcher::DescriptorCollection::*)(int) const>("get_descriptor", &cv::DescriptorMatcher::DescriptorCollection::getDescriptor,
      Arg("global_desc_idx")).
    define_method<void(cv::DescriptorMatcher::DescriptorCollection::*)(int, int&, int&) const>("get_local_idx", &cv::DescriptorMatcher::DescriptorCollection::getLocalIdx,
      Arg("global_desc_idx"), Arg("img_idx"), Arg("local_desc_idx")).
    define_method<int(cv::DescriptorMatcher::DescriptorCollection::*)() const>("size", &cv::DescriptorMatcher::DescriptorCollection::size);
  
  Enum<cv::DescriptorMatcher::MatcherType> rb_cCvDescriptorMatcherMatcherType = define_enum_under<cv::DescriptorMatcher::MatcherType>("MatcherType", rb_cCvDescriptorMatcher).
    define_value("FLANNBASED", cv::DescriptorMatcher::MatcherType::FLANNBASED).
    define_value("BRUTEFORCE", cv::DescriptorMatcher::MatcherType::BRUTEFORCE).
    define_value("BRUTEFORCE_L1", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_L1).
    define_value("BRUTEFORCE_HAMMING", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMING).
    define_value("BRUTEFORCE_HAMMINGLUT", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_HAMMINGLUT).
    define_value("BRUTEFORCE_SL2", cv::DescriptorMatcher::MatcherType::BRUTEFORCE_SL2);
  
  Class rb_cCvBFMatcher = define_class_under<cv::BFMatcher, cv::DescriptorMatcher>(rb_mCv, "BFMatcher").
    define_constructor(Constructor<cv::BFMatcher, int, bool>(),
      Arg("norm_type"), Arg("cross_check")).
    define_method<bool(cv::BFMatcher::*)() const>("is_mask_supported?", &cv::BFMatcher::isMaskSupported).
    define_singleton_function<cv::Ptr<cv::BFMatcher>(*)(int, bool)>("create", &cv::BFMatcher::create,
      Arg("norm_type"), Arg("cross_check")).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::BFMatcher::*)(bool) const>("clone", &cv::BFMatcher::clone,
      Arg("empty_train_data"));
  
  Class rb_cCvFlannBasedMatcher = define_class_under<cv::FlannBasedMatcher, cv::DescriptorMatcher>(rb_mCv, "FlannBasedMatcher").
    define_constructor(Constructor<cv::FlannBasedMatcher, const cv::Ptr<cv::flann::IndexParams>&, const cv::Ptr<cv::flann::SearchParams>&>(),
      Arg("index_params"), Arg("search_params")).
    define_method<void(cv::FlannBasedMatcher::*)(cv::InputArrayOfArrays)>("add", &cv::FlannBasedMatcher::add,
      Arg("descriptors")).
    define_method<void(cv::FlannBasedMatcher::*)()>("clear", &cv::FlannBasedMatcher::clear).
    define_method<void(cv::FlannBasedMatcher::*)(const cv::FileNode&)>("read", &cv::FlannBasedMatcher::read,
      Arg("")).
    define_method<void(cv::FlannBasedMatcher::*)(cv::FileStorage&) const>("write", &cv::FlannBasedMatcher::write,
      Arg("")).
    define_method<void(cv::FlannBasedMatcher::*)()>("train", &cv::FlannBasedMatcher::train).
    define_method<bool(cv::FlannBasedMatcher::*)() const>("is_mask_supported?", &cv::FlannBasedMatcher::isMaskSupported).
    define_singleton_function<cv::Ptr<cv::FlannBasedMatcher>(*)()>("create", &cv::FlannBasedMatcher::create).
    define_method<cv::Ptr<cv::DescriptorMatcher>(cv::FlannBasedMatcher::*)(bool) const>("clone", &cv::FlannBasedMatcher::clone,
      Arg("empty_train_data"));
  
  Enum<cv::DrawMatchesFlags> rb_cCvDrawMatchesFlags = define_enum_under<cv::DrawMatchesFlags>("DrawMatchesFlags", rb_mCv).
    define_value("DEFAULT", cv::DrawMatchesFlags::DEFAULT).
    define_value("DRAW_OVER_OUTIMG", cv::DrawMatchesFlags::DRAW_OVER_OUTIMG).
    define_value("NOT_DRAW_SINGLE_POINTS", cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS).
    define_value("DRAW_RICH_KEYPOINTS", cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputOutputArray, const cv::Scalar&, cv::DrawMatchesFlags)>("draw_keypoints", &cv::drawKeypoints,
    Arg("image"), Arg("keypoints"), Arg("out_image"), Arg("color") = -1, Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, cv::InputOutputArray, const cv::Scalar&, const cv::Scalar&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("match_color") = -1, Arg("single_point_color") = -1, Arg("matches_mask"), Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<cv::DMatch>&, cv::InputOutputArray, const int, const cv::Scalar&, const cv::Scalar&, const std::vector<char>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("matches_thickness"), Arg("match_color") = -1, Arg("single_point_color") = -1, Arg("matches_mask"), Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, const std::vector<cv::KeyPoint>&, cv::InputArray, const std::vector<cv::KeyPoint>&, const std::vector<std::vector<cv::DMatch>>&, cv::InputOutputArray, const cv::Scalar&, const cv::Scalar&, const std::vector<std::vector<char>>&, cv::DrawMatchesFlags)>("draw_matches", &cv::drawMatches,
    Arg("img1"), Arg("keypoints1"), Arg("img2"), Arg("keypoints2"), Arg("matches1to2"), Arg("out_img"), Arg("match_color") = -1, Arg("single_point_color") = -1, Arg("matches_mask"), Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, std::vector<cv::KeyPoint>*, std::vector<cv::KeyPoint>*, float&, int&, const cv::Ptr<cv::Feature2D>&)>("evaluate_feature_detector", &cv::evaluateFeatureDetector,
    Arg("img1"), Arg("img2"), Arg("h1to2"), Arg("keypoints1"), Arg("keypoints2"), Arg("repeatability"), Arg("corresp_count"), Arg("fdetector"));
  
  rb_mCv.define_module_function<void(*)(const std::vector<std::vector<cv::DMatch>>&, const std::vector<std::vector<unsigned char>>&, std::vector<cv::Point_<float>>&)>("compute_recall_precision_curve", &cv::computeRecallPrecisionCurve,
    Arg("matches1to2"), Arg("correct_matches1to2_mask"), Arg("recall_precision_curve"));
  
  rb_mCv.define_module_function<float(*)(const std::vector<cv::Point_<float>>&, float)>("get_recall", &cv::getRecall,
    Arg("recall_precision_curve"), Arg("l_precision"));
  
  rb_mCv.define_module_function<int(*)(const std::vector<cv::Point_<float>>&, float)>("get_nearest_point", &cv::getNearestPoint,
    Arg("recall_precision_curve"), Arg("l_precision"));
  
  Class rb_cCvBOWTrainer = define_class_under<cv::BOWTrainer>(rb_mCv, "BOWTrainer").
    define_method<void(cv::BOWTrainer::*)(const cv::Mat&)>("add", &cv::BOWTrainer::add,
      Arg("descriptors")).
    define_method<const std::vector<cv::Mat>&(cv::BOWTrainer::*)() const>("get_descriptors", &cv::BOWTrainer::getDescriptors).
    define_method<int(cv::BOWTrainer::*)() const>("descriptors_count", &cv::BOWTrainer::descriptorsCount).
    define_method<void(cv::BOWTrainer::*)()>("clear", &cv::BOWTrainer::clear).
    define_method<cv::Mat(cv::BOWTrainer::*)() const>("cluster", &cv::BOWTrainer::cluster).
    define_method<cv::Mat(cv::BOWTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWTrainer::cluster,
      Arg("descriptors"));
  
  Class rb_cCvBOWKMeansTrainer = define_class_under<cv::BOWKMeansTrainer, cv::BOWTrainer>(rb_mCv, "BOWKMeansTrainer").
    define_constructor(Constructor<cv::BOWKMeansTrainer, int, const cv::TermCriteria&, int, int>(),
      Arg("cluster_count"), Arg("termcrit"), Arg("attempts") = 3, Arg("flags")).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)() const>("cluster", &cv::BOWKMeansTrainer::cluster).
    define_method<cv::Mat(cv::BOWKMeansTrainer::*)(const cv::Mat&) const>("cluster", &cv::BOWKMeansTrainer::cluster,
      Arg("descriptors"));
  
  Class rb_cCvBOWImgDescriptorExtractor = define_class_under<cv::BOWImgDescriptorExtractor>(rb_mCv, "BOWImgDescriptorExtractor").
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::Feature2D>&, const cv::Ptr<cv::DescriptorMatcher>&>(),
      Arg("dextractor"), Arg("dmatcher")).
    define_constructor(Constructor<cv::BOWImgDescriptorExtractor, const cv::Ptr<cv::DescriptorMatcher>&>(),
      Arg("dmatcher")).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::Mat&)>("set_vocabulary", &cv::BOWImgDescriptorExtractor::setVocabulary,
      Arg("vocabulary")).
    define_method<const cv::Mat&(cv::BOWImgDescriptorExtractor::*)() const>("get_vocabulary", &cv::BOWImgDescriptorExtractor::getVocabulary).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(cv::InputArray, std::vector<cv::KeyPoint>&, cv::OutputArray, std::vector<std::vector<int>>*, cv::Mat*)>("compute", &cv::BOWImgDescriptorExtractor::compute,
      Arg("image"), Arg("keypoints"), Arg("img_descriptor"), Arg("point_idxs_of_clusters") = 0, Arg("descriptors") = 0).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(cv::InputArray, cv::OutputArray, std::vector<std::vector<int>>*)>("compute", &cv::BOWImgDescriptorExtractor::compute,
      Arg("keypoint_descriptors"), Arg("img_descriptor"), Arg("point_idxs_of_clusters") = 0).
    define_method<void(cv::BOWImgDescriptorExtractor::*)(const cv::Mat&, std::vector<cv::KeyPoint>&, cv::Mat&)>("compute2", &cv::BOWImgDescriptorExtractor::compute2,
      Arg("image"), Arg("keypoints"), Arg("img_descriptor")).
    define_method<int(cv::BOWImgDescriptorExtractor::*)() const>("descriptor_size", &cv::BOWImgDescriptorExtractor::descriptorSize).
    define_method<int(cv::BOWImgDescriptorExtractor::*)() const>("descriptor_type", &cv::BOWImgDescriptorExtractor::descriptorType);

}