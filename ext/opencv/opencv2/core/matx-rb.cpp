#include <opencv2/core.hpp>
#include <opencv2/core/matx.hpp>
#include "traits-rb.hpp"
#include "matx-rb.hpp"

using namespace Rice;

Rice::Class rb_cMatx44d;

template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_builder(Data_Type_T& klass)
{
  klass.define_constant("Rows", (int)cv::Matx<_Tp, m, n>::rows).
    define_constant("Cols", (int)cv::Matx<_Tp, m, n>::cols).
    define_constant("Channels", (int)cv::Matx<_Tp, m, n>::channels).
    define_constant("Shortdim", (int)cv::Matx<_Tp, m, n>::shortdim).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>>()).
   /* define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).*/
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const _Tp*>(),
      Arg("vals")).
    define_singleton_function("all", &cv::Matx<_Tp, m, n>::all,
      Arg("alpha")).
    define_singleton_function("zeros", &cv::Matx<_Tp, m, n>::zeros).
    define_singleton_function("ones", &cv::Matx<_Tp, m, n>::ones).
    define_singleton_function("eye", &cv::Matx<_Tp, m, n>::eye).
    define_singleton_function<cv::Matx<_Tp, m, n>(*)(const cv::Matx<_Tp, m, n>::diag_type&)>("diag", &cv::Matx<_Tp, m, n>::diag,
      Arg("d")).
    //define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randu", &cv::Matx<_Tp, m, n>::randu,
    //  Arg("a"), Arg("b")).
    //define_singleton_function<cv::Matx<_Tp, m, n>(*)(_Tp, _Tp)>("randn", &cv::Matx<_Tp, m, n>::randn,
    //  Arg("a"), Arg("b")).
    template define_method<_Tp(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("dot", &cv::Matx<_Tp, m, n>::dot,
      Arg("v")).
    define_method("ddot", &cv::Matx<_Tp, m, n>::ddot,
      Arg("v")).
    define_method("row", &cv::Matx<_Tp, m, n>::row,
      Arg("i")).
    define_method("col", &cv::Matx<_Tp, m, n>::col,
      Arg("i")).
    template define_method<cv::Matx<_Tp, m, n>::diag_type(cv::Matx<_Tp, m, n>::*)() const>("diag", &cv::Matx<_Tp, m, n>::diag).
    template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)() const>("t", &cv::Matx<_Tp, m, n>::t).
    //template define_method<cv::Matx<_Tp, n, m>(cv::Matx<_Tp, m, n>::*)(int, bool*) const>("inv", &cv::Matx<_Tp, m, n>::inv,
    //  Arg("method"), Arg("p_is_ok") = NULL).
   // template define_method<cv::Vec<_Tp, n>(cv::Matx<_Tp, m, n>::*)(const cv::Vec<_Tp, m>&, int) const>("solve", &cv::Matx<_Tp, m, n>::solve,
    //  Arg("rhs"), Arg("method")).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("mul", &cv::Matx<_Tp, m, n>::mul,
      Arg("a")).
    template define_method<cv::Matx<_Tp, m, n>(cv::Matx<_Tp, m, n>::*)(const cv::Matx<_Tp, m, n>&) const>("div", &cv::Matx<_Tp, m, n>::div,
      Arg("a")).
    template define_method<const _Tp&(cv::Matx<_Tp, m, n>::*)(int, int) const>("()", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col")).
    template define_method<_Tp& (cv::Matx<_Tp, m, n>::*)(int, int)>("()", &cv::Matx<_Tp, m, n>::operator(),
      Arg("row"), Arg("col"));

    if constexpr (m == 1 || n == 1)
    {
      klass.template define_method<const _Tp& (cv::Matx<_Tp, m, n>::*)(int) const>("()", &cv::Matx<_Tp, m, n>::operator(),
        Arg("i")).
        template define_method<_Tp& (cv::Matx<_Tp, m, n>::*)(int)>("()", &cv::Matx<_Tp, m, n>::operator(),
          Arg("i"));
    }

    klass.define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_SubOp>(),
      Arg("a"), Arg("b"), Arg("")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_MulOp>(),
      Arg("a"), Arg("b"), Arg("")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const cv::Matx<_Tp, m, n>&, const cv::Matx<_Tp, m, n>&, cv::Matx_DivOp>(),
      Arg("a"), Arg("b"), Arg("")).
    define_constructor(Constructor<cv::Matx::Matx<_Tp, m, n>, const cv::Matx<_Tp, n, m>&, cv::Matx_TOp>(),
      Arg("a"), Arg(""));

    klass.define_method("inspect", [](const cv::Matx::Matx<_Tp, m, n>& self) -> std::string
      {
        std::ostringstream stream;
        stream << self;
        return stream.str();
      });

    // Match cv::Mat API
    klass.define_method("rows", [](const cv::Matx<_Tp, m, n>& self) -> int
    {
        return (int)cv::Matx<_Tp, m, n>::rows;
    }).
    define_method("cols", [](const cv::Matx<_Tp, m, n>& self) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::cols;
    }).
    define_method("channels", [](const cv::Matx<_Tp, m, n>& self) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::channels;
    }).
    define_method("shortdim", [](const cv::Matx<_Tp, m, n>& self) -> int
    {
      return (int)cv::Matx<_Tp, m, n>::shortdim;
    });
};

template<typename Data_Type_T, typename _Tp, int cn>
inline void Vec_builder(Data_Type_T& klass)
{
  klass.define_constant("Channels", (int)cv::Vec<_Tp, cn>::channels).
   // define_constant("_dummy_enum_finalizer", (int)cv::Vec<_Tp, cn>::_dummy_enum_finalizer).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>>()).
   /* define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp>(),
      Arg("v0")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp>(),
      Arg("v0"), Arg("v1")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp, _Tp>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13")).*/
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, const _Tp*>(),
      Arg("values")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, const cv::Vec<_Tp, cn>&>(),
      Arg("v")).
    define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp)>("all", &cv::Vec<_Tp, cn>::all,
      Arg("alpha")).
    define_singleton_function<cv::Vec<_Tp, cn>(*)()>("ones", &cv::Vec<_Tp, cn>::ones).
    //define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randn", &cv::Vec<_Tp, cn>::randn,
    //  Arg("a"), Arg("b")).
    //define_singleton_function<cv::Vec<_Tp, cn>(*)(_Tp, _Tp)>("randu", &cv::Vec<_Tp, cn>::randu,
    //  Arg("a"), Arg("b")).
    define_singleton_function<cv::Vec<_Tp, cn>(*)()>("zeros", &cv::Vec<_Tp, cn>::zeros).
    template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("mul", &cv::Vec<_Tp, cn>::mul,
      Arg("v")).
    //template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)() const>("conj", &cv::Vec<_Tp, cn>::conj).
    //template define_method<cv::Vec<_Tp, cn>(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&) const>("cross", &cv::Vec<_Tp, cn>::cross,
      //Arg("v")).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("[]", &cv::Vec<_Tp, cn>::operator[],
      Arg("i")).
    define_method("[]=", [](cv::Vec<_Tp, cn>&self, int index, _Tp & value)
    {
      self[index] = value;
    }).
    template define_method<const _Tp&(cv::Vec<_Tp, cn>::*)(int) const>("()", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    template define_method<_Tp&(cv::Vec<_Tp, cn>::*)(int)>("()", &cv::Vec<_Tp, cn>::operator(),
      Arg("i")).
    template define_method<cv::Vec<_Tp, cn>&(cv::Vec<_Tp, cn>::*)(const cv::Vec<_Tp, cn>&)>("=", &cv::Vec<_Tp, cn>::operator=,
      Arg("rhs")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_AddOp>(),
      Arg("a"), Arg("b"), Arg("")).
    define_constructor(Constructor<cv::Vec::Vec<_Tp, cn>, const cv::Matx<_Tp, cn, 1>&, const cv::Matx<_Tp, cn, 1>&, cv::Matx_SubOp>(),
      Arg("a") = 1, Arg("b") = 1, Arg("")).
    define_method("inspect", [](const cv::Vec<_Tp, cn>& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    }).
    define_method("to_a", [](const cv::Vec<_Tp, cn>& self) -> VALUE
    {
      Rice::Array result((long)cn);
      for (int i = 0; i < cn; i++)
      {
        result.push(self[i]);
      }
      return result.value();
    }, Return().setValue());
};


void Init_Matx()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvMatxAddOp = define_class_under<cv::Matx_AddOp>(rb_mCv, "MatxAddOp").
    define_constructor(Constructor<cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Matx_AddOp, const cv::Matx_AddOp&>(),
      Arg(""));
  
  Class rb_cCvMatxSubOp = define_class_under<cv::Matx_SubOp>(rb_mCv, "MatxSubOp").
    define_constructor(Constructor<cv::Matx_SubOp>()).
    define_constructor(Constructor<cv::Matx_SubOp, const cv::Matx_SubOp&>(),
      Arg(""));
  
  Class rb_cCvMatxScaleOp = define_class_under<cv::Matx_ScaleOp>(rb_mCv, "MatxScaleOp").
    define_constructor(Constructor<cv::Matx_ScaleOp>()).
    define_constructor(Constructor<cv::Matx_ScaleOp, const cv::Matx_ScaleOp&>(),
      Arg(""));
  
  Class rb_cCvMatxMulOp = define_class_under<cv::Matx_MulOp>(rb_mCv, "MatxMulOp").
    define_constructor(Constructor<cv::Matx_MulOp>()).
    define_constructor(Constructor<cv::Matx_MulOp, const cv::Matx_MulOp&>(),
      Arg(""));
  
  Class rb_cCvMatxDivOp = define_class_under<cv::Matx_DivOp>(rb_mCv, "MatxDivOp").
    define_constructor(Constructor<cv::Matx_DivOp>()).
    define_constructor(Constructor<cv::Matx_DivOp, const cv::Matx_DivOp&>(),
      Arg(""));
  
  Class rb_cCvMatxMatMulOp = define_class_under<cv::Matx_MatMulOp>(rb_mCv, "MatxMatMulOp").
    define_constructor(Constructor<cv::Matx_MatMulOp>()).
    define_constructor(Constructor<cv::Matx_MatMulOp, const cv::Matx_MatMulOp&>(),
      Arg(""));
  
  Class rb_cCvMatxTOp = define_class_under<cv::Matx_TOp>(rb_mCv, "MatxTOp").
    define_constructor(Constructor<cv::Matx_TOp>()).
    define_constructor(Constructor<cv::Matx_TOp, const cv::Matx_TOp&>(),
      Arg(""));
  
  Class rb_cMatx12f = define_class_under<cv::Matx<float, 1, 2>>(rb_mCv, "Matx12f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 2>>, float, 1, 2>);
  
  Class rb_cMatx12d = define_class_under<cv::Matx<double, 1, 2>>(rb_mCv, "Matx12d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 2>>, double, 1, 2>);
  
  Class rb_cMatx13f = define_class_under<cv::Matx<float, 1, 3>>(rb_mCv, "Matx13f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 3>>, float, 1, 3>);
  
  Class rb_cMatx13d = define_class_under<cv::Matx<double, 1, 3>>(rb_mCv, "Matx13d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 3>>, double, 1, 3>);
  
  Class rb_cMatx14f = define_class_under<cv::Matx<float, 1, 4>>(rb_mCv, "Matx14f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 4>>, float, 1, 4>);
  
  Class rb_cMatx14d = define_class_under<cv::Matx<double, 1, 4>>(rb_mCv, "Matx14d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 4>>, double, 1, 4>);
  
  Class rb_cMatx16f = define_class_under<cv::Matx<float, 1, 6>>(rb_mCv, "Matx16f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 6>>, float, 1, 6>);
  
  Class rb_cMatx16d = define_class_under<cv::Matx<double, 1, 6>>(rb_mCv, "Matx16d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 6>>, double, 1, 6>);
  
  Class rb_cMatx21f = define_class_under<cv::Matx<float, 2, 1>>(rb_mCv, "Matx21f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 1>>, float, 2, 1>);
  
  Class rb_cMatx21d = define_class_under<cv::Matx<double, 2, 1>>(rb_mCv, "Matx21d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 1>>, double, 2, 1>);
  
  Class rb_cMatx31f = define_class_under<cv::Matx<float, 3, 1>>(rb_mCv, "Matx31f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 1>>, float, 3, 1>);
  
  Class rb_cMatx31d = define_class_under<cv::Matx<double, 3, 1>>(rb_mCv, "Matx31d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 1>>, double, 3, 1>);
  
  Class rb_cMatx41f = define_class_under<cv::Matx<float, 4, 1>>(rb_mCv, "Matx41f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 1>>, float, 4, 1>);
  
  Class rb_cMatx41d = define_class_under<cv::Matx<double, 4, 1>>(rb_mCv, "Matx41d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 1>>, double, 4, 1>);
  
  Class rb_cMatx61f = define_class_under<cv::Matx<float, 6, 1>>(rb_mCv, "Matx61f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 1>>, float, 6, 1>);
  
  Class rb_cMatx61d = define_class_under<cv::Matx<double, 6, 1>>(rb_mCv, "Matx61d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 1>>, double, 6, 1>);
  
  Class rb_cMatx22f = define_class_under<cv::Matx<float, 2, 2>>(rb_mCv, "Matx22f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 2>>, float, 2, 2>);
  
  Class rb_cMatx22d = define_class_under<cv::Matx<double, 2, 2>>(rb_mCv, "Matx22d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 2>>, double, 2, 2>);
  
  Class rb_cMatx23f = define_class_under<cv::Matx<float, 2, 3>>(rb_mCv, "Matx23f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 3>>, float, 2, 3>);
  
  Class rb_cMatx23d = define_class_under<cv::Matx<double, 2, 3>>(rb_mCv, "Matx23d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 3>>, double, 2, 3>);
  
  Class rb_cMatx32f = define_class_under<cv::Matx<float, 3, 2>>(rb_mCv, "Matx32f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 2>>, float, 3, 2>);
  
  Class rb_cMatx32d = define_class_under<cv::Matx<double, 3, 2>>(rb_mCv, "Matx32d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 2>>, double, 3, 2>);
  
  Class rb_cMatx33f = define_class_under<cv::Matx<float, 3, 3>>(rb_mCv, "Matx33f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 3>>, float, 3, 3>);
  
  Class rb_cMatx33d = define_class_under<cv::Matx<double, 3, 3>>(rb_mCv, "Matx33d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 3>>, double, 3, 3>);
  
  Class rb_cMatx34f = define_class_under<cv::Matx<float, 3, 4>>(rb_mCv, "Matx34f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 4>>, float, 3, 4>);
  
  Class rb_cMatx34d = define_class_under<cv::Matx<double, 3, 4>>(rb_mCv, "Matx34d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 4>>, double, 3, 4>);
  
  Class rb_cMatx43f = define_class_under<cv::Matx<float, 4, 3>>(rb_mCv, "Matx43f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 3>>, float, 4, 3>);
  
  Class rb_cMatx43d = define_class_under<cv::Matx<double, 4, 3>>(rb_mCv, "Matx43d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 3>>, double, 4, 3>);
  
  Class rb_cMatx44f = define_class_under<cv::Matx<float, 4, 4>>(rb_mCv, "Matx44f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 4>>, float, 4, 4>);
  
  Class rb_cMatx44d = define_class_under<cv::Matx<double, 4, 4>>(rb_mCv, "Matx44d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 4>>, double, 4, 4>);
  
  Class rb_cMatx66f = define_class_under<cv::Matx<float, 6, 6>>(rb_mCv, "Matx66f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 6>>, float, 6, 6>);
  
  Class rb_cMatx66d = define_class_under<cv::Matx<double, 6, 6>>(rb_mCv, "Matx66d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 6>>, double, 6, 6>);
  
  Class rb_cMatx11b = define_class_under<cv::Matx<unsigned char, 1, 1 >>(rb_mCv, "Matx11b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 1>>, unsigned char, 1, 1>);

  Class rb_cMatx12b = define_class_under<cv::Matx<unsigned char, 1, 2 >>(rb_mCv, "Matx12b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 2>>, unsigned char, 1, 2>);

  Class rb_cMatx13b = define_class_under<cv::Matx<unsigned char, 1, 3 >>(rb_mCv, "Matx13b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 3>>, unsigned char, 1, 3>);

  Class rb_cMatx14b = define_class_under<cv::Matx<unsigned char, 1, 4 >>(rb_mCv, "Matx14b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 1, 4>>, unsigned char, 1, 4>);

  Class rb_cMatx21b = define_class_under<cv::Matx<unsigned char, 2, 1 >>(rb_mCv, "Matx21b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 2, 1>>, unsigned char, 2, 1>);

  Class rb_cVec2b = define_class_under<cv::Vec<unsigned char, 2>, cv::Matx<unsigned char, 2, 1>>(rb_mCv, "Vec2b").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 2>>, unsigned char, 2>);
  
  Class rb_cMatx31b = define_class_under<cv::Matx<unsigned char, 3, 1 >>(rb_mCv, "Matx31b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 3, 1>>, unsigned char, 3, 1>);

  Class rb_cVec3b = define_class_under<cv::Vec<unsigned char, 3>, cv::Matx<unsigned char, 3, 1>>(rb_mCv, "Vec3b").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 3>>, unsigned char, 3>);
  
  Class rb_cMatx41b = define_class_under<cv::Matx<unsigned char, 4, 1 >>(rb_mCv, "Matx41b").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 4, 1>>, unsigned char, 4, 1>);

  Class rb_cVec4b = define_class_under<cv::Vec<unsigned char, 4>, cv::Matx<unsigned char, 4, 1>>(rb_mCv, "Vec4b").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned char, 4>>, unsigned char, 4>);
  
  Class rb_cMatx11s = define_class_under<cv::Matx<short, 1, 1 >>(rb_mCv, "Matx11s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 1>>, short, 1, 1>);

  Class rb_cMatx12s = define_class_under<cv::Matx<short, 1, 2 >>(rb_mCv, "Matx12s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 2>>, short, 1, 2>);

  Class rb_cMatx13s = define_class_under<cv::Matx<short, 1, 3 >>(rb_mCv, "Matx13s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 3>>, short, 1, 3>);

  Class rb_cMatx14s = define_class_under<cv::Matx<short, 1, 4 >>(rb_mCv, "Matx14s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 1, 4>>, short, 1, 4>);

  Class rb_cMatx21s = define_class_under<cv::Matx<short, 2, 1 >>(rb_mCv, "Matx21s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 2, 1>>, short, 2, 1>);

  Class rb_cVec2s = define_class_under<cv::Vec<short, 2>, cv::Matx<short, 2, 1>>(rb_mCv, "Vec2s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 2>>, short, 2>);
  
  Class rb_cMatx31s = define_class_under<cv::Matx<short, 3, 1 >>(rb_mCv, "Matx31s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 3, 1>>, short, 3, 1>);

  Class rb_cVec3s = define_class_under<cv::Vec<short, 3>, cv::Matx<short, 3, 1>>(rb_mCv, "Vec3s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 3>>, short, 3>);
  
  Class rb_cMatx41s = define_class_under<cv::Matx<short, 4, 1 >>(rb_mCv, "Matx41s").
    define(&Matx_builder<Data_Type<cv::Matx<short, 4, 1>>, short, 4, 1>);

  Class rb_cVec4s = define_class_under<cv::Vec<short, 4>, cv::Matx<short, 4, 1>>(rb_mCv, "Vec4s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 4>>, short, 4>);
  
  Class rb_cMatx11w = define_class_under<cv::Matx<unsigned short, 1, 1 >>(rb_mCv, "Matx11w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 1>>, unsigned short, 1, 1>);

  Class rb_cMatx12w = define_class_under<cv::Matx<unsigned short, 1, 2 >>(rb_mCv, "Matx12w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 2>>, unsigned short, 1, 2>);

  Class rb_cMatx13w = define_class_under<cv::Matx<unsigned short, 1, 3 >>(rb_mCv, "Matx13w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 3>>, unsigned short, 1, 3>);

  Class rb_cMatx14w = define_class_under<cv::Matx<unsigned short, 1, 4 >>(rb_mCv, "Matx14w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 1, 4>>, unsigned short, 1, 4>);

  Class rb_cMatx21w = define_class_under<cv::Matx<unsigned short, 2, 1 >>(rb_mCv, "Matx21w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 2, 1>>, unsigned short, 2, 1>);

  Class rb_cVec2w = define_class_under<cv::Vec<unsigned short, 2>, cv::Matx<unsigned short, 2, 1>>(rb_mCv, "Vec2w").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 2>>, unsigned short, 2>);
  
  Class rb_cMatx31w = define_class_under<cv::Matx<unsigned short, 3, 1 >>(rb_mCv, "Matx31w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 3, 1>>, unsigned short, 3, 1>);

  Class rb_cVec3w = define_class_under<cv::Vec<unsigned short, 3>, cv::Matx<unsigned short, 3, 1>>(rb_mCv, "Vec3w").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 3>>, unsigned short, 3>);
  
  Class rb_cMatx41w = define_class_under<cv::Matx<unsigned short, 4, 1 >>(rb_mCv, "Matx41w").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 4, 1>>, unsigned short, 4, 1>);
  
  Class rb_cVec4w = define_class_under<cv::Vec<unsigned short, 4>, cv::Matx<unsigned short, 4, 1>>(rb_mCv, "Vec4w").
    define(&Vec_builder<Data_Type<cv::Vec<unsigned short, 4>>, unsigned short, 4>);
  
  Class rb_cMatx11i = define_class_under<cv::Matx<int, 1, 1 >>(rb_mCv, "Matx11i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 1>>, int, 1, 1>);

  Class rb_cMatx12i = define_class_under<cv::Matx<int, 1, 2 >>(rb_mCv, "Matx12i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 2>>, int, 1, 2>);

  Class rb_cMatx13i = define_class_under<cv::Matx<int, 1, 3 >>(rb_mCv, "Matx13i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 3>>, int, 1, 3>);

  Class rb_cMatx14i = define_class_under<cv::Matx<int, 1, 4 >>(rb_mCv, "Matx14i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 4>>, int, 1, 4>);

  Class rb_cMatx16i = define_class_under<cv::Matx<int, 1, 6 >>(rb_mCv, "Matx16i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 6>>, int, 1, 6>);

  Class rb_cMatx18i = define_class_under<cv::Matx<int, 1, 8 >>(rb_mCv, "Matx18i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 1, 8>>, int, 1, 8>);

  Class rb_cMatx21i = define_class_under<cv::Matx<int, 2, 1 >>(rb_mCv, "Matx21i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 2, 1>>, int, 2, 1>);

  Class rb_cVec2i = define_class_under<cv::Vec<int, 2>, cv::Matx<int, 2, 1>>(rb_mCv, "Vec2i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 2>>, int, 2>);
  
  Class rb_cMatx31i = define_class_under<cv::Matx<int, 3, 1 >>(rb_mCv, "Matx31i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 3, 1>>, int, 3, 1>);

  Class rb_cVec3i = define_class_under<cv::Vec<int, 3>, cv::Matx<int, 3, 1>>(rb_mCv, "Vec3i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 3>>, int, 3>);
  
  Class rb_cMatx41i = define_class_under<cv::Matx<int, 4, 1 >>(rb_mCv, "Matx41i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 4, 1>>, int, 4, 1>);

  Class rb_cVec4i = define_class_under<cv::Vec<int, 4>, cv::Matx<int, 4, 1>>(rb_mCv, "Vec4i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 4>>, int, 4>);
  
  Class rb_cMatx61i = define_class_under<cv::Matx<int, 6, 1 >>(rb_mCv, "Matx61i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 6, 1>>, int, 6, 1>);

  Class rb_cVec6i = define_class_under<cv::Vec<int, 6>, cv::Matx<int, 6, 1>>(rb_mCv, "Vec6i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 6>>, int, 6>);
  
  Class rb_cMatx81i = define_class_under<cv::Matx<int, 8, 1 >>(rb_mCv, "Matx81i").
    define(&Matx_builder<Data_Type<cv::Matx<int, 8, 1>>, int, 8, 1>);

  Class rb_cVec8i = define_class_under<cv::Vec<int, 8>, cv::Matx<int, 8, 1>>(rb_mCv, "Vec8i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 8>>, int, 8>);
  
  Class rb_cVec2f = define_class_under<cv::Vec<float, 2>, cv::Matx<float, 2, 1>>(rb_mCv, "Vec2f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 2>>, float, 2>);
  
  Class rb_cVec3f = define_class_under<cv::Vec<float, 3>, cv::Matx<float, 3, 1>>(rb_mCv, "Vec3f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 3>>, float, 3>);
  
  Class rb_cVec4f = define_class_under<cv::Vec<float, 4>, cv::Matx<float, 4, 1>>(rb_mCv, "Vec4f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 4>>, float, 4>);
  
  Class rb_cVec6f = define_class_under<cv::Vec<float, 6>, cv::Matx<float, 6, 1>>(rb_mCv, "Vec6f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 6>>, float, 6>);
  
  Class rb_cVec2d = define_class_under<cv::Vec<double, 2>, cv::Matx<double, 2, 1>>(rb_mCv, "Vec2d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 2>>, double, 2>);
  
  Class rb_cVec3d = define_class_under<cv::Vec<double, 3>, cv::Matx<double, 3, 1>>(rb_mCv, "Vec3d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 3>>, double, 3>);
  
  Class rb_cVec4d = define_class_under<cv::Vec<double, 4>, cv::Matx<double, 4, 1>>(rb_mCv, "Vec4d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 4>>, double, 4>);
  
  Class rb_cVec6d = define_class_under<cv::Vec<double, 6>, cv::Matx<double, 6, 1>>(rb_mCv, "Vec6d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 6>>, double, 6>);

  // Manually added
  Class rb_cMatx11f = define_class_under<cv::Matx<float, 1, 1>>(rb_mCv, "Matx11f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 1>>, float, 1, 1>);

  Class rb_cMatx11d = define_class_under<cv::Matx<double, 1, 1>>(rb_mCv, "Matx11d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 1>>, double, 1, 1>);

  // Requires adding long long (int64) support from OpenCV5
  Class rb_cVec2l = define_class_under<cv::Vec<int64, 2>>(rb_mCv, "Vec2l").
    define(&Vec_builder<Data_Type<cv::Vec<int64, 2>>, int64, 2>);
}