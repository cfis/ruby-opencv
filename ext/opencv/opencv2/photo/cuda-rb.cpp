#include <opencv2/photo/cuda.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cuda()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, int, int, int, cv::cuda::Stream&)>("non_local_means", &cv::cuda::nonLocalMeans);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, int, int, int, cv::cuda::Stream&)>("non_local_means", &cv::cuda::nonLocalMeans);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising", &cv::cuda::fastNlMeansDenoising);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising", &cv::cuda::fastNlMeansDenoising);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, float, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising_colored", &cv::cuda::fastNlMeansDenoisingColored);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat&, cv::cuda::GpuMat&, float, float, int, int, cv::cuda::Stream&)>("fast_nl_means_denoising_colored", &cv::cuda::fastNlMeansDenoisingColored);
}