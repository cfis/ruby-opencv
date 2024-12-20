#include <sstream>
#include <opencv2/stitching/detail/blenders.hpp>
#include "blenders-rb.hpp"

using namespace Rice;



void Init_Blenders()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailBlender = define_class_under<cv::detail::Blender>(rb_mCvDetail, "Blender").
    define_constructor(Constructor<cv::detail::Blender>()).
    define_singleton_function<cv::Ptr<cv::detail::Blender>(*)(int, bool)>("create_default", &cv::detail::Blender::createDefault,
      Arg("type"), Arg("try_gpu")).
    define_method<void(cv::detail::Blender::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("prepare", &cv::detail::Blender::prepare,
      Arg("corners"), Arg("sizes")).
    define_method<void(cv::detail::Blender::*)(cv::Rect)>("prepare", &cv::detail::Blender::prepare,
      Arg("dst_roi")).
    define_method<void(cv::detail::Blender::*)(cv::InputArray, cv::InputArray, cv::Point)>("feed", &cv::detail::Blender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method<void(cv::detail::Blender::*)(cv::InputOutputArray, cv::InputOutputArray)>("blend", &cv::detail::Blender::blend,
      Arg("dst"), Arg("dst_mask"));
  
  
  Class rb_cCvDetailFeatherBlender = define_class_under<cv::detail::FeatherBlender, cv::detail::Blender>(rb_mCvDetail, "FeatherBlender").
    define_constructor(Constructor<cv::detail::FeatherBlender, float>(),
      Arg("sharpness") = 0.02f).
    define_method<float(cv::detail::FeatherBlender::*)() const>("sharpness", &cv::detail::FeatherBlender::sharpness).
    define_method<void(cv::detail::FeatherBlender::*)(float)>("set_sharpness", &cv::detail::FeatherBlender::setSharpness,
      Arg("val")).
    define_method<void(cv::detail::FeatherBlender::*)(cv::Rect)>("prepare", &cv::detail::FeatherBlender::prepare,
      Arg("dst_roi")).
    define_method<void(cv::detail::FeatherBlender::*)(cv::InputArray, cv::InputArray, cv::Point)>("feed", &cv::detail::FeatherBlender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method<void(cv::detail::FeatherBlender::*)(cv::InputOutputArray, cv::InputOutputArray)>("blend", &cv::detail::FeatherBlender::blend,
      Arg("dst"), Arg("dst_mask")).
    define_method<cv::Rect(cv::detail::FeatherBlender::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("create_weight_maps", &cv::detail::FeatherBlender::createWeightMaps,
      Arg("masks"), Arg("corners"), Arg("weight_maps"));
  
  Class rb_cCvDetailMultiBandBlender = define_class_under<cv::detail::MultiBandBlender, cv::detail::Blender>(rb_mCvDetail, "MultiBandBlender").
    define_constructor(Constructor<cv::detail::MultiBandBlender, int, int, int>(),
      Arg("try_gpu"), Arg("num_bands") = 5, Arg("weight_type") = NULL).
    define_method<int(cv::detail::MultiBandBlender::*)() const>("num_bands", &cv::detail::MultiBandBlender::numBands).
    define_method<void(cv::detail::MultiBandBlender::*)(int)>("set_num_bands", &cv::detail::MultiBandBlender::setNumBands,
      Arg("val")).
    define_method<void(cv::detail::MultiBandBlender::*)(cv::Rect)>("prepare", &cv::detail::MultiBandBlender::prepare,
      Arg("dst_roi")).
    define_method<void(cv::detail::MultiBandBlender::*)(cv::InputArray, cv::InputArray, cv::Point)>("feed", &cv::detail::MultiBandBlender::feed,
      Arg("img"), Arg("mask"), Arg("tl")).
    define_method<void(cv::detail::MultiBandBlender::*)(cv::InputOutputArray, cv::InputOutputArray)>("blend", &cv::detail::MultiBandBlender::blend,
      Arg("dst"), Arg("dst_mask"));
  
  rb_mCvDetail.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray)>("normalize_using_weight_map", &cv::detail::normalizeUsingWeightMap,
    Arg("weight"), Arg("src"));
  
  rb_mCvDetail.define_module_function<void(*)(cv::InputArray, float, cv::InputOutputArray)>("create_weight_map", &cv::detail::createWeightMap,
    Arg("mask"), Arg("sharpness"), Arg("weight"));
  
  rb_mCvDetail.define_module_function<void(*)(cv::InputArray, int, std::vector<cv::UMat>&)>("create_laplace_pyr", &cv::detail::createLaplacePyr,
    Arg("img"), Arg("num_levels"), Arg("pyr"));
  
  rb_mCvDetail.define_module_function<void(*)(cv::InputArray, int, std::vector<cv::UMat>&)>("create_laplace_pyr_gpu", &cv::detail::createLaplacePyrGpu,
    Arg("img"), Arg("num_levels"), Arg("pyr"));
  
  rb_mCvDetail.define_module_function<void(*)(std::vector<cv::UMat>&)>("restore_image_from_laplace_pyr", &cv::detail::restoreImageFromLaplacePyr,
    Arg("pyr"));
  
  rb_mCvDetail.define_module_function<void(*)(std::vector<cv::UMat>&)>("restore_image_from_laplace_pyr_gpu", &cv::detail::restoreImageFromLaplacePyrGpu,
    Arg("pyr"));

}