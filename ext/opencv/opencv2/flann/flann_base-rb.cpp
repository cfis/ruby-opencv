#include <opencv2/flann/flann_base.hpp>
#include "flann_base-rb.hpp"

using namespace Rice;

extern "C"
void Init_FlannBase()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  Class rb_cCvflannFILEScopeGuard = define_class_under<cvflann::FILEScopeGuard>(rb_mCvflann, "FILEScopeGuard").
    define_constructor(Constructor<cvflann::FILEScopeGuard, _iobuf*>());
  
  rb_mCvflann.define_module_function<void(*)(int)>("log_verbosity", &cvflann::log_verbosity);
  
  Class rb_cCvflannSavedIndexParams = define_class_under<cvflann::SavedIndexParams, cvflann::IndexParams>(rb_mCvflann, "SavedIndexParams").
    define_constructor(Constructor<cvflann::SavedIndexParams, std::basic_string<char>>());
}