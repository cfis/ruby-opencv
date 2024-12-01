#include <opencv2/imgproc/hal/hal.hpp>
#include "hal-rb.hpp"

using namespace Rice;



void Init_Hal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHal = define_module_under(rb_mCv, "Hal");
  
  Class rb_cCvHalFilter2D = define_class_under<cv::hal::Filter2D>(rb_mCvHal, "Filter2D").
    define_singleton_function("create", &cv::hal::Filter2D::create,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg("")).
    define_method("apply", &cv::hal::Filter2D::apply,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""));
  
  Class rb_cCvHalSepFilter2D = define_class_under<cv::hal::SepFilter2D>(rb_mCvHal, "SepFilter2D").
    define_singleton_function("create", &cv::hal::SepFilter2D::create,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg("")).
    define_method("apply", &cv::hal::SepFilter2D::apply,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""));
  
  Class rb_cCvHalMorph = define_class_under<cv::hal::Morph>(rb_mCvHal, "Morph").
    define_singleton_function("create", &cv::hal::Morph::create,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg("")).
    define_method("apply", &cv::hal::Morph::apply,
      Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""), Arg(""));
  
  rb_mCvHal.define_module_function("filter2_d", &cv::hal::filter2D,
    Arg("stype"), Arg("dtype"), Arg("kernel_type"), Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("full_width"), Arg("full_height"), Arg("offset_x"), Arg("offset_y"), Arg("kernel_data"), Arg("kernel_step"), Arg("kernel_width"), Arg("kernel_height"), Arg("anchor_x"), Arg("anchor_y"), Arg("delta"), Arg("border_type"), Arg("is_submatrix"));
  
  rb_mCvHal.define_module_function("sep_filter2_d", &cv::hal::sepFilter2D,
    Arg("stype"), Arg("dtype"), Arg("ktype"), Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("full_width"), Arg("full_height"), Arg("offset_x"), Arg("offset_y"), Arg("kernelx_data"), Arg("kernelx_len"), Arg("kernely_data"), Arg("kernely_len"), Arg("anchor_x"), Arg("anchor_y"), Arg("delta"), Arg("border_type"));
  
  rb_mCvHal.define_module_function("morph", &cv::hal::morph,
    Arg("op"), Arg("src_type"), Arg("dst_type"), Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("roi_width"), Arg("roi_height"), Arg("roi_x"), Arg("roi_y"), Arg("roi_width2"), Arg("roi_height2"), Arg("roi_x2"), Arg("roi_y2"), Arg("kernel_type"), Arg("kernel_data"), Arg("kernel_step"), Arg("kernel_width"), Arg("kernel_height"), Arg("anchor_x"), Arg("anchor_y"), Arg("border_type"), Arg("border_value"), Arg("iterations"), Arg("is_submatrix"));
  
  rb_mCvHal.define_module_function("resize", &cv::hal::resize,
    Arg("src_type"), Arg("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("inv_scale_x"), Arg("inv_scale_y"), Arg("interpolation"));
  
  rb_mCvHal.define_module_function("warp_affine", &cv::hal::warpAffine,
    Arg("src_type"), Arg("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("m"), Arg("interpolation"), Arg("border_type"), Arg("border_value"));
  
  rb_mCvHal.define_module_function("warp_perspective", &cv::hal::warpPerspective,
    Arg("src_type"), Arg("src_data"), Arg("src_step"), Arg("src_width"), Arg("src_height"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("m"), Arg("interpolation"), Arg("border_type"), Arg("border_value"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_bgr", &cv::hal::cvtBGRtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("dcn"), Arg("swap_blue"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_bgr5x5", &cv::hal::cvtBGRtoBGR5x5,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("green_bits"));
  
  rb_mCvHal.define_module_function("cvt_bgr5x5to_bgr", &cv::hal::cvtBGR5x5toBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("dcn"), Arg("swap_blue"), Arg("green_bits"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_gray", &cv::hal::cvtBGRtoGray,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"));
  
  rb_mCvHal.define_module_function("cvt_grayto_bgr", &cv::hal::cvtGraytoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"));
  
  rb_mCvHal.define_module_function("cvt_bgr5x5to_gray", &cv::hal::cvtBGR5x5toGray,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("green_bits"));
  
  rb_mCvHal.define_module_function("cvt_grayto_bgr5x5", &cv::hal::cvtGraytoBGR5x5,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("green_bits"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_yuv", &cv::hal::cvtBGRtoYUV,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_cb_cr"));
  
  rb_mCvHal.define_module_function("cvt_yu_vto_bgr", &cv::hal::cvtYUVtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_cb_cr"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_xyz", &cv::hal::cvtBGRtoXYZ,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"));
  
  rb_mCvHal.define_module_function("cvt_xy_zto_bgr", &cv::hal::cvtXYZtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_hsv", &cv::hal::cvtBGRtoHSV,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_full_range"), Arg("is_hsv"));
  
  rb_mCvHal.define_module_function("cvt_hs_vto_bgr", &cv::hal::cvtHSVtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_full_range"), Arg("is_hsv"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_lab", &cv::hal::cvtBGRtoLab,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("scn"), Arg("swap_blue"), Arg("is_lab"), Arg("srgb"));
  
  rb_mCvHal.define_module_function("cvt_labto_bgr", &cv::hal::cvtLabtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("depth"), Arg("dcn"), Arg("swap_blue"), Arg("is_lab"), Arg("srgb"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, uchar*, ::size_t, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, const uchar*, ::size_t, uchar*, ::size_t, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    Arg("y_data"), Arg("uv_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, int, bool, int)>("cvt_two_plane_yu_vto_bgr", &cv::hal::cvtTwoPlaneYUVtoBGR,
    Arg("y_data"), Arg("y_step"), Arg("uv_data"), Arg("uv_step"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function("cvt_three_plane_yu_vto_bgr", &cv::hal::cvtThreePlaneYUVtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("dst_width"), Arg("dst_height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_three_plane_yuv", &cv::hal::cvtBGRtoThreePlaneYUV,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function("cvt_bg_rto_two_plane_yuv", &cv::hal::cvtBGRtoTwoPlaneYUV,
    Arg("src_data"), Arg("src_step"), Arg("y_data"), Arg("uv_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"));
  
  rb_mCvHal.define_module_function("cvt_one_plane_yu_vto_bgr", &cv::hal::cvtOnePlaneYUVtoBGR,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("dcn"), Arg("swap_blue"), Arg("u_idx"), Arg("ycn"));
  
  rb_mCvHal.define_module_function("cvt_one_plane_bg_rto_yuv", &cv::hal::cvtOnePlaneBGRtoYUV,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"), Arg("scn"), Arg("swap_blue"), Arg("u_idx"), Arg("ycn"));
  
  rb_mCvHal.define_module_function("cvt_rgb_ato_multiplied_rgba", &cv::hal::cvtRGBAtoMultipliedRGBA,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"));
  
  rb_mCvHal.define_module_function("cvt_multiplied_rgb_ato_rgba", &cv::hal::cvtMultipliedRGBAtoRGBA,
    Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"), Arg("width"), Arg("height"));
  
  rb_mCvHal.define_module_function("integral", &cv::hal::integral,
    Arg("depth"), Arg("sdepth"), Arg("sqdepth"), Arg("src"), Arg("srcstep"), Arg("sum"), Arg("sumstep"), Arg("sqsum"), Arg("sqsumstep"), Arg("tilted"), Arg("tstep"), Arg("width"), Arg("height"), Arg("cn"));

}