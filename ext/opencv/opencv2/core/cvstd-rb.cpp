#include <sstream>
#include <opencv2/core/cvstd.hpp>
#include "cvstd-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp>
inline void Allocator_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Allocator::Allocator<_Tp>>()).
    define_constructor(Constructor<cv::Allocator::Allocator<_Tp>, const cv::Allocator<_Tp>&>(),
      Arg("")).
    template define_method<cv::Allocator<_Tp>::pointer(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method<cv::Allocator<_Tp>::const_pointer(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::const_reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method<cv::Allocator<_Tp>::pointer(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::size_type, const void*)>("allocate", &cv::Allocator<_Tp>::allocate,
      Arg("count"), Arg("") = 0).
    template define_method<void(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::pointer, cv::Allocator<_Tp>::size_type)>("deallocate", &cv::Allocator<_Tp>::deallocate,
      Arg("p"), Arg("")).
    template define_method<void(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::pointer, const _Tp&)>("construct", &cv::Allocator<_Tp>::construct,
      Arg("p"), Arg("v")).
    template define_method<void(cv::Allocator<_Tp>::*)(cv::Allocator<_Tp>::pointer)>("destroy", &cv::Allocator<_Tp>::destroy,
      Arg("p")).
    template define_method<cv::Allocator<_Tp>::size_type(cv::Allocator<_Tp>::*)() const>("max_size", &cv::Allocator<_Tp>::max_size);
};

template<typename Data_Type_T, typename U>
inline void rebind_builder(Data_Type_T& klass)
{
};


void Init_Cvstd()
{
  Module rb_mCv = define_module("Cv");
  
  
  rb_mCv.define_module_function<void*(*)(::size_t)>("fast_malloc", &cv::fastMalloc,
    Arg("buf_size"));
  
  rb_mCv.define_module_function<void(*)(void*)>("fast_free", &cv::fastFree,
    Arg("ptr"));
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
  

}