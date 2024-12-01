#include <opencv2/core/matx.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/operations.hpp>

#include "matx-rb.hpp"

using namespace Rice;

template<typename Data_Object_T, typename _Tp, int m, int n>
inline void Matx_builder(Data_Object_T& klass)
{
 /* klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const _Tp*>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, std::initializer_list<_Tp>>()).*/
    klass.template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp)>("all", &cv::Matx<_Tp, m, n>::all).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("zeros", &cv::Matx<_Tp, m, n>::zeros).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("ones", &cv::Matx<_Tp, m, n>::ones).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)()>("eye", &cv::Matx<_Tp, m, n>::eye).
  //  template define_singleton_function<cv::Matx<_Tp, m, n>(*)(const cv::diag_type&)>("diag", &cv::Matx<_Tp, m, n>::diag).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randu", &cv::Matx<_Tp, m, n>::randu).
    template define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randn", &cv::Matx<_Tp, m, n>::randn).
    template define_method<_Tp(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("dot", &cv::Matx<_Tp, m, n>::dot).
    template define_method<double(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("ddot", &cv::Matx<_Tp, m, n>::ddot).
    template define_method<cv::Matx<_Tp, 1, n>(cv::Matx<_Tp, m, n>::*)(int) const>("row", &cv::Matx<_Tp, m, n>::row).
    template define_method<cv::Matx<_Tp, m, 1>(cv::Matx<_Tp, m, n>::*)(int) const>("col", &cv::Matx<_Tp, m, n>::col).
    //template define_method<cv::diag_type(cv::Matx<_Tp, m, n>::*)() const>("diag", &cv::Matx<_Tp, m, n>::diag).
    template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)() const>("t", &cv::Matx<_Tp, m, n>::t).
    template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)(int, bool*) const>("inv", &cv::Matx<_Tp, m, n>::inv).
    template define_method<cv::Vec<_Tp, n>(cv::Matx<_Tp, m, n>::*)(const cv::Vec<_Tp, m>&, int) const>("solve", &cv::Matx<_Tp, m, n>::solve).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("mul", &cv::Matx<_Tp, m, n>::mul).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("div", &cv::Matx<_Tp, m, n>::div);
  //  template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int, int) const>("operator()", &cv::Matx<_Tp, m, n>::operator());
//    template define_method<_Tp&(cv::Matx<_Tp, m, n>::*)(int, int)>("operator()", &cv::Matx<_Tp, m, n>::operator());

    if constexpr (m == 1 || n == 1)
    {
      klass.template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int) const>("operator()", &cv::Matx<_Tp, m, n>::operator()).
            template define_method<_Tp&(cv::Matx<_Tp, m, n>::*)(int)>("operator()", &cv::Matx<_Tp, m, n>::operator());
    }
  /*  klass.define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_SubOp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_MulOp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_DivOp>()).
    define_constructor(Constructor<cv::Matx<_Tp, m, n>, const cv::Matx<_Tp, n, m>&, cv::Matx_TOp>());*/
};

template<typename Data_Object_T, typename _Tp, int cn>
inline void Vec_builder(Data_Object_T& klass)
{
 /* klass.define_constructor(Constructor<cv::Vec<_Tp, cn>>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const _Tp*>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, std::initializer_list<_Tp>>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Vec<_Tp, cn>&>()).*/
    klass.template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp)>("all", &cv::Vec<_Tp, cn>::all).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)()>("ones", &cv::Vec<_Tp, cn>::ones).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randn", &cv::Vec<_Tp, cn>::randn).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randu", &cv::Vec<_Tp, cn>::randu).
    template define_singleton_function<cv::Vec<_Tp, cn>(*)()>("zeros", &cv::Vec<_Tp, cn>::zeros).
    template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("mul", &cv::Vec<_Tp, cn>::mul).
    //template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)() const>("conj", &cv::Vec<_Tp, cn>::conj).
    //template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("cross", &cv::Vec<_Tp, cn>::cross).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("operator[]", &cv::Vec<_Tp, cn>::operator[]).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("operator[]", &cv::Vec<_Tp, cn>::operator[]).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("operator()", &cv::Vec<_Tp, cn>::operator()).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("operator()", &cv::Vec<_Tp, cn>::operator()).
    template define_method<cv::Vec<_Tp, cn>&(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&)>("operator=", &cv::Vec<_Tp, cn>::operator=).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_SubOp>());
};


extern "C"
void Init_Matx()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvMatxAddOp = define_class_under<cv::Matx_AddOp>(rb_mCv, "MatxAddOp").
    define_constructor(Constructor<cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Matx_AddOp, const cv::Matx_AddOp&>());
  
  Class rb_cCvMatxSubOp = define_class_under<cv::Matx_SubOp>(rb_mCv, "MatxSubOp").
    define_constructor(Constructor<cv::Matx_SubOp>()).
    define_constructor(Constructor<cv::Matx_SubOp, const cv::Matx_SubOp&>());
  
  Class rb_cCvMatxScaleOp = define_class_under<cv::Matx_ScaleOp>(rb_mCv, "MatxScaleOp").
    define_constructor(Constructor<cv::Matx_ScaleOp>()).
    define_constructor(Constructor<cv::Matx_ScaleOp, const cv::Matx_ScaleOp&>());
  
  Class rb_cCvMatxMulOp = define_class_under<cv::Matx_MulOp>(rb_mCv, "MatxMulOp").
    define_constructor(Constructor<cv::Matx_MulOp>()).
    define_constructor(Constructor<cv::Matx_MulOp, const cv::Matx_MulOp&>());
  
  Class rb_cCvMatxDivOp = define_class_under<cv::Matx_DivOp>(rb_mCv, "MatxDivOp").
    define_constructor(Constructor<cv::Matx_DivOp>()).
    define_constructor(Constructor<cv::Matx_DivOp, const cv::Matx_DivOp&>());
  
  Class rb_cCvMatxMatMulOp = define_class_under<cv::Matx_MatMulOp>(rb_mCv, "MatxMatMulOp").
    define_constructor(Constructor<cv::Matx_MatMulOp>()).
    define_constructor(Constructor<cv::Matx_MatMulOp, const cv::Matx_MatMulOp&>());
  
  Class rb_cCvMatxTOp = define_class_under<cv::Matx_TOp>(rb_mCv, "MatxTOp").
    define_constructor(Constructor<cv::Matx_TOp>()).
    define_constructor(Constructor<cv::Matx_TOp, const cv::Matx_TOp&>());
  
  Data_Type<cv::Matx<float, 1, 2>> rb_cMatx12f = define_class_under<cv::Matx<float, 1, 2>>(rb_mCv, "Matx12f");
  rb_cMatx12f.define(&Matx_builder<Data_Type<cv::Matx<float, 1, 2>>, float, 1, 2>);
  
  Data_Type<cv::Matx<double, 1, 2>> rb_cMatx12d = define_class_under<cv::Matx<double, 1, 2>>(rb_mCv, "Matx12d");
  rb_cMatx12d.define(&Matx_builder<Data_Type<cv::Matx<double, 1, 2>>, double, 1, 2>);
  
  Data_Type<cv::Matx<float, 1, 3>> rb_cMatx13f = define_class_under<cv::Matx<float, 1, 3>>(rb_mCv, "Matx13f");
  rb_cMatx13f.define(&Matx_builder<Data_Type<cv::Matx<float, 1, 3>>, float, 1, 3>);
  
  Data_Type<cv::Matx<double, 1, 3>> rb_cMatx13d = define_class_under<cv::Matx<double, 1, 3>>(rb_mCv, "Matx13d");
  rb_cMatx13d.define(&Matx_builder<Data_Type<cv::Matx<double, 1, 3>>, double, 1, 3>);
  
  Data_Type<cv::Matx<float, 1, 4>> rb_cMatx14f = define_class_under<cv::Matx<float, 1, 4>>(rb_mCv, "Matx14f");
  rb_cMatx14f.define(&Matx_builder<Data_Type<cv::Matx<float, 1, 4>>, float, 1, 4>);
  
  Data_Type<cv::Matx<double, 1, 4>> rb_cMatx14d = define_class_under<cv::Matx<double, 1, 4>>(rb_mCv, "Matx14d");
  rb_cMatx14d.define(&Matx_builder<Data_Type<cv::Matx<double, 1, 4>>, double, 1, 4>);
  
  Data_Type<cv::Matx<float, 1, 6>> rb_cMatx16f = define_class_under<cv::Matx<float, 1, 6>>(rb_mCv, "Matx16f");
  rb_cMatx16f.define(&Matx_builder<Data_Type<cv::Matx<float, 1, 6>>, float, 1, 6>);
  
  Data_Type<cv::Matx<double, 1, 6>> rb_cMatx16d = define_class_under<cv::Matx<double, 1, 6>>(rb_mCv, "Matx16d");
  rb_cMatx16d.define(&Matx_builder<Data_Type<cv::Matx<double, 1, 6>>, double, 1, 6>);
  
  Data_Type<cv::Matx<float, 2, 1>> rb_cMatx21f = define_class_under<cv::Matx<float, 2, 1>>(rb_mCv, "Matx21f");
  rb_cMatx21f.define(&Matx_builder<Data_Type<cv::Matx<float, 2, 1>>, float, 2, 1>);
  
  Data_Type<cv::Matx<double, 2, 1>> rb_cMatx21d = define_class_under<cv::Matx<double, 2, 1>>(rb_mCv, "Matx21d");
  rb_cMatx21d.define(&Matx_builder<Data_Type<cv::Matx<double, 2, 1>>, double, 2, 1>);
  
  Data_Type<cv::Matx<float, 3, 1>> rb_cMatx31f = define_class_under<cv::Matx<float, 3, 1>>(rb_mCv, "Matx31f");
  rb_cMatx31f.define(&Matx_builder<Data_Type<cv::Matx<float, 3, 1>>, float, 3, 1>);
  
  Data_Type<cv::Matx<double, 3, 1>> rb_cMatx31d = define_class_under<cv::Matx<double, 3, 1>>(rb_mCv, "Matx31d");
  rb_cMatx31d.define(&Matx_builder<Data_Type<cv::Matx<double, 3, 1>>, double, 3, 1>);
  
  Data_Type<cv::Matx<float, 4, 1>> rb_cMatx41f = define_class_under<cv::Matx<float, 4, 1>>(rb_mCv, "Matx41f");
  rb_cMatx41f.define(&Matx_builder<Data_Type<cv::Matx<float, 4, 1>>, float, 4, 1>);
  
  Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = define_class_under<cv::Matx<double, 4, 1>>(rb_mCv, "Matx41d");
  rb_cMatx41d.define(&Matx_builder<Data_Type<cv::Matx<double, 4, 1>>, double, 4, 1>);
  
  Data_Type<cv::Matx<float, 6, 1>> rb_cMatx61f = define_class_under<cv::Matx<float, 6, 1>>(rb_mCv, "Matx61f");
  rb_cMatx61f.define(&Matx_builder<Data_Type<cv::Matx<float, 6, 1>>, float, 6, 1>);
  
  Data_Type<cv::Matx<double, 6, 1>> rb_cMatx61d = define_class_under<cv::Matx<double, 6, 1>>(rb_mCv, "Matx61d");
  rb_cMatx61d.define(&Matx_builder<Data_Type<cv::Matx<double, 6, 1>>, double, 6, 1>);
  
  Data_Type<cv::Matx<float, 2, 2>> rb_cMatx22f = define_class_under<cv::Matx<float, 2, 2>>(rb_mCv, "Matx22f");
  rb_cMatx22f.define(&Matx_builder<Data_Type<cv::Matx<float, 2, 2>>, float, 2, 2>);
  
  Data_Type<cv::Matx<double, 2, 2>> rb_cMatx22d = define_class_under<cv::Matx<double, 2, 2>>(rb_mCv, "Matx22d");
  rb_cMatx22d.define(&Matx_builder<Data_Type<cv::Matx<double, 2, 2>>, double, 2, 2>);
  
  Data_Type<cv::Matx<float, 2, 3>> rb_cMatx23f = define_class_under<cv::Matx<float, 2, 3>>(rb_mCv, "Matx23f");
  rb_cMatx23f.define(&Matx_builder<Data_Type<cv::Matx<float, 2, 3>>, float, 2, 3>);
  
  Data_Type<cv::Matx<double, 2, 3>> rb_cMatx23d = define_class_under<cv::Matx<double, 2, 3>>(rb_mCv, "Matx23d");
  rb_cMatx23d.define(&Matx_builder<Data_Type<cv::Matx<double, 2, 3>>, double, 2, 3>);
  
  Data_Type<cv::Matx<float, 3, 2>> rb_cMatx32f = define_class_under<cv::Matx<float, 3, 2>>(rb_mCv, "Matx32f");
  rb_cMatx32f.define(&Matx_builder<Data_Type<cv::Matx<float, 3, 2>>, float, 3, 2>);
  
  Data_Type<cv::Matx<double, 3, 2>> rb_cMatx32d = define_class_under<cv::Matx<double, 3, 2>>(rb_mCv, "Matx32d");
  rb_cMatx32d.define(&Matx_builder<Data_Type<cv::Matx<double, 3, 2>>, double, 3, 2>);
  
  Data_Type<cv::Matx<float, 3, 3>> rb_cMatx33f = define_class_under<cv::Matx<float, 3, 3>>(rb_mCv, "Matx33f");
  rb_cMatx33f.define(&Matx_builder<Data_Type<cv::Matx<float, 3, 3>>, float, 3, 3>);
  
  Data_Type<cv::Matx<double, 3, 3>> rb_cMatx33d = define_class_under<cv::Matx<double, 3, 3>>(rb_mCv, "Matx33d");
  rb_cMatx33d.define(&Matx_builder<Data_Type<cv::Matx<double, 3, 3>>, double, 3, 3>);
  
  Data_Type<cv::Matx<float, 3, 4>> rb_cMatx34f = define_class_under<cv::Matx<float, 3, 4>>(rb_mCv, "Matx34f");
  rb_cMatx34f.define(&Matx_builder<Data_Type<cv::Matx<float, 3, 4>>, float, 3, 4>);
  
  Data_Type<cv::Matx<double, 3, 4>> rb_cMatx34d = define_class_under<cv::Matx<double, 3, 4>>(rb_mCv, "Matx34d");
  rb_cMatx34d.define(&Matx_builder<Data_Type<cv::Matx<double, 3, 4>>, double, 3, 4>);
  
  Data_Type<cv::Matx<float, 4, 3>> rb_cMatx43f = define_class_under<cv::Matx<float, 4, 3>>(rb_mCv, "Matx43f");
  rb_cMatx43f.define(&Matx_builder<Data_Type<cv::Matx<float, 4, 3>>, float, 4, 3>);
  
  Data_Type<cv::Matx<double, 4, 3>> rb_cMatx43d = define_class_under<cv::Matx<double, 4, 3>>(rb_mCv, "Matx43d");
  rb_cMatx43d.define(&Matx_builder<Data_Type<cv::Matx<double, 4, 3>>, double, 4, 3>);
  
  Data_Type<cv::Matx<float, 4, 4>> rb_cMatx44f = define_class_under<cv::Matx<float, 4, 4>>(rb_mCv, "Matx44f");
  rb_cMatx44f.define(&Matx_builder<Data_Type<cv::Matx<float, 4, 4>>, float, 4, 4>);
  
  Data_Type<cv::Matx<double, 4, 4>> rb_cMatx44d = define_class_under<cv::Matx<double, 4, 4>>(rb_mCv, "Matx44d");
  rb_cMatx44d.define(&Matx_builder<Data_Type<cv::Matx<double, 4, 4>>, double, 4, 4>);
  
  Data_Type<cv::Matx<float, 6, 6>> rb_cMatx66f = define_class_under<cv::Matx<float, 6, 6>>(rb_mCv, "Matx66f");
  rb_cMatx66f.define(&Matx_builder<Data_Type<cv::Matx<float, 6, 6>>, float, 6, 6>);
  
  Data_Type<cv::Matx<double, 6, 6>> rb_cMatx66d = define_class_under<cv::Matx<double, 6, 6>>(rb_mCv, "Matx66d");
  rb_cMatx66d.define(&Matx_builder<Data_Type<cv::Matx<double, 6, 6>>, double, 6, 6>);
  
  Data_Type<cv::Vec<unsigned char, 2>> rb_cVec2b = define_class_under<cv::Vec<unsigned char, 2>>(rb_mCv, "Vec2b");
  rb_cVec2b.define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 2>>, unsigned char, 2>);
  
  Data_Type<cv::Vec<unsigned char, 3>> rb_cVec3b = define_class_under<cv::Vec<unsigned char, 3>>(rb_mCv, "Vec3b");
  rb_cVec3b.define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 3>>, unsigned char, 3>);
  
  Data_Type<cv::Vec<unsigned char, 4>> rb_cVec4b = define_class_under<cv::Vec<unsigned char, 4>>(rb_mCv, "Vec4b");
  rb_cVec4b.define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 4>>, unsigned char, 4>);
  
  Data_Type<cv::Vec<short, 2>> rb_cVec2s = define_class_under<cv::Vec<short, 2>>(rb_mCv, "Vec2s");
  rb_cVec2s.define(&Vec_builder<Data_Type<cv::Vec<short, 2>>, short, 2>);
  
  Data_Type<cv::Vec<short, 3>> rb_cVec3s = define_class_under<cv::Vec<short, 3>>(rb_mCv, "Vec3s");
  rb_cVec3s.define(&Vec_builder<Data_Type<cv::Vec<short, 3>>, short, 3>);
  
  Data_Type<cv::Vec<short, 4>> rb_cVec4s = define_class_under<cv::Vec<short, 4>>(rb_mCv, "Vec4s");
  rb_cVec4s.define(&Vec_builder<Data_Type<cv::Vec<short, 4>>, short, 4>);
  
  Data_Type<cv::Vec<unsigned short, 2>> rb_cVec2w = define_class_under<cv::Vec<unsigned short, 2>>(rb_mCv, "Vec2w");
  rb_cVec2w.define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 2>>, unsigned short, 2>);
  
  Data_Type<cv::Vec<unsigned short, 3>> rb_cVec3w = define_class_under<cv::Vec<unsigned short, 3>>(rb_mCv, "Vec3w");
  rb_cVec3w.define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 3>>, unsigned short, 3>);
  
  Data_Type<cv::Vec<unsigned short, 4>> rb_cVec4w = define_class_under<cv::Vec<unsigned short, 4>>(rb_mCv, "Vec4w");
  rb_cVec4w.define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 4>>, unsigned short, 4>);
  
  Data_Type<cv::Vec<int, 2>> rb_cVec2i = define_class_under<cv::Vec<int, 2>>(rb_mCv, "Vec2i");
  rb_cVec2i.define(&Vec_builder<Data_Type<cv::Vec<int, 2>>, int, 2>);
  
  Data_Type<cv::Vec<int, 3>> rb_cVec3i = define_class_under<cv::Vec<int, 3>>(rb_mCv, "Vec3i");
  rb_cVec3i.define(&Vec_builder<Data_Type<cv::Vec<int, 3>>, int, 3>);
  
  Data_Type<cv::Vec<int, 4>> rb_cVec4i = define_class_under<cv::Vec<int, 4>>(rb_mCv, "Vec4i");
  rb_cVec4i.define(&Vec_builder<Data_Type<cv::Vec<int, 4>>, int, 4>);
  
  Data_Type<cv::Vec<int, 6>> rb_cVec6i = define_class_under<cv::Vec<int, 6>>(rb_mCv, "Vec6i");
  rb_cVec6i.define(&Vec_builder<Data_Type<cv::Vec<int, 6>>, int, 6>);
  
  Data_Type<cv::Vec<int, 8>> rb_cVec8i = define_class_under<cv::Vec<int, 8>>(rb_mCv, "Vec8i");
  rb_cVec8i.define(&Vec_builder<Data_Type<cv::Vec<int, 8>>, int, 8>);
  
  Data_Type<cv::Vec<float, 2>> rb_cVec2f = define_class_under<cv::Vec<float, 2>>(rb_mCv, "Vec2f");
  rb_cVec2f.define(&Vec_builder<Data_Type<cv::Vec<float, 2>>, float, 2>);
  
  Data_Type<cv::Vec<float, 3>> rb_cVec3f = define_class_under<cv::Vec<float, 3>>(rb_mCv, "Vec3f");
  rb_cVec3f.define(&Vec_builder<Data_Type<cv::Vec<float, 3>>, float, 3>);
  
  Data_Type<cv::Vec<float, 4>> rb_cVec4f = define_class_under<cv::Vec<float, 4>>(rb_mCv, "Vec4f");
  rb_cVec4f.define(&Vec_builder<Data_Type<cv::Vec<float, 4>>, float, 4>);
  
  Data_Type<cv::Vec<float, 6>> rb_cVec6f = define_class_under<cv::Vec<float, 6>>(rb_mCv, "Vec6f");
  rb_cVec6f.define(&Vec_builder<Data_Type<cv::Vec<float, 6>>, float, 6>);
  
  Data_Type<cv::Vec<double, 2>> rb_cVec2d = define_class_under<cv::Vec<double, 2>>(rb_mCv, "Vec2d");
  rb_cVec2d.define(&Vec_builder<Data_Type<cv::Vec<double, 2>>, double, 2>);
  
  Data_Type<cv::Vec<double, 3>> rb_cVec3d = define_class_under<cv::Vec<double, 3>>(rb_mCv, "Vec3d");
  rb_cVec3d.define(&Vec_builder<Data_Type<cv::Vec<double, 3>>, double, 3>);
  
  Data_Type<cv::Vec<double, 4>> rb_cVec4d = define_class_under<cv::Vec<double, 4>>(rb_mCv, "Vec4d");
  rb_cVec4d.define(&Vec_builder<Data_Type<cv::Vec<double, 4>>, double, 4>);
  
  Data_Type<cv::Vec<double, 6>> rb_cVec6d = define_class_under<cv::Vec<double, 6>>(rb_mCv, "Vec6d");
  rb_cVec6d.define(&Vec_builder<Data_Type<cv::Vec<double, 6>>, double, 6>);

  // Manually added
  Data_Type<cv::Vec<double, 1>> rb_cVec1d = define_class_under<cv::Vec<double, 1>>(rb_mCv, "Vec1d");
  rb_cVec1d.define(&Vec_builder<Data_Type<cv::Vec<double, 1>>, double, 1>);

  Data_Type<cv::Vec<float, 1>> rb_cVec1f = define_class_under<cv::Vec<float, 1>>(rb_mCv, "Vec1f");
  rb_cVec1f.define(&Vec_builder<Data_Type<cv::Vec<float, 1>>, float, 1>);

  //Data_Type<cv::Vec<long long, 2>> rb_cVec2l = define_class_under<cv::Vec<long long, 2>>(rb_mCv, "Vec2l");
  //rb_cVec2l.define(&Vec_builder<Data_Type<cv::Vec<long long, 2>>, long long, 2>);

  // Data_Type<cv::Vec<long long, 1>> rb_cVec1l = define_class_under<cv::Vec<long long, 1>>(rb_mCv, "Vec1l");
  //rb_cVec1l.define(&Vec_builder<Data_Type<cv::Vec<long long, 1>>, long long, 1>);

  Data_Type<cv::Matx<float, 1, 1>> rb_cMatx11f = define_class_under<cv::Matx<float, 1, 1>>(rb_mCv, "Matx11f");
  rb_cMatx11f.define(&Matx_builder<Data_Type<cv::Matx<float, 1, 1>>, float, 1, 1>);

  Data_Type<cv::Matx<double, 1, 1>> rb_cMatx11d = define_class_under<cv::Matx<double, 1, 1>>(rb_mCv, "Matx11d");
  rb_cMatx11d.define(&Matx_builder<Data_Type<cv::Matx<double, 1, 1>>, double, 1, 1>);
}