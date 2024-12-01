#include <opencv2/core/detail/async_promise.hpp>
#include "async_promise-rb.hpp"

using namespace Rice;

extern "C"
void Init_AsyncPromise()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvAsyncPromise = define_class_under<cv::AsyncPromise>(rb_mCv, "AsyncPromise").
    define_constructor(Constructor<cv::AsyncPromise>()).
    define_constructor(Constructor<cv::AsyncPromise, const cv::AsyncPromise&>()).
    define_method<cv::AsyncPromise&(cv::AsyncPromise::*)(const cv::AsyncPromise&) noexcept>("operator=", &cv::AsyncPromise::operator=).
    define_method<void(cv::AsyncPromise::*)() noexcept>("release", &cv::AsyncPromise::release).
    define_method<cv::AsyncArray(cv::AsyncPromise::*)()>("get_array_result", &cv::AsyncPromise::getArrayResult).
    define_method<void(cv::AsyncPromise::*)(const cv::_InputArray &)>("set_value", &cv::AsyncPromise::setValue).
    define_method<void(cv::AsyncPromise::*)(std::exception_ptr)>("set_exception", &cv::AsyncPromise::setException).
    define_method<void(cv::AsyncPromise::*)(const cv::Exception&)>("set_exception", &cv::AsyncPromise::setException).
    define_constructor(Constructor<cv::AsyncPromise, cv::AsyncPromise&&>()).
    define_method<cv::AsyncPromise&(cv::AsyncPromise::*)(cv::AsyncPromise&&) noexcept>("operator=", &cv::AsyncPromise::operator=).
    define_method<void*(cv::AsyncPromise::*)() const noexcept>("_get_impl", &cv::AsyncPromise::_getImpl);
}