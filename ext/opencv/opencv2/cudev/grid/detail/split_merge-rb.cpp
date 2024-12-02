#include <opencv2/cudev/grid/detail/split_merge.hpp>
#include "split_merge-rb.hpp"

using namespace Rice;

extern "C"
void Init_SplitMerge()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevGridSplitMergeDetail = define_module_under(rb_mCvCudev, "GridSplitMergeDetail");
}