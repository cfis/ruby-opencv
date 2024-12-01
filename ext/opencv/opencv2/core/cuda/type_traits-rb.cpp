#include <sstream>
#include <opencv2/core/cuda/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void IsSimpleParameter_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void TypeTraits_builder(Data_Type_T& klass)
{
};


void Init_TypeTraits()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  

}