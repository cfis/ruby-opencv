#include <opencv2/videoio/registry.hpp>
#include "registry-rb.hpp"

using namespace Rice;

extern "C"
void Init_Registry()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideoioRegistry = define_module_under(rb_mCv, "VideoioRegistry");
  
  rb_mCvVideoioRegistry.define_module_function<std::basic_string<char>(*)(cv::VideoCaptureAPIs)>("get_backend_name", &cv::videoio_registry::getBackendName);
  
  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_backends", &cv::videoio_registry::getBackends);
  
  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_camera_backends", &cv::videoio_registry::getCameraBackends);
  
  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_stream_backends", &cv::videoio_registry::getStreamBackends);
  
  rb_mCvVideoioRegistry.define_module_function<std::vector<cv::VideoCaptureAPIs>(*)()>("get_writer_backends", &cv::videoio_registry::getWriterBackends);
  
  rb_mCvVideoioRegistry.define_module_function<bool(*)(cv::VideoCaptureAPIs)>("has_backend", &cv::videoio_registry::hasBackend);
  
  rb_mCvVideoioRegistry.define_module_function<bool(*)(cv::VideoCaptureAPIs)>("is_backend_built_in", &cv::videoio_registry::isBackendBuiltIn);
  
  rb_mCvVideoioRegistry.define_module_function<std::basic_string<char>(*)(cv::VideoCaptureAPIs, int&, int&)>("get_camera_backend_plugin_version", &cv::videoio_registry::getCameraBackendPluginVersion);
  
  rb_mCvVideoioRegistry.define_module_function<std::basic_string<char>(*)(cv::VideoCaptureAPIs, int&, int&)>("get_stream_backend_plugin_version", &cv::videoio_registry::getStreamBackendPluginVersion);
  
  rb_mCvVideoioRegistry.define_module_function<std::basic_string<char>(*)(cv::VideoCaptureAPIs, int&, int&)>("get_writer_backend_plugin_version", &cv::videoio_registry::getWriterBackendPluginVersion);
}