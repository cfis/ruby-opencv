#include <opencv2/core/softfloat.hpp>
#include "softfloat-rb.hpp"

using namespace Rice;

extern "C"
void Init_Softfloat()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvSoftfloat = define_class_under<cv::softfloat>(rb_mCv, "Softfloat").
    define_constructor(Constructor<cv::softfloat>()).
    define_constructor(Constructor<cv::softfloat, const cv::softfloat&>()).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator=", &cv::softfloat::operator=).
    define_singleton_function<const cv::softfloat(*)(const unsigned int)>("from_raw", &cv::softfloat::fromRaw).
    define_constructor(Constructor<cv::softfloat, const unsigned int>()).
    define_constructor(Constructor<cv::softfloat, const unsigned long long>()).
    define_constructor(Constructor<cv::softfloat, const int>()).
    define_constructor(Constructor<cv::softfloat, const long long>()).
    define_constructor(Constructor<cv::softfloat, const float>()).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("operator+", &cv::softfloat::operator+).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("operator_", &cv::softfloat::operator-).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("operator*", &cv::softfloat::operator*).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("operator/", &cv::softfloat::operator/).
    define_method<cv::softfloat(cv::softfloat::*)() const>("operator_", &cv::softfloat::operator-).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("operator%", &cv::softfloat::operator%).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator+=", &cv::softfloat::operator+=).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator_=", &cv::softfloat::operator-=).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator*=", &cv::softfloat::operator*=).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator/=", &cv::softfloat::operator/=).
    define_method<cv::softfloat&(cv::softfloat::*)(const cv::softfloat&)>("operator%=", &cv::softfloat::operator%=).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator==", &cv::softfloat::operator==).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator!=", &cv::softfloat::operator!=).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator>", &cv::softfloat::operator>).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator>=", &cv::softfloat::operator>=).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator<", &cv::softfloat::operator<).
    define_method<bool(cv::softfloat::*)(const cv::softfloat&) const>("operator<=", &cv::softfloat::operator<=).
    define_method<bool(cv::softfloat::*)() const>("is_na_n", &cv::softfloat::isNaN).
    define_method<bool(cv::softfloat::*)() const>("is_inf", &cv::softfloat::isInf).
    define_method<bool(cv::softfloat::*)() const>("is_subnormal", &cv::softfloat::isSubnormal).
    define_method<bool(cv::softfloat::*)() const>("get_sign", &cv::softfloat::getSign).
    define_method<cv::softfloat(cv::softfloat::*)(bool) const>("set_sign", &cv::softfloat::setSign).
    define_method<int(cv::softfloat::*)() const>("get_exp", &cv::softfloat::getExp).
    define_method<cv::softfloat(cv::softfloat::*)(int) const>("set_exp", &cv::softfloat::setExp).
    define_method<cv::softfloat(cv::softfloat::*)() const>("get_frac", &cv::softfloat::getFrac).
    define_method<cv::softfloat(cv::softfloat::*)(const cv::softfloat&) const>("set_frac", &cv::softfloat::setFrac).
    define_singleton_function<cv::softfloat(*)()>("zero", &cv::softfloat::zero).
    define_singleton_function<cv::softfloat(*)()>("inf", &cv::softfloat::inf).
    define_singleton_function<cv::softfloat(*)()>("nan", &cv::softfloat::nan).
    define_singleton_function<cv::softfloat(*)()>("one", &cv::softfloat::one).
    define_singleton_function<cv::softfloat(*)()>("min", &cv::softfloat::min).
    define_singleton_function<cv::softfloat(*)()>("eps", &cv::softfloat::eps).
    define_singleton_function<cv::softfloat(*)()>("max", &cv::softfloat::max).
    define_singleton_function<cv::softfloat(*)()>("pi", &cv::softfloat::pi).
    define_attr("v", &cv::softfloat::v);
  
  Class rb_cCvSoftdouble = define_class_under<cv::softdouble>(rb_mCv, "Softdouble").
    define_constructor(Constructor<cv::softdouble>()).
    define_constructor(Constructor<cv::softdouble, const cv::softdouble&>()).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator=", &cv::softdouble::operator=).
    define_singleton_function<cv::softdouble(*)(const unsigned long long)>("from_raw", &cv::softdouble::fromRaw).
    define_constructor(Constructor<cv::softdouble, const unsigned int>()).
    define_constructor(Constructor<cv::softdouble, const unsigned long long>()).
    define_constructor(Constructor<cv::softdouble, const int>()).
    define_constructor(Constructor<cv::softdouble, const long long>()).
    define_constructor(Constructor<cv::softdouble, const double>()).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("operator+", &cv::softdouble::operator+).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("operator_", &cv::softdouble::operator-).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("operator*", &cv::softdouble::operator*).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("operator/", &cv::softdouble::operator/).
    define_method<cv::softdouble(cv::softdouble::*)() const>("operator_", &cv::softdouble::operator-).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("operator%", &cv::softdouble::operator%).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator+=", &cv::softdouble::operator+=).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator_=", &cv::softdouble::operator-=).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator*=", &cv::softdouble::operator*=).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator/=", &cv::softdouble::operator/=).
    define_method<cv::softdouble&(cv::softdouble::*)(const cv::softdouble&)>("operator%=", &cv::softdouble::operator%=).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator==", &cv::softdouble::operator==).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator!=", &cv::softdouble::operator!=).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator>", &cv::softdouble::operator>).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator>=", &cv::softdouble::operator>=).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator<", &cv::softdouble::operator<).
    define_method<bool(cv::softdouble::*)(const cv::softdouble&) const>("operator<=", &cv::softdouble::operator<=).
    define_method<bool(cv::softdouble::*)() const>("is_na_n", &cv::softdouble::isNaN).
    define_method<bool(cv::softdouble::*)() const>("is_inf", &cv::softdouble::isInf).
    define_method<bool(cv::softdouble::*)() const>("is_subnormal", &cv::softdouble::isSubnormal).
    define_method<bool(cv::softdouble::*)() const>("get_sign", &cv::softdouble::getSign).
    define_method<cv::softdouble(cv::softdouble::*)(bool) const>("set_sign", &cv::softdouble::setSign).
    define_method<int(cv::softdouble::*)() const>("get_exp", &cv::softdouble::getExp).
    define_method<cv::softdouble(cv::softdouble::*)(int) const>("set_exp", &cv::softdouble::setExp).
    define_method<cv::softdouble(cv::softdouble::*)() const>("get_frac", &cv::softdouble::getFrac).
    define_method<cv::softdouble(cv::softdouble::*)(const cv::softdouble&) const>("set_frac", &cv::softdouble::setFrac).
    define_singleton_function<cv::softdouble(*)()>("zero", &cv::softdouble::zero).
    define_singleton_function<cv::softdouble(*)()>("inf", &cv::softdouble::inf).
    define_singleton_function<cv::softdouble(*)()>("nan", &cv::softdouble::nan).
    define_singleton_function<cv::softdouble(*)()>("one", &cv::softdouble::one).
    define_singleton_function<cv::softdouble(*)()>("min", &cv::softdouble::min).
    define_singleton_function<cv::softdouble(*)()>("eps", &cv::softdouble::eps).
    define_singleton_function<cv::softdouble(*)()>("max", &cv::softdouble::max).
    define_singleton_function<cv::softdouble(*)()>("pi", &cv::softdouble::pi).
    define_attr("v", &cv::softdouble::v);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&, const cv::softfloat&)>("mul_add", &cv::mulAdd);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&, const cv::softdouble&)>("mul_add", &cv::mulAdd);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("sqrt", &cv::sqrt);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("sqrt", &cv::sqrt);
  
  define_global_function<int(*)(const cv::softfloat&)>("cv_trunc", &cvTrunc);
  
  define_global_function<int(*)(const cv::softdouble&)>("cv_trunc", &cvTrunc);
  
  define_global_function<int(*)(const cv::softfloat&)>("cv_round", &cvRound);
  
  define_global_function<int(*)(const cv::softdouble&)>("cv_round", &cvRound);
  
  define_global_function<long long(*)(const cv::softdouble&)>("cv_round64", &cvRound64);
  
  define_global_function<int(*)(const cv::softfloat&)>("cv_floor", &cvFloor);
  
  define_global_function<int(*)(const cv::softdouble&)>("cv_floor", &cvFloor);
  
  define_global_function<int(*)(const cv::softfloat&)>("cv_ceil", &cvCeil);
  
  define_global_function<int(*)(const cv::softdouble&)>("cv_ceil", &cvCeil);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("min", &cv::min);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("min", &cv::min);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("max", &cv::max);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("max", &cv::max);
  
  rb_mCv.define_module_function<cv::softfloat(*)(cv::softfloat)>("abs", &cv::abs);
  
  rb_mCv.define_module_function<cv::softdouble(*)(cv::softdouble)>("abs", &cv::abs);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("exp", &cv::exp);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("exp", &cv::exp);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("log", &cv::log);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("log", &cv::log);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&, const cv::softfloat&)>("pow", &cv::pow);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&, const cv::softdouble&)>("pow", &cv::pow);
  
  rb_mCv.define_module_function<cv::softfloat(*)(const cv::softfloat&)>("cbrt", &cv::cbrt);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("sin", &cv::sin);
  
  rb_mCv.define_module_function<cv::softdouble(*)(const cv::softdouble&)>("cos", &cv::cos);
}