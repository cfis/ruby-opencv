#include <opencv2/wechat_qrcode.hpp>
#include "wechat_qrcode-rb.hpp"

using namespace Rice;

extern "C"
void Init_WechatQrcode()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvWechatQrcode = define_module_under(rb_mCv, "WechatQrcode");
  
  Class rb_cCvWechatQrcodeWeChatQRCode = define_class_under<cv::wechat_qrcode::WeChatQRCode>(rb_mCvWechatQrcode, "WeChatQRCode").
    define_constructor(Constructor<cv::wechat_qrcode::WeChatQRCode, const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&>()).
    define_method<std::vector<std::basic_string<char>>(cv::wechat_qrcode::WeChatQRCode::*)(const cv::_InputArray &, const cv::_OutputArray &)>("detect_and_decode", &cv::wechat_qrcode::WeChatQRCode::detectAndDecode).
    define_method<void(cv::wechat_qrcode::WeChatQRCode::*)(float)>("set_scale_factor", &cv::wechat_qrcode::WeChatQRCode::setScaleFactor).
    define_method<float(cv::wechat_qrcode::WeChatQRCode::*)()>("get_scale_factor", &cv::wechat_qrcode::WeChatQRCode::getScaleFactor);
}