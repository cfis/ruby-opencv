#include <opencv2/stereo/quasi_dense_stereo.hpp>
#include "quasi_dense_stereo-rb.hpp"

using namespace Rice;

extern "C"
void Init_QuasiDenseStereo()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvStereo = define_module_under(rb_mCv, "Stereo");
  
  Class rb_cCvStereoMatchQuasiDense = define_class_under<cv::stereo::MatchQuasiDense>(rb_mCvStereo, "MatchQuasiDense").
    define_attr("p0", &cv::stereo::MatchQuasiDense::p0).
    define_attr("p1", &cv::stereo::MatchQuasiDense::p1).
    define_attr("corr", &cv::stereo::MatchQuasiDense::corr).
    define_constructor(Constructor<cv::stereo::MatchQuasiDense>()).
    define_method<bool(cv::stereo::MatchQuasiDense::*)(const cv::stereo::MatchQuasiDense&) const>("operator<", &cv::stereo::MatchQuasiDense::operator<);
  
  Class rb_cCvStereoPropagationParameters = define_class_under<cv::stereo::PropagationParameters>(rb_mCvStereo, "PropagationParameters").
    define_attr("corr_win_size_x", &cv::stereo::PropagationParameters::corrWinSizeX).
    define_attr("corr_win_size_y", &cv::stereo::PropagationParameters::corrWinSizeY).
    define_attr("border_x", &cv::stereo::PropagationParameters::borderX).
    define_attr("border_y", &cv::stereo::PropagationParameters::borderY).
    define_attr("correlation_threshold", &cv::stereo::PropagationParameters::correlationThreshold).
    define_attr("textrure_threshold", &cv::stereo::PropagationParameters::textrureThreshold).
    define_attr("neighborhood_size", &cv::stereo::PropagationParameters::neighborhoodSize).
    define_attr("disparity_gradient", &cv::stereo::PropagationParameters::disparityGradient).
    define_attr("lk_template_size", &cv::stereo::PropagationParameters::lkTemplateSize).
    define_attr("lk_pyr_lvl", &cv::stereo::PropagationParameters::lkPyrLvl).
    define_attr("lk_term_param1", &cv::stereo::PropagationParameters::lkTermParam1).
    define_attr("lk_term_param2", &cv::stereo::PropagationParameters::lkTermParam2).
    define_attr("gft_quality_thres", &cv::stereo::PropagationParameters::gftQualityThres).
    define_attr("gft_min_seperation_dist", &cv::stereo::PropagationParameters::gftMinSeperationDist).
    define_attr("gft_max_num_features", &cv::stereo::PropagationParameters::gftMaxNumFeatures);
  
  Class rb_cCvStereoQuasiDenseStereo = define_class_under<cv::stereo::QuasiDenseStereo>(rb_mCvStereo, "QuasiDenseStereo").
    define_method<int(cv::stereo::QuasiDenseStereo::*)(std::basic_string<char>)>("load_parameters", &cv::stereo::QuasiDenseStereo::loadParameters).
    define_method<int(cv::stereo::QuasiDenseStereo::*)(std::basic_string<char>)>("save_parameters", &cv::stereo::QuasiDenseStereo::saveParameters).
    define_method<void(cv::stereo::QuasiDenseStereo::*)(std::vector<cv::stereo::MatchQuasiDense>&)>("get_sparse_matches", &cv::stereo::QuasiDenseStereo::getSparseMatches).
    define_method<void(cv::stereo::QuasiDenseStereo::*)(std::vector<cv::stereo::MatchQuasiDense>&)>("get_dense_matches", &cv::stereo::QuasiDenseStereo::getDenseMatches).
    define_method<void(cv::stereo::QuasiDenseStereo::*)(const cv::Mat&, const cv::Mat&)>("process", &cv::stereo::QuasiDenseStereo::process).
    define_method<cv::Point_<float>(cv::stereo::QuasiDenseStereo::*)(const int, const int)>("get_match", &cv::stereo::QuasiDenseStereo::getMatch).
    define_method<cv::Mat(cv::stereo::QuasiDenseStereo::*)()>("get_disparity", &cv::stereo::QuasiDenseStereo::getDisparity).
    define_singleton_function<cv::Ptr<cv::stereo::QuasiDenseStereo>(*)(cv::Size_<int>, std::basic_string<char>)>("create", &cv::stereo::QuasiDenseStereo::create).
    define_attr("param", &cv::stereo::QuasiDenseStereo::Param);
}