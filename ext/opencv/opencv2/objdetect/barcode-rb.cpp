#include <opencv2/objdetect/barcode.hpp>
#include "barcode-rb.hpp"

using namespace Rice;

extern "C"
void Init_Barcode()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvBarcode = define_module_under(rb_mCv, "Barcode");
  
  Class rb_cCvBarcodeBarcodeDetector = define_class_under<cv::barcode::BarcodeDetector, cv::GraphicalCodeDetector>(rb_mCvBarcode, "BarcodeDetector").
    define_constructor(Constructor<cv::barcode::BarcodeDetector>()).
    define_constructor(Constructor<cv::barcode::BarcodeDetector, const std::basic_string<char>&, const std::basic_string<char>&>()).
    define_method<bool(cv::barcode::BarcodeDetector::*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::basic_string<char>>&, std::vector<std::basic_string<char>>&) const>("decode_with_type", &cv::barcode::BarcodeDetector::decodeWithType).
    define_method<bool(cv::barcode::BarcodeDetector::*)(const cv::_InputArray &, std::vector<std::basic_string<char>>&, std::vector<std::basic_string<char>>&, const cv::_OutputArray &) const>("detect_and_decode_with_type", &cv::barcode::BarcodeDetector::detectAndDecodeWithType);
}