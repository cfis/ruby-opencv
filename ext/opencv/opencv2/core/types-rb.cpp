#include <opencv2/core/types.hpp>
#include "types-rb.hpp"

using namespace Rice;

template<typename Data_Object_T, typename _Tp>
inline void Complex_builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Complex<_Tp>>()).
    define_constructor(Constructor<cv::Complex<_Tp>, _Tp, _Tp>()).
    template define_method<cv::Complex<_Tp>(cv::Complex<_Tp>::*)() const>("conj", &cv::Complex<_Tp>::conj).
    define_attr("re", &cv::Complex<_Tp>::re).
    define_attr("im", &cv::Complex<_Tp>::im);
};

template<typename Data_Object_T, typename _Tp>
inline void Point__builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Point_<_Tp>>()).
    define_constructor(Constructor<cv::Point_<_Tp>, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Point_<_Tp>&>()).
    define_constructor(Constructor<cv::Point_<_Tp>, cv::Point_<_Tp>&&>()).
    define_constructor(Constructor<cv::Point_<_Tp>, const cv::Size_<_Tp>&>());

  if constexpr (!std::is_same_v<_Tp, long long>)
  {
    klass.define_constructor(Constructor<cv::Point_<_Tp>, const cv::Vec<_Tp, 2>&>());
  }
  klass.
    template define_method<cv::Point_<_Tp>&(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&)>("operator=", &cv::Point_<_Tp>::operator=).
    template define_method<cv::Point_<_Tp>&(cv::Point_<_Tp>::*)(cv::Point_<_Tp>&&) noexcept>("operator=", &cv::Point_<_Tp>::operator=).
    template define_method<_Tp(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("dot", &cv::Point_<_Tp>::dot).
    template define_method<double(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("ddot", &cv::Point_<_Tp>::ddot).
    template define_method<double(cv::Point_<_Tp>::*)(const cv::Point_<_Tp>&) const>("cross", &cv::Point_<_Tp>::cross).
    template define_method<bool(cv::Point_<_Tp>::*)(const cv::Rect_<_Tp>&) const>("inside", &cv::Point_<_Tp>::inside).
    define_attr("x", &cv::Point_<_Tp>::x).
    define_attr("y", &cv::Point_<_Tp>::y);
};

template<typename Data_Object_T, typename _Tp>
inline void Point3__builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Point3_<_Tp>>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point3_<_Tp>&>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, cv::Point3_<_Tp>&&>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Point_<_Tp>&>()).
    define_constructor(Constructor<cv::Point3_<_Tp>, const cv::Vec<_Tp, 3>&>()).
    template define_method<cv::Point3_<_Tp>&(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&)>("operator=", &cv::Point3_<_Tp>::operator=).
    template define_method<cv::Point3_<_Tp>&(cv::Point3_<_Tp>::*)(cv::Point3_<_Tp>&&) noexcept>("operator=", &cv::Point3_<_Tp>::operator=).
    template define_method<_Tp(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("dot", &cv::Point3_<_Tp>::dot).
    template define_method<double(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("ddot", &cv::Point3_<_Tp>::ddot).
    template define_method<cv::Point3_<_Tp>(cv::Point3_<_Tp>::*)(const cv::Point3_<_Tp>&) const>("cross", &cv::Point3_<_Tp>::cross).
    define_attr("x", &cv::Point3_<_Tp>::x).
    define_attr("y", &cv::Point3_<_Tp>::y).
    define_attr("z", &cv::Point3_<_Tp>::z);
};

template<typename Data_Object_T, typename _Tp>
inline void Size__builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Size_<_Tp>>()).
    define_constructor(Constructor<cv::Size_<_Tp>, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Size_<_Tp>&>()).
    define_constructor(Constructor<cv::Size_<_Tp>, cv::Size_<_Tp>&&>()).
    define_constructor(Constructor<cv::Size_<_Tp>, const cv::Point_<_Tp>&>()).
    template define_method<cv::Size_<_Tp>&(cv::Size_<_Tp>::*)(const cv::Size_<_Tp>&)>("operator=", &cv::Size_<_Tp>::operator=).
    template define_method<cv::Size_<_Tp>&(cv::Size_<_Tp>::*)(cv::Size_<_Tp>&&) noexcept>("operator=", &cv::Size_<_Tp>::operator=).
    template define_method<_Tp(cv::Size_<_Tp>::*)() const>("area", &cv::Size_<_Tp>::area).
    template define_method<double(cv::Size_<_Tp>::*)() const>("aspect_ratio", &cv::Size_<_Tp>::aspectRatio).
    template define_method<bool(cv::Size_<_Tp>::*)() const>("empty", &cv::Size_<_Tp>::empty).
    define_attr("width", &cv::Size_<_Tp>::width).
    define_attr("height", &cv::Size_<_Tp>::height);
};

template<typename Data_Object_T, typename _Tp>
inline void Rect__builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Rect_<_Tp>>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Rect_<_Tp>&>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, cv::Rect_<_Tp>&&>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Size_<_Tp>&>()).
    define_constructor(Constructor<cv::Rect_<_Tp>, const cv::Point_<_Tp>&, const cv::Point_<_Tp>&>()).
    template define_method<cv::Rect_<_Tp>&(cv::Rect_<_Tp>::*)(const cv::Rect_<_Tp>&)>("operator=", &cv::Rect_<_Tp>::operator=).
    template define_method<cv::Rect_<_Tp>&(cv::Rect_<_Tp>::*)(cv::Rect_<_Tp>&&) noexcept>("operator=", &cv::Rect_<_Tp>::operator=).
    template define_method<cv::Point_<_Tp>(cv::Rect_<_Tp>::*)() const>("tl", &cv::Rect_<_Tp>::tl).
    template define_method<cv::Point_<_Tp>(cv::Rect_<_Tp>::*)() const>("br", &cv::Rect_<_Tp>::br).
    template define_method<cv::Size_<_Tp>(cv::Rect_<_Tp>::*)() const>("size", &cv::Rect_<_Tp>::size).
    template define_method<_Tp(cv::Rect_<_Tp>::*)() const>("area", &cv::Rect_<_Tp>::area).
    template define_method<bool(cv::Rect_<_Tp>::*)() const>("empty", &cv::Rect_<_Tp>::empty).
    template define_method<bool(cv::Rect_<_Tp>::*)(const cv::Point_<_Tp>&) const>("contains", &cv::Rect_<_Tp>::contains).
    define_attr("x", &cv::Rect_<_Tp>::x).
    define_attr("y", &cv::Rect_<_Tp>::y).
    define_attr("width", &cv::Rect_<_Tp>::width).
    define_attr("height", &cv::Rect_<_Tp>::height);
};

template<typename Data_Object_T, typename _Tp>
inline void Scalar__builder(Data_Object_T& klass)
{
  klass.define_constructor(Constructor<cv::Scalar_<_Tp>>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp, _Tp, _Tp, _Tp>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, _Tp>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, const cv::Scalar_<_Tp>&>()).
    define_constructor(Constructor<cv::Scalar_<_Tp>, cv::Scalar_<_Tp>&&>()).
    template define_method<cv::Scalar_<_Tp>&(cv::Scalar_<_Tp>::*)(const cv::Scalar_<_Tp>&)>("operator=", &cv::Scalar_<_Tp>::operator=).
    template define_method<cv::Scalar_<_Tp>&(cv::Scalar_<_Tp>::*)(cv::Scalar_<_Tp>&&) noexcept>("operator=", &cv::Scalar_<_Tp>::operator=).
    template define_singleton_function<cv::Scalar_<_Tp>(*)(_Tp)>("all", &cv::Scalar_<_Tp>::all).
    template define_method<cv::Scalar_<_Tp>(cv::Scalar_<_Tp>::*)(const cv::Scalar_<_Tp>&, double) const>("mul", &cv::Scalar_<_Tp>::mul).
    template define_method<cv::Scalar_<_Tp>(cv::Scalar_<_Tp>::*)() const>("conj", &cv::Scalar_<_Tp>::conj).
    template define_method<bool(cv::Scalar_<_Tp>::*)() const>("is_real", &cv::Scalar_<_Tp>::isReal);
};


extern "C"
void Init_Types()
{
  Module rb_mCv = define_module("Cv");
  
  Data_Type<cv::Complex<float>> rb_cComplexf = define_class_under<cv::Complex<float>>(rb_mCv, "Complexf");
  rb_cComplexf.define(&Complex_builder<Data_Type<cv::Complex<float>>, float>);
  
  Data_Type<cv::Complex<double>> rb_cComplexd = define_class_under<cv::Complex<double>>(rb_mCv, "Complexd");
  rb_cComplexd.define(&Complex_builder<Data_Type<cv::Complex<double>>, double>);
  
  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");
  
  
  Data_Type<cv::Point_<int>> rb_cPoint2i = define_class_under<cv::Point_<int>>(rb_mCv, "Point2i");
  rb_cPoint2i.define(&Point__builder<Data_Type<cv::Point_<int>>, int>);
  
  Data_Type<cv::Point_<long long>> rb_cPoint2l = define_class_under<cv::Point_<long long>>(rb_mCv, "Point2l");
  rb_cPoint2l.define(&Point__builder<Data_Type<cv::Point_<long long>>, long long>);
  
  Data_Type<cv::Point_<float>> rb_cPoint2f = define_class_under<cv::Point_<float>>(rb_mCv, "Point2f");
  rb_cPoint2f.define(&Point__builder<Data_Type<cv::Point_<float>>, float>);
  
  Data_Type<cv::Point_<double>> rb_cPoint2d = define_class_under<cv::Point_<double>>(rb_mCv, "Point2d");
  rb_cPoint2d.define(&Point__builder<Data_Type<cv::Point_<double>>, double>);
  
  Data_Type<cv::Point3_<int>> rb_cPoint3i = define_class_under<cv::Point3_<int>>(rb_mCv, "Point3i");
  rb_cPoint3i.define(&Point3__builder<Data_Type<cv::Point3_<int>>, int>);
  
  Data_Type<cv::Point3_<float>> rb_cPoint3f = define_class_under<cv::Point3_<float>>(rb_mCv, "Point3f");
  rb_cPoint3f.define(&Point3__builder<Data_Type<cv::Point3_<float>>, float>);
  
  Data_Type<cv::Point3_<double>> rb_cPoint3d = define_class_under<cv::Point3_<double>>(rb_mCv, "Point3d");
  rb_cPoint3d.define(&Point3__builder<Data_Type<cv::Point3_<double>>, double>);
  
  Data_Type<cv::Size_<int>> rb_cSize2i = define_class_under<cv::Size_<int>>(rb_mCv, "Size2i");
  rb_cSize2i.define(&Size__builder<Data_Type<cv::Size_<int>>, int>);
  
  Data_Type<cv::Size_<long long>> rb_cSize2l = define_class_under<cv::Size_<long long>>(rb_mCv, "Size2l");
  rb_cSize2l.define(&Size__builder<Data_Type<cv::Size_<long long>>, long long>);
  
  Data_Type<cv::Size_<float>> rb_cSize2f = define_class_under<cv::Size_<float>>(rb_mCv, "Size2f");
  rb_cSize2f.define(&Size__builder<Data_Type<cv::Size_<float>>, float>);
  
  Data_Type<cv::Size_<double>> rb_cSize2d = define_class_under<cv::Size_<double>>(rb_mCv, "Size2d");
  rb_cSize2d.define(&Size__builder<Data_Type<cv::Size_<double>>, double>);
  
  Data_Type<cv::Rect_<int>> rb_cRect2i = define_class_under<cv::Rect_<int>>(rb_mCv, "Rect2i");
  rb_cRect2i.define(&Rect__builder<Data_Type<cv::Rect_<int>>, int>);
  
  Data_Type<cv::Rect_<float>> rb_cRect2f = define_class_under<cv::Rect_<float>>(rb_mCv, "Rect2f");
  rb_cRect2f.define(&Rect__builder<Data_Type<cv::Rect_<float>>, float>);
  
  Data_Type<cv::Rect_<double>> rb_cRect2d = define_class_under<cv::Rect_<double>>(rb_mCv, "Rect2d");
  rb_cRect2d.define(&Rect__builder<Data_Type<cv::Rect_<double>>, double>);
  
  Class rb_cCvRotatedRect = define_class_under<cv::RotatedRect>(rb_mCv, "RotatedRect").
    define_constructor(Constructor<cv::RotatedRect>()).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point_<float>&, const cv::Size_<float>&, float>()).
    define_constructor(Constructor<cv::RotatedRect, const cv::Point_<float>&, const cv::Point_<float>&, const cv::Point_<float>&>()).
    define_method<void(cv::RotatedRect::*)(cv::Point_<float>[]) const>("points", &cv::RotatedRect::points).
    define_method<void(cv::RotatedRect::*)(std::vector<cv::Point_<float>>&) const>("points", &cv::RotatedRect::points).
    define_method<cv::Rect_<int>(cv::RotatedRect::*)() const>("bounding_rect", &cv::RotatedRect::boundingRect).
    define_method<cv::Rect_<float>(cv::RotatedRect::*)() const>("bounding_rect2f", &cv::RotatedRect::boundingRect2f).
    define_attr("center", &cv::RotatedRect::center).
    define_attr("size", &cv::RotatedRect::size).
    define_attr("angle", &cv::RotatedRect::angle);
  
  Class rb_cCvDataTypeRotatedRect = define_class_under<cv::DataType<cv::RotatedRect>>(rb_mCv, "DataTypeRotatedRect").
    define_constructor(Constructor<cv::DataType<cv::RotatedRect>>());
  
  
  Class rb_cCvTraitsDepthRotatedRect = define_class_under<cv::traits::Depth<cv::RotatedRect>>(rb_mCvTraits, "DepthRotatedRect").
    define_constructor(Constructor<cv::traits::Depth<cv::RotatedRect>>());
  
  
  Class rb_cCvTraitsTypeRotatedRect = define_class_under<cv::traits::Type<cv::RotatedRect>>(rb_mCvTraits, "TypeRotatedRect").
    define_constructor(Constructor<cv::traits::Type<cv::RotatedRect>>());
  
  
  Class rb_cCvRange = define_class_under<cv::Range>(rb_mCv, "Range").
    define_constructor(Constructor<cv::Range>()).
    define_constructor(Constructor<cv::Range, int, int>()).
    define_method<int(cv::Range::*)() const>("size", &cv::Range::size).
    define_method<bool(cv::Range::*)() const>("empty", &cv::Range::empty).
    define_singleton_function<cv::Range(*)()>("all", &cv::Range::all).
    define_attr("start", &cv::Range::start).
    define_attr("end", &cv::Range::end);
  
  Class rb_cCvDataTypeRange = define_class_under<cv::DataType<cv::Range>>(rb_mCv, "DataTypeRange").
    define_constructor(Constructor<cv::DataType<cv::Range>>());
  
  
  Class rb_cCvTraitsDepthRange = define_class_under<cv::traits::Depth<cv::Range>>(rb_mCvTraits, "DepthRange").
    define_constructor(Constructor<cv::traits::Depth<cv::Range>>());
  
  
  Class rb_cCvTraitsTypeRange = define_class_under<cv::traits::Type<cv::Range>>(rb_mCvTraits, "TypeRange").
    define_constructor(Constructor<cv::traits::Type<cv::Range>>());
  
  
  Data_Type<cv::Scalar_<double>> rb_cScalar = define_class_under<cv::Scalar_<double>>(rb_mCv, "Scalar");
  rb_cScalar.define(&Scalar__builder<Data_Type<cv::Scalar_<double>>, double>);
  
  Class rb_cCvKeyPoint = define_class_under<cv::KeyPoint>(rb_mCv, "KeyPoint").
    define_constructor(Constructor<cv::KeyPoint>()).
    define_constructor(Constructor<cv::KeyPoint, cv::Point_<float>, float, float, float, int, int>()).
    define_constructor(Constructor<cv::KeyPoint, float, float, float, float, float, int, int>()).
    define_method<unsigned long long(cv::KeyPoint::*)() const>("hash", &cv::KeyPoint::hash).
    define_singleton_function<void(*)(const std::vector<cv::KeyPoint>&, std::vector<cv::Point_<float>>&, const std::vector<int>&)>("convert", &cv::KeyPoint::convert).
    define_singleton_function<void(*)(const std::vector<cv::Point_<float>>&, std::vector<cv::KeyPoint>&, float, float, int, int)>("convert", &cv::KeyPoint::convert).
    define_singleton_function<float(*)(const cv::KeyPoint&, const cv::KeyPoint&)>("overlap", &cv::KeyPoint::overlap).
    define_attr("pt", &cv::KeyPoint::pt).
    define_attr("size", &cv::KeyPoint::size).
    define_attr("angle", &cv::KeyPoint::angle).
    define_attr("response", &cv::KeyPoint::response).
    define_attr("octave", &cv::KeyPoint::octave).
    define_attr("class_id", &cv::KeyPoint::class_id);
  
  Class rb_cCvDMatch = define_class_under<cv::DMatch>(rb_mCv, "DMatch").
    define_constructor(Constructor<cv::DMatch>()).
    define_constructor(Constructor<cv::DMatch, int, int, float>()).
    define_constructor(Constructor<cv::DMatch, int, int, int, float>()).
    define_attr("query_idx", &cv::DMatch::queryIdx).
    define_attr("train_idx", &cv::DMatch::trainIdx).
    define_attr("img_idx", &cv::DMatch::imgIdx).
    define_attr("distance", &cv::DMatch::distance).
    define_method<bool(cv::DMatch::*)(const cv::DMatch&) const>("operator<", &cv::DMatch::operator<);
  
  Class rb_cCvTermCriteria = define_class_under<cv::TermCriteria>(rb_mCv, "TermCriteria").
    define_constructor(Constructor<cv::TermCriteria>()).
    define_constructor(Constructor<cv::TermCriteria, int, int, double>()).
    define_method<bool(cv::TermCriteria::*)() const>("is_valid", &cv::TermCriteria::isValid).
    define_attr("type", &cv::TermCriteria::type).
    define_attr("max_count", &cv::TermCriteria::maxCount).
    define_attr("epsilon", &cv::TermCriteria::epsilon);
  
  Enum<cv::TermCriteria::Type> rb_cCvTermCriteriaType = define_enum<cv::TermCriteria::Type>("Type", rb_cCvTermCriteria).
    define_value("COUNT", cv::TermCriteria::Type::COUNT).
    define_value("MAX_ITER", cv::TermCriteria::Type::MAX_ITER).
    define_value("EPS", cv::TermCriteria::Type::EPS);
  
  Class rb_cCvMoments = define_class_under<cv::Moments>(rb_mCv, "Moments").
    define_constructor(Constructor<cv::Moments>()).
    define_constructor(Constructor<cv::Moments, double, double, double, double, double, double, double, double, double, double>()).
    define_attr("m00", &cv::Moments::m00).
    define_attr("m10", &cv::Moments::m10).
    define_attr("m01", &cv::Moments::m01).
    define_attr("m20", &cv::Moments::m20).
    define_attr("m11", &cv::Moments::m11).
    define_attr("m02", &cv::Moments::m02).
    define_attr("m30", &cv::Moments::m30).
    define_attr("m21", &cv::Moments::m21).
    define_attr("m12", &cv::Moments::m12).
    define_attr("m03", &cv::Moments::m03).
    define_attr("mu20", &cv::Moments::mu20).
    define_attr("mu11", &cv::Moments::mu11).
    define_attr("mu02", &cv::Moments::mu02).
    define_attr("mu30", &cv::Moments::mu30).
    define_attr("mu21", &cv::Moments::mu21).
    define_attr("mu12", &cv::Moments::mu12).
    define_attr("mu03", &cv::Moments::mu03).
    define_attr("nu20", &cv::Moments::nu20).
    define_attr("nu11", &cv::Moments::nu11).
    define_attr("nu02", &cv::Moments::nu02).
    define_attr("nu30", &cv::Moments::nu30).
    define_attr("nu21", &cv::Moments::nu21).
    define_attr("nu12", &cv::Moments::nu12).
    define_attr("nu03", &cv::Moments::nu03);
  
  Class rb_cCvDataTypeMoments = define_class_under<cv::DataType<cv::Moments>>(rb_mCv, "DataTypeMoments").
    define_constructor(Constructor<cv::DataType<cv::Moments>>());
  
  
  Class rb_cCvTraitsDepthMoments = define_class_under<cv::traits::Depth<cv::Moments>>(rb_mCvTraits, "DepthMoments").
    define_constructor(Constructor<cv::traits::Depth<cv::Moments>>());
  
  
  Class rb_cCvTraitsTypeMoments = define_class_under<cv::traits::Type<cv::Moments>>(rb_mCvTraits, "TypeMoments").
    define_constructor(Constructor<cv::traits::Type<cv::Moments>>());
  
  
  rb_mCv.define_module_function<double(*)(const cv::Rect_<double>&, const cv::Rect_<double>&)>("rectangle_intersection_area", &cv::rectangleIntersectionArea);

  // Manualy added
  Data_Type<cv::Rect_<long long>> rb_cRect2l = define_class_under<cv::Rect_<long long>>(rb_mCv, "Rect2l");
  rb_cRect2l.define(&Rect__builder<Data_Type<cv::Rect_<long long>>, long long>);
}