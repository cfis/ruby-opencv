#include <opencv2/core/bufferpool.hpp>
#include "bufferpool-rb.hpp"

using namespace Rice;



extern "C"
void Init_Bufferpool()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvBufferPoolController = define_class_under<cv::BufferPoolController>(rb_mCv, "BufferPoolController").
    define_method<unsigned long long(cv::BufferPoolController::*)() const>("get_reserved_size", &cv::BufferPoolController::getReservedSize).
    define_method<unsigned long long(cv::BufferPoolController::*)() const>("get_max_reserved_size", &cv::BufferPoolController::getMaxReservedSize).
    define_method<void(cv::BufferPoolController::*)(unsigned long long)>("set_max_reserved_size", &cv::BufferPoolController::setMaxReservedSize).
    define_method<void(cv::BufferPoolController::*)()>("free_all_reserved_buffers", &cv::BufferPoolController::freeAllReservedBuffers);

}