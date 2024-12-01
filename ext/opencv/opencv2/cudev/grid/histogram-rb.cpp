#include <opencv2/cudev/grid/histogram.hpp>
#include "histogram-rb.hpp"

using namespace Rice;

extern "C"
void Init_Histogram()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevDefaultHistogramPolicy = define_class_under<cv::cudev::DefaultHistogramPolicy>(rb_mCvCudev, "DefaultHistogramPolicy");
}