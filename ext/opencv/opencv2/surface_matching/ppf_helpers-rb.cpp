#include <opencv2/surface_matching/ppf_helpers.hpp>
#include "ppf_helpers-rb.hpp"

using namespace Rice;

extern "C"
void Init_PpfHelpers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(const char*, int)>("load_ply_simple", &cv::ppf_match_3d::loadPLYSimple);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, const char*)>("write_ply", &cv::ppf_match_3d::writePLY);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, const char*)>("write_ply_visible_normals", &cv::ppf_match_3d::writePLYVisibleNormals);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, int)>("sample_pc_uniform", &cv::ppf_match_3d::samplePCUniform);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, int, std::vector<int>&)>("sample_pc_uniform_ind", &cv::ppf_match_3d::samplePCUniformInd);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, cv::Vec<float, 2>&, cv::Vec<float, 2>&, cv::Vec<float, 2>&, float, int)>("sample_pc_by_quantization", &cv::ppf_match_3d::samplePCByQuantization);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Mat, cv::Vec<float, 2>&, cv::Vec<float, 2>&, cv::Vec<float, 2>&)>("compute_bbox_std", &cv::ppf_match_3d::computeBboxStd);
  
  rb_mCvPpfMatch3d.define_module_function<void*(*)(cv::Mat)>("index_pc_flann", &cv::ppf_match_3d::indexPCFlann);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(void*)>("destroy_flann", &cv::ppf_match_3d::destroyFlann);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(void*, cv::Mat&, cv::Mat&, cv::Mat&)>("query_pc_flann", &cv::ppf_match_3d::queryPCFlann);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(void*, cv::Mat&, cv::Mat&, cv::Mat&, const int)>("query_pc_flann", &cv::ppf_match_3d::queryPCFlann);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, float, float*, float*, float*, float*, float*)>("normalize_pc_coeff", &cv::ppf_match_3d::normalizePCCoeff);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, float, float, float, float, float, float)>("trans_pc_coeff", &cv::ppf_match_3d::transPCCoeff);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, const cv::Matx<double, 4, 4>&)>("transform_pc_pose", &cv::ppf_match_3d::transformPCPose);
  
  rb_mCvPpfMatch3d.define_module_function<void(*)(cv::Matx<double, 4, 4>&)>("get_random_pose", &cv::ppf_match_3d::getRandomPose);
  
  rb_mCvPpfMatch3d.define_module_function<cv::Mat(*)(cv::Mat, double)>("add_noise_pc", &cv::ppf_match_3d::addNoisePC);
  
  rb_mCvPpfMatch3d.define_module_function<int(*)(const cv::Mat&, cv::Mat&, const int, const bool, const cv::Vec<float, 3>&)>("compute_normals_pc3d", &cv::ppf_match_3d::computeNormalsPC3d);
}