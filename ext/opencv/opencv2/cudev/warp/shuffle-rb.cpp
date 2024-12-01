#include <opencv2/cudev/warp/shuffle.hpp>
#include "shuffle-rb.hpp"

using namespace Rice;

extern "C"
void Init_Shuffle()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}