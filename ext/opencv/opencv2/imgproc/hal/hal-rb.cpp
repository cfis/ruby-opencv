#include <opencv2/imgproc/hal/hal.hpp>
#include "hal-rb.hpp"

using namespace Rice;

extern "C"
void Init_Hal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHal = define_module_under(rb_mCv, "Hal");
  
  Class rb_cCvHalFilter2D = define_class_under<cv::hal::Filter2D>(rb_mCvHal, "Filter2D").
    define_singleton_function<cv::Ptr<cv::hal::Filter2D>(*)(unsigned char*, unsigned long long, int, int, int, int, int, int, int, int, double, int, int, bool, bool)>("create", &cv::hal::Filter2D::create).
    define_method<void(cv::hal::Filter2D::*)(unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int)>("apply", &cv::hal::Filter2D::apply);
  
  Class rb_cCvHalSepFilter2D = define_class_under<cv::hal::SepFilter2D>(rb_mCvHal, "SepFilter2D").
    define_singleton_function<cv::Ptr<cv::hal::SepFilter2D>(*)(int, int, int, unsigned char*, int, unsigned char*, int, int, int, double, int)>("create", &cv::hal::SepFilter2D::create).
    define_method<void(cv::hal::SepFilter2D::*)(unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int)>("apply", &cv::hal::SepFilter2D::apply);
  
  Class rb_cCvHalMorph = define_class_under<cv::hal::Morph>(rb_mCvHal, "Morph").
    define_singleton_function<cv::Ptr<cv::hal::Morph>(*)(int, int, int, int, int, int, unsigned char*, unsigned long long, int, int, int, int, int, const double*, int, bool, bool)>("create", &cv::hal::Morph::create).
    define_method<void(cv::hal::Morph::*)(unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int, int, int, int, int)>("apply", &cv::hal::Morph::apply);
  
  rb_mCvHal.define_module_function<void(*)(int, int, int, unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int, unsigned char*, unsigned long long, int, int, int, int, double, int, bool)>("filter2_d", &cv::hal::filter2D);
  
  rb_mCvHal.define_module_function<void(*)(int, int, int, unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int, unsigned char*, int, unsigned char*, int, int, int, double, int)>("sep_filter2_d", &cv::hal::sepFilter2D);
  
  rb_mCvHal.define_module_function<void(*)(int, int, int, unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, int, int, int, int, int, int, unsigned char*, unsigned long long, int, int, int, int, int, const double[4], int, bool)>("morph", &cv::hal::morph);
  
  rb_mCvHal.define_module_function<void(*)(int, const unsigned char*, unsigned long long, int, int, unsigned char*, unsigned long long, int, int, double, double, int)>("resize", &cv::hal::resize);
  
  rb_mCvHal.define_module_function<void(*)(int, const unsigned char*, unsigned long long, int, int, unsigned char*, unsigned long long, int, int, const double[6], int, int, const double[4])>("warp_affine", &cv::hal::warpAffine);
  
  rb_mCvHal.define_module_function<void(*)(int, const unsigned char*, unsigned long long, int, int, unsigned char*, unsigned long long, int, int, const double[9], int, int, const double[4])>("warp_perspective", &cv::hal::warpPerspective);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, int, bool)>("cvt_bg_rto_bgr", &cv::hal::cvtBGRtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_bg_rto_bgr5x5", &cv::hal::cvtBGRtoBGR5x5);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_bgr5x5to_bgr", &cv::hal::cvtBGR5x5toBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool)>("cvt_bg_rto_gray", &cv::hal::cvtBGRtoGray);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int)>("cvt_grayto_bgr", &cv::hal::cvtGraytoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int)>("cvt_bgr5x5to_gray", &cv::hal::cvtBGR5x5toGray);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int)>("cvt_grayto_bgr5x5", &cv::hal::cvtGraytoBGR5x5);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool)>("cvt_bg_rto_yuv", &cv::hal::cvtBGRtoYUV);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool)>("cvt_yu_vto_bgr", &cv::hal::cvtYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool)>("cvt_bg_rto_xyz", &cv::hal::cvtBGRtoXYZ);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool)>("cvt_xy_zto_bgr", &cv::hal::cvtXYZtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool, bool)>("cvt_bg_rto_hsv", &cv::hal::cvtBGRtoHSV);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool, bool)>("cvt_hs_vto_bgr", &cv::hal::cvtHSVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool, bool)>("cvt_bg_rto_lab", &cv::hal::cvtBGRtoLab);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, int, bool, bool, bool)>("cvt_labto_bgr", &cv::hal::cvtLabtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_three_plane_yu_vto_bgr", &cv::hal::cvtThreePlaneYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_bg_rto_three_plane_yuv", &cv::hal::cvtBGRtoThreePlaneYUV);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned char*, unsigned long long, int, int, int, bool, int)>("cvt_bg_rto_two_plane_yuv", &cv::hal::cvtBGRtoTwoPlaneYUV);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int, bool, int, int)>("cvt_one_plane_yu_vto_bgr", &cv::hal::cvtOnePlaneYUVtoBGR);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int)>("cvt_rgb_ato_multiplied_rgba", &cv::hal::cvtRGBAtoMultipliedRGBA);
  
  rb_mCvHal.define_module_function<void(*)(const unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int)>("cvt_multiplied_rgb_ato_rgba", &cv::hal::cvtMultipliedRGBAtoRGBA);
  
  rb_mCvHal.define_module_function<void(*)(int, int, int, const unsigned char*, unsigned long long, unsigned char*, unsigned long long, unsigned char*, unsigned long long, unsigned char*, unsigned long long, int, int, int)>("integral", &cv::hal::integral);
}