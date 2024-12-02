#include <opencv2/tracking/kalman_filters.hpp>
#include "kalman_filters-rb.hpp"

using namespace Rice;

extern "C"
void Init_KalmanFilters()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Module rb_mCvDetailTracking = define_module_under(rb_mCvDetail, "Tracking");
  
  Module rb_mCvDetailTrackingKalmanFilters = define_module_under(rb_mCvDetailTracking, "KalmanFilters");
  
  Class rb_cCvDetailUnscentedKalmanFilter = define_class_under<cv::detail::UnscentedKalmanFilter>(rb_mCvDetailTrackingKalmanFilters, "UnscentedKalmanFilter").
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)(const cv::_InputArray &)>("predict", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::predict).
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)(const cv::_InputArray &)>("correct", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::correct).
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)() const>("get_process_noise_cov", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::getProcessNoiseCov).
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)() const>("get_measurement_noise_cov", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::getMeasurementNoiseCov).
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)() const>("get_error_cov", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::getErrorCov).
    define_method<cv::Mat(cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::*)() const>("get_state", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilter::getState);
  
  Class rb_cCvDetailUkfSystemModel = define_class_under<cv::detail::UkfSystemModel>(rb_mCvDetailTrackingKalmanFilters, "UkfSystemModel").
    define_method<void(cv::detail::tracking::kalman_filters::UkfSystemModel::*)(const cv::Mat&, const cv::Mat&, const cv::Mat&, cv::Mat&)>("state_conversion_function", &cv::detail::tracking::kalman_filters::UkfSystemModel::stateConversionFunction).
    define_method<void(cv::detail::tracking::kalman_filters::UkfSystemModel::*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("measurement_function", &cv::detail::tracking::kalman_filters::UkfSystemModel::measurementFunction);
  
  Class rb_cCvDetailUnscentedKalmanFilterParams = define_class_under<cv::detail::UnscentedKalmanFilterParams>(rb_mCvDetailTrackingKalmanFilters, "UnscentedKalmanFilterParams").
    define_attr("dp", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::DP).
    define_attr("mp", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::MP).
    define_attr("cp", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::CP).
    define_attr("data_type", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::dataType).
    define_attr("state_init", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::stateInit).
    define_attr("error_cov_init", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::errorCovInit).
    define_attr("process_noise_cov", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::processNoiseCov).
    define_attr("measurement_noise_cov", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::measurementNoiseCov).
    define_attr("alpha", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::alpha).
    define_attr("k", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::k).
    define_attr("beta", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::beta).
    define_attr("model", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::model).
    define_constructor(Constructor<cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams>()).
    define_constructor(Constructor<cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams, int, int, int, double, double, cv::Ptr<cv::detail::UkfSystemModel>, int>()).
    define_method<void(cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::*)(int, int, int, double, double, cv::Ptr<cv::detail::UkfSystemModel>, int)>("init", &cv::detail::tracking::kalman_filters::UnscentedKalmanFilterParams::init);
  
  Class rb_cCvDetailAugmentedUnscentedKalmanFilterParams = define_class_under<cv::detail::AugmentedUnscentedKalmanFilterParams, cv::detail::UnscentedKalmanFilterParams>(rb_mCvDetailTrackingKalmanFilters, "AugmentedUnscentedKalmanFilterParams").
    define_constructor(Constructor<cv::detail::tracking::kalman_filters::AugmentedUnscentedKalmanFilterParams>()).
    define_constructor(Constructor<cv::detail::tracking::kalman_filters::AugmentedUnscentedKalmanFilterParams, int, int, int, double, double, cv::Ptr<cv::detail::UkfSystemModel>, int>()).
    define_method<void(cv::detail::tracking::kalman_filters::AugmentedUnscentedKalmanFilterParams::*)(int, int, int, double, double, cv::Ptr<cv::detail::UkfSystemModel>, int)>("init", &cv::detail::tracking::kalman_filters::AugmentedUnscentedKalmanFilterParams::init);
  
  rb_mCvDetailTrackingKalmanFilters.define_module_function<cv::Ptr<cv::detail::UnscentedKalmanFilter>(*)(const cv::detail::UnscentedKalmanFilterParams&)>("create_unscented_kalman_filter", &cv::detail::tracking::kalman_filters::createUnscentedKalmanFilter);
  
  rb_mCvDetailTrackingKalmanFilters.define_module_function<cv::Ptr<cv::detail::UnscentedKalmanFilter>(*)(const cv::detail::AugmentedUnscentedKalmanFilterParams&)>("create_augmented_unscented_kalman_filter", &cv::detail::tracking::kalman_filters::createAugmentedUnscentedKalmanFilter);
}