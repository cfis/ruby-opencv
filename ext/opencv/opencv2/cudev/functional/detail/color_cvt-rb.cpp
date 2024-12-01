#include <opencv2/cudev/functional/detail/color_cvt.hpp>
#include "color_cvt-rb.hpp"

using namespace Rice;

extern "C"
void Init_ColorCvt()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  Module rb_mCvCudevColorCvtDetail = define_module_under(rb_mCvCudev, "ColorCvtDetail");
  
  Class rb_cCvCudevColorCvtDetailColorChannelFloat = define_class_under<cv::cudev::color_cvt_detail::ColorChannel<float>>(rb_mCvCudevColorCvtDetail, "ColorChannelFloat").
    define_singleton_function<float(*)()>("max", &cv::cudev::color_cvt_detail::ColorChannel::max).
    define_singleton_function<float(*)()>("half", &cv::cudev::color_cvt_detail::ColorChannel::half);
  
  Class rb_cCvCudevColorCvtDetailGray2RGB5x55 = define_class_under<cv::cudev::color_cvt_detail::Gray2RGB5x5<5>, >(rb_mCvCudevColorCvtDetail, "Gray2RGB5x55").
    define_method<unsigned short(cv::cudev::color_cvt_detail::Gray2RGB5x5::*)(unsigned char) const>("operator()", &cv::cudev::color_cvt_detail::Gray2RGB5x5::operator());
  
  Class rb_cCvCudevColorCvtDetailGray2RGB5x56 = define_class_under<cv::cudev::color_cvt_detail::Gray2RGB5x5<6>, >(rb_mCvCudevColorCvtDetail, "Gray2RGB5x56").
    define_method<unsigned short(cv::cudev::color_cvt_detail::Gray2RGB5x5::*)(unsigned char) const>("operator()", &cv::cudev::color_cvt_detail::Gray2RGB5x5::operator());
  
  Class rb_cCvCudevColorCvtDetailRGB5x52Gray5 = define_class_under<cv::cudev::color_cvt_detail::RGB5x52Gray<5>, >(rb_mCvCudevColorCvtDetail, "RGB5x52Gray5").
    define_method<unsigned char(cv::cudev::color_cvt_detail::RGB5x52Gray::*)(unsigned short) const>("operator()", &cv::cudev::color_cvt_detail::RGB5x52Gray::operator());
  
  Class rb_cCvCudevColorCvtDetailRGB5x52Gray6 = define_class_under<cv::cudev::color_cvt_detail::RGB5x52Gray<6>, >(rb_mCvCudevColorCvtDetail, "RGB5x52Gray6").
    define_method<unsigned char(cv::cudev::color_cvt_detail::RGB5x52Gray::*)(unsigned short) const>("operator()", &cv::cudev::color_cvt_detail::RGB5x52Gray::operator());
}