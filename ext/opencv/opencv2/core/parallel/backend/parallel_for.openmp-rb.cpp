#include <opencv2/core/parallel/backend/parallel_for.openmp.hpp>
#include "parallel_for.openmp-rb.hpp"

using namespace Rice;

extern "C"
void Init_ParallelForOpenmp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  Module rb_mCvParallelOpenmp = define_module_under(rb_mCvParallel, "Openmp");
  
  Class rb_cCvParallelOpenmpParallelForBackend = define_class_under<cv::parallel::openmp::ParallelForBackend, cv::parallel::ParallelForAPI>(rb_mCvParallelOpenmp, "ParallelForBackend").
    define_constructor(Constructor<cv::parallel::openmp::ParallelForBackend>()).
    define_method<void(cv::parallel::openmp::ParallelForBackend::*)(int, void (*)(int, int, void *), void*)>("parallel_for", &cv::parallel::openmp::ParallelForBackend::parallel_for).
    define_method<int(cv::parallel::openmp::ParallelForBackend::*)() const>("get_thread_num", &cv::parallel::openmp::ParallelForBackend::getThreadNum).
    define_method<int(cv::parallel::openmp::ParallelForBackend::*)() const>("get_num_threads", &cv::parallel::openmp::ParallelForBackend::getNumThreads).
    define_method<int(cv::parallel::openmp::ParallelForBackend::*)(int)>("set_num_threads", &cv::parallel::openmp::ParallelForBackend::setNumThreads).
    define_method<const char*(cv::parallel::openmp::ParallelForBackend::*)() const>("get_name", &cv::parallel::openmp::ParallelForBackend::getName);
}