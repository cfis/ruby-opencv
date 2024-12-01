#include <opencv2/core/dualquaternion.hpp>
#include "dualquaternion-rb.hpp"

using namespace Rice;

extern "C"
void Init_Dualquaternion()
{
  Module rb_mCv = define_module("Cv");
}