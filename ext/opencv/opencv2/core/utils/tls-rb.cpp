#include <opencv2/core/utils/tls.hpp>
#include "tls-rb.hpp"

using namespace Rice;

extern "C"
void Init_Tls()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
}