#include <opencv2/ccalib/multicalib.hpp>
#include "multicalib-rb.hpp"

using namespace Rice;

extern "C"
void Init_Multicalib()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvMulticalib = define_module_under(rb_mCv, "Multicalib");
  
  Class rb_cCvMulticalibMultiCameraCalibration = define_class_under<cv::multicalib::MultiCameraCalibration>(rb_mCvMulticalib, "MultiCameraCalibration").
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration, int, int, const std::basic_string<char>&, float, float, int, int, int, int, cv::TermCriteria, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::DescriptorMatcher>>()).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)()>("load_images", &cv::multicalib::MultiCameraCalibration::loadImages).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)()>("initialize", &cv::multicalib::MultiCameraCalibration::initialize).
    define_method<double(cv::multicalib::MultiCameraCalibration::*)()>("optimize_extrinsics", &cv::multicalib::MultiCameraCalibration::optimizeExtrinsics).
    define_method<double(cv::multicalib::MultiCameraCalibration::*)()>("run", &cv::multicalib::MultiCameraCalibration::run).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)(const std::basic_string<char>&)>("write_parameters", &cv::multicalib::MultiCameraCalibration::writeParameters);
  
  Class rb_cCvMulticalibMultiCameraCalibrationEdge = define_class_under<cv::multicalib::MultiCameraCalibration::edge>(rb_cCvMulticalibMultiCameraCalibration, "Edge").
    define_attr("camera_vertex", &cv::multicalib::MultiCameraCalibration::edge::cameraVertex).
    define_attr("photo_vertex", &cv::multicalib::MultiCameraCalibration::edge::photoVertex).
    define_attr("photo_index", &cv::multicalib::MultiCameraCalibration::edge::photoIndex).
    define_attr("transform", &cv::multicalib::MultiCameraCalibration::edge::transform).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::edge, int, int, int, cv::Mat>());
  
  Class rb_cCvMulticalibMultiCameraCalibrationVertex = define_class_under<cv::multicalib::MultiCameraCalibration::vertex>(rb_cCvMulticalibMultiCameraCalibration, "Vertex").
    define_attr("pose", &cv::multicalib::MultiCameraCalibration::vertex::pose).
    define_attr("timestamp", &cv::multicalib::MultiCameraCalibration::vertex::timestamp).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::vertex, cv::Mat, int>()).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::vertex>());
}