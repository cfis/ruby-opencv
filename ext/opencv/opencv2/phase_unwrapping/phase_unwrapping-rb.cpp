#include <opencv2/phase_unwrapping/phase_unwrapping.hpp>
#include "phase_unwrapping-rb.hpp"

using namespace Rice;

extern "C"
void Init_PhaseUnwrapping()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPhaseUnwrapping = define_module_under(rb_mCv, "PhaseUnwrapping");
  
  Class rb_cCvPhaseUnwrappingPhaseUnwrapping = define_class_under<cv::phase_unwrapping::PhaseUnwrapping, cv::Algorithm>(rb_mCvPhaseUnwrapping, "PhaseUnwrapping").
    define_method<void(cv::phase_unwrapping::PhaseUnwrapping::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("unwrap_phase_map", &cv::phase_unwrapping::PhaseUnwrapping::unwrapPhaseMap);
}