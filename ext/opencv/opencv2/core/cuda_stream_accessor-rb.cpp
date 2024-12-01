#include <opencv2/core/cuda_stream_accessor.hpp>
#include "cuda_stream_accessor-rb.hpp"

using namespace Rice;

extern "C"
void Init_CudaStreamAccessor()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaStreamAccessor = define_class_under<cv::cuda::StreamAccessor>(rb_mCvCuda, "StreamAccessor").
    define_singleton_function<CUstream_st *(*)(const cv::cuda::Stream&)>("get_stream", &cv::cuda::StreamAccessor::getStream).
    define_singleton_function<cv::cuda::Stream(*)(CUstream_st *)>("wrap_stream", &cv::cuda::StreamAccessor::wrapStream);
  
  Class rb_cCvCudaEventAccessor = define_class_under<cv::cuda::EventAccessor>(rb_mCvCuda, "EventAccessor").
    define_singleton_function<CUevent_st *(*)(const cv::cuda::Event&)>("get_event", &cv::cuda::EventAccessor::getEvent).
    define_singleton_function<cv::cuda::Event(*)(CUevent_st *)>("wrap_event", &cv::cuda::EventAccessor::wrapEvent);
}