#include <sstream>
#include <opencv2/core/utils/filesystem.hpp>
#include "filesystem-rb.hpp"

using namespace Rice;



void Init_Filesystem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&)>("exists", &cv::utils::fs::exists,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&)>("is_directory", &cv::utils::fs::isDirectory,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&)>("remove_all", &cv::utils::fs::remove_all,
    Arg("path"));
  
  rb_mCv.define_singleton_attr("String", &cv::String);
  
  rb_mCv.define_singleton_attr("String", &cv::String);
  
  rb_mCv.define_singleton_attr("String", &cv::String);
  
  rb_mCv.define_singleton_attr("String", &cv::String);
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&, const int&, int)>("glob", &cv::utils::fs::glob,
    Arg("directory"), Arg("pattern"), Arg(""));
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&, const int&, int)>("glob_relative", &cv::utils::fs::glob_relative,
    Arg("directory"), Arg("pattern"), Arg(""));
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&)>("create_directory", &cv::utils::fs::createDirectory,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function<int(*)(const int&)>("create_directories", &cv::utils::fs::createDirectories,
    Arg("path"));

}