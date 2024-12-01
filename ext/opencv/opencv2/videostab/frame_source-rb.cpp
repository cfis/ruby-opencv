#include <opencv2/videostab/frame_source.hpp>
#include "frame_source-rb.hpp"

using namespace Rice;

extern "C"
void Init_FrameSource()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
  
  Class rb_cCvVideostabIFrameSource = define_class_under<cv::videostab::IFrameSource>(rb_mCvVideostab, "IFrameSource").
    define_method<void(cv::videostab::IFrameSource::*)()>("reset", &cv::videostab::IFrameSource::reset).
    define_method<cv::Mat(cv::videostab::IFrameSource::*)()>("next_frame", &cv::videostab::IFrameSource::nextFrame);
  
  Class rb_cCvVideostabNullFrameSource = define_class_under<cv::videostab::NullFrameSource, cv::videostab::IFrameSource>(rb_mCvVideostab, "NullFrameSource").
    define_method<void(cv::videostab::NullFrameSource::*)()>("reset", &cv::videostab::NullFrameSource::reset).
    define_method<cv::Mat(cv::videostab::NullFrameSource::*)()>("next_frame", &cv::videostab::NullFrameSource::nextFrame);
  
  Class rb_cCvVideostabVideoFileSource = define_class_under<cv::videostab::VideoFileSource, cv::videostab::IFrameSource>(rb_mCvVideostab, "VideoFileSource").
    define_constructor(Constructor<cv::videostab::VideoFileSource, const std::basic_string<char>&, bool>()).
    define_method<void(cv::videostab::VideoFileSource::*)()>("reset", &cv::videostab::VideoFileSource::reset).
    define_method<cv::Mat(cv::videostab::VideoFileSource::*)()>("next_frame", &cv::videostab::VideoFileSource::nextFrame).
    define_method<int(cv::videostab::VideoFileSource::*)()>("width", &cv::videostab::VideoFileSource::width).
    define_method<int(cv::videostab::VideoFileSource::*)()>("height", &cv::videostab::VideoFileSource::height).
    define_method<int(cv::videostab::VideoFileSource::*)()>("count", &cv::videostab::VideoFileSource::count).
    define_method<double(cv::videostab::VideoFileSource::*)()>("fps", &cv::videostab::VideoFileSource::fps);
  
  Class rb_cCvVideostabMaskFrameSource = define_class_under<cv::videostab::MaskFrameSource, cv::videostab::IFrameSource>(rb_mCvVideostab, "MaskFrameSource").
    define_constructor(Constructor<cv::videostab::MaskFrameSource, const cv::Ptr<cv::videostab::IFrameSource>&>()).
    define_method<void(cv::videostab::MaskFrameSource::*)()>("reset", &cv::videostab::MaskFrameSource::reset).
    define_method<cv::Mat(cv::videostab::MaskFrameSource::*)()>("next_frame", &cv::videostab::MaskFrameSource::nextFrame).
    define_method<void(cv::videostab::MaskFrameSource::*)(std::function<void (cv::Mat &)>)>("set_mask_callback", &cv::videostab::MaskFrameSource::setMaskCallback);
}