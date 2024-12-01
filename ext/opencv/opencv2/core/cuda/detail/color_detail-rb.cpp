#include <sstream>
#include <opencv2/core/cuda/detail/color_detail.hpp>
#include "color_detail-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void ColorChannel_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2RGB_builder(Data_Type_T& klass)
{
  klass.template define_method<int(cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::*)(const typename TypeVec<T, scn>::vec_type&) const>("()", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::operator(),
      Arg("src")).
    define_attr("__device__", &cv::cuda::device::color_detail::RGB2RGB<T, scn, dcn, bidx>::__device__);
};

template<typename Data_Type_T, int green_bits, int bidx>
inline void RGB2RGB5x5Converter_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, int scn, int bidx, int green_bits>
inline void RGB2RGB5x5_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, int green_bits, int bidx>
inline void RGB5x52RGBConverter_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, int dcn, int bidx, int green_bits>
inline void RGB5x52RGB_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int dcn>
inline void Gray2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB<T, dcn>::__forceinline__);
};

template<typename Data_Type_T, int green_bits>
inline void Gray2RGB5x5Converter_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, int green_bits>
inline void Gray2RGB5x5_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB5x5<green_bits>::__forceinline__);
};

template<typename Data_Type_T, int green_bits>
inline void RGB5x52GrayConverter_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, int green_bits>
inline void RGB5x52Gray_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB5x52Gray<green_bits>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int bidx>
inline void RGB2Gray_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2Gray<T, scn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YUV_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2YUV<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YUV2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::YUV2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2YCrCb_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2YCrCb<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void YCrCb2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::YCrCb2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void RGB2XYZ_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2XYZ<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx>
inline void XYZ2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::XYZ2RGB<T, scn, dcn, bidx>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HSV_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2HSV<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HSV2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::HSV2RGB<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void RGB2HLS_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::RGB2HLS<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, int bidx, int hr>
inline void HLS2RGB_builder(Data_Type_T& klass)
{
  klass.define_attr("__forceinline__", &cv::cuda::device::color_detail::HLS2RGB<T, scn, dcn, bidx, hr>::__forceinline__);
};

template<typename Data_Type_T, typename T, int scn, int dcn, bool srgb, int blueIdx>
inline void RGB2Lab_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int scn, int dcn, bool srgb, int blueIdx>
inline void Lab2RGB_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int scn, int dcn, bool srgb, int blueIdx>
inline void RGB2Luv_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T, int scn, int dcn, bool srgb, int blueIdx>
inline void Luv2RGB_builder(Data_Type_T& klass)
{
};


void Init_ColorDetail()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Module rb_mCvCudaDeviceColorDetail = define_module_under(rb_mCvCudaDevice, "ColorDetail");
  
  Class rb_cCvCudaDeviceColorDetailColorChannelFloat = define_class_under<cv::cuda::device::color_detail::ColorChannel<float>>(rb_mCvCudaDeviceColorDetail, "ColorChannelFloat").
    define_constructor(Constructor<cv::cuda::device::color_detail::ColorChannel<float>>());
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(int&, int)>("set_alpha", &cv::cuda::device::color_detail::setAlpha,
    Arg("vec"), Arg("val"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(int&, int)>("set_alpha", &cv::cuda::device::color_detail::setAlpha,
    Arg("vec"), Arg("val"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int&)>("get_alpha", &cv::cuda::device::color_detail::getAlpha,
    Arg("vec"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int&)>("get_alpha", &cv::cuda::device::color_detail::getAlpha,
    Arg("vec"));
  
  Class rb_cCvCudaDeviceColorDetailRGB2RGBUchar442 = define_class_under<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>>(rb_mCvCudaDeviceColorDetail, "RGB2RGBUchar442").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>>()).
    define_attr("uint", &cv::cuda::device::color_detail::RGB2RGB<uchar, 4, 4, 2>::uint);
  
  Class rb_cCvCudaDeviceColorDetailGray2RGBUchar4 = define_class_under<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>>(rb_mCvCudaDeviceColorDetail, "Gray2RGBUchar4").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB<uchar, 4>>()).
    define_attr("__forceinline__", &cv::cuda::device::color_detail::Gray2RGB<uchar, 4>::__forceinline__);
  
  Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter6 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<6>>());
  
  Class rb_cCvCudaDeviceColorDetailGray2RGB5x5Converter5 = define_class_under<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>(rb_mCvCudaDeviceColorDetail, "Gray2RGB5x5Converter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::Gray2RGB5x5Converter<5>>());
  
  Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter6 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter6").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<6>>());
  
  Class rb_cCvCudaDeviceColorDetailRGB5x52GrayConverter5 = define_class_under<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>(rb_mCvCudaDeviceColorDetail, "RGB5x52GrayConverter5").
    define_constructor(Constructor<cv::cuda::device::color_detail::RGB5x52GrayConverter<5>>());
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(const int*)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<uchar(*)(uint)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<float(*)(const float*)>("rgb2_gray_convert", &cv::cuda::device::color_detail::RGB2GrayConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const float*, int&)>("rgb2_yuv_convert", &cv::cuda::device::color_detail::RGB2YUVConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("yuv2_rgb_convert", &cv::cuda::device::color_detail::YUV2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("yuv2_rgb_convert", &cv::cuda::device::color_detail::YUV2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_y_cr_cb_convert", &cv::cuda::device::color_detail::RGB2YCrCbConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const float*, int&)>("rgb2_y_cr_cb_convert", &cv::cuda::device::color_detail::RGB2YCrCbConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("y_cr_cb2_rgb_convert", &cv::cuda::device::color_detail::YCrCb2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("y_cr_cb2_rgb_convert", &cv::cuda::device::color_detail::YCrCb2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int*, int&)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const float*, int&)>("rgb2_xyz_convert", &cv::cuda::device::color_detail::RGB2XYZConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int*)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, float*)>("xyz2_rgb_convert", &cv::cuda::device::color_detail::XYZ2RGBConvert,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_hsv_convert", &cv::cuda::device::color_detail::RGB2HSVConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("hsv2_rgb_convert", &cv::cuda::device::color_detail::HSV2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("rgb2_hls_convert", &cv::cuda::device::color_detail::RGB2HLSConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("hls2_rgb_convert", &cv::cuda::device::color_detail::HLS2RGBConvert,
    Arg("src"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<int(*)(int)>("lab_cbrt_b", &cv::cuda::device::color_detail::LabCbrt_b,
    Arg("i"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("rgb2_lab_convert_b", &cv::cuda::device::color_detail::RGB2LabConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<float(*)(float, const float*, int)>("spline_interpolate", &cv::cuda::device::color_detail::splineInterpolate,
    Arg("x"), Arg("tab"), Arg("n"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("rgb2_lab_convert_f", &cv::cuda::device::color_detail::RGB2LabConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("lab2_rgb_convert_f", &cv::cuda::device::color_detail::Lab2RGBConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("lab2_rgb_convert_b", &cv::cuda::device::color_detail::Lab2RGBConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("rgb2_luv_convert_f", &cv::cuda::device::color_detail::RGB2LuvConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("rgb2_luv_convert_b", &cv::cuda::device::color_detail::RGB2LuvConvert_b,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("luv2_rgb_convert_f", &cv::cuda::device::color_detail::Luv2RGBConvert_f,
    Arg("src"), Arg("dst"));
  
  rb_mCvCudaDeviceColorDetail.define_module_function<void(*)(const int&, int&)>("luv2_rgb_convert_b", &cv::cuda::device::color_detail::Luv2RGBConvert_b,
    Arg("src"), Arg("dst"));

}