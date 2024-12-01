#include <opencv2/bioinspired/transientareassegmentationmodule.hpp>
#include "transientareassegmentationmodule-rb.hpp"

using namespace Rice;

extern "C"
void Init_Transientareassegmentationmodule()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");
  
  Class rb_cCvBioinspiredSegmentationParameters = define_class_under<cv::bioinspired::SegmentationParameters>(rb_mCvBioinspired, "SegmentationParameters").
    define_constructor(Constructor<cv::bioinspired::SegmentationParameters>()).
    define_attr("threshold_on", &cv::bioinspired::SegmentationParameters::thresholdON).
    define_attr("threshold_off", &cv::bioinspired::SegmentationParameters::thresholdOFF).
    define_attr("local_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::localEnergy_temporalConstant).
    define_attr("local_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::localEnergy_spatialConstant).
    define_attr("neighborhood_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::neighborhoodEnergy_temporalConstant).
    define_attr("neighborhood_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::neighborhoodEnergy_spatialConstant).
    define_attr("context_energy_temporal_constant", &cv::bioinspired::SegmentationParameters::contextEnergy_temporalConstant).
    define_attr("context_energy_spatial_constant", &cv::bioinspired::SegmentationParameters::contextEnergy_spatialConstant);
  
  Class rb_cCvBioinspiredTransientAreasSegmentationModule = define_class_under<cv::bioinspired::TransientAreasSegmentationModule, cv::Algorithm>(rb_mCvBioinspired, "TransientAreasSegmentationModule").
    define_method<cv::Size_<int>(cv::bioinspired::TransientAreasSegmentationModule::*)()>("get_size", &cv::bioinspired::TransientAreasSegmentationModule::getSize).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(std::basic_string<char>, const bool)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::FileStorage&, const bool)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::bioinspired::SegmentationParameters)>("setup", &cv::bioinspired::TransientAreasSegmentationModule::setup).
    define_method<cv::bioinspired::SegmentationParameters(cv::bioinspired::TransientAreasSegmentationModule::*)()>("get_parameters", &cv::bioinspired::TransientAreasSegmentationModule::getParameters).
    define_method<std::basic_string<char>(cv::bioinspired::TransientAreasSegmentationModule::*)()>("print_setup", &cv::bioinspired::TransientAreasSegmentationModule::printSetup).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(std::basic_string<char>) const>("write", &cv::bioinspired::TransientAreasSegmentationModule::write).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(cv::FileStorage&) const>("write", &cv::bioinspired::TransientAreasSegmentationModule::write).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(const cv::_InputArray &, const int)>("run", &cv::bioinspired::TransientAreasSegmentationModule::run).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)(const cv::_OutputArray &)>("get_segmentation_picture", &cv::bioinspired::TransientAreasSegmentationModule::getSegmentationPicture).
    define_method<void(cv::bioinspired::TransientAreasSegmentationModule::*)()>("clear_all_buffers", &cv::bioinspired::TransientAreasSegmentationModule::clearAllBuffers).
    define_singleton_function<cv::Ptr<cv::bioinspired::TransientAreasSegmentationModule>(*)(cv::Size_<int>)>("create", &cv::bioinspired::TransientAreasSegmentationModule::create);
}