#include <opencv2/hdf/hdf5.hpp>
#include "hdf5-rb.hpp"

using namespace Rice;

extern "C"
void Init_Hdf5()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHdf = define_module_under(rb_mCv, "Hdf");
  
  Class rb_cCvHdfHDF5 = define_class_under<cv::hdf::HDF5>(rb_mCvHdf, "HDF5").
    define_method<void(cv::hdf::HDF5::*)()>("close", &cv::hdf::HDF5::close).
    define_method<void(cv::hdf::HDF5::*)(const std::basic_string<char>&)>("grcreate", &cv::hdf::HDF5::grcreate).
    define_method<bool(cv::hdf::HDF5::*)(const std::basic_string<char>&) const>("hlexists", &cv::hdf::HDF5::hlexists).
    define_method<bool(cv::hdf::HDF5::*)(const std::basic_string<char>&) const>("atexists", &cv::hdf::HDF5::atexists).
    define_method<void(cv::hdf::HDF5::*)(const std::basic_string<char>&)>("atdelete", &cv::hdf::HDF5::atdelete).
    define_method<void(cv::hdf::HDF5::*)(const int, const std::basic_string<char>&)>("atwrite", &cv::hdf::HDF5::atwrite).
    define_method<void(cv::hdf::HDF5::*)(int*, const std::basic_string<char>&)>("atread", &cv::hdf::HDF5::atread).
    define_method<void(cv::hdf::HDF5::*)(const double, const std::basic_string<char>&)>("atwrite", &cv::hdf::HDF5::atwrite).
    define_method<void(cv::hdf::HDF5::*)(double*, const std::basic_string<char>&)>("atread", &cv::hdf::HDF5::atread).
    define_method<void(cv::hdf::HDF5::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("atwrite", &cv::hdf::HDF5::atwrite).
    define_method<void(cv::hdf::HDF5::*)(std::basic_string<char>*, const std::basic_string<char>&)>("atread", &cv::hdf::HDF5::atread).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&)>("atwrite", &cv::hdf::HDF5::atwrite).
    define_method<void(cv::hdf::HDF5::*)(const cv::_OutputArray &, const std::basic_string<char>&)>("atread", &cv::hdf::HDF5::atread).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const std::basic_string<char>&) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const std::basic_string<char>&, const int) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const std::basic_string<char>&, const int, const std::vector<int>&) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int, const int, const std::basic_string<char>&, const int, const int*) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const std::basic_string<char>&) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const std::basic_string<char>&, const int) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<int>&, const int, const std::basic_string<char>&, const int, const std::vector<int>&) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<void(cv::hdf::HDF5::*)(const int, const int*, const int, const std::basic_string<char>&, const int, const int*) const>("dscreate", &cv::hdf::HDF5::dscreate).
    define_method<std::vector<int>(cv::hdf::HDF5::*)(const std::basic_string<char>&, int) const>("dsgetsize", &cv::hdf::HDF5::dsgetsize).
    define_method<int(cv::hdf::HDF5::*)(const std::basic_string<char>&) const>("dsgettype", &cv::hdf::HDF5::dsgettype).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&) const>("dswrite", &cv::hdf::HDF5::dswrite).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const int*) const>("dswrite", &cv::hdf::HDF5::dswrite).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const std::vector<int>&, const std::vector<int>&) const>("dswrite", &cv::hdf::HDF5::dswrite).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const int*, const int*) const>("dswrite", &cv::hdf::HDF5::dswrite).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&) const>("dsinsert", &cv::hdf::HDF5::dsinsert).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const int*) const>("dsinsert", &cv::hdf::HDF5::dsinsert).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const std::vector<int>&, const std::vector<int>&) const>("dsinsert", &cv::hdf::HDF5::dsinsert).
    define_method<void(cv::hdf::HDF5::*)(const cv::_InputArray &, const std::basic_string<char>&, const int*, const int*) const>("dsinsert", &cv::hdf::HDF5::dsinsert).
    define_method<void(cv::hdf::HDF5::*)(const cv::_OutputArray &, const std::basic_string<char>&) const>("dsread", &cv::hdf::HDF5::dsread).
    define_method<void(cv::hdf::HDF5::*)(const cv::_OutputArray &, const std::basic_string<char>&, const int*) const>("dsread", &cv::hdf::HDF5::dsread).
    define_method<void(cv::hdf::HDF5::*)(const cv::_OutputArray &, const std::basic_string<char>&, const std::vector<int>&, const std::vector<int>&) const>("dsread", &cv::hdf::HDF5::dsread).
    define_method<void(cv::hdf::HDF5::*)(const cv::_OutputArray &, const std::basic_string<char>&, const int*, const int*) const>("dsread", &cv::hdf::HDF5::dsread).
    define_method<int(cv::hdf::HDF5::*)(const std::basic_string<char>&, int) const>("kpgetsize", &cv::hdf::HDF5::kpgetsize).
    define_method<void(cv::hdf::HDF5::*)(const int, const std::basic_string<char>&, const int, const int) const>("kpcreate", &cv::hdf::HDF5::kpcreate).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<cv::KeyPoint>, const std::basic_string<char>&, const int, const int) const>("kpwrite", &cv::hdf::HDF5::kpwrite).
    define_method<void(cv::hdf::HDF5::*)(const std::vector<cv::KeyPoint>, const std::basic_string<char>&, const int, const int) const>("kpinsert", &cv::hdf::HDF5::kpinsert).
    define_method<void(cv::hdf::HDF5::*)(std::vector<cv::KeyPoint>&, const std::basic_string<char>&, const int, const int) const>("kpread", &cv::hdf::HDF5::kpread);
  
  
  rb_mCvHdf.define_module_function<cv::Ptr<cv::hdf::HDF5>(*)(const std::basic_string<char>&)>("open", &cv::hdf::open);
}