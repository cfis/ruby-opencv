#include <opencv2/flann.hpp>
#include "flann-rb.hpp"

using namespace Rice;

extern "C"
void Init_Flann()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_mCvflann.define_module_function<cvflann::flann_distance_t(*)()>("flann_distance_type", &cvflann::flann_distance_type);
  
  rb_mCvflann.define_module_function<void(*)(cvflann::flann_distance_t, int)>("set_distance_type", &cvflann::set_distance_type);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFlann = define_module_under(rb_mCv, "Flann");
  
  Class rb_cCvFlannCvTypeUnsigned char = define_class_under<cv::flann::CvType<unsigned char>>(rb_mCvFlann, "CvTypeUnsigned char").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeChar = define_class_under<cv::flann::CvType<char>>(rb_mCvFlann, "CvTypeChar").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeUnsigned short = define_class_under<cv::flann::CvType<unsigned short>>(rb_mCvFlann, "CvTypeUnsigned short").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeShort = define_class_under<cv::flann::CvType<short>>(rb_mCvFlann, "CvTypeShort").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeInt = define_class_under<cv::flann::CvType<int>>(rb_mCvFlann, "CvTypeInt").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeFloat = define_class_under<cv::flann::CvType<float>>(rb_mCvFlann, "CvTypeFloat").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
  
  Class rb_cCvFlannCvTypeDouble = define_class_under<cv::flann::CvType<double>>(rb_mCvFlann, "CvTypeDouble").
    define_singleton_function<int(*)()>("type", &cv::flann::CvType::type);
}