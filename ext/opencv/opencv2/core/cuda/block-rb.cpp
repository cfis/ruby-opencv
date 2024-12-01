#include <opencv2/core/cuda/block.hpp>
#include "block-rb.hpp"

using namespace Rice;

extern "C"
void Init_Block()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Class rb_cCvCudaDeviceBlock = define_class_under<cv::cuda::device::Block>(rb_mCvCudaDevice, "Block").
    define_singleton_function<unsigned int(*)()>("id", &cv::cuda::device::Block::id).
    define_singleton_function<unsigned int(*)()>("stride", &cv::cuda::device::Block::stride).
    define_singleton_function<void(*)()>("sync", &cv::cuda::device::Block::sync).
    define_singleton_function<int(*)()>("flattened_thread_id", &cv::cuda::device::Block::flattenedThreadId);
}