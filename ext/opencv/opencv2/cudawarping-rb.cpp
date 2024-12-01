#include <opencv2/cudawarping.hpp>
#include "cudawarping-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudawarping()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("remap", &cv::cuda::remap);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, double, double, int, cv::cuda::Stream&)>("resize", &cv::cuda::resize);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::UMat, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Mat, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_affine", &cv::cuda::warpAffine);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, bool, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps);
  
  rb_mCvCuda.define_module_function<void(*)(cv::UMat, bool, cv::Size_<int>, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps);
  
  rb_mCvCuda.define_module_function<void(*)(cv::Mat, bool, cv::Size_<int>, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_affine_maps", &cv::cuda::buildWarpAffineMaps);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::UMat, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Mat, cv::Size_<int>, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("warp_perspective", &cv::cuda::warpPerspective);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, bool, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps);
  
  rb_mCvCuda.define_module_function<void(*)(cv::UMat, bool, cv::Size_<int>, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps);
  
  rb_mCvCuda.define_module_function<void(*)(cv::Mat, bool, cv::Size_<int>, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&)>("build_warp_perspective_maps", &cv::cuda::buildWarpPerspectiveMaps);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, double, double, double, int, cv::cuda::Stream&)>("rotate", &cv::cuda::rotate);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("pyr_down", &cv::cuda::pyrDown);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("pyr_up", &cv::cuda::pyrUp);
}