#include <opencv2/surface_matching/ppf_match_3d.hpp>
#include "ppf_match_3d-rb.hpp"

using namespace Rice;

extern "C"
void Init_PpfMatch3d()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");
  
  Class rb_cCvPpfMatch3dTHash = define_class_under<cv::ppf_match_3d::THash>(rb_mCvPpfMatch3d, "THash").
    define_attr("id", &cv::ppf_match_3d::THash::id).
    define_attr("i", &cv::ppf_match_3d::THash::i).
    define_attr("ppf_ind", &cv::ppf_match_3d::THash::ppfInd);
  
  Class rb_cCvPpfMatch3dPPF3DDetector = define_class_under<cv::ppf_match_3d::PPF3DDetector>(rb_mCvPpfMatch3d, "PPF3DDetector").
    define_constructor(Constructor<cv::ppf_match_3d::PPF3DDetector>()).
    define_constructor(Constructor<cv::ppf_match_3d::PPF3DDetector, const double, const double, const double>()).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const double, const double, const bool)>("set_search_params", &cv::ppf_match_3d::PPF3DDetector::setSearchParams).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const cv::Mat&)>("train_model", &cv::ppf_match_3d::PPF3DDetector::trainModel).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const cv::Mat&, std::vector<cv::Ptr<cv::ppf_match_3d::Pose3D>>&, const double, const double)>("match", &cv::ppf_match_3d::PPF3DDetector::match).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(const cv::FileNode&)>("read", &cv::ppf_match_3d::PPF3DDetector::read).
    define_method<void(cv::ppf_match_3d::PPF3DDetector::*)(cv::FileStorage&) const>("write", &cv::ppf_match_3d::PPF3DDetector::write);
}