#include <opencv2/core/detail/async_promise.hpp>
#include "async_promise-rb.hpp"

using namespace Rice;



void Init_AsyncPromise()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvAsyncPromise = define_class_under<cv::AsyncPromise>(rb_mCv, "AsyncPromise").
    define_constructor(Constructor<cv::AsyncPromise>()).
    define_constructor(Constructor<cv::AsyncPromise, const cv::AsyncPromise&>(),
      Arg("o")).
    define_method("release", &cv::AsyncPromise::release).
    define_method("get_array_result", &cv::AsyncPromise::getArrayResult).
    define_method("set_value", &cv::AsyncPromise::setValue,
      Arg("value")).
    define_method<void(cv::AsyncPromise::*)(std::exception_ptr)>("set_exception", &cv::AsyncPromise::setException,
      Arg("exception")).
    define_method<void(cv::AsyncPromise::*)(const int&)>("set_exception", &cv::AsyncPromise::setException,
      Arg("exception")).
    define_method("_get_impl", &cv::AsyncPromise::_getImpl);

}