#include <sstream>
#include <opencv2/imgproc/bindings.hpp>
#include "bindings-rb.hpp"

using namespace Rice;



void Init_Bindings()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<int(*)(int, int, double, double, int, double, double, double, double)>("hough_lines_with_accumulator", &cv::HoughLinesWithAccumulator,
    Arg("image"), Arg("lines"), Arg("rho"), Arg("theta"), Arg("threshold"), Arg("srn") = 0, Arg("stn") = 0, Arg("min_theta") = 0, Arg("max_theta"));

}