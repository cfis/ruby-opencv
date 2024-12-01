#include <opencv2/calib3d.hpp>
#include "calib3d-rb.hpp"

using namespace Rice;

extern "C"
void Init_Calib3d()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::SolvePnPMethod> rb_cCvSolvePnPMethod = define_enum<cv::SolvePnPMethod>("SolvePnPMethod", rb_mCv).
    define_value("SOLVEPNP_ITERATIVE", cv::SolvePnPMethod::SOLVEPNP_ITERATIVE).
    define_value("SOLVEPNP_EPNP", cv::SolvePnPMethod::SOLVEPNP_EPNP).
    define_value("SOLVEPNP_P3P", cv::SolvePnPMethod::SOLVEPNP_P3P).
    define_value("SOLVEPNP_DLS", cv::SolvePnPMethod::SOLVEPNP_DLS).
    define_value("SOLVEPNP_UPNP", cv::SolvePnPMethod::SOLVEPNP_UPNP).
    define_value("SOLVEPNP_AP3P", cv::SolvePnPMethod::SOLVEPNP_AP3P).
    define_value("SOLVEPNP_IPPE", cv::SolvePnPMethod::SOLVEPNP_IPPE).
    define_value("SOLVEPNP_IPPE_SQUARE", cv::SolvePnPMethod::SOLVEPNP_IPPE_SQUARE).
    define_value("SOLVEPNP_SQPNP", cv::SolvePnPMethod::SOLVEPNP_SQPNP).
    define_value("SOLVEPNP_MAX_COUNT", cv::SolvePnPMethod::SOLVEPNP_MAX_COUNT);
  
  Enum<cv::HandEyeCalibrationMethod> rb_cCvHandEyeCalibrationMethod = define_enum<cv::HandEyeCalibrationMethod>("HandEyeCalibrationMethod", rb_mCv).
    define_value("CALIB_HAND_EYE_TSAI", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_TSAI).
    define_value("CALIB_HAND_EYE_PARK", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_PARK).
    define_value("CALIB_HAND_EYE_HORAUD", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_HORAUD).
    define_value("CALIB_HAND_EYE_ANDREFF", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_ANDREFF).
    define_value("CALIB_HAND_EYE_DANIILIDIS", cv::HandEyeCalibrationMethod::CALIB_HAND_EYE_DANIILIDIS);
  
  Enum<cv::RobotWorldHandEyeCalibrationMethod> rb_cCvRobotWorldHandEyeCalibrationMethod = define_enum<cv::RobotWorldHandEyeCalibrationMethod>("RobotWorldHandEyeCalibrationMethod", rb_mCv).
    define_value("CALIB_ROBOT_WORLD_HAND_EYE_SHAH", cv::RobotWorldHandEyeCalibrationMethod::CALIB_ROBOT_WORLD_HAND_EYE_SHAH).
    define_value("CALIB_ROBOT_WORLD_HAND_EYE_LI", cv::RobotWorldHandEyeCalibrationMethod::CALIB_ROBOT_WORLD_HAND_EYE_LI);
  
  Enum<cv::SamplingMethod> rb_cCvSamplingMethod = define_enum<cv::SamplingMethod>("SamplingMethod", rb_mCv).
    define_value("SAMPLING_UNIFORM", cv::SamplingMethod::SAMPLING_UNIFORM).
    define_value("SAMPLING_PROGRESSIVE_NAPSAC", cv::SamplingMethod::SAMPLING_PROGRESSIVE_NAPSAC).
    define_value("SAMPLING_NAPSAC", cv::SamplingMethod::SAMPLING_NAPSAC).
    define_value("SAMPLING_PROSAC", cv::SamplingMethod::SAMPLING_PROSAC);
  
  Enum<cv::LocalOptimMethod> rb_cCvLocalOptimMethod = define_enum<cv::LocalOptimMethod>("LocalOptimMethod", rb_mCv).
    define_value("LOCAL_OPTIM_NULL", cv::LocalOptimMethod::LOCAL_OPTIM_NULL).
    define_value("LOCAL_OPTIM_INNER_LO", cv::LocalOptimMethod::LOCAL_OPTIM_INNER_LO).
    define_value("LOCAL_OPTIM_INNER_AND_ITER_LO", cv::LocalOptimMethod::LOCAL_OPTIM_INNER_AND_ITER_LO).
    define_value("LOCAL_OPTIM_GC", cv::LocalOptimMethod::LOCAL_OPTIM_GC).
    define_value("LOCAL_OPTIM_SIGMA", cv::LocalOptimMethod::LOCAL_OPTIM_SIGMA);
  
  Enum<cv::ScoreMethod> rb_cCvScoreMethod = define_enum<cv::ScoreMethod>("ScoreMethod", rb_mCv).
    define_value("SCORE_METHOD_RANSAC", cv::ScoreMethod::SCORE_METHOD_RANSAC).
    define_value("SCORE_METHOD_MSAC", cv::ScoreMethod::SCORE_METHOD_MSAC).
    define_value("SCORE_METHOD_MAGSAC", cv::ScoreMethod::SCORE_METHOD_MAGSAC).
    define_value("SCORE_METHOD_LMEDS", cv::ScoreMethod::SCORE_METHOD_LMEDS);
  
  Enum<cv::NeighborSearchMethod> rb_cCvNeighborSearchMethod = define_enum<cv::NeighborSearchMethod>("NeighborSearchMethod", rb_mCv).
    define_value("NEIGH_FLANN_KNN", cv::NeighborSearchMethod::NEIGH_FLANN_KNN).
    define_value("NEIGH_GRID", cv::NeighborSearchMethod::NEIGH_GRID).
    define_value("NEIGH_FLANN_RADIUS", cv::NeighborSearchMethod::NEIGH_FLANN_RADIUS);
  
  Enum<cv::PolishingMethod> rb_cCvPolishingMethod = define_enum<cv::PolishingMethod>("PolishingMethod", rb_mCv).
    define_value("NONE_POLISHER", cv::PolishingMethod::NONE_POLISHER).
    define_value("LSQ_POLISHER", cv::PolishingMethod::LSQ_POLISHER).
    define_value("MAGSAC", cv::PolishingMethod::MAGSAC).
    define_value("COV_POLISHER", cv::PolishingMethod::COV_POLISHER);
  
  Class rb_cCvUsacParams = define_class_under<cv::UsacParams>(rb_mCv, "UsacParams").
    define_constructor(Constructor<cv::UsacParams>()).
    define_attr("confidence", &cv::UsacParams::confidence).
    define_attr("is_parallel", &cv::UsacParams::isParallel).
    define_attr("lo_iterations", &cv::UsacParams::loIterations).
    define_attr("lo_method", &cv::UsacParams::loMethod).
    define_attr("lo_sample_size", &cv::UsacParams::loSampleSize).
    define_attr("max_iterations", &cv::UsacParams::maxIterations).
    define_attr("neighbors_search", &cv::UsacParams::neighborsSearch).
    define_attr("random_generator_state", &cv::UsacParams::randomGeneratorState).
    define_attr("sampler", &cv::UsacParams::sampler).
    define_attr("score", &cv::UsacParams::score).
    define_attr("threshold", &cv::UsacParams::threshold).
    define_attr("final_polisher", &cv::UsacParams::final_polisher).
    define_attr("final_polisher_iterations", &cv::UsacParams::final_polisher_iterations);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("rodrigues", &cv::Rodrigues);
  
  Class rb_cCvLMSolver = define_class_under<cv::LMSolver, cv::Algorithm>(rb_mCv, "LMSolver").
    define_method<int(cv::LMSolver::*)(const cv::_InputOutputArray &) const>("run", &cv::LMSolver::run).
    define_method<void(cv::LMSolver::*)(int)>("set_max_iters", &cv::LMSolver::setMaxIters).
    define_method<int(cv::LMSolver::*)() const>("get_max_iters", &cv::LMSolver::getMaxIters).
    define_singleton_function<cv::Ptr<cv::LMSolver>(*)(const cv::Ptr<cv::LMSolver::Callback>&, int)>("create", &cv::LMSolver::create).
    define_singleton_function<cv::Ptr<cv::LMSolver>(*)(const cv::Ptr<cv::LMSolver::Callback>&, int, double)>("create", &cv::LMSolver::create);
  
  Class rb_cCvLMSolverCallback = define_class_under<cv::LMSolver::Callback>(rb_cCvLMSolver, "Callback").
    define_method<bool(cv::LMSolver::Callback::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &) const>("compute", &cv::LMSolver::Callback::compute);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, int, double, const cv::_OutputArray &, const int, const double)>("find_homography", &cv::findHomography);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double)>("find_homography", &cv::findHomography);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::UsacParams&)>("find_homography", &cv::findHomography);
  
  rb_mCv.define_module_function<cv::Vec<double, 3>(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("rq_decomp3x3", &cv::RQDecomp3x3);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("decompose_projection_matrix", &cv::decomposeProjectionMatrix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("mat_mul_deriv", &cv::matMulDeriv);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("compose_rt", &cv::composeRT);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double)>("project_points", &cv::projectPoints);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, int)>("solve_pn_p", &cv::solvePnP);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, int, float, double, const cv::_OutputArray &, int)>("solve_pn_p_ransac", &cv::solvePnPRansac);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::UsacParams&)>("solve_pn_p_ransac", &cv::solvePnPRansac);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int)>("solve_p3_p", &cv::solveP3P);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::TermCriteria)>("solve_pn_p_refine_lm", &cv::solvePnPRefineLM);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::TermCriteria, double)>("solve_pn_p_refine_vvs", &cv::solvePnPRefineVVS);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, bool, cv::SolvePnPMethod, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("solve_pn_p_generic", &cv::solvePnPGeneric);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, double)>("init_camera_matrix2_d", &cv::initCameraMatrix2D);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, int)>("find_chessboard_corners", &cv::findChessboardCorners);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>)>("check_chessboard", &cv::checkChessboard);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, int, const cv::_OutputArray &)>("find_chessboard_corners_sb", &cv::findChessboardCornersSB);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, int)>("find_chessboard_corners_sb", &cv::findChessboardCornersSB);
  
  rb_mCv.define_module_function<cv::Scalar_<double>(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_InputArray &, float, bool, const cv::_OutputArray &)>("estimate_chessboard_sharpness", &cv::estimateChessboardSharpness);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputOutputArray &, cv::Size_<int>)>("find4_quad_corner_subpix", &cv::find4QuadCornerSubpix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Size_<int>, const cv::_InputArray &, bool)>("draw_chessboard_corners", &cv::drawChessboardCorners);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, float, int)>("draw_frame_axes", &cv::drawFrameAxes);
  
  Class rb_cCvCirclesGridFinderParameters = define_class_under<cv::CirclesGridFinderParameters>(rb_mCv, "CirclesGridFinderParameters").
    define_constructor(Constructor<cv::CirclesGridFinderParameters>()).
    define_attr("density_neighborhood_size", &cv::CirclesGridFinderParameters::densityNeighborhoodSize).
    define_attr("min_density", &cv::CirclesGridFinderParameters::minDensity).
    define_attr("kmeans_attempts", &cv::CirclesGridFinderParameters::kmeansAttempts).
    define_attr("min_distance_to_add_keypoint", &cv::CirclesGridFinderParameters::minDistanceToAddKeypoint).
    define_attr("keypoint_scale", &cv::CirclesGridFinderParameters::keypointScale).
    define_attr("min_graph_confidence", &cv::CirclesGridFinderParameters::minGraphConfidence).
    define_attr("vertex_gain", &cv::CirclesGridFinderParameters::vertexGain).
    define_attr("vertex_penalty", &cv::CirclesGridFinderParameters::vertexPenalty).
    define_attr("existing_vertex_gain", &cv::CirclesGridFinderParameters::existingVertexGain).
    define_attr("edge_gain", &cv::CirclesGridFinderParameters::edgeGain).
    define_attr("edge_penalty", &cv::CirclesGridFinderParameters::edgePenalty).
    define_attr("convex_hull_factor", &cv::CirclesGridFinderParameters::convexHullFactor).
    define_attr("min_rng_edge_switch_dist", &cv::CirclesGridFinderParameters::minRNGEdgeSwitchDist).
    define_attr("grid_type", &cv::CirclesGridFinderParameters::gridType).
    define_attr("square_size", &cv::CirclesGridFinderParameters::squareSize).
    define_attr("max_rectified_distance", &cv::CirclesGridFinderParameters::maxRectifiedDistance);
  
  Enum<cv::CirclesGridFinderParameters::GridType> rb_cCvCirclesGridFinderParametersGridType = define_enum<cv::CirclesGridFinderParameters::GridType>("GridType", rb_cCvCirclesGridFinderParameters).
    define_value("SYMMETRIC_GRID", cv::CirclesGridFinderParameters::GridType::SYMMETRIC_GRID).
    define_value("ASYMMETRIC_GRID", cv::CirclesGridFinderParameters::GridType::ASYMMETRIC_GRID);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, int, const cv::Ptr<cv::Feature2D>&, const cv::CirclesGridFinderParameters&)>("find_circles_grid", &cv::findCirclesGrid);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, int, const cv::Ptr<cv::Feature2D>&)>("find_circles_grid", &cv::findCirclesGrid);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate_camera", &cv::calibrateCamera);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate_camera", &cv::calibrateCamera);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, int, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate_camera_ro", &cv::calibrateCameraRO);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, int, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate_camera_ro", &cv::calibrateCameraRO);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, cv::Size_<int>, double, double, double&, double&, double&, cv::Point_<double>&, double&)>("calibration_matrix_values", &cv::calibrationMatrixValues);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Size_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("stereo_calibrate", &cv::stereoCalibrate);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, double, cv::Size_<int>, cv::Rect_<int>*, cv::Rect_<int>*)>("stereo_rectify", &cv::stereoRectify);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, double)>("stereo_rectify_uncalibrated", &cv::stereoRectifyUncalibrated);
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, cv::Size_<int>, cv::Rect_<int>*, cv::Rect_<int>*, int)>("rectify3_collinear", &cv::rectify3Collinear);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, double, cv::Size_<int>, cv::Rect_<int>*, bool)>("get_optimal_new_camera_matrix", &cv::getOptimalNewCameraMatrix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::HandEyeCalibrationMethod)>("calibrate_hand_eye", &cv::calibrateHandEye);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, cv::RobotWorldHandEyeCalibrationMethod)>("calibrate_robot_world_hand_eye", &cv::calibrateRobotWorldHandEye);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("convert_points_to_homogeneous", &cv::convertPointsToHomogeneous);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("convert_points_from_homogeneous", &cv::convertPointsFromHomogeneous);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("convert_points_homogeneous", &cv::convertPointsHomogeneous);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, int, double, double, int, const cv::_OutputArray &)>("find_fundamental_mat", &cv::findFundamentalMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, int, double, double, const cv::_OutputArray &)>("find_fundamental_mat", &cv::findFundamentalMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double, double)>("find_fundamental_mat", &cv::findFundamentalMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::UsacParams&)>("find_fundamental_mat", &cv::findFundamentalMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, double, double, int, const cv::_OutputArray &)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, double, double, const cv::_OutputArray &)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, double, cv::Point_<double>, int, double, double, int, const cv::_OutputArray &)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, double, cv::Point_<double>, int, double, double, const cv::_OutputArray &)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int, double, double, const cv::_OutputArray &)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::UsacParams&)>("find_essential_mat", &cv::findEssentialMat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("decompose_essential_mat", &cv::decomposeEssentialMat);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, double, double, const cv::_InputOutputArray &)>("recover_pose", &cv::recoverPose);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_InputOutputArray &)>("recover_pose", &cv::recoverPose);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, cv::Point_<double>, const cv::_InputOutputArray &)>("recover_pose", &cv::recoverPose);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, const cv::_InputOutputArray &, const cv::_OutputArray &)>("recover_pose", &cv::recoverPose);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, int, const cv::_InputArray &, const cv::_OutputArray &)>("compute_correspond_epilines", &cv::computeCorrespondEpilines);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("triangulate_points", &cv::triangulatePoints);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("correct_matches", &cv::correctMatches);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, double, int, double, const cv::_InputOutputArray &)>("filter_speckles", &cv::filterSpeckles);
  
  rb_mCv.define_module_function<cv::Rect_<int>(*)(cv::Rect_<int>, cv::Rect_<int>, int, int, int)>("get_valid_disparity_roi", &cv::getValidDisparityROI);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, int, int, int)>("validate_disparity", &cv::validateDisparity);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, bool, int)>("reproject_image_to3_d", &cv::reprojectImageTo3D);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("sampson_distance", &cv::sampsonDistance);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, double)>("estimate_affine3_d", &cv::estimateAffine3D);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, double*, bool)>("estimate_affine3_d", &cv::estimateAffine3D);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, double, double)>("estimate_translation3_d", &cv::estimateTranslation3D);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double, unsigned long long, double, unsigned long long)>("estimate_affine2_d", &cv::estimateAffine2D);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::UsacParams&)>("estimate_affine2_d", &cv::estimateAffine2D);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, double, unsigned long long, double, unsigned long long)>("estimate_affine_partial2_d", &cv::estimateAffinePartial2D);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("decompose_homography_mat", &cv::decomposeHomographyMat);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("filter_homography_decomp_by_visible_refpoints", &cv::filterHomographyDecompByVisibleRefpoints);
  
  Class rb_cCvStereoMatcher = define_class_under<cv::StereoMatcher, cv::Algorithm>(rb_mCv, "StereoMatcher").
    define_method<void(cv::StereoMatcher::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("compute", &cv::StereoMatcher::compute).
    define_method<int(cv::StereoMatcher::*)() const>("get_min_disparity", &cv::StereoMatcher::getMinDisparity).
    define_method<void(cv::StereoMatcher::*)(int)>("set_min_disparity", &cv::StereoMatcher::setMinDisparity).
    define_method<int(cv::StereoMatcher::*)() const>("get_num_disparities", &cv::StereoMatcher::getNumDisparities).
    define_method<void(cv::StereoMatcher::*)(int)>("set_num_disparities", &cv::StereoMatcher::setNumDisparities).
    define_method<int(cv::StereoMatcher::*)() const>("get_block_size", &cv::StereoMatcher::getBlockSize).
    define_method<void(cv::StereoMatcher::*)(int)>("set_block_size", &cv::StereoMatcher::setBlockSize).
    define_method<int(cv::StereoMatcher::*)() const>("get_speckle_window_size", &cv::StereoMatcher::getSpeckleWindowSize).
    define_method<void(cv::StereoMatcher::*)(int)>("set_speckle_window_size", &cv::StereoMatcher::setSpeckleWindowSize).
    define_method<int(cv::StereoMatcher::*)() const>("get_speckle_range", &cv::StereoMatcher::getSpeckleRange).
    define_method<void(cv::StereoMatcher::*)(int)>("set_speckle_range", &cv::StereoMatcher::setSpeckleRange).
    define_method<int(cv::StereoMatcher::*)() const>("get_disp12_max_diff", &cv::StereoMatcher::getDisp12MaxDiff).
    define_method<void(cv::StereoMatcher::*)(int)>("set_disp12_max_diff", &cv::StereoMatcher::setDisp12MaxDiff);
  
  
  Class rb_cCvStereoBM = define_class_under<cv::StereoBM, cv::StereoMatcher>(rb_mCv, "StereoBM").
    define_method<int(cv::StereoBM::*)() const>("get_pre_filter_type", &cv::StereoBM::getPreFilterType).
    define_method<void(cv::StereoBM::*)(int)>("set_pre_filter_type", &cv::StereoBM::setPreFilterType).
    define_method<int(cv::StereoBM::*)() const>("get_pre_filter_size", &cv::StereoBM::getPreFilterSize).
    define_method<void(cv::StereoBM::*)(int)>("set_pre_filter_size", &cv::StereoBM::setPreFilterSize).
    define_method<int(cv::StereoBM::*)() const>("get_pre_filter_cap", &cv::StereoBM::getPreFilterCap).
    define_method<void(cv::StereoBM::*)(int)>("set_pre_filter_cap", &cv::StereoBM::setPreFilterCap).
    define_method<int(cv::StereoBM::*)() const>("get_texture_threshold", &cv::StereoBM::getTextureThreshold).
    define_method<void(cv::StereoBM::*)(int)>("set_texture_threshold", &cv::StereoBM::setTextureThreshold).
    define_method<int(cv::StereoBM::*)() const>("get_uniqueness_ratio", &cv::StereoBM::getUniquenessRatio).
    define_method<void(cv::StereoBM::*)(int)>("set_uniqueness_ratio", &cv::StereoBM::setUniquenessRatio).
    define_method<int(cv::StereoBM::*)() const>("get_smaller_block_size", &cv::StereoBM::getSmallerBlockSize).
    define_method<void(cv::StereoBM::*)(int)>("set_smaller_block_size", &cv::StereoBM::setSmallerBlockSize).
    define_method<cv::Rect_<int>(cv::StereoBM::*)() const>("get_roi1", &cv::StereoBM::getROI1).
    define_method<void(cv::StereoBM::*)(cv::Rect_<int>)>("set_roi1", &cv::StereoBM::setROI1).
    define_method<cv::Rect_<int>(cv::StereoBM::*)() const>("get_roi2", &cv::StereoBM::getROI2).
    define_method<void(cv::StereoBM::*)(cv::Rect_<int>)>("set_roi2", &cv::StereoBM::setROI2).
    define_singleton_function<cv::Ptr<cv::StereoBM>(*)(int, int)>("create", &cv::StereoBM::create);
  
  
  Class rb_cCvStereoSGBM = define_class_under<cv::StereoSGBM, cv::StereoMatcher>(rb_mCv, "StereoSGBM").
    define_method<int(cv::StereoSGBM::*)() const>("get_pre_filter_cap", &cv::StereoSGBM::getPreFilterCap).
    define_method<void(cv::StereoSGBM::*)(int)>("set_pre_filter_cap", &cv::StereoSGBM::setPreFilterCap).
    define_method<int(cv::StereoSGBM::*)() const>("get_uniqueness_ratio", &cv::StereoSGBM::getUniquenessRatio).
    define_method<void(cv::StereoSGBM::*)(int)>("set_uniqueness_ratio", &cv::StereoSGBM::setUniquenessRatio).
    define_method<int(cv::StereoSGBM::*)() const>("get_p1", &cv::StereoSGBM::getP1).
    define_method<void(cv::StereoSGBM::*)(int)>("set_p1", &cv::StereoSGBM::setP1).
    define_method<int(cv::StereoSGBM::*)() const>("get_p2", &cv::StereoSGBM::getP2).
    define_method<void(cv::StereoSGBM::*)(int)>("set_p2", &cv::StereoSGBM::setP2).
    define_method<int(cv::StereoSGBM::*)() const>("get_mode", &cv::StereoSGBM::getMode).
    define_method<void(cv::StereoSGBM::*)(int)>("set_mode", &cv::StereoSGBM::setMode).
    define_singleton_function<cv::Ptr<cv::StereoSGBM>(*)(int, int, int, int, int, int, int, int, int, int, int)>("create", &cv::StereoSGBM::create);
  
  
  Enum<cv::UndistortTypes> rb_cCvUndistortTypes = define_enum<cv::UndistortTypes>("UndistortTypes", rb_mCv).
    define_value("PROJ_SPHERICAL_ORTHO", cv::UndistortTypes::PROJ_SPHERICAL_ORTHO).
    define_value("PROJ_SPHERICAL_EQRECT", cv::UndistortTypes::PROJ_SPHERICAL_EQRECT);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("undistort", &cv::undistort);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, int, const cv::_OutputArray &, const cv::_OutputArray &)>("init_undistort_rectify_map", &cv::initUndistortRectifyMap);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, int, const cv::_OutputArray &, const cv::_OutputArray &)>("init_inverse_rectification_map", &cv::initInverseRectificationMap);
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &, cv::Size_<int>, int, int, const cv::_OutputArray &, const cv::_OutputArray &, cv::UndistortTypes, double)>("init_wide_angle_proj_map", &cv::initWideAngleProjMap);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, cv::Size_<int>, bool)>("get_default_new_camera_matrix", &cv::getDefaultNewCameraMatrix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("undistort_points", &cv::undistortPoints);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::TermCriteria)>("undistort_points", &cv::undistortPoints);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::TermCriteria)>("undistort_image_points", &cv::undistortImagePoints);
  
  Module rb_mCvFisheye = define_module_under(rb_mCv, "Fisheye");
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::Affine3<double>&, const cv::_InputArray &, const cv::_InputArray &, double, const cv::_OutputArray &)>("project_points", &cv::fisheye::projectPoints);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double, const cv::_OutputArray &)>("project_points", &cv::fisheye::projectPoints);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, double)>("distort_points", &cv::fisheye::distortPoints);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::TermCriteria)>("undistort_points", &cv::fisheye::undistortPoints);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, int, const cv::_OutputArray &, const cv::_OutputArray &)>("init_undistort_rectify_map", &cv::fisheye::initUndistortRectifyMap);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&)>("undistort_image", &cv::fisheye::undistortImage);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, const cv::_InputArray &, const cv::_OutputArray &, double, const cv::Size_<int>&, double)>("estimate_new_camera_matrix_for_undistort_rectify", &cv::fisheye::estimateNewCameraMatrixForUndistortRectify);
  
  rb_mCvFisheye.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("calibrate", &cv::fisheye::calibrate);
  
  rb_mCvFisheye.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::Size_<int>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, const cv::Size_<int>&, double, double)>("stereo_rectify", &cv::fisheye::stereoRectify);
  
  rb_mCvFisheye.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("stereo_calibrate", &cv::fisheye::stereoCalibrate);
  
  rb_mCvFisheye.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Size_<int>, const cv::_OutputArray &, const cv::_OutputArray &, int, cv::TermCriteria)>("stereo_calibrate", &cv::fisheye::stereoCalibrate);
}