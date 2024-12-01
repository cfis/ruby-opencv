#include <opencv2/bioinspired/retina.hpp>
#include "retina-rb.hpp"

using namespace Rice;

extern "C"
void Init_Retina()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBioinspired = define_module_under(rb_mCv, "Bioinspired");
  
  Class rb_cCvBioinspiredRetinaParameters = define_class_under<cv::bioinspired::RetinaParameters>(rb_mCvBioinspired, "RetinaParameters").
    define_attr("op_land_ipl_parvo", &cv::bioinspired::RetinaParameters::OPLandIplParvo).
    define_attr("ipl_magno", &cv::bioinspired::RetinaParameters::IplMagno);
  
  Class rb_cCvBioinspiredRetinaParametersOPLandIplParvoParameters = define_class_under<cv::bioinspired::RetinaParameters::OPLandIplParvoParameters>(rb_cCvBioinspiredRetinaParameters, "OPLandIplParvoParameters").
    define_constructor(Constructor<cv::bioinspired::RetinaParameters::OPLandIplParvoParameters>()).
    define_attr("color_mode", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::colorMode).
    define_attr("normalise_output", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::normaliseOutput).
    define_attr("photoreceptors_local_adaptation_sensitivity", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsLocalAdaptationSensitivity).
    define_attr("photoreceptors_temporal_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsTemporalConstant).
    define_attr("photoreceptors_spatial_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::photoreceptorsSpatialConstant).
    define_attr("horizontal_cells_gain", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::horizontalCellsGain).
    define_attr("hcells_temporal_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::hcellsTemporalConstant).
    define_attr("hcells_spatial_constant", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::hcellsSpatialConstant).
    define_attr("ganglion_cells_sensitivity", &cv::bioinspired::RetinaParameters::OPLandIplParvoParameters::ganglionCellsSensitivity);
  
  Class rb_cCvBioinspiredRetinaParametersIplMagnoParameters = define_class_under<cv::bioinspired::RetinaParameters::IplMagnoParameters>(rb_cCvBioinspiredRetinaParameters, "IplMagnoParameters").
    define_constructor(Constructor<cv::bioinspired::RetinaParameters::IplMagnoParameters>()).
    define_attr("normalise_output", &cv::bioinspired::RetinaParameters::IplMagnoParameters::normaliseOutput).
    define_attr("parasol_cells_beta", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_beta).
    define_attr("parasol_cells_tau", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_tau).
    define_attr("parasol_cells_k", &cv::bioinspired::RetinaParameters::IplMagnoParameters::parasolCells_k).
    define_attr("amacrin_cells_temporal_cut_frequency", &cv::bioinspired::RetinaParameters::IplMagnoParameters::amacrinCellsTemporalCutFrequency).
    define_attr("v0_compression_parameter", &cv::bioinspired::RetinaParameters::IplMagnoParameters::V0CompressionParameter).
    define_attr("local_adaptintegration_tau", &cv::bioinspired::RetinaParameters::IplMagnoParameters::localAdaptintegration_tau).
    define_attr("local_adaptintegration_k", &cv::bioinspired::RetinaParameters::IplMagnoParameters::localAdaptintegration_k);
  
  Class rb_cCvBioinspiredRetina = define_class_under<cv::bioinspired::Retina, cv::Algorithm>(rb_mCvBioinspired, "Retina").
    define_method<cv::Size_<int>(cv::bioinspired::Retina::*)()>("get_input_size", &cv::bioinspired::Retina::getInputSize).
    define_method<cv::Size_<int>(cv::bioinspired::Retina::*)()>("get_output_size", &cv::bioinspired::Retina::getOutputSize).
    define_method<void(cv::bioinspired::Retina::*)(std::basic_string<char>, const bool)>("setup", &cv::bioinspired::Retina::setup).
    define_method<void(cv::bioinspired::Retina::*)(cv::FileStorage&, const bool)>("setup", &cv::bioinspired::Retina::setup).
    define_method<void(cv::bioinspired::Retina::*)(cv::bioinspired::RetinaParameters)>("setup", &cv::bioinspired::Retina::setup).
    define_method<cv::bioinspired::RetinaParameters(cv::bioinspired::Retina::*)()>("get_parameters", &cv::bioinspired::Retina::getParameters).
    define_method<std::basic_string<char>(cv::bioinspired::Retina::*)()>("print_setup", &cv::bioinspired::Retina::printSetup).
    define_method<void(cv::bioinspired::Retina::*)(std::basic_string<char>) const>("write", &cv::bioinspired::Retina::write).
    define_method<void(cv::bioinspired::Retina::*)(cv::FileStorage&) const>("write", &cv::bioinspired::Retina::write).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const bool, const float, const float, const float, const float, const float, const float, const float)>("setup_op_land_ipl_parvo_channel", &cv::bioinspired::Retina::setupOPLandIPLParvoChannel).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const float, const float, const float, const float, const float, const float, const float)>("setup_ipl_magno_channel", &cv::bioinspired::Retina::setupIPLMagnoChannel).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_InputArray &)>("run", &cv::bioinspired::Retina::run).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_InputArray &, const cv::_OutputArray &)>("apply_fast_tone_mapping", &cv::bioinspired::Retina::applyFastToneMapping).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_OutputArray &)>("get_parvo", &cv::bioinspired::Retina::getParvo).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_OutputArray &)>("get_parvo_raw", &cv::bioinspired::Retina::getParvoRAW).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_OutputArray &)>("get_magno", &cv::bioinspired::Retina::getMagno).
    define_method<void(cv::bioinspired::Retina::*)(const cv::_OutputArray &)>("get_magno_raw", &cv::bioinspired::Retina::getMagnoRAW).
    define_method<cv::Mat(cv::bioinspired::Retina::*)() const>("get_magno_raw", &cv::bioinspired::Retina::getMagnoRAW).
    define_method<cv::Mat(cv::bioinspired::Retina::*)() const>("get_parvo_raw", &cv::bioinspired::Retina::getParvoRAW).
    define_method<void(cv::bioinspired::Retina::*)(const bool, const float)>("set_color_saturation", &cv::bioinspired::Retina::setColorSaturation).
    define_method<void(cv::bioinspired::Retina::*)()>("clear_buffers", &cv::bioinspired::Retina::clearBuffers).
    define_method<void(cv::bioinspired::Retina::*)(const bool)>("activate_moving_contours_processing", &cv::bioinspired::Retina::activateMovingContoursProcessing).
    define_method<void(cv::bioinspired::Retina::*)(const bool)>("activate_contours_processing", &cv::bioinspired::Retina::activateContoursProcessing).
    define_singleton_function<cv::Ptr<cv::bioinspired::Retina>(*)(cv::Size_<int>)>("create", &cv::bioinspired::Retina::create).
    define_singleton_function<cv::Ptr<cv::bioinspired::Retina>(*)(cv::Size_<int>, const bool, int, const bool, const float, const float)>("create", &cv::bioinspired::Retina::create);
}