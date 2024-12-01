#include <opencv2/stitching/detail/blenders.hpp>
#include "blenders-rb.hpp"

using namespace Rice;

extern "C"
void Init_Blenders()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailBlender = define_class_under<cv::detail::Blender>(rb_mCvDetail, "Blender").
    define_singleton_function<cv::Ptr<cv::detail::Blender>(*)(int, bool)>("create_default", &cv::detail::Blender::createDefault).
    define_method<void(cv::detail::Blender::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("prepare", &cv::detail::Blender::prepare).
    define_method<void(cv::detail::Blender::*)(cv::Rect_<int>)>("prepare", &cv::detail::Blender::prepare).
    define_method<void(cv::detail::Blender::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>)>("feed", &cv::detail::Blender::feed).
    define_method<void(cv::detail::Blender::*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &)>("blend", &cv::detail::Blender::blend);
  
  
  Class rb_cCvDetailFeatherBlender = define_class_under<cv::detail::FeatherBlender, cv::detail::Blender>(rb_mCvDetail, "FeatherBlender").
    define_constructor(Constructor<cv::detail::FeatherBlender, float>()).
    define_method<float(cv::detail::FeatherBlender::*)() const>("sharpness", &cv::detail::FeatherBlender::sharpness).
    define_method<void(cv::detail::FeatherBlender::*)(float)>("set_sharpness", &cv::detail::FeatherBlender::setSharpness).
    define_method<void(cv::detail::FeatherBlender::*)(cv::Rect_<int>)>("prepare", &cv::detail::FeatherBlender::prepare).
    define_method<void(cv::detail::FeatherBlender::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>)>("feed", &cv::detail::FeatherBlender::feed).
    define_method<void(cv::detail::FeatherBlender::*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &)>("blend", &cv::detail::FeatherBlender::blend).
    define_method<cv::Rect_<int>(cv::detail::FeatherBlender::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("create_weight_maps", &cv::detail::FeatherBlender::createWeightMaps);
  
  Class rb_cCvDetailMultiBandBlender = define_class_under<cv::detail::MultiBandBlender, cv::detail::Blender>(rb_mCvDetail, "MultiBandBlender").
    define_constructor(Constructor<cv::detail::MultiBandBlender, int, int, int>()).
    define_method<int(cv::detail::MultiBandBlender::*)() const>("num_bands", &cv::detail::MultiBandBlender::numBands).
    define_method<void(cv::detail::MultiBandBlender::*)(int)>("set_num_bands", &cv::detail::MultiBandBlender::setNumBands).
    define_method<void(cv::detail::MultiBandBlender::*)(cv::Rect_<int>)>("prepare", &cv::detail::MultiBandBlender::prepare).
    define_method<void(cv::detail::MultiBandBlender::*)(const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>)>("feed", &cv::detail::MultiBandBlender::feed).
    define_method<void(cv::detail::MultiBandBlender::*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &)>("blend", &cv::detail::MultiBandBlender::blend);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &)>("normalize_using_weight_map", &cv::detail::normalizeUsingWeightMap);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::_InputArray &, float, const cv::_InputOutputArray &)>("create_weight_map", &cv::detail::createWeightMap);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::_InputArray &, int, std::vector<cv::UMat>&)>("create_laplace_pyr", &cv::detail::createLaplacePyr);
  
  rb_mCvDetail.define_module_function<void(*)(const cv::_InputArray &, int, std::vector<cv::UMat>&)>("create_laplace_pyr_gpu", &cv::detail::createLaplacePyrGpu);
  
  rb_mCvDetail.define_module_function<void(*)(std::vector<cv::UMat>&)>("restore_image_from_laplace_pyr", &cv::detail::restoreImageFromLaplacePyr);
  
  rb_mCvDetail.define_module_function<void(*)(std::vector<cv::UMat>&)>("restore_image_from_laplace_pyr_gpu", &cv::detail::restoreImageFromLaplacePyrGpu);
}