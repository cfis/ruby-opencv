#include <opencv2/core/hal/intrin_neon.hpp>
#include "intrin_neon-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvVFloat32x4;
Rice::Class rb_cCvVInt16x8;
Rice::Class rb_cCvVInt32x4;
Rice::Class rb_cCvVInt64x2;
Rice::Class rb_cCvVInt8x16;
Rice::Class rb_cCvVUint16x8;
Rice::Class rb_cCvVUint32x4;
Rice::Class rb_cCvVUint64x2;
Rice::Class rb_cCvVUint8x16;

template<typename Data_Type_T, typename T>
inline void VTraits_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function("vlanes", &cv::VTraits<T>::vlanes).
    define_constant("Max_nlanes", (int)cv::VTraits<T>::max_nlanes).
    define_constant("Nlanes", (int)cv::VTraits<T>::nlanes);
};
void Init_IntrinNeon()
{
  Class(rb_cObject).define_constant("CV_SIMD128", CV_SIMD128);
  
  Class(rb_cObject).define_constant("CV_SIMD128_64F", CV_SIMD128_64F);
  
  Class(rb_cObject).define_constant("CV_NEON_AARCH64", CV_NEON_AARCH64);
  
  Module rb_mCv = define_module("Cv");
  
  rb_cCvVUint8x16 = define_class_under<cv::v_uint8x16>(rb_mCv, "VUint8x16").
    define_constructor(Constructor<cv::v_uint8x16>()).
    define_constructor(Constructor<cv::v_uint8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint8x16, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_attr("val", &cv::v_uint8x16::val);
  
  rb_cCvVInt8x16 = define_class_under<cv::v_int8x16>(rb_mCv, "VInt8x16").
    define_constructor(Constructor<cv::v_int8x16>()).
    define_constructor(Constructor<cv::v_int8x16, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int8x16, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar, schar>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7"), Arg("v8"), Arg("v9"), Arg("v10"), Arg("v11"), Arg("v12"), Arg("v13"), Arg("v14"), Arg("v15")).
    define_attr("val", &cv::v_int8x16::val);
  
  rb_cCvVUint16x8 = define_class_under<cv::v_uint16x8>(rb_mCv, "VUint16x8").
    define_constructor(Constructor<cv::v_uint16x8>()).
    define_constructor(Constructor<cv::v_uint16x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint16x8, ushort, ushort, ushort, ushort, ushort, ushort, ushort, ushort>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_attr("val", &cv::v_uint16x8::val);
  
  rb_cCvVInt16x8 = define_class_under<cv::v_int16x8>(rb_mCv, "VInt16x8").
    define_constructor(Constructor<cv::v_int16x8>()).
    define_constructor(Constructor<cv::v_int16x8, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int16x8, short, short, short, short, short, short, short, short>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3"), Arg("v4"), Arg("v5"), Arg("v6"), Arg("v7")).
    define_attr("val", &cv::v_int16x8::val);
  
  rb_cCvVUint32x4 = define_class_under<cv::v_uint32x4>(rb_mCv, "VUint32x4").
    define_constructor(Constructor<cv::v_uint32x4>()).
    define_constructor(Constructor<cv::v_uint32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint32x4, unsigned int, unsigned int, unsigned int, unsigned int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_attr("val", &cv::v_uint32x4::val);
  
  rb_cCvVInt32x4 = define_class_under<cv::v_int32x4>(rb_mCv, "VInt32x4").
    define_constructor(Constructor<cv::v_int32x4>()).
    define_constructor(Constructor<cv::v_int32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int32x4, int, int, int, int>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_attr("val", &cv::v_int32x4::val);
  
  rb_cCvVFloat32x4 = define_class_under<cv::v_float32x4>(rb_mCv, "VFloat32x4").
    define_constructor(Constructor<cv::v_float32x4>()).
    define_constructor(Constructor<cv::v_float32x4, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_float32x4, float, float, float, float>(),
      Arg("v0"), Arg("v1"), Arg("v2"), Arg("v3")).
    define_attr("val", &cv::v_float32x4::val);
  
  rb_cCvVUint64x2 = define_class_under<cv::v_uint64x2>(rb_mCv, "VUint64x2").
    define_constructor(Constructor<cv::v_uint64x2>()).
    define_constructor(Constructor<cv::v_uint64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_uint64x2, uint64, uint64>(),
      Arg("v0"), Arg("v1")).
    define_attr("val", &cv::v_uint64x2::val);
  
  rb_cCvVInt64x2 = define_class_under<cv::v_int64x2>(rb_mCv, "VInt64x2").
    define_constructor(Constructor<cv::v_int64x2>()).
    define_constructor(Constructor<cv::v_int64x2, int>(),
      Arg("v")).
    define_constructor(Constructor<cv::v_int64x2, int64, int64>(),
      Arg("v0"), Arg("v1")).
    define_attr("val", &cv::v_int64x2::val);
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_pack_b", &cv::v_pack_b,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"), Arg("e"), Arg("f"), Arg("g"), Arg("h"));
  
  rb_mCv.define_module_function("v_matmul", &cv::v_matmul,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("m3"));
  
  rb_mCv.define_module_function("v_matmuladd", &cv::v_matmuladd,
    Arg("v"), Arg("m0"), Arg("m1"), Arg("m2"), Arg("a"));
  
  rb_mCv.define_module_function("v_div", &cv::v_div,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int8x16&, const cv::v_int8x16&, cv::v_int16x8&, cv::v_int16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, cv::v_uint16x8&, cv::v_uint16x8&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_int16x8&, const cv::v_int16x8&, cv::v_int32x4&, cv::v_int32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, cv::v_uint32x4&, cv::v_uint32x4&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<void(*)(const cv::v_uint32x4&, const cv::v_uint32x4&, cv::v_uint64x2&, cv::v_uint64x2&)>("v_mul_expand", &cv::v_mul_expand,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_mul_hi", &cv::v_mul_hi,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int32x4&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int64x2&)>("v_dotprod", &cv::v_dotprod,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint32x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&, const cv::v_int32x4&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint64x2&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int64x2&)>("v_dotprod_expand", &cv::v_dotprod_expand,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int32x4&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int64x2&)>("v_dotprod_fast", &cv::v_dotprod_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint8x16&, const cv::v_uint8x16&, const cv::v_uint32x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int8x16&, const cv::v_int8x16&, const cv::v_int32x4&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint16x8&, const cv::v_uint16x8&, const cv::v_uint64x2&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int16x8&, const cv::v_int16x8&, const cv::v_int64x2&)>("v_dotprod_expand_fast", &cv::v_dotprod_expand_fast,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_not", &cv::v_not,
    Arg("a"));
  
  rb_mCv.define_module_function("v_sqrt", &cv::v_sqrt,
    Arg("x"));
  
  rb_mCv.define_module_function("v_invsqrt", &cv::v_invsqrt,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(cv::v_float32x4)>("v_abs", &cv::v_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_eq", &cv::v_eq,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&, const cv::v_uint64x2&)>("v_ne", &cv::v_ne,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int64x2&, const cv::v_int64x2&)>("v_eq", &cv::v_eq,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int64x2&, const cv::v_int64x2&)>("v_ne", &cv::v_ne,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("v_not_nan", &cv::v_not_nan,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_absdiffs", &cv::v_absdiffs,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("v_magnitude", &cv::v_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("v_sqr_magnitude", &cv::v_sqr_magnitude,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_fma", &cv::v_fma,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&, const cv::v_float32x4&, const cv::v_float32x4&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&, const cv::v_int32x4&, const cv::v_int32x4&)>("v_muladd", &cv::v_muladd,
    Arg("a"), Arg("b"), Arg("c"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<uint64(*)(const cv::v_uint64x2&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function<int64(*)(const cv::v_int64x2&)>("v_reduce_sum", &cv::v_reduce_sum,
    Arg("a"));
  
  rb_mCv.define_module_function("v_reduce_sum4", &cv::v_reduce_sum4,
    Arg("a"), Arg("b"), Arg("c"), Arg("d"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint8x16&, const cv::v_uint8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int8x16&, const cv::v_int8x16&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint16x8&, const cv::v_uint16x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int16x8&, const cv::v_int16x8&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_uint32x4&, const cv::v_uint32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<unsigned int(*)(const cv::v_int32x4&, const cv::v_int32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<float(*)(const cv::v_float32x4&, const cv::v_float32x4&)>("v_reduce_sad", &cv::v_reduce_sad,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_int8x16&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_int16x8&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_int32x4&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_int64x2&)>("v_popcount", &cv::v_popcount,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x4&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x2&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x2&)>("v_signmask", &cv::v_signmask,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int8x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint8x16&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int16x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint16x8&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_float32x4&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_int64x2&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<int(*)(const cv::v_uint64x2&)>("v_scan_forward", &cv::v_scan_forward,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint64x2&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_uint64x2&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int8x16&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int16x8&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int32x4&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float32x4&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int8x16&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int16x8&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int32x4&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_float32x4&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int64x2&)>("v_check_all?", &cv::v_check_all,
    Arg("a"));
  
  rb_mCv.define_module_function<bool(*)(const cv::v_int64x2&)>("v_check_any?", &cv::v_check_any,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const uchar*)>("v_load_expand_q", &cv::v_load_expand_q,
    Arg("ptr"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const schar*)>("v_load_expand_q", &cv::v_load_expand_q,
    Arg("ptr"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const cv::v_uint64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const cv::v_int64x2&)>("v_reverse", &cv::v_reverse,
    Arg("a"));
  
  rb_mCv.define_module_function("v_round", &cv::v_round,
    Arg("a"));
  
  rb_mCv.define_module_function("v_floor", &cv::v_floor,
    Arg("a"));
  
  rb_mCv.define_module_function("v_ceil", &cv::v_ceil,
    Arg("a"));
  
  rb_mCv.define_module_function("v_trunc", &cv::v_trunc,
    Arg("a"));
  
  rb_mCv.define_module_function("v_cvt_f32", &cv::v_cvt_f32,
    Arg("a"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const schar*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const uchar*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const short*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const ushort*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int64_t*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int64x2(*)(const int64_t*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const uint64_t*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_uint64x2(*)(const uint64_t*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut_pairs", &cv::v_lut_pairs,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const int*)>("v_lut_quads", &cv::v_lut_quads,
    Arg("tab"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const int*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const unsigned int*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const float*, const cv::v_int32x4&)>("v_lut", &cv::v_lut,
    Arg("tab"), Arg("idxvec"));
  
  rb_mCv.define_module_function("v_lut_deinterleave", &cv::v_lut_deinterleave,
    Arg("tab"), Arg("idxvec"), Arg("x"), Arg("y"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_interleave_quads", &cv::v_interleave_quads,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_interleave_pairs", &cv::v_interleave_pairs,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int8x16(*)(const cv::v_int8x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint8x16(*)(const cv::v_uint8x16&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int16x8(*)(const cv::v_int16x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint16x8(*)(const cv::v_uint16x8&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_int32x4(*)(const cv::v_int32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_uint32x4(*)(const cv::v_uint32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::v_float32x4&)>("v_pack_triplets", &cv::v_pack_triplets,
    Arg("vec"));
  
  rb_mCv.define_module_function<cv::v_float32x4(*)(const cv::hfloat*)>("v_load_expand", &cv::v_load_expand,
    Arg("ptr"));
  
  rb_mCv.define_module_function<void(*)(cv::hfloat*, const cv::v_float32x4&)>("v_pack_store", &cv::v_pack_store,
    Arg("ptr"), Arg("v"));
  
  rb_mCv.define_module_function("v_cleanup", &cv::v_cleanup);

}