#include <opencv2/core/utils/logger.defines.hpp>
#include "logger.defines-rb.hpp"

using namespace Rice;

extern "C"
void Init_LoggerDefines()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsLogging = define_module_under(rb_mCvUtils, "Logging");
  
  Enum<cv::utils::logging::LogLevel> rb_cCvUtilsLoggingLogLevel = define_enum<cv::utils::logging::LogLevel>("LogLevel", rb_mCvUtilsLogging).
    define_value("LOG_LEVEL_SILENT", cv::utils::logging::LogLevel::LOG_LEVEL_SILENT).
    define_value("LOG_LEVEL_FATAL", cv::utils::logging::LogLevel::LOG_LEVEL_FATAL).
    define_value("LOG_LEVEL_ERROR", cv::utils::logging::LogLevel::LOG_LEVEL_ERROR).
    define_value("LOG_LEVEL_WARNING", cv::utils::logging::LogLevel::LOG_LEVEL_WARNING).
    define_value("LOG_LEVEL_INFO", cv::utils::logging::LogLevel::LOG_LEVEL_INFO).
    define_value("LOG_LEVEL_DEBUG", cv::utils::logging::LogLevel::LOG_LEVEL_DEBUG).
    define_value("LOG_LEVEL_VERBOSE", cv::utils::logging::LogLevel::LOG_LEVEL_VERBOSE).
    define_value("ENUM_LOG_LEVEL_FORCE_INT", cv::utils::logging::LogLevel::ENUM_LOG_LEVEL_FORCE_INT);
}