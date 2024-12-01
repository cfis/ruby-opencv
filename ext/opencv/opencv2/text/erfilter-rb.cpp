#include <opencv2/text/erfilter.hpp>
#include "erfilter-rb.hpp"

using namespace Rice;

extern "C"
void Init_Erfilter()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvText = define_module_under(rb_mCv, "Text");
  
  Class rb_cCvTextERStat = define_class_under<cv::text::ERStat>(rb_mCvText, "ERStat").
    define_constructor(Constructor<cv::text::ERStat, int, int, int, int>()).
    define_attr("pixel", &cv::text::ERStat::pixel).
    define_attr("level", &cv::text::ERStat::level).
    define_attr("area", &cv::text::ERStat::area).
    define_attr("perimeter", &cv::text::ERStat::perimeter).
    define_attr("euler", &cv::text::ERStat::euler).
    define_attr("rect", &cv::text::ERStat::rect).
    define_attr("raw_moments", &cv::text::ERStat::raw_moments).
    define_attr("central_moments", &cv::text::ERStat::central_moments).
    define_attr("crossings", &cv::text::ERStat::crossings).
    define_attr("med_crossings", &cv::text::ERStat::med_crossings).
    define_attr("hole_area_ratio", &cv::text::ERStat::hole_area_ratio).
    define_attr("convex_hull_ratio", &cv::text::ERStat::convex_hull_ratio).
    define_attr("num_inflexion_points", &cv::text::ERStat::num_inflexion_points).
    define_attr("pixels", &cv::text::ERStat::pixels).
    define_attr("probability", &cv::text::ERStat::probability).
    define_attr("parent", &cv::text::ERStat::parent).
    define_attr("child", &cv::text::ERStat::child).
    define_attr("next", &cv::text::ERStat::next).
    define_attr("prev", &cv::text::ERStat::prev).
    define_attr("local_maxima", &cv::text::ERStat::local_maxima).
    define_attr("max_probability_ancestor", &cv::text::ERStat::max_probability_ancestor).
    define_attr("min_probability_ancestor", &cv::text::ERStat::min_probability_ancestor);
  
  Class rb_cCvTextERFilter = define_class_under<cv::text::ERFilter, cv::Algorithm>(rb_mCvText, "ERFilter").
    define_method<void(cv::text::ERFilter::*)(const cv::_InputArray &, std::vector<cv::text::ERStat>&)>("run", &cv::text::ERFilter::run).
    define_method<void(cv::text::ERFilter::*)(const cv::Ptr<cv::text::ERFilter::Callback>&)>("set_callback", &cv::text::ERFilter::setCallback).
    define_method<void(cv::text::ERFilter::*)(int)>("set_threshold_delta", &cv::text::ERFilter::setThresholdDelta).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_area", &cv::text::ERFilter::setMinArea).
    define_method<void(cv::text::ERFilter::*)(float)>("set_max_area", &cv::text::ERFilter::setMaxArea).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_probability", &cv::text::ERFilter::setMinProbability).
    define_method<void(cv::text::ERFilter::*)(float)>("set_min_probability_diff", &cv::text::ERFilter::setMinProbabilityDiff).
    define_method<void(cv::text::ERFilter::*)(bool)>("set_non_max_suppression", &cv::text::ERFilter::setNonMaxSuppression).
    define_method<int(cv::text::ERFilter::*)() const>("get_num_rejected", &cv::text::ERFilter::getNumRejected);
  
  Class rb_cCvTextERFilterCallback = define_class_under<cv::text::ERFilter::Callback>(rb_cCvTextERFilter, "Callback").
    define_method<double(cv::text::ERFilter::Callback::*)(const cv::text::ERStat&)>("eval", &cv::text::ERFilter::Callback::eval);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::Ptr<cv::text::ERFilter::Callback>&, int, float, float, float, bool, float)>("create_er_filter_nm1", &cv::text::createERFilterNM1);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const cv::Ptr<cv::text::ERFilter::Callback>&, float)>("create_er_filter_nm2", &cv::text::createERFilterNM2);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const std::basic_string<char>&, int, float, float, float, bool, float)>("create_er_filter_nm1", &cv::text::createERFilterNM1);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter>(*)(const std::basic_string<char>&, float)>("create_er_filter_nm2", &cv::text::createERFilterNM2);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter::Callback>(*)(const std::basic_string<char>&)>("load_classifier_nm1", &cv::text::loadClassifierNM1);
  
  rb_mCvText.define_module_function<cv::Ptr<cv::text::ERFilter::Callback>(*)(const std::basic_string<char>&)>("load_classifier_nm2", &cv::text::loadClassifierNM2);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("compute_nm_channels", &cv::text::computeNMChannels);
  
  Enum<cv::text::erGrouping_Modes> rb_cCvTextErGroupingModes = define_enum<cv::text::erGrouping_Modes>("ErGroupingModes", rb_mCvText).
    define_value("ERGROUPING_ORIENTATION_HORIZ", cv::text::erGrouping_Modes::ERGROUPING_ORIENTATION_HORIZ).
    define_value("ERGROUPING_ORIENTATION_ANY", cv::text::erGrouping_Modes::ERGROUPING_ORIENTATION_ANY);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::text::ERStat>>&, std::vector<std::vector<cv::Vec<int, 2>>>&, std::vector<cv::Rect_<int>>&, int, const std::basic_string<char>&, float)>("er_grouping", &cv::text::erGrouping);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, std::vector<std::vector<cv::Point_<int>>>, std::vector<cv::Rect_<int>>&, int, const std::basic_string<char>&, float)>("er_grouping", &cv::text::erGrouping);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, std::vector<std::vector<cv::Point_<int>>>&, std::vector<std::vector<cv::text::ERStat>>&)>("mse_rs_to_er_stats", &cv::text::MSERsToERStats);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, const cv::Ptr<cv::text::ERFilter>&, const cv::Ptr<cv::text::ERFilter>&, std::vector<std::vector<cv::Point_<int>>>&)>("detect_regions", &cv::text::detectRegions);
  
  rb_mCvText.define_module_function<void(*)(const cv::_InputArray &, const cv::Ptr<cv::text::ERFilter>&, const cv::Ptr<cv::text::ERFilter>&, std::vector<cv::Rect_<int>>&, int, const std::basic_string<char>&, float)>("detect_regions", &cv::text::detectRegions);
}