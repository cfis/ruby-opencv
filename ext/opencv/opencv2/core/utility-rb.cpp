#include <sstream>
#include <opencv2/core/utility.hpp>
#include "utility-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp, size_t fixed_size>
inline void AutoBuffer_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::AutoBuffer::AutoBuffer<_Tp, fixed_size>>()).
    define_constructor(Constructor<cv::AutoBuffer::AutoBuffer<_Tp, fixed_size>, ::size_t>(),
      Arg("_size")).
    define_constructor(Constructor<cv::AutoBuffer::AutoBuffer<_Tp, fixed_size>, const cv::AutoBuffer<_Tp, fixed_size>&>(),
      Arg("buf")).
    template define_method<cv::AutoBuffer<_Tp, fixed_size>&(cv::AutoBuffer<_Tp, fixed_size>::*)(const cv::AutoBuffer<_Tp, fixed_size>&)>("=", &cv::AutoBuffer<_Tp, fixed_size>::operator=,
      Arg("buf")).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)(::size_t)>("allocate", &cv::AutoBuffer<_Tp, fixed_size>::allocate,
      Arg("_size")).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)()>("deallocate", &cv::AutoBuffer<_Tp, fixed_size>::deallocate).
    template define_method<void(cv::AutoBuffer<_Tp, fixed_size>::*)(::size_t)>("resize", &cv::AutoBuffer<_Tp, fixed_size>::resize,
      Arg("_size")).
    template define_method<::size_t(cv::AutoBuffer<_Tp, fixed_size>::*)() const>("size", &cv::AutoBuffer<_Tp, fixed_size>::size).
    template define_method<_Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)()>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    template define_method<const _Tp*(cv::AutoBuffer<_Tp, fixed_size>::*)() const>("data", &cv::AutoBuffer<_Tp, fixed_size>::data).
    define_method("to_type_parameter_0_0 *", [](const cv::AutoBuffer<_Tp, fixed_size>& self) -> _Tp*
    {
      return self;
    }).
    define_method("to_const type_parameter_0_0 *", [](const cv::AutoBuffer<_Tp, fixed_size>& self) -> const _Tp*
    {
      return self;
    });
};

template<typename Data_Type_T, typename OBJECT>
inline void Node_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Node::Node<OBJECT>>()).
    define_constructor(Constructor<cv::Node::Node<OBJECT>, OBJECT&>(),
      Arg("payload")).
    template define_method<cv::Node<OBJECT>*(cv::Node<OBJECT>::*)(OBJECT&) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("payload")).
    template define_method<int(cv::Node<OBJECT>::*)(cv::Node<OBJECT>*) const>("find_child", &cv::Node<OBJECT>::findChild,
      Arg("p_node")).
    template define_method<void(cv::Node<OBJECT>::*)(cv::Node<OBJECT>*)>("add_child", &cv::Node<OBJECT>::addChild,
      Arg("p_node")).
    template define_method<void(cv::Node<OBJECT>::*)()>("remove_childs", &cv::Node<OBJECT>::removeChilds).
    template define_method<int(cv::Node<OBJECT>::*)()>("get_depth", &cv::Node<OBJECT>::getDepth).
    define_attr("m_payload", &cv::Node<OBJECT>::m_payload).
    define_attr("m_p_parent", &cv::Node<OBJECT>::m_pParent).
    define_attr("m_childs", &cv::Node<OBJECT>::m_childs);
};


void Init_Utility()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<bool(*)(bool)>("set_break_on_error?", &cv::setBreakOnError,
    Arg("flag"));
  
  rb_mCv.define_module_function<cv::::ErrorCallback(*)(cv::::ErrorCallback, void*, void**)>("redirect_error", &cv::redirectError,
    Arg("err_callback"), Arg("userdata") = 0, Arg("prev_userdata") = 0);
  
  rb_mCv.define_module_function<cv::String(*)(const char*)>("tempfile", &cv::tempfile,
    Arg("suffix") = 0);
  
  rb_mCv.define_module_function<void(*)(cv::String, std::vector<std::basic_string<char>>&, bool)>("glob", &cv::glob,
    Arg("pattern"), Arg("result"), Arg("recursive"));
  
  rb_mCv.define_module_function<void(*)(int)>("set_num_threads", &cv::setNumThreads,
    Arg("nthreads"));
  
  rb_mCv.define_module_function<int(*)()>("get_num_threads", &cv::getNumThreads);
  
  rb_mCv.define_module_function<int(*)()>("get_thread_num", &cv::getThreadNum);
  
  rb_mCv.define_module_function<const cv::String&(*)()>("get_build_information", &cv::getBuildInformation);
  
  rb_mCv.define_module_function<cv::String(*)()>("get_version_string", &cv::getVersionString);
  
  rb_mCv.define_module_function<int(*)()>("get_version_major", &cv::getVersionMajor);
  
  rb_mCv.define_module_function<int(*)()>("get_version_minor", &cv::getVersionMinor);
  
  rb_mCv.define_module_function<int(*)()>("get_version_revision", &cv::getVersionRevision);
  
  rb_mCv.define_module_function<int64(*)()>("get_tick_count", &cv::getTickCount);
  
  rb_mCv.define_module_function<double(*)()>("get_tick_frequency", &cv::getTickFrequency);
  
  Class rb_cCvTickMeter = define_class_under<cv::TickMeter>(rb_mCv, "TickMeter").
    define_constructor(Constructor<cv::TickMeter>()).
    define_method<void(cv::TickMeter::*)()>("start", &cv::TickMeter::start).
    define_method<void(cv::TickMeter::*)()>("stop", &cv::TickMeter::stop).
    define_method<int64(cv::TickMeter::*)() const>("get_time_ticks", &cv::TickMeter::getTimeTicks).
    define_method<double(cv::TickMeter::*)() const>("get_time_micro", &cv::TickMeter::getTimeMicro).
    define_method<double(cv::TickMeter::*)() const>("get_time_milli", &cv::TickMeter::getTimeMilli).
    define_method<double(cv::TickMeter::*)() const>("get_time_sec", &cv::TickMeter::getTimeSec).
    define_method<int64(cv::TickMeter::*)() const>("get_counter", &cv::TickMeter::getCounter).
    define_method<double(cv::TickMeter::*)() const>("get_fps", &cv::TickMeter::getFPS).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_sec", &cv::TickMeter::getAvgTimeSec).
    define_method<double(cv::TickMeter::*)() const>("get_avg_time_milli", &cv::TickMeter::getAvgTimeMilli).
    define_method<void(cv::TickMeter::*)()>("reset", &cv::TickMeter::reset);
  
  
  rb_cCvTickMeter.define_method("to_s", [](const cv::TickMeter& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });
  
  rb_mCv.define_module_function<int64(*)()>("get_cpu_tick_count", &cv::getCPUTickCount);
  
  rb_mCv.define_module_function<bool(*)(int)>("check_hardware_support?", &cv::checkHardwareSupport,
    Arg("feature"));
  
  rb_mCv.define_module_function<cv::String(*)(int)>("get_hardware_feature_name", &cv::getHardwareFeatureName,
    Arg("feature"));
  
  rb_mCv.define_module_function<std::string(*)()>("get_cpu_features_line", &cv::getCPUFeaturesLine);
  
  rb_mCv.define_module_function<int(*)()>("get_number_of_cp_us", &cv::getNumberOfCPUs);
  
  rb_mCv.define_module_function<void(*)(bool)>("set_use_optimized", &cv::setUseOptimized,
    Arg("onoff"));
  
  rb_mCv.define_module_function<bool(*)()>("use_optimized?", &cv::useOptimized);
  
  Class rb_cCvParallelLoopBody = define_class_under<cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBody").
    define_method<void(cv::ParallelLoopBody::*)(const cv::Range&) const>("()", &cv::ParallelLoopBody::operator(),
      Arg("range"));
  
  rb_mCv.define_module_function<void(*)(const cv::Range&, const cv::ParallelLoopBody&, double)>("parallel_for_", &cv::parallel_for_,
    Arg("range"), Arg("body"), Arg("nstripes") = -1.);
  
  Class rb_cCvParallelLoopBodyLambdaWrapper = define_class_under<cv::ParallelLoopBodyLambdaWrapper, cv::ParallelLoopBody>(rb_mCv, "ParallelLoopBodyLambdaWrapper").
    define_constructor(Constructor<cv::ParallelLoopBodyLambdaWrapper, std::function<void (const cv::Range &)>>(),
      Arg("functor")).
    define_method<void(cv::ParallelLoopBodyLambdaWrapper::*)(const cv::Range&) const>("()", &cv::ParallelLoopBodyLambdaWrapper::operator(),
      Arg("range"));
  
  Class rb_cCvCommandLineParser = define_class_under<cv::CommandLineParser>(rb_mCv, "CommandLineParser").
    define_constructor(Constructor<cv::CommandLineParser, int, const char *const[], const cv::String&>(),
      Arg("argc"), Arg("argv"), Arg("keys")).
    define_constructor(Constructor<cv::CommandLineParser, const cv::CommandLineParser&>(),
      Arg("parser")).
    define_method<cv::CommandLineParser&(cv::CommandLineParser::*)(const cv::CommandLineParser&)>("=", &cv::CommandLineParser::operator=,
      Arg("parser")).
    define_method<cv::String(cv::CommandLineParser::*)() const>("get_path_to_application", &cv::CommandLineParser::getPathToApplication).
    define_method<bool(cv::CommandLineParser::*)(const cv::String&) const>("has?", &cv::CommandLineParser::has,
      Arg("name")).
    define_method<bool(cv::CommandLineParser::*)() const>("check?", &cv::CommandLineParser::check).
    define_method<void(cv::CommandLineParser::*)(const cv::String&)>("about", &cv::CommandLineParser::about,
      Arg("message")).
    define_method<void(cv::CommandLineParser::*)() const>("print_message", &cv::CommandLineParser::printMessage).
    define_method<void(cv::CommandLineParser::*)() const>("print_errors", &cv::CommandLineParser::printErrors);
  
  
  Module rb_mCvSamples = define_module_under(rb_mCv, "Samples");
  
  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool, bool)>("find_file", &cv::samples::findFile,
    Arg("relative_path"), Arg("required"), Arg("silent_mode"));
  
  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode"));
  
  rb_mCvSamples.define_module_function<cv::String(*)(const cv::String&, bool)>("find_file_or_keep", &cv::samples::findFileOrKeep,
    Arg("relative_path"), Arg("silent_mode"));
  
  rb_mCvSamples.define_module_function<void(*)(const cv::String&)>("add_samples_data_search_path", &cv::samples::addSamplesDataSearchPath,
    Arg("path"));
  
  rb_mCvSamples.define_module_function<void(*)(const cv::String&)>("add_samples_data_search_sub_directory", &cv::samples::addSamplesDataSearchSubDirectory,
    Arg("subdir"));
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  rb_mCvUtils.define_module_function<int(*)()>("get_thread_id", &cv::utils::getThreadID);

}