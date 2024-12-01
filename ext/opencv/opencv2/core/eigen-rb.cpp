#include <opencv2/core/eigen.hpp>
#include "eigen-rb.hpp"

using namespace Rice;

extern "C"
void Init_Eigen()
{
  Module rb_mCv = define_module("Cv");
}