#include <opencv2/ccalib/omnidir.hpp>
#include "omnidir-rb.hpp"

using namespace Rice;

extern "C"
void Init_Omnidir()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOmnidir = define_module_under(rb_mCv, "Omnidir");
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, const cv::_InputArray &, const cv::_OutputArray &)>("project_points", &cv::omnidir::projectPoints);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::Affine3<double>&, const cv::_InputArray &, double, const cv::_InputArray &, const cv::_OutputArray &)>("project_points", &cv::omnidir::projectPoints);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("undistort_points", &cv::omnidir::undistortPoints);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, int, const cv::_OutputArray &, const cv::_OutputArray &, int)>("init_undistort_rectify_map", &cv::omnidir::initUndistortRectifyMap);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, const cv::_InputArray &, const cv::Size_<int>&, const cv::_InputArray &)>("undistort_image", &cv::omnidir::undistortImage);
  
  rb_mCvOmnidir.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria, const cv::_OutputArray &)>("calibrate", &cv::omnidir::calibrate);
  
  rb_mCvOmnidir.define_module_function<double(*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::Size_<int>&, const cv::Size_<int>&, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria, const cv::_OutputArray &)>("stereo_calibrate", &cv::omnidir::stereoCalibrate);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("stereo_rectify", &cv::omnidir::stereoRectify);
  
  rb_mCvOmnidir.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, int, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::Size_<int>&, const cv::_InputArray &, const cv::_OutputArray &, int)>("stereo_reconstruct", &cv::omnidir::stereoReconstruct);
  
  Module rb_mCvOmnidirInternal = define_module_under(rb_mCvOmnidir, "Internal");
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double&, const cv::_OutputArray &)>("initialize_calibration", &cv::omnidir::internal::initializeCalibration);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, const cv::Size_<int>&, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double&, double&, int, const cv::_OutputArray &)>("initialize_stereo_calibration", &cv::omnidir::internal::initializeStereoCalibration);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Mat&, cv::Mat&, int, double)>("compute_jacobian", &cv::omnidir::internal::computeJacobian);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Mat&, cv::Mat&, int, double)>("compute_jacobian_stereo", &cv::omnidir::internal::computeJacobianStereo);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, const cv::_OutputArray &)>("encode_parameters", &cv::omnidir::internal::encodeParameters);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, double, const cv::_OutputArray &)>("encode_parameters_stereo", &cv::omnidir::internal::encodeParametersStereo);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double&)>("decode_parameters", &cv::omnidir::internal::decodeParameters);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double&, double&)>("decode_parameters_stereo", &cv::omnidir::internal::decodeParametersStereo);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Mat&, cv::Vec<double, 2>&, double&, int)>("estimate_uncertainties", &cv::omnidir::internal::estimateUncertainties);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Mat&, cv::Vec<double, 2>&, double&, int)>("estimate_uncertainties_stereo", &cv::omnidir::internal::estimateUncertaintiesStereo);
  
  rb_mCvOmnidirInternal.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &)>("compute_mean_repro_err", &cv::omnidir::internal::computeMeanReproErr);
  
  rb_mCvOmnidirInternal.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, const cv::_InputArray &, const cv::_InputArray &)>("compute_mean_repro_err", &cv::omnidir::internal::computeMeanReproErr);
  
  rb_mCvOmnidirInternal.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, double, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("compute_mean_repro_err_stereo", &cv::omnidir::internal::computeMeanReproErrStereo);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::Mat&, cv::Mat&, const std::vector<int>&, const std::vector<int>&)>("sub_matrix", &cv::omnidir::internal::subMatrix);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(int, std::vector<int>&, int)>("flags2idx", &cv::omnidir::internal::flags2idx);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(int, std::vector<int>&, int)>("flags2idx_stereo", &cv::omnidir::internal::flags2idxStereo);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::Mat&, int, int)>("fill_fixed", &cv::omnidir::internal::fillFixed);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(cv::Mat&, int, int)>("fill_fixed_stereo", &cv::omnidir::internal::fillFixedStereo);
  
  rb_mCvOmnidirInternal.define_module_function<double(*)(const cv::Mat&)>("find_median", &cv::omnidir::internal::findMedian);
  
  rb_mCvOmnidirInternal.define_module_function<cv::Vec<double, 3>(*)(const cv::_InputArray &)>("find_median3", &cv::omnidir::internal::findMedian3);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("get_interset", &cv::omnidir::internal::getInterset);
  
  rb_mCvOmnidirInternal.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&, cv::Mat&)>("compose_motion", &cv::omnidir::internal::compose_motion);
}