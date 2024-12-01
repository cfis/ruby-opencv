#include <opencv2/dnn/version.hpp>
#include "version-rb.hpp"

using namespace Rice;

extern "C"
void Init_Version()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
}