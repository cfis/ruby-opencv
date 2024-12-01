#include <opencv2/cudaimgproc.hpp>
#include "cudaimgproc-rb.hpp"

using namespace Rice;

extern "C"
void Init_Cudaimgproc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, cv::cuda::Stream&)>("cvt_color", &cv::cuda::cvtColor);
  
  Enum<cv::cuda::DemosaicTypes> rb_cCvCudaDemosaicTypes = define_enum<cv::cuda::DemosaicTypes>("DemosaicTypes", rb_mCvCuda).
    define_value("COLOR_BayerBG2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2BGR_MHT).
    define_value("COLOR_BayerGB2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2BGR_MHT).
    define_value("COLOR_BayerRG2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2BGR_MHT).
    define_value("COLOR_BayerGR2BGR_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2BGR_MHT).
    define_value("COLOR_BayerBG2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2RGB_MHT).
    define_value("COLOR_BayerGB2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2RGB_MHT).
    define_value("COLOR_BayerRG2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2RGB_MHT).
    define_value("COLOR_BayerGR2RGB_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2RGB_MHT).
    define_value("COLOR_BayerBG2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerBG2GRAY_MHT).
    define_value("COLOR_BayerGB2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGB2GRAY_MHT).
    define_value("COLOR_BayerRG2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerRG2GRAY_MHT).
    define_value("COLOR_BayerGR2GRAY_MHT", cv::cuda::DemosaicTypes::COLOR_BayerGR2GRAY_MHT);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, cv::cuda::Stream&)>("demosaicing", &cv::cuda::demosaicing);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputOutputArray &, const int[4], cv::cuda::Stream&)>("swap_channels", &cv::cuda::swapChannels);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, bool, cv::cuda::Stream&)>("gamma_correction", &cv::cuda::gammaCorrection);
  
  Enum<cv::cuda::AlphaCompTypes> rb_cCvCudaAlphaCompTypes = define_enum<cv::cuda::AlphaCompTypes>("AlphaCompTypes", rb_mCvCuda).
    define_value("ALPHA_OVER", cv::cuda::AlphaCompTypes::ALPHA_OVER).
    define_value("ALPHA_IN", cv::cuda::AlphaCompTypes::ALPHA_IN).
    define_value("ALPHA_OUT", cv::cuda::AlphaCompTypes::ALPHA_OUT).
    define_value("ALPHA_ATOP", cv::cuda::AlphaCompTypes::ALPHA_ATOP).
    define_value("ALPHA_XOR", cv::cuda::AlphaCompTypes::ALPHA_XOR).
    define_value("ALPHA_PLUS", cv::cuda::AlphaCompTypes::ALPHA_PLUS).
    define_value("ALPHA_OVER_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_OVER_PREMUL).
    define_value("ALPHA_IN_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_IN_PREMUL).
    define_value("ALPHA_OUT_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_OUT_PREMUL).
    define_value("ALPHA_ATOP_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_ATOP_PREMUL).
    define_value("ALPHA_XOR_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_XOR_PREMUL).
    define_value("ALPHA_PLUS_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_PLUS_PREMUL).
    define_value("ALPHA_PREMUL", cv::cuda::AlphaCompTypes::ALPHA_PREMUL);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, cv::cuda::Stream&)>("alpha_comp", &cv::cuda::alphaComp);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("calc_hist", &cv::cuda::calcHist);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("calc_hist", &cv::cuda::calcHist);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("equalize_hist", &cv::cuda::equalizeHist);
  
  Class rb_cCvCudaCLAHE = define_class_under<cv::cuda::CLAHE, cv::CLAHE>(rb_mCvCuda, "CLAHE").
    define_method<void(cv::cuda::CLAHE::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("apply", &cv::cuda::CLAHE::apply);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CLAHE>(*)(double, cv::Size_<int>)>("create_clahe", &cv::cuda::createCLAHE);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_OutputArray &, int, int, int, cv::cuda::Stream&)>("even_levels", &cv::cuda::evenLevels);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, cv::cuda::Stream&)>("hist_even", &cv::cuda::histEven);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, GpuMat[4], int[4], int[4], int[4], cv::cuda::Stream&)>("hist_even", &cv::cuda::histEven);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("hist_range", &cv::cuda::histRange);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, GpuMat[4], const GpuMat[4], cv::cuda::Stream&)>("hist_range", &cv::cuda::histRange);
  
  Class rb_cCvCudaCannyEdgeDetector = define_class_under<cv::cuda::CannyEdgeDetector, cv::Algorithm>(rb_mCvCuda, "CannyEdgeDetector").
    define_method<void(cv::cuda::CannyEdgeDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::CannyEdgeDetector::detect).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::CannyEdgeDetector::detect).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(double)>("set_low_threshold", &cv::cuda::CannyEdgeDetector::setLowThreshold).
    define_method<double(cv::cuda::CannyEdgeDetector::*)() const>("get_low_threshold", &cv::cuda::CannyEdgeDetector::getLowThreshold).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(double)>("set_high_threshold", &cv::cuda::CannyEdgeDetector::setHighThreshold).
    define_method<double(cv::cuda::CannyEdgeDetector::*)() const>("get_high_threshold", &cv::cuda::CannyEdgeDetector::getHighThreshold).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(int)>("set_apperture_size", &cv::cuda::CannyEdgeDetector::setAppertureSize).
    define_method<int(cv::cuda::CannyEdgeDetector::*)() const>("get_apperture_size", &cv::cuda::CannyEdgeDetector::getAppertureSize).
    define_method<void(cv::cuda::CannyEdgeDetector::*)(bool)>("set_l2_gradient", &cv::cuda::CannyEdgeDetector::setL2Gradient).
    define_method<bool(cv::cuda::CannyEdgeDetector::*)() const>("get_l2_gradient", &cv::cuda::CannyEdgeDetector::getL2Gradient);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CannyEdgeDetector>(*)(double, double, int, bool)>("create_canny_edge_detector", &cv::cuda::createCannyEdgeDetector);
  
  Class rb_cCvCudaHoughLinesDetector = define_class_under<cv::cuda::HoughLinesDetector, cv::Algorithm>(rb_mCvCuda, "HoughLinesDetector").
    define_method<void(cv::cuda::HoughLinesDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::HoughLinesDetector::detect).
    define_method<void(cv::cuda::HoughLinesDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("download_results", &cv::cuda::HoughLinesDetector::downloadResults).
    define_method<void(cv::cuda::HoughLinesDetector::*)(float)>("set_rho", &cv::cuda::HoughLinesDetector::setRho).
    define_method<float(cv::cuda::HoughLinesDetector::*)() const>("get_rho", &cv::cuda::HoughLinesDetector::getRho).
    define_method<void(cv::cuda::HoughLinesDetector::*)(float)>("set_theta", &cv::cuda::HoughLinesDetector::setTheta).
    define_method<float(cv::cuda::HoughLinesDetector::*)() const>("get_theta", &cv::cuda::HoughLinesDetector::getTheta).
    define_method<void(cv::cuda::HoughLinesDetector::*)(int)>("set_threshold", &cv::cuda::HoughLinesDetector::setThreshold).
    define_method<int(cv::cuda::HoughLinesDetector::*)() const>("get_threshold", &cv::cuda::HoughLinesDetector::getThreshold).
    define_method<void(cv::cuda::HoughLinesDetector::*)(bool)>("set_do_sort", &cv::cuda::HoughLinesDetector::setDoSort).
    define_method<bool(cv::cuda::HoughLinesDetector::*)() const>("get_do_sort", &cv::cuda::HoughLinesDetector::getDoSort).
    define_method<void(cv::cuda::HoughLinesDetector::*)(int)>("set_max_lines", &cv::cuda::HoughLinesDetector::setMaxLines).
    define_method<int(cv::cuda::HoughLinesDetector::*)() const>("get_max_lines", &cv::cuda::HoughLinesDetector::getMaxLines);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughLinesDetector>(*)(float, float, int, bool, int)>("create_hough_lines_detector", &cv::cuda::createHoughLinesDetector);
  
  Class rb_cCvCudaHoughSegmentDetector = define_class_under<cv::cuda::HoughSegmentDetector, cv::Algorithm>(rb_mCvCuda, "HoughSegmentDetector").
    define_method<void(cv::cuda::HoughSegmentDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::HoughSegmentDetector::detect).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(float)>("set_rho", &cv::cuda::HoughSegmentDetector::setRho).
    define_method<float(cv::cuda::HoughSegmentDetector::*)() const>("get_rho", &cv::cuda::HoughSegmentDetector::getRho).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(float)>("set_theta", &cv::cuda::HoughSegmentDetector::setTheta).
    define_method<float(cv::cuda::HoughSegmentDetector::*)() const>("get_theta", &cv::cuda::HoughSegmentDetector::getTheta).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_min_line_length", &cv::cuda::HoughSegmentDetector::setMinLineLength).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_min_line_length", &cv::cuda::HoughSegmentDetector::getMinLineLength).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_max_line_gap", &cv::cuda::HoughSegmentDetector::setMaxLineGap).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_max_line_gap", &cv::cuda::HoughSegmentDetector::getMaxLineGap).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_max_lines", &cv::cuda::HoughSegmentDetector::setMaxLines).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_max_lines", &cv::cuda::HoughSegmentDetector::getMaxLines).
    define_method<void(cv::cuda::HoughSegmentDetector::*)(int)>("set_threshold", &cv::cuda::HoughSegmentDetector::setThreshold).
    define_method<int(cv::cuda::HoughSegmentDetector::*)() const>("get_threshold", &cv::cuda::HoughSegmentDetector::getThreshold);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughSegmentDetector>(*)(float, float, int, int, int, int)>("create_hough_segment_detector", &cv::cuda::createHoughSegmentDetector);
  
  Class rb_cCvCudaHoughCirclesDetector = define_class_under<cv::cuda::HoughCirclesDetector, cv::Algorithm>(rb_mCvCuda, "HoughCirclesDetector").
    define_method<void(cv::cuda::HoughCirclesDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::HoughCirclesDetector::detect).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(float)>("set_dp", &cv::cuda::HoughCirclesDetector::setDp).
    define_method<float(cv::cuda::HoughCirclesDetector::*)() const>("get_dp", &cv::cuda::HoughCirclesDetector::getDp).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(float)>("set_min_dist", &cv::cuda::HoughCirclesDetector::setMinDist).
    define_method<float(cv::cuda::HoughCirclesDetector::*)() const>("get_min_dist", &cv::cuda::HoughCirclesDetector::getMinDist).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_canny_threshold", &cv::cuda::HoughCirclesDetector::setCannyThreshold).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_canny_threshold", &cv::cuda::HoughCirclesDetector::getCannyThreshold).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_votes_threshold", &cv::cuda::HoughCirclesDetector::setVotesThreshold).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_votes_threshold", &cv::cuda::HoughCirclesDetector::getVotesThreshold).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_min_radius", &cv::cuda::HoughCirclesDetector::setMinRadius).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_min_radius", &cv::cuda::HoughCirclesDetector::getMinRadius).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_max_radius", &cv::cuda::HoughCirclesDetector::setMaxRadius).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_max_radius", &cv::cuda::HoughCirclesDetector::getMaxRadius).
    define_method<void(cv::cuda::HoughCirclesDetector::*)(int)>("set_max_circles", &cv::cuda::HoughCirclesDetector::setMaxCircles).
    define_method<int(cv::cuda::HoughCirclesDetector::*)() const>("get_max_circles", &cv::cuda::HoughCirclesDetector::getMaxCircles);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::HoughCirclesDetector>(*)(float, float, int, int, int, int, int)>("create_hough_circles_detector", &cv::cuda::createHoughCirclesDetector);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::GeneralizedHoughBallard>(*)()>("create_generalized_hough_ballard", &cv::cuda::createGeneralizedHoughBallard);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::GeneralizedHoughGuil>(*)()>("create_generalized_hough_guil", &cv::cuda::createGeneralizedHoughGuil);
  
  Class rb_cCvCudaCornernessCriteria = define_class_under<cv::cuda::CornernessCriteria, cv::Algorithm>(rb_mCvCuda, "CornernessCriteria").
    define_method<void(cv::cuda::CornernessCriteria::*)(const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("compute", &cv::cuda::CornernessCriteria::compute);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornernessCriteria>(*)(int, int, int, double, int)>("create_harris_corner", &cv::cuda::createHarrisCorner);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornernessCriteria>(*)(int, int, int, int)>("create_min_eigen_val_corner", &cv::cuda::createMinEigenValCorner);
  
  Class rb_cCvCudaCornersDetector = define_class_under<cv::cuda::CornersDetector, cv::Algorithm>(rb_mCvCuda, "CornersDetector").
    define_method<void(cv::cuda::CornersDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::cuda::Stream&)>("detect", &cv::cuda::CornersDetector::detect);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::CornersDetector>(*)(int, int, double, double, int, bool, double)>("create_good_features_to_track_detector", &cv::cuda::createGoodFeaturesToTrackDetector);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_filtering", &cv::cuda::meanShiftFiltering);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_proc", &cv::cuda::meanShiftProc);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, cv::TermCriteria, cv::cuda::Stream&)>("mean_shift_segmentation", &cv::cuda::meanShiftSegmentation);
  
  Class rb_cCvCudaTemplateMatching = define_class_under<cv::cuda::TemplateMatching, cv::Algorithm>(rb_mCvCuda, "TemplateMatching").
    define_method<void(cv::cuda::TemplateMatching::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("match", &cv::cuda::TemplateMatching::match);
  
  rb_mCvCuda.define_module_function<cv::Ptr<cv::cuda::TemplateMatching>(*)(int, int, cv::Size_<int>)>("create_template_matching", &cv::cuda::createTemplateMatching);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, float, float, int, cv::cuda::Stream&)>("bilateral_filter", &cv::cuda::bilateralFilter);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, cv::cuda::Stream&)>("blend_linear", &cv::cuda::blendLinear);
  
  Enum<cv::cuda::ConnectedComponentsAlgorithmsTypes> rb_cCvCudaConnectedComponentsAlgorithmsTypes = define_enum<cv::cuda::ConnectedComponentsAlgorithmsTypes>("ConnectedComponentsAlgorithmsTypes", rb_mCvCuda).
    define_value("CCL_DEFAULT", cv::cuda::ConnectedComponentsAlgorithmsTypes::CCL_DEFAULT).
    define_value("CCL_BKE", cv::cuda::ConnectedComponentsAlgorithmsTypes::CCL_BKE);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, cv::cuda::ConnectedComponentsAlgorithmsTypes)>("connected_components", &cv::cuda::connectedComponents);
  
  rb_mCvCuda.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("connected_components", &cv::cuda::connectedComponents);
}