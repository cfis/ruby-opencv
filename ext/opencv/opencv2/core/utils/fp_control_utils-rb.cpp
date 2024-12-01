#include <opencv2/core/utils/fp_control_utils.hpp>
#include "fp_control_utils-rb.hpp"

using namespace Rice;

extern "C"
void Init_FpControlUtils()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
  
  Class rb_cCvDetailsFPDenormalsModeState = define_class_under<cv::details::FPDenormalsModeState>(rb_mCvDetails, "FPDenormalsModeState").
    define_attr("reserved", &cv::details::FPDenormalsModeState::reserved);
  
  rb_mCvDetails.define_module_function<void(*)(bool, cv::details::FPDenormalsModeState&)>("set_fp_denormals_ignore_hint", &cv::details::setFPDenormalsIgnoreHint);
  
  rb_mCvDetails.define_module_function<int(*)(cv::details::FPDenormalsModeState&)>("save_fp_denormals_state", &cv::details::saveFPDenormalsState);
  
  rb_mCvDetails.define_module_function<bool(*)(const cv::details::FPDenormalsModeState&)>("restore_fp_denormals_state", &cv::details::restoreFPDenormalsState);
  
  Class rb_cCvDetailsFPDenormalsIgnoreHintScope = define_class_under<cv::details::FPDenormalsIgnoreHintScope>(rb_mCvDetails, "FPDenormalsIgnoreHintScope").
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScope, bool>()).
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScope, const cv::details::FPDenormalsModeState&>());
  
  Class rb_cCvDetailsFPDenormalsIgnoreHintScopeNOOP = define_class_under<cv::details::FPDenormalsIgnoreHintScopeNOOP>(rb_mCvDetails, "FPDenormalsIgnoreHintScopeNOOP").
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScopeNOOP, bool>()).
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScopeNOOP, const cv::details::FPDenormalsModeState&>());
}