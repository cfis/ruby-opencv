#include <opencv2/imgproc/bindings.hpp>
#include "bindings-rb.hpp"

using namespace Rice;

extern "C"
void Init_Bindings()
{
  Module rb_mCv = define_module("Cv");
}