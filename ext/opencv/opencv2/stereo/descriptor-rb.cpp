#include <opencv2/stereo/descriptor.hpp>
#include "descriptor-rb.hpp"

using namespace Rice;

extern "C"
void Init_Descriptor()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStereo = define_module_under(rb_mCv, "Stereo");
  
  rb_mCvStereo.define_module_function<int(*)(const int&, const int&, int, int&, int&, const int)>("census_transform", &cv::stereo::censusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, int, int&, const int)>("census_transform", &cv::stereo::censusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, const int&, int, int&, int&, const int, int, const int&, const int&)>("modified_census_transform", &cv::stereo::modifiedCensusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, int, int&, const int, int, const int&)>("modified_census_transform", &cv::stereo::modifiedCensusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, const int&, int, int&, int&, const int)>("symetric_census_transform", &cv::stereo::symetricCensusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, int, int&, const int)>("symetric_census_transform", &cv::stereo::symetricCensusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, const int&, int, int&, int&)>("star_census_transform", &cv::stereo::starCensusTransform);
  
  rb_mCvStereo.define_module_function<int(*)(const int&, int, int&)>("star_census_transform", &cv::stereo::starCensusTransform);
}