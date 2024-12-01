#include <opencv2/surface_matching/icp.hpp>
#include "icp-rb.hpp"

using namespace Rice;

extern "C"
void Init_Icp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");
  
  Class rb_cCvPpfMatch3dICP = define_class_under<cv::ppf_match_3d::ICP>(rb_mCvPpfMatch3d, "ICP").
    define_constructor(Constructor<cv::ppf_match_3d::ICP>()).
    define_constructor(Constructor<cv::ppf_match_3d::ICP, const int, const float, const float, const int, const int, const int>()).
    define_method<int(cv::ppf_match_3d::ICP::*)(const cv::Mat&, const cv::Mat&, double&, cv::Matx<double, 4, 4>&)>("register_model_to_scene", &cv::ppf_match_3d::ICP::registerModelToScene).
    define_method<int(cv::ppf_match_3d::ICP::*)(const cv::Mat&, const cv::Mat&, std::vector<cv::Ptr<cv::ppf_match_3d::Pose3D>>&)>("register_model_to_scene", &cv::ppf_match_3d::ICP::registerModelToScene);
}