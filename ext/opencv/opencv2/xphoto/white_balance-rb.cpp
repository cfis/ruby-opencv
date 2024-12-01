#include <opencv2/xphoto/white_balance.hpp>
#include "white_balance-rb.hpp"

using namespace Rice;

extern "C"
void Init_WhiteBalance()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXphoto = define_module_under(rb_mCv, "Xphoto");
  
  Class rb_cCvXphotoWhiteBalancer = define_class_under<cv::xphoto::WhiteBalancer, cv::Algorithm>(rb_mCvXphoto, "WhiteBalancer").
    define_method<void(cv::xphoto::WhiteBalancer::*)(const cv::_InputArray &, const cv::_OutputArray &)>("balance_white", &cv::xphoto::WhiteBalancer::balanceWhite);
  
  Class rb_cCvXphotoSimpleWB = define_class_under<cv::xphoto::SimpleWB, cv::xphoto::WhiteBalancer>(rb_mCvXphoto, "SimpleWB").
    define_method<float(cv::xphoto::SimpleWB::*)() const>("get_input_min", &cv::xphoto::SimpleWB::getInputMin).
    define_method<void(cv::xphoto::SimpleWB::*)(float)>("set_input_min", &cv::xphoto::SimpleWB::setInputMin).
    define_method<float(cv::xphoto::SimpleWB::*)() const>("get_input_max", &cv::xphoto::SimpleWB::getInputMax).
    define_method<void(cv::xphoto::SimpleWB::*)(float)>("set_input_max", &cv::xphoto::SimpleWB::setInputMax).
    define_method<float(cv::xphoto::SimpleWB::*)() const>("get_output_min", &cv::xphoto::SimpleWB::getOutputMin).
    define_method<void(cv::xphoto::SimpleWB::*)(float)>("set_output_min", &cv::xphoto::SimpleWB::setOutputMin).
    define_method<float(cv::xphoto::SimpleWB::*)() const>("get_output_max", &cv::xphoto::SimpleWB::getOutputMax).
    define_method<void(cv::xphoto::SimpleWB::*)(float)>("set_output_max", &cv::xphoto::SimpleWB::setOutputMax).
    define_method<float(cv::xphoto::SimpleWB::*)() const>("get_p", &cv::xphoto::SimpleWB::getP).
    define_method<void(cv::xphoto::SimpleWB::*)(float)>("set_p", &cv::xphoto::SimpleWB::setP);
  
  rb_mCvXphoto.define_module_function<cv::Ptr<cv::xphoto::SimpleWB>(*)()>("create_simple_wb", &cv::xphoto::createSimpleWB);
  
  Class rb_cCvXphotoGrayworldWB = define_class_under<cv::xphoto::GrayworldWB, cv::xphoto::WhiteBalancer>(rb_mCvXphoto, "GrayworldWB").
    define_method<float(cv::xphoto::GrayworldWB::*)() const>("get_saturation_threshold", &cv::xphoto::GrayworldWB::getSaturationThreshold).
    define_method<void(cv::xphoto::GrayworldWB::*)(float)>("set_saturation_threshold", &cv::xphoto::GrayworldWB::setSaturationThreshold);
  
  rb_mCvXphoto.define_module_function<cv::Ptr<cv::xphoto::GrayworldWB>(*)()>("create_grayworld_wb", &cv::xphoto::createGrayworldWB);
  
  Class rb_cCvXphotoLearningBasedWB = define_class_under<cv::xphoto::LearningBasedWB, cv::xphoto::WhiteBalancer>(rb_mCvXphoto, "LearningBasedWB").
    define_method<void(cv::xphoto::LearningBasedWB::*)(const cv::_InputArray &, const cv::_OutputArray &)>("extract_simple_features", &cv::xphoto::LearningBasedWB::extractSimpleFeatures).
    define_method<int(cv::xphoto::LearningBasedWB::*)() const>("get_range_max_val", &cv::xphoto::LearningBasedWB::getRangeMaxVal).
    define_method<void(cv::xphoto::LearningBasedWB::*)(int)>("set_range_max_val", &cv::xphoto::LearningBasedWB::setRangeMaxVal).
    define_method<float(cv::xphoto::LearningBasedWB::*)() const>("get_saturation_threshold", &cv::xphoto::LearningBasedWB::getSaturationThreshold).
    define_method<void(cv::xphoto::LearningBasedWB::*)(float)>("set_saturation_threshold", &cv::xphoto::LearningBasedWB::setSaturationThreshold).
    define_method<int(cv::xphoto::LearningBasedWB::*)() const>("get_hist_bin_num", &cv::xphoto::LearningBasedWB::getHistBinNum).
    define_method<void(cv::xphoto::LearningBasedWB::*)(int)>("set_hist_bin_num", &cv::xphoto::LearningBasedWB::setHistBinNum);
  
  rb_mCvXphoto.define_module_function<cv::Ptr<cv::xphoto::LearningBasedWB>(*)(const std::basic_string<char>&)>("create_learning_based_wb", &cv::xphoto::createLearningBasedWB);
  
  rb_mCvXphoto.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, float)>("apply_channel_gains", &cv::xphoto::applyChannelGains);
}