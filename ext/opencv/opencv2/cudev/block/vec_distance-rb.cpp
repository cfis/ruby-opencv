#include <opencv2/cudev/block/vec_distance.hpp>
#include "vec_distance-rb.hpp"

using namespace Rice;

extern "C"
void Init_VecDistance()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Class rb_cCvCudevNormL1Float = define_class_under<cv::cudev::NormL1<float>>(rb_mCvCudev, "NormL1Float").
    define_attr("my_sum", &cv::cudev::NormL1::mySum).
    define_constructor(Constructor<cv::cudev::NormL1>()).
    define_method<void(cv::cudev::NormL1::*)(float, float)>("reduce_thread", &cv::cudev::NormL1::reduceThread).
    define_method<void(cv::cudev::NormL1::*)(float*, unsigned int)>("reduce_warp", &cv::cudev::NormL1::reduceWarp);
  
  Class rb_cCvCudevNormL2 = define_class_under<cv::cudev::NormL2>(rb_mCvCudev, "NormL2").
    define_attr("my_sum", &cv::cudev::NormL2::mySum).
    define_constructor(Constructor<cv::cudev::NormL2>()).
    define_method<void(cv::cudev::NormL2::*)(float, float)>("reduce_thread", &cv::cudev::NormL2::reduceThread).
    define_method<void(cv::cudev::NormL2::*)(float*, unsigned int)>("reduce_warp", &cv::cudev::NormL2::reduceWarp);
  
  Class rb_cCvCudevNormHamming = define_class_under<cv::cudev::NormHamming>(rb_mCvCudev, "NormHamming").
    define_attr("my_sum", &cv::cudev::NormHamming::mySum).
    define_constructor(Constructor<cv::cudev::NormHamming>()).
    define_method<void(cv::cudev::NormHamming::*)(int, int)>("reduce_thread", &cv::cudev::NormHamming::reduceThread).
    define_method<void(cv::cudev::NormHamming::*)(int*, unsigned int)>("reduce_warp", &cv::cudev::NormHamming::reduceWarp);
}