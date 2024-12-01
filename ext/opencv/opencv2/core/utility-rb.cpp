#include <opencv2/core/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

extern "C"
void Init_Utility()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<bool(*)(bool)>("set_break_on_error", &cv::setBreakOnError);
  
//  rb_mCv.define_module_function<int (*)(int, const char *, const char *, const char *, int, void *)(*)(int (*)(int, const char *, const char *, const char *, int, void *), void*, void**)>("redirect_error", &cv::redirectError);
  
  rb_mCv.define_module_function<std::basic_string<char>(*)(const char*)>("tempfile", &cv::tempfile);
  
  rb_mCv.define_module_function<void(*)(std::basic_string<char>, std::vector<std::basic_string<char>>&, bool)>("glob", &cv::glob);
  
  rb_mCv.define_module_function<void(*)(int)>("set_num_threads", &cv::setNumThreads);
  
  rb_mCv.define_module_function<int(*)()>("get_num_threads", &cv::getNumThreads);
  
  rb_mCv.define_module_function<int(*)()>("get_thread_num", &cv::getThreadNum);
  
  rb_mCv.define_module_function<const std::basic_string<char>&(*)()>("get_build_information", &cv::getBuildInformation);
  
  rb_mCv.define_module_function<std::basic_string<char>(*)()>("get_version_string", &cv::getVersionString);
  
  rb_mCv.define_module_function<int(*)()>("get_version_major", &cv::getVersionMajor);
  
  rb_mCv.define_module_function<int(*)()>("get_version_minor", &cv::getVersionMinor);
  
  rb_mCv.define_module_function<int(*)()>("get_version_revision", &cv::getVersionRevision);
  
  rb_mCv.define_module_function<long long(*)()>("get_tick_count", &cv::getTickCount);
  
  rb_mCv.define_module_function<double(*)()>("get_tick_frequency", &cv::getTickFrequency);
  
  Class rb_cCvTickMeter = define_class_under<cv::TickMeter>(rb_mCv, "TickMeter").
    define_constructor(Constructor<cv::TickMeter>()).
    define_method<void(cv::TickMeter::*)()>("start", &cv::TickMeter::start).
    define_method<void(cv::TickMeter::*)()>("stop", &cv::TickMeter::stop).
    define_method<long long(cv::TickMeter::*)() const>("get_time_ticks", &cv::TickMeter::getTimeTicks).
    define_method<double(cv::TickMeter::*)() const>("get_time_micro", &cv::TickMeter::getTimeMicro).
    define_method<double(cv::TickMeter::*)() const>("get_time_milli", &cv::TickMeter::getTimeMilli).
    define_method<double(cv::TickMeter::*)() const>("get_time_sec", &cv::TickMeter::getTimeSec).
    define_method<long long(cv::TickMeter::*)() const>("get_counter", &cv::TickMeter::getCounter).
    define_method<double(cv::TickMeter::*)() const>("get_fps", &cv::TickMeter::getFPS).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_sec", &cv::TickMeter::getAvgTimeSec).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_milli", &cv::TickMeter::getAvgTimeMilli).
    define_method<void(cv::TickMeter::*)()>("reset", &cv::TickMeter::reset);
  
  rb_mCv.define_module_function<long long(*)()>("get_cpu_tick_count", &cv::getCPUTickCount);
  
  rb_mCv.define_module_function<bool(*)(int)>("check_hardware_support", &cv::checkHardwareSupport);
  
  rb_mCv.define_module_function<std::basic_string<char>(*)(int)>("get_hardware_feature_name", &cv::getHardwareFeatureName);
  
  rb_mCv.define_module_function<std::basic_string<char>(*)()>("get_cpu_features_line", &cv::getCPUFeaturesLine);
  
  rb_mCv.define_module_function<int(*)()>("get_number_of_cp_us", &cv::getNumberOfCPUs);
  
  rb_mCv.define_module_function<void(*)(bool)>("set_use_optimized", &cv::setUseOptimized);
  
  rb_mCv.define_module_function<bool(*)()>("use_optimized", &cv::useOptimized);
  
  Class rb_cCvParallelLoopBody = define_class_under<cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBody").
    define_method<void(cv::ParallelLoopBody::*)(const cv::Range&) const>("operator()", &cv::ParallelLoopBody::operator());
  
  rb_mCv.define_module_function<void(*)(const cv::Range&, const cv::ParallelLoopBody&, double)>("parallel_for_", &cv::parallel_for_);
  
  Class rb_cCvParallelLoopBodyLambdaWrapper = define_class_under<cv::ParallelLoopBodyLambdaWrapper, cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBodyLambdaWrapper").
    define_constructor(Constructor<cv::ParallelLoopBodyLambdaWrapper, std::function<void (const cv::Range &)>>()).
    define_method<void(cv::ParallelLoopBodyLambdaWrapper::*)(const cv::Range&) const>("operator()", &cv::ParallelLoopBodyLambdaWrapper::operator());
  
  Class rb_cCvCommandLineParser = define_class_under<cv::CommandLineParser>(rb_mCv, "CommandLineParser").
    define_constructor(Constructor<cv::CommandLineParser, int, const char *const[], const std::basic_string<char>&>()).
    define_constructor(Constructor<cv::CommandLineParser, const cv::CommandLineParser&>()).
    define_method<cv::CommandLineParser&(cv::CommandLineParser::*)(const cv::CommandLineParser&)>("operator=", &cv::CommandLineParser::operator=).
    define_method<std::basic_string<char>(cv::CommandLineParser::*)() const>("get_path_to_application", &cv::CommandLineParser::getPathToApplication).
    define_method<bool(cv::CommandLineParser::*)(const std::basic_string<char>&) const>("has", &cv::CommandLineParser::has).
    define_method<bool(cv::CommandLineParser::*)() const>("check", &cv::CommandLineParser::check).
    define_method<void(cv::CommandLineParser::*)(const std::basic_string<char>&)>("about", &cv::CommandLineParser::about).
    define_method<void(cv::CommandLineParser::*)() const>("print_message", &cv::CommandLineParser::printMessage).
    define_method<void(cv::CommandLineParser::*)() const>("print_errors", &cv::CommandLineParser::printErrors);
  
  
  Module rb_mCvSamples = define_module_under(rb_mCv, "Samples");
  
  rb_mCvSamples.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&, bool, bool)>("find_file", &cv::samples::findFile);
  
  rb_mCvSamples.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep);
  
  rb_mCvSamples.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep);
  
  rb_mCvSamples.define_module_function<void(*)(const std::basic_string<char>&)>("add_samples_data_search_path", &cv::samples::addSamplesDataSearchPath);
  
  rb_mCvSamples.define_module_function<void(*)(const std::basic_string<char>&)>("add_samples_data_search_sub_directory", &cv::samples::addSamplesDataSearchSubDirectory);
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_mCvUtils.define_module_function<int(*)()>("get_thread_id", &cv::utils::getThreadID);
}