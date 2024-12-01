#include <opencv2/core/parallel/backend/parallel_for.tbb.hpp>
#include "parallel_for.tbb-rb.hpp"

using namespace Rice;

extern "C"
void Init_ParallelForTbb()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  Module rb_mCvParallelTbb = define_module_under(rb_mCvParallel, "Tbb");
  
  Class rb_cCvParallelTbbParallelForBackend = define_class_under<cv::parallel::tbb::ParallelForBackend, cv::parallel::ParallelForAPI>(rb_mCvParallelTbb, "ParallelForBackend").
    define_constructor(Constructor<cv::parallel::tbb::ParallelForBackend>()).
    define_method<void(cv::parallel::tbb::ParallelForBackend::*)(int, void (*)(int, int, void *), void*)>("parallel_for", &cv::parallel::tbb::ParallelForBackend::parallel_for).
    define_method<int(cv::parallel::tbb::ParallelForBackend::*)() const>("get_thread_num", &cv::parallel::tbb::ParallelForBackend::getThreadNum).
    define_method<int(cv::parallel::tbb::ParallelForBackend::*)() const>("get_num_threads", &cv::parallel::tbb::ParallelForBackend::getNumThreads).
    define_method<int(cv::parallel::tbb::ParallelForBackend::*)(int)>("set_num_threads", &cv::parallel::tbb::ParallelForBackend::setNumThreads).
    define_method<const char*(cv::parallel::tbb::ParallelForBackend::*)() const>("get_name", &cv::parallel::tbb::ParallelForBackend::getName);
  
  Class rb_cCvParallelTbbParallelForBackendCallbackProxy = define_class_under<cv::parallel::tbb::ParallelForBackend::CallbackProxy>(rb_cCvParallelTbbParallelForBackend, "CallbackProxy").
    define_constructor(Constructor<cv::parallel::tbb::ParallelForBackend::CallbackProxy, int, void (*)(int, int, void *)&, void*>()).
    define_method<void(cv::parallel::tbb::ParallelForBackend::CallbackProxy::*)(const int&) const>("operator()", &cv::parallel::tbb::ParallelForBackend::CallbackProxy::operator()).
    define_method<void(cv::parallel::tbb::ParallelForBackend::CallbackProxy::*)() const>("operator()", &cv::parallel::tbb::ParallelForBackend::CallbackProxy::operator());
}