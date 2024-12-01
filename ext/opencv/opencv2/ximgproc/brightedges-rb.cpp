#include <opencv2/ximgproc/brightedges.hpp>
#include "brightedges-rb.hpp"

using namespace Rice;

extern "C"
void Init_Brightedges()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(cv::Mat&, cv::Mat&, int, int, int)>("bright_edges", &cv::ximgproc::BrightEdges);
}