#include <opencv2/cudacodec.hpp>
#include "cudacodec-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudacodec()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudacodec = define_module_under(rb_mCv, "Cudacodec");
  
  Enum<cv::cudacodec::Codec> rb_cCvCudacodecCodec = define_enum<cv::cudacodec::Codec>("Codec", rb_mCvCudacodec).
    define_value("MPEG1", cv::cudacodec::Codec::MPEG1).
    define_value("MPEG2", cv::cudacodec::Codec::MPEG2).
    define_value("MPEG4", cv::cudacodec::Codec::MPEG4).
    define_value("VC1", cv::cudacodec::Codec::VC1).
    define_value("H264", cv::cudacodec::Codec::H264).
    define_value("JPEG", cv::cudacodec::Codec::JPEG).
    define_value("H264_SVC", cv::cudacodec::Codec::H264_SVC).
    define_value("H264_MVC", cv::cudacodec::Codec::H264_MVC).
    define_value("HEVC", cv::cudacodec::Codec::HEVC).
    define_value("VP8", cv::cudacodec::Codec::VP8).
    define_value("VP9", cv::cudacodec::Codec::VP9).
    define_value("AV1", cv::cudacodec::Codec::AV1).
    define_value("NumCodecs", cv::cudacodec::Codec::NumCodecs).
    define_value("Uncompressed_YUV420", cv::cudacodec::Codec::Uncompressed_YUV420).
    define_value("Uncompressed_YV12", cv::cudacodec::Codec::Uncompressed_YV12).
    define_value("Uncompressed_NV12", cv::cudacodec::Codec::Uncompressed_NV12).
    define_value("Uncompressed_YUYV", cv::cudacodec::Codec::Uncompressed_YUYV).
    define_value("Uncompressed_UYVY", cv::cudacodec::Codec::Uncompressed_UYVY);
  
  Enum<cv::cudacodec::ColorFormat> rb_cCvCudacodecColorFormat = define_enum<cv::cudacodec::ColorFormat>("ColorFormat", rb_mCvCudacodec).
    define_value("UNDEFINED", cv::cudacodec::ColorFormat::UNDEFINED).
    define_value("BGRA", cv::cudacodec::ColorFormat::BGRA).
    define_value("BGR", cv::cudacodec::ColorFormat::BGR).
    define_value("GRAY", cv::cudacodec::ColorFormat::GRAY).
    define_value("NV_NV12", cv::cudacodec::ColorFormat::NV_NV12).
    define_value("RGB", cv::cudacodec::ColorFormat::RGB).
    define_value("RGBA", cv::cudacodec::ColorFormat::RGBA).
    define_value("NV_YV12", cv::cudacodec::ColorFormat::NV_YV12).
    define_value("NV_IYUV", cv::cudacodec::ColorFormat::NV_IYUV).
    define_value("NV_YUV444", cv::cudacodec::ColorFormat::NV_YUV444).
    define_value("NV_AYUV", cv::cudacodec::ColorFormat::NV_AYUV).
    define_value("PROP_NOT_SUPPORTED", cv::cudacodec::ColorFormat::PROP_NOT_SUPPORTED);
  
  Enum<cv::cudacodec::EncodeParamsRcMode> rb_cCvCudacodecEncodeParamsRcMode = define_enum<cv::cudacodec::EncodeParamsRcMode>("EncodeParamsRcMode", rb_mCvCudacodec).
    define_value("ENC_PARAMS_RC_CONSTQP", cv::cudacodec::EncodeParamsRcMode::ENC_PARAMS_RC_CONSTQP).
    define_value("ENC_PARAMS_RC_VBR", cv::cudacodec::EncodeParamsRcMode::ENC_PARAMS_RC_VBR).
    define_value("ENC_PARAMS_RC_CBR", cv::cudacodec::EncodeParamsRcMode::ENC_PARAMS_RC_CBR);
  
  Enum<cv::cudacodec::EncodeMultiPass> rb_cCvCudacodecEncodeMultiPass = define_enum<cv::cudacodec::EncodeMultiPass>("EncodeMultiPass", rb_mCvCudacodec).
    define_value("ENC_MULTI_PASS_DISABLED", cv::cudacodec::EncodeMultiPass::ENC_MULTI_PASS_DISABLED).
    define_value("ENC_TWO_PASS_QUARTER_RESOLUTION", cv::cudacodec::EncodeMultiPass::ENC_TWO_PASS_QUARTER_RESOLUTION).
    define_value("ENC_TWO_PASS_FULL_RESOLUTION", cv::cudacodec::EncodeMultiPass::ENC_TWO_PASS_FULL_RESOLUTION);
  
  Enum<cv::cudacodec::EncodeProfile> rb_cCvCudacodecEncodeProfile = define_enum<cv::cudacodec::EncodeProfile>("EncodeProfile", rb_mCvCudacodec).
    define_value("ENC_CODEC_PROFILE_AUTOSELECT", cv::cudacodec::EncodeProfile::ENC_CODEC_PROFILE_AUTOSELECT).
    define_value("ENC_H264_PROFILE_BASELINE", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_BASELINE).
    define_value("ENC_H264_PROFILE_MAIN", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_MAIN).
    define_value("ENC_H264_PROFILE_HIGH", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_HIGH).
    define_value("ENC_H264_PROFILE_HIGH_444", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_HIGH_444).
    define_value("ENC_H264_PROFILE_STEREO", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_STEREO).
    define_value("ENC_H264_PROFILE_PROGRESSIVE_HIGH", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_PROGRESSIVE_HIGH).
    define_value("ENC_H264_PROFILE_CONSTRAINED_HIGH", cv::cudacodec::EncodeProfile::ENC_H264_PROFILE_CONSTRAINED_HIGH).
    define_value("ENC_HEVC_PROFILE_MAIN", cv::cudacodec::EncodeProfile::ENC_HEVC_PROFILE_MAIN).
    define_value("ENC_HEVC_PROFILE_MAIN10", cv::cudacodec::EncodeProfile::ENC_HEVC_PROFILE_MAIN10).
    define_value("ENC_HEVC_PROFILE_FREXT", cv::cudacodec::EncodeProfile::ENC_HEVC_PROFILE_FREXT);
  
  Enum<cv::cudacodec::EncodePreset> rb_cCvCudacodecEncodePreset = define_enum<cv::cudacodec::EncodePreset>("EncodePreset", rb_mCvCudacodec).
    define_value("ENC_PRESET_P1", cv::cudacodec::EncodePreset::ENC_PRESET_P1).
    define_value("ENC_PRESET_P2", cv::cudacodec::EncodePreset::ENC_PRESET_P2).
    define_value("ENC_PRESET_P3", cv::cudacodec::EncodePreset::ENC_PRESET_P3).
    define_value("ENC_PRESET_P4", cv::cudacodec::EncodePreset::ENC_PRESET_P4).
    define_value("ENC_PRESET_P5", cv::cudacodec::EncodePreset::ENC_PRESET_P5).
    define_value("ENC_PRESET_P6", cv::cudacodec::EncodePreset::ENC_PRESET_P6).
    define_value("ENC_PRESET_P7", cv::cudacodec::EncodePreset::ENC_PRESET_P7);
  
  Enum<cv::cudacodec::EncodeTuningInfo> rb_cCvCudacodecEncodeTuningInfo = define_enum<cv::cudacodec::EncodeTuningInfo>("EncodeTuningInfo", rb_mCvCudacodec).
    define_value("ENC_TUNING_INFO_UNDEFINED", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_UNDEFINED).
    define_value("ENC_TUNING_INFO_HIGH_QUALITY", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_HIGH_QUALITY).
    define_value("ENC_TUNING_INFO_LOW_LATENCY", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_LOW_LATENCY).
    define_value("ENC_TUNING_INFO_ULTRA_LOW_LATENCY", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_ULTRA_LOW_LATENCY).
    define_value("ENC_TUNING_INFO_LOSSLESS", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_LOSSLESS).
    define_value("ENC_TUNING_INFO_COUNT", cv::cudacodec::EncodeTuningInfo::ENC_TUNING_INFO_COUNT);
  
  Class rb_cCvCudacodecEncodeQp = define_class_under<cv::cudacodec::EncodeQp>(rb_mCvCudacodec, "EncodeQp").
    define_attr("qp_inter_p", &cv::cudacodec::EncodeQp::qpInterP).
    define_attr("qp_inter_b", &cv::cudacodec::EncodeQp::qpInterB).
    define_attr("qp_intra", &cv::cudacodec::EncodeQp::qpIntra);
  
  Class rb_cCvCudacodecEncoderParams = define_class_under<cv::cudacodec::EncoderParams>(rb_mCvCudacodec, "EncoderParams").
    define_constructor(Constructor<cv::cudacodec::EncoderParams>()).
    define_attr("nv_preset", &cv::cudacodec::EncoderParams::nvPreset).
    define_attr("tuning_info", &cv::cudacodec::EncoderParams::tuningInfo).
    define_attr("encoding_profile", &cv::cudacodec::EncoderParams::encodingProfile).
    define_attr("rate_control_mode", &cv::cudacodec::EncoderParams::rateControlMode).
    define_attr("multi_pass_encoding", &cv::cudacodec::EncoderParams::multiPassEncoding).
    define_attr("const_qp", &cv::cudacodec::EncoderParams::constQp).
    define_attr("average_bit_rate", &cv::cudacodec::EncoderParams::averageBitRate).
    define_attr("max_bit_rate", &cv::cudacodec::EncoderParams::maxBitRate).
    define_attr("target_quality", &cv::cudacodec::EncoderParams::targetQuality).
    define_attr("gop_length", &cv::cudacodec::EncoderParams::gopLength);
  
  rb_mCvCudacodec.define_module_function<bool(*)(const cv::cudacodec::EncoderParams&, const cv::cudacodec::EncoderParams&)>("operator==", &cv::cudacodec::operator==);
  
  Class rb_cCvCudacodecEncoderCallback = define_class_under<cv::cudacodec::EncoderCallback>(rb_mCvCudacodec, "EncoderCallback").
    define_method<void(cv::cudacodec::EncoderCallback::*)(std::vector<std::vector<unsigned char>>)>("on_encoded", &cv::cudacodec::EncoderCallback::onEncoded).
    define_method<void(cv::cudacodec::EncoderCallback::*)()>("on_encoding_finished", &cv::cudacodec::EncoderCallback::onEncodingFinished);
  
  Class rb_cCvCudacodecVideoWriter = define_class_under<cv::cudacodec::VideoWriter>(rb_mCvCudacodec, "VideoWriter").
    define_method<void(cv::cudacodec::VideoWriter::*)(const cv::_InputArray &)>("write", &cv::cudacodec::VideoWriter::write).
    define_method<cv::cudacodec::EncoderParams(cv::cudacodec::VideoWriter::*)() const>("get_encoder_params", &cv::cudacodec::VideoWriter::getEncoderParams).
    define_method<void(cv::cudacodec::VideoWriter::*)()>("release", &cv::cudacodec::VideoWriter::release);
  
  rb_mCvCudacodec.define_module_function<cv::Ptr<cv::cudacodec::VideoWriter>(*)(const std::basic_string<char>&, const cv::Size_<int>, const cv::cudacodec::Codec, const double, const cv::cudacodec::ColorFormat, cv::Ptr<cv::cudacodec::EncoderCallback>, const cv::cuda::Stream&)>("create_video_writer", &cv::cudacodec::createVideoWriter);
  
  rb_mCvCudacodec.define_module_function<cv::Ptr<cv::cudacodec::VideoWriter>(*)(const std::basic_string<char>&, const cv::Size_<int>, const cv::cudacodec::Codec, const double, const cv::cudacodec::ColorFormat, const cv::cudacodec::EncoderParams&, cv::Ptr<cv::cudacodec::EncoderCallback>, const cv::cuda::Stream&)>("create_video_writer", &cv::cudacodec::createVideoWriter);
  
  Enum<cv::cudacodec::ChromaFormat> rb_cCvCudacodecChromaFormat = define_enum<cv::cudacodec::ChromaFormat>("ChromaFormat", rb_mCvCudacodec).
    define_value("Monochrome", cv::cudacodec::ChromaFormat::Monochrome).
    define_value("YUV420", cv::cudacodec::ChromaFormat::YUV420).
    define_value("YUV422", cv::cudacodec::ChromaFormat::YUV422).
    define_value("YUV444", cv::cudacodec::ChromaFormat::YUV444).
    define_value("NumFormats", cv::cudacodec::ChromaFormat::NumFormats);
  
  Enum<cv::cudacodec::DeinterlaceMode> rb_cCvCudacodecDeinterlaceMode = define_enum<cv::cudacodec::DeinterlaceMode>("DeinterlaceMode", rb_mCvCudacodec).
    define_value("Weave", cv::cudacodec::DeinterlaceMode::Weave).
    define_value("Bob", cv::cudacodec::DeinterlaceMode::Bob).
    define_value("Adaptive", cv::cudacodec::DeinterlaceMode::Adaptive);
  
  Class rb_cCvCudacodecFormatInfo = define_class_under<cv::cudacodec::FormatInfo>(rb_mCvCudacodec, "FormatInfo").
    define_constructor(Constructor<cv::cudacodec::FormatInfo>()).
    define_attr("codec", &cv::cudacodec::FormatInfo::codec).
    define_attr("chroma_format", &cv::cudacodec::FormatInfo::chromaFormat).
    define_attr("n_bit_depth_minus8", &cv::cudacodec::FormatInfo::nBitDepthMinus8).
    define_attr("n_bit_depth_chroma_minus8", &cv::cudacodec::FormatInfo::nBitDepthChromaMinus8).
    define_attr("ul_width", &cv::cudacodec::FormatInfo::ulWidth).
    define_attr("ul_height", &cv::cudacodec::FormatInfo::ulHeight).
    define_attr("width", &cv::cudacodec::FormatInfo::width).
    define_attr("height", &cv::cudacodec::FormatInfo::height).
    define_attr("ul_max_width", &cv::cudacodec::FormatInfo::ulMaxWidth).
    define_attr("ul_max_height", &cv::cudacodec::FormatInfo::ulMaxHeight).
    define_attr("display_area", &cv::cudacodec::FormatInfo::displayArea).
    define_attr("valid", &cv::cudacodec::FormatInfo::valid).
    define_attr("fps", &cv::cudacodec::FormatInfo::fps).
    define_attr("ul_num_decode_surfaces", &cv::cudacodec::FormatInfo::ulNumDecodeSurfaces).
    define_attr("deinterlace_mode", &cv::cudacodec::FormatInfo::deinterlaceMode).
    define_attr("target_sz", &cv::cudacodec::FormatInfo::targetSz).
    define_attr("src_roi", &cv::cudacodec::FormatInfo::srcRoi).
    define_attr("target_roi", &cv::cudacodec::FormatInfo::targetRoi).
    define_attr("video_full_range_flag", &cv::cudacodec::FormatInfo::videoFullRangeFlag);
  
  Enum<cv::cudacodec::VideoReaderProps> rb_cCvCudacodecVideoReaderProps = define_enum<cv::cudacodec::VideoReaderProps>("VideoReaderProps", rb_mCvCudacodec).
    define_value("PROP_DECODED_FRAME_IDX", cv::cudacodec::VideoReaderProps::PROP_DECODED_FRAME_IDX).
    define_value("PROP_EXTRA_DATA_INDEX", cv::cudacodec::VideoReaderProps::PROP_EXTRA_DATA_INDEX).
    define_value("PROP_RAW_PACKAGES_BASE_INDEX", cv::cudacodec::VideoReaderProps::PROP_RAW_PACKAGES_BASE_INDEX).
    define_value("PROP_NUMBER_OF_RAW_PACKAGES_SINCE_LAST_GRAB", cv::cudacodec::VideoReaderProps::PROP_NUMBER_OF_RAW_PACKAGES_SINCE_LAST_GRAB).
    define_value("PROP_RAW_MODE", cv::cudacodec::VideoReaderProps::PROP_RAW_MODE).
    define_value("PROP_LRF_HAS_KEY_FRAME", cv::cudacodec::VideoReaderProps::PROP_LRF_HAS_KEY_FRAME).
    define_value("PROP_COLOR_FORMAT", cv::cudacodec::VideoReaderProps::PROP_COLOR_FORMAT).
    define_value("PROP_UDP_SOURCE", cv::cudacodec::VideoReaderProps::PROP_UDP_SOURCE).
    define_value("PROP_ALLOW_FRAME_DROP", cv::cudacodec::VideoReaderProps::PROP_ALLOW_FRAME_DROP).
    define_value("PROP_NOT_SUPPORTED", cv::cudacodec::VideoReaderProps::PROP_NOT_SUPPORTED);
  
  Class rb_cCvCudacodecVideoReader = define_class_under<cv::cudacodec::VideoReader>(rb_mCvCudacodec, "VideoReader").
    define_method<bool(cv::cudacodec::VideoReader::*)(cv::cuda::GpuMat&, cv::cuda::Stream&)>("next_frame", &cv::cudacodec::VideoReader::nextFrame).
    define_method<cv::cudacodec::FormatInfo(cv::cudacodec::VideoReader::*)() const>("format", &cv::cudacodec::VideoReader::format).
    define_method<bool(cv::cudacodec::VideoReader::*)(cv::cuda::Stream&)>("grab", &cv::cudacodec::VideoReader::grab).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::_OutputArray &, const unsigned long long) const>("retrieve", &cv::cudacodec::VideoReader::retrieve).
    define_method<bool(cv::cudacodec::VideoReader::*)(cv::Mat&, const unsigned long long) const>("retrieve", &cv::cudacodec::VideoReader::retrieve).
    define_method<bool(cv::cudacodec::VideoReader::*)(cv::cuda::GpuMat&) const>("retrieve", &cv::cudacodec::VideoReader::retrieve).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::cudacodec::VideoReaderProps, const double)>("set", &cv::cudacodec::VideoReader::set).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::cudacodec::VideoReaderProps, double)>("set_video_reader_props", &cv::cudacodec::VideoReader::setVideoReaderProps).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::cudacodec::ColorFormat)>("set", &cv::cudacodec::VideoReader::set).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::cudacodec::VideoReaderProps, double&) const>("get", &cv::cudacodec::VideoReader::get).
    define_method<bool(cv::cudacodec::VideoReader::*)(const cv::cudacodec::VideoReaderProps, double&, double) const>("get_video_reader_props", &cv::cudacodec::VideoReader::getVideoReaderProps).
    define_method<bool(cv::cudacodec::VideoReader::*)(const int, double&) const>("get", &cv::cudacodec::VideoReader::get);
  
  Class rb_cCvCudacodecRawVideoSource = define_class_under<cv::cudacodec::RawVideoSource>(rb_mCvCudacodec, "RawVideoSource").
    define_method<bool(cv::cudacodec::RawVideoSource::*)(unsigned char**, unsigned long long*)>("get_next_packet", &cv::cudacodec::RawVideoSource::getNextPacket).
    define_method<bool(cv::cudacodec::RawVideoSource::*)() const>("last_packet_contains_key_frame", &cv::cudacodec::RawVideoSource::lastPacketContainsKeyFrame).
    define_method<cv::cudacodec::FormatInfo(cv::cudacodec::RawVideoSource::*)() const>("format", &cv::cudacodec::RawVideoSource::format).
    define_method<void(cv::cudacodec::RawVideoSource::*)(const cv::cudacodec::FormatInfo&)>("update_format", &cv::cudacodec::RawVideoSource::updateFormat).
    define_method<void(cv::cudacodec::RawVideoSource::*)(cv::Mat&) const>("get_extra_data", &cv::cudacodec::RawVideoSource::getExtraData).
    define_method<bool(cv::cudacodec::RawVideoSource::*)(const int, double&) const>("get", &cv::cudacodec::RawVideoSource::get);
  
  Class rb_cCvCudacodecVideoReaderInitParams = define_class_under<cv::cudacodec::VideoReaderInitParams>(rb_mCvCudacodec, "VideoReaderInitParams").
    define_constructor(Constructor<cv::cudacodec::VideoReaderInitParams>()).
    define_attr("udp_source", &cv::cudacodec::VideoReaderInitParams::udpSource).
    define_attr("allow_frame_drop", &cv::cudacodec::VideoReaderInitParams::allowFrameDrop).
    define_attr("min_num_decode_surfaces", &cv::cudacodec::VideoReaderInitParams::minNumDecodeSurfaces).
    define_attr("raw_mode", &cv::cudacodec::VideoReaderInitParams::rawMode).
    define_attr("target_sz", &cv::cudacodec::VideoReaderInitParams::targetSz).
    define_attr("src_roi", &cv::cudacodec::VideoReaderInitParams::srcRoi).
    define_attr("target_roi", &cv::cudacodec::VideoReaderInitParams::targetRoi);
  
  rb_mCvCudacodec.define_module_function<cv::Ptr<cv::cudacodec::VideoReader>(*)(const std::basic_string<char>&, const std::vector<int>&, const cv::cudacodec::VideoReaderInitParams)>("create_video_reader", &cv::cudacodec::createVideoReader);
  
  rb_mCvCudacodec.define_module_function<cv::Ptr<cv::cudacodec::VideoReader>(*)(const cv::Ptr<cv::cudacodec::RawVideoSource>&, const cv::cudacodec::VideoReaderInitParams)>("create_video_reader", &cv::cudacodec::createVideoReader);
}