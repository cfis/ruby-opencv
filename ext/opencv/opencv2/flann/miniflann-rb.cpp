#include <opencv2/flann/miniflann.hpp>
#include "miniflann-rb.hpp"

using namespace Rice;

extern "C"
void Init_Miniflann()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");
  
  Enum<cv::flann::FlannIndexType> rb_cCvFlannFlannIndexType = define_enum<cv::flann::FlannIndexType>("FlannIndexType", rb_mCvFlann).
    define_value("FLANN_INDEX_TYPE_8U", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_8U).
    define_value("FLANN_INDEX_TYPE_8S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_8S).
    define_value("FLANN_INDEX_TYPE_16U", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_16U).
    define_value("FLANN_INDEX_TYPE_16S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_16S).
    define_value("FLANN_INDEX_TYPE_32S", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_32S).
    define_value("FLANN_INDEX_TYPE_32F", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_32F).
    define_value("FLANN_INDEX_TYPE_64F", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_64F).
    define_value("FLANN_INDEX_TYPE_STRING", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_STRING).
    define_value("FLANN_INDEX_TYPE_BOOL", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_BOOL).
    define_value("FLANN_INDEX_TYPE_ALGORITHM", cv::flann::FlannIndexType::FLANN_INDEX_TYPE_ALGORITHM).
    define_value("LAST_VALUE_FLANN_INDEX_TYPE", cv::flann::FlannIndexType::LAST_VALUE_FLANN_INDEX_TYPE);
  
  Class rb_cCvFlannIndexParams = define_class_under<cv::flann::IndexParams>(rb_mCvFlann, "IndexParams").
    define_constructor(Constructor<cv::flann::IndexParams>()).
    define_method<std::basic_string<char>(cv::flann::IndexParams::*)(const std::basic_string<char>&, const std::basic_string<char>&) const>("get_string", &cv::flann::IndexParams::getString).
    define_method<int(cv::flann::IndexParams::*)(const std::basic_string<char>&, int) const>("get_int", &cv::flann::IndexParams::getInt).
    define_method<double(cv::flann::IndexParams::*)(const std::basic_string<char>&, double) const>("get_double", &cv::flann::IndexParams::getDouble).
    define_method<void(cv::flann::IndexParams::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("set_string", &cv::flann::IndexParams::setString).
    define_method<void(cv::flann::IndexParams::*)(const std::basic_string<char>&, int)>("set_int", &cv::flann::IndexParams::setInt).
    define_method<void(cv::flann::IndexParams::*)(const std::basic_string<char>&, double)>("set_double", &cv::flann::IndexParams::setDouble).
    define_method<void(cv::flann::IndexParams::*)(const std::basic_string<char>&, float)>("set_float", &cv::flann::IndexParams::setFloat).
    define_method<void(cv::flann::IndexParams::*)(const std::basic_string<char>&, bool)>("set_bool", &cv::flann::IndexParams::setBool).
    define_method<void(cv::flann::IndexParams::*)(int)>("set_algorithm", &cv::flann::IndexParams::setAlgorithm).
    define_method<void(cv::flann::IndexParams::*)(std::vector<std::basic_string<char>>&, std::vector<cv::flann::FlannIndexType>&, std::vector<std::basic_string<char>>&, std::vector<double>&) const>("get_all", &cv::flann::IndexParams::getAll).
    define_attr("params", &cv::flann::IndexParams::params).
    define_constructor(Constructor<cv::flann::IndexParams, const cv::flann::IndexParams&>());
  
  Class rb_cCvFlannKDTreeIndexParams = define_class_under<cv::flann::KDTreeIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "KDTreeIndexParams").
    define_constructor(Constructor<cv::flann::KDTreeIndexParams, int>());
  
  Class rb_cCvFlannLinearIndexParams = define_class_under<cv::flann::LinearIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "LinearIndexParams").
    define_constructor(Constructor<cv::flann::LinearIndexParams>());
  
  Class rb_cCvFlannCompositeIndexParams = define_class_under<cv::flann::CompositeIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "CompositeIndexParams").
    define_constructor(Constructor<cv::flann::CompositeIndexParams, int, int, int, cvflann::flann_centers_init_t, float>());
  
  Class rb_cCvFlannAutotunedIndexParams = define_class_under<cv::flann::AutotunedIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "AutotunedIndexParams").
    define_constructor(Constructor<cv::flann::AutotunedIndexParams, float, float, float, float>());
  
  Class rb_cCvFlannHierarchicalClusteringIndexParams = define_class_under<cv::flann::HierarchicalClusteringIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "HierarchicalClusteringIndexParams").
    define_constructor(Constructor<cv::flann::HierarchicalClusteringIndexParams, int, cvflann::flann_centers_init_t, int, int>());
  
  Class rb_cCvFlannKMeansIndexParams = define_class_under<cv::flann::KMeansIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "KMeansIndexParams").
    define_constructor(Constructor<cv::flann::KMeansIndexParams, int, int, cvflann::flann_centers_init_t, float>());
  
  Class rb_cCvFlannLshIndexParams = define_class_under<cv::flann::LshIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "LshIndexParams").
    define_constructor(Constructor<cv::flann::LshIndexParams, int, int, int>());
  
  Class rb_cCvFlannSavedIndexParams = define_class_under<cv::flann::SavedIndexParams, cv::flann::IndexParams>(rb_mCvFlann, "SavedIndexParams").
    define_constructor(Constructor<cv::flann::SavedIndexParams, const std::basic_string<char>&>());
  
  Class rb_cCvFlannSearchParams = define_class_under<cv::flann::SearchParams, cv::flann::IndexParams>(rb_mCvFlann, "SearchParams").
    define_constructor(Constructor<cv::flann::SearchParams, int, float, bool, bool>()).
    define_constructor(Constructor<cv::flann::SearchParams, int, float, bool>());
  
  Class rb_cCvFlannIndex = define_class_under<cv::flann::Index>(rb_mCvFlann, "Index").
    define_constructor(Constructor<cv::flann::Index>()).
    define_constructor(Constructor<cv::flann::Index, const cv::_InputArray &, const cv::flann::IndexParams&, cvflann::flann_distance_t>()).
    define_method<void(cv::flann::Index::*)(const cv::_InputArray &, const cv::flann::IndexParams&, cvflann::flann_distance_t)>("build", &cv::flann::Index::build).
    define_method<void(cv::flann::Index::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::flann::SearchParams&)>("knn_search", &cv::flann::Index::knnSearch).
    define_method<int(cv::flann::Index::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, int, const cv::flann::SearchParams&)>("radius_search", &cv::flann::Index::radiusSearch).
    define_method<void(cv::flann::Index::*)(const std::basic_string<char>&) const>("save", &cv::flann::Index::save).
    define_method<bool(cv::flann::Index::*)(const cv::_InputArray &, const std::basic_string<char>&)>("load", &cv::flann::Index::load).
    define_method<void(cv::flann::Index::*)()>("release", &cv::flann::Index::release).
    define_method<cvflann::flann_distance_t(cv::flann::Index::*)() const>("get_distance", &cv::flann::Index::getDistance).
    define_method<cvflann::flann_algorithm_t(cv::flann::Index::*)() const>("get_algorithm", &cv::flann::Index::getAlgorithm);
}