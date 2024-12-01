#include <opencv2/dnn_superres.hpp>
#include "dnn_superres-rb.hpp"

using namespace Rice;

extern "C"
void Init_DnnSuperres()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnnSuperres = define_module_under(rb_mCv, "DnnSuperres");
  
  Class rb_cCvDnnSuperresDnnSuperResImpl = define_class_under<cv::dnn_superres::DnnSuperResImpl>(rb_mCvDnnSuperres, "DnnSuperResImpl").
    define_singleton_function<cv::Ptr<cv::dnn_superres::DnnSuperResImpl>(*)()>("create", &cv::dnn_superres::DnnSuperResImpl::create).
    define_constructor(Constructor<cv::dnn_superres::DnnSuperResImpl>()).
    define_constructor(Constructor<cv::dnn_superres::DnnSuperResImpl, const std::basic_string<char>&, int>()).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const std::basic_string<char>&)>("read_model", &cv::dnn_superres::DnnSuperResImpl::readModel).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("read_model", &cv::dnn_superres::DnnSuperResImpl::readModel).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const std::basic_string<char>&, int)>("set_model", &cv::dnn_superres::DnnSuperResImpl::setModel).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(int)>("set_preferable_backend", &cv::dnn_superres::DnnSuperResImpl::setPreferableBackend).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(int)>("set_preferable_target", &cv::dnn_superres::DnnSuperResImpl::setPreferableTarget).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const cv::_InputArray &, const cv::_OutputArray &)>("upsample", &cv::dnn_superres::DnnSuperResImpl::upsample).
    define_method<void(cv::dnn_superres::DnnSuperResImpl::*)(const cv::_InputArray &, std::vector<cv::Mat>&, const std::vector<int>&, const std::vector<std::basic_string<char>>&)>("upsample_multioutput", &cv::dnn_superres::DnnSuperResImpl::upsampleMultioutput).
    define_method<int(cv::dnn_superres::DnnSuperResImpl::*)()>("get_scale", &cv::dnn_superres::DnnSuperResImpl::getScale).
    define_method<std::basic_string<char>(cv::dnn_superres::DnnSuperResImpl::*)()>("get_algorithm", &cv::dnn_superres::DnnSuperResImpl::getAlgorithm);
}