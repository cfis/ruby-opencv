#include <opencv2/objdetect/aruco_dictionary.hpp>
#include "aruco_dictionary-rb.hpp"

using namespace Rice;

extern "C"
void Init_ArucoDictionary()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvAruco = define_module_under(rb_mCv, "Aruco");
  
  Class rb_cCvArucoDictionary = define_class_under<cv::aruco::Dictionary>(rb_mCvAruco, "Dictionary").
    define_attr("bytes_list", &cv::aruco::Dictionary::bytesList).
    define_attr("marker_size", &cv::aruco::Dictionary::markerSize).
    define_attr("max_correction_bits", &cv::aruco::Dictionary::maxCorrectionBits).
    define_constructor(Constructor<cv::aruco::Dictionary>()).
    define_constructor(Constructor<cv::aruco::Dictionary, const cv::Mat&, int, int>()).
    define_method<bool(cv::aruco::Dictionary::*)(const cv::FileNode&)>("read_dictionary", &cv::aruco::Dictionary::readDictionary).
    define_method<void(cv::aruco::Dictionary::*)(cv::FileStorage&, const std::basic_string<char>&)>("write_dictionary", &cv::aruco::Dictionary::writeDictionary).
    define_method<bool(cv::aruco::Dictionary::*)(const cv::Mat&, int&, int&, double) const>("identify", &cv::aruco::Dictionary::identify).
    define_method<int(cv::aruco::Dictionary::*)(const cv::_InputArray &, int, bool) const>("get_distance_to_id", &cv::aruco::Dictionary::getDistanceToId).
    define_method<void(cv::aruco::Dictionary::*)(int, int, const cv::_OutputArray &, int) const>("generate_image_marker", &cv::aruco::Dictionary::generateImageMarker).
    define_singleton_function<cv::Mat(*)(const cv::Mat&)>("get_byte_list_from_bits", &cv::aruco::Dictionary::getByteListFromBits).
    define_singleton_function<cv::Mat(*)(const cv::Mat&, int)>("get_bits_from_byte_list", &cv::aruco::Dictionary::getBitsFromByteList);
  
  Enum<cv::aruco::PredefinedDictionaryType> rb_cCvArucoPredefinedDictionaryType = define_enum<cv::aruco::PredefinedDictionaryType>("PredefinedDictionaryType", rb_mCvAruco).
    define_value("DICT_4X4_50", cv::aruco::PredefinedDictionaryType::DICT_4X4_50).
    define_value("DICT_4X4_100", cv::aruco::PredefinedDictionaryType::DICT_4X4_100).
    define_value("DICT_4X4_250", cv::aruco::PredefinedDictionaryType::DICT_4X4_250).
    define_value("DICT_4X4_1000", cv::aruco::PredefinedDictionaryType::DICT_4X4_1000).
    define_value("DICT_5X5_50", cv::aruco::PredefinedDictionaryType::DICT_5X5_50).
    define_value("DICT_5X5_100", cv::aruco::PredefinedDictionaryType::DICT_5X5_100).
    define_value("DICT_5X5_250", cv::aruco::PredefinedDictionaryType::DICT_5X5_250).
    define_value("DICT_5X5_1000", cv::aruco::PredefinedDictionaryType::DICT_5X5_1000).
    define_value("DICT_6X6_50", cv::aruco::PredefinedDictionaryType::DICT_6X6_50).
    define_value("DICT_6X6_100", cv::aruco::PredefinedDictionaryType::DICT_6X6_100).
    define_value("DICT_6X6_250", cv::aruco::PredefinedDictionaryType::DICT_6X6_250).
    define_value("DICT_6X6_1000", cv::aruco::PredefinedDictionaryType::DICT_6X6_1000).
    define_value("DICT_7X7_50", cv::aruco::PredefinedDictionaryType::DICT_7X7_50).
    define_value("DICT_7X7_100", cv::aruco::PredefinedDictionaryType::DICT_7X7_100).
    define_value("DICT_7X7_250", cv::aruco::PredefinedDictionaryType::DICT_7X7_250).
    define_value("DICT_7X7_1000", cv::aruco::PredefinedDictionaryType::DICT_7X7_1000).
    define_value("DICT_ARUCO_ORIGINAL", cv::aruco::PredefinedDictionaryType::DICT_ARUCO_ORIGINAL).
    define_value("DICT_APRILTAG_16h5", cv::aruco::PredefinedDictionaryType::DICT_APRILTAG_16h5).
    define_value("DICT_APRILTAG_25h9", cv::aruco::PredefinedDictionaryType::DICT_APRILTAG_25h9).
    define_value("DICT_APRILTAG_36h10", cv::aruco::PredefinedDictionaryType::DICT_APRILTAG_36h10).
    define_value("DICT_APRILTAG_36h11", cv::aruco::PredefinedDictionaryType::DICT_APRILTAG_36h11).
    define_value("DICT_ARUCO_MIP_36h12", cv::aruco::PredefinedDictionaryType::DICT_ARUCO_MIP_36h12);
  
  rb_mCvAruco.define_module_function<cv::aruco::Dictionary(*)(cv::aruco::PredefinedDictionaryType)>("get_predefined_dictionary", &cv::aruco::getPredefinedDictionary);
  
  rb_mCvAruco.define_module_function<cv::aruco::Dictionary(*)(int)>("get_predefined_dictionary", &cv::aruco::getPredefinedDictionary);
  
  rb_mCvAruco.define_module_function<cv::aruco::Dictionary(*)(int, int, const cv::aruco::Dictionary&, int)>("extend_dictionary", &cv::aruco::extendDictionary);
}