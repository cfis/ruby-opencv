#include <opencv2/fuzzy/types.hpp>
#include "types-rb.hpp"

using namespace Rice;

extern "C"
void Init_Types()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvFt = define_module_under(rb_mCv, "Ft");
}