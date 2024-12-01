#include <opencv2/cudev/block/block.hpp>
#include "block-rb.hpp"

using namespace Rice;

extern "C"
void Init_Block()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevBlock = define_class_under<cv::cudev::Block>(rb_mCvCudev, "Block").
    define_singleton_function<unsigned int(*)()>("block_id", &cv::cudev::Block::blockId).
    define_singleton_function<unsigned int(*)()>("block_size", &cv::cudev::Block::blockSize).
    define_singleton_function<unsigned int(*)()>("thread_line_id", &cv::cudev::Block::threadLineId);
}