#include <opencv2/xfeatures2d/cuda.hpp>
#include "cuda-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cuda()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaSURFCUDA = define_class_under<cv::cuda::SURF_CUDA>(rb_mCvCuda, "SURF_CUDA").
    define_constructor(Constructor<cv::cuda::SURF_CUDA>()).
    define_constructor(Constructor<cv::cuda::SURF_CUDA, double, int, int, bool, float, bool>()).
    define_singleton_function<cv::Ptr<cv::cuda::SURF_CUDA>(*)(double, int, int, bool, float, bool)>("create", &cv::cuda::SURF_CUDA::create).
    define_method<int(cv::cuda::SURF_CUDA::*)() const>("descriptor_size", &cv::cuda::SURF_CUDA::descriptorSize).
    define_method<int(cv::cuda::SURF_CUDA::*)() const>("default_norm", &cv::cuda::SURF_CUDA::defaultNorm).
    define_method<void(cv::cuda::SURF_CUDA::*)(const std::vector<cv::KeyPoint>&, cv::cuda::GpuMat&)>("upload_keypoints", &cv::cuda::SURF_CUDA::uploadKeypoints).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&)>("download_keypoints", &cv::cuda::SURF_CUDA::downloadKeypoints).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, std::vector<float>&)>("download_descriptors", &cv::cuda::SURF_CUDA::downloadDescriptors).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("operator()", &cv::cuda::SURF_CUDA::operator()).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, bool)>("operator()", &cv::cuda::SURF_CUDA::operator()).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("detect", &cv::cuda::SURF_CUDA::detect).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&)>("operator()", &cv::cuda::SURF_CUDA::operator()).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&, cv::cuda::GpuMat&, bool)>("operator()", &cv::cuda::SURF_CUDA::operator()).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, bool)>("detect_with_descriptors", &cv::cuda::SURF_CUDA::detectWithDescriptors).
    define_method<void(cv::cuda::SURF_CUDA::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, std::vector<cv::KeyPoint>&, std::vector<float>&, bool)>("operator()", &cv::cuda::SURF_CUDA::operator()).
    define_method<void(cv::cuda::SURF_CUDA::*)()>("release_memory", &cv::cuda::SURF_CUDA::releaseMemory).
    define_attr("hessian_threshold", &cv::cuda::SURF_CUDA::hessianThreshold).
    define_attr("n_octaves", &cv::cuda::SURF_CUDA::nOctaves).
    define_attr("n_octave_layers", &cv::cuda::SURF_CUDA::nOctaveLayers).
    define_attr("extended", &cv::cuda::SURF_CUDA::extended).
    define_attr("upright", &cv::cuda::SURF_CUDA::upright).
    define_attr("keypoints_ratio", &cv::cuda::SURF_CUDA::keypointsRatio).
    define_attr("sum", &cv::cuda::SURF_CUDA::sum).
    define_attr("mask1", &cv::cuda::SURF_CUDA::mask1).
    define_attr("mask_sum", &cv::cuda::SURF_CUDA::maskSum).
    define_attr("det", &cv::cuda::SURF_CUDA::det).
    define_attr("trace", &cv::cuda::SURF_CUDA::trace).
    define_attr("max_pos_buffer", &cv::cuda::SURF_CUDA::maxPosBuffer);
  
  Enum<cv::cuda::SURF_CUDA::KeypointLayout> rb_cCvCudaSURFCUDAKeypointLayout = define_enum<cv::cuda::SURF_CUDA::KeypointLayout>("KeypointLayout", rb_cCvCudaSURFCUDA).
    define_value("X_ROW", cv::cuda::SURF_CUDA::KeypointLayout::X_ROW).
    define_value("Y_ROW", cv::cuda::SURF_CUDA::KeypointLayout::Y_ROW).
    define_value("LAPLACIAN_ROW", cv::cuda::SURF_CUDA::KeypointLayout::LAPLACIAN_ROW).
    define_value("OCTAVE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::OCTAVE_ROW).
    define_value("SIZE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::SIZE_ROW).
    define_value("ANGLE_ROW", cv::cuda::SURF_CUDA::KeypointLayout::ANGLE_ROW).
    define_value("HESSIAN_ROW", cv::cuda::SURF_CUDA::KeypointLayout::HESSIAN_ROW).
    define_value("ROWS_COUNT", cv::cuda::SURF_CUDA::KeypointLayout::ROWS_COUNT);
}