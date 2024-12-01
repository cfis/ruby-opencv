#include <sstream>
#include <opencv2/core/async.hpp>
#include "async-rb.hpp"

using namespace Rice;



void Init_Async()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvAsyncArray = define_class_under<cv::AsyncArray>(rb_mCv, "AsyncArray").
    define_constructor(Constructor<cv::AsyncArray>()).
    define_constructor(Constructor<cv::AsyncArray, const cv::AsyncArray&>(),
      Arg("o")).
    define_method<cv::AsyncArray&(cv::AsyncArray::*)(const cv::AsyncArray&) noexcept>("=", &cv::AsyncArray::operator=,
      Arg("o")).
    define_method<void(cv::AsyncArray::*)() noexcept>("release", &cv::AsyncArray::release).
    define_method<void(cv::AsyncArray::*)(cv::OutputArray) const>("get", &cv::AsyncArray::get,
      Arg("dst")).
    define_method<bool(cv::AsyncArray::*)(cv::OutputArray, int64) const>("get?", &cv::AsyncArray::get,
      Arg("dst"), Arg("timeout_ns")).
    define_method<bool(cv::AsyncArray::*)(cv::OutputArray, double) const>("get?", &cv::AsyncArray::get,
      Arg("dst"), Arg("timeout_ns")).
    define_method<bool(cv::AsyncArray::*)(int64) const>("wait_for?", &cv::AsyncArray::wait_for,
      Arg("timeout_ns")).
    define_method<bool(cv::AsyncArray::*)(double) const>("wait_for?", &cv::AsyncArray::wait_for,
      Arg("timeout_ns")).
    define_method<bool(cv::AsyncArray::*)() const noexcept>("valid?", &cv::AsyncArray::valid).
    define_constructor(Constructor<cv::AsyncArray, cv::AsyncArray&&>(),
      Arg("o")).
    define_method<cv::AsyncArray&(cv::AsyncArray::*)(cv::AsyncArray&&) noexcept>("=", &cv::AsyncArray::operator=,
      Arg("o")).
    define_method<void*(cv::AsyncArray::*)() const noexcept>("_get_impl", &cv::AsyncArray::_getImpl);
  

}