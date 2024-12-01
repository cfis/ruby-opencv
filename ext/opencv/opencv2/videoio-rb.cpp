#include <sstream>
#include <opencv2/videoio.hpp>
#include "videoio-rb.hpp"

using namespace Rice;



void Init_Videoio()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::VideoCaptureAPIs> rb_cCvVideoCaptureAPIs = define_enum_under<cv::VideoCaptureAPIs>("VideoCaptureAPIs", rb_mCv).
    define_value("CAP_ANY", cv::VideoCaptureAPIs::CAP_ANY).
    define_value("CAP_VFW", cv::VideoCaptureAPIs::CAP_VFW).
    define_value("CAP_V4L", cv::VideoCaptureAPIs::CAP_V4L).
    define_value("CAP_V4L2", cv::VideoCaptureAPIs::CAP_V4L2).
    define_value("CAP_FIREWIRE", cv::VideoCaptureAPIs::CAP_FIREWIRE).
    define_value("CAP_FIREWARE", cv::VideoCaptureAPIs::CAP_FIREWARE).
    define_value("CAP_IEEE1394", cv::VideoCaptureAPIs::CAP_IEEE1394).
    define_value("CAP_DC1394", cv::VideoCaptureAPIs::CAP_DC1394).
    define_value("CAP_CMU1394", cv::VideoCaptureAPIs::CAP_CMU1394).
    define_value("CAP_QT", cv::VideoCaptureAPIs::CAP_QT).
    define_value("CAP_UNICAP", cv::VideoCaptureAPIs::CAP_UNICAP).
    define_value("CAP_DSHOW", cv::VideoCaptureAPIs::CAP_DSHOW).
    define_value("CAP_PVAPI", cv::VideoCaptureAPIs::CAP_PVAPI).
    define_value("CAP_OPENNI", cv::VideoCaptureAPIs::CAP_OPENNI).
    define_value("CAP_OPENNI_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI_ASUS).
    define_value("CAP_ANDROID", cv::VideoCaptureAPIs::CAP_ANDROID).
    define_value("CAP_XIAPI", cv::VideoCaptureAPIs::CAP_XIAPI).
    define_value("CAP_AVFOUNDATION", cv::VideoCaptureAPIs::CAP_AVFOUNDATION).
    define_value("CAP_GIGANETIX", cv::VideoCaptureAPIs::CAP_GIGANETIX).
    define_value("CAP_MSMF", cv::VideoCaptureAPIs::CAP_MSMF).
    define_value("CAP_WINRT", cv::VideoCaptureAPIs::CAP_WINRT).
    define_value("CAP_INTELPERC", cv::VideoCaptureAPIs::CAP_INTELPERC).
    define_value("CAP_REALSENSE", cv::VideoCaptureAPIs::CAP_REALSENSE).
    define_value("CAP_OPENNI2", cv::VideoCaptureAPIs::CAP_OPENNI2).
    define_value("CAP_OPENNI2_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI2_ASUS).
    define_value("CAP_OPENNI2_ASTRA", cv::VideoCaptureAPIs::CAP_OPENNI2_ASTRA).
    define_value("CAP_GPHOTO2", cv::VideoCaptureAPIs::CAP_GPHOTO2).
    define_value("CAP_GSTREAMER", cv::VideoCaptureAPIs::CAP_GSTREAMER).
    define_value("CAP_FFMPEG", cv::VideoCaptureAPIs::CAP_FFMPEG).
    define_value("CAP_IMAGES", cv::VideoCaptureAPIs::CAP_IMAGES).
    define_value("CAP_ARAVIS", cv::VideoCaptureAPIs::CAP_ARAVIS).
    define_value("CAP_OPENCV_MJPEG", cv::VideoCaptureAPIs::CAP_OPENCV_MJPEG).
    define_value("CAP_INTEL_MFX", cv::VideoCaptureAPIs::CAP_INTEL_MFX).
    define_value("CAP_XINE", cv::VideoCaptureAPIs::CAP_XINE).
    define_value("CAP_UEYE", cv::VideoCaptureAPIs::CAP_UEYE).
    define_value("CAP_OBSENSOR", cv::VideoCaptureAPIs::CAP_OBSENSOR);
  
  Enum<cv::VideoCaptureProperties> rb_cCvVideoCaptureProperties = define_enum_under<cv::VideoCaptureProperties>("VideoCaptureProperties", rb_mCv).
    define_value("CAP_PROP_POS_MSEC", cv::VideoCaptureProperties::CAP_PROP_POS_MSEC).
    define_value("CAP_PROP_POS_FRAMES", cv::VideoCaptureProperties::CAP_PROP_POS_FRAMES).
    define_value("CAP_PROP_POS_AVI_RATIO", cv::VideoCaptureProperties::CAP_PROP_POS_AVI_RATIO).
    define_value("CAP_PROP_FRAME_WIDTH", cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH).
    define_value("CAP_PROP_FRAME_HEIGHT", cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT).
    define_value("CAP_PROP_FPS", cv::VideoCaptureProperties::CAP_PROP_FPS).
    define_value("CAP_PROP_FOURCC", cv::VideoCaptureProperties::CAP_PROP_FOURCC).
    define_value("CAP_PROP_FRAME_COUNT", cv::VideoCaptureProperties::CAP_PROP_FRAME_COUNT).
    define_value("CAP_PROP_FORMAT", cv::VideoCaptureProperties::CAP_PROP_FORMAT).
    define_value("CAP_PROP_MODE", cv::VideoCaptureProperties::CAP_PROP_MODE).
    define_value("CAP_PROP_BRIGHTNESS", cv::VideoCaptureProperties::CAP_PROP_BRIGHTNESS).
    define_value("CAP_PROP_CONTRAST", cv::VideoCaptureProperties::CAP_PROP_CONTRAST).
    define_value("CAP_PROP_SATURATION", cv::VideoCaptureProperties::CAP_PROP_SATURATION).
    define_value("CAP_PROP_HUE", cv::VideoCaptureProperties::CAP_PROP_HUE).
    define_value("CAP_PROP_GAIN", cv::VideoCaptureProperties::CAP_PROP_GAIN).
    define_value("CAP_PROP_EXPOSURE", cv::VideoCaptureProperties::CAP_PROP_EXPOSURE).
    define_value("CAP_PROP_CONVERT_RGB", cv::VideoCaptureProperties::CAP_PROP_CONVERT_RGB).
    define_value("CAP_PROP_WHITE_BALANCE_BLUE_U", cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_BLUE_U).
    define_value("CAP_PROP_RECTIFICATION", cv::VideoCaptureProperties::CAP_PROP_RECTIFICATION).
    define_value("CAP_PROP_MONOCHROME", cv::VideoCaptureProperties::CAP_PROP_MONOCHROME).
    define_value("CAP_PROP_SHARPNESS", cv::VideoCaptureProperties::CAP_PROP_SHARPNESS).
    define_value("CAP_PROP_AUTO_EXPOSURE", cv::VideoCaptureProperties::CAP_PROP_AUTO_EXPOSURE).
    define_value("CAP_PROP_GAMMA", cv::VideoCaptureProperties::CAP_PROP_GAMMA).
    define_value("CAP_PROP_TEMPERATURE", cv::VideoCaptureProperties::CAP_PROP_TEMPERATURE).
    define_value("CAP_PROP_TRIGGER", cv::VideoCaptureProperties::CAP_PROP_TRIGGER).
    define_value("CAP_PROP_TRIGGER_DELAY", cv::VideoCaptureProperties::CAP_PROP_TRIGGER_DELAY).
    define_value("CAP_PROP_WHITE_BALANCE_RED_V", cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_RED_V).
    define_value("CAP_PROP_ZOOM", cv::VideoCaptureProperties::CAP_PROP_ZOOM).
    define_value("CAP_PROP_FOCUS", cv::VideoCaptureProperties::CAP_PROP_FOCUS).
    define_value("CAP_PROP_GUID", cv::VideoCaptureProperties::CAP_PROP_GUID).
    define_value("CAP_PROP_ISO_SPEED", cv::VideoCaptureProperties::CAP_PROP_ISO_SPEED).
    define_value("CAP_PROP_BACKLIGHT", cv::VideoCaptureProperties::CAP_PROP_BACKLIGHT).
    define_value("CAP_PROP_PAN", cv::VideoCaptureProperties::CAP_PROP_PAN).
    define_value("CAP_PROP_TILT", cv::VideoCaptureProperties::CAP_PROP_TILT).
    define_value("CAP_PROP_ROLL", cv::VideoCaptureProperties::CAP_PROP_ROLL).
    define_value("CAP_PROP_IRIS", cv::VideoCaptureProperties::CAP_PROP_IRIS).
    define_value("CAP_PROP_SETTINGS", cv::VideoCaptureProperties::CAP_PROP_SETTINGS).
    define_value("CAP_PROP_BUFFERSIZE", cv::VideoCaptureProperties::CAP_PROP_BUFFERSIZE).
    define_value("CAP_PROP_AUTOFOCUS", cv::VideoCaptureProperties::CAP_PROP_AUTOFOCUS).
    define_value("CAP_PROP_SAR_NUM", cv::VideoCaptureProperties::CAP_PROP_SAR_NUM).
    define_value("CAP_PROP_SAR_DEN", cv::VideoCaptureProperties::CAP_PROP_SAR_DEN).
    define_value("CAP_PROP_BACKEND", cv::VideoCaptureProperties::CAP_PROP_BACKEND).
    define_value("CAP_PROP_CHANNEL", cv::VideoCaptureProperties::CAP_PROP_CHANNEL).
    define_value("CAP_PROP_AUTO_WB", cv::VideoCaptureProperties::CAP_PROP_AUTO_WB).
    define_value("CAP_PROP_WB_TEMPERATURE", cv::VideoCaptureProperties::CAP_PROP_WB_TEMPERATURE).
    define_value("CAP_PROP_CODEC_PIXEL_FORMAT", cv::VideoCaptureProperties::CAP_PROP_CODEC_PIXEL_FORMAT).
    define_value("CAP_PROP_BITRATE", cv::VideoCaptureProperties::CAP_PROP_BITRATE).
    define_value("CAP_PROP_ORIENTATION_META", cv::VideoCaptureProperties::CAP_PROP_ORIENTATION_META).
    define_value("CAP_PROP_ORIENTATION_AUTO", cv::VideoCaptureProperties::CAP_PROP_ORIENTATION_AUTO).
    define_value("CAP_PROP_HW_ACCELERATION", cv::VideoCaptureProperties::CAP_PROP_HW_ACCELERATION).
    define_value("CAP_PROP_HW_DEVICE", cv::VideoCaptureProperties::CAP_PROP_HW_DEVICE).
    define_value("CAP_PROP_HW_ACCELERATION_USE_OPENCL", cv::VideoCaptureProperties::CAP_PROP_HW_ACCELERATION_USE_OPENCL).
    define_value("CAP_PROP_OPEN_TIMEOUT_MSEC", cv::VideoCaptureProperties::CAP_PROP_OPEN_TIMEOUT_MSEC).
    define_value("CAP_PROP_READ_TIMEOUT_MSEC", cv::VideoCaptureProperties::CAP_PROP_READ_TIMEOUT_MSEC).
    define_value("CAP_PROP_STREAM_OPEN_TIME_USEC", cv::VideoCaptureProperties::CAP_PROP_STREAM_OPEN_TIME_USEC).
    define_value("CAP_PROP_VIDEO_TOTAL_CHANNELS", cv::VideoCaptureProperties::CAP_PROP_VIDEO_TOTAL_CHANNELS).
    define_value("CAP_PROP_VIDEO_STREAM", cv::VideoCaptureProperties::CAP_PROP_VIDEO_STREAM).
    define_value("CAP_PROP_AUDIO_STREAM", cv::VideoCaptureProperties::CAP_PROP_AUDIO_STREAM).
    define_value("CAP_PROP_AUDIO_POS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_POS).
    define_value("CAP_PROP_AUDIO_SHIFT_NSEC", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SHIFT_NSEC).
    define_value("CAP_PROP_AUDIO_DATA_DEPTH", cv::VideoCaptureProperties::CAP_PROP_AUDIO_DATA_DEPTH).
    define_value("CAP_PROP_AUDIO_SAMPLES_PER_SECOND", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SAMPLES_PER_SECOND).
    define_value("CAP_PROP_AUDIO_BASE_INDEX", cv::VideoCaptureProperties::CAP_PROP_AUDIO_BASE_INDEX).
    define_value("CAP_PROP_AUDIO_TOTAL_CHANNELS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_TOTAL_CHANNELS).
    define_value("CAP_PROP_AUDIO_TOTAL_STREAMS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_TOTAL_STREAMS).
    define_value("CAP_PROP_AUDIO_SYNCHRONIZE", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SYNCHRONIZE).
    define_value("CAP_PROP_LRF_HAS_KEY_FRAME", cv::VideoCaptureProperties::CAP_PROP_LRF_HAS_KEY_FRAME).
    define_value("CAP_PROP_CODEC_EXTRADATA_INDEX", cv::VideoCaptureProperties::CAP_PROP_CODEC_EXTRADATA_INDEX).
    define_value("CAP_PROP_FRAME_TYPE", cv::VideoCaptureProperties::CAP_PROP_FRAME_TYPE).
    define_value("CAP_PROP_N_THREADS", cv::VideoCaptureProperties::CAP_PROP_N_THREADS).
    define_value("CV__CAP_PROP_LATEST", cv::VideoCaptureProperties::CV__CAP_PROP_LATEST);
  
  Enum<cv::VideoWriterProperties> rb_cCvVideoWriterProperties = define_enum_under<cv::VideoWriterProperties>("VideoWriterProperties", rb_mCv).
    define_value("VIDEOWRITER_PROP_QUALITY", cv::VideoWriterProperties::VIDEOWRITER_PROP_QUALITY).
    define_value("VIDEOWRITER_PROP_FRAMEBYTES", cv::VideoWriterProperties::VIDEOWRITER_PROP_FRAMEBYTES).
    define_value("VIDEOWRITER_PROP_NSTRIPES", cv::VideoWriterProperties::VIDEOWRITER_PROP_NSTRIPES).
    define_value("VIDEOWRITER_PROP_IS_COLOR", cv::VideoWriterProperties::VIDEOWRITER_PROP_IS_COLOR).
    define_value("VIDEOWRITER_PROP_DEPTH", cv::VideoWriterProperties::VIDEOWRITER_PROP_DEPTH).
    define_value("VIDEOWRITER_PROP_HW_ACCELERATION", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_ACCELERATION).
    define_value("VIDEOWRITER_PROP_HW_DEVICE", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_DEVICE).
    define_value("VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL).
    define_value("VIDEOWRITER_PROP_RAW_VIDEO", cv::VideoWriterProperties::VIDEOWRITER_PROP_RAW_VIDEO).
    define_value("VIDEOWRITER_PROP_KEY_INTERVAL", cv::VideoWriterProperties::VIDEOWRITER_PROP_KEY_INTERVAL).
    define_value("VIDEOWRITER_PROP_KEY_FLAG", cv::VideoWriterProperties::VIDEOWRITER_PROP_KEY_FLAG).
    define_value("CV__VIDEOWRITER_PROP_LATEST", cv::VideoWriterProperties::CV__VIDEOWRITER_PROP_LATEST);
  
  Enum<cv::VideoAccelerationType> rb_cCvVideoAccelerationType = define_enum_under<cv::VideoAccelerationType>("VideoAccelerationType", rb_mCv).
    define_value("VIDEO_ACCELERATION_NONE", cv::VideoAccelerationType::VIDEO_ACCELERATION_NONE).
    define_value("VIDEO_ACCELERATION_ANY", cv::VideoAccelerationType::VIDEO_ACCELERATION_ANY).
    define_value("VIDEO_ACCELERATION_D3D11", cv::VideoAccelerationType::VIDEO_ACCELERATION_D3D11).
    define_value("VIDEO_ACCELERATION_VAAPI", cv::VideoAccelerationType::VIDEO_ACCELERATION_VAAPI).
    define_value("VIDEO_ACCELERATION_MFX", cv::VideoAccelerationType::VIDEO_ACCELERATION_MFX);
  
  Enum<cv::VideoCaptureOBSensorDataType> rb_cCvVideoCaptureOBSensorDataType = define_enum_under<cv::VideoCaptureOBSensorDataType>("VideoCaptureOBSensorDataType", rb_mCv).
    define_value("CAP_OBSENSOR_DEPTH_MAP", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_DEPTH_MAP).
    define_value("CAP_OBSENSOR_BGR_IMAGE", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_BGR_IMAGE).
    define_value("CAP_OBSENSOR_IR_IMAGE", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_IR_IMAGE);
  
  Enum<cv::VideoCaptureOBSensorGenerators> rb_cCvVideoCaptureOBSensorGenerators = define_enum_under<cv::VideoCaptureOBSensorGenerators>("VideoCaptureOBSensorGenerators", rb_mCv).
    define_value("CAP_OBSENSOR_DEPTH_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_DEPTH_GENERATOR).
    define_value("CAP_OBSENSOR_IMAGE_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_IMAGE_GENERATOR).
    define_value("CAP_OBSENSOR_IR_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_IR_GENERATOR).
    define_value("CAP_OBSENSOR_GENERATORS_MASK", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_GENERATORS_MASK);
  
  Enum<cv::VideoCaptureOBSensorProperties> rb_cCvVideoCaptureOBSensorProperties = define_enum_under<cv::VideoCaptureOBSensorProperties>("VideoCaptureOBSensorProperties", rb_mCv).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_FX", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_FX).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_FY", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_FY).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_CX", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_CX).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_CY", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_CY);
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  
  Class rb_cCvVideoCapture = define_class_under<cv::VideoCapture>(rb_mCv, "VideoCapture").
    define_constructor(Constructor<cv::VideoCapture>()).
    define_constructor(Constructor<cv::VideoCapture, const cv::String&, int>(),
      Arg("filename"), Arg("api_preference")).
    define_constructor(Constructor<cv::VideoCapture, const cv::String&, int, const std::vector<int>&>(),
      Arg("filename"), Arg("api_preference"), Arg("params")).
    define_constructor(Constructor<cv::VideoCapture, int, int>(),
      Arg("index"), Arg("api_preference")).
    define_constructor(Constructor<cv::VideoCapture, int, int, const std::vector<int>&>(),
      Arg("index"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)(const cv::String&, int)>("open?", &cv::VideoCapture::open,
      Arg("filename"), Arg("api_preference")).
    define_method<bool(cv::VideoCapture::*)(const cv::String&, int, const std::vector<int>&)>("open?", &cv::VideoCapture::open,
      Arg("filename"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)(int, int)>("open?", &cv::VideoCapture::open,
      Arg("index"), Arg("api_preference")).
    define_method<bool(cv::VideoCapture::*)(int, int, const std::vector<int>&)>("open?", &cv::VideoCapture::open,
      Arg("index"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)() const>("is_opened?", &cv::VideoCapture::isOpened).
    define_method<void(cv::VideoCapture::*)()>("release", &cv::VideoCapture::release).
    define_method<bool(cv::VideoCapture::*)()>("grab?", &cv::VideoCapture::grab).
    define_method<bool(cv::VideoCapture::*)(cv::OutputArray, int)>("retrieve?", &cv::VideoCapture::retrieve,
      Arg("image"), Arg("flag") = 0).
    define_method<cv::VideoCapture&(cv::VideoCapture::*)(cv::Mat&)>(">>", &cv::VideoCapture::operator>>,
      Arg("image")).
    define_method<cv::VideoCapture&(cv::VideoCapture::*)(cv::UMat&)>(">>", &cv::VideoCapture::operator>>,
      Arg("image")).
    define_method<bool(cv::VideoCapture::*)(cv::OutputArray)>("read?", &cv::VideoCapture::read,
      Arg("image")).
    define_method<bool(cv::VideoCapture::*)(int, double)>("set?", &cv::VideoCapture::set,
      Arg("prop_id"), Arg("value")).
    define_method<double(cv::VideoCapture::*)(int) const>("get", &cv::VideoCapture::get,
      Arg("prop_id")).
    define_method<cv::String(cv::VideoCapture::*)() const>("get_backend_name", &cv::VideoCapture::getBackendName).
    define_method<void(cv::VideoCapture::*)(bool)>("set_exception_mode", &cv::VideoCapture::setExceptionMode,
      Arg("enable")).
    define_method<bool(cv::VideoCapture::*)() const>("get_exception_mode?", &cv::VideoCapture::getExceptionMode).
    define_singleton_function<bool(*)(const std::vector<cv::VideoCapture>&, std::vector<int>&, int64)>("wait_any?", &cv::VideoCapture::waitAny,
      Arg("streams"), Arg("ready_index"), Arg("timeout_ns") = 0);
  
  Class rb_cCvVideoWriter = define_class_under<cv::VideoWriter>(rb_mCv, "VideoWriter").
    define_constructor(Constructor<cv::VideoWriter>()).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, double, cv::Size, bool>(),
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color")).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, int, double, cv::Size, bool>(),
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color")).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, double, const cv::Size&, const std::vector<int>&>(),
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, int, double, const cv::Size&, const std::vector<int>&>(),
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, double, cv::Size, bool)>("open?", &cv::VideoWriter::open,
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, int, double, cv::Size, bool)>("open?", &cv::VideoWriter::open,
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, double, const cv::Size&, const std::vector<int>&)>("open?", &cv::VideoWriter::open,
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, int, double, const cv::Size&, const std::vector<int>&)>("open?", &cv::VideoWriter::open,
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)() const>("is_opened?", &cv::VideoWriter::isOpened).
    define_method<void(cv::VideoWriter::*)()>("release", &cv::VideoWriter::release).
    define_method<cv::VideoWriter&(cv::VideoWriter::*)(const cv::Mat&)>("<<", &cv::VideoWriter::operator<<,
      Arg("image")).
    define_method<cv::VideoWriter&(cv::VideoWriter::*)(const cv::UMat&)>("<<", &cv::VideoWriter::operator<<,
      Arg("image")).
    define_method<void(cv::VideoWriter::*)(cv::InputArray)>("write", &cv::VideoWriter::write,
      Arg("image")).
    define_method<bool(cv::VideoWriter::*)(int, double)>("set?", &cv::VideoWriter::set,
      Arg("prop_id"), Arg("value")).
    define_method<double(cv::VideoWriter::*)(int) const>("get", &cv::VideoWriter::get,
      Arg("prop_id")).
    define_singleton_function<int(*)(char, char, char, char)>("fourcc", &cv::VideoWriter::fourcc,
      Arg("c1"), Arg("c2"), Arg("c3"), Arg("c4")).
    define_method<cv::String(cv::VideoWriter::*)() const>("get_backend_name", &cv::VideoWriter::getBackendName);
  
  Class rb_cCvDefaultDeleterCvCapture = define_class_under<cv::DefaultDeleter<CvCapture>>(rb_mCv, "DefaultDeleterCvCapture").
    define_constructor(Constructor<cv::DefaultDeleter<CvCapture>>()).
    define_method<void(cv::DefaultDeleter<CvCapture>::*)(CvCapture*) const>("()", &cv::DefaultDeleter<CvCapture>::operator(),
      Arg("obj"));
  
  Class rb_cCvDefaultDeleterCvVideoWriter = define_class_under<cv::DefaultDeleter<CvVideoWriter>>(rb_mCv, "DefaultDeleterCvVideoWriter").
    define_constructor(Constructor<cv::DefaultDeleter<CvVideoWriter>>()).
    define_method<void(cv::DefaultDeleter<CvVideoWriter>::*)(CvVideoWriter*) const>("()", &cv::DefaultDeleter<CvVideoWriter>::operator(),
      Arg("obj"));

}