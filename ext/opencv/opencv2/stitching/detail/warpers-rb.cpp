#include <opencv2/stitching/detail/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;

extern "C"
void Init_Warpers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailRotationWarper = define_class_under<cv::detail::RotationWarper>(rb_mCvDetail, "RotationWarper").
    define_method<cv::Point_<float>(cv::detail::RotationWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point", &cv::detail::RotationWarper::warpPoint).
    define_method<cv::Point_<float>(cv::detail::RotationWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point_backward", &cv::detail::RotationWarper::warpPointBackward).
    define_method<cv::Rect_<int>(cv::detail::RotationWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::RotationWarper::buildMaps).
    define_method<cv::Point_<int>(cv::detail::RotationWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::RotationWarper::warp).
    define_method<void(cv::detail::RotationWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::Size_<int>, const cv::_OutputArray &)>("warp_backward", &cv::detail::RotationWarper::warpBackward).
    define_method<cv::Rect_<int>(cv::detail::RotationWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &)>("warp_roi", &cv::detail::RotationWarper::warpRoi).
    define_method<float(cv::detail::RotationWarper::*)() const>("get_scale", &cv::detail::RotationWarper::getScale).
    define_method<void(cv::detail::RotationWarper::*)(float)>("set_scale", &cv::detail::RotationWarper::setScale);
  
  Class rb_cCvDetailProjectorBase = define_class_under<cv::detail::ProjectorBase>(rb_mCvDetail, "ProjectorBase").
    define_method<void(cv::detail::ProjectorBase::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("set_camera_params", &cv::detail::ProjectorBase::setCameraParams).
    define_attr("scale", &cv::detail::ProjectorBase::scale).
    define_attr("k", &cv::detail::ProjectorBase::k).
    define_attr("rinv", &cv::detail::ProjectorBase::rinv).
    define_attr("r_kinv", &cv::detail::ProjectorBase::r_kinv).
    define_attr("k_rinv", &cv::detail::ProjectorBase::k_rinv).
    define_attr("t", &cv::detail::ProjectorBase::t);
  
  Class rb_cCvDetailPlaneProjector = define_class_under<cv::detail::PlaneProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlaneProjector").
    define_method<void(cv::detail::PlaneProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::PlaneProjector::mapForward).
    define_method<void(cv::detail::PlaneProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::PlaneProjector::mapBackward);
  
  Class rb_cCvDetailPlaneWarper = define_class_under<cv::detail::PlaneWarper, >(rb_mCvDetail, "PlaneWarper").
    define_constructor(Constructor<cv::detail::PlaneWarper, float>()).
    define_method<cv::Point_<float>(cv::detail::PlaneWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point", &cv::detail::PlaneWarper::warpPoint).
    define_method<cv::Point_<float>(cv::detail::PlaneWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("warp_point", &cv::detail::PlaneWarper::warpPoint).
    define_method<cv::Point_<float>(cv::detail::PlaneWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward).
    define_method<cv::Point_<float>(cv::detail::PlaneWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("warp_point_backward", &cv::detail::PlaneWarper::warpPointBackward).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::PlaneWarper::buildMaps).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::PlaneWarper::buildMaps).
    define_method<cv::Point_<int>(cv::detail::PlaneWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::PlaneWarper::warp).
    define_method<cv::Point_<int>(cv::detail::PlaneWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::PlaneWarper::warp).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &)>("warp_roi", &cv::detail::PlaneWarper::warpRoi).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("warp_roi", &cv::detail::PlaneWarper::warpRoi);
  
  Class rb_cCvDetailAffineWarper = define_class_under<cv::detail::AffineWarper, cv::detail::PlaneWarper>(rb_mCvDetail, "AffineWarper").
    define_constructor(Constructor<cv::detail::AffineWarper, float>()).
    define_method<cv::Point_<float>(cv::detail::AffineWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point", &cv::detail::AffineWarper::warpPoint).
    define_method<cv::Point_<float>(cv::detail::AffineWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point_backward", &cv::detail::AffineWarper::warpPointBackward).
    define_method<cv::Rect_<int>(cv::detail::AffineWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::AffineWarper::buildMaps).
    define_method<cv::Point_<int>(cv::detail::AffineWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::AffineWarper::warp).
    define_method<cv::Rect_<int>(cv::detail::AffineWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &)>("warp_roi", &cv::detail::AffineWarper::warpRoi);
  
  Class rb_cCvDetailSphericalProjector = define_class_under<cv::detail::SphericalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalProjector").
    define_method<void(cv::detail::SphericalProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::SphericalProjector::mapForward).
    define_method<void(cv::detail::SphericalProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::SphericalProjector::mapBackward);
  
  Class rb_cCvDetailSphericalWarper = define_class_under<cv::detail::SphericalWarper, >(rb_mCvDetail, "SphericalWarper").
    define_constructor(Constructor<cv::detail::SphericalWarper, float>()).
    define_method<cv::Rect_<int>(cv::detail::SphericalWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::SphericalWarper::buildMaps).
    define_method<cv::Point_<int>(cv::detail::SphericalWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::SphericalWarper::warp);
  
  Class rb_cCvDetailCylindricalProjector = define_class_under<cv::detail::CylindricalProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalProjector").
    define_method<void(cv::detail::CylindricalProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::CylindricalProjector::mapForward).
    define_method<void(cv::detail::CylindricalProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::CylindricalProjector::mapBackward);
  
  Class rb_cCvDetailCylindricalWarper = define_class_under<cv::detail::CylindricalWarper, >(rb_mCvDetail, "CylindricalWarper").
    define_constructor(Constructor<cv::detail::CylindricalWarper, float>()).
    define_method<cv::Rect_<int>(cv::detail::CylindricalWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::CylindricalWarper::buildMaps).
    define_method<cv::Point_<int>(cv::detail::CylindricalWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::CylindricalWarper::warp);
  
  Class rb_cCvDetailFisheyeProjector = define_class_under<cv::detail::FisheyeProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "FisheyeProjector").
    define_method<void(cv::detail::FisheyeProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::FisheyeProjector::mapForward).
    define_method<void(cv::detail::FisheyeProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::FisheyeProjector::mapBackward);
  
  Class rb_cCvDetailFisheyeWarper = define_class_under<cv::detail::FisheyeWarper, >(rb_mCvDetail, "FisheyeWarper").
    define_constructor(Constructor<cv::detail::FisheyeWarper, float>());
  
  Class rb_cCvDetailStereographicProjector = define_class_under<cv::detail::StereographicProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "StereographicProjector").
    define_method<void(cv::detail::StereographicProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::StereographicProjector::mapForward).
    define_method<void(cv::detail::StereographicProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::StereographicProjector::mapBackward);
  
  Class rb_cCvDetailStereographicWarper = define_class_under<cv::detail::StereographicWarper, >(rb_mCvDetail, "StereographicWarper").
    define_constructor(Constructor<cv::detail::StereographicWarper, float>());
  
  Class rb_cCvDetailCompressedRectilinearProjector = define_class_under<cv::detail::CompressedRectilinearProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearProjector").
    define_attr("a", &cv::detail::CompressedRectilinearProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearProjector::b).
    define_method<void(cv::detail::CompressedRectilinearProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::CompressedRectilinearProjector::mapForward).
    define_method<void(cv::detail::CompressedRectilinearProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::CompressedRectilinearProjector::mapBackward);
  
  Class rb_cCvDetailCompressedRectilinearWarper = define_class_under<cv::detail::CompressedRectilinearWarper, >(rb_mCvDetail, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearWarper, float, float, float>());
  
  Class rb_cCvDetailCompressedRectilinearPortraitProjector = define_class_under<cv::detail::CompressedRectilinearPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CompressedRectilinearPortraitProjector").
    define_attr("a", &cv::detail::CompressedRectilinearPortraitProjector::a).
    define_attr("b", &cv::detail::CompressedRectilinearPortraitProjector::b).
    define_method<void(cv::detail::CompressedRectilinearPortraitProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::CompressedRectilinearPortraitProjector::mapForward).
    define_method<void(cv::detail::CompressedRectilinearPortraitProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::CompressedRectilinearPortraitProjector::mapBackward);
  
  Class rb_cCvDetailCompressedRectilinearPortraitWarper = define_class_under<cv::detail::CompressedRectilinearPortraitWarper, >(rb_mCvDetail, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::detail::CompressedRectilinearPortraitWarper, float, float, float>());
  
  Class rb_cCvDetailPaniniProjector = define_class_under<cv::detail::PaniniProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniProjector").
    define_attr("a", &cv::detail::PaniniProjector::a).
    define_attr("b", &cv::detail::PaniniProjector::b).
    define_method<void(cv::detail::PaniniProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::PaniniProjector::mapForward).
    define_method<void(cv::detail::PaniniProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::PaniniProjector::mapBackward);
  
  Class rb_cCvDetailPaniniWarper = define_class_under<cv::detail::PaniniWarper, >(rb_mCvDetail, "PaniniWarper").
    define_constructor(Constructor<cv::detail::PaniniWarper, float, float, float>());
  
  Class rb_cCvDetailPaniniPortraitProjector = define_class_under<cv::detail::PaniniPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PaniniPortraitProjector").
    define_attr("a", &cv::detail::PaniniPortraitProjector::a).
    define_attr("b", &cv::detail::PaniniPortraitProjector::b).
    define_method<void(cv::detail::PaniniPortraitProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::PaniniPortraitProjector::mapForward).
    define_method<void(cv::detail::PaniniPortraitProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::PaniniPortraitProjector::mapBackward);
  
  Class rb_cCvDetailPaniniPortraitWarper = define_class_under<cv::detail::PaniniPortraitWarper, >(rb_mCvDetail, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::detail::PaniniPortraitWarper, float, float, float>());
  
  Class rb_cCvDetailMercatorProjector = define_class_under<cv::detail::MercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "MercatorProjector").
    define_method<void(cv::detail::MercatorProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::MercatorProjector::mapForward).
    define_method<void(cv::detail::MercatorProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::MercatorProjector::mapBackward);
  
  Class rb_cCvDetailMercatorWarper = define_class_under<cv::detail::MercatorWarper, >(rb_mCvDetail, "MercatorWarper").
    define_constructor(Constructor<cv::detail::MercatorWarper, float>());
  
  Class rb_cCvDetailTransverseMercatorProjector = define_class_under<cv::detail::TransverseMercatorProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "TransverseMercatorProjector").
    define_method<void(cv::detail::TransverseMercatorProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::TransverseMercatorProjector::mapForward).
    define_method<void(cv::detail::TransverseMercatorProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::TransverseMercatorProjector::mapBackward);
  
  Class rb_cCvDetailTransverseMercatorWarper = define_class_under<cv::detail::TransverseMercatorWarper, >(rb_mCvDetail, "TransverseMercatorWarper").
    define_constructor(Constructor<cv::detail::TransverseMercatorWarper, float>());
  
  Class rb_cCvDetailPlaneWarperGpu = define_class_under<cv::detail::PlaneWarperGpu, cv::detail::PlaneWarper>(rb_mCvDetail, "PlaneWarperGpu").
    define_constructor(Constructor<cv::detail::PlaneWarperGpu, float>()).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::PlaneWarperGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::PlaneWarperGpu::warp).
    define_method<cv::Point_<int>(cv::detail::PlaneWarperGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::PlaneWarperGpu::warp).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps).
    define_method<cv::Rect_<int>(cv::detail::PlaneWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::PlaneWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp).
    define_method<cv::Point_<int>(cv::detail::PlaneWarperGpu::*)(const cv::cuda::GpuMat&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::PlaneWarperGpu::warp);
  
  Class rb_cCvDetailSphericalWarperGpu = define_class_under<cv::detail::SphericalWarperGpu, cv::detail::SphericalWarper>(rb_mCvDetail, "SphericalWarperGpu").
    define_constructor(Constructor<cv::detail::SphericalWarperGpu, float>()).
    define_method<cv::Rect_<int>(cv::detail::SphericalWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::SphericalWarperGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::SphericalWarperGpu::warp).
    define_method<cv::Rect_<int>(cv::detail::SphericalWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::SphericalWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::SphericalWarperGpu::*)(const cv::cuda::GpuMat&, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::SphericalWarperGpu::warp);
  
  Class rb_cCvDetailCylindricalWarperGpu = define_class_under<cv::detail::CylindricalWarperGpu, cv::detail::CylindricalWarper>(rb_mCvDetail, "CylindricalWarperGpu").
    define_constructor(Constructor<cv::detail::CylindricalWarperGpu, float>()).
    define_method<cv::Rect_<int>(cv::detail::CylindricalWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::CylindricalWarperGpu::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::detail::CylindricalWarperGpu::warp).
    define_method<cv::Rect_<int>(cv::detail::CylindricalWarperGpu::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("build_maps", &cv::detail::CylindricalWarperGpu::buildMaps).
    define_method<cv::Point_<int>(cv::detail::CylindricalWarperGpu::*)(const cv::cuda::GpuMat&, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::cuda::GpuMat&)>("warp", &cv::detail::CylindricalWarperGpu::warp);
  
  Class rb_cCvDetailSphericalPortraitProjector = define_class_under<cv::detail::SphericalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "SphericalPortraitProjector").
    define_method<void(cv::detail::SphericalPortraitProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::SphericalPortraitProjector::mapForward).
    define_method<void(cv::detail::SphericalPortraitProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::SphericalPortraitProjector::mapBackward);
  
  Class rb_cCvDetailSphericalPortraitWarper = define_class_under<cv::detail::SphericalPortraitWarper, >(rb_mCvDetail, "SphericalPortraitWarper").
    define_constructor(Constructor<cv::detail::SphericalPortraitWarper, float>());
  
  Class rb_cCvDetailCylindricalPortraitProjector = define_class_under<cv::detail::CylindricalPortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "CylindricalPortraitProjector").
    define_method<void(cv::detail::CylindricalPortraitProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::CylindricalPortraitProjector::mapForward).
    define_method<void(cv::detail::CylindricalPortraitProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::CylindricalPortraitProjector::mapBackward);
  
  Class rb_cCvDetailCylindricalPortraitWarper = define_class_under<cv::detail::CylindricalPortraitWarper, >(rb_mCvDetail, "CylindricalPortraitWarper").
    define_constructor(Constructor<cv::detail::CylindricalPortraitWarper, float>());
  
  Class rb_cCvDetailPlanePortraitProjector = define_class_under<cv::detail::PlanePortraitProjector, cv::detail::ProjectorBase>(rb_mCvDetail, "PlanePortraitProjector").
    define_method<void(cv::detail::PlanePortraitProjector::*)(float, float, float&, float&)>("map_forward", &cv::detail::PlanePortraitProjector::mapForward).
    define_method<void(cv::detail::PlanePortraitProjector::*)(float, float, float&, float&)>("map_backward", &cv::detail::PlanePortraitProjector::mapBackward);
  
  Class rb_cCvDetailPlanePortraitWarper = define_class_under<cv::detail::PlanePortraitWarper, >(rb_mCvDetail, "PlanePortraitWarper").
    define_constructor(Constructor<cv::detail::PlanePortraitWarper, float>());
}