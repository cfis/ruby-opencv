#include <opencv2/stitching/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;

extern "C"
void Init_Warpers()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvPyRotationWarper = define_class_under<cv::PyRotationWarper>(rb_mCv, "PyRotationWarper").
    define_constructor(Constructor<cv::PyRotationWarper, std::basic_string<char>, float>()).
    define_constructor(Constructor<cv::PyRotationWarper>()).
    define_method<cv::Point_<float>(cv::PyRotationWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point", &cv::PyRotationWarper::warpPoint).
    define_method<cv::Point_<float>(cv::PyRotationWarper::*)(const cv::Point_<float>&, const cv::_InputArray &, const cv::_InputArray &)>("warp_point_backward", &cv::PyRotationWarper::warpPointBackward).
    define_method<cv::Rect_<int>(cv::PyRotationWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("build_maps", &cv::PyRotationWarper::buildMaps).
    define_method<cv::Point_<int>(cv::PyRotationWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::_OutputArray &)>("warp", &cv::PyRotationWarper::warp).
    define_method<void(cv::PyRotationWarper::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, cv::Size_<int>, const cv::_OutputArray &)>("warp_backward", &cv::PyRotationWarper::warpBackward).
    define_method<cv::Rect_<int>(cv::PyRotationWarper::*)(cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &)>("warp_roi", &cv::PyRotationWarper::warpRoi).
    define_method<float(cv::PyRotationWarper::*)() const>("get_scale", &cv::PyRotationWarper::getScale).
    define_method<void(cv::PyRotationWarper::*)(float)>("set_scale", &cv::PyRotationWarper::setScale);
  
  Class rb_cCvWarperCreator = define_class_under<cv::WarperCreator>(rb_mCv, "WarperCreator").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::WarperCreator::*)(float) const>("create", &cv::WarperCreator::create);
  
  Class rb_cCvPlaneWarper = define_class_under<cv::PlaneWarper, cv::WarperCreator>(rb_mCv, "PlaneWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PlaneWarper::*)(float) const>("create", &cv::PlaneWarper::create);
  
  Class rb_cCvAffineWarper = define_class_under<cv::AffineWarper, cv::WarperCreator>(rb_mCv, "AffineWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::AffineWarper::*)(float) const>("create", &cv::AffineWarper::create);
  
  Class rb_cCvCylindricalWarper = define_class_under<cv::CylindricalWarper, cv::WarperCreator>(rb_mCv, "CylindricalWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CylindricalWarper::*)(float) const>("create", &cv::CylindricalWarper::create);
  
  Class rb_cCvSphericalWarper = define_class_under<cv::SphericalWarper, cv::WarperCreator>(rb_mCv, "SphericalWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::SphericalWarper::*)(float) const>("create", &cv::SphericalWarper::create);
  
  Class rb_cCvFisheyeWarper = define_class_under<cv::FisheyeWarper, cv::WarperCreator>(rb_mCv, "FisheyeWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::FisheyeWarper::*)(float) const>("create", &cv::FisheyeWarper::create);
  
  Class rb_cCvStereographicWarper = define_class_under<cv::StereographicWarper, cv::WarperCreator>(rb_mCv, "StereographicWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::StereographicWarper::*)(float) const>("create", &cv::StereographicWarper::create);
  
  Class rb_cCvCompressedRectilinearWarper = define_class_under<cv::CompressedRectilinearWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::CompressedRectilinearWarper, float, float>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CompressedRectilinearWarper::*)(float) const>("create", &cv::CompressedRectilinearWarper::create);
  
  Class rb_cCvCompressedRectilinearPortraitWarper = define_class_under<cv::CompressedRectilinearPortraitWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::CompressedRectilinearPortraitWarper, float, float>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CompressedRectilinearPortraitWarper::*)(float) const>("create", &cv::CompressedRectilinearPortraitWarper::create);
  
  Class rb_cCvPaniniWarper = define_class_under<cv::PaniniWarper, cv::WarperCreator>(rb_mCv, "PaniniWarper").
    define_constructor(Constructor<cv::PaniniWarper, float, float>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PaniniWarper::*)(float) const>("create", &cv::PaniniWarper::create);
  
  Class rb_cCvPaniniPortraitWarper = define_class_under<cv::PaniniPortraitWarper, cv::WarperCreator>(rb_mCv, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::PaniniPortraitWarper, float, float>()).
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PaniniPortraitWarper::*)(float) const>("create", &cv::PaniniPortraitWarper::create);
  
  Class rb_cCvMercatorWarper = define_class_under<cv::MercatorWarper, cv::WarperCreator>(rb_mCv, "MercatorWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::MercatorWarper::*)(float) const>("create", &cv::MercatorWarper::create);
  
  Class rb_cCvTransverseMercatorWarper = define_class_under<cv::TransverseMercatorWarper, cv::WarperCreator>(rb_mCv, "TransverseMercatorWarper").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::TransverseMercatorWarper::*)(float) const>("create", &cv::TransverseMercatorWarper::create);
  
  Class rb_cCvPlaneWarperGpu = define_class_under<cv::PlaneWarperGpu, cv::WarperCreator>(rb_mCv, "PlaneWarperGpu").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::PlaneWarperGpu::*)(float) const>("create", &cv::PlaneWarperGpu::create);
  
  Class rb_cCvCylindricalWarperGpu = define_class_under<cv::CylindricalWarperGpu, cv::WarperCreator>(rb_mCv, "CylindricalWarperGpu").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::CylindricalWarperGpu::*)(float) const>("create", &cv::CylindricalWarperGpu::create);
  
  Class rb_cCvSphericalWarperGpu = define_class_under<cv::SphericalWarperGpu, cv::WarperCreator>(rb_mCv, "SphericalWarperGpu").
    define_method<cv::Ptr<cv::detail::RotationWarper>(cv::SphericalWarperGpu::*)(float) const>("create", &cv::SphericalWarperGpu::create);
}