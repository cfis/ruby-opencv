#include <opencv2/core.hpp>
#include "cvstd_wrapper-rb.hpp"
#include "core-rb.hpp"

using namespace Rice;

extern "C"
void Init_Core()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvException = define_class_under<cv::Exception, std::exception>(rb_mCv, "Exception").
    define_constructor(Constructor<cv::Exception>()).
    define_constructor(Constructor<cv::Exception, int, const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&, int>()).
    define_method<const char*(cv::Exception::*)() const>("what", &cv::Exception::what).
    define_method<void(cv::Exception::*)()>("format_message", &cv::Exception::formatMessage).
    define_attr("msg", &cv::Exception::msg).
    define_attr("code", &cv::Exception::code).
    define_attr("err", &cv::Exception::err).
    define_attr("func", &cv::Exception::func).
    define_attr("file", &cv::Exception::file).
    define_attr("line", &cv::Exception::line);
  
  rb_mCv.define_module_function<void(*)(const cv::Exception&)>("error", &cv::error);
  
  Enum<cv::SortFlags> rb_cCvSortFlags = define_enum<cv::SortFlags>("SortFlags", rb_mCv).
    define_value("SORT_EVERY_ROW", cv::SortFlags::SORT_EVERY_ROW).
    define_value("SORT_EVERY_COLUMN", cv::SortFlags::SORT_EVERY_COLUMN).
    define_value("SORT_ASCENDING", cv::SortFlags::SORT_ASCENDING).
    define_value("SORT_DESCENDING", cv::SortFlags::SORT_DESCENDING);
  
  Enum<cv::CovarFlags> rb_cCvCovarFlags = define_enum<cv::CovarFlags>("CovarFlags", rb_mCv).
    define_value("COVAR_SCRAMBLED", cv::CovarFlags::COVAR_SCRAMBLED).
    define_value("COVAR_NORMAL", cv::CovarFlags::COVAR_NORMAL).
    define_value("COVAR_USE_AVG", cv::CovarFlags::COVAR_USE_AVG).
    define_value("COVAR_SCALE", cv::CovarFlags::COVAR_SCALE).
    define_value("COVAR_ROWS", cv::CovarFlags::COVAR_ROWS).
    define_value("COVAR_COLS", cv::CovarFlags::COVAR_COLS);
  
  Enum<cv::KmeansFlags> rb_cCvKmeansFlags = define_enum<cv::KmeansFlags>("KmeansFlags", rb_mCv).
    define_value("KMEANS_RANDOM_CENTERS", cv::KmeansFlags::KMEANS_RANDOM_CENTERS).
    define_value("KMEANS_PP_CENTERS", cv::KmeansFlags::KMEANS_PP_CENTERS).
    define_value("KMEANS_USE_INITIAL_LABELS", cv::KmeansFlags::KMEANS_USE_INITIAL_LABELS);
  
  Enum<cv::ReduceTypes> rb_cCvReduceTypes = define_enum<cv::ReduceTypes>("ReduceTypes", rb_mCv).
    define_value("REDUCE_SUM", cv::ReduceTypes::REDUCE_SUM).
    define_value("REDUCE_AVG", cv::ReduceTypes::REDUCE_AVG).
    define_value("REDUCE_MAX", cv::ReduceTypes::REDUCE_MAX).
    define_value("REDUCE_MIN", cv::ReduceTypes::REDUCE_MIN).
    define_value("REDUCE_SUM2", cv::ReduceTypes::REDUCE_SUM2);
  
  rb_mCv.define_module_function<void(*)(cv::Mat&, cv::Mat&)>("swap", &cv::swap);
  
  rb_mCv.define_module_function<void(*)(cv::UMat&, cv::UMat&)>("swap", &cv::swap);
  
  rb_mCv.define_module_function<int(*)(int, int, int)>("border_interpolate", &cv::borderInterpolate);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, int, int, const cv::Scalar_<double>&)>("copy_make_border", &cv::copyMakeBorder);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, int)>("add", &cv::add);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, int)>("subtract", &cv::subtract);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, int)>("multiply", &cv::multiply);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, int)>("divide", &cv::divide);
  
  rb_mCv.define_module_function<void(*)(double, const cv::_InputArray &, const cv::_OutputArray &, int)>("divide", &cv::divide);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, double, const cv::_InputArray &, const cv::_OutputArray &)>("scale_add", &cv::scaleAdd);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, double, const cv::_InputArray &, double, double, const cv::_OutputArray &, int)>("add_weighted", &cv::addWeighted);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double)>("convert_scale_abs", &cv::convertScaleAbs);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("convert_fp16", &cv::convertFp16);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("lut", &cv::LUT);
  
  rb_mCv.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &)>("sum", &cv::sum);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &)>("has_non_zero", &cv::hasNonZero);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &)>("count_non_zero", &cv::countNonZero);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("find_non_zero", &cv::findNonZero);
  
  rb_mCv.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &, const cv::_InputArray &)>("mean", &cv::mean);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("mean_std_dev", &cv::meanStdDev);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, int, const cv::_InputArray &)>("norm", &cv::norm);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, int, const cv::_InputArray &)>("norm", &cv::norm);
  
  rb_mCv.define_module_function<double(*)(const cv::SparseMat&, int)>("norm", &cv::norm);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, double)>("psnr", &cv::PSNR);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_OutputArray &, int, int, const cv::_InputArray &, int, bool)>("batch_distance", &cv::batchDistance);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, double, double, int, int, const cv::_InputArray &)>("normalize", &cv::normalize);
  
  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, cv::SparseMat&, double, int)>("normalize", &cv::normalize);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, double*, double*, cv::Point_<int>*, cv::Point_<int>*, const cv::_InputArray &)>("min_max_loc", &cv::minMaxLoc);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, bool)>("reduce_arg_min", &cv::reduceArgMin);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, bool)>("reduce_arg_max", &cv::reduceArgMax);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, double*, double*, int*, int*, const cv::_InputArray &)>("min_max_idx", &cv::minMaxIdx);
  
  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, double*, double*, int*, int*)>("min_max_loc", &cv::minMaxLoc);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("reduce", &cv::reduce);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, unsigned long long, const cv::_OutputArray &)>("merge", &cv::merge);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("merge", &cv::merge);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, cv::Mat*)>("split", &cv::split);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("split", &cv::split);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, unsigned long long, cv::Mat*, unsigned long long, const int*, unsigned long long)>("mix_channels", &cv::mixChannels);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const int*, unsigned long long)>("mix_channels", &cv::mixChannels);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const std::vector<int>&)>("mix_channels", &cv::mixChannels);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("extract_channel", &cv::extractChannel);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, int)>("insert_channel", &cv::insertChannel);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("flip", &cv::flip);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("flip_nd", &cv::flipND);
  
  Enum<cv::RotateFlags> rb_cCvRotateFlags = define_enum<cv::RotateFlags>("RotateFlags", rb_mCv).
    define_value("ROTATE_90_CLOCKWISE", cv::RotateFlags::ROTATE_90_CLOCKWISE).
    define_value("ROTATE_180", cv::RotateFlags::ROTATE_180).
    define_value("ROTATE_90_COUNTERCLOCKWISE", cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("rotate", &cv::rotate);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, int, int, const cv::_OutputArray &)>("repeat", &cv::repeat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::Mat&, int, int)>("repeat", &cv::repeat);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, unsigned long long, const cv::_OutputArray &)>("hconcat", &cv::hconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("hconcat", &cv::hconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("hconcat", &cv::hconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, unsigned long long, const cv::_OutputArray &)>("vconcat", &cv::vconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("vconcat", &cv::vconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("vconcat", &cv::vconcat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("bitwise_and", &cv::bitwise_and);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("bitwise_or", &cv::bitwise_or);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("bitwise_xor", &cv::bitwise_xor);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("bitwise_not", &cv::bitwise_not);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("absdiff", &cv::absdiff);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("copy_to", &cv::copyTo);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("in_range", &cv::inRange);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int)>("compare", &cv::compare);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("min", &cv::min);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("min", &cv::min);
  
  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("min", &cv::min);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("max", &cv::max);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("max", &cv::max);
  
  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("max", &cv::max);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("sqrt", &cv::sqrt);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, double, const cv::_OutputArray &)>("pow", &cv::pow);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("exp", &cv::exp);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("log", &cv::log);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool)>("polar_to_cart", &cv::polarToCart);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool)>("cart_to_polar", &cv::cartToPolar);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool)>("phase", &cv::phase);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("magnitude", &cv::magnitude);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, bool, cv::Point_<int>*, double, double)>("check_range", &cv::checkRange);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, double)>("patch_na_ns", &cv::patchNaNs);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, double, const cv::_InputArray &, double, const cv::_OutputArray &, int)>("gemm", &cv::gemm);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, bool, const cv::_InputArray &, double, int)>("mul_transposed", &cv::mulTransposed);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("transpose", &cv::transpose);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<int>&, const cv::_OutputArray &)>("transpose_nd", &cv::transposeND);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("transform", &cv::transform);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("perspective_transform", &cv::perspectiveTransform);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, bool)>("complete_symm", &cv::completeSymm);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::Scalar_<double>&)>("set_identity", &cv::setIdentity);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &)>("determinant", &cv::determinant);
  
  rb_mCv.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &)>("trace", &cv::trace);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("invert", &cv::invert);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int)>("solve", &cv::solve);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("sort", &cv::sort);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("sort_idx", &cv::sortIdx);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &)>("solve_cubic", &cv::solveCubic);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("solve_poly", &cv::solvePoly);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("eigen", &cv::eigen);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("eigen_non_symmetric", &cv::eigenNonSymmetric);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, cv::Mat&, cv::Mat&, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputOutputArray &, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, int)>("pca_compute", &cv::PCACompute);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int)>("pca_compute", &cv::PCACompute);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, double)>("pca_compute", &cv::PCACompute);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double)>("pca_compute", &cv::PCACompute);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("pca_project", &cv::PCAProject);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("pca_back_project", &cv::PCABackProject);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int)>("sv_decomp", &cv::SVDecomp);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("sv_back_subst", &cv::SVBackSubst);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("mahalanobis", &cv::Mahalanobis);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("dft", &cv::dft);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("idft", &cv::idft);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("dct", &cv::dct);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("idct", &cv::idct);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, bool)>("mul_spectrums", &cv::mulSpectrums);
  
  rb_mCv.define_module_function<int(*)(int)>("get_optimal_dft_size", &cv::getOptimalDFTSize);
  
  rb_mCv.define_module_function<cv::RNG&(*)()>("the_rng", &cv::theRNG);
  
  rb_mCv.define_module_function<void(*)(int)>("set_rng_seed", &cv::setRNGSeed);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("randu", &cv::randu);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &)>("randn", &cv::randn);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, double, cv::RNG*)>("rand_shuffle", &cv::randShuffle);
  
  Class rb_cCvPCA = define_class_under<cv::PCA>(rb_mCv, "PCA").
    define_constructor(Constructor<cv::PCA>()).
    define_constructor(Constructor<cv::PCA, const cv::_InputArray &, const cv::_InputArray &, int, int>()).
    define_constructor(Constructor<cv::PCA, const cv::_InputArray &, const cv::_InputArray &, int, double>()).
    define_method<cv::PCA&(cv::PCA::*)(const cv::_InputArray &, const cv::_InputArray &, int, int)>("operator()", &cv::PCA::operator()).
    define_method<cv::PCA&(cv::PCA::*)(const cv::_InputArray &, const cv::_InputArray &, int, double)>("operator()", &cv::PCA::operator()).
    define_method<cv::Mat(cv::PCA::*)(const cv::_InputArray &) const>("project", &cv::PCA::project).
    define_method<void(cv::PCA::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("project", &cv::PCA::project).
    define_method<cv::Mat(cv::PCA::*)(const cv::_InputArray &) const>("back_project", &cv::PCA::backProject).
    define_method<void(cv::PCA::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("back_project", &cv::PCA::backProject).
    define_method<void(cv::PCA::*)(cv::FileStorage&) const>("write", &cv::PCA::write).
    define_method<void(cv::PCA::*)(const cv::FileNode&)>("read", &cv::PCA::read).
    define_attr("eigenvectors", &cv::PCA::eigenvectors).
    define_attr("eigenvalues", &cv::PCA::eigenvalues).
    define_attr("mean", &cv::PCA::mean);
  
  Enum<cv::PCA::Flags> rb_cCvPCAFlags = define_enum<cv::PCA::Flags>("Flags", rb_cCvPCA).
    define_value("DATA_AS_ROW", cv::PCA::Flags::DATA_AS_ROW).
    define_value("DATA_AS_COL", cv::PCA::Flags::DATA_AS_COL).
    define_value("USE_AVG", cv::PCA::Flags::USE_AVG);
  
  Class rb_cCvLDA = define_class_under<cv::LDA>(rb_mCv, "LDA").
    define_constructor(Constructor<cv::LDA, int>()).
    define_constructor(Constructor<cv::LDA, const cv::_InputArray &, const cv::_InputArray &, int>()).
    define_method<void(cv::LDA::*)(const std::basic_string<char>&) const>("save", &cv::LDA::save).
    define_method<void(cv::LDA::*)(const std::basic_string<char>&)>("load", &cv::LDA::load).
    define_method<void(cv::LDA::*)(cv::FileStorage&) const>("save", &cv::LDA::save).
    define_method<void(cv::LDA::*)(const cv::FileStorage&)>("load", &cv::LDA::load).
    define_method<void(cv::LDA::*)(const cv::_InputArray &, const cv::_InputArray &)>("compute", &cv::LDA::compute).
    define_method<cv::Mat(cv::LDA::*)(const cv::_InputArray &)>("project", &cv::LDA::project).
    define_method<cv::Mat(cv::LDA::*)(const cv::_InputArray &)>("reconstruct", &cv::LDA::reconstruct).
    define_method<cv::Mat(cv::LDA::*)() const>("eigenvectors", &cv::LDA::eigenvectors).
    define_method<cv::Mat(cv::LDA::*)() const>("eigenvalues", &cv::LDA::eigenvalues).
    define_singleton_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("subspace_project", &cv::LDA::subspaceProject).
    define_singleton_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("subspace_reconstruct", &cv::LDA::subspaceReconstruct);
  
  Class rb_cCvSVD = define_class_under<cv::SVD>(rb_mCv, "SVD").
    define_constructor(Constructor<cv::SVD>()).
    define_constructor(Constructor<cv::SVD, const cv::_InputArray &, int>()).
    define_method<cv::SVD&(cv::SVD::*)(const cv::_InputArray &, int)>("operator()", &cv::SVD::operator()).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int)>("compute", &cv::SVD::compute).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("compute", &cv::SVD::compute).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("back_subst", &cv::SVD::backSubst).
    define_singleton_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("solve_z", &cv::SVD::solveZ).
    define_method<void(cv::SVD::*)(const cv::_InputArray &, const cv::_OutputArray &) const>("back_subst", &cv::SVD::backSubst).
    define_attr("u", &cv::SVD::u).
    define_attr("w", &cv::SVD::w).
    define_attr("vt", &cv::SVD::vt);
  
  Enum<cv::SVD::Flags> rb_cCvSVDFlags = define_enum<cv::SVD::Flags>("Flags", rb_cCvSVD).
    define_value("MODIFY_A", cv::SVD::Flags::MODIFY_A).
    define_value("NO_UV", cv::SVD::Flags::NO_UV).
    define_value("FULL_UV", cv::SVD::Flags::FULL_UV);
  
  Class rb_cCvRNG = define_class_under<cv::RNG>(rb_mCv, "RNG").
    define_constructor(Constructor<cv::RNG>()).
    define_constructor(Constructor<cv::RNG, unsigned long long>()).
    define_method<unsigned int(cv::RNG::*)()>("next", &cv::RNG::next).
    define_method<unsigned int(cv::RNG::*)()>("operator()", &cv::RNG::operator()).
    define_method<unsigned int(cv::RNG::*)(unsigned int)>("operator()", &cv::RNG::operator()).
    define_method<int(cv::RNG::*)(int, int)>("uniform", &cv::RNG::uniform).
    define_method<float(cv::RNG::*)(float, float)>("uniform", &cv::RNG::uniform).
    define_method<double(cv::RNG::*)(double, double)>("uniform", &cv::RNG::uniform).
    define_method<void(cv::RNG::*)(const cv::_InputOutputArray &, int, const cv::_InputArray &, const cv::_InputArray &, bool)>("fill", &cv::RNG::fill).
    define_method<double(cv::RNG::*)(double)>("gaussian", &cv::RNG::gaussian).
    define_attr("state", &cv::RNG::state).
    define_method<bool(cv::RNG::*)(const cv::RNG&) const>("operator==", &cv::RNG::operator==);
  
  
  Class rb_cCvRNGMT19937 = define_class_under<cv::RNG_MT19937>(rb_mCv, "RNG_MT19937").
    define_constructor(Constructor<cv::RNG_MT19937>()).
    define_constructor(Constructor<cv::RNG_MT19937, unsigned int>()).
    define_method<void(cv::RNG_MT19937::*)(unsigned int)>("seed", &cv::RNG_MT19937::seed).
    define_method<unsigned int(cv::RNG_MT19937::*)()>("next", &cv::RNG_MT19937::next).
    define_method<unsigned int(cv::RNG_MT19937::*)(unsigned int)>("operator()", &cv::RNG_MT19937::operator()).
    define_method<unsigned int(cv::RNG_MT19937::*)()>("operator()", &cv::RNG_MT19937::operator()).
    define_method<int(cv::RNG_MT19937::*)(int, int)>("uniform", &cv::RNG_MT19937::uniform).
    define_method<float(cv::RNG_MT19937::*)(float, float)>("uniform", &cv::RNG_MT19937::uniform).
    define_method<double(cv::RNG_MT19937::*)(double, double)>("uniform", &cv::RNG_MT19937::uniform);
  
  Enum<cv::RNG_MT19937::PeriodParameters> rb_cCvRNGMT19937PeriodParameters = define_enum<cv::RNG_MT19937::PeriodParameters>("PeriodParameters", rb_cCvRNGMT19937).
    define_value("N", cv::RNG_MT19937::PeriodParameters::N).
    define_value("M", cv::RNG_MT19937::PeriodParameters::M);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, int, const cv::_InputOutputArray &, cv::TermCriteria, int, int, const cv::_OutputArray &)>("kmeans", &cv::kmeans);
  
  Class rb_cCvFormatted = define_class_under<cv::Formatted>(rb_mCv, "Formatted").
    define_method<const char*(cv::Formatted::*)()>("next", &cv::Formatted::next).
    define_method<void(cv::Formatted::*)()>("reset", &cv::Formatted::reset);
  
  Class rb_cCvFormatter = define_class_under<cv::Formatter>(rb_mCv, "Formatter").
    define_method<cv::Ptr<cv::Formatted>(cv::Formatter::*)(const cv::Mat&) const>("format", &cv::Formatter::format).
    define_method<void(cv::Formatter::*)(int)>("set16f_precision", &cv::Formatter::set16fPrecision).
    define_method<void(cv::Formatter::*)(int)>("set32f_precision", &cv::Formatter::set32fPrecision).
    define_method<void(cv::Formatter::*)(int)>("set64f_precision", &cv::Formatter::set64fPrecision).
    define_method<void(cv::Formatter::*)(bool)>("set_multiline", &cv::Formatter::setMultiline).
    define_singleton_function<cv::Ptr<cv::Formatter>(*)(cv::Formatter::FormatType)>("get", &cv::Formatter::get);
  
  Enum<cv::Formatter::FormatType> rb_cCvFormatterFormatType = define_enum<cv::Formatter::FormatType>("FormatType", rb_cCvFormatter).
    define_value("FMT_DEFAULT", cv::Formatter::FormatType::FMT_DEFAULT).
    define_value("FMT_MATLAB", cv::Formatter::FormatType::FMT_MATLAB).
    define_value("FMT_CSV", cv::Formatter::FormatType::FMT_CSV).
    define_value("FMT_PYTHON", cv::Formatter::FormatType::FMT_PYTHON).
    define_value("FMT_NUMPY", cv::Formatter::FormatType::FMT_NUMPY).
    define_value("FMT_C", cv::Formatter::FormatType::FMT_C);
  
  Class rb_cCvAlgorithm = define_class_under<cv::Algorithm>(rb_mCv, "Algorithm").
    define_constructor(Constructor<cv::Algorithm>()).
    define_method<void(cv::Algorithm::*)()>("clear", &cv::Algorithm::clear).
    define_method<void(cv::Algorithm::*)(cv::FileStorage&) const>("write", &cv::Algorithm::write).
    define_method<void(cv::Algorithm::*)(cv::FileStorage&, const std::basic_string<char>&) const>("write", &cv::Algorithm::write).
    define_method<void(cv::Algorithm::*)(const cv::Ptr<cv::FileStorage>&, const std::basic_string<char>&) const>("write", &cv::Algorithm::write).
    define_method<void(cv::Algorithm::*)(const cv::FileNode&)>("read", &cv::Algorithm::read).
    define_method<bool(cv::Algorithm::*)() const>("empty", &cv::Algorithm::empty).
    define_method<void(cv::Algorithm::*)(const std::basic_string<char>&) const>("save", &cv::Algorithm::save).
    define_method<std::basic_string<char>(cv::Algorithm::*)() const>("get_default_name", &cv::Algorithm::getDefaultName);
  
  Enum<cv::Param> rb_cCvParam = define_enum<cv::Param>("Param", rb_mCv).
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
  
  Class rb_cCvParamTypeBool = define_class_under<cv::ParamType<bool>>(rb_mCv, "ParamTypeBool");
  
  
  Class rb_cCvParamTypeInt = define_class_under<cv::ParamType<int>>(rb_mCv, "ParamTypeInt");
  
  
  Class rb_cCvParamTypeDouble = define_class_under<cv::ParamType<double>>(rb_mCv, "ParamTypeDouble");
  
  
  Class rb_cCvParamTypeString = define_class_under<cv::ParamType<String>>(rb_mCv, "ParamTypeString");
  
  
  Class rb_cCvParamTypeMat = define_class_under<cv::ParamType<Mat>>(rb_mCv, "ParamTypeMat");
  
  
  Class rb_cCvParamTypeStdVectorMat = define_class_under<cv::ParamType<std::vector<Mat>>>(rb_mCv, "VectorMat");
  
  
  Class rb_cCvParamTypeAlgorithm = define_class_under<cv::ParamType<Algorithm>>(rb_mCv, "ParamTypeAlgorithm");
  
  
  Class rb_cCvParamTypeFloat = define_class_under<cv::ParamType<float>>(rb_mCv, "ParamTypeFloat");
  
  
  Class rb_cCvParamTypeUnsigned int = define_class_under<cv::ParamType<unsigned int>>(rb_mCv, "ParamTypeUnsigned int");
  
  
  Class rb_cCvParamTypeUint64 = define_class_under<cv::ParamType<uint64>>(rb_mCv, "ParamTypeUint64");
  
  
  Class rb_cCvParamTypeUchar = define_class_under<cv::ParamType<uchar>>(rb_mCv, "ParamTypeUchar");
  
  
  Class rb_cCvParamTypeScalar = define_class_under<cv::ParamType<Scalar>>(rb_mCv, "ParamTypeScalar");
}