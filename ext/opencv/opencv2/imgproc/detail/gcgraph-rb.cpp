#include <sstream>
#include <opencv2/imgproc/detail/gcgraph.hpp>
#include "gcgraph-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename TWeight>
inline void GCGraph_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::detail::GCGraph::GCGraph<TWeight>>()).
    define_constructor(Constructor<cv::detail::GCGraph::GCGraph<TWeight>, unsigned int, unsigned int>(),
      Arg("vtx_count"), Arg("edge_count")).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(unsigned int, unsigned int)>("create", &cv::detail::GCGraph<TWeight>::create,
      Arg("vtx_count"), Arg("edge_count")).
    template define_method<int(cv::detail::GCGraph<TWeight>::*)()>("add_vtx", &cv::detail::GCGraph<TWeight>::addVtx).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(int, int, TWeight, TWeight)>("add_edges", &cv::detail::GCGraph<TWeight>::addEdges,
      Arg("i"), Arg("j"), Arg("w"), Arg("revw")).
    template define_method<void(cv::detail::GCGraph<TWeight>::*)(int, TWeight, TWeight)>("add_term_weights", &cv::detail::GCGraph<TWeight>::addTermWeights,
      Arg("i"), Arg("source_w"), Arg("sink_w")).
    template define_method<TWeight(cv::detail::GCGraph<TWeight>::*)()>("max_flow", &cv::detail::GCGraph<TWeight>::maxFlow).
    template define_method<bool(cv::detail::GCGraph<TWeight>::*)(int)>("in_source_segment?", &cv::detail::GCGraph<TWeight>::inSourceSegment,
      Arg("i")).
    Class rb_cCvDetailGCGraphVtx = define_class<cv::detail::GCGraph::Vtx>("Vtx").
      define_constructor(Constructor<cv::detail::GCGraph::Vtx>()).
      define_attr("next", &cv::detail::GCGraph<TWeight>::Vtx::next).
      define_attr("parent", &cv::detail::GCGraph<TWeight>::Vtx::parent).
      define_attr("first", &cv::detail::GCGraph<TWeight>::Vtx::first).
      define_attr("ts", &cv::detail::GCGraph<TWeight>::Vtx::ts).
      define_attr("dist", &cv::detail::GCGraph<TWeight>::Vtx::dist).
      define_attr("weight", &cv::detail::GCGraph<TWeight>::Vtx::weight).
      define_attr("t", &cv::detail::GCGraph<TWeight>::Vtx::t);;
};


void Init_Gcgraph()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  

}