#include <opencv2/tracking/feature.hpp>
#include "feature-rb.hpp"

using namespace Rice;

extern "C"
void Init_Feature()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Module rb_mCvDetailTrackingContribFeature = define_module_under(rb_mCvDetailTracking, "ContribFeature");
  
  rb_mCvDetailTrackingContribFeature.define_module_function<float(*)(const cv::Mat&, const cv::Mat&)>("calc_norm_factor", &cv::detail::tracking::contrib_feature::calcNormFactor);
  
  Class rb_cCvDetailCvParams = define_class_under<cv::detail::CvParams>(rb_mCvDetailTrackingContribFeature, "CvParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvParams>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvParams::write).
    define_method<bool(cv::detail::tracking::contrib_feature::CvParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvParams::read).
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)() const>("print_defaults", &cv::detail::tracking::contrib_feature::CvParams::printDefaults).
    define_method<void(cv::detail::tracking::contrib_feature::CvParams::*)() const>("print_attrs", &cv::detail::tracking::contrib_feature::CvParams::printAttrs).
    define_method<bool(cv::detail::tracking::contrib_feature::CvParams::*)(const std::basic_string<char>, const std::basic_string<char>)>("scan_attr", &cv::detail::tracking::contrib_feature::CvParams::scanAttr).
    define_attr("name", &cv::detail::tracking::contrib_feature::CvParams::name);
  
  Class rb_cCvDetailCvFeatureParams = define_class_under<cv::detail::CvFeatureParams, cv::detail::CvParams>(rb_mCvDetailTrackingContribFeature, "CvFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvFeatureParams>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(const cv::detail::CvFeatureParams&)>("init", &cv::detail::tracking::contrib_feature::CvFeatureParams::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvFeatureParams::write).
    define_method<bool(cv::detail::tracking::contrib_feature::CvFeatureParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvFeatureParams::read).
    define_singleton_function<cv::Ptr<cv::detail::CvFeatureParams>(*)(cv::detail::CvFeatureParams::FeatureType)>("create", &cv::detail::tracking::contrib_feature::CvFeatureParams::create).
    define_attr("max_cat_count", &cv::detail::tracking::contrib_feature::CvFeatureParams::maxCatCount).
    define_attr("feat_size", &cv::detail::tracking::contrib_feature::CvFeatureParams::featSize).
    define_attr("num_features", &cv::detail::tracking::contrib_feature::CvFeatureParams::numFeatures);
  
  Enum<cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType> rb_cCvDetailCvFeatureParamsFeatureType = define_enum<cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType>("FeatureType", rb_cCvDetailCvFeatureParams).
    define_value("HAAR", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::HAAR).
    define_value("LBP", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::LBP).
    define_value("HOG", cv::detail::tracking::contrib_feature::CvFeatureParams::FeatureType::HOG);
  
  Class rb_cCvDetailCvFeatureEvaluator = define_class_under<cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvFeatureEvaluator").
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(const cv::detail::CvFeatureParams*, int, cv::Size_<int>)>("init", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(const cv::Mat&, unsigned char, int)>("set_image", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::setImage).
    define_method<void(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::writeFeatures).
    define_method<float(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(int, int)>("operator()", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::operator()).
    define_singleton_function<cv::Ptr<cv::detail::CvFeatureEvaluator>(*)(cv::detail::CvFeatureParams::FeatureType)>("create", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::create).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_num_features", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getNumFeatures).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_max_cat_count", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getMaxCatCount).
    define_method<int(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_feature_size", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getFeatureSize).
    define_method<const cv::Mat&(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)() const>("get_cls", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getCls).
    define_method<float(cv::detail::tracking::contrib_feature::CvFeatureEvaluator::*)(int) const>("get_cls", &cv::detail::tracking::contrib_feature::CvFeatureEvaluator::getCls);
  
  Class rb_cCvDetailCvHaarFeatureParams = define_class_under<cv::detail::CvHaarFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvHaarFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHaarFeatureParams>()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const cv::detail::CvFeatureParams&)>("init", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::write).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const cv::FileNode&)>("read", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::read).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)() const>("print_defaults", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::printDefaults).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)() const>("print_attrs", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::printAttrs).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarFeatureParams::*)(const std::basic_string<char>, const std::basic_string<char>)>("scan_attr", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::scanAttr).
    define_attr("is_integral", &cv::detail::tracking::contrib_feature::CvHaarFeatureParams::isIntegral);
  
  Class rb_cCvDetailCvHaarEvaluator = define_class_under<cv::detail::CvHaarEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvHaarEvaluator").
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(const cv::detail::CvFeatureParams*, int, cv::Size_<int>)>("init", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(const cv::Mat&, unsigned char, int)>("set_image", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setImage).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int, int)>("operator()", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::operator()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::writeFeatures).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::FileStorage&) const>("write_feature", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::writeFeature).
    define_method<const std::vector<cv::detail::CvHaarEvaluator::FeatureHaar>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)() const>("get_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::getFeatures).
    define_method<cv::detail::CvHaarEvaluator::FeatureHaar&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int)>("get_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::getFeatures).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(cv::Size_<int>)>("set_win_size", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setWinSize).
    define_method<cv::Size_<int>(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)() const>("set_win_size", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::setWinSize).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)()>("generate_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::generateFeatures).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::*)(int)>("generate_features", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::generateFeatures);
  
  Class rb_cCvDetailCvHaarEvaluatorFeatureHaar = define_class_under<cv::detail::CvHaarEvaluator::FeatureHaar>(rb_cCvDetailCvHaarEvaluator, "FeatureHaar").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar, cv::Size_<int>>()).
    define_method<bool(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)(const cv::Mat&, cv::Rect_<int>, float*) const>("eval", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::eval).
    define_method<int(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)()>("get_num_areas", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getNumAreas).
    define_method<const std::vector<float>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_weights", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getWeights).
    define_method<const std::vector<cv::Rect_<int>>&(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_areas", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getAreas).
    define_method<void(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)(cv::FileStorage) const>("write", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::write).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_init_mean", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getInitMean).
    define_method<float(cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::*)() const>("get_init_sigma", &cv::detail::tracking::contrib_feature::CvHaarEvaluator::FeatureHaar::getInitSigma);
  
  Class rb_cCvDetailCvHOGFeatureParams = define_class_under<cv::detail::CvHOGFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvHOGFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHOGFeatureParams>());
  
  Class rb_cCvDetailCvHOGEvaluator = define_class_under<cv::detail::CvHOGEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvHOGEvaluator").
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(const cv::detail::CvFeatureParams*, int, cv::Size_<int>)>("init", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(const cv::Mat&, unsigned char, int)>("set_image", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::setImage).
    define_method<float(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(int, int)>("operator()", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::operator()).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::writeFeatures);
  
  Class rb_cCvDetailCvHOGEvaluatorFeature = define_class_under<cv::detail::CvHOGEvaluator::Feature>(rb_cCvDetailCvHOGEvaluator, "Feature").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature>()).
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature, int, int, int, int, int>()).
    define_method<float(cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::*)(const std::vector<cv::Mat>&, const cv::Mat&, unsigned long long, int) const>("calc", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::calc).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::write).
    define_method<void(cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::*)(cv::FileStorage&, int) const>("write", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::write).
    define_attr("rect", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::rect).
    define_attr("fast_rect", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::fastRect);
  
  Class rb_cCvDetailCvHOGEvaluatorFeature(unnamed struct at C:\Source\vcpkg\installed\x64Windows\include\opencv2\tracking\featureHpp:325:5) = define_class_under<cv::detail::CvHOGEvaluator::Feature::(unnamed struct at C:\Source\vcpkg\installed\x64-windows\include\opencv2\tracking\feature.hpp:325:5)>(rb_cCvDetailCvHOGEvaluatorFeature, "(unnamed struct at C:\Source\vcpkg\installed\x64Windows\include\opencv2\tracking\featureHpp:325:5)").
    define_attr("p0", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::(unnamed struct at C:\Source\vcpkg\installed\x64-windows\include\opencv2\tracking\feature.hpp:325:5)::p0).
    define_attr("p1", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::(unnamed struct at C:\Source\vcpkg\installed\x64-windows\include\opencv2\tracking\feature.hpp:325:5)::p1).
    define_attr("p2", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::(unnamed struct at C:\Source\vcpkg\installed\x64-windows\include\opencv2\tracking\feature.hpp:325:5)::p2).
    define_attr("p3", &cv::detail::tracking::contrib_feature::CvHOGEvaluator::Feature::(unnamed struct at C:\Source\vcpkg\installed\x64-windows\include\opencv2\tracking\feature.hpp:325:5)::p3);
  
  Class rb_cCvDetailCvLBPFeatureParams = define_class_under<cv::detail::CvLBPFeatureParams, cv::detail::CvFeatureParams>(rb_mCvDetailTrackingContribFeature, "CvLBPFeatureParams").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvLBPFeatureParams>());
  
  Class rb_cCvDetailCvLBPEvaluator = define_class_under<cv::detail::CvLBPEvaluator, cv::detail::CvFeatureEvaluator>(rb_mCvDetailTrackingContribFeature, "CvLBPEvaluator").
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(const cv::detail::CvFeatureParams*, int, cv::Size_<int>)>("init", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::init).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(const cv::Mat&, unsigned char, int)>("set_image", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::setImage).
    define_method<float(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(int, int)>("operator()", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::operator()).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::*)(cv::FileStorage&, const cv::Mat&) const>("write_features", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::writeFeatures);
  
  Class rb_cCvDetailCvLBPEvaluatorFeature = define_class_under<cv::detail::CvLBPEvaluator::Feature>(rb_cCvDetailCvLBPEvaluator, "Feature").
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature>()).
    define_constructor(Constructor<cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature, int, int, int, int, int>()).
    define_method<unsigned char(cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::*)(const cv::Mat&, unsigned long long) const>("calc", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::calc).
    define_method<void(cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::*)(cv::FileStorage&) const>("write", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::write).
    define_attr("rect", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::rect).
    define_attr("p", &cv::detail::tracking::contrib_feature::CvLBPEvaluator::Feature::p);
}