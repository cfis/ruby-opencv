#include <opencv2/highgui.hpp>
#include "highgui-rb.hpp"

using namespace Rice;

extern "C"
void Init_Highgui()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::WindowFlags> rb_cCvWindowFlags = define_enum<cv::WindowFlags>("WindowFlags", rb_mCv).
    define_value("WINDOW_NORMAL", cv::WindowFlags::WINDOW_NORMAL).
    define_value("WINDOW_AUTOSIZE", cv::WindowFlags::WINDOW_AUTOSIZE).
    define_value("WINDOW_OPENGL", cv::WindowFlags::WINDOW_OPENGL).
    define_value("WINDOW_FULLSCREEN", cv::WindowFlags::WINDOW_FULLSCREEN).
    define_value("WINDOW_FREERATIO", cv::WindowFlags::WINDOW_FREERATIO).
    define_value("WINDOW_KEEPRATIO", cv::WindowFlags::WINDOW_KEEPRATIO).
    define_value("WINDOW_GUI_EXPANDED", cv::WindowFlags::WINDOW_GUI_EXPANDED).
    define_value("WINDOW_GUI_NORMAL", cv::WindowFlags::WINDOW_GUI_NORMAL);
  
  Enum<cv::WindowPropertyFlags> rb_cCvWindowPropertyFlags = define_enum<cv::WindowPropertyFlags>("WindowPropertyFlags", rb_mCv).
    define_value("WND_PROP_FULLSCREEN", cv::WindowPropertyFlags::WND_PROP_FULLSCREEN).
    define_value("WND_PROP_AUTOSIZE", cv::WindowPropertyFlags::WND_PROP_AUTOSIZE).
    define_value("WND_PROP_ASPECT_RATIO", cv::WindowPropertyFlags::WND_PROP_ASPECT_RATIO).
    define_value("WND_PROP_OPENGL", cv::WindowPropertyFlags::WND_PROP_OPENGL).
    define_value("WND_PROP_VISIBLE", cv::WindowPropertyFlags::WND_PROP_VISIBLE).
    define_value("WND_PROP_TOPMOST", cv::WindowPropertyFlags::WND_PROP_TOPMOST).
    define_value("WND_PROP_VSYNC", cv::WindowPropertyFlags::WND_PROP_VSYNC);
  
  Enum<cv::MouseEventTypes> rb_cCvMouseEventTypes = define_enum<cv::MouseEventTypes>("MouseEventTypes", rb_mCv).
    define_value("EVENT_MOUSEMOVE", cv::MouseEventTypes::EVENT_MOUSEMOVE).
    define_value("EVENT_LBUTTONDOWN", cv::MouseEventTypes::EVENT_LBUTTONDOWN).
    define_value("EVENT_RBUTTONDOWN", cv::MouseEventTypes::EVENT_RBUTTONDOWN).
    define_value("EVENT_MBUTTONDOWN", cv::MouseEventTypes::EVENT_MBUTTONDOWN).
    define_value("EVENT_LBUTTONUP", cv::MouseEventTypes::EVENT_LBUTTONUP).
    define_value("EVENT_RBUTTONUP", cv::MouseEventTypes::EVENT_RBUTTONUP).
    define_value("EVENT_MBUTTONUP", cv::MouseEventTypes::EVENT_MBUTTONUP).
    define_value("EVENT_LBUTTONDBLCLK", cv::MouseEventTypes::EVENT_LBUTTONDBLCLK).
    define_value("EVENT_RBUTTONDBLCLK", cv::MouseEventTypes::EVENT_RBUTTONDBLCLK).
    define_value("EVENT_MBUTTONDBLCLK", cv::MouseEventTypes::EVENT_MBUTTONDBLCLK).
    define_value("EVENT_MOUSEWHEEL", cv::MouseEventTypes::EVENT_MOUSEWHEEL).
    define_value("EVENT_MOUSEHWHEEL", cv::MouseEventTypes::EVENT_MOUSEHWHEEL);
  
  Enum<cv::MouseEventFlags> rb_cCvMouseEventFlags = define_enum<cv::MouseEventFlags>("MouseEventFlags", rb_mCv).
    define_value("EVENT_FLAG_LBUTTON", cv::MouseEventFlags::EVENT_FLAG_LBUTTON).
    define_value("EVENT_FLAG_RBUTTON", cv::MouseEventFlags::EVENT_FLAG_RBUTTON).
    define_value("EVENT_FLAG_MBUTTON", cv::MouseEventFlags::EVENT_FLAG_MBUTTON).
    define_value("EVENT_FLAG_CTRLKEY", cv::MouseEventFlags::EVENT_FLAG_CTRLKEY).
    define_value("EVENT_FLAG_SHIFTKEY", cv::MouseEventFlags::EVENT_FLAG_SHIFTKEY).
    define_value("EVENT_FLAG_ALTKEY", cv::MouseEventFlags::EVENT_FLAG_ALTKEY);
  
  Enum<cv::QtFontWeights> rb_cCvQtFontWeights = define_enum<cv::QtFontWeights>("QtFontWeights", rb_mCv).
    define_value("QT_FONT_LIGHT", cv::QtFontWeights::QT_FONT_LIGHT).
    define_value("QT_FONT_NORMAL", cv::QtFontWeights::QT_FONT_NORMAL).
    define_value("QT_FONT_DEMIBOLD", cv::QtFontWeights::QT_FONT_DEMIBOLD).
    define_value("QT_FONT_BOLD", cv::QtFontWeights::QT_FONT_BOLD).
    define_value("QT_FONT_BLACK", cv::QtFontWeights::QT_FONT_BLACK);
  
  Enum<cv::QtFontStyles> rb_cCvQtFontStyles = define_enum<cv::QtFontStyles>("QtFontStyles", rb_mCv).
    define_value("QT_STYLE_NORMAL", cv::QtFontStyles::QT_STYLE_NORMAL).
    define_value("QT_STYLE_ITALIC", cv::QtFontStyles::QT_STYLE_ITALIC).
    define_value("QT_STYLE_OBLIQUE", cv::QtFontStyles::QT_STYLE_OBLIQUE);
  
  Enum<cv::QtButtonTypes> rb_cCvQtButtonTypes = define_enum<cv::QtButtonTypes>("QtButtonTypes", rb_mCv).
    define_value("QT_PUSH_BUTTON", cv::QtButtonTypes::QT_PUSH_BUTTON).
    define_value("QT_CHECKBOX", cv::QtButtonTypes::QT_CHECKBOX).
    define_value("QT_RADIOBOX", cv::QtButtonTypes::QT_RADIOBOX).
    define_value("QT_NEW_BUTTONBAR", cv::QtButtonTypes::QT_NEW_BUTTONBAR);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, int)>("named_window", &cv::namedWindow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&)>("destroy_window", &cv::destroyWindow);
  
  rb_mCv.define_module_function<void(*)()>("destroy_all_windows", &cv::destroyAllWindows);
  
  rb_mCv.define_module_function<int(*)()>("start_window_thread", &cv::startWindowThread);
  
  rb_mCv.define_module_function<int(*)(int)>("wait_key_ex", &cv::waitKeyEx);
  
  rb_mCv.define_module_function<int(*)(int)>("wait_key", &cv::waitKey);
  
  rb_mCv.define_module_function<int(*)()>("poll_key", &cv::pollKey);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const cv::_InputArray &)>("imshow", &cv::imshow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, int, int)>("resize_window", &cv::resizeWindow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const cv::Size_<int>&)>("resize_window", &cv::resizeWindow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, int, int)>("move_window", &cv::moveWindow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, int, double)>("set_window_property", &cv::setWindowProperty);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("set_window_title", &cv::setWindowTitle);
  
  rb_mCv.define_module_function<double(*)(const std::basic_string<char>&, int)>("get_window_property", &cv::getWindowProperty);
  
  rb_mCv.define_module_function<cv::Rect_<int>(*)(const std::basic_string<char>&)>("get_window_image_rect", &cv::getWindowImageRect);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, void (*)(int, int, int, int, void *), void*)>("set_mouse_callback", &cv::setMouseCallback);
  
  rb_mCv.define_module_function<int(*)(int)>("get_mouse_wheel_delta", &cv::getMouseWheelDelta);
  
  rb_mCv.define_module_function<cv::Rect_<int>(*)(const std::basic_string<char>&, const cv::_InputArray &, bool, bool, bool)>("select_roi", &cv::selectROI);
  
  rb_mCv.define_module_function<cv::Rect_<int>(*)(const cv::_InputArray &, bool, bool, bool)>("select_roi", &cv::selectROI);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const cv::_InputArray &, std::vector<cv::Rect_<int>>&, bool, bool, bool)>("select_ro_is", &cv::selectROIs);
  
  rb_mCv.define_module_function<int(*)(const std::basic_string<char>&, const std::basic_string<char>&, int*, int, void (*)(int, void *), void*)>("create_trackbar", &cv::createTrackbar);
  
  rb_mCv.define_module_function<int(*)(const std::basic_string<char>&, const std::basic_string<char>&)>("get_trackbar_pos", &cv::getTrackbarPos);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, int)>("set_trackbar_pos", &cv::setTrackbarPos);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, int)>("set_trackbar_max", &cv::setTrackbarMax);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, int)>("set_trackbar_min", &cv::setTrackbarMin);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const cv::ogl::Texture2D&)>("imshow", &cv::imshow);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, void (*)(void *), void*)>("set_open_gl_draw_callback", &cv::setOpenGlDrawCallback);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&)>("set_open_gl_context", &cv::setOpenGlContext);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&)>("update_window", &cv::updateWindow);
  
  Class rb_cCvQtFont = define_class_under<cv::QtFont>(rb_mCv, "QtFont").
    define_attr("name_font", &cv::QtFont::nameFont).
    define_attr("color", &cv::QtFont::color).
    define_attr("font_face", &cv::QtFont::font_face).
    define_attr("ascii", &cv::QtFont::ascii).
    define_attr("greek", &cv::QtFont::greek).
    define_attr("cyrillic", &cv::QtFont::cyrillic).
    define_attr("hscale", &cv::QtFont::hscale).
    define_attr("vscale", &cv::QtFont::vscale).
    define_attr("shear", &cv::QtFont::shear).
    define_attr("thickness", &cv::QtFont::thickness).
    define_attr("dx", &cv::QtFont::dx).
    define_attr("line_type", &cv::QtFont::line_type);
  
  rb_mCv.define_module_function<cv::QtFont(*)(const std::basic_string<char>&, int, cv::Scalar_<double>, int, int, int)>("font_qt", &cv::fontQt);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const std::basic_string<char>&, cv::Point_<int>, const cv::QtFont&)>("add_text", &cv::addText);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat&, const std::basic_string<char>&, cv::Point_<int>, const std::basic_string<char>&, int, cv::Scalar_<double>, int, int, int)>("add_text", &cv::addText);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, int)>("display_overlay", &cv::displayOverlay);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&, const std::basic_string<char>&, int)>("display_status_bar", &cv::displayStatusBar);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&)>("save_window_parameters", &cv::saveWindowParameters);
  
  rb_mCv.define_module_function<void(*)(const std::basic_string<char>&)>("load_window_parameters", &cv::loadWindowParameters);
  
  rb_mCv.define_module_function<int(*)(int (int, char **)*, int, char *[])>("start_loop", &cv::startLoop);
  
  rb_mCv.define_module_function<void(*)()>("stop_loop", &cv::stopLoop);
  
  rb_mCv.define_module_function<int(*)(const std::basic_string<char>&, void (*)(int, void *), void*, int, bool)>("create_button", &cv::createButton);
}