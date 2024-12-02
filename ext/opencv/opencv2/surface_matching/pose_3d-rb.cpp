#include <opencv2/surface_matching/pose_3d.hpp>
#include "pose_3d-rb.hpp"

using namespace Rice;

extern "C"
void Init_Pose3d()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPpfMatch3d = define_module_under(rb_mCv, "PpfMatch3d");
  
  Class rb_cCvPpfMatch3dPose3D = define_class_under<cv::ppf_match_3d::Pose3D>(rb_mCvPpfMatch3d, "Pose3D").
    define_constructor(Constructor<cv::ppf_match_3d::Pose3D>()).
    define_constructor(Constructor<cv::ppf_match_3d::Pose3D, double, unsigned long long, unsigned long long>()).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(int&)>("update_pose", &cv::ppf_match_3d::Pose3D::updatePose).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(int&, int&)>("update_pose", &cv::ppf_match_3d::Pose3D::updatePose).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(int&, int&)>("update_pose_quat", &cv::ppf_match_3d::Pose3D::updatePoseQuat).
    define_method<void(cv::ppf_match_3d::Pose3D::*)(int&)>("append_pose", &cv::ppf_match_3d::Pose3D::appendPose).
    define_method<void(cv::ppf_match_3d::Pose3D::*)()>("print_pose", &cv::ppf_match_3d::Pose3D::printPose).
    define_method<cv::Ptr<cv::ppf_match_3d::Pose3D>(cv::ppf_match_3d::Pose3D::*)()>("clone", &cv::ppf_match_3d::Pose3D::clone).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(_iobuf*)>("write_pose", &cv::ppf_match_3d::Pose3D::writePose).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(_iobuf*)>("read_pose", &cv::ppf_match_3d::Pose3D::readPose).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(const std::basic_string<char>&)>("write_pose", &cv::ppf_match_3d::Pose3D::writePose).
    define_method<int(cv::ppf_match_3d::Pose3D::*)(const std::basic_string<char>&)>("read_pose", &cv::ppf_match_3d::Pose3D::readPose).
    define_attr("alpha", &cv::ppf_match_3d::Pose3D::alpha).
    define_attr("residual", &cv::ppf_match_3d::Pose3D::residual).
    define_attr("model_index", &cv::ppf_match_3d::Pose3D::modelIndex).
    define_attr("num_votes", &cv::ppf_match_3d::Pose3D::numVotes).
    define_attr("pose", &cv::ppf_match_3d::Pose3D::pose).
    define_attr("angle", &cv::ppf_match_3d::Pose3D::angle).
    define_attr("t", &cv::ppf_match_3d::Pose3D::t).
    define_attr("q", &cv::ppf_match_3d::Pose3D::q);
  
  Class rb_cCvPpfMatch3dPoseCluster3D = define_class_under<cv::ppf_match_3d::PoseCluster3D>(rb_mCvPpfMatch3d, "PoseCluster3D").
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D>()).
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D, cv::Ptr<cv::ppf_match_3d::Pose3D>>()).
    define_constructor(Constructor<cv::ppf_match_3d::PoseCluster3D, cv::Ptr<cv::ppf_match_3d::Pose3D>, int>()).
    define_method<void(cv::ppf_match_3d::PoseCluster3D::*)(cv::Ptr<cv::ppf_match_3d::Pose3D>)>("add_pose", &cv::ppf_match_3d::PoseCluster3D::addPose).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(_iobuf*)>("write_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::writePoseCluster).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(_iobuf*)>("read_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::readPoseCluster).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(const std::basic_string<char>&)>("write_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::writePoseCluster).
    define_method<int(cv::ppf_match_3d::PoseCluster3D::*)(const std::basic_string<char>&)>("read_pose_cluster", &cv::ppf_match_3d::PoseCluster3D::readPoseCluster).
    define_attr("pose_list", &cv::ppf_match_3d::PoseCluster3D::poseList).
    define_attr("num_votes", &cv::ppf_match_3d::PoseCluster3D::numVotes).
    define_attr("id", &cv::ppf_match_3d::PoseCluster3D::id);
}