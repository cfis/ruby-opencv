#include <opencv2/cudafilters.hpp>
#include "cudafilters-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudafilters()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaFilter = define_class_under<cv::cuda::Filter, cv::Algorithm>(rb_mCvCuda, "Filter").
    define_method<void(cv::cuda::Filter::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("apply", &cv::cuda::Filter::apply);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, cv::Size_<int>, cv::Point_<int>, int, cv::Scalar_<double>)>("create_box_filter", &cv::cuda::createBoxFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, const cv::_InputArray &, cv::Point_<int>, int, cv::Scalar_<double>)>("create_linear_filter", &cv::cuda::createLinearFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, double, int, cv::Scalar_<double>)>("create_laplacian_filter", &cv::cuda::createLaplacianFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>, int, int)>("create_separable_linear_filter", &cv::cuda::createSeparableLinearFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, int, int, bool, double, int, int)>("create_deriv_filter", &cv::cuda::createDerivFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, int, int, double, int, int)>("create_sobel_filter", &cv::cuda::createSobelFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, int, double, int, int)>("create_scharr_filter", &cv::cuda::createScharrFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, cv::Size_<int>, double, double, int, int)>("create_gaussian_filter", &cv::cuda::createGaussianFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, const cv::_InputArray &, cv::Point_<int>, int)>("create_morphology_filter", &cv::cuda::createMorphologyFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, cv::Size_<int>, cv::Point_<int>, int, cv::Scalar_<double>)>("create_box_max_filter", &cv::cuda::createBoxMaxFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, cv::Size_<int>, cv::Point_<int>, int, cv::Scalar_<double>)>("create_box_min_filter", &cv::cuda::createBoxMinFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, int, int, cv::Scalar_<double>)>("create_row_sum_filter", &cv::cuda::createRowSumFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int, int, int, cv::Scalar_<double>)>("create_column_sum_filter", &cv::cuda::createColumnSumFilter);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::Filter>(*)(int, int, int)>("create_median_filter", &cv::cuda::createMedianFilter);
}