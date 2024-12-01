#include <opencv2/core/saturate.hpp>
#include "saturate-rb.hpp"

using namespace Rice;

extern "C"
void Init_Saturate()
{
  Module rb_mCv = define_module("Cv");
}