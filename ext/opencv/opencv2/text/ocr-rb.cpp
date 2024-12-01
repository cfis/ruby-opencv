#include <opencv2/text/ocr.hpp>
#include "ocr-rb.hpp"

using namespace Rice;

extern "C"
void Init_Ocr()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvText = define_module_under(rb_mCv, "Text");
  
  Enum<cv::text::page_seg_mode> rb_cCvTextPageSegMode = define_enum<cv::text::page_seg_mode>("PageSegMode", rb_mCvText).
    define_value("PSM_OSD_ONLY", cv::text::page_seg_mode::PSM_OSD_ONLY).
    define_value("PSM_AUTO_OSD", cv::text::page_seg_mode::PSM_AUTO_OSD).
    define_value("PSM_AUTO_ONLY", cv::text::page_seg_mode::PSM_AUTO_ONLY).
    define_value("PSM_AUTO", cv::text::page_seg_mode::PSM_AUTO).
    define_value("PSM_SINGLE_COLUMN", cv::text::page_seg_mode::PSM_SINGLE_COLUMN).
    define_value("PSM_SINGLE_BLOCK_VERT_TEXT", cv::text::page_seg_mode::PSM_SINGLE_BLOCK_VERT_TEXT).
    define_value("PSM_SINGLE_BLOCK", cv::text::page_seg_mode::PSM_SINGLE_BLOCK).
    define_value("PSM_SINGLE_LINE", cv::text::page_seg_mode::PSM_SINGLE_LINE).
    define_value("PSM_SINGLE_WORD", cv::text::page_seg_mode::PSM_SINGLE_WORD).
    define_value("PSM_CIRCLE_WORD", cv::text::page_seg_mode::PSM_CIRCLE_WORD).
    define_value("PSM_SINGLE_CHAR", cv::text::page_seg_mode::PSM_SINGLE_CHAR);
  
  Enum<cv::text::ocr_engine_mode> rb_cCvTextOcrEngineMode = define_enum<cv::text::ocr_engine_mode>("OcrEngineMode", rb_mCvText).
    define_value("OEM_TESSERACT_ONLY", cv::text::ocr_engine_mode::OEM_TESSERACT_ONLY).
    define_value("OEM_CUBE_ONLY", cv::text::ocr_engine_mode::OEM_CUBE_ONLY).
    define_value("OEM_TESSERACT_CUBE_COMBINED", cv::text::ocr_engine_mode::OEM_TESSERACT_CUBE_COMBINED).
    define_value("OEM_DEFAULT", cv::text::ocr_engine_mode::OEM_DEFAULT);
  
  Class rb_cCvTextBaseOCR = define_class_under<cv::text::BaseOCR>(rb_mCvText, "BaseOCR").
    define_method<void(cv::text::BaseOCR::*)(cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::BaseOCR::run).
    define_method<void(cv::text::BaseOCR::*)(cv::Mat&, cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::BaseOCR::run);
  
  Class rb_cCvTextOCRTesseract = define_class_under<cv::text::OCRTesseract, cv::text::BaseOCR>(rb_mCvText, "OCRTesseract").
    define_method<void(cv::text::OCRTesseract::*)(cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRTesseract::run).
    define_method<void(cv::text::OCRTesseract::*)(cv::Mat&, cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRTesseract::run).
    define_method<std::basic_string<char>(cv::text::OCRTesseract::*)(const cv::_InputArray &, int, int)>("run", &cv::text::OCRTesseract::run).
    define_method<std::basic_string<char>(cv::text::OCRTesseract::*)(const cv::_InputArray &, const cv::_InputArray &, int, int)>("run", &cv::text::OCRTesseract::run).
    define_method<void(cv::text::OCRTesseract::*)(const std::basic_string<char>&)>("set_white_list", &cv::text::OCRTesseract::setWhiteList).
    define_singleton_function<cv::Ptr<cv::text::OCRTesseract>(*)(const char*, const char*, const char*, int, int)>("create", &cv::text::OCRTesseract::create);
  
  Enum<cv::text::decoder_mode> rb_cCvTextDecoderMode = define_enum<cv::text::decoder_mode>("DecoderMode", rb_mCvText).
    define_value("OCR_DECODER_VITERBI", cv::text::decoder_mode::OCR_DECODER_VITERBI);
  
  Enum<cv::text::classifier_type> rb_cCvTextClassifierType = define_enum<cv::text::classifier_type>("ClassifierType", rb_mCvText).
    define_value("OCR_KNN_CLASSIFIER", cv::text::classifier_type::OCR_KNN_CLASSIFIER).
    define_value("OCR_CNN_CLASSIFIER", cv::text::classifier_type::OCR_CNN_CLASSIFIER);
  
  Class rb_cCvTextOCRHMMDecoder = define_class_under<cv::text::OCRHMMDecoder, cv::text::BaseOCR>(rb_mCvText, "OCRHMMDecoder").
    define_method<void(cv::text::OCRHMMDecoder::*)(cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRHMMDecoder::run).
    define_method<void(cv::text::OCRHMMDecoder::*)(cv::Mat&, cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRHMMDecoder::run).
    define_method<std::basic_string<char>(cv::text::OCRHMMDecoder::*)(const cv::_InputArray &, int, int)>("run", &cv::text::OCRHMMDecoder::run).
    define_method<std::basic_string<char>(cv::text::OCRHMMDecoder::*)(const cv::_InputArray &, const cv::_InputArray &, int, int)>("run", &cv::text::OCRHMMDecoder::run).
    define_singleton_function<cv::Ptr<cv::text::OCRHMMDecoder>(*)(const cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>, const std::basic_string<char>&, const cv::_InputArray &, const cv::_InputArray &, int)>("create", &cv::text::OCRHMMDecoder::create).
    define_singleton_function<cv::Ptr<cv::text::OCRHMMDecoder>(*)(const std::basic_string<char>&, const std::basic_string<char>&, const cv::_InputArray &, const cv::_InputArray &, int, int)>("create", &cv::text::OCRHMMDecoder::create);
  
  Class rb_cCvTextOCRHMMDecoderClassifierCallback = define_class_under<cv::text::OCRHMMDecoder::ClassifierCallback>(rb_cCvTextOCRHMMDecoder, "ClassifierCallback").
    define_method<void(cv::text::OCRHMMDecoder::ClassifierCallback::*)(const cv::_InputArray &, std::vector<int>&, std::vector<double>&)>("eval", &cv::text::OCRHMMDecoder::ClassifierCallback::eval);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const std::basic_string<char>&)>("load_ocrhmm_classifier_nm", &cv::text::loadOCRHMMClassifierNM);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const std::basic_string<char>&)>("load_ocrhmm_classifier_cnn", &cv::text::loadOCRHMMClassifierCNN);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRHMMDecoder::ClassifierCallback>(*)(const std::basic_string<char>&, int)>("load_ocrhmm_classifier", &cv::text::loadOCRHMMClassifier);
  
  rb_mCvText.define_module_function<void(*)(std::basic_string<char>&, std::vector<std::basic_string<char>>&, const cv::_OutputArray &)>("create_ocrhmm_transitions_table", &cv::text::createOCRHMMTransitionsTable);
  
  rb_mCvText.define_module_function<cv::Mat(*)(const std::basic_string<char>&, std::vector<std::basic_string<char>>&)>("create_ocrhmm_transitions_table", &cv::text::createOCRHMMTransitionsTable);
  
  Class rb_cCvTextOCRBeamSearchDecoder = define_class_under<cv::text::OCRBeamSearchDecoder, cv::text::BaseOCR>(rb_mCvText, "OCRBeamSearchDecoder").
    define_method<void(cv::text::OCRBeamSearchDecoder::*)(cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRBeamSearchDecoder::run).
    define_method<void(cv::text::OCRBeamSearchDecoder::*)(cv::Mat&, cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRBeamSearchDecoder::run).
    define_method<std::basic_string<char>(cv::text::OCRBeamSearchDecoder::*)(const cv::_InputArray &, int, int)>("run", &cv::text::OCRBeamSearchDecoder::run).
    define_method<std::basic_string<char>(cv::text::OCRBeamSearchDecoder::*)(const cv::_InputArray &, const cv::_InputArray &, int, int)>("run", &cv::text::OCRBeamSearchDecoder::run).
    define_singleton_function<cv::Ptr<cv::text::OCRBeamSearchDecoder>(*)(const cv::Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>, const std::basic_string<char>&, const cv::_InputArray &, const cv::_InputArray &, cv::text::decoder_mode, int)>("create", &cv::text::OCRBeamSearchDecoder::create).
    define_singleton_function<cv::Ptr<cv::text::OCRBeamSearchDecoder>(*)(const std::basic_string<char>&, const std::basic_string<char>&, const cv::_InputArray &, const cv::_InputArray &, cv::text::decoder_mode, int)>("create", &cv::text::OCRBeamSearchDecoder::create);
  
  Class rb_cCvTextOCRBeamSearchDecoderClassifierCallback = define_class_under<cv::text::OCRBeamSearchDecoder::ClassifierCallback>(rb_cCvTextOCRBeamSearchDecoder, "ClassifierCallback").
    define_method<void(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)(const cv::_InputArray &, std::vector<std::vector<double>>&, std::vector<int>&)>("eval", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::eval).
    define_method<int(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)()>("get_window_size", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::getWindowSize).
    define_method<int(cv::text::OCRBeamSearchDecoder::ClassifierCallback::*)()>("get_step_size", &cv::text::OCRBeamSearchDecoder::ClassifierCallback::getStepSize);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::OCRBeamSearchDecoder::ClassifierCallback>(*)(const std::basic_string<char>&)>("load_ocr_beam_search_classifier_cnn", &cv::text::loadOCRBeamSearchClassifierCNN);
  
  Class rb_cCvTextOCRHolisticWordRecognizer = define_class_under<cv::text::OCRHolisticWordRecognizer, cv::text::BaseOCR>(rb_mCvText, "OCRHolisticWordRecognizer").
    define_method<void(cv::text::OCRHolisticWordRecognizer::*)(cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRHolisticWordRecognizer::run).
    define_method<void(cv::text::OCRHolisticWordRecognizer::*)(cv::Mat&, cv::Mat&, std::basic_string<char>&, std::vector<cv::Rect_<int>>*, std::vector<std::basic_string<char>>*, std::vector<float>*, int)>("run", &cv::text::OCRHolisticWordRecognizer::run).
    define_singleton_function<cv::Ptr<cv::text::OCRHolisticWordRecognizer>(*)(const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&)>("create", &cv::text::OCRHolisticWordRecognizer::create);
}