#include <opencv2/cudev/grid/split_merge.hpp>
#include "split_merge-rb.hpp"

using namespace Rice;

extern "C"
void Init_SplitMerge()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultSplitMergePolicy = define_class_under<cv::cudev::DefaultSplitMergePolicy>(rb_mCvCudev, "DefaultSplitMergePolicy");
}