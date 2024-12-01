#include <opencv2/cudaarithm.hpp>
#include "cudaarithm-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudaarithm()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, int, cv::cuda::Stream&)>("add", &cv::cuda::add);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, int, cv::cuda::Stream&)>("subtract", &cv::cuda::subtract);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, int, cv::cuda::Stream&)>("multiply", &cv::cuda::multiply);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, int, cv::cuda::Stream&)>("divide", &cv::cuda::divide);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("absdiff", &cv::cuda::absdiff);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("abs", &cv::cuda::abs);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("sqr", &cv::cuda::sqr);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("sqrt", &cv::cuda::sqrt);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("exp", &cv::cuda::exp);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("log", &cv::cuda::log);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, double, const cv::_OutputArray &, cv::cuda::Stream&)>("pow", &cv::cuda::pow);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, cv::cuda::Stream&)>("compare", &cv::cuda::compare);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("bitwise_not", &cv::cuda::bitwise_not);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("bitwise_or", &cv::cuda::bitwise_or);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("bitwise_and", &cv::cuda::bitwise_and);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("bitwise_xor", &cv::cuda::bitwise_xor);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<int>, const cv::_OutputArray &, cv::cuda::Stream&)>("rshift", &cv::cuda::rshift);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<double>, const cv::_OutputArray &, cv::cuda::Stream&)>("rshift", &cv::cuda::rshift);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<int>, const cv::_OutputArray &, cv::cuda::Stream&)>("lshift", &cv::cuda::lshift);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<double>, const cv::_OutputArray &, cv::cuda::Stream&)>("lshift", &cv::cuda::lshift);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("min", &cv::cuda::min);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("max", &cv::cuda::max);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, double, const cv::_InputArray &, double, double, const cv::_OutputArray &, int, cv::cuda::Stream&)>("add_weighted", &cv::cuda::addWeighted);
  
  rb_mCvCuda.define_module_function<double(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, cv::cuda::Stream&)>("threshold", &cv::cuda::threshold);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::Scalar_<double>&, const cv::Scalar_<double>&, const cv::_OutputArray &, cv::cuda::Stream&)>("in_range", &cv::cuda::inRange);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("magnitude", &cv::cuda::magnitude);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("magnitude_sqr", &cv::cuda::magnitudeSqr);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("magnitude", &cv::cuda::magnitude);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("magnitude_sqr", &cv::cuda::magnitudeSqr);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("phase", &cv::cuda::phase);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("cart_to_polar", &cv::cuda::cartToPolar);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("polar_to_cart", &cv::cuda::polarToCart);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat*, unsigned long long, const cv::_OutputArray &, cv::cuda::Stream&)>("merge", &cv::cuda::merge);
  
  rb_mCvCuda.define_module_function<void(*)(const std::vector<cv::cuda::GpuMat>&, const cv::_OutputArray &, cv::cuda::Stream&)>("merge", &cv::cuda::merge);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::cuda::GpuMat*, cv::cuda::Stream&)>("split", &cv::cuda::split);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("split", &cv::cuda::split);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("transpose", &cv::cuda::transpose);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, cv::cuda::Stream&)>("flip", &cv::cuda::flip);
  
  Class rb_cCvCudaLookUpTable = define_class_under<cv::cuda::LookUpTable, cv::Algorithm>(rb_mCvCuda, "LookUpTable").
    define_method<void(cv::cuda::LookUpTable::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("transform", &cv::cuda::LookUpTable::transform);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::LookUpTable>(*)(const cv::_InputArray &)>("create_look_up_table", &cv::cuda::createLookUpTable);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, int, int, cv::Scalar_<double>, cv::cuda::Stream&)>("copy_make_border", &cv::cuda::copyMakeBorder);
  
  rb_mCvCuda.define_module_function<double(*)(const cv::_InputArray &, int, const cv::_InputArray &)>("norm", &cv::cuda::norm);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, cv::cuda::Stream&)>("calc_norm", &cv::cuda::calcNorm);
  
  rb_mCvCuda.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, int)>("norm", &cv::cuda::norm);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, cv::cuda::Stream&)>("calc_norm_diff", &cv::cuda::calcNormDiff);
  
  rb_mCvCuda.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &)>("sum", &cv::cuda::sum);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("calc_sum", &cv::cuda::calcSum);
  
  rb_mCvCuda.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &)>("abs_sum", &cv::cuda::absSum);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("calc_abs_sum", &cv::cuda::calcAbsSum);
  
  rb_mCvCuda.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &)>("sqr_sum", &cv::cuda::sqrSum);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("calc_sqr_sum", &cv::cuda::calcSqrSum);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, double*, double*, const cv::_InputArray &)>("min_max", &cv::cuda::minMax);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("find_min_max", &cv::cuda::findMinMax);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, double*, double*, cv::Point_<int>*, cv::Point_<int>*, const cv::_InputArray &)>("min_max_loc", &cv::cuda::minMaxLoc);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("find_min_max_loc", &cv::cuda::findMinMaxLoc);
  
  rb_mCvCuda.define_module_function<int(*)(const cv::_InputArray &)>("count_non_zero", &cv::cuda::countNonZero);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("count_non_zero", &cv::cuda::countNonZero);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, cv::cuda::Stream&)>("reduce", &cv::cuda::reduce);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("mean_std_dev", &cv::cuda::meanStdDev);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("mean_std_dev", &cv::cuda::meanStdDev);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<double>&, cv::Scalar_<double>&, const cv::_InputArray &)>("mean_std_dev", &cv::cuda::meanStdDev);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, cv::Scalar_<double>&, cv::Scalar_<double>&)>("mean_std_dev", &cv::cuda::meanStdDev);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::Rect_<int>, cv::cuda::Stream&)>("rect_std_dev", &cv::cuda::rectStdDev);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, int, const cv::_InputArray &, cv::cuda::Stream&)>("normalize", &cv::cuda::normalize);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("integral", &cv::cuda::integral);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("sqr_integral", &cv::cuda::sqrIntegral);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, double, const cv::_InputArray &, double, const cv::_OutputArray &, int, cv::cuda::Stream&)>("gemm", &cv::cuda::gemm);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, bool, cv::cuda::Stream&)>("mul_spectrums", &cv::cuda::mulSpectrums);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, float, bool, cv::cuda::Stream&)>("mul_and_scale_spectrums", &cv::cuda::mulAndScaleSpectrums);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, int, cv::cuda::Stream&)>("dft", &cv::cuda::dft);
  
  Class rb_cCvCudaDFT = define_class_under<cv::cuda::DFT, cv::Algorithm>(rb_mCvCuda, "DFT").
    define_method<void(cv::cuda::DFT::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::DFT::compute);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::DFT>(*)(cv::Size_<int>, int)>("create_dft", &cv::cuda::createDFT);
  
  Class rb_cCvCudaConvolution = define_class_under<cv::cuda::Convolution, cv::Algorithm>(rb_mCvCuda, "Convolution").
    define_method<void(cv::cuda::Convolution::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("convolve", &cv::cuda::Convolution::convolve);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Convolution>(*)(cv::Size_<int>)>("create_convolution", &cv::cuda::createConvolution);
}