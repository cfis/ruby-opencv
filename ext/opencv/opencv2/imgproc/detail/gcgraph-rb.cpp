#include <opencv2/imgproc/detail/gcgraph.hpp>
#include "gcgraph-rb.hpp"

using namespace Rice;

extern "C"
void Init_Gcgraph()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
}