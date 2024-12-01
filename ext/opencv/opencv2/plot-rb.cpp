#include <opencv2/plot.hpp>
#include "plot-rb.hpp"

using namespace Rice;

extern "C"
void Init_Plot()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvPlot = define_module_under(rb_mCv, "Plot");
  
  Class rb_cCvPlotPlot2d = define_class_under<cv::plot::Plot2d, cv::Algorithm>(rb_mCvPlot, "Plot2d").
    define_method<void(cv::plot::Plot2d::*)(double)>("set_min_x", &cv::plot::Plot2d::setMinX).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_min_y", &cv::plot::Plot2d::setMinY).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_max_x", &cv::plot::Plot2d::setMaxX).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_max_y", &cv::plot::Plot2d::setMaxY).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_plot_line_width", &cv::plot::Plot2d::setPlotLineWidth).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_need_plot_line", &cv::plot::Plot2d::setNeedPlotLine).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar_<double>)>("set_plot_line_color", &cv::plot::Plot2d::setPlotLineColor).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar_<double>)>("set_plot_background_color", &cv::plot::Plot2d::setPlotBackgroundColor).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar_<double>)>("set_plot_axis_color", &cv::plot::Plot2d::setPlotAxisColor).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar_<double>)>("set_plot_grid_color", &cv::plot::Plot2d::setPlotGridColor).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar_<double>)>("set_plot_text_color", &cv::plot::Plot2d::setPlotTextColor).
    define_method<void(cv::plot::Plot2d::*)(int, int)>("set_plot_size", &cv::plot::Plot2d::setPlotSize).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_show_grid", &cv::plot::Plot2d::setShowGrid).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_show_text", &cv::plot::Plot2d::setShowText).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_grid_lines_number", &cv::plot::Plot2d::setGridLinesNumber).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_invert_orientation", &cv::plot::Plot2d::setInvertOrientation).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_point_idx_to_print", &cv::plot::Plot2d::setPointIdxToPrint).
    define_method<void(cv::plot::Plot2d::*)(const cv::_OutputArray &)>("render", &cv::plot::Plot2d::render).
    define_singleton_function<cv::Ptr<cv::plot::Plot2d>(*)(const cv::_InputArray &)>("create", &cv::plot::Plot2d::create).
    define_singleton_function<cv::Ptr<cv::plot::Plot2d>(*)(const cv::_InputArray &, const cv::_InputArray &)>("create", &cv::plot::Plot2d::create);
}