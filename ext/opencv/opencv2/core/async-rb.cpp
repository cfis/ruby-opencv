#include <opencv2/core/async.hpp>
#include "async-rb.hpp"

using namespace Rice;

extern "C"
void Init_Async()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvAsyncArray = define_class_under<cv::AsyncArray>(rb_mCv, "AsyncArray").
    define_constructor(Constructor<cv::AsyncArray>()).
    define_constructor(Constructor<cv::AsyncArray, const cv::AsyncArray&>()).
    define_method<cv::AsyncArray&(cv::AsyncArray::*)(const cv::AsyncArray&) noexcept>("operator=", &cv::AsyncArray::operator=).
    define_method<void(cv::AsyncArray::*)() noexcept>("release", &cv::AsyncArray::release).
    define_method<void(cv::AsyncArray::*)(const cv::_OutputArray &) const>("get", &cv::AsyncArray::get).
    define_method<bool(cv::AsyncArray::*)(const cv::_OutputArray &, long long) const>("get", &cv::AsyncArray::get).
    define_method<bool(cv::AsyncArray::*)(const cv::_OutputArray &, double) const>("get", &cv::AsyncArray::get).
    define_method<bool(cv::AsyncArray::*)(long long) const>("wait_for", &cv::AsyncArray::wait_for).
    define_method<bool(cv::AsyncArray::*)(double) const>("wait_for", &cv::AsyncArray::wait_for).
    define_method<bool(cv::AsyncArray::*)() const noexcept>("valid", &cv::AsyncArray::valid).
    define_constructor(Constructor<cv::AsyncArray, cv::AsyncArray&&>()).
    define_method<cv::AsyncArray&(cv::AsyncArray::*)(cv::AsyncArray&&) noexcept>("operator=", &cv::AsyncArray::operator=).
    define_method<void*(cv::AsyncArray::*)() const noexcept>("_get_impl", &cv::AsyncArray::_getImpl);
}