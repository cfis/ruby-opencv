#include <opencv2/phase_unwrapping/histogramphaseunwrapping.hpp>
#include "histogramphaseunwrapping-rb.hpp"

using namespace Rice;

extern "C"
void Init_Histogramphaseunwrapping()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPhaseUnwrapping = define_module_under(rb_mCv, "PhaseUnwrapping");
  
  Class rb_cCvPhaseUnwrappingHistogramPhaseUnwrapping = define_class_under<cv::phase_unwrapping::HistogramPhaseUnwrapping, cv::phase_unwrapping::PhaseUnwrapping>(rb_mCvPhaseUnwrapping, "HistogramPhaseUnwrapping").
    define_singleton_function<cv::Ptr<cv::phase_unwrapping::HistogramPhaseUnwrapping>(*)(const cv::phase_unwrapping::HistogramPhaseUnwrapping::Params&)>("create", &cv::phase_unwrapping::HistogramPhaseUnwrapping::create).
    define_method<void(cv::phase_unwrapping::HistogramPhaseUnwrapping::*)(const cv::_OutputArray &)>("get_inverse_reliability_map", &cv::phase_unwrapping::HistogramPhaseUnwrapping::getInverseReliabilityMap);
  
  Class rb_cCvPhaseUnwrappingHistogramPhaseUnwrappingParams = define_class_under<cv::phase_unwrapping::HistogramPhaseUnwrapping::Params>(rb_cCvPhaseUnwrappingHistogramPhaseUnwrapping, "Params").
    define_constructor(Constructor<cv::phase_unwrapping::HistogramPhaseUnwrapping::Params>()).
    define_attr("width", &cv::phase_unwrapping::HistogramPhaseUnwrapping::Params::width).
    define_attr("height", &cv::phase_unwrapping::HistogramPhaseUnwrapping::Params::height).
    define_attr("hist_thresh", &cv::phase_unwrapping::HistogramPhaseUnwrapping::Params::histThresh).
    define_attr("nbr_of_small_bins", &cv::phase_unwrapping::HistogramPhaseUnwrapping::Params::nbrOfSmallBins).
    define_attr("nbr_of_large_bins", &cv::phase_unwrapping::HistogramPhaseUnwrapping::Params::nbrOfLargeBins);
}