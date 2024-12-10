#include <sstream>
#include <opencv2/core/operations.hpp>
#include "operations-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_FastInvOp_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::internal::Matx_FastInvOp<_Tp, m, n>::*)(const int&, int&, int) const>("()", &cv::internal::Matx_FastInvOp<_Tp, m, n>::operator(),
      Arg("a"), Arg("b"), Arg("method"));
};

template<typename Data_Type_T, typename _Tp, int m, int l, int n>
inline void Matx_FastSolveOp_builder(Data_Type_T& klass)
{
  klass.template define_method<bool(cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::*)(const int&, const int&, int&, int) const>("()", &cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::operator(),
      Arg("a"), Arg("b"), Arg("x"), Arg("method"));
};


void Init_Operations()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  
  rb_mCv.define_module_function<int(*)(int, int)>("format", &cv::format,
    Arg("mtx"), Arg("fmt"));
  
  rb_mCv.define_module_function<int(*)(int, ::FILE*)>("print", &cv::print,
    Arg("fmtd"), Arg("stream") = NULL);
  
  rb_mCv.define_module_function<int(*)(const int&, ::FILE*)>("print", &cv::print,
    Arg("mtx"), Arg("stream") = NULL);
  
  rb_mCv.define_module_function<int(*)(const int&, ::FILE*)>("print", &cv::print,
    Arg("mtx"), Arg("stream") = NULL);
  
  rb_mCv.define_singleton_attr("String", &cv::String);

}