#include <opencv2/cudev/warp/warp.hpp>
#include "warp-rb.hpp"

using namespace Rice;

extern "C"
void Init_Warp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevWarp = define_class_under<cv::cudev::Warp>(rb_mCvCudev, "Warp").
    define_singleton_function<unsigned int(*)()>("lane_id", &cv::cudev::Warp::laneId).
    define_singleton_function<unsigned int(*)()>("warp_id", &cv::cudev::Warp::warpId);
}