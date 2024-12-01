#include <opencv2/videostab/log.hpp>
#include "log-rb.hpp"

using namespace Rice;

extern "C"
void Init_Log()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabILog = define_class_under<cv::videostab::ILog>(rb_mCvVideostab, "ILog").
    define_method<void(cv::videostab::ILog::*)(const char*)>("print", &cv::videostab::ILog::print);
  
  Class rb_cCvVideostabNullLog = define_class_under<cv::videostab::NullLog, cv::videostab::ILog>(rb_mCvVideostab, "NullLog").
    define_method<void(cv::videostab::NullLog::*)(const char*)>("print", &cv::videostab::NullLog::print);
  
  Class rb_cCvVideostabLogToStdout = define_class_under<cv::videostab::LogToStdout, cv::videostab::ILog>(rb_mCvVideostab, "LogToStdout").
    define_method<void(cv::videostab::LogToStdout::*)(const char*)>("print", &cv::videostab::LogToStdout::print);
}