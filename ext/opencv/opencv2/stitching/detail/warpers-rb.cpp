#include <opencv2/stitching/detail/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename P>
inline void RotationWarperBase_builder(Data_Type_T& klass)
{
  klass.template define_method("warp_point", &cv::detail::RotationWarperBase<P>::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    template define_method("warp_point_backward", &cv::detail::RotationWarperBase<P>::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    template define_method("build_maps", &cv::detail::RotationWarperBase<P>::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    template define_method("warp", &cv::detail::RotationWarperBase<P>::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    template define_method("warp_backward", &cv::detail::RotationWarperBase<P>::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    template define_method("warp_roi", &cv::detail::RotationWarperBase<P>::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    template define_method("get_scale", &cv::detail::RotationWarperBase<P>::getScale).
    template define_method("set_scale", &cv::detail::RotationWarperBase<P>::setScale,
      Arg("val"));
};


void Init_Warpers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailRotationWarper = define_class_under<cv::detail::RotationWarper>(rb_mCvDetail, "RotationWarper").
    define_method("warp_point", &cv::detail::RotationWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("warp_point_backward", &cv::detail::RotationWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("build_maps", &cv::detail::RotationWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::RotationWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_backward", &cv::detail::RotationWarper::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    define_method("warp_roi", &cv::detail::RotationWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method("get_scale", &cv::detail::RotationWarper::getScale).
    define_method("set_scale", &cv::detail::RotationWarper::setScale,
      Arg(""));
  
  Class rb_cCvDetailProjectorBase = define_class_under<cv::detail::ProjectorBase>(rb_mCvDetail, "ProjectorBase").
    define_constructor(Constructor<cv::detail::ProjectorBase>()).
    define_method("set_camera_params", &cv::detail::ProjectorBase::setCameraParams,
      Arg("k") = static_cast<InputArray>(Mat::eye(3, 3, CV_32F)), Arg("r") = static_cast<InputArray>(Mat::eye(3, 3, CV_32F)), Arg("t") = static_cast<InputArray>(Mat::zeros(3, 1, CV_32F))).
    define_attr("scale", &cv::detail::ProjectorBase::scale);
  
  Class rb_cCvDetailPlaneProjector = define_class_under<cv::detail::PlaneProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlaneProjector").
    define_constructor(Constructor<cv::detail::PlaneProjector>()).
    define_method("map_forward", &cv::detail::PlaneProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PlaneProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailPlaneWarper = define_class_under<cv::detail::PlaneWarper, >(rb_mCvDetail, "PlaneWarper").
    define_constructor(Constructor<cv::detail::PlaneWarper, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point", &cv::detail::PlaneWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_point", &cv::detail::PlaneWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r"), Arg("t")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method<cv::Point2f(cv::detail::PlaneWarper::*)(const cv::Point2f&, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r"), Arg("t")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarper::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray)>("warp_roi", &cv::detail::PlaneWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method<cv::Rect(cv::detail::PlaneWarper::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray)>("warp_roi", &cv::detail::PlaneWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"));
  
  Class rb_cCvDetailAffineWarper = define_class_under<cv::detail::AffineWarper, cv::detail::PlaneWarper>(rb_mCvDetail, "AffineWarper").
    define_constructor(Constructor<cv::detail::AffineWarper, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method("warp_point", &cv::detail::AffineWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("h")).
    define_method("warp_point_backward", &cv::detail::AffineWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("h")).
    define_method("build_maps", &cv::detail::AffineWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("h"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::AffineWarper::warp,
      Arg("src"), Arg("k"), Arg("h"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_roi", &cv::detail::AffineWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("h"));
  
  Class rb_cCvDetailSphericalProjector = define_class_under<cv::detail::SphericalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalProjector").
    define_constructor(Constructor<cv::detail::SphericalProjector>()).
    define_method("map_forward", &cv::detail::SphericalProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::SphericalProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailSphericalWarper = define_class_under<cv::detail::SphericalWarper, >(rb_mCvDetail, "SphericalWarper").
    define_constructor(Constructor<cv::detail::SphericalWarper, float>(),
      Arg("scale")).
    define_method("build_maps", &cv::detail::SphericalWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::SphericalWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  Class rb_cCvDetailCylindricalProjector = define_class_under<cv::detail::CylindricalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalProjector").
    define_constructor(Constructor<cv::detail::CylindricalProjector>()).
    define_method("map_forward", &cv::detail::CylindricalProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CylindricalProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailCylindricalWarper = define_class_under<cv::detail::CylindricalWarper, >(rb_mCvDetail, "CylindricalWarper").
    define_constructor(Constructor<cv::detail::CylindricalWarper, float>(),
      Arg("scale")).
    define_method("build_maps", &cv::detail::CylindricalWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::detail::CylindricalWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  Class rb_cCvDetailFisheyeProjector = define_class_under<cv::detail::FisheyeProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "FisheyeProjector").
    define_constructor(Constructor<cv::detail::FisheyeProjector>()).
    define_method("map_forward", &cv::detail::FisheyeProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::FisheyeProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailFisheyeWarper = define_class_under<cv::detail::FisheyeWarper, >(rb_mCvDetail, "FisheyeWarper").
    define_constructor(Constructor<cv::detail::FisheyeWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailStereographicProjector = define_class_under<cv::detail::StereographicProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "StereographicProjector").
    define_constructor(Constructor<cv::detail::StereographicProjector>()).
    define_method("map_forward", &cv::detail::StereographicProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::StereographicProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailStereographicWarper = define_class_under<cv::detail::StereographicWarper, >(rb_mCvDetail, "StereographicWarper").
    define_constructor(Constructor<cv::detail::StereographicWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailCompressedRectilinearProjector = define_class_under<cv::detail::CompressedRectilinearProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearProjector").
    define_constructor(Constructor<cv::detail::CompressedRectilinearProjector>()).
    define_attr("a", &cv::detail::CompressedRectilinearProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearProjector::b).
    define_method("map_forward", &cv::detail::CompressedRectilinearProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CompressedRectilinearProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailCompressedRectilinearWarper = define_class_under<cv::detail::CompressedRectilinearWarper, >(rb_mCvDetail, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  Class rb_cCvDetailCompressedRectilinearPortraitProjector = define_class_under<cv::detail::CompressedRectilinearPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearPortraitProjector").
    define_constructor(Constructor<cv::detail::CompressedRectilinearPortraitProjector>()).
    define_attr("a", &cv::detail::CompressedRectilinearPortraitProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearPortraitProjector::b).
    define_method("map_forward", &cv::detail::CompressedRectilinearPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CompressedRectilinearPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailCompressedRectilinearPortraitWarper = define_class_under<cv::detail::CompressedRectilinearPortraitWarper, >(rb_mCvDetail, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearPortraitWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  Class rb_cCvDetailPaniniProjector = define_class_under<cv::detail::PaniniProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniProjector").
    define_constructor(Constructor<cv::detail::PaniniProjector>()).
    define_attr("a", &cv::detail::PaniniProjector::a).
    define_attr("b", &cv::detail::PaniniProjector::b).
    define_method("map_forward", &cv::detail::PaniniProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PaniniProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailPaniniWarper = define_class_under<cv::detail::PaniniWarper, >(rb_mCvDetail, "PaniniWarper").
    define_constructor(Constructor<cv::detail::PaniniWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  Class rb_cCvDetailPaniniPortraitProjector = define_class_under<cv::detail::PaniniPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniPortraitProjector").
    define_constructor(Constructor<cv::detail::PaniniPortraitProjector>()).
    define_attr("a", &cv::detail::PaniniPortraitProjector::a).
    define_attr("b", &cv::detail::PaniniPortraitProjector::b).
    define_method("map_forward", &cv::detail::PaniniPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PaniniPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailPaniniPortraitWarper = define_class_under<cv::detail::PaniniPortraitWarper, >(rb_mCvDetail, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::detail::PaniniPortraitWarper, float, float, float>(),
      Arg("scale"), Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1));
  
  Class rb_cCvDetailMercatorProjector = define_class_under<cv::detail::MercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "MercatorProjector").
    define_constructor(Constructor<cv::detail::MercatorProjector>()).
    define_method("map_forward", &cv::detail::MercatorProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::MercatorProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailMercatorWarper = define_class_under<cv::detail::MercatorWarper, >(rb_mCvDetail, "MercatorWarper").
    define_constructor(Constructor<cv::detail::MercatorWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailTransverseMercatorProjector = define_class_under<cv::detail::TransverseMercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "TransverseMercatorProjector").
    define_constructor(Constructor<cv::detail::TransverseMercatorProjector>()).
    define_method("map_forward", &cv::detail::TransverseMercatorProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::TransverseMercatorProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailTransverseMercatorWarper = define_class_under<cv::detail::TransverseMercatorWarper, >(rb_mCvDetail, "TransverseMercatorWarper").
    define_constructor(Constructor<cv::detail::TransverseMercatorWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailPlaneWarperGpu = define_class_under<cv::detail::PlaneWarperGpu, cv::detail::PlaneWarper>(rb_mCvDetail, "PlaneWarperGpu").
    define_constructor(Constructor<cv::detail::PlaneWarperGpu, float>(),
      Arg("scale") = static_cast<float>(1.f)).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Rect(cv::detail::PlaneWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("t"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Point(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("t"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  Class rb_cCvDetailSphericalWarperGpu = define_class_under<cv::detail::SphericalWarperGpu, cv::detail::SphericalWarper>(rb_mCvDetail, "SphericalWarperGpu").
    define_constructor(Constructor<cv::detail::SphericalWarperGpu, float>(),
      Arg("scale")).
    define_method<cv::Rect(cv::detail::SphericalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::SphericalWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::SphericalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::SphericalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::SphericalWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::SphericalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  Class rb_cCvDetailCylindricalWarperGpu = define_class_under<cv::detail::CylindricalWarperGpu, cv::detail::CylindricalWarper>(rb_mCvDetail, "CylindricalWarperGpu").
    define_constructor(Constructor<cv::detail::CylindricalWarperGpu, float>(),
      Arg("scale")).
    define_method<cv::Rect(cv::detail::CylindricalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::CylindricalWarperGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, int, int, cv::OutputArray)>("warp", &cv::detail::CylindricalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method<cv::Rect(cv::detail::CylindricalWarperGpu::*)(cv::Size, cv::InputArray, cv::InputArray, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method<cv::Point(cv::detail::CylindricalWarperGpu::*)(const cv::cuda::GpuMat&, cv::InputArray, cv::InputArray, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::CylindricalWarperGpu::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst"));
  
  Class rb_cCvDetailSphericalPortraitProjector = define_class_under<cv::detail::SphericalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalPortraitProjector").
    define_constructor(Constructor<cv::detail::SphericalPortraitProjector>()).
    define_method("map_forward", &cv::detail::SphericalPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::SphericalPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailSphericalPortraitWarper = define_class_under<cv::detail::SphericalPortraitWarper, >(rb_mCvDetail, "SphericalPortraitWarper").
    define_constructor(Constructor<cv::detail::SphericalPortraitWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailCylindricalPortraitProjector = define_class_under<cv::detail::CylindricalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalPortraitProjector").
    define_constructor(Constructor<cv::detail::CylindricalPortraitProjector>()).
    define_method("map_forward", &cv::detail::CylindricalPortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::CylindricalPortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailCylindricalPortraitWarper = define_class_under<cv::detail::CylindricalPortraitWarper, >(rb_mCvDetail, "CylindricalPortraitWarper").
    define_constructor(Constructor<cv::detail::CylindricalPortraitWarper, float>(),
      Arg("scale"));
  
  Class rb_cCvDetailPlanePortraitProjector = define_class_under<cv::detail::PlanePortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlanePortraitProjector").
    define_constructor(Constructor<cv::detail::PlanePortraitProjector>()).
    define_method("map_forward", &cv::detail::PlanePortraitProjector::mapForward,
      Arg("x"), Arg("y"), Arg("u"), Arg("v")).
    define_method("map_backward", &cv::detail::PlanePortraitProjector::mapBackward,
      Arg("u"), Arg("v"), Arg("x"), Arg("y"));
  
  Class rb_cCvDetailPlanePortraitWarper = define_class_under<cv::detail::PlanePortraitWarper, >(rb_mCvDetail, "PlanePortraitWarper").
    define_constructor(Constructor<cv::detail::PlanePortraitWarper, float>(),
      Arg("scale"));

}