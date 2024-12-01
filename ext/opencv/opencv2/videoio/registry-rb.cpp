#include <opencv2/videoio/registry.hpp>
#include "registry-rb.hpp"

using namespace Rice;



void Init_Registry()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideoioRegistry = define_module_under(rb_mCv, "VideoioRegistry");
  
  rb_mCvVideoioRegistry.define_module_function("get_backend_name", &cv::videoio_registry::getBackendName,
    Arg("api"));
  
  rb_mCvVideoioRegistry.define_module_function("get_backends", &cv::videoio_registry::getBackends);
  
  rb_mCvVideoioRegistry.define_module_function("get_camera_backends", &cv::videoio_registry::getCameraBackends);
  
  rb_mCvVideoioRegistry.define_module_function("get_stream_backends", &cv::videoio_registry::getStreamBackends);
  
  rb_mCvVideoioRegistry.define_module_function("get_writer_backends", &cv::videoio_registry::getWriterBackends);
  
  rb_mCvVideoioRegistry.define_module_function("has_backend?", &cv::videoio_registry::hasBackend,
    Arg("api"));
  
  rb_mCvVideoioRegistry.define_module_function("is_backend_built_in?", &cv::videoio_registry::isBackendBuiltIn,
    Arg("api"));
  
  rb_mCvVideoioRegistry.define_module_function("get_camera_backend_plugin_version", &cv::videoio_registry::getCameraBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));
  
  rb_mCvVideoioRegistry.define_module_function("get_stream_backend_plugin_version", &cv::videoio_registry::getStreamBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));
  
  rb_mCvVideoioRegistry.define_module_function("get_writer_backend_plugin_version", &cv::videoio_registry::getWriterBackendPluginVersion,
    Arg("api"), Arg("version_abi"), Arg("version_api"));

}