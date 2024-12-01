#include <opencv2/dnn/utils/inference_engine.hpp>
#include "inference_engine-rb.hpp"

using namespace Rice;

extern "C"
void Init_InferenceEngine()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
}