#include <opencv2/core/parallel/parallel_backend.hpp>
#include "parallel_backend-rb.hpp"

using namespace Rice;

extern "C"
void Init_ParallelBackend()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  Class rb_cCvParallelParallelForAPI = define_class_under<cv::parallel::ParallelForAPI>(rb_mCvParallel, "ParallelForAPI").
    define_method<void(cv::parallel::ParallelForAPI::*)(int, void (*)(int, int, void *), void*)>("parallel_for", &cv::parallel::ParallelForAPI::parallel_for).
    define_method<int(cv::parallel::ParallelForAPI::*)() const>("get_thread_num", &cv::parallel::ParallelForAPI::getThreadNum).
    define_method<int(cv::parallel::ParallelForAPI::*)() const>("get_num_threads", &cv::parallel::ParallelForAPI::getNumThreads).
    define_method<int(cv::parallel::ParallelForAPI::*)(int)>("set_num_threads", &cv::parallel::ParallelForAPI::setNumThreads).
    define_method<const char*(cv::parallel::ParallelForAPI::*)() const>("get_name", &cv::parallel::ParallelForAPI::getName);
  
  rb_mCvParallel.define_module_function<void(*)(const std::shared_ptr<cv::parallel::ParallelForAPI>&, bool)>("set_parallel_for_backend", &cv::parallel::setParallelForBackend);
  
  rb_mCvParallel.define_module_function<bool(*)(const std::basic_string<char>&, bool)>("set_parallel_for_backend", &cv::parallel::setParallelForBackend);
}