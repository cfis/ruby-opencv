#include <opencv2/ximgproc/segmentation.hpp>
#include "segmentation-rb.hpp"

using namespace Rice;

extern "C"
void Init_Segmentation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvXimgproc = define_module_under(rb_mCv, "Ximgproc");
  
  Module rb_mCvXimgprocSegmentation = define_module_under(rb_mCvXimgproc, "Segmentation");
  
  Class rb_cCvXimgprocSegmentationGraphSegmentation = define_class_under<cv::ximgproc::segmentation::GraphSegmentation, cv::Algorithm>(rb_mCvXimgprocSegmentation, "GraphSegmentation").
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(const cv::_InputArray &, const cv::_OutputArray &)>("process_image", &cv::ximgproc::segmentation::GraphSegmentation::processImage).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(double)>("set_sigma", &cv::ximgproc::segmentation::GraphSegmentation::setSigma).
    define_method<double(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_sigma", &cv::ximgproc::segmentation::GraphSegmentation::getSigma).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(float)>("set_k", &cv::ximgproc::segmentation::GraphSegmentation::setK).
    define_method<float(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_k", &cv::ximgproc::segmentation::GraphSegmentation::getK).
    define_method<void(cv::ximgproc::segmentation::GraphSegmentation::*)(int)>("set_min_size", &cv::ximgproc::segmentation::GraphSegmentation::setMinSize).
    define_method<int(cv::ximgproc::segmentation::GraphSegmentation::*)()>("get_min_size", &cv::ximgproc::segmentation::GraphSegmentation::getMinSize);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>(*)(double, float, int)>("create_graph_segmentation", &cv::ximgproc::segmentation::createGraphSegmentation);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategy = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy, cv::Algorithm>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategy").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int)>("set_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::setImage).
    define_method<float(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(int, int)>("get", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::get).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::*)(int, int)>("merge", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy::merge);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyColor = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyColor");
  
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyColor>(*)()>("create_selective_search_segmentation_strategy_color", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyColor);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategySize = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategySize");
  
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategySize>(*)()>("create_selective_search_segmentation_strategy_size", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategySize);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyTexture = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyTexture");
  
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyTexture>(*)()>("create_selective_search_segmentation_strategy_texture", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyTexture);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyFill = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyFill");
  
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyFill>(*)()>("create_selective_search_segmentation_strategy_fill", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyFill);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentationStrategyMultiple = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple, cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentationStrategyMultiple").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, float)>("add_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::addStrategy).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::*)()>("clear_strategies", &cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple::clearStrategies);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)()>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategyMultiple>(*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>, cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("create_selective_search_segmentation_strategy_multiple", &cv::ximgproc::segmentation::createSelectiveSearchSegmentationStrategyMultiple);
  
  Class rb_cCvXimgprocSegmentationSelectiveSearchSegmentation = define_class_under<cv::ximgproc::segmentation::SelectiveSearchSegmentation, cv::Algorithm>(rb_mCvXimgprocSegmentation, "SelectiveSearchSegmentation").
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(const cv::_InputArray &)>("set_base_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::setBaseImage).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, float)>("switch_to_single_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSingleStrategy).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, int, float)>("switch_to_selective_search_fast", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSelectiveSearchFast).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(int, int, float)>("switch_to_selective_search_quality", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::switchToSelectiveSearchQuality).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(const cv::_InputArray &)>("add_image", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addImage).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_images", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearImages).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::Ptr<cv::ximgproc::segmentation::GraphSegmentation>)>("add_graph_segmentation", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addGraphSegmentation).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_graph_segmentations", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearGraphSegmentations).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentationStrategy>)>("add_strategy", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::addStrategy).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)()>("clear_strategies", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::clearStrategies).
    define_method<void(cv::ximgproc::segmentation::SelectiveSearchSegmentation::*)(std::vector<cv::Rect_<int>>&)>("process", &cv::ximgproc::segmentation::SelectiveSearchSegmentation::process);
  
  rb_mCvXimgprocSegmentation.define_module_function<cv::Ptr<cv::ximgproc::segmentation::SelectiveSearchSegmentation>(*)()>("create_selective_search_segmentation", &cv::ximgproc::segmentation::createSelectiveSearchSegmentation);
}