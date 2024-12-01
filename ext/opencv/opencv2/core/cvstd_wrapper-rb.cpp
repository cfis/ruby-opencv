#include <opencv2/core/cvstd_wrapper.hpp>
#include "cvstd_wrapper-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename C, typename Ret, typename Args>
inline void has_parenthesis_operator_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", cv::sfinae::has_parenthesis_operator<C, Ret, Args>::value);
};

template<typename Data_Type_T, typename T, typename >
inline void has_custom_delete_builder(Data_Type_T& klass)
{
};

template<typename Data_Type_T, typename T>
inline void Ptr_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Ptr::Ptr<T>>()).
    define_constructor(Constructor<cv::Ptr::Ptr<T>, nullptr_t>(),
      Arg("")).
    define_constructor(Constructor<cv::Ptr::Ptr<T>, const cv::Ptr<T>&>(),
      Arg("o")).
    define_constructor(Constructor<cv::Ptr::Ptr<T>, const std::shared_ptr<T>&>(),
      Arg("o")).
    define_constructor(Constructor<cv::Ptr::Ptr<T>, std::shared_ptr<T>&&>(),
      Arg("o")).
    template define_method("reset", &cv::Ptr<T>::reset).
    template define_method("assign", &cv::Ptr<T>::operator=,
      Arg("o")).
    template define_method("->", &cv::Ptr<T>::operator->).
    template define_method("*", &cv::Ptr<T>::operator*).
    template define_method("release", &cv::Ptr<T>::release).
    define_method("to_type_parameter_0_0 *", [](const cv::Ptr<T>& self) -> T*
    {
      return self;
    }).
    template define_method("empty?", &cv::Ptr<T>::empty);
};

void Init_CvstdWrapper()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvSfinae = define_module_under(rb_mCv, "Sfinae");
}