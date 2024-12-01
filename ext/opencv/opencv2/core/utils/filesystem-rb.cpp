#include <opencv2/core/utils/filesystem.hpp>
#include "filesystem-rb.hpp"

using namespace Rice;

extern "C"
void Init_Filesystem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");
  
  rb_mCvUtilsFs.define_module_function<bool(*)(const std::basic_string<char>&)>("exists", &cv::utils::fs::exists);
  
  rb_mCvUtilsFs.define_module_function<bool(*)(const std::basic_string<char>&)>("is_directory", &cv::utils::fs::isDirectory);
  
  rb_mCvUtilsFs.define_module_function<void(*)(const std::basic_string<char>&)>("remove_all", &cv::utils::fs::remove_all);
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<char>(*)()>("getcwd", &cv::utils::fs::getcwd);
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&)>("canonical", &cv::utils::fs::canonical);
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("join", &cv::utils::fs::join);
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<char>(*)(const std::basic_string<char>&)>("get_parent", &cv::utils::fs::getParent);
  
  rb_mCvUtilsFs.define_module_function<std::basic_string<wchar_t>(*)(const std::basic_string<wchar_t>&)>("get_parent", &cv::utils::fs::getParent);
  
  rb_mCvUtilsFs.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, std::vector<std::basic_string<char>>&, bool, bool)>("glob", &cv::utils::fs::glob);
  
  rb_mCvUtilsFs.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, std::vector<std::basic_string<char>>&, bool, bool)>("glob_relative", &cv::utils::fs::glob_relative);
  
  rb_mCvUtilsFs.define_module_function<bool(*)(const std::basic_string<char>&)>("create_directory", &cv::utils::fs::createDirectory);
  
  rb_mCvUtilsFs.define_module_function<bool(*)(const std::basic_string<char>&)>("create_directories", &cv::utils::fs::createDirectories);
}