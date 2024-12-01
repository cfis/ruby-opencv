#include <opencv2/core.hpp>

#include "core/cvstd_wrapper-rb.hpp"
#include "core-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp, typename _EnumTp>
inline void ParamType_builder(Data_Type_T& klass)
{
};


void Init_Core()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvException = define_class_under<cv::Exception, std::exception>(rb_mCv, "Exception").
    define_constructor(Constructor<cv::Exception>()).
    define_constructor(Constructor<cv::Exception, int, const cv::String&, const cv::String&, const cv::String&, int>(),
      Arg("_code"), Arg("_err"), Arg("_func"), Arg("_file"), Arg("_line")).
    define_method("what", &cv::Exception::what).
    define_method("format_message", &cv::Exception::formatMessage).
    define_attr("msg", &cv::Exception::msg).
    define_attr("code", &cv::Exception::code).
    define_attr("err", &cv::Exception::err).
    define_attr("func", &cv::Exception::func).
    define_attr("file", &cv::Exception::file).
    define_attr("line", &cv::Exception::line);
  
  rb_mCv.define_module_function<void(*)(const cv::Exception&)>("error", &cv::error,
    Arg("exc"));
  
  Enum<cv::SortFlags> rb_cCvSortFlags = define_enum_under<cv::SortFlags>("SortFlags", rb_mCv).
    define_value("SORT_EVERY_ROW", cv::SortFlags::SORT_EVERY_ROW).
    define_value("SORT_EVERY_COLUMN", cv::SortFlags::SORT_EVERY_COLUMN).
    define_value("SORT_ASCENDING", cv::SortFlags::SORT_ASCENDING).
    define_value("SORT_DESCENDING", cv::SortFlags::SORT_DESCENDING);
  
  Enum<cv::CovarFlags> rb_cCvCovarFlags = define_enum_under<cv::CovarFlags>("CovarFlags", rb_mCv).
    define_value("COVAR_SCRAMBLED", cv::CovarFlags::COVAR_SCRAMBLED).
    define_value("COVAR_NORMAL", cv::CovarFlags::COVAR_NORMAL).
    define_value("COVAR_USE_AVG", cv::CovarFlags::COVAR_USE_AVG).
    define_value("COVAR_SCALE", cv::CovarFlags::COVAR_SCALE).
    define_value("COVAR_ROWS", cv::CovarFlags::COVAR_ROWS).
    define_value("COVAR_COLS", cv::CovarFlags::COVAR_COLS);
  
  Enum<cv::KmeansFlags> rb_cCvKmeansFlags = define_enum_under<cv::KmeansFlags>("KmeansFlags", rb_mCv).
    define_value("KMEANS_RANDOM_CENTERS", cv::KmeansFlags::KMEANS_RANDOM_CENTERS).
    define_value("KMEANS_PP_CENTERS", cv::KmeansFlags::KMEANS_PP_CENTERS).
    define_value("KMEANS_USE_INITIAL_LABELS", cv::KmeansFlags::KMEANS_USE_INITIAL_LABELS);
  
  Enum<cv::ReduceTypes> rb_cCvReduceTypes = define_enum_under<cv::ReduceTypes>("ReduceTypes", rb_mCv).
    define_value("REDUCE_SUM", cv::ReduceTypes::REDUCE_SUM).
    define_value("REDUCE_AVG", cv::ReduceTypes::REDUCE_AVG).
    define_value("REDUCE_MAX", cv::ReduceTypes::REDUCE_MAX).
    define_value("REDUCE_MIN", cv::ReduceTypes::REDUCE_MIN).
    define_value("REDUCE_SUM2", cv::ReduceTypes::REDUCE_SUM2);
  
  rb_mCv.define_module_function<void(*)(cv::Mat&, cv::Mat&)>("swap", &cv::swap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function<void(*)(cv::UMat&, cv::UMat&)>("swap", &cv::swap,
    Arg("a"), Arg("b"));
  
  rb_mCv.define_module_function("border_interpolate", &cv::borderInterpolate,
    Arg("p"), Arg("len"), Arg("border_type"));
  
  rb_mCv.define_module_function("copy_make_border", &cv::copyMakeBorder,
    Arg("src"), Arg("dst"), Arg("top"), Arg("bottom"), Arg("left"), Arg("right"), Arg("border_type"), Arg("value") = static_cast<const cv::Scalar &>(cv::Scalar()));
  
  rb_mCv.define_module_function("add", &cv::add,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("subtract", &cv::subtract,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("multiply", &cv::multiply,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, int)>("divide", &cv::divide,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function<void(*)(double, cv::InputArray, cv::OutputArray, int)>("divide", &cv::divide,
    Arg("scale"), Arg("src2"), Arg("dst"), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("scale_add", &cv::scaleAdd,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function("add_weighted", &cv::addWeighted,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("beta"), Arg("gamma"), Arg("dst"), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("convert_scale_abs", &cv::convertScaleAbs,
    Arg("src"), Arg("dst"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0));
  
  rb_mCv.define_module_function("convert_fp16", &cv::convertFp16,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("lut", &cv::LUT,
    Arg("src"), Arg("lut"), Arg("dst"));
  
  rb_mCv.define_module_function("sum", &cv::sum,
    Arg("src"));
  
  rb_mCv.define_module_function("has_non_zero?", &cv::hasNonZero,
    Arg("src"));
  
  rb_mCv.define_module_function("count_non_zero", &cv::countNonZero,
    Arg("src"));
  
  rb_mCv.define_module_function("find_non_zero", &cv::findNonZero,
    Arg("src"), Arg("idx"));
  
  rb_mCv.define_module_function<cv::Scalar(*)(cv::InputArray, cv::InputArray)>("mean", &cv::mean,
    Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::InputArray)>("mean_std_dev", &cv::meanStdDev,
    Arg("src"), Arg("mean"), Arg("stddev"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArray, int, cv::InputArray)>("norm", &cv::norm,
    Arg("src1"), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, int, cv::InputArray)>("norm", &cv::norm,
    Arg("src1"), Arg("src2"), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<double(*)(const cv::SparseMat&, int)>("norm", &cv::norm,
    Arg("src"), Arg("norm_type"));
  
  rb_mCv.define_module_function("psnr", &cv::PSNR,
    Arg("src1"), Arg("src2"), Arg("r") = static_cast<double>(255.));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int, cv::OutputArray, int, int, cv::InputArray, int, bool)>("batch_distance", &cv::batchDistance,
    Arg("src1"), Arg("src2"), Arg("dist"), Arg("dtype"), Arg("nidx"), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("k") = static_cast<int>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("update") = static_cast<int>(0), Arg("crosscheck") = static_cast<bool>(false));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, double, double, int, int, cv::InputArray)>("normalize", &cv::normalize,
    Arg("src"), Arg("dst"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0), Arg("norm_type") = static_cast<int>(cv::NormTypes::NORM_L2), Arg("dtype") = static_cast<int>(-1), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, cv::SparseMat&, double, int)>("normalize", &cv::normalize,
    Arg("src"), Arg("dst"), Arg("alpha"), Arg("norm_type"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, double*, double*, cv::Point*, cv::Point*, cv::InputArray)>("min_max_loc", &cv::minMaxLoc,
    Arg("src"), Arg("min_val"), Arg("max_val") = static_cast<double *>(0), Arg("min_loc") = static_cast<cv::Point *>(0), Arg("max_loc") = static_cast<cv::Point *>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, bool)>("reduce_arg_min", &cv::reduceArgMin,
    Arg("src"), Arg("dst"), Arg("axis"), Arg("last_index") = static_cast<bool>(false));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int, bool)>("reduce_arg_max", &cv::reduceArgMax,
    Arg("src"), Arg("dst"), Arg("axis"), Arg("last_index") = static_cast<bool>(false));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, double*, double*, int*, int*, cv::InputArray)>("min_max_idx", &cv::minMaxIdx,
    Arg("src"), Arg("min_val"), Arg("max_val") = static_cast<double *>(0), Arg("min_idx") = static_cast<int *>(0), Arg("max_idx") = static_cast<int *>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, double*, double*, int*, int*)>("min_max_loc", &cv::minMaxLoc,
    Arg("a"), Arg("min_val"), Arg("max_val"), Arg("min_idx") = static_cast<int *>(0), Arg("max_idx") = static_cast<int *>(0));
  
  rb_mCv.define_module_function("reduce", &cv::reduce,
    Arg("src"), Arg("dst"), Arg("dim"), Arg("rtype"), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, ::size_t, cv::OutputArray)>("merge", &cv::merge,
    Arg("mv"), Arg("count"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("merge", &cv::merge,
    Arg("mv"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, cv::Mat*)>("split", &cv::split,
    Arg("src"), Arg("mvbegin"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays)>("split", &cv::split,
    Arg("m"), Arg("mv"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, ::size_t, cv::Mat*, ::size_t, const int*, ::size_t)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("nsrcs"), Arg("dst"), Arg("ndsts"), Arg("from_to"), Arg("npairs"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputOutputArrayOfArrays, const int*, ::size_t)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("dst"), Arg("from_to"), Arg("npairs"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputOutputArrayOfArrays, const std::vector<int>&)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("dst"), Arg("from_to"));
  
  rb_mCv.define_module_function("extract_channel", &cv::extractChannel,
    Arg("src"), Arg("dst"), Arg("coi"));
  
  rb_mCv.define_module_function("insert_channel", &cv::insertChannel,
    Arg("src"), Arg("dst"), Arg("coi"));
  
  rb_mCv.define_module_function("flip", &cv::flip,
    Arg("src"), Arg("dst"), Arg("flip_code"));
  
  rb_mCv.define_module_function("flip_nd", &cv::flipND,
    Arg("src"), Arg("dst"), Arg("axis"));
  
  rb_mCv.define_module_function("broadcast", &cv::broadcast,
    Arg("src"), Arg("shape"), Arg("dst"));
  
  Enum<cv::RotateFlags> rb_cCvRotateFlags = define_enum_under<cv::RotateFlags>("RotateFlags", rb_mCv).
    define_value("ROTATE_90_CLOCKWISE", cv::RotateFlags::ROTATE_90_CLOCKWISE).
    define_value("ROTATE_180", cv::RotateFlags::ROTATE_180).
    define_value("ROTATE_90_COUNTERCLOCKWISE", cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE);
  
  rb_mCv.define_module_function("rotate", &cv::rotate,
    Arg("src"), Arg("dst"), Arg("rotate_code"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, int, int, cv::OutputArray)>("repeat", &cv::repeat,
    Arg("src"), Arg("ny"), Arg("nx"), Arg("dst"));
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::Mat&, int, int)>("repeat", &cv::repeat,
    Arg("src"), Arg("ny"), Arg("nx"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, ::size_t, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src"), Arg("nsrc"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, ::size_t, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src"), Arg("nsrc"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("bitwise_and", &cv::bitwise_and,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("bitwise_or", &cv::bitwise_or,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::InputArray)>("bitwise_xor", &cv::bitwise_xor,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray)>("bitwise_not", &cv::bitwise_not,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("absdiff", &cv::absdiff,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray)>("copy_to", &cv::copyTo,
    Arg("src"), Arg("dst"), Arg("mask"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray)>("in_range", &cv::inRange,
    Arg("src"), Arg("lowerb"), Arg("upperb"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int)>("compare", &cv::compare,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("cmpop"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));
  
  rb_mCv.define_module_function("sqrt", &cv::sqrt,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("pow", &cv::pow,
    Arg("src"), Arg("power"), Arg("dst"));
  
  rb_mCv.define_module_function("exp", &cv::exp,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("log", &cv::log,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("polar_to_cart", &cv::polarToCart,
    Arg("magnitude"), Arg("angle"), Arg("x"), Arg("y"), Arg("angle_in_degrees") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("cart_to_polar", &cv::cartToPolar,
    Arg("x"), Arg("y"), Arg("magnitude"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("phase", &cv::phase,
    Arg("x"), Arg("y"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("magnitude", &cv::magnitude,
    Arg("x"), Arg("y"), Arg("magnitude"));
  
  rb_mCv.define_module_function("check_range?", &cv::checkRange,
    Arg("a"), Arg("quiet") = static_cast<bool>(true), Arg("pos") = static_cast<cv::Point *>(0), Arg("min_val") = static_cast<double>(-DBL_MAX), Arg("max_val") = static_cast<double>(DBL_MAX));
  
  rb_mCv.define_module_function("patch_na_ns", &cv::patchNaNs,
    Arg("a"), Arg("val") = static_cast<double>(0));
  
  rb_mCv.define_module_function("gemm", &cv::gemm,
    Arg("src1"), Arg("src2"), Arg("alpha"), Arg("src3"), Arg("beta"), Arg("dst"), Arg("flags") = static_cast<int>(0));
  
  rb_mCv.define_module_function("mul_transposed", &cv::mulTransposed,
    Arg("src"), Arg("dst"), Arg("a_ta"), Arg("delta") = static_cast<cv::InputArray>(cv::noArray()), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));
  
  rb_mCv.define_module_function("transpose", &cv::transpose,
    Arg("src"), Arg("dst"));
  
  rb_mCv.define_module_function("transpose_nd", &cv::transposeND,
    Arg("src"), Arg("order"), Arg("dst"));
  
  rb_mCv.define_module_function("transform", &cv::transform,
    Arg("src"), Arg("dst"), Arg("m"));
  
  rb_mCv.define_module_function("perspective_transform", &cv::perspectiveTransform,
    Arg("src"), Arg("dst"), Arg("m"));
  
  rb_mCv.define_module_function("complete_symm", &cv::completeSymm,
    Arg("m"), Arg("lower_to_upper") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("set_identity", &cv::setIdentity,
    Arg("mtx"), Arg("s") = static_cast<const cv::Scalar &>(cv::Scalar(1)));
  
  rb_mCv.define_module_function("determinant", &cv::determinant,
    Arg("mtx"));
  
  rb_mCv.define_module_function("trace", &cv::trace,
    Arg("mtx"));
  
  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::OutputArray, int)>("invert", &cv::invert,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(cv::DecompTypes::DECOMP_LU));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::InputArray, cv::OutputArray, int)>("solve?", &cv::solve,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("flags") = static_cast<int>(cv::DecompTypes::DECOMP_LU));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("sort", &cv::sort,
    Arg("src"), Arg("dst"), Arg("flags"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, int)>("sort_idx", &cv::sortIdx,
    Arg("src"), Arg("dst"), Arg("flags"));
  
  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::OutputArray)>("solve_cubic", &cv::solveCubic,
    Arg("coeffs"), Arg("roots"));
  
  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::OutputArray, int)>("solve_poly", &cv::solvePoly,
    Arg("coeffs"), Arg("roots"), Arg("max_iters") = static_cast<int>(300));
  
  rb_mCv.define_module_function<bool(*)(cv::InputArray, cv::OutputArray, cv::OutputArray)>("eigen?", &cv::eigen,
    Arg("src"), Arg("eigenvalues"), Arg("eigenvectors") = static_cast<cv::OutputArray>(cv::noArray()));
  
  rb_mCv.define_module_function("eigen_non_symmetric", &cv::eigenNonSymmetric,
    Arg("src"), Arg("eigenvalues"), Arg("eigenvectors"));
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, cv::Mat&, cv::Mat&, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix,
    Arg("samples"), Arg("nsamples"), Arg("covar"), Arg("mean"), Arg("flags"), Arg("ctype") = static_cast<int>(CV_64F));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputOutputArray, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix,
    Arg("samples"), Arg("covar"), Arg("mean"), Arg("flags"), Arg("ctype") = static_cast<int>(CV_64F));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, int)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("max_components") = static_cast<int>(0));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, int)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("eigenvalues"), Arg("max_components") = static_cast<int>(0));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, double)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("retained_variance"));
  
  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, double)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("eigenvalues"), Arg("retained_variance"));
  
  rb_mCv.define_module_function("pca_project", &cv::PCAProject,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("result"));
  
  rb_mCv.define_module_function("pca_back_project", &cv::PCABackProject,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("result"));
  
  rb_mCv.define_module_function("sv_decomp", &cv::SVDecomp,
    Arg("src"), Arg("w"), Arg("u"), Arg("vt"), Arg("flags") = static_cast<int>(0));
  
  rb_mCv.define_module_function("sv_back_subst", &cv::SVBackSubst,
    Arg("w"), Arg("u"), Arg("vt"), Arg("rhs"), Arg("dst"));
  
  rb_mCv.define_module_function("mahalanobis", &cv::Mahalanobis,
    Arg("v1"), Arg("v2"), Arg("icovar"));
  
  rb_mCv.define_module_function("dft", &cv::dft,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0), Arg("nonzero_rows") = static_cast<int>(0));
  
  rb_mCv.define_module_function("idft", &cv::idft,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0), Arg("nonzero_rows") = static_cast<int>(0));
  
  rb_mCv.define_module_function("dct", &cv::dct,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0));
  
  rb_mCv.define_module_function("idct", &cv::idct,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0));
  
  rb_mCv.define_module_function("mul_spectrums", &cv::mulSpectrums,
    Arg("a"), Arg("b"), Arg("c"), Arg("flags"), Arg("conj_b") = static_cast<bool>(false));
  
  rb_mCv.define_module_function("get_optimal_dft_size", &cv::getOptimalDFTSize,
    Arg("vecsize"));
  
  rb_mCv.define_module_function("the_rng", &cv::theRNG);
  
  rb_mCv.define_module_function("set_rng_seed", &cv::setRNGSeed,
    Arg("seed"));
  
  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, cv::InputArray, cv::InputArray)>("randu", &cv::randu,
    Arg("dst"), Arg("low"), Arg("high"));
  
  rb_mCv.define_module_function("randn", &cv::randn,
    Arg("dst"), Arg("mean"), Arg("stddev"));
  
  rb_mCv.define_module_function<void(*)(cv::InputOutputArray, double, cv::RNG*)>("rand_shuffle", &cv::randShuffle,
    Arg("dst"), Arg("iter_factor") = static_cast<double>(1.), Arg("rng") = static_cast<cv::RNG *>(0));
  
  Class rb_cCvPCA = define_class_under<cv::PCA>(rb_mCv, "PCA").
    define_constructor(Constructor<cv::PCA>()).
    define_constructor(Constructor<cv::PCA, cv::InputArray, cv::InputArray, int, int>(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("max_components") = static_cast<int>(0)).
    define_constructor(Constructor<cv::PCA, cv::InputArray, cv::InputArray, int, double>(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("retained_variance")).
    define_method<cv::PCA&(cv::PCA::*)(cv::InputArray, cv::InputArray, int, int)>("()", &cv::PCA::operator(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("max_components") = static_cast<int>(0)).
    define_method<cv::PCA&(cv::PCA::*)(cv::InputArray, cv::InputArray, int, double)>("()", &cv::PCA::operator(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("retained_variance")).
    define_method<cv::Mat(cv::PCA::*)(cv::InputArray) const>("project", &cv::PCA::project,
      Arg("vec")).
    define_method<void(cv::PCA::*)(cv::InputArray, cv::OutputArray) const>("project", &cv::PCA::project,
      Arg("vec"), Arg("result")).
    define_method<cv::Mat(cv::PCA::*)(cv::InputArray) const>("back_project", &cv::PCA::backProject,
      Arg("vec")).
    define_method<void(cv::PCA::*)(cv::InputArray, cv::OutputArray) const>("back_project", &cv::PCA::backProject,
      Arg("vec"), Arg("result")).
    define_method<void(cv::PCA::*)(cv::FileStorage&) const>("write", &cv::PCA::write,
      Arg("fs")).
    define_method<void(cv::PCA::*)(const cv::FileNode&)>("read", &cv::PCA::read,
      Arg("fn")).
    define_attr("eigenvectors", &cv::PCA::eigenvectors).
    define_attr("eigenvalues", &cv::PCA::eigenvalues).
    define_attr("mean", &cv::PCA::mean);
  
  Enum<cv::PCA::Flags> rb_cCvPCAFlags = define_enum_under<cv::PCA::Flags>("Flags", rb_cCvPCA).
    define_value("DATA_AS_ROW", cv::PCA::Flags::DATA_AS_ROW).
    define_value("DATA_AS_COL", cv::PCA::Flags::DATA_AS_COL).
    define_value("USE_AVG", cv::PCA::Flags::USE_AVG);
  
  Class rb_cCvLDA = define_class_under<cv::LDA>(rb_mCv, "LDA").
    define_constructor(Constructor<cv::LDA, int>(),
      Arg("num_components") = static_cast<int>(0)).
    define_constructor(Constructor<cv::LDA, cv::InputArrayOfArrays, cv::InputArray, int>(),
      Arg("src"), Arg("labels"), Arg("num_components") = static_cast<int>(0)).
    define_method<void(cv::LDA::*)(const cv::String&) const>("save", &cv::LDA::save,
      Arg("filename")).
    define_method<void(cv::LDA::*)(const cv::String&)>("load", &cv::LDA::load,
      Arg("filename")).
    define_method<void(cv::LDA::*)(cv::FileStorage&) const>("save", &cv::LDA::save,
      Arg("fs")).
    define_method<void(cv::LDA::*)(const cv::FileStorage&)>("load", &cv::LDA::load,
      Arg("node")).
    define_method("compute", &cv::LDA::compute,
      Arg("src"), Arg("labels")).
    define_method("project", &cv::LDA::project,
      Arg("src")).
    define_method("reconstruct", &cv::LDA::reconstruct,
      Arg("src")).
    define_method("eigenvectors", &cv::LDA::eigenvectors).
    define_method("eigenvalues", &cv::LDA::eigenvalues).
    define_singleton_function("subspace_project", &cv::LDA::subspaceProject,
      Arg("w"), Arg("mean"), Arg("src")).
    define_singleton_function("subspace_reconstruct", &cv::LDA::subspaceReconstruct,
      Arg("w"), Arg("mean"), Arg("src"));
  
  Class rb_cCvSVD = define_class_under<cv::SVD>(rb_mCv, "SVD").
    define_constructor(Constructor<cv::SVD>()).
    define_constructor(Constructor<cv::SVD, cv::InputArray, int>(),
      Arg("src"), Arg("flags") = static_cast<int>(0)).
    define_method("()", &cv::SVD::operator(),
      Arg("src"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int)>("compute", &cv::SVD::compute,
      Arg("src"), Arg("w"), Arg("u"), Arg("vt"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<void(*)(cv::InputArray, cv::OutputArray, int)>("compute", &cv::SVD::compute,
      Arg("src"), Arg("w"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray)>("back_subst", &cv::SVD::backSubst,
      Arg("w"), Arg("u"), Arg("vt"), Arg("rhs"), Arg("dst")).
    define_singleton_function("solve_z", &cv::SVD::solveZ,
      Arg("src"), Arg("dst")).
    define_method<void(cv::SVD::*)(cv::InputArray, cv::OutputArray) const>("back_subst", &cv::SVD::backSubst,
      Arg("rhs"), Arg("dst")).
    define_attr("u", &cv::SVD::u).
    define_attr("w", &cv::SVD::w).
    define_attr("vt", &cv::SVD::vt);
  
  Enum<cv::SVD::Flags> rb_cCvSVDFlags = define_enum_under<cv::SVD::Flags>("Flags", rb_cCvSVD).
    define_value("MODIFY_A", cv::SVD::Flags::MODIFY_A).
    define_value("NO_UV", cv::SVD::Flags::NO_UV).
    define_value("FULL_UV", cv::SVD::Flags::FULL_UV);
  
  Class rb_cCvRNG = define_class_under<cv::RNG>(rb_mCv, "RNG").
    define_constructor(Constructor<cv::RNG>()).
    define_constructor(Constructor<cv::RNG, uint64>(),
      Arg("state")).
    define_method<unsigned int(cv::RNG::*)()>("next", &cv::RNG::next).
   /* define_method("to_unsigned char", [](const cv::RNG& self) -> uchar
    {
      return self;
    }).
    define_method("to_signed char", [](const cv::RNG& self) -> schar
    {
      return self;
    }).
    define_method("to_unsigned short", [](const cv::RNG& self) -> ushort
    {
      return self;
    }).
    define_method("to_short", [](const cv::RNG& self) -> short
    {
      return self;
    }).
    define_method("to_unsigned int", [](const cv::RNG& self) -> unsigned int
    {
      return self;
    }).
    define_method("to_int", [](const cv::RNG& self) -> int
    {
      return self;
    }).
    define_method("to_float", [](const cv::RNG& self) -> float
    {
      return self;
    }).
    define_method("to_double", [](const cv::RNG& self) -> double
    {
      return self;
    }).*/
    define_method<unsigned int(cv::RNG::*)()>("()", &cv::RNG::operator()).
    define_method<unsigned int(cv::RNG::*)(unsigned int)>("()", &cv::RNG::operator(),
      Arg("n")).
    define_method<int(cv::RNG::*)(int, int)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method<float(cv::RNG::*)(float, float)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method<double(cv::RNG::*)(double, double)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method("fill", &cv::RNG::fill,
      Arg("mat"), Arg("dist_type"), Arg("a"), Arg("b"), Arg("saturate_range") = static_cast<bool>(false)).
    define_method("gaussian", &cv::RNG::gaussian,
      Arg("sigma")).
    define_attr("state", &cv::RNG::state).
    define_method("==", &cv::RNG::operator==,
      Arg("other"));
  
  rb_cCvRNG.define_constant("UNIFORM", (int)cv::RNG::UNIFORM);
  rb_cCvRNG.define_constant("NORMAL", (int)cv::RNG::NORMAL);
  
  Class rb_cCvRNGMT19937 = define_class_under<cv::RNG_MT19937>(rb_mCv, "RNG_MT19937").
    define_constructor(Constructor<cv::RNG_MT19937>()).
    define_constructor(Constructor<cv::RNG_MT19937, unsigned int>(),
      Arg("s")).
    define_method("seed", &cv::RNG_MT19937::seed,
      Arg("s")).
    define_method<unsigned int(cv::RNG_MT19937::*)()>("next", &cv::RNG_MT19937::next).
   /* define_method("to_int", [](const cv::RNG_MT19937& self) -> int
    {
      return self;
    }).
    define_method("to_unsigned int", [](const cv::RNG_MT19937& self) -> unsigned int
    {
      return self;
    }).
    define_method("to_float", [](const cv::RNG_MT19937& self) -> float
    {
      return self;
    }).
    define_method("to_double", [](const cv::RNG_MT19937& self) -> double
    {
      return self;
    }).*/
    define_method<unsigned int(cv::RNG_MT19937::*)(unsigned int)>("()", &cv::RNG_MT19937::operator(),
      Arg("n")).
    define_method<unsigned int(cv::RNG_MT19937::*)()>("()", &cv::RNG_MT19937::operator()).
    define_method<int(cv::RNG_MT19937::*)(int, int)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b")).
    define_method<float(cv::RNG_MT19937::*)(float, float)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b")).
    define_method<double(cv::RNG_MT19937::*)(double, double)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b"));
  
  
  rb_mCv.define_module_function<double(*)(cv::InputArray, int, cv::InputOutputArray, cv::TermCriteria, int, int, cv::OutputArray)>("kmeans", &cv::kmeans,
    Arg("data"), Arg("k"), Arg("best_labels"), Arg("criteria"), Arg("attempts"), Arg("flags"), Arg("centers") = static_cast<cv::OutputArray>(cv::noArray()));
  
  Class rb_cCvFormatted = define_class_under<cv::Formatted>(rb_mCv, "Formatted").
    define_method("next", &cv::Formatted::next).
    define_method("reset", &cv::Formatted::reset);
  
  Class rb_cCvFormatter = define_class_under<cv::Formatter>(rb_mCv, "Formatter").
    define_method("format", &cv::Formatter::format,
      Arg("mtx")).
    define_method("set16f_precision", &cv::Formatter::set16fPrecision,
      Arg("p") = static_cast<int>(4)).
    define_method("set32f_precision", &cv::Formatter::set32fPrecision,
      Arg("p") = static_cast<int>(8)).
    define_method("set64f_precision", &cv::Formatter::set64fPrecision,
      Arg("p") = static_cast<int>(16)).
    define_method("set_multiline", &cv::Formatter::setMultiline,
      Arg("ml") = static_cast<bool>(true)).
    define_singleton_function("get", &cv::Formatter::get,
      Arg("fmt") = static_cast<cv::Formatter::FormatType > (cv::Formatter::FormatType::FMT_DEFAULT));
  
  Enum<cv::Formatter::FormatType> rb_cCvFormatterFormatType = define_enum_under<cv::Formatter::FormatType>("FormatType", rb_cCvFormatter).
    define_value("FMT_DEFAULT", cv::Formatter::FormatType::FMT_DEFAULT).
    define_value("FMT_MATLAB", cv::Formatter::FormatType::FMT_MATLAB).
    define_value("FMT_CSV", cv::Formatter::FormatType::FMT_CSV).
    define_value("FMT_PYTHON", cv::Formatter::FormatType::FMT_PYTHON).
    define_value("FMT_NUMPY", cv::Formatter::FormatType::FMT_NUMPY).
    define_value("FMT_C", cv::Formatter::FormatType::FMT_C);
  
  Class rb_cCvAlgorithm = define_class_under<cv::Algorithm>(rb_mCv, "Algorithm").
    define_constructor(Constructor<cv::Algorithm>()).
    define_method("clear", &cv::Algorithm::clear).
    define_method<void(cv::Algorithm::*)(cv::FileStorage&) const>("write", &cv::Algorithm::write,
      Arg("fs")).
    define_method<void(cv::Algorithm::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::Algorithm::write,
      Arg("fs"), Arg("name")).
    define_method<void(cv::Algorithm::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::Algorithm::write,
      Arg("fs"), Arg("name") = static_cast<const String &>(String())).
    define_method<void(cv::Algorithm::*)(const cv::FileNode&)>("read", &cv::Algorithm::read,
      Arg("fn")).
    define_method("empty?", &cv::Algorithm::empty).
    define_method("save", &cv::Algorithm::save,
      Arg("filename")).
    define_method("get_default_name", &cv::Algorithm::getDefaultName);
  
  Enum<cv::Param> rb_cCvParam = define_enum_under<cv::Param>("Param", rb_mCv).
    define_value("INT", cv::Param::INT).
    define_value("BOOLEAN", cv::Param::BOOLEAN).
    define_value("REAL", cv::Param::REAL).
    define_value("STRING", cv::Param::STRING).
    define_value("MAT", cv::Param::MAT).
    define_value("MAT_VECTOR", cv::Param::MAT_VECTOR).
    define_value("ALGORITHM", cv::Param::ALGORITHM).
    define_value("FLOAT", cv::Param::FLOAT).
    define_value("UNSIGNED_INT", cv::Param::UNSIGNED_INT).
    define_value("UINT64", cv::Param::UINT64).
    define_value("UCHAR", cv::Param::UCHAR).
    define_value("SCALAR", cv::Param::SCALAR);
  
  Class rb_cCvParamTypeBool = define_class_under<cv::ParamType<bool>>(rb_mCv, "ParamTypeBool").
    define_constructor(Constructor<cv::ParamType<bool>>()).
    define_constant("Type", cv::ParamType<bool>::type);
  
  Class rb_cCvParamTypeInt = define_class_under<cv::ParamType<int>>(rb_mCv, "ParamTypeInt").
    define_constructor(Constructor<cv::ParamType<int>>()).
    define_constant("Type", cv::ParamType<int>::type);
  
  Class rb_cCvParamTypeDouble = define_class_under<cv::ParamType<double>>(rb_mCv, "ParamTypeDouble").
    define_constructor(Constructor<cv::ParamType<double>>()).
    define_constant("Type", cv::ParamType<double>::type);
  
  Class rb_cCvParamTypeString = define_class_under<cv::ParamType<cv::String>>(rb_mCv, "ParamTypeString").
    define_constructor(Constructor<cv::ParamType<cv::String>>()).
    define_constant("Type", cv::ParamType<cv::String>::type);
  
  Class rb_cCvParamTypeMat = define_class_under<cv::ParamType<cv::Mat>>(rb_mCv, "ParamTypeMat").
    define_constructor(Constructor<cv::ParamType<cv::Mat>>()).
    define_constant("Type", cv::ParamType<cv::Mat>::type);
  
  Class rb_cCvParamTypeStdVectorMat = define_class_under<cv::ParamType<std::vector<cv::Mat>>>(rb_mCv, "VectorMat").
    define_constructor(Constructor<cv::ParamType<std::vector<cv::Mat>>>()).
    define_constant("Type", cv::ParamType<std::vector<cv::Mat>>::type);
  
  Class rb_cCvParamTypeAlgorithm = define_class_under<cv::ParamType<cv::Algorithm>>(rb_mCv, "ParamTypeAlgorithm").
    define_constructor(Constructor<cv::ParamType<cv::Algorithm>>()).
    define_constant("Type", cv::ParamType<cv::Algorithm>::type);
  
  Class rb_cCvParamTypeFloat = define_class_under<cv::ParamType<float>>(rb_mCv, "ParamTypeFloat").
    define_constructor(Constructor<cv::ParamType<float>>()).
    define_constant("Type", cv::ParamType<float>::type);
  
  Class rb_cCvParamTypeUnsignedInt = define_class_under<cv::ParamType<unsigned int>>(rb_mCv, "ParamTypeUnsignedInt").
    define_constructor(Constructor<cv::ParamType<unsigned int>>()).
    define_constant("Type", cv::ParamType<unsigned int>::type);
  
  Class rb_cCvParamTypeUint64 = define_class_under<cv::ParamType<uint64>>(rb_mCv, "ParamTypeUint64").
    define_constructor(Constructor<cv::ParamType<uint64>>()).
    define_constant("Type", cv::ParamType<uint64>::type);
  
  Class rb_cCvParamTypeUchar = define_class_under<cv::ParamType<uchar>>(rb_mCv, "ParamTypeUchar").
    define_constructor(Constructor<cv::ParamType<uchar>>()).
    define_constant("Type", cv::ParamType<uchar>::type);
  
  Class rb_cCvParamTypeScalar = define_class_under<cv::ParamType<cv::Scalar>>(rb_mCv, "ParamTypeScalar").
    define_constructor(Constructor<cv::ParamType<cv::Scalar>>()).
    define_constant("Type", cv::ParamType<cv::Scalar>::type);

}