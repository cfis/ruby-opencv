#include <opencv2/core/utils/allocator_stats.hpp>
#include "allocator_stats-rb.hpp"

using namespace Rice;

extern "C"
void Init_AllocatorStats()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
}