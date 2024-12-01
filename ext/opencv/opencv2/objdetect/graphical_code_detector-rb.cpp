#include <opencv2/objdetect/graphical_code_detector.hpp>
#include "graphical_code_detector-rb.hpp"

using namespace Rice;



void Init_GraphicalCodeDetector()
{
  Module rb_mCv = define_module("Cv");
  
  Class rb_cCvGraphicalCodeDetector = define_class_under<cv::GraphicalCodeDetector>(rb_mCv, "GraphicalCodeDetector").
    define_constructor(Constructor<cv::GraphicalCodeDetector>()).
    define_constructor(Constructor<cv::GraphicalCodeDetector, const cv::GraphicalCodeDetector&>(),
      Arg("")).
    define_method("detect?", &cv::GraphicalCodeDetector::detect,
      Arg("img"), Arg("points")).
    define_method("decode", &cv::GraphicalCodeDetector::decode,
      Arg("img"), Arg("points"), Arg("straight_code") = static_cast<OutputArray>(noArray())).
    define_method("detect_and_decode", &cv::GraphicalCodeDetector::detectAndDecode,
      Arg("img"), Arg("points") = static_cast<OutputArray>(noArray()), Arg("straight_code") = static_cast<OutputArray>(noArray())).
    define_method("detect_multi?", &cv::GraphicalCodeDetector::detectMulti,
      Arg("img"), Arg("points")).
    define_method("decode_multi?", &cv::GraphicalCodeDetector::decodeMulti,
      Arg("img"), Arg("points"), Arg("decoded_info"), Arg("straight_code") = static_cast<OutputArrayOfArrays>(noArray())).
    define_method("detect_and_decode_multi?", &cv::GraphicalCodeDetector::detectAndDecodeMulti,
      Arg("img"), Arg("decoded_info"), Arg("points") = static_cast<OutputArray>(noArray()), Arg("straight_code") = static_cast<OutputArrayOfArrays>(noArray()));
  

}