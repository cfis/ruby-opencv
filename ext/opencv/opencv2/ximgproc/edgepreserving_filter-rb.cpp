#include <opencv2/ximgproc/edgepreserving_filter.hpp>
#include "edgepreserving_filter-rb.hpp"

using namespace Rice;

extern "C"
void Init_EdgepreservingFilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  rb_mCvXimgproc.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double)>("edge_preserving_filter", &cv::ximgproc::edgePreservingFilter);
}