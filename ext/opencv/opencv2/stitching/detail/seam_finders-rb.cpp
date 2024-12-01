#include <opencv2/stitching/detail/seam_finders.hpp>
#include "seam_finders-rb.hpp"

using namespace Rice;

extern "C"
void Init_SeamFinders()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  Class rb_cCvDetailSeamFinder = define_class_under<cv::detail::SeamFinder>(rb_mCvDetail, "SeamFinder").
    define_method<void(cv::detail::SeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::SeamFinder::find).
    define_singleton_function<cv::Ptr<cv::detail::SeamFinder>(*)(int)>("create_default", &cv::detail::SeamFinder::createDefault);
  
  
  Class rb_cCvDetailNoSeamFinder = define_class_under<cv::detail::NoSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "NoSeamFinder").
    define_method<void(cv::detail::NoSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::NoSeamFinder::find);
  
  Class rb_cCvDetailPairwiseSeamFinder = define_class_under<cv::detail::PairwiseSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "PairwiseSeamFinder").
    define_method<void(cv::detail::PairwiseSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::PairwiseSeamFinder::find);
  
  Class rb_cCvDetailVoronoiSeamFinder = define_class_under<cv::detail::VoronoiSeamFinder, cv::detail::PairwiseSeamFinder>(rb_mCvDetail, "VoronoiSeamFinder").
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find).
    define_method<void(cv::detail::VoronoiSeamFinder::*)(const std::vector<cv::Size_<int>>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::VoronoiSeamFinder::find);
  
  Class rb_cCvDetailDpSeamFinder = define_class_under<cv::detail::DpSeamFinder, cv::detail::SeamFinder>(rb_mCvDetail, "DpSeamFinder").
    define_constructor(Constructor<cv::detail::DpSeamFinder, cv::detail::DpSeamFinder::CostFunction>()).
    define_constructor(Constructor<cv::detail::DpSeamFinder, std::basic_string<char>>()).
    define_method<cv::detail::DpSeamFinder::CostFunction(cv::detail::DpSeamFinder::*)() const>("cost_function", &cv::detail::DpSeamFinder::costFunction).
    define_method<void(cv::detail::DpSeamFinder::*)(cv::detail::DpSeamFinder::CostFunction)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction).
    define_method<void(cv::detail::DpSeamFinder::*)(std::basic_string<char>)>("set_cost_function", &cv::detail::DpSeamFinder::setCostFunction).
    define_method<void(cv::detail::DpSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::DpSeamFinder::find);
  
  Class rb_cCvDetailDpSeamFinderImagePairLess = define_class_under<cv::detail::DpSeamFinder::ImagePairLess>(rb_cCvDetailDpSeamFinder, "ImagePairLess").
    define_constructor(Constructor<cv::detail::DpSeamFinder::ImagePairLess, const std::vector<cv::Mat>&, const std::vector<cv::Point_<int>>&>()).
    define_method<bool(cv::detail::DpSeamFinder::ImagePairLess::*)(const std::pair<unsigned long long, unsigned long long>&, const std::pair<unsigned long long, unsigned long long>&) const>("operator()", &cv::detail::DpSeamFinder::ImagePairLess::operator());
  
  Class rb_cCvDetailDpSeamFinderClosePoints = define_class_under<cv::detail::DpSeamFinder::ClosePoints>(rb_cCvDetailDpSeamFinder, "ClosePoints").
    define_constructor(Constructor<cv::detail::DpSeamFinder::ClosePoints, int>()).
    define_method<bool(cv::detail::DpSeamFinder::ClosePoints::*)(const cv::Point_<int>&, const cv::Point_<int>&) const>("operator()", &cv::detail::DpSeamFinder::ClosePoints::operator());
  
  Enum<cv::detail::DpSeamFinder::CostFunction> rb_cCvDetailDpSeamFinderCostFunction = define_enum<cv::detail::DpSeamFinder::CostFunction>("CostFunction", rb_cCvDetailDpSeamFinder).
    define_value("COLOR", cv::detail::DpSeamFinder::CostFunction::COLOR).
    define_value("COLOR_GRAD", cv::detail::DpSeamFinder::CostFunction::COLOR_GRAD);
  
  Enum<cv::detail::DpSeamFinder::ComponentState> rb_cCvDetailDpSeamFinderComponentState = define_enum<cv::detail::DpSeamFinder::ComponentState>("ComponentState", rb_cCvDetailDpSeamFinder).
    define_value("FIRST", cv::detail::DpSeamFinder::ComponentState::FIRST).
    define_value("SECOND", cv::detail::DpSeamFinder::ComponentState::SECOND).
    define_value("INTERS", cv::detail::DpSeamFinder::ComponentState::INTERS).
    define_value("INTERS_FIRST", cv::detail::DpSeamFinder::ComponentState::INTERS_FIRST).
    define_value("INTERS_SECOND", cv::detail::DpSeamFinder::ComponentState::INTERS_SECOND);
  
  Class rb_cCvDetailGraphCutSeamFinderBase = define_class_under<cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinderBase");
  
  
  Enum<cv::detail::GraphCutSeamFinderBase::CostType> rb_cCvDetailGraphCutSeamFinderBaseCostType = define_enum<cv::detail::GraphCutSeamFinderBase::CostType>("CostType", rb_cCvDetailGraphCutSeamFinderBase).
    define_value("COST_COLOR", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR).
    define_value("COST_COLOR_GRAD", cv::detail::GraphCutSeamFinderBase::CostType::COST_COLOR_GRAD);
  
  Class rb_cCvDetailGraphCutSeamFinder = define_class_under<cv::detail::GraphCutSeamFinder, cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinder").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, int, float, float>()).
    define_constructor(Constructor<cv::detail::GraphCutSeamFinder, std::basic_string<char>, float, float>()).
    define_method<void(cv::detail::GraphCutSeamFinder::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::GraphCutSeamFinder::find);
  
  
  Class rb_cCvDetailGraphCutSeamFinderGpu = define_class_under<cv::detail::GraphCutSeamFinderGpu, cv::detail::GraphCutSeamFinderBase>(rb_mCvDetail, "GraphCutSeamFinderGpu").
    define_constructor(Constructor<cv::detail::GraphCutSeamFinderGpu, int, float, float>()).
    define_method<void(cv::detail::GraphCutSeamFinderGpu::*)(const std::vector<cv::UMat>&, const std::vector<cv::Point_<int>>&, std::vector<cv::UMat>&)>("find", &cv::detail::GraphCutSeamFinderGpu::find).
    define_method<void(cv::detail::GraphCutSeamFinderGpu::*)(unsigned long long, unsigned long long, cv::Rect_<int>)>("find_in_pair", &cv::detail::GraphCutSeamFinderGpu::findInPair);
}