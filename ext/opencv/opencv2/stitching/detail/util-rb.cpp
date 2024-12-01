#include <opencv2/stitching/detail/util.hpp>
#include "util-rb.hpp"

using namespace Rice;

extern "C"
void Init_Util()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailDisjointSets = define_class_under<cv::detail::DisjointSets>(rb_mCvDetail, "DisjointSets").
    define_constructor(Constructor<cv::detail::DisjointSets, int>()).
    define_method<void(cv::detail::DisjointSets::*)(int)>("create_one_elem_sets", &cv::detail::DisjointSets::createOneElemSets).
    define_method<int(cv::detail::DisjointSets::*)(int)>("find_set_by_elem", &cv::detail::DisjointSets::findSetByElem).
    define_method<int(cv::detail::DisjointSets::*)(int, int)>("merge_sets", &cv::detail::DisjointSets::mergeSets).
    define_attr("parent", &cv::detail::DisjointSets::parent).
    define_attr("size", &cv::detail::DisjointSets::size);
  
  Class rb_cCvDetailGraphEdge = define_class_under<cv::detail::GraphEdge>(rb_mCvDetail, "GraphEdge").
    define_constructor(Constructor<cv::detail::GraphEdge, int, int, float>()).
    define_method<bool(cv::detail::GraphEdge::*)(const cv::detail::GraphEdge&) const>("operator<", &cv::detail::GraphEdge::operator<).
    define_method<bool(cv::detail::GraphEdge::*)(const cv::detail::GraphEdge&) const>("operator>", &cv::detail::GraphEdge::operator>).
    define_attr("from", &cv::detail::GraphEdge::from).
    define_attr("to", &cv::detail::GraphEdge::to).
    define_attr("weight", &cv::detail::GraphEdge::weight);
  
  Class rb_cCvDetailGraph = define_class_under<cv::detail::Graph>(rb_mCvDetail, "Graph").
    define_constructor(Constructor<cv::detail::Graph, int>()).
    define_method<void(cv::detail::Graph::*)(int)>("create", &cv::detail::Graph::create).
    define_method<int(cv::detail::Graph::*)() const>("num_vertices", &cv::detail::Graph::numVertices).
    define_method<void(cv::detail::Graph::*)(int, int, float)>("add_edge", &cv::detail::Graph::addEdge);
  
  rb_mCvDetail.define_module_function<bool(*)(cv::Point_<int>, cv::Point_<int>, cv::Size_<int>, cv::Size_<int>, cv::Rect_<int>&)>("overlap_roi", &cv::detail::overlapRoi);
  
  rb_mCvDetail.define_module_function<cv::Rect_<int>(*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&)>("result_roi", &cv::detail::resultRoi);
  
  rb_mCvDetail.define_module_function<cv::Rect_<int>(*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("result_roi", &cv::detail::resultRoi);
  
  rb_mCvDetail.define_module_function<cv::Rect_<int>(*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::Size_<int>>&)>("result_roi_intersection", &cv::detail::resultRoiIntersection);
  
  rb_mCvDetail.define_module_function<cv::Point_<int>(*)(const std::vector<cv::Point_<int>>&)>("result_tl", &cv::detail::resultTl);
  
  rb_mCvDetail.define_module_function<void(*)(int, int, std::vector<int>&)>("select_random_subset", &cv::detail::selectRandomSubset);
  
  rb_mCvDetail.define_module_function<int&(*)()>("stitching_log_level", &cv::detail::stitchingLogLevel);
}