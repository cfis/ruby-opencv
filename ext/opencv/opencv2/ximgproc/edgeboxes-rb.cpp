#include <opencv2/ximgproc/edgeboxes.hpp>
#include "edgeboxes-rb.hpp"

using namespace Rice;

extern "C"
void Init_Edgeboxes()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Class rb_cCvXimgprocBox = define_class_under<cv::ximgproc::Box>(rb_mCvXimgproc, "Box").
    define_attr("x", &cv::ximgproc::Box::x).
    define_attr("y", &cv::ximgproc::Box::y).
    define_attr("w", &cv::ximgproc::Box::w).
    define_attr("h", &cv::ximgproc::Box::h).
    define_attr("score", &cv::ximgproc::Box::score);
  
  Class rb_cCvXimgprocEdgeBoxes = define_class_under<cv::ximgproc::EdgeBoxes, cv::Algorithm>(rb_mCvXimgproc, "EdgeBoxes").
    define_method<void(cv::ximgproc::EdgeBoxes::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<cv::Rect_<int>>&, const cv::_OutputArray &)>("get_bounding_boxes", &cv::ximgproc::EdgeBoxes::getBoundingBoxes).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_alpha", &cv::ximgproc::EdgeBoxes::getAlpha).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_alpha", &cv::ximgproc::EdgeBoxes::setAlpha).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_beta", &cv::ximgproc::EdgeBoxes::getBeta).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_beta", &cv::ximgproc::EdgeBoxes::setBeta).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_eta", &cv::ximgproc::EdgeBoxes::getEta).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_eta", &cv::ximgproc::EdgeBoxes::setEta).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_min_score", &cv::ximgproc::EdgeBoxes::getMinScore).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_min_score", &cv::ximgproc::EdgeBoxes::setMinScore).
    define_method<int(cv::ximgproc::EdgeBoxes::*)() const>("get_max_boxes", &cv::ximgproc::EdgeBoxes::getMaxBoxes).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(int)>("set_max_boxes", &cv::ximgproc::EdgeBoxes::setMaxBoxes).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_edge_min_mag", &cv::ximgproc::EdgeBoxes::getEdgeMinMag).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_edge_min_mag", &cv::ximgproc::EdgeBoxes::setEdgeMinMag).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_edge_merge_thr", &cv::ximgproc::EdgeBoxes::getEdgeMergeThr).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_edge_merge_thr", &cv::ximgproc::EdgeBoxes::setEdgeMergeThr).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_cluster_min_mag", &cv::ximgproc::EdgeBoxes::getClusterMinMag).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_cluster_min_mag", &cv::ximgproc::EdgeBoxes::setClusterMinMag).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_max_aspect_ratio", &cv::ximgproc::EdgeBoxes::getMaxAspectRatio).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_max_aspect_ratio", &cv::ximgproc::EdgeBoxes::setMaxAspectRatio).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_min_box_area", &cv::ximgproc::EdgeBoxes::getMinBoxArea).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_min_box_area", &cv::ximgproc::EdgeBoxes::setMinBoxArea).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_gamma", &cv::ximgproc::EdgeBoxes::getGamma).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_gamma", &cv::ximgproc::EdgeBoxes::setGamma).
    define_method<float(cv::ximgproc::EdgeBoxes::*)() const>("get_kappa", &cv::ximgproc::EdgeBoxes::getKappa).
    define_method<void(cv::ximgproc::EdgeBoxes::*)(float)>("set_kappa", &cv::ximgproc::EdgeBoxes::setKappa);
  
  rb_mCvXimgproc.define_module_function<cv::Ptr<cv::ximgproc::EdgeBoxes>(*)(float, float, float, float, int, float, float, float, float, float, float, float)>("create_edge_boxes", &cv::ximgproc::createEdgeBoxes);
}