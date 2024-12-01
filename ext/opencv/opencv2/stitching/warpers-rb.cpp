#include <opencv2/stitching/warpers.hpp>
#include "warpers-rb.hpp"

using namespace Rice;



void Init_Warpers()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvPyRotationWarper = define_class_under<cv::PyRotationWarper>(rb_mCv, "PyRotationWarper").
    define_constructor(Constructor<cv::PyRotationWarper, cv::String, float>(),
      Arg("type"), Arg("scale")).
    define_constructor(Constructor<cv::PyRotationWarper>()).
    define_method("warp_point", &cv::PyRotationWarper::warpPoint,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("warp_point_backward", &cv::PyRotationWarper::warpPointBackward,
      Arg("pt"), Arg("k"), Arg("r")).
    define_method("build_maps", &cv::PyRotationWarper::buildMaps,
      Arg("src_size"), Arg("k"), Arg("r"), Arg("xmap"), Arg("ymap")).
    define_method("warp", &cv::PyRotationWarper::warp,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst")).
    define_method("warp_backward", &cv::PyRotationWarper::warpBackward,
      Arg("src"), Arg("k"), Arg("r"), Arg("interp_mode"), Arg("border_mode"), Arg("dst_size"), Arg("dst")).
    define_method("warp_roi", &cv::PyRotationWarper::warpRoi,
      Arg("src_size"), Arg("k"), Arg("r")).
    define_method("get_scale", &cv::PyRotationWarper::getScale).
    define_method("set_scale", &cv::PyRotationWarper::setScale,
      Arg(""));
  
  Class rb_cCvWarperCreator = define_class_under<cv::WarperCreator>(rb_mCv, "WarperCreator").
    define_method("create", &cv::WarperCreator::create,
      Arg("scale"));
  
  Class rb_cCvPlaneWarper = define_class_under<cv::PlaneWarper, cv::WarperCreator>(rb_mCv, "PlaneWarper").
    define_constructor(Constructor<cv::PlaneWarper>()).
    define_method("create", &cv::PlaneWarper::create,
      Arg("scale"));
  
  Class rb_cCvAffineWarper = define_class_under<cv::AffineWarper, cv::WarperCreator>(rb_mCv, "AffineWarper").
    define_constructor(Constructor<cv::AffineWarper>()).
    define_method("create", &cv::AffineWarper::create,
      Arg("scale"));
  
  Class rb_cCvCylindricalWarper = define_class_under<cv::CylindricalWarper, cv::WarperCreator>(rb_mCv, "CylindricalWarper").
    define_constructor(Constructor<cv::CylindricalWarper>()).
    define_method("create", &cv::CylindricalWarper::create,
      Arg("scale"));
  
  Class rb_cCvSphericalWarper = define_class_under<cv::SphericalWarper, cv::WarperCreator>(rb_mCv, "SphericalWarper").
    define_constructor(Constructor<cv::SphericalWarper>()).
    define_method("create", &cv::SphericalWarper::create,
      Arg("scale"));
  
  Class rb_cCvFisheyeWarper = define_class_under<cv::FisheyeWarper, cv::WarperCreator>(rb_mCv, "FisheyeWarper").
    define_constructor(Constructor<cv::FisheyeWarper>()).
    define_method("create", &cv::FisheyeWarper::create,
      Arg("scale"));
  
  Class rb_cCvStereographicWarper = define_class_under<cv::StereographicWarper, cv::WarperCreator>(rb_mCv, "StereographicWarper").
    define_constructor(Constructor<cv::StereographicWarper>()).
    define_method("create", &cv::StereographicWarper::create,
      Arg("scale"));
  
  Class rb_cCvCompressedRectilinearWarper = define_class_under<cv::CompressedRectilinearWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearWarper").
    define_constructor(Constructor<cv::CompressedRectilinearWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method("create", &cv::CompressedRectilinearWarper::create,
      Arg("scale"));
  
  Class rb_cCvCompressedRectilinearPortraitWarper = define_class_under<cv::CompressedRectilinearPortraitWarper, cv::WarperCreator>(rb_mCv, "CompressedRectilinearPortraitWarper").
    define_constructor(Constructor<cv::CompressedRectilinearPortraitWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method("create", &cv::CompressedRectilinearPortraitWarper::create,
      Arg("scale"));
  
  Class rb_cCvPaniniWarper = define_class_under<cv::PaniniWarper, cv::WarperCreator>(rb_mCv, "PaniniWarper").
    define_constructor(Constructor<cv::PaniniWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method("create", &cv::PaniniWarper::create,
      Arg("scale"));
  
  Class rb_cCvPaniniPortraitWarper = define_class_under<cv::PaniniPortraitWarper, cv::WarperCreator>(rb_mCv, "PaniniPortraitWarper").
    define_constructor(Constructor<cv::PaniniPortraitWarper, float, float>(),
      Arg("a") = static_cast<float>(1), Arg("b") = static_cast<float>(1)).
    define_method("create", &cv::PaniniPortraitWarper::create,
      Arg("scale"));
  
  Class rb_cCvMercatorWarper = define_class_under<cv::MercatorWarper, cv::WarperCreator>(rb_mCv, "MercatorWarper").
    define_constructor(Constructor<cv::MercatorWarper>()).
    define_method("create", &cv::MercatorWarper::create,
      Arg("scale"));
  
  Class rb_cCvTransverseMercatorWarper = define_class_under<cv::TransverseMercatorWarper, cv::WarperCreator>(rb_mCv, "TransverseMercatorWarper").
    define_constructor(Constructor<cv::TransverseMercatorWarper>()).
    define_method("create", &cv::TransverseMercatorWarper::create,
      Arg("scale"));

}