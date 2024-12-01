#include <opencv2/core/cuda/detail/color_detail.hpp>
#include "color_detail-rb.hpp"

using namespace Rice;

extern "C"
void Init_ColorDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceColorDetail = define_module_under(rb_mCvCudaDevice, "ColorDetail");
  
  Class rb_cCvCudaDeviceColorDetailColorChannelFloat = define_class_under<cv::cuda::device::color_detail::ColorChannel<float>>(rb_mCvCudaDeviceColorDetail, "ColorChannelFloat").
    define_singleton_function<float(*)()>("max", &cv::cuda::device::color_detail::ColorChannel::max).
    define_singleton_function<float(*)()>("half", &cv::cuda::device::color_detail::ColorChannel::half);
  
  Class rb_cCvCudaDeviceColorDetailRGB2RGBUchar, 4, 4, 2 = define_class_under<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>, >(rb_mCvCudaDeviceColorDetail, "RGB2RGBUchar, 4, 4, 2").
    define_method<unsigned int(cv::cuda::device::color_detail::RGB2RGB::*)(unsigned int) const>("operator()", &cv::cuda::device::color_detail::RGB2RGB::operator()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB, const cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>&>());
  
  Class rb_cCvCudaDeviceColorDetailGray2RGBUchar, 4 = define_class_under<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>, >(rb_mCvCudaDeviceColorDetail, "Gray2RGBUchar, 4").
    define_method<unsigned int(cv::cuda::device::color_detail::Gray2RGB::*)(unsigned int) const>("operator()", &cv::cuda::device::color_detail::Gray2RGB::operator()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB>()).
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB, const cv::cuda::device::color_detail::Gray2RGB<uchar, 4>&>());
  
  Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter6 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter6").
    define_singleton_function<unsigned short(*)(unsigned int)>("cvt", &cv::cuda::device::color_detail::Gray2RGB5x5Converter::cvt);
  
  Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter5 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter5").
    define_singleton_function<unsigned short(*)(unsigned int)>("cvt", &cv::cuda::device::color_detail::Gray2RGB5x5Converter::cvt);
  
  Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter6 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter6").
    define_singleton_function<unsigned char(*)(unsigned int)>("cvt", &cv::cuda::device::color_detail::RGB5x52GrayConverter::cvt);
  
  Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter5 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter5").
    define_singleton_function<unsigned char(*)(unsigned int)>("cvt", &cv::cuda::device::color_detail::RGB5x52GrayConverter::cvt);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("lab_cbrt_b", &cv::cuda::device::color_detail::LabCbrt_b);
  
  rb_mCvCudaDeviceColorDetail.define_module_function<float(*)(float, const float*, int)>("spline_interpolate", &cv::cuda::device::color_detail::splineInterpolate);
}