#include <opencv2/core/utils/logger.hpp>
#include "logger-rb.hpp"

using namespace Rice;

extern "C"
void Init_Logger()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsLogging = define_module_under(rb_mCvUtils, "Logging");
  
  rb_mCvUtilsLogging.define_module_function<cv::utils::logging::LogLevel(*)(cv::utils::logging::LogLevel)>("set_log_level", &cv::utils::logging::setLogLevel);
  
  rb_mCvUtilsLogging.define_module_function<cv::utils::logging::LogLevel(*)()>("get_log_level", &cv::utils::logging::getLogLevel);
  
  rb_mCvUtilsLogging.define_module_function<void(*)(cv::utils::logging::LogTag*)>("register_log_tag", &cv::utils::logging::registerLogTag);
  
  rb_mCvUtilsLogging.define_module_function<void(*)(const char*, cv::utils::logging::LogLevel)>("set_log_tag_level", &cv::utils::logging::setLogTagLevel);
  
  rb_mCvUtilsLogging.define_module_function<cv::utils::logging::LogLevel(*)(const char*)>("get_log_tag_level", &cv::utils::logging::getLogTagLevel);
  
  Module rb_mCvUtilsLoggingInternal = define_module_under(rb_mCvUtilsLogging, "Internal");
  
  rb_mCvUtilsLoggingInternal.define_module_function<cv::utils::logging::LogTag*(*)()>("get_global_log_tag", &cv::utils::logging::internal::getGlobalLogTag);
  
  rb_mCvUtilsLoggingInternal.define_module_function<void(*)(cv::utils::logging::LogLevel, const char*)>("write_log_message", &cv::utils::logging::internal::writeLogMessage);
  
  rb_mCvUtilsLoggingInternal.define_module_function<void(*)(cv::utils::logging::LogLevel, const char*, const char*, int, const char*, const char*)>("write_log_message_ex", &cv::utils::logging::internal::writeLogMessageEx);
  
  Class rb_cCvUtilsLoggingLogTagAuto = define_class_under<cv::utils::logging::LogTagAuto, cv::utils::logging::LogTag>(rb_mCvUtilsLogging, "LogTagAuto").
    define_constructor(Constructor<cv::utils::logging::LogTagAuto, const char*, cv::utils::logging::LogLevel>());
}