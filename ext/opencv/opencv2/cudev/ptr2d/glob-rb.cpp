#include <opencv2/cudev/ptr2d/glob.hpp>
#include "glob-rb.hpp"

using namespace Rice;

extern "C"
void Init_Glob()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}