#include <opencv2/imgcodecs.hpp>
#include "imgcodecs-rb.hpp"

using namespace Rice;



extern "C"
void Init_Imgcodecs()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::ImreadModes> rb_cCvImreadModes = define_enum<cv::ImreadModes>("ImreadModes", rb_mCv).
    define_value("IMREAD_UNCHANGED", cv::ImreadModes::IMREAD_UNCHANGED).
    define_value("IMREAD_GRAYSCALE", cv::ImreadModes::IMREAD_GRAYSCALE).
    define_value("IMREAD_COLOR", cv::ImreadModes::IMREAD_COLOR).
    define_value("IMREAD_ANYDEPTH", cv::ImreadModes::IMREAD_ANYDEPTH).
    define_value("IMREAD_ANYCOLOR", cv::ImreadModes::IMREAD_ANYCOLOR).
    define_value("IMREAD_LOAD_GDAL", cv::ImreadModes::IMREAD_LOAD_GDAL).
    define_value("IMREAD_REDUCED_GRAYSCALE_2", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_2).
    define_value("IMREAD_REDUCED_COLOR_2", cv::ImreadModes::IMREAD_REDUCED_COLOR_2).
    define_value("IMREAD_REDUCED_GRAYSCALE_4", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_4).
    define_value("IMREAD_REDUCED_COLOR_4", cv::ImreadModes::IMREAD_REDUCED_COLOR_4).
    define_value("IMREAD_REDUCED_GRAYSCALE_8", cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_8).
    define_value("IMREAD_REDUCED_COLOR_8", cv::ImreadModes::IMREAD_REDUCED_COLOR_8).
    define_value("IMREAD_IGNORE_ORIENTATION", cv::ImreadModes::IMREAD_IGNORE_ORIENTATION);
  
  Enum<cv::ImwriteFlags> rb_cCvImwriteFlags = define_enum<cv::ImwriteFlags>("ImwriteFlags", rb_mCv).
    define_value("IMWRITE_JPEG_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_QUALITY).
    define_value("IMWRITE_JPEG_PROGRESSIVE", cv::ImwriteFlags::IMWRITE_JPEG_PROGRESSIVE).
    define_value("IMWRITE_JPEG_OPTIMIZE", cv::ImwriteFlags::IMWRITE_JPEG_OPTIMIZE).
    define_value("IMWRITE_JPEG_RST_INTERVAL", cv::ImwriteFlags::IMWRITE_JPEG_RST_INTERVAL).
    define_value("IMWRITE_JPEG_LUMA_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_LUMA_QUALITY).
    define_value("IMWRITE_JPEG_CHROMA_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_CHROMA_QUALITY).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR", cv::ImwriteFlags::IMWRITE_JPEG_SAMPLING_FACTOR).
    define_value("IMWRITE_PNG_COMPRESSION", cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION).
    define_value("IMWRITE_PNG_STRATEGY", cv::ImwriteFlags::IMWRITE_PNG_STRATEGY).
    define_value("IMWRITE_PNG_BILEVEL", cv::ImwriteFlags::IMWRITE_PNG_BILEVEL).
    define_value("IMWRITE_PXM_BINARY", cv::ImwriteFlags::IMWRITE_PXM_BINARY).
    define_value("IMWRITE_EXR_TYPE", cv::ImwriteFlags::IMWRITE_EXR_TYPE).
    define_value("IMWRITE_EXR_COMPRESSION", cv::ImwriteFlags::IMWRITE_EXR_COMPRESSION).
    define_value("IMWRITE_EXR_DWA_COMPRESSION_LEVEL", cv::ImwriteFlags::IMWRITE_EXR_DWA_COMPRESSION_LEVEL).
    define_value("IMWRITE_WEBP_QUALITY", cv::ImwriteFlags::IMWRITE_WEBP_QUALITY).
    define_value("IMWRITE_HDR_COMPRESSION", cv::ImwriteFlags::IMWRITE_HDR_COMPRESSION).
    define_value("IMWRITE_PAM_TUPLETYPE", cv::ImwriteFlags::IMWRITE_PAM_TUPLETYPE).
    define_value("IMWRITE_TIFF_RESUNIT", cv::ImwriteFlags::IMWRITE_TIFF_RESUNIT).
    define_value("IMWRITE_TIFF_XDPI", cv::ImwriteFlags::IMWRITE_TIFF_XDPI).
    define_value("IMWRITE_TIFF_YDPI", cv::ImwriteFlags::IMWRITE_TIFF_YDPI).
    define_value("IMWRITE_TIFF_COMPRESSION", cv::ImwriteFlags::IMWRITE_TIFF_COMPRESSION).
    define_value("IMWRITE_TIFF_ROWSPERSTRIP", cv::ImwriteFlags::IMWRITE_TIFF_ROWSPERSTRIP).
    define_value("IMWRITE_TIFF_PREDICTOR", cv::ImwriteFlags::IMWRITE_TIFF_PREDICTOR).
    define_value("IMWRITE_JPEG2000_COMPRESSION_X1000", cv::ImwriteFlags::IMWRITE_JPEG2000_COMPRESSION_X1000).
    define_value("IMWRITE_AVIF_QUALITY", cv::ImwriteFlags::IMWRITE_AVIF_QUALITY).
    define_value("IMWRITE_AVIF_DEPTH", cv::ImwriteFlags::IMWRITE_AVIF_DEPTH).
    define_value("IMWRITE_AVIF_SPEED", cv::ImwriteFlags::IMWRITE_AVIF_SPEED);
  
  Enum<cv::ImwriteJPEGSamplingFactorParams> rb_cCvImwriteJPEGSamplingFactorParams = define_enum<cv::ImwriteJPEGSamplingFactorParams>("ImwriteJPEGSamplingFactorParams", rb_mCv).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_411", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_411).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_420", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_420).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_422", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_422).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_440", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_440).
    define_value("IMWRITE_JPEG_SAMPLING_FACTOR_444", cv::ImwriteJPEGSamplingFactorParams::IMWRITE_JPEG_SAMPLING_FACTOR_444);
  
  Enum<cv::ImwriteTiffCompressionFlags> rb_cCvImwriteTiffCompressionFlags = define_enum<cv::ImwriteTiffCompressionFlags>("ImwriteTiffCompressionFlags", rb_mCv).
    define_value("IMWRITE_TIFF_COMPRESSION_NONE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_NONE).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTRLE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTRLE).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTFAX3", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTFAX3).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITT_T4", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITT_T4).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTFAX4", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTFAX4).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITT_T6", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITT_T6).
    define_value("IMWRITE_TIFF_COMPRESSION_LZW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LZW).
    define_value("IMWRITE_TIFF_COMPRESSION_OJPEG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_OJPEG).
    define_value("IMWRITE_TIFF_COMPRESSION_JPEG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JPEG).
    define_value("IMWRITE_TIFF_COMPRESSION_T85", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_T85).
    define_value("IMWRITE_TIFF_COMPRESSION_T43", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_T43).
    define_value("IMWRITE_TIFF_COMPRESSION_NEXT", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_NEXT).
    define_value("IMWRITE_TIFF_COMPRESSION_CCITTRLEW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_CCITTRLEW).
    define_value("IMWRITE_TIFF_COMPRESSION_PACKBITS", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PACKBITS).
    define_value("IMWRITE_TIFF_COMPRESSION_THUNDERSCAN", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_THUNDERSCAN).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8CTPAD", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8CTPAD).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8LW", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8LW).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8MP", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8MP).
    define_value("IMWRITE_TIFF_COMPRESSION_IT8BL", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_IT8BL).
    define_value("IMWRITE_TIFF_COMPRESSION_PIXARFILM", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PIXARFILM).
    define_value("IMWRITE_TIFF_COMPRESSION_PIXARLOG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_PIXARLOG).
    define_value("IMWRITE_TIFF_COMPRESSION_DEFLATE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_DEFLATE).
    define_value("IMWRITE_TIFF_COMPRESSION_ADOBE_DEFLATE", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_ADOBE_DEFLATE).
    define_value("IMWRITE_TIFF_COMPRESSION_DCS", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_DCS).
    define_value("IMWRITE_TIFF_COMPRESSION_JBIG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JBIG).
    define_value("IMWRITE_TIFF_COMPRESSION_SGILOG", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_SGILOG).
    define_value("IMWRITE_TIFF_COMPRESSION_SGILOG24", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_SGILOG24).
    define_value("IMWRITE_TIFF_COMPRESSION_JP2000", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JP2000).
    define_value("IMWRITE_TIFF_COMPRESSION_LERC", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LERC).
    define_value("IMWRITE_TIFF_COMPRESSION_LZMA", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_LZMA).
    define_value("IMWRITE_TIFF_COMPRESSION_ZSTD", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_ZSTD).
    define_value("IMWRITE_TIFF_COMPRESSION_WEBP", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_WEBP).
    define_value("IMWRITE_TIFF_COMPRESSION_JXL", cv::ImwriteTiffCompressionFlags::IMWRITE_TIFF_COMPRESSION_JXL);
  
  Enum<cv::ImwriteTiffPredictorFlags> rb_cCvImwriteTiffPredictorFlags = define_enum<cv::ImwriteTiffPredictorFlags>("ImwriteTiffPredictorFlags", rb_mCv).
    define_value("IMWRITE_TIFF_PREDICTOR_NONE", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_NONE).
    define_value("IMWRITE_TIFF_PREDICTOR_HORIZONTAL", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_HORIZONTAL).
    define_value("IMWRITE_TIFF_PREDICTOR_FLOATINGPOINT", cv::ImwriteTiffPredictorFlags::IMWRITE_TIFF_PREDICTOR_FLOATINGPOINT);
  
  Enum<cv::ImwriteEXRTypeFlags> rb_cCvImwriteEXRTypeFlags = define_enum<cv::ImwriteEXRTypeFlags>("ImwriteEXRTypeFlags", rb_mCv).
    define_value("IMWRITE_EXR_TYPE_HALF", cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_HALF).
    define_value("IMWRITE_EXR_TYPE_FLOAT", cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_FLOAT);
  
  Enum<cv::ImwriteEXRCompressionFlags> rb_cCvImwriteEXRCompressionFlags = define_enum<cv::ImwriteEXRCompressionFlags>("ImwriteEXRCompressionFlags", rb_mCv).
    define_value("IMWRITE_EXR_COMPRESSION_NO", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_NO).
    define_value("IMWRITE_EXR_COMPRESSION_RLE", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_RLE).
    define_value("IMWRITE_EXR_COMPRESSION_ZIPS", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_ZIPS).
    define_value("IMWRITE_EXR_COMPRESSION_ZIP", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_ZIP).
    define_value("IMWRITE_EXR_COMPRESSION_PIZ", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_PIZ).
    define_value("IMWRITE_EXR_COMPRESSION_PXR24", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_PXR24).
    define_value("IMWRITE_EXR_COMPRESSION_B44", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_B44).
    define_value("IMWRITE_EXR_COMPRESSION_B44A", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_B44A).
    define_value("IMWRITE_EXR_COMPRESSION_DWAA", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_DWAA).
    define_value("IMWRITE_EXR_COMPRESSION_DWAB", cv::ImwriteEXRCompressionFlags::IMWRITE_EXR_COMPRESSION_DWAB);
  
  Enum<cv::ImwritePNGFlags> rb_cCvImwritePNGFlags = define_enum<cv::ImwritePNGFlags>("ImwritePNGFlags", rb_mCv).
    define_value("IMWRITE_PNG_STRATEGY_DEFAULT", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_DEFAULT).
    define_value("IMWRITE_PNG_STRATEGY_FILTERED", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FILTERED).
    define_value("IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY).
    define_value("IMWRITE_PNG_STRATEGY_RLE", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_RLE).
    define_value("IMWRITE_PNG_STRATEGY_FIXED", cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FIXED);
  
  Enum<cv::ImwritePAMFlags> rb_cCvImwritePAMFlags = define_enum<cv::ImwritePAMFlags>("ImwritePAMFlags", rb_mCv).
    define_value("IMWRITE_PAM_FORMAT_NULL", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_NULL).
    define_value("IMWRITE_PAM_FORMAT_BLACKANDWHITE", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_BLACKANDWHITE).
    define_value("IMWRITE_PAM_FORMAT_GRAYSCALE", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE).
    define_value("IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA).
    define_value("IMWRITE_PAM_FORMAT_RGB", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB).
    define_value("IMWRITE_PAM_FORMAT_RGB_ALPHA", cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB_ALPHA);
  
  Enum<cv::ImwriteHDRCompressionFlags> rb_cCvImwriteHDRCompressionFlags = define_enum<cv::ImwriteHDRCompressionFlags>("ImwriteHDRCompressionFlags", rb_mCv).
    define_value("IMWRITE_HDR_COMPRESSION_NONE", cv::ImwriteHDRCompressionFlags::IMWRITE_HDR_COMPRESSION_NONE).
    define_value("IMWRITE_HDR_COMPRESSION_RLE", cv::ImwriteHDRCompressionFlags::IMWRITE_HDR_COMPRESSION_RLE);
  
  rb_mCv.define_module_function<cv::Mat(*)(const std::basic_string<char>&, int)>("imread", &cv::imread);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const cv::_OutputArray &, int)>("imread", &cv::imread);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&, std::vector<cv::Mat>&, int)>("imreadmulti", &cv::imreadmulti);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&, std::vector<cv::Mat>&, int, int, int)>("imreadmulti", &cv::imreadmulti);
  
  rb_mCv.define_module_function<unsigned long long(*)(const std::basic_string<char>&, int)>("imcount", &cv::imcount);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&, const cv::_InputArray &, const std::vector<int>&)>("imwrite", &cv::imwrite);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, int)>("imdecode", &cv::imdecode);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, int, cv::Mat*)>("imdecode", &cv::imdecode);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, int, std::vector<cv::Mat>&, const cv::Range&)>("imdecodemulti", &cv::imdecodemulti);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&, const cv::_InputArray &, std::vector<unsigned char>&, const std::vector<int>&)>("imencode", &cv::imencode);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&)>("have_image_reader", &cv::haveImageReader);
  
  rb_mCv.define_module_function<bool(*)(const std::basic_string<char>&)>("have_image_writer", &cv::haveImageWriter);
  
  Class rb_cCvImageCollection = define_class_under<cv::ImageCollection>(rb_mCv, "ImageCollection").
    define_constructor(Constructor<cv::ImageCollection>()).
    define_constructor(Constructor<cv::ImageCollection, const std::basic_string<char>&, int>()).
    define_method<void(cv::ImageCollection::*)(const std::basic_string<char>&, int)>("init", &cv::ImageCollection::init).
    define_method<unsigned long long(cv::ImageCollection::*)() const>("size", &cv::ImageCollection::size).
    define_method<const cv::Mat & (cv::ImageCollection::*)(int)>("at", &cv::ImageCollection::at).
    define_method<const cv::Mat & (cv::ImageCollection::*)(int)>("operator[]", &cv::ImageCollection::operator[]).
    define_method<void(cv::ImageCollection::*)(int)>("release_cache", &cv::ImageCollection::releaseCache).
    define_method<cv::ImageCollection::iterator(cv::ImageCollection::*)()>("begin", &cv::ImageCollection::begin).
    define_method<cv::ImageCollection::iterator(cv::ImageCollection::*)()>("end", &cv::ImageCollection::end);
    //define_method<cv::Ptr<cv::ImageCollection::Impl>(cv::ImageCollection::*)()>("get_impl", &cv::ImageCollection::getImpl);
  
  
  Class rb_cCvImageCollectionIterator = define_class_under<cv::ImageCollection::iterator>(rb_cCvImageCollection, "Iterator").
    define_constructor(Constructor<cv::ImageCollection::iterator, cv::ImageCollection*>()).
    define_constructor(Constructor<cv::ImageCollection::iterator, cv::ImageCollection*, int>()).
    define_method<cv::Mat&(cv::ImageCollection::iterator::*)()>("operator*", &cv::ImageCollection::iterator::operator*).
    define_method<cv::Mat*(cv::ImageCollection::iterator::*)()>("operator_>", &cv::ImageCollection::iterator::operator->).
    define_method<cv::ImageCollection::iterator&(cv::ImageCollection::iterator::*)()>("operator++", &cv::ImageCollection::iterator::operator++).
    define_method<cv::ImageCollection::iterator(cv::ImageCollection::iterator::*)(int)>("operator++", &cv::ImageCollection::iterator::operator++);

}