#include <opencv2/line_descriptor/descriptor.hpp>
#include "descriptor-rb.hpp"

using namespace Rice;

extern "C"
void Init_Descriptor()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvLineDescriptor = define_module_under(rb_mCv, "LineDescriptor");
  
  Class rb_cCvLineDescriptorKeyLine = define_class_under<cv::line_descriptor::KeyLine>(rb_mCvLineDescriptor, "KeyLine").
    define_attr("angle", &cv::line_descriptor::KeyLine::angle).
    define_attr("class_id", &cv::line_descriptor::KeyLine::class_id).
    define_attr("octave", &cv::line_descriptor::KeyLine::octave).
    define_attr("pt", &cv::line_descriptor::KeyLine::pt).
    define_attr("response", &cv::line_descriptor::KeyLine::response).
    define_attr("size", &cv::line_descriptor::KeyLine::size).
    define_attr("start_point_x", &cv::line_descriptor::KeyLine::startPointX).
    define_attr("start_point_y", &cv::line_descriptor::KeyLine::startPointY).
    define_attr("end_point_x", &cv::line_descriptor::KeyLine::endPointX).
    define_attr("end_point_y", &cv::line_descriptor::KeyLine::endPointY).
    define_attr("s_point_in_octave_x", &cv::line_descriptor::KeyLine::sPointInOctaveX).
    define_attr("s_point_in_octave_y", &cv::line_descriptor::KeyLine::sPointInOctaveY).
    define_attr("e_point_in_octave_x", &cv::line_descriptor::KeyLine::ePointInOctaveX).
    define_attr("e_point_in_octave_y", &cv::line_descriptor::KeyLine::ePointInOctaveY).
    define_attr("line_length", &cv::line_descriptor::KeyLine::lineLength).
    define_attr("num_of_pixels", &cv::line_descriptor::KeyLine::numOfPixels).
    define_method<cv::Point_<float>(cv::line_descriptor::KeyLine::*)() const>("get_start_point", &cv::line_descriptor::KeyLine::getStartPoint).
    define_method<cv::Point_<float>(cv::line_descriptor::KeyLine::*)() const>("get_end_point", &cv::line_descriptor::KeyLine::getEndPoint).
    define_method<cv::Point_<float>(cv::line_descriptor::KeyLine::*)() const>("get_start_point_in_octave", &cv::line_descriptor::KeyLine::getStartPointInOctave).
    define_method<cv::Point_<float>(cv::line_descriptor::KeyLine::*)() const>("get_end_point_in_octave", &cv::line_descriptor::KeyLine::getEndPointInOctave).
    define_constructor(Constructor<cv::line_descriptor::KeyLine>());
  
  Class rb_cCvLineDescriptorBinaryDescriptor = define_class_under<cv::line_descriptor::BinaryDescriptor, cv::Algorithm>(rb_mCvLineDescriptor, "BinaryDescriptor").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor, const cv::line_descriptor::BinaryDescriptor::Params&>()).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor>(*)()>("create_binary_descriptor", &cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor>(*)(cv::line_descriptor::BinaryDescriptor::Params)>("create_binary_descriptor", &cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_num_of_octaves", &cv::line_descriptor::BinaryDescriptor::getNumOfOctaves).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_num_of_octaves", &cv::line_descriptor::BinaryDescriptor::setNumOfOctaves).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_width_of_band", &cv::line_descriptor::BinaryDescriptor::getWidthOfBand).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_width_of_band", &cv::line_descriptor::BinaryDescriptor::setWidthOfBand).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_reduction_ratio", &cv::line_descriptor::BinaryDescriptor::getReductionRatio).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_reduction_ratio", &cv::line_descriptor::BinaryDescriptor::setReductionRatio).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::FileNode&)>("read", &cv::line_descriptor::BinaryDescriptor::read).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(cv::FileStorage&) const>("write", &cv::line_descriptor::BinaryDescriptor::write).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, const cv::Mat&)>("detect", &cv::line_descriptor::BinaryDescriptor::detect).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, const std::vector<cv::Mat>&) const>("detect", &cv::line_descriptor::BinaryDescriptor::detect).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, cv::Mat&, bool) const>("compute", &cv::line_descriptor::BinaryDescriptor::compute).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, std::vector<cv::Mat>&, bool) const>("compute", &cv::line_descriptor::BinaryDescriptor::compute).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("descriptor_size", &cv::line_descriptor::BinaryDescriptor::descriptorSize).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("descriptor_type", &cv::line_descriptor::BinaryDescriptor::descriptorType).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("default_norm", &cv::line_descriptor::BinaryDescriptor::defaultNorm).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::line_descriptor::KeyLine>&, const cv::_OutputArray &, bool, bool) const>("operator()", &cv::line_descriptor::BinaryDescriptor::operator());
  
  Class rb_cCvLineDescriptorBinaryDescriptorEDLineDetector = define_class_under<cv::line_descriptor::BinaryDescriptor::EDLineDetector>(rb_cCvLineDescriptorBinaryDescriptor, "EDLineDetector").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor::EDLineDetector>()).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor::EDLineDetector, cv::line_descriptor::BinaryDescriptor::EDLineParam>()).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor::EDLineDetector>(*)()>("create_ed_line_detector", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::createEDLineDetector).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor::EDLineDetector>(*)(cv::line_descriptor::BinaryDescriptor::EDLineParam)>("create_ed_line_detector", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::createEDLineDetector).
    define_method<int(cv::line_descriptor::BinaryDescriptor::EDLineDetector::*)(cv::Mat&, cv::line_descriptor::BinaryDescriptor::EdgeChains&)>("edge_drawing", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::EdgeDrawing).
    define_method<int(cv::line_descriptor::BinaryDescriptor::EDLineDetector::*)(cv::Mat&, cv::line_descriptor::BinaryDescriptor::LineChains&)>("e_dline", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::EDline).
    define_method<int(cv::line_descriptor::BinaryDescriptor::EDLineDetector::*)(cv::Mat&)>("e_dline", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::EDline).
    define_attr("dx_img_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::dxImg_).
    define_attr("dy_img_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::dyImg_).
    define_attr("g_img_wo_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::gImgWO_).
    define_attr("lines_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lines_).
    define_attr("line_equations_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lineEquations_).
    define_attr("line_endpoints_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lineEndpoints_).
    define_attr("line_direction_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lineDirection_).
    define_attr("line_salience_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lineSalience_).
    define_attr("image_width", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::imageWidth).
    define_attr("image_height", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::imageHeight).
    define_attr("line_fit_err_threshold_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::lineFitErrThreshold_).
    define_attr("gradien_threshold_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::gradienThreshold_).
    define_attr("anchor_threshold_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::anchorThreshold_).
    define_attr("scan_intervals_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::scanIntervals_).
    define_attr("min_line_len_", &cv::line_descriptor::BinaryDescriptor::EDLineDetector::minLineLen_);
  
  Class rb_cCvLineDescriptorBinaryDescriptorParams = define_class_under<cv::line_descriptor::BinaryDescriptor::Params>(rb_cCvLineDescriptorBinaryDescriptor, "Params").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor::Params>()).
    define_attr("num_of_octave_", &cv::line_descriptor::BinaryDescriptor::Params::numOfOctave_).
    define_attr("width_of_band_", &cv::line_descriptor::BinaryDescriptor::Params::widthOfBand_).
    define_attr("reduction_ratio", &cv::line_descriptor::BinaryDescriptor::Params::reductionRatio).
    define_attr("ksize_", &cv::line_descriptor::BinaryDescriptor::Params::ksize_).
    define_method<void(cv::line_descriptor::BinaryDescriptor::Params::*)(const cv::FileNode&)>("read", &cv::line_descriptor::BinaryDescriptor::Params::read).
    define_method<void(cv::line_descriptor::BinaryDescriptor::Params::*)(cv::FileStorage&) const>("write", &cv::line_descriptor::BinaryDescriptor::Params::write);
  
  Class rb_cCvLineDescriptorBinaryDescriptorOctaveLine = define_class_under<cv::line_descriptor::BinaryDescriptor::OctaveLine>(rb_cCvLineDescriptorBinaryDescriptor, "OctaveLine").
    define_attr("octave_count", &cv::line_descriptor::BinaryDescriptor::OctaveLine::octaveCount).
    define_attr("line_id_in_octave", &cv::line_descriptor::BinaryDescriptor::OctaveLine::lineIDInOctave).
    define_attr("line_id_in_scale_line_vec", &cv::line_descriptor::BinaryDescriptor::OctaveLine::lineIDInScaleLineVec).
    define_attr("line_length", &cv::line_descriptor::BinaryDescriptor::OctaveLine::lineLength);
  
  Class rb_cCvLineDescriptorBinaryDescriptorSingleLine = define_class_under<cv::line_descriptor::BinaryDescriptor::SingleLine>(rb_cCvLineDescriptorBinaryDescriptor, "SingleLine").
    define_attr("rho", &cv::line_descriptor::BinaryDescriptor::SingleLine::rho).
    define_attr("theta", &cv::line_descriptor::BinaryDescriptor::SingleLine::theta).
    define_attr("line_point_x", &cv::line_descriptor::BinaryDescriptor::SingleLine::linePointX).
    define_attr("line_point_y", &cv::line_descriptor::BinaryDescriptor::SingleLine::linePointY).
    define_attr("start_point_x", &cv::line_descriptor::BinaryDescriptor::SingleLine::startPointX).
    define_attr("start_point_y", &cv::line_descriptor::BinaryDescriptor::SingleLine::startPointY).
    define_attr("end_point_x", &cv::line_descriptor::BinaryDescriptor::SingleLine::endPointX).
    define_attr("end_point_y", &cv::line_descriptor::BinaryDescriptor::SingleLine::endPointY).
    define_attr("direction", &cv::line_descriptor::BinaryDescriptor::SingleLine::direction).
    define_attr("gradient_magnitude", &cv::line_descriptor::BinaryDescriptor::SingleLine::gradientMagnitude).
    define_attr("dark_side_gray_value", &cv::line_descriptor::BinaryDescriptor::SingleLine::darkSideGrayValue).
    define_attr("light_side_gray_value", &cv::line_descriptor::BinaryDescriptor::SingleLine::lightSideGrayValue).
    define_attr("line_length", &cv::line_descriptor::BinaryDescriptor::SingleLine::lineLength).
    define_attr("width", &cv::line_descriptor::BinaryDescriptor::SingleLine::width).
    define_attr("num_of_pixels", &cv::line_descriptor::BinaryDescriptor::SingleLine::numOfPixels).
    define_attr("descriptor", &cv::line_descriptor::BinaryDescriptor::SingleLine::descriptor);
  
  Class rb_cCvLineDescriptorBinaryDescriptorOctaveSingleLine = define_class_under<cv::line_descriptor::BinaryDescriptor::OctaveSingleLine>(rb_cCvLineDescriptorBinaryDescriptor, "OctaveSingleLine").
    define_attr("start_point_x", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::startPointX).
    define_attr("start_point_y", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::startPointY).
    define_attr("end_point_x", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::endPointX).
    define_attr("end_point_y", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::endPointY).
    define_attr("s_point_in_octave_x", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::sPointInOctaveX).
    define_attr("s_point_in_octave_y", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::sPointInOctaveY).
    define_attr("e_point_in_octave_x", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::ePointInOctaveX).
    define_attr("e_point_in_octave_y", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::ePointInOctaveY).
    define_attr("direction", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::direction).
    define_attr("salience", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::salience).
    define_attr("line_length", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::lineLength).
    define_attr("num_of_pixels", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::numOfPixels).
    define_attr("octave_count", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::octaveCount).
    define_attr("descriptor", &cv::line_descriptor::BinaryDescriptor::OctaveSingleLine::descriptor).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor::OctaveSingleLine>());
  
  Class rb_cCvLineDescriptorBinaryDescriptorPixel = define_class_under<cv::line_descriptor::BinaryDescriptor::Pixel>(rb_cCvLineDescriptorBinaryDescriptor, "Pixel").
    define_attr("x", &cv::line_descriptor::BinaryDescriptor::Pixel::x).
    define_attr("y", &cv::line_descriptor::BinaryDescriptor::Pixel::y);
  
  Class rb_cCvLineDescriptorBinaryDescriptorEdgeChains = define_class_under<cv::line_descriptor::BinaryDescriptor::EdgeChains>(rb_cCvLineDescriptorBinaryDescriptor, "EdgeChains").
    define_attr("x_cors", &cv::line_descriptor::BinaryDescriptor::EdgeChains::xCors).
    define_attr("y_cors", &cv::line_descriptor::BinaryDescriptor::EdgeChains::yCors).
    define_attr("s_id", &cv::line_descriptor::BinaryDescriptor::EdgeChains::sId).
    define_attr("num_of_edges", &cv::line_descriptor::BinaryDescriptor::EdgeChains::numOfEdges);
  
  Class rb_cCvLineDescriptorBinaryDescriptorLineChains = define_class_under<cv::line_descriptor::BinaryDescriptor::LineChains>(rb_cCvLineDescriptorBinaryDescriptor, "LineChains").
    define_attr("x_cors", &cv::line_descriptor::BinaryDescriptor::LineChains::xCors).
    define_attr("y_cors", &cv::line_descriptor::BinaryDescriptor::LineChains::yCors).
    define_attr("s_id", &cv::line_descriptor::BinaryDescriptor::LineChains::sId).
    define_attr("num_of_lines", &cv::line_descriptor::BinaryDescriptor::LineChains::numOfLines);
  
  Class rb_cCvLineDescriptorBinaryDescriptorEDLineParam = define_class_under<cv::line_descriptor::BinaryDescriptor::EDLineParam>(rb_cCvLineDescriptorBinaryDescriptor, "EDLineParam").
    define_attr("ksize", &cv::line_descriptor::BinaryDescriptor::EDLineParam::ksize).
    define_attr("sigma", &cv::line_descriptor::BinaryDescriptor::EDLineParam::sigma).
    define_attr("gradient_threshold", &cv::line_descriptor::BinaryDescriptor::EDLineParam::gradientThreshold).
    define_attr("anchor_threshold", &cv::line_descriptor::BinaryDescriptor::EDLineParam::anchorThreshold).
    define_attr("scan_intervals", &cv::line_descriptor::BinaryDescriptor::EDLineParam::scanIntervals).
    define_attr("min_line_len", &cv::line_descriptor::BinaryDescriptor::EDLineParam::minLineLen).
    define_attr("line_fit_err_threshold", &cv::line_descriptor::BinaryDescriptor::EDLineParam::lineFitErrThreshold);
  
  Class rb_cCvLineDescriptorLSDParam = define_class_under<cv::line_descriptor::LSDParam>(rb_mCvLineDescriptor, "LSDParam").
    define_attr("scale", &cv::line_descriptor::LSDParam::scale).
    define_attr("sigma_scale", &cv::line_descriptor::LSDParam::sigma_scale).
    define_attr("quant", &cv::line_descriptor::LSDParam::quant).
    define_attr("ang_th", &cv::line_descriptor::LSDParam::ang_th).
    define_attr("log_eps", &cv::line_descriptor::LSDParam::log_eps).
    define_attr("density_th", &cv::line_descriptor::LSDParam::density_th).
    define_attr("n_bins", &cv::line_descriptor::LSDParam::n_bins).
    define_constructor(Constructor<cv::line_descriptor::LSDParam>());
  
  Class rb_cCvLineDescriptorLSDDetector = define_class_under<cv::line_descriptor::LSDDetector, cv::Algorithm>(rb_mCvLineDescriptor, "LSDDetector").
    define_constructor(Constructor<cv::line_descriptor::LSDDetector>()).
    define_constructor(Constructor<cv::line_descriptor::LSDDetector, cv::line_descriptor::LSDParam>()).
    define_singleton_function<cv::Ptr<cv::line_descriptor::LSDDetector>(*)()>("create_lsd_detector", &cv::line_descriptor::LSDDetector::createLSDDetector).
    define_singleton_function<cv::Ptr<cv::line_descriptor::LSDDetector>(*)(cv::line_descriptor::LSDParam)>("create_lsd_detector", &cv::line_descriptor::LSDDetector::createLSDDetector).
    define_method<void(cv::line_descriptor::LSDDetector::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, int, int, const cv::Mat&)>("detect", &cv::line_descriptor::LSDDetector::detect).
    define_method<void(cv::line_descriptor::LSDDetector::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, int, int, const std::vector<cv::Mat>&) const>("detect", &cv::line_descriptor::LSDDetector::detect);
  
  Class rb_cCvLineDescriptorBinaryDescriptorMatcher = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher, cv::Algorithm>(rb_mCvLineDescriptor, "BinaryDescriptorMatcher").
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<cv::DMatch>&, const cv::Mat&) const>("match", &cv::line_descriptor::BinaryDescriptorMatcher::match).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<cv::DMatch>&, const std::vector<cv::Mat>&)>("match", &cv::line_descriptor::BinaryDescriptorMatcher::match).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, int, const cv::Mat&, bool) const>("knn_match", &cv::line_descriptor::BinaryDescriptorMatcher::knnMatch).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, int, const std::vector<cv::Mat>&, bool)>("knn_match", &cv::line_descriptor::BinaryDescriptorMatcher::knnMatch).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, float, const cv::Mat&, bool) const>("radius_match", &cv::line_descriptor::BinaryDescriptorMatcher::radiusMatch).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, float, const std::vector<cv::Mat>&, bool)>("radius_match", &cv::line_descriptor::BinaryDescriptorMatcher::radiusMatch).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const std::vector<cv::Mat>&)>("add", &cv::line_descriptor::BinaryDescriptorMatcher::add).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)()>("train", &cv::line_descriptor::BinaryDescriptorMatcher::train).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher>(*)()>("create_binary_descriptor_matcher", &cv::line_descriptor::BinaryDescriptorMatcher::createBinaryDescriptorMatcher).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)()>("clear", &cv::line_descriptor::BinaryDescriptorMatcher::clear).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher>());
  
  Class rb_cCvLineDescriptorBinaryDescriptorMatcherBucketGroup = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup>(rb_cCvLineDescriptorBinaryDescriptorMatcher, "BucketGroup").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup, bool>()).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::*)(int, unsigned int)>("insert", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::insert).
    define_method<unsigned int*(cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::*)(int, int*)>("query", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::query).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::*)(std::vector<unsigned int>&, int, unsigned int)>("insert_value", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::insert_value).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::*)(std::vector<unsigned int>&, unsigned int)>("push_value", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::push_value).
    define_attr("empty", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::empty).
    define_attr("group", &cv::line_descriptor::BinaryDescriptorMatcher::BucketGroup::group);
  
  Class rb_cCvLineDescriptorBinaryDescriptorMatcherSparseHashtable = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable>(rb_cCvLineDescriptorBinaryDescriptorMatcher, "SparseHashtable").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable>()).
    define_method<int(cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::*)(int)>("init", &cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::init).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::*)(unsigned long long, unsigned int)>("insert", &cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::insert).
    define_method<unsigned int*(cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::*)(unsigned long long, int*)>("query", &cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::query).
    define_attr("b", &cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::b).
    define_attr("size", &cv::line_descriptor::BinaryDescriptorMatcher::SparseHashtable::size);
  
  Class rb_cCvLineDescriptorBinaryDescriptorMatcherBitarray = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher::bitarray>(rb_cCvLineDescriptorBinaryDescriptorMatcher, "Bitarray").
    define_attr("arr", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::arr).
    define_attr("length", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::length).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::bitarray>()).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::bitarray, unsigned long long>()).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::bitarray::*)(unsigned long long)>("init", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::init).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::bitarray::*)(unsigned long long)>("flip", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::flip).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::bitarray::*)(unsigned long long)>("set", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::set).
    define_method<unsigned char(cv::line_descriptor::BinaryDescriptorMatcher::bitarray::*)(unsigned long long)>("get", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::get).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::bitarray::*)()>("erase", &cv::line_descriptor::BinaryDescriptorMatcher::bitarray::erase);
  
  Class rb_cCvLineDescriptorBinaryDescriptorMatcherMihasher = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher::Mihasher>(rb_cCvLineDescriptorBinaryDescriptorMatcher, "Mihasher").
    define_attr("b", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::B).
    define_attr("b_over_8", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::B_over_8).
    define_attr("b", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::b).
    define_attr("m", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::m).
    define_attr("mplus", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::mplus).
    define_attr("d", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::D).
    define_attr("d", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::d).
    define_attr("k", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::K).
    define_attr("n", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::N).
    define_attr("codes", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::codes).
    define_attr("counter", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::counter).
    define_attr("h", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::H).
    define_attr("xornum", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::xornum).
    define_attr("power", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::power).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::Mihasher>()).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher::Mihasher, int, int>()).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::*)(int)>("set_k", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::setK).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::*)(cv::Mat&, unsigned int, int)>("populate", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::populate).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::*)(unsigned int*, unsigned int*, const cv::Mat&, unsigned int, int)>("batchquery", &cv::line_descriptor::BinaryDescriptorMatcher::Mihasher::batchquery);
  
  Class rb_cCvLineDescriptorDrawLinesMatchesFlags = define_class_under<cv::line_descriptor::DrawLinesMatchesFlags>(rb_mCvLineDescriptor, "DrawLinesMatchesFlags");
  
  
  
  rb_mCvLineDescriptor.define_module_function<void(*)(const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, const std::vector<cv::DMatch>&, cv::Mat&, const cv::Scalar_<double>&, const cv::Scalar_<double>&, const std::vector<char>&, int)>("draw_line_matches", &cv::line_descriptor::drawLineMatches);
  
  rb_mCvLineDescriptor.define_module_function<void(*)(const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, cv::Mat&, const cv::Scalar_<double>&, int)>("draw_keylines", &cv::line_descriptor::drawKeylines);
}