#include <opencv2/datasets/util.hpp>
#include "util-rb.hpp"

using namespace Rice;

extern "C"
void Init_Util()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");
  
  rb_mCvDatasets.define_module_function<void(*)(const std::basic_string<char>&, std::vector<std::basic_string<char>>&, char)>("split", &cv::datasets::split);
  
  rb_mCvDatasets.define_module_function<void(*)(const std::basic_string<char>&)>("create_directory", &cv::datasets::createDirectory);
  
  rb_mCvDatasets.define_module_function<void(*)(const std::basic_string<char>&, std::vector<std::basic_string<char>>&)>("get_dir_list", &cv::datasets::getDirList);
}