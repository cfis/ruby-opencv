#include <sstream>
#include <opencv2/objdetect.hpp>
#include "objdetect-rb.hpp"

using namespace Rice;



void Init_Objdetect()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvSimilarRects = define_class_under<cv::SimilarRects>(rb_mCv, "SimilarRects").
    define_constructor(Constructor<cv::SimilarRects, double>(),
      Arg("_eps")).
    define_method<bool(cv::SimilarRects::*)(const cv::Rect&, const cv::Rect&) const>("()", &cv::SimilarRects::operator(),
      Arg("r1"), Arg("r2")).
    define_attr("eps", &cv::SimilarRects::eps);
  
  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("group_threshold"), Arg("eps") = 0.2);
  
  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, std::vector<int>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("weights"), Arg("group_threshold"), Arg("eps") = 0.2);
  
  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, int, double, std::vector<int>*, std::vector<double>*)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("group_threshold"), Arg("eps"), Arg("weights"), Arg("level_weights"));
  
  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, int, double)>("group_rectangles", &cv::groupRectangles,
    Arg("rect_list"), Arg("reject_levels"), Arg("level_weights"), Arg("group_threshold"), Arg("eps") = 0.2);
  
  rb_mCv.define_module_function<void(*)(std::vector<cv::Rect_<int>>&, std::vector<double>&, std::vector<double>&, double, cv::Size)>("group_rectangles_meanshift", &cv::groupRectangles_meanshift,
    Arg("rect_list"), Arg("found_weights"), Arg("found_scales"), Arg("detect_threshold") = 0.0, Arg("win_det_size") = 64128);
  
  Class rb_cCvDefaultDeleterCvHaarClassifierCascade = define_class_under<cv::DefaultDeleter<CvHaarClassifierCascade>>(rb_mCv, "DefaultDeleterCvHaarClassifierCascade").
    define_constructor(Constructor<cv::DefaultDeleter<CvHaarClassifierCascade>>()).
    define_method<void(cv::DefaultDeleter<CvHaarClassifierCascade>::*)(CvHaarClassifierCascade*) const>("()", &cv::DefaultDeleter<CvHaarClassifierCascade>::operator(),
      Arg("obj"));
  
  Class rb_cCvBaseCascadeClassifier = define_class_under<cv::BaseCascadeClassifier, cv::Algorithm>(rb_mCv, "BaseCascadeClassifier").
    define_method<bool(cv::BaseCascadeClassifier::*)() const>("empty?", &cv::BaseCascadeClassifier::empty).
    define_method<bool(cv::BaseCascadeClassifier::*)(const cv::String&)>("load?", &cv::BaseCascadeClassifier::load,
      Arg("filename")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("num_detections"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size")).
    define_method<void(cv::BaseCascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, double, int, int, cv::Size, cv::Size, bool)>("detect_multi_scale", &cv::BaseCascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("reject_levels"), Arg("level_weights"), Arg("scale_factor"), Arg("min_neighbors"), Arg("flags"), Arg("min_size"), Arg("max_size"), Arg("output_reject_levels")).
    define_method<bool(cv::BaseCascadeClassifier::*)() const>("is_old_format_cascade?", &cv::BaseCascadeClassifier::isOldFormatCascade).
    define_method<cv::Size(cv::BaseCascadeClassifier::*)() const>("get_original_window_size", &cv::BaseCascadeClassifier::getOriginalWindowSize).
    define_method<int(cv::BaseCascadeClassifier::*)() const>("get_feature_type", &cv::BaseCascadeClassifier::getFeatureType).
    define_method<void*(cv::BaseCascadeClassifier::*)()>("get_old_cascade", &cv::BaseCascadeClassifier::getOldCascade).
    define_method<void(cv::BaseCascadeClassifier::*)(const cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>&)>("set_mask_generator", &cv::BaseCascadeClassifier::setMaskGenerator,
      Arg("mask_generator")).
    define_method<cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>(cv::BaseCascadeClassifier::*)()>("get_mask_generator", &cv::BaseCascadeClassifier::getMaskGenerator);
  
  Class rb_cCvBaseCascadeClassifierMaskGenerator = define_class_under<cv::BaseCascadeClassifier::MaskGenerator>(rb_cCvBaseCascadeClassifier, "MaskGenerator").
    define_method<cv::Mat(cv::BaseCascadeClassifier::MaskGenerator::*)(const cv::Mat&)>("generate_mask", &cv::BaseCascadeClassifier::MaskGenerator::generateMask,
      Arg("src")).
    define_method<void(cv::BaseCascadeClassifier::MaskGenerator::*)(const cv::Mat&)>("initialize_mask", &cv::BaseCascadeClassifier::MaskGenerator::initializeMask,
      Arg(""));
  
  Class rb_cCvCascadeClassifier = define_class_under<cv::CascadeClassifier>(rb_mCv, "CascadeClassifier").
    define_constructor(Constructor<cv::CascadeClassifier>()).
    define_constructor(Constructor<cv::CascadeClassifier, const cv::String&>(),
      Arg("filename")).
    define_method<bool(cv::CascadeClassifier::*)() const>("empty?", &cv::CascadeClassifier::empty).
    define_method<bool(cv::CascadeClassifier::*)(const cv::String&)>("load?", &cv::CascadeClassifier::load,
      Arg("filename")).
    define_method<bool(cv::CascadeClassifier::*)(const cv::FileNode&)>("read?", &cv::CascadeClassifier::read,
      Arg("node")).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("scale_factor") = 1.1, Arg("min_neighbors") = 3, Arg("flags") = 0, Arg("min_size"), Arg("max_size")).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, double, int, int, cv::Size, cv::Size)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("num_detections"), Arg("scale_factor") = 1.1, Arg("min_neighbors") = 3, Arg("flags") = 0, Arg("min_size"), Arg("max_size")).
    define_method<void(cv::CascadeClassifier::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<int>&, std::vector<double>&, double, int, int, cv::Size, cv::Size, bool)>("detect_multi_scale", &cv::CascadeClassifier::detectMultiScale,
      Arg("image"), Arg("objects"), Arg("reject_levels"), Arg("level_weights"), Arg("scale_factor") = 1.1, Arg("min_neighbors") = 3, Arg("flags") = 0, Arg("min_size"), Arg("max_size"), Arg("output_reject_levels")).
    define_method<bool(cv::CascadeClassifier::*)() const>("is_old_format_cascade?", &cv::CascadeClassifier::isOldFormatCascade).
    define_method<cv::Size(cv::CascadeClassifier::*)() const>("get_original_window_size", &cv::CascadeClassifier::getOriginalWindowSize).
    define_method<int(cv::CascadeClassifier::*)() const>("get_feature_type", &cv::CascadeClassifier::getFeatureType).
    define_method<void*(cv::CascadeClassifier::*)()>("get_old_cascade", &cv::CascadeClassifier::getOldCascade).
    define_singleton_function<bool(*)(const cv::String&, const cv::String&)>("convert?", &cv::CascadeClassifier::convert,
      Arg("oldcascade"), Arg("newcascade")).
    define_method<void(cv::CascadeClassifier::*)(const cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>&)>("set_mask_generator", &cv::CascadeClassifier::setMaskGenerator,
      Arg("mask_generator")).
    define_method<cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>(cv::CascadeClassifier::*)()>("get_mask_generator", &cv::CascadeClassifier::getMaskGenerator).
    define_attr("cc", &cv::CascadeClassifier::cc);
  
  rb_mCv.define_module_function<cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>(*)()>("create_face_detection_mask_generator", &cv::createFaceDetectionMaskGenerator);
  
  Class rb_cCvDetectionROI = define_class_under<cv::DetectionROI>(rb_mCv, "DetectionROI").
    define_constructor(Constructor<cv::DetectionROI>()).
    define_attr("scale", &cv::DetectionROI::scale).
    define_attr("locations", &cv::DetectionROI::locations).
    define_attr("confidences", &cv::DetectionROI::confidences);
  
  Class rb_cCvHOGDescriptor = define_class_under<cv::HOGDescriptor>(rb_mCv, "HOGDescriptor").
    define_constructor(Constructor<cv::HOGDescriptor>()).
    define_constructor(Constructor<cv::HOGDescriptor, cv::Size, cv::Size, cv::Size, cv::Size, int, int, double, cv::HOGDescriptor::HistogramNormType, double, bool, int, bool>(),
      Arg("_win_size"), Arg("_block_size"), Arg("_block_stride"), Arg("_cell_size"), Arg("_nbins"), Arg("_deriv_aperture") = 1, Arg("_win_sigma") = -1, Arg("_histogram_norm_type"), Arg("_l2_hys_threshold") = 0.2, Arg("_gamma_correction"), Arg("_nlevels"), Arg("_signed_gradient")).
    define_constructor(Constructor<cv::HOGDescriptor, const cv::String&>(),
      Arg("filename")).
    define_constructor(Constructor<cv::HOGDescriptor, const cv::HOGDescriptor&>(),
      Arg("d")).
    define_method<::size_t(cv::HOGDescriptor::*)() const>("get_descriptor_size", &cv::HOGDescriptor::getDescriptorSize).
    define_method<bool(cv::HOGDescriptor::*)() const>("check_detector_size?", &cv::HOGDescriptor::checkDetectorSize).
    define_method<double(cv::HOGDescriptor::*)() const>("get_win_sigma", &cv::HOGDescriptor::getWinSigma).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray)>("set_svm_detector", &cv::HOGDescriptor::setSVMDetector,
      Arg("svmdetector")).
    define_method<bool(cv::HOGDescriptor::*)(cv::FileNode&)>("read?", &cv::HOGDescriptor::read,
      Arg("fn")).
    define_method<void(cv::HOGDescriptor::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::HOGDescriptor::write,
      Arg("fs"), Arg("objname")).
    define_method<bool(cv::HOGDescriptor::*)(const cv::String&, const cv::String&)>("load?", &cv::HOGDescriptor::load,
      Arg("filename"), Arg("objname")).
    define_method<void(cv::HOGDescriptor::*)(const cv::String&, const cv::String&) const>("save", &cv::HOGDescriptor::save,
      Arg("filename"), Arg("objname")).
    define_method<void(cv::HOGDescriptor::*)(cv::HOGDescriptor&) const>("copy_to", &cv::HOGDescriptor::copyTo,
      Arg("c")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<float>&, cv::Size, cv::Size, const std::vector<cv::Point_<int>>&) const>("compute", &cv::HOGDescriptor::compute,
      Arg("img"), Arg("descriptors"), Arg("win_stride"), Arg("padding"), Arg("locations")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Point_<int>>&, std::vector<double>&, double, cv::Size, cv::Size, const std::vector<cv::Point_<int>>&) const>("detect", &cv::HOGDescriptor::detect,
      Arg("img"), Arg("found_locations"), Arg("weights"), Arg("hit_threshold") = 0, Arg("win_stride"), Arg("padding"), Arg("search_locations")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Point_<int>>&, double, cv::Size, cv::Size, const std::vector<cv::Point_<int>>&) const>("detect", &cv::HOGDescriptor::detect,
      Arg("img"), Arg("found_locations"), Arg("hit_threshold") = 0, Arg("win_stride"), Arg("padding"), Arg("search_locations")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<double>&, double, cv::Size, cv::Size, double, double, bool) const>("detect_multi_scale", &cv::HOGDescriptor::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("found_weights"), Arg("hit_threshold") = 0, Arg("win_stride"), Arg("padding"), Arg("scale") = 1.05, Arg("group_threshold") = 2.0, Arg("use_meanshift_grouping")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, double, cv::Size, cv::Size, double, double, bool) const>("detect_multi_scale", &cv::HOGDescriptor::detectMultiScale,
      Arg("img"), Arg("found_locations"), Arg("hit_threshold") = 0, Arg("win_stride"), Arg("padding"), Arg("scale") = 1.05, Arg("group_threshold") = 2.0, Arg("use_meanshift_grouping")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, cv::Size, cv::Size) const>("compute_gradient", &cv::HOGDescriptor::computeGradient,
      Arg("img"), Arg("grad"), Arg("angle_ofs"), Arg("padding_tl"), Arg("padding_br")).
    define_singleton_function<std::vector<float>(*)()>("get_default_people_detector", &cv::HOGDescriptor::getDefaultPeopleDetector).
    define_singleton_function<std::vector<float>(*)()>("get_daimler_people_detector", &cv::HOGDescriptor::getDaimlerPeopleDetector).
    define_attr("win_size", &cv::HOGDescriptor::winSize).
    define_attr("block_size", &cv::HOGDescriptor::blockSize).
    define_attr("block_stride", &cv::HOGDescriptor::blockStride).
    define_attr("cell_size", &cv::HOGDescriptor::cellSize).
    define_attr("nbins", &cv::HOGDescriptor::nbins).
    define_attr("deriv_aperture", &cv::HOGDescriptor::derivAperture).
    define_attr("win_sigma", &cv::HOGDescriptor::winSigma).
    define_attr("histogram_norm_type", &cv::HOGDescriptor::histogramNormType).
    define_attr("l2_hys_threshold", &cv::HOGDescriptor::L2HysThreshold).
    define_attr("gamma_correction", &cv::HOGDescriptor::gammaCorrection).
    define_attr("svm_detector", &cv::HOGDescriptor::svmDetector).
    define_attr("ocl_svm_detector", &cv::HOGDescriptor::oclSvmDetector).
    define_attr("free_coef", &cv::HOGDescriptor::free_coef).
    define_attr("nlevels", &cv::HOGDescriptor::nlevels).
    define_attr("signed_gradient", &cv::HOGDescriptor::signedGradient).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, const std::vector<cv::Point_<int>>&, std::vector<cv::Point_<int>>&, std::vector<double>&, double, cv::Size, cv::Size) const>("detect_roi", &cv::HOGDescriptor::detectROI,
      Arg("img"), Arg("locations"), Arg("found_locations"), Arg("confidences"), Arg("hit_threshold") = 0, Arg("win_stride"), Arg("padding")).
    define_method<void(cv::HOGDescriptor::*)(cv::InputArray, std::vector<cv::Rect_<int>>&, std::vector<cv::DetectionROI>&, double, int) const>("detect_multi_scale_roi", &cv::HOGDescriptor::detectMultiScaleROI,
      Arg("img"), Arg("found_locations"), Arg("locations"), Arg("hit_threshold") = 0, Arg("group_threshold") = 0).
    define_method<void(cv::HOGDescriptor::*)(std::vector<cv::Rect_<int>>&, std::vector<double>&, int, double) const>("group_rectangles", &cv::HOGDescriptor::groupRectangles,
      Arg("rect_list"), Arg("weights"), Arg("group_threshold"), Arg("eps"));
  
  Enum<cv::HOGDescriptor::HistogramNormType> rb_cCvHOGDescriptorHistogramNormType = define_enum_under<cv::HOGDescriptor::HistogramNormType>("HistogramNormType", rb_cCvHOGDescriptor).
    define_value("L2Hys", cv::HOGDescriptor::HistogramNormType::L2Hys);
  
  
  Enum<cv::HOGDescriptor::DescriptorStorageFormat> rb_cCvHOGDescriptorDescriptorStorageFormat = define_enum_under<cv::HOGDescriptor::DescriptorStorageFormat>("DescriptorStorageFormat", rb_cCvHOGDescriptor).
    define_value("DESCR_FORMAT_COL_BY_COL", cv::HOGDescriptor::DescriptorStorageFormat::DESCR_FORMAT_COL_BY_COL).
    define_value("DESCR_FORMAT_ROW_BY_ROW", cv::HOGDescriptor::DescriptorStorageFormat::DESCR_FORMAT_ROW_BY_ROW);
  
  Class rb_cCvQRCodeEncoder = define_class_under<cv::QRCodeEncoder>(rb_mCv, "QRCodeEncoder").
    define_singleton_function<cv::Ptr<cv::QRCodeEncoder>(*)(const cv::QRCodeEncoder::Params&)>("create", &cv::QRCodeEncoder::create,
      Arg("parameters")).
    define_method<void(cv::QRCodeEncoder::*)(const cv::String&, cv::OutputArray)>("encode", &cv::QRCodeEncoder::encode,
      Arg("encoded_info"), Arg("qrcode")).
    define_method<void(cv::QRCodeEncoder::*)(const cv::String&, cv::OutputArrayOfArrays)>("encode_structured_append", &cv::QRCodeEncoder::encodeStructuredAppend,
      Arg("encoded_info"), Arg("qrcodes"));
  
  Class rb_cCvQRCodeEncoderParams = define_class_under<cv::QRCodeEncoder::Params>(rb_cCvQRCodeEncoder, "Params").
    define_constructor(Constructor<cv::QRCodeEncoder::Params>()).
    define_attr("version", &cv::QRCodeEncoder::Params::version).
    define_attr("correction_level", &cv::QRCodeEncoder::Params::correction_level).
    define_attr("mode", &cv::QRCodeEncoder::Params::mode).
    define_attr("structure_number", &cv::QRCodeEncoder::Params::structure_number);
  
  Enum<cv::QRCodeEncoder::EncodeMode> rb_cCvQRCodeEncoderEncodeMode = define_enum_under<cv::QRCodeEncoder::EncodeMode>("EncodeMode", rb_cCvQRCodeEncoder).
    define_value("MODE_AUTO", cv::QRCodeEncoder::EncodeMode::MODE_AUTO).
    define_value("MODE_NUMERIC", cv::QRCodeEncoder::EncodeMode::MODE_NUMERIC).
    define_value("MODE_ALPHANUMERIC", cv::QRCodeEncoder::EncodeMode::MODE_ALPHANUMERIC).
    define_value("MODE_BYTE", cv::QRCodeEncoder::EncodeMode::MODE_BYTE).
    define_value("MODE_ECI", cv::QRCodeEncoder::EncodeMode::MODE_ECI).
    define_value("MODE_KANJI", cv::QRCodeEncoder::EncodeMode::MODE_KANJI).
    define_value("MODE_STRUCTURED_APPEND", cv::QRCodeEncoder::EncodeMode::MODE_STRUCTURED_APPEND);
  
  Enum<cv::QRCodeEncoder::CorrectionLevel> rb_cCvQRCodeEncoderCorrectionLevel = define_enum_under<cv::QRCodeEncoder::CorrectionLevel>("CorrectionLevel", rb_cCvQRCodeEncoder).
    define_value("CORRECT_LEVEL_L", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_L).
    define_value("CORRECT_LEVEL_M", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_M).
    define_value("CORRECT_LEVEL_Q", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_Q).
    define_value("CORRECT_LEVEL_H", cv::QRCodeEncoder::CorrectionLevel::CORRECT_LEVEL_H);
  
  Enum<cv::QRCodeEncoder::ECIEncodings> rb_cCvQRCodeEncoderECIEncodings = define_enum_under<cv::QRCodeEncoder::ECIEncodings>("ECIEncodings", rb_cCvQRCodeEncoder).
    define_value("ECI_UTF8", cv::QRCodeEncoder::ECIEncodings::ECI_UTF8);
  
  Class rb_cCvQRCodeDetector = define_class_under<cv::QRCodeDetector, cv::GraphicalCodeDetector>(rb_mCv, "QRCodeDetector").
    define_constructor(Constructor<cv::QRCodeDetector>()).
    define_method<cv::QRCodeDetector&(cv::QRCodeDetector::*)(double)>("set_eps_x", &cv::QRCodeDetector::setEpsX,
      Arg("eps_x")).
    define_method<cv::QRCodeDetector&(cv::QRCodeDetector::*)(double)>("set_eps_y", &cv::QRCodeDetector::setEpsY,
      Arg("eps_y")).
    define_method<cv::QRCodeDetector&(cv::QRCodeDetector::*)(bool)>("set_use_alignment_markers", &cv::QRCodeDetector::setUseAlignmentMarkers,
      Arg("use_alignment_markers")).
    define_method<cv::String(cv::QRCodeDetector::*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("decode_curved", &cv::QRCodeDetector::decodeCurved,
      Arg("img"), Arg("points"), Arg("straight_qrcode")).
    define_method<std::string(cv::QRCodeDetector::*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("detect_and_decode_curved", &cv::QRCodeDetector::detectAndDecodeCurved,
      Arg("img"), Arg("points"), Arg("straight_qrcode"));
  
  Class rb_cCvQRCodeDetectorAruco = define_class_under<cv::QRCodeDetectorAruco, cv::GraphicalCodeDetector>(rb_mCv, "QRCodeDetectorAruco").
    define_constructor(Constructor<cv::QRCodeDetectorAruco>()).
    define_constructor(Constructor<cv::QRCodeDetectorAruco, const cv::QRCodeDetectorAruco::Params&>(),
      Arg("params")).
    define_method<const cv::QRCodeDetectorAruco::Params&(cv::QRCodeDetectorAruco::*)() const>("get_detector_parameters", &cv::QRCodeDetectorAruco::getDetectorParameters).
    define_method<cv::QRCodeDetectorAruco&(cv::QRCodeDetectorAruco::*)(const cv::QRCodeDetectorAruco::Params&)>("set_detector_parameters", &cv::QRCodeDetectorAruco::setDetectorParameters,
      Arg("params")).
    define_method<const cv::aruco::DetectorParameters&(cv::QRCodeDetectorAruco::*)() const>("get_aruco_parameters", &cv::QRCodeDetectorAruco::getArucoParameters).
    define_method<void(cv::QRCodeDetectorAruco::*)(const cv::aruco::DetectorParameters&)>("set_aruco_parameters", &cv::QRCodeDetectorAruco::setArucoParameters,
      Arg("params"));
  
  Class rb_cCvQRCodeDetectorArucoParams = define_class_under<cv::QRCodeDetectorAruco::Params>(rb_cCvQRCodeDetectorAruco, "Params").
    define_constructor(Constructor<cv::QRCodeDetectorAruco::Params>()).
    define_attr("min_module_size_in_pyramid", &cv::QRCodeDetectorAruco::Params::minModuleSizeInPyramid).
    define_attr("max_rotation", &cv::QRCodeDetectorAruco::Params::maxRotation).
    define_attr("max_module_size_mismatch", &cv::QRCodeDetectorAruco::Params::maxModuleSizeMismatch).
    define_attr("max_timing_pattern_mismatch", &cv::QRCodeDetectorAruco::Params::maxTimingPatternMismatch).
    define_attr("max_penalties", &cv::QRCodeDetectorAruco::Params::maxPenalties).
    define_attr("max_colors_mismatch", &cv::QRCodeDetectorAruco::Params::maxColorsMismatch).
    define_attr("scale_timing_pattern_score", &cv::QRCodeDetectorAruco::Params::scaleTimingPatternScore);

}