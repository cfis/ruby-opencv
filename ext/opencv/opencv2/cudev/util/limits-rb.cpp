#include <opencv2/cudev/util/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

extern "C"
void Init_Limits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevNumericLimitsBool = define_class_under<cv::cudev::numeric_limits<bool>>(rb_mCvCudev, "NumericLimitsBool").
    define_singleton_function<bool(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<bool(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsSchar = define_class_under<cv::cudev::numeric_limits<schar>>(rb_mCvCudev, "NumericLimitsSchar").
    define_singleton_function<signed char(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<signed char(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsUchar = define_class_under<cv::cudev::numeric_limits<uchar>>(rb_mCvCudev, "NumericLimitsUchar").
    define_singleton_function<unsigned char(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<unsigned char(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsShort = define_class_under<cv::cudev::numeric_limits<short>>(rb_mCvCudev, "NumericLimitsShort").
    define_singleton_function<short(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<short(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsUshort = define_class_under<cv::cudev::numeric_limits<ushort>>(rb_mCvCudev, "NumericLimitsUshort").
    define_singleton_function<unsigned short(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<unsigned short(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsInt = define_class_under<cv::cudev::numeric_limits<int>>(rb_mCvCudev, "NumericLimitsInt").
    define_singleton_function<int(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<int(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsUint = define_class_under<cv::cudev::numeric_limits<uint>>(rb_mCvCudev, "NumericLimitsUint").
    define_singleton_function<unsigned int(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<unsigned int(*)()>("max", &cv::cudev::numeric_limits::max);
  
  Class rb_cCvCudevNumericLimitsFloat = define_class_under<cv::cudev::numeric_limits<float>>(rb_mCvCudev, "NumericLimitsFloat").
    define_singleton_function<float(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<float(*)()>("max", &cv::cudev::numeric_limits::max).
    define_singleton_function<float(*)()>("epsilon", &cv::cudev::numeric_limits::epsilon);
  
  Class rb_cCvCudevNumericLimitsDouble = define_class_under<cv::cudev::numeric_limits<double>>(rb_mCvCudev, "NumericLimitsDouble").
    define_singleton_function<double(*)()>("min", &cv::cudev::numeric_limits::min).
    define_singleton_function<double(*)()>("max", &cv::cudev::numeric_limits::max).
    define_singleton_function<double(*)()>("epsilon", &cv::cudev::numeric_limits::epsilon);
}