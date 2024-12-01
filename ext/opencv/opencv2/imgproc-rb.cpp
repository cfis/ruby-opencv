#include <opencv2/imgproc.hpp>
#include "imgproc-rb.hpp"

using namespace Rice;

extern "C"
void Init_Imgproc()
{
  Module rb_mCv = define_module("Cv");
  
  Enum<cv::SpecialFilter> rb_cCvSpecialFilter = define_enum<cv::SpecialFilter>("SpecialFilter", rb_mCv).
    define_value("FILTER_SCHARR", cv::SpecialFilter::FILTER_SCHARR);
  
  Enum<cv::MorphTypes> rb_cCvMorphTypes = define_enum<cv::MorphTypes>("MorphTypes", rb_mCv).
    define_value("MORPH_ERODE", cv::MorphTypes::MORPH_ERODE).
    define_value("MORPH_DILATE", cv::MorphTypes::MORPH_DILATE).
    define_value("MORPH_OPEN", cv::MorphTypes::MORPH_OPEN).
    define_value("MORPH_CLOSE", cv::MorphTypes::MORPH_CLOSE).
    define_value("MORPH_GRADIENT", cv::MorphTypes::MORPH_GRADIENT).
    define_value("MORPH_TOPHAT", cv::MorphTypes::MORPH_TOPHAT).
    define_value("MORPH_BLACKHAT", cv::MorphTypes::MORPH_BLACKHAT).
    define_value("MORPH_HITMISS", cv::MorphTypes::MORPH_HITMISS);
  
  Enum<cv::MorphShapes> rb_cCvMorphShapes = define_enum<cv::MorphShapes>("MorphShapes", rb_mCv).
    define_value("MORPH_RECT", cv::MorphShapes::MORPH_RECT).
    define_value("MORPH_CROSS", cv::MorphShapes::MORPH_CROSS).
    define_value("MORPH_ELLIPSE", cv::MorphShapes::MORPH_ELLIPSE);
  
  Enum<cv::InterpolationFlags> rb_cCvInterpolationFlags = define_enum<cv::InterpolationFlags>("InterpolationFlags", rb_mCv).
    define_value("INTER_NEAREST", cv::InterpolationFlags::INTER_NEAREST).
    define_value("INTER_LINEAR", cv::InterpolationFlags::INTER_LINEAR).
    define_value("INTER_CUBIC", cv::InterpolationFlags::INTER_CUBIC).
    define_value("INTER_AREA", cv::InterpolationFlags::INTER_AREA).
    define_value("INTER_LANCZOS4", cv::InterpolationFlags::INTER_LANCZOS4).
    define_value("INTER_LINEAR_EXACT", cv::InterpolationFlags::INTER_LINEAR_EXACT).
    define_value("INTER_NEAREST_EXACT", cv::InterpolationFlags::INTER_NEAREST_EXACT).
    define_value("INTER_MAX", cv::InterpolationFlags::INTER_MAX).
    define_value("WARP_FILL_OUTLIERS", cv::InterpolationFlags::WARP_FILL_OUTLIERS).
    define_value("WARP_INVERSE_MAP", cv::InterpolationFlags::WARP_INVERSE_MAP);
  
  Enum<cv::WarpPolarMode> rb_cCvWarpPolarMode = define_enum<cv::WarpPolarMode>("WarpPolarMode", rb_mCv).
    define_value("WARP_POLAR_LINEAR", cv::WarpPolarMode::WARP_POLAR_LINEAR).
    define_value("WARP_POLAR_LOG", cv::WarpPolarMode::WARP_POLAR_LOG);
  
  Enum<cv::InterpolationMasks> rb_cCvInterpolationMasks = define_enum<cv::InterpolationMasks>("InterpolationMasks", rb_mCv).
    define_value("INTER_BITS", cv::InterpolationMasks::INTER_BITS).
    define_value("INTER_BITS2", cv::InterpolationMasks::INTER_BITS2).
    define_value("INTER_TAB_SIZE", cv::InterpolationMasks::INTER_TAB_SIZE).
    define_value("INTER_TAB_SIZE2", cv::InterpolationMasks::INTER_TAB_SIZE2);
  
  Enum<cv::DistanceTypes> rb_cCvDistanceTypes = define_enum<cv::DistanceTypes>("DistanceTypes", rb_mCv).
    define_value("DIST_USER", cv::DistanceTypes::DIST_USER).
    define_value("DIST_L1", cv::DistanceTypes::DIST_L1).
    define_value("DIST_L2", cv::DistanceTypes::DIST_L2).
    define_value("DIST_C", cv::DistanceTypes::DIST_C).
    define_value("DIST_L12", cv::DistanceTypes::DIST_L12).
    define_value("DIST_FAIR", cv::DistanceTypes::DIST_FAIR).
    define_value("DIST_WELSCH", cv::DistanceTypes::DIST_WELSCH).
    define_value("DIST_HUBER", cv::DistanceTypes::DIST_HUBER);
  
  Enum<cv::DistanceTransformMasks> rb_cCvDistanceTransformMasks = define_enum<cv::DistanceTransformMasks>("DistanceTransformMasks", rb_mCv).
    define_value("DIST_MASK_3", cv::DistanceTransformMasks::DIST_MASK_3).
    define_value("DIST_MASK_5", cv::DistanceTransformMasks::DIST_MASK_5).
    define_value("DIST_MASK_PRECISE", cv::DistanceTransformMasks::DIST_MASK_PRECISE);
  
  Enum<cv::ThresholdTypes> rb_cCvThresholdTypes = define_enum<cv::ThresholdTypes>("ThresholdTypes", rb_mCv).
    define_value("THRESH_BINARY", cv::ThresholdTypes::THRESH_BINARY).
    define_value("THRESH_BINARY_INV", cv::ThresholdTypes::THRESH_BINARY_INV).
    define_value("THRESH_TRUNC", cv::ThresholdTypes::THRESH_TRUNC).
    define_value("THRESH_TOZERO", cv::ThresholdTypes::THRESH_TOZERO).
    define_value("THRESH_TOZERO_INV", cv::ThresholdTypes::THRESH_TOZERO_INV).
    define_value("THRESH_MASK", cv::ThresholdTypes::THRESH_MASK).
    define_value("THRESH_OTSU", cv::ThresholdTypes::THRESH_OTSU).
    define_value("THRESH_TRIANGLE", cv::ThresholdTypes::THRESH_TRIANGLE);
  
  Enum<cv::AdaptiveThresholdTypes> rb_cCvAdaptiveThresholdTypes = define_enum<cv::AdaptiveThresholdTypes>("AdaptiveThresholdTypes", rb_mCv).
    define_value("ADAPTIVE_THRESH_MEAN_C", cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_MEAN_C).
    define_value("ADAPTIVE_THRESH_GAUSSIAN_C", cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C);
  
  Enum<cv::GrabCutClasses> rb_cCvGrabCutClasses = define_enum<cv::GrabCutClasses>("GrabCutClasses", rb_mCv).
    define_value("GC_BGD", cv::GrabCutClasses::GC_BGD).
    define_value("GC_FGD", cv::GrabCutClasses::GC_FGD).
    define_value("GC_PR_BGD", cv::GrabCutClasses::GC_PR_BGD).
    define_value("GC_PR_FGD", cv::GrabCutClasses::GC_PR_FGD);
  
  Enum<cv::GrabCutModes> rb_cCvGrabCutModes = define_enum<cv::GrabCutModes>("GrabCutModes", rb_mCv).
    define_value("GC_INIT_WITH_RECT", cv::GrabCutModes::GC_INIT_WITH_RECT).
    define_value("GC_INIT_WITH_MASK", cv::GrabCutModes::GC_INIT_WITH_MASK).
    define_value("GC_EVAL", cv::GrabCutModes::GC_EVAL).
    define_value("GC_EVAL_FREEZE_MODEL", cv::GrabCutModes::GC_EVAL_FREEZE_MODEL);
  
  Enum<cv::DistanceTransformLabelTypes> rb_cCvDistanceTransformLabelTypes = define_enum<cv::DistanceTransformLabelTypes>("DistanceTransformLabelTypes", rb_mCv).
    define_value("DIST_LABEL_CCOMP", cv::DistanceTransformLabelTypes::DIST_LABEL_CCOMP).
    define_value("DIST_LABEL_PIXEL", cv::DistanceTransformLabelTypes::DIST_LABEL_PIXEL);
  
  Enum<cv::FloodFillFlags> rb_cCvFloodFillFlags = define_enum<cv::FloodFillFlags>("FloodFillFlags", rb_mCv).
    define_value("FLOODFILL_FIXED_RANGE", cv::FloodFillFlags::FLOODFILL_FIXED_RANGE).
    define_value("FLOODFILL_MASK_ONLY", cv::FloodFillFlags::FLOODFILL_MASK_ONLY);
  
  Enum<cv::ConnectedComponentsTypes> rb_cCvConnectedComponentsTypes = define_enum<cv::ConnectedComponentsTypes>("ConnectedComponentsTypes", rb_mCv).
    define_value("CC_STAT_LEFT", cv::ConnectedComponentsTypes::CC_STAT_LEFT).
    define_value("CC_STAT_TOP", cv::ConnectedComponentsTypes::CC_STAT_TOP).
    define_value("CC_STAT_WIDTH", cv::ConnectedComponentsTypes::CC_STAT_WIDTH).
    define_value("CC_STAT_HEIGHT", cv::ConnectedComponentsTypes::CC_STAT_HEIGHT).
    define_value("CC_STAT_AREA", cv::ConnectedComponentsTypes::CC_STAT_AREA).
    define_value("CC_STAT_MAX", cv::ConnectedComponentsTypes::CC_STAT_MAX);
  
  Enum<cv::ConnectedComponentsAlgorithmsTypes> rb_cCvConnectedComponentsAlgorithmsTypes = define_enum<cv::ConnectedComponentsAlgorithmsTypes>("ConnectedComponentsAlgorithmsTypes", rb_mCv).
    define_value("CCL_DEFAULT", cv::ConnectedComponentsAlgorithmsTypes::CCL_DEFAULT).
    define_value("CCL_WU", cv::ConnectedComponentsAlgorithmsTypes::CCL_WU).
    define_value("CCL_GRANA", cv::ConnectedComponentsAlgorithmsTypes::CCL_GRANA).
    define_value("CCL_BOLELLI", cv::ConnectedComponentsAlgorithmsTypes::CCL_BOLELLI).
    define_value("CCL_SAUF", cv::ConnectedComponentsAlgorithmsTypes::CCL_SAUF).
    define_value("CCL_BBDT", cv::ConnectedComponentsAlgorithmsTypes::CCL_BBDT).
    define_value("CCL_SPAGHETTI", cv::ConnectedComponentsAlgorithmsTypes::CCL_SPAGHETTI);
  
  Enum<cv::RetrievalModes> rb_cCvRetrievalModes = define_enum<cv::RetrievalModes>("RetrievalModes", rb_mCv).
    define_value("RETR_EXTERNAL", cv::RetrievalModes::RETR_EXTERNAL).
    define_value("RETR_LIST", cv::RetrievalModes::RETR_LIST).
    define_value("RETR_CCOMP", cv::RetrievalModes::RETR_CCOMP).
    define_value("RETR_TREE", cv::RetrievalModes::RETR_TREE).
    define_value("RETR_FLOODFILL", cv::RetrievalModes::RETR_FLOODFILL);
  
  Enum<cv::ContourApproximationModes> rb_cCvContourApproximationModes = define_enum<cv::ContourApproximationModes>("ContourApproximationModes", rb_mCv).
    define_value("CHAIN_APPROX_NONE", cv::ContourApproximationModes::CHAIN_APPROX_NONE).
    define_value("CHAIN_APPROX_SIMPLE", cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE).
    define_value("CHAIN_APPROX_TC89_L1", cv::ContourApproximationModes::CHAIN_APPROX_TC89_L1).
    define_value("CHAIN_APPROX_TC89_KCOS", cv::ContourApproximationModes::CHAIN_APPROX_TC89_KCOS);
  
  Enum<cv::ShapeMatchModes> rb_cCvShapeMatchModes = define_enum<cv::ShapeMatchModes>("ShapeMatchModes", rb_mCv).
    define_value("CONTOURS_MATCH_I1", cv::ShapeMatchModes::CONTOURS_MATCH_I1).
    define_value("CONTOURS_MATCH_I2", cv::ShapeMatchModes::CONTOURS_MATCH_I2).
    define_value("CONTOURS_MATCH_I3", cv::ShapeMatchModes::CONTOURS_MATCH_I3);
  
  Enum<cv::HoughModes> rb_cCvHoughModes = define_enum<cv::HoughModes>("HoughModes", rb_mCv).
    define_value("HOUGH_STANDARD", cv::HoughModes::HOUGH_STANDARD).
    define_value("HOUGH_PROBABILISTIC", cv::HoughModes::HOUGH_PROBABILISTIC).
    define_value("HOUGH_MULTI_SCALE", cv::HoughModes::HOUGH_MULTI_SCALE).
    define_value("HOUGH_GRADIENT", cv::HoughModes::HOUGH_GRADIENT).
    define_value("HOUGH_GRADIENT_ALT", cv::HoughModes::HOUGH_GRADIENT_ALT);
  
  Enum<cv::LineSegmentDetectorModes> rb_cCvLineSegmentDetectorModes = define_enum<cv::LineSegmentDetectorModes>("LineSegmentDetectorModes", rb_mCv).
    define_value("LSD_REFINE_NONE", cv::LineSegmentDetectorModes::LSD_REFINE_NONE).
    define_value("LSD_REFINE_STD", cv::LineSegmentDetectorModes::LSD_REFINE_STD).
    define_value("LSD_REFINE_ADV", cv::LineSegmentDetectorModes::LSD_REFINE_ADV);
  
  Enum<cv::HistCompMethods> rb_cCvHistCompMethods = define_enum<cv::HistCompMethods>("HistCompMethods", rb_mCv).
    define_value("HISTCMP_CORREL", cv::HistCompMethods::HISTCMP_CORREL).
    define_value("HISTCMP_CHISQR", cv::HistCompMethods::HISTCMP_CHISQR).
    define_value("HISTCMP_INTERSECT", cv::HistCompMethods::HISTCMP_INTERSECT).
    define_value("HISTCMP_BHATTACHARYYA", cv::HistCompMethods::HISTCMP_BHATTACHARYYA).
    define_value("HISTCMP_HELLINGER", cv::HistCompMethods::HISTCMP_HELLINGER).
    define_value("HISTCMP_CHISQR_ALT", cv::HistCompMethods::HISTCMP_CHISQR_ALT).
    define_value("HISTCMP_KL_DIV", cv::HistCompMethods::HISTCMP_KL_DIV);
  
  Enum<cv::ColorConversionCodes> rb_cCvColorConversionCodes = define_enum<cv::ColorConversionCodes>("ColorConversionCodes", rb_mCv).
    define_value("COLOR_BGR2BGRA", cv::ColorConversionCodes::COLOR_BGR2BGRA).
    define_value("COLOR_RGB2RGBA", cv::ColorConversionCodes::COLOR_RGB2RGBA).
    define_value("COLOR_BGRA2BGR", cv::ColorConversionCodes::COLOR_BGRA2BGR).
    define_value("COLOR_RGBA2RGB", cv::ColorConversionCodes::COLOR_RGBA2RGB).
    define_value("COLOR_BGR2RGBA", cv::ColorConversionCodes::COLOR_BGR2RGBA).
    define_value("COLOR_RGB2BGRA", cv::ColorConversionCodes::COLOR_RGB2BGRA).
    define_value("COLOR_RGBA2BGR", cv::ColorConversionCodes::COLOR_RGBA2BGR).
    define_value("COLOR_BGRA2RGB", cv::ColorConversionCodes::COLOR_BGRA2RGB).
    define_value("COLOR_BGR2RGB", cv::ColorConversionCodes::COLOR_BGR2RGB).
    define_value("COLOR_RGB2BGR", cv::ColorConversionCodes::COLOR_RGB2BGR).
    define_value("COLOR_BGRA2RGBA", cv::ColorConversionCodes::COLOR_BGRA2RGBA).
    define_value("COLOR_RGBA2BGRA", cv::ColorConversionCodes::COLOR_RGBA2BGRA).
    define_value("COLOR_BGR2GRAY", cv::ColorConversionCodes::COLOR_BGR2GRAY).
    define_value("COLOR_RGB2GRAY", cv::ColorConversionCodes::COLOR_RGB2GRAY).
    define_value("COLOR_GRAY2BGR", cv::ColorConversionCodes::COLOR_GRAY2BGR).
    define_value("COLOR_GRAY2RGB", cv::ColorConversionCodes::COLOR_GRAY2RGB).
    define_value("COLOR_GRAY2BGRA", cv::ColorConversionCodes::COLOR_GRAY2BGRA).
    define_value("COLOR_GRAY2RGBA", cv::ColorConversionCodes::COLOR_GRAY2RGBA).
    define_value("COLOR_BGRA2GRAY", cv::ColorConversionCodes::COLOR_BGRA2GRAY).
    define_value("COLOR_RGBA2GRAY", cv::ColorConversionCodes::COLOR_RGBA2GRAY).
    define_value("COLOR_BGR2BGR565", cv::ColorConversionCodes::COLOR_BGR2BGR565).
    define_value("COLOR_RGB2BGR565", cv::ColorConversionCodes::COLOR_RGB2BGR565).
    define_value("COLOR_BGR5652BGR", cv::ColorConversionCodes::COLOR_BGR5652BGR).
    define_value("COLOR_BGR5652RGB", cv::ColorConversionCodes::COLOR_BGR5652RGB).
    define_value("COLOR_BGRA2BGR565", cv::ColorConversionCodes::COLOR_BGRA2BGR565).
    define_value("COLOR_RGBA2BGR565", cv::ColorConversionCodes::COLOR_RGBA2BGR565).
    define_value("COLOR_BGR5652BGRA", cv::ColorConversionCodes::COLOR_BGR5652BGRA).
    define_value("COLOR_BGR5652RGBA", cv::ColorConversionCodes::COLOR_BGR5652RGBA).
    define_value("COLOR_GRAY2BGR565", cv::ColorConversionCodes::COLOR_GRAY2BGR565).
    define_value("COLOR_BGR5652GRAY", cv::ColorConversionCodes::COLOR_BGR5652GRAY).
    define_value("COLOR_BGR2BGR555", cv::ColorConversionCodes::COLOR_BGR2BGR555).
    define_value("COLOR_RGB2BGR555", cv::ColorConversionCodes::COLOR_RGB2BGR555).
    define_value("COLOR_BGR5552BGR", cv::ColorConversionCodes::COLOR_BGR5552BGR).
    define_value("COLOR_BGR5552RGB", cv::ColorConversionCodes::COLOR_BGR5552RGB).
    define_value("COLOR_BGRA2BGR555", cv::ColorConversionCodes::COLOR_BGRA2BGR555).
    define_value("COLOR_RGBA2BGR555", cv::ColorConversionCodes::COLOR_RGBA2BGR555).
    define_value("COLOR_BGR5552BGRA", cv::ColorConversionCodes::COLOR_BGR5552BGRA).
    define_value("COLOR_BGR5552RGBA", cv::ColorConversionCodes::COLOR_BGR5552RGBA).
    define_value("COLOR_GRAY2BGR555", cv::ColorConversionCodes::COLOR_GRAY2BGR555).
    define_value("COLOR_BGR5552GRAY", cv::ColorConversionCodes::COLOR_BGR5552GRAY).
    define_value("COLOR_BGR2XYZ", cv::ColorConversionCodes::COLOR_BGR2XYZ).
    define_value("COLOR_RGB2XYZ", cv::ColorConversionCodes::COLOR_RGB2XYZ).
    define_value("COLOR_XYZ2BGR", cv::ColorConversionCodes::COLOR_XYZ2BGR).
    define_value("COLOR_XYZ2RGB", cv::ColorConversionCodes::COLOR_XYZ2RGB).
    define_value("COLOR_BGR2YCrCb", cv::ColorConversionCodes::COLOR_BGR2YCrCb).
    define_value("COLOR_RGB2YCrCb", cv::ColorConversionCodes::COLOR_RGB2YCrCb).
    define_value("COLOR_YCrCb2BGR", cv::ColorConversionCodes::COLOR_YCrCb2BGR).
    define_value("COLOR_YCrCb2RGB", cv::ColorConversionCodes::COLOR_YCrCb2RGB).
    define_value("COLOR_BGR2HSV", cv::ColorConversionCodes::COLOR_BGR2HSV).
    define_value("COLOR_RGB2HSV", cv::ColorConversionCodes::COLOR_RGB2HSV).
    define_value("COLOR_BGR2Lab", cv::ColorConversionCodes::COLOR_BGR2Lab).
    define_value("COLOR_RGB2Lab", cv::ColorConversionCodes::COLOR_RGB2Lab).
    define_value("COLOR_BGR2Luv", cv::ColorConversionCodes::COLOR_BGR2Luv).
    define_value("COLOR_RGB2Luv", cv::ColorConversionCodes::COLOR_RGB2Luv).
    define_value("COLOR_BGR2HLS", cv::ColorConversionCodes::COLOR_BGR2HLS).
    define_value("COLOR_RGB2HLS", cv::ColorConversionCodes::COLOR_RGB2HLS).
    define_value("COLOR_HSV2BGR", cv::ColorConversionCodes::COLOR_HSV2BGR).
    define_value("COLOR_HSV2RGB", cv::ColorConversionCodes::COLOR_HSV2RGB).
    define_value("COLOR_Lab2BGR", cv::ColorConversionCodes::COLOR_Lab2BGR).
    define_value("COLOR_Lab2RGB", cv::ColorConversionCodes::COLOR_Lab2RGB).
    define_value("COLOR_Luv2BGR", cv::ColorConversionCodes::COLOR_Luv2BGR).
    define_value("COLOR_Luv2RGB", cv::ColorConversionCodes::COLOR_Luv2RGB).
    define_value("COLOR_HLS2BGR", cv::ColorConversionCodes::COLOR_HLS2BGR).
    define_value("COLOR_HLS2RGB", cv::ColorConversionCodes::COLOR_HLS2RGB).
    define_value("COLOR_BGR2HSV_FULL", cv::ColorConversionCodes::COLOR_BGR2HSV_FULL).
    define_value("COLOR_RGB2HSV_FULL", cv::ColorConversionCodes::COLOR_RGB2HSV_FULL).
    define_value("COLOR_BGR2HLS_FULL", cv::ColorConversionCodes::COLOR_BGR2HLS_FULL).
    define_value("COLOR_RGB2HLS_FULL", cv::ColorConversionCodes::COLOR_RGB2HLS_FULL).
    define_value("COLOR_HSV2BGR_FULL", cv::ColorConversionCodes::COLOR_HSV2BGR_FULL).
    define_value("COLOR_HSV2RGB_FULL", cv::ColorConversionCodes::COLOR_HSV2RGB_FULL).
    define_value("COLOR_HLS2BGR_FULL", cv::ColorConversionCodes::COLOR_HLS2BGR_FULL).
    define_value("COLOR_HLS2RGB_FULL", cv::ColorConversionCodes::COLOR_HLS2RGB_FULL).
    define_value("COLOR_LBGR2Lab", cv::ColorConversionCodes::COLOR_LBGR2Lab).
    define_value("COLOR_LRGB2Lab", cv::ColorConversionCodes::COLOR_LRGB2Lab).
    define_value("COLOR_LBGR2Luv", cv::ColorConversionCodes::COLOR_LBGR2Luv).
    define_value("COLOR_LRGB2Luv", cv::ColorConversionCodes::COLOR_LRGB2Luv).
    define_value("COLOR_Lab2LBGR", cv::ColorConversionCodes::COLOR_Lab2LBGR).
    define_value("COLOR_Lab2LRGB", cv::ColorConversionCodes::COLOR_Lab2LRGB).
    define_value("COLOR_Luv2LBGR", cv::ColorConversionCodes::COLOR_Luv2LBGR).
    define_value("COLOR_Luv2LRGB", cv::ColorConversionCodes::COLOR_Luv2LRGB).
    define_value("COLOR_BGR2YUV", cv::ColorConversionCodes::COLOR_BGR2YUV).
    define_value("COLOR_RGB2YUV", cv::ColorConversionCodes::COLOR_RGB2YUV).
    define_value("COLOR_YUV2BGR", cv::ColorConversionCodes::COLOR_YUV2BGR).
    define_value("COLOR_YUV2RGB", cv::ColorConversionCodes::COLOR_YUV2RGB).
    define_value("COLOR_YUV2RGB_NV12", cv::ColorConversionCodes::COLOR_YUV2RGB_NV12).
    define_value("COLOR_YUV2BGR_NV12", cv::ColorConversionCodes::COLOR_YUV2BGR_NV12).
    define_value("COLOR_YUV2RGB_NV21", cv::ColorConversionCodes::COLOR_YUV2RGB_NV21).
    define_value("COLOR_YUV2BGR_NV21", cv::ColorConversionCodes::COLOR_YUV2BGR_NV21).
    define_value("COLOR_YUV420sp2RGB", cv::ColorConversionCodes::COLOR_YUV420sp2RGB).
    define_value("COLOR_YUV420sp2BGR", cv::ColorConversionCodes::COLOR_YUV420sp2BGR).
    define_value("COLOR_YUV2RGBA_NV12", cv::ColorConversionCodes::COLOR_YUV2RGBA_NV12).
    define_value("COLOR_YUV2BGRA_NV12", cv::ColorConversionCodes::COLOR_YUV2BGRA_NV12).
    define_value("COLOR_YUV2RGBA_NV21", cv::ColorConversionCodes::COLOR_YUV2RGBA_NV21).
    define_value("COLOR_YUV2BGRA_NV21", cv::ColorConversionCodes::COLOR_YUV2BGRA_NV21).
    define_value("COLOR_YUV420sp2RGBA", cv::ColorConversionCodes::COLOR_YUV420sp2RGBA).
    define_value("COLOR_YUV420sp2BGRA", cv::ColorConversionCodes::COLOR_YUV420sp2BGRA).
    define_value("COLOR_YUV2RGB_YV12", cv::ColorConversionCodes::COLOR_YUV2RGB_YV12).
    define_value("COLOR_YUV2BGR_YV12", cv::ColorConversionCodes::COLOR_YUV2BGR_YV12).
    define_value("COLOR_YUV2RGB_IYUV", cv::ColorConversionCodes::COLOR_YUV2RGB_IYUV).
    define_value("COLOR_YUV2BGR_IYUV", cv::ColorConversionCodes::COLOR_YUV2BGR_IYUV).
    define_value("COLOR_YUV2RGB_I420", cv::ColorConversionCodes::COLOR_YUV2RGB_I420).
    define_value("COLOR_YUV2BGR_I420", cv::ColorConversionCodes::COLOR_YUV2BGR_I420).
    define_value("COLOR_YUV420p2RGB", cv::ColorConversionCodes::COLOR_YUV420p2RGB).
    define_value("COLOR_YUV420p2BGR", cv::ColorConversionCodes::COLOR_YUV420p2BGR).
    define_value("COLOR_YUV2RGBA_YV12", cv::ColorConversionCodes::COLOR_YUV2RGBA_YV12).
    define_value("COLOR_YUV2BGRA_YV12", cv::ColorConversionCodes::COLOR_YUV2BGRA_YV12).
    define_value("COLOR_YUV2RGBA_IYUV", cv::ColorConversionCodes::COLOR_YUV2RGBA_IYUV).
    define_value("COLOR_YUV2BGRA_IYUV", cv::ColorConversionCodes::COLOR_YUV2BGRA_IYUV).
    define_value("COLOR_YUV2RGBA_I420", cv::ColorConversionCodes::COLOR_YUV2RGBA_I420).
    define_value("COLOR_YUV2BGRA_I420", cv::ColorConversionCodes::COLOR_YUV2BGRA_I420).
    define_value("COLOR_YUV420p2RGBA", cv::ColorConversionCodes::COLOR_YUV420p2RGBA).
    define_value("COLOR_YUV420p2BGRA", cv::ColorConversionCodes::COLOR_YUV420p2BGRA).
    define_value("COLOR_YUV2GRAY_420", cv::ColorConversionCodes::COLOR_YUV2GRAY_420).
    define_value("COLOR_YUV2GRAY_NV21", cv::ColorConversionCodes::COLOR_YUV2GRAY_NV21).
    define_value("COLOR_YUV2GRAY_NV12", cv::ColorConversionCodes::COLOR_YUV2GRAY_NV12).
    define_value("COLOR_YUV2GRAY_YV12", cv::ColorConversionCodes::COLOR_YUV2GRAY_YV12).
    define_value("COLOR_YUV2GRAY_IYUV", cv::ColorConversionCodes::COLOR_YUV2GRAY_IYUV).
    define_value("COLOR_YUV2GRAY_I420", cv::ColorConversionCodes::COLOR_YUV2GRAY_I420).
    define_value("COLOR_YUV420sp2GRAY", cv::ColorConversionCodes::COLOR_YUV420sp2GRAY).
    define_value("COLOR_YUV420p2GRAY", cv::ColorConversionCodes::COLOR_YUV420p2GRAY).
    define_value("COLOR_YUV2RGB_UYVY", cv::ColorConversionCodes::COLOR_YUV2RGB_UYVY).
    define_value("COLOR_YUV2BGR_UYVY", cv::ColorConversionCodes::COLOR_YUV2BGR_UYVY).
    define_value("COLOR_YUV2RGB_Y422", cv::ColorConversionCodes::COLOR_YUV2RGB_Y422).
    define_value("COLOR_YUV2BGR_Y422", cv::ColorConversionCodes::COLOR_YUV2BGR_Y422).
    define_value("COLOR_YUV2RGB_UYNV", cv::ColorConversionCodes::COLOR_YUV2RGB_UYNV).
    define_value("COLOR_YUV2BGR_UYNV", cv::ColorConversionCodes::COLOR_YUV2BGR_UYNV).
    define_value("COLOR_YUV2RGBA_UYVY", cv::ColorConversionCodes::COLOR_YUV2RGBA_UYVY).
    define_value("COLOR_YUV2BGRA_UYVY", cv::ColorConversionCodes::COLOR_YUV2BGRA_UYVY).
    define_value("COLOR_YUV2RGBA_Y422", cv::ColorConversionCodes::COLOR_YUV2RGBA_Y422).
    define_value("COLOR_YUV2BGRA_Y422", cv::ColorConversionCodes::COLOR_YUV2BGRA_Y422).
    define_value("COLOR_YUV2RGBA_UYNV", cv::ColorConversionCodes::COLOR_YUV2RGBA_UYNV).
    define_value("COLOR_YUV2BGRA_UYNV", cv::ColorConversionCodes::COLOR_YUV2BGRA_UYNV).
    define_value("COLOR_YUV2RGB_YUY2", cv::ColorConversionCodes::COLOR_YUV2RGB_YUY2).
    define_value("COLOR_YUV2BGR_YUY2", cv::ColorConversionCodes::COLOR_YUV2BGR_YUY2).
    define_value("COLOR_YUV2RGB_YVYU", cv::ColorConversionCodes::COLOR_YUV2RGB_YVYU).
    define_value("COLOR_YUV2BGR_YVYU", cv::ColorConversionCodes::COLOR_YUV2BGR_YVYU).
    define_value("COLOR_YUV2RGB_YUYV", cv::ColorConversionCodes::COLOR_YUV2RGB_YUYV).
    define_value("COLOR_YUV2BGR_YUYV", cv::ColorConversionCodes::COLOR_YUV2BGR_YUYV).
    define_value("COLOR_YUV2RGB_YUNV", cv::ColorConversionCodes::COLOR_YUV2RGB_YUNV).
    define_value("COLOR_YUV2BGR_YUNV", cv::ColorConversionCodes::COLOR_YUV2BGR_YUNV).
    define_value("COLOR_YUV2RGBA_YUY2", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUY2).
    define_value("COLOR_YUV2BGRA_YUY2", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUY2).
    define_value("COLOR_YUV2RGBA_YVYU", cv::ColorConversionCodes::COLOR_YUV2RGBA_YVYU).
    define_value("COLOR_YUV2BGRA_YVYU", cv::ColorConversionCodes::COLOR_YUV2BGRA_YVYU).
    define_value("COLOR_YUV2RGBA_YUYV", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUYV).
    define_value("COLOR_YUV2BGRA_YUYV", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUYV).
    define_value("COLOR_YUV2RGBA_YUNV", cv::ColorConversionCodes::COLOR_YUV2RGBA_YUNV).
    define_value("COLOR_YUV2BGRA_YUNV", cv::ColorConversionCodes::COLOR_YUV2BGRA_YUNV).
    define_value("COLOR_YUV2GRAY_UYVY", cv::ColorConversionCodes::COLOR_YUV2GRAY_UYVY).
    define_value("COLOR_YUV2GRAY_YUY2", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUY2).
    define_value("COLOR_YUV2GRAY_Y422", cv::ColorConversionCodes::COLOR_YUV2GRAY_Y422).
    define_value("COLOR_YUV2GRAY_UYNV", cv::ColorConversionCodes::COLOR_YUV2GRAY_UYNV).
    define_value("COLOR_YUV2GRAY_YVYU", cv::ColorConversionCodes::COLOR_YUV2GRAY_YVYU).
    define_value("COLOR_YUV2GRAY_YUYV", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUYV).
    define_value("COLOR_YUV2GRAY_YUNV", cv::ColorConversionCodes::COLOR_YUV2GRAY_YUNV).
    define_value("COLOR_RGBA2mRGBA", cv::ColorConversionCodes::COLOR_RGBA2mRGBA).
    define_value("COLOR_mRGBA2RGBA", cv::ColorConversionCodes::COLOR_mRGBA2RGBA).
    define_value("COLOR_RGB2YUV_I420", cv::ColorConversionCodes::COLOR_RGB2YUV_I420).
    define_value("COLOR_BGR2YUV_I420", cv::ColorConversionCodes::COLOR_BGR2YUV_I420).
    define_value("COLOR_RGB2YUV_IYUV", cv::ColorConversionCodes::COLOR_RGB2YUV_IYUV).
    define_value("COLOR_BGR2YUV_IYUV", cv::ColorConversionCodes::COLOR_BGR2YUV_IYUV).
    define_value("COLOR_RGBA2YUV_I420", cv::ColorConversionCodes::COLOR_RGBA2YUV_I420).
    define_value("COLOR_BGRA2YUV_I420", cv::ColorConversionCodes::COLOR_BGRA2YUV_I420).
    define_value("COLOR_RGBA2YUV_IYUV", cv::ColorConversionCodes::COLOR_RGBA2YUV_IYUV).
    define_value("COLOR_BGRA2YUV_IYUV", cv::ColorConversionCodes::COLOR_BGRA2YUV_IYUV).
    define_value("COLOR_RGB2YUV_YV12", cv::ColorConversionCodes::COLOR_RGB2YUV_YV12).
    define_value("COLOR_BGR2YUV_YV12", cv::ColorConversionCodes::COLOR_BGR2YUV_YV12).
    define_value("COLOR_RGBA2YUV_YV12", cv::ColorConversionCodes::COLOR_RGBA2YUV_YV12).
    define_value("COLOR_BGRA2YUV_YV12", cv::ColorConversionCodes::COLOR_BGRA2YUV_YV12).
    define_value("COLOR_BayerBG2BGR", cv::ColorConversionCodes::COLOR_BayerBG2BGR).
    define_value("COLOR_BayerGB2BGR", cv::ColorConversionCodes::COLOR_BayerGB2BGR).
    define_value("COLOR_BayerRG2BGR", cv::ColorConversionCodes::COLOR_BayerRG2BGR).
    define_value("COLOR_BayerGR2BGR", cv::ColorConversionCodes::COLOR_BayerGR2BGR).
    define_value("COLOR_BayerRGGB2BGR", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR).
    define_value("COLOR_BayerGRBG2BGR", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR).
    define_value("COLOR_BayerBGGR2BGR", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR).
    define_value("COLOR_BayerGBRG2BGR", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR).
    define_value("COLOR_BayerRGGB2RGB", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB).
    define_value("COLOR_BayerGRBG2RGB", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB).
    define_value("COLOR_BayerBGGR2RGB", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB).
    define_value("COLOR_BayerGBRG2RGB", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB).
    define_value("COLOR_BayerBG2RGB", cv::ColorConversionCodes::COLOR_BayerBG2RGB).
    define_value("COLOR_BayerGB2RGB", cv::ColorConversionCodes::COLOR_BayerGB2RGB).
    define_value("COLOR_BayerRG2RGB", cv::ColorConversionCodes::COLOR_BayerRG2RGB).
    define_value("COLOR_BayerGR2RGB", cv::ColorConversionCodes::COLOR_BayerGR2RGB).
    define_value("COLOR_BayerBG2GRAY", cv::ColorConversionCodes::COLOR_BayerBG2GRAY).
    define_value("COLOR_BayerGB2GRAY", cv::ColorConversionCodes::COLOR_BayerGB2GRAY).
    define_value("COLOR_BayerRG2GRAY", cv::ColorConversionCodes::COLOR_BayerRG2GRAY).
    define_value("COLOR_BayerGR2GRAY", cv::ColorConversionCodes::COLOR_BayerGR2GRAY).
    define_value("COLOR_BayerRGGB2GRAY", cv::ColorConversionCodes::COLOR_BayerRGGB2GRAY).
    define_value("COLOR_BayerGRBG2GRAY", cv::ColorConversionCodes::COLOR_BayerGRBG2GRAY).
    define_value("COLOR_BayerBGGR2GRAY", cv::ColorConversionCodes::COLOR_BayerBGGR2GRAY).
    define_value("COLOR_BayerGBRG2GRAY", cv::ColorConversionCodes::COLOR_BayerGBRG2GRAY).
    define_value("COLOR_BayerBG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerBG2BGR_VNG).
    define_value("COLOR_BayerGB2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGB2BGR_VNG).
    define_value("COLOR_BayerRG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerRG2BGR_VNG).
    define_value("COLOR_BayerGR2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGR2BGR_VNG).
    define_value("COLOR_BayerRGGB2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR_VNG).
    define_value("COLOR_BayerGRBG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR_VNG).
    define_value("COLOR_BayerBGGR2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR_VNG).
    define_value("COLOR_BayerGBRG2BGR_VNG", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR_VNG).
    define_value("COLOR_BayerRGGB2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB_VNG).
    define_value("COLOR_BayerGRBG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB_VNG).
    define_value("COLOR_BayerBGGR2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB_VNG).
    define_value("COLOR_BayerGBRG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB_VNG).
    define_value("COLOR_BayerBG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerBG2RGB_VNG).
    define_value("COLOR_BayerGB2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGB2RGB_VNG).
    define_value("COLOR_BayerRG2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerRG2RGB_VNG).
    define_value("COLOR_BayerGR2RGB_VNG", cv::ColorConversionCodes::COLOR_BayerGR2RGB_VNG).
    define_value("COLOR_BayerBG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerBG2BGR_EA).
    define_value("COLOR_BayerGB2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGB2BGR_EA).
    define_value("COLOR_BayerRG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerRG2BGR_EA).
    define_value("COLOR_BayerGR2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGR2BGR_EA).
    define_value("COLOR_BayerRGGB2BGR_EA", cv::ColorConversionCodes::COLOR_BayerRGGB2BGR_EA).
    define_value("COLOR_BayerGRBG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGRBG2BGR_EA).
    define_value("COLOR_BayerBGGR2BGR_EA", cv::ColorConversionCodes::COLOR_BayerBGGR2BGR_EA).
    define_value("COLOR_BayerGBRG2BGR_EA", cv::ColorConversionCodes::COLOR_BayerGBRG2BGR_EA).
    define_value("COLOR_BayerRGGB2RGB_EA", cv::ColorConversionCodes::COLOR_BayerRGGB2RGB_EA).
    define_value("COLOR_BayerGRBG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGRBG2RGB_EA).
    define_value("COLOR_BayerBGGR2RGB_EA", cv::ColorConversionCodes::COLOR_BayerBGGR2RGB_EA).
    define_value("COLOR_BayerGBRG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGBRG2RGB_EA).
    define_value("COLOR_BayerBG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerBG2RGB_EA).
    define_value("COLOR_BayerGB2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGB2RGB_EA).
    define_value("COLOR_BayerRG2RGB_EA", cv::ColorConversionCodes::COLOR_BayerRG2RGB_EA).
    define_value("COLOR_BayerGR2RGB_EA", cv::ColorConversionCodes::COLOR_BayerGR2RGB_EA).
    define_value("COLOR_BayerBG2BGRA", cv::ColorConversionCodes::COLOR_BayerBG2BGRA).
    define_value("COLOR_BayerGB2BGRA", cv::ColorConversionCodes::COLOR_BayerGB2BGRA).
    define_value("COLOR_BayerRG2BGRA", cv::ColorConversionCodes::COLOR_BayerRG2BGRA).
    define_value("COLOR_BayerGR2BGRA", cv::ColorConversionCodes::COLOR_BayerGR2BGRA).
    define_value("COLOR_BayerRGGB2BGRA", cv::ColorConversionCodes::COLOR_BayerRGGB2BGRA).
    define_value("COLOR_BayerGRBG2BGRA", cv::ColorConversionCodes::COLOR_BayerGRBG2BGRA).
    define_value("COLOR_BayerBGGR2BGRA", cv::ColorConversionCodes::COLOR_BayerBGGR2BGRA).
    define_value("COLOR_BayerGBRG2BGRA", cv::ColorConversionCodes::COLOR_BayerGBRG2BGRA).
    define_value("COLOR_BayerRGGB2RGBA", cv::ColorConversionCodes::COLOR_BayerRGGB2RGBA).
    define_value("COLOR_BayerGRBG2RGBA", cv::ColorConversionCodes::COLOR_BayerGRBG2RGBA).
    define_value("COLOR_BayerBGGR2RGBA", cv::ColorConversionCodes::COLOR_BayerBGGR2RGBA).
    define_value("COLOR_BayerGBRG2RGBA", cv::ColorConversionCodes::COLOR_BayerGBRG2RGBA).
    define_value("COLOR_BayerBG2RGBA", cv::ColorConversionCodes::COLOR_BayerBG2RGBA).
    define_value("COLOR_BayerGB2RGBA", cv::ColorConversionCodes::COLOR_BayerGB2RGBA).
    define_value("COLOR_BayerRG2RGBA", cv::ColorConversionCodes::COLOR_BayerRG2RGBA).
    define_value("COLOR_BayerGR2RGBA", cv::ColorConversionCodes::COLOR_BayerGR2RGBA).
    define_value("COLOR_COLORCVT_MAX", cv::ColorConversionCodes::COLOR_COLORCVT_MAX);
  
  Enum<cv::RectanglesIntersectTypes> rb_cCvRectanglesIntersectTypes = define_enum<cv::RectanglesIntersectTypes>("RectanglesIntersectTypes", rb_mCv).
    define_value("INTERSECT_NONE", cv::RectanglesIntersectTypes::INTERSECT_NONE).
    define_value("INTERSECT_PARTIAL", cv::RectanglesIntersectTypes::INTERSECT_PARTIAL).
    define_value("INTERSECT_FULL", cv::RectanglesIntersectTypes::INTERSECT_FULL);
  
  Enum<cv::LineTypes> rb_cCvLineTypes = define_enum<cv::LineTypes>("LineTypes", rb_mCv).
    define_value("FILLED", cv::LineTypes::FILLED).
    define_value("LINE_4", cv::LineTypes::LINE_4).
    define_value("LINE_8", cv::LineTypes::LINE_8).
    define_value("LINE_AA", cv::LineTypes::LINE_AA);
  
  Enum<cv::HersheyFonts> rb_cCvHersheyFonts = define_enum<cv::HersheyFonts>("HersheyFonts", rb_mCv).
    define_value("FONT_HERSHEY_SIMPLEX", cv::HersheyFonts::FONT_HERSHEY_SIMPLEX).
    define_value("FONT_HERSHEY_PLAIN", cv::HersheyFonts::FONT_HERSHEY_PLAIN).
    define_value("FONT_HERSHEY_DUPLEX", cv::HersheyFonts::FONT_HERSHEY_DUPLEX).
    define_value("FONT_HERSHEY_COMPLEX", cv::HersheyFonts::FONT_HERSHEY_COMPLEX).
    define_value("FONT_HERSHEY_TRIPLEX", cv::HersheyFonts::FONT_HERSHEY_TRIPLEX).
    define_value("FONT_HERSHEY_COMPLEX_SMALL", cv::HersheyFonts::FONT_HERSHEY_COMPLEX_SMALL).
    define_value("FONT_HERSHEY_SCRIPT_SIMPLEX", cv::HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX).
    define_value("FONT_HERSHEY_SCRIPT_COMPLEX", cv::HersheyFonts::FONT_HERSHEY_SCRIPT_COMPLEX).
    define_value("FONT_ITALIC", cv::HersheyFonts::FONT_ITALIC);
  
  Enum<cv::MarkerTypes> rb_cCvMarkerTypes = define_enum<cv::MarkerTypes>("MarkerTypes", rb_mCv).
    define_value("MARKER_CROSS", cv::MarkerTypes::MARKER_CROSS).
    define_value("MARKER_TILTED_CROSS", cv::MarkerTypes::MARKER_TILTED_CROSS).
    define_value("MARKER_STAR", cv::MarkerTypes::MARKER_STAR).
    define_value("MARKER_DIAMOND", cv::MarkerTypes::MARKER_DIAMOND).
    define_value("MARKER_SQUARE", cv::MarkerTypes::MARKER_SQUARE).
    define_value("MARKER_TRIANGLE_UP", cv::MarkerTypes::MARKER_TRIANGLE_UP).
    define_value("MARKER_TRIANGLE_DOWN", cv::MarkerTypes::MARKER_TRIANGLE_DOWN);
  
  Class rb_cCvGeneralizedHough = define_class_under<cv::GeneralizedHough, cv::Algorithm>(rb_mCv, "GeneralizedHough").
    define_method<void(cv::GeneralizedHough::*)(const cv::_InputArray &, cv::Point_<int>)>("set_template", &cv::GeneralizedHough::setTemplate).
    define_method<void(cv::GeneralizedHough::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>)>("set_template", &cv::GeneralizedHough::setTemplate).
    define_method<void(cv::GeneralizedHough::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("detect", &cv::GeneralizedHough::detect).
    define_method<void(cv::GeneralizedHough::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("detect", &cv::GeneralizedHough::detect).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_canny_low_thresh", &cv::GeneralizedHough::setCannyLowThresh).
    define_method<int(cv::GeneralizedHough::*)() const>("get_canny_low_thresh", &cv::GeneralizedHough::getCannyLowThresh).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_canny_high_thresh", &cv::GeneralizedHough::setCannyHighThresh).
    define_method<int(cv::GeneralizedHough::*)() const>("get_canny_high_thresh", &cv::GeneralizedHough::getCannyHighThresh).
    define_method<void(cv::GeneralizedHough::*)(double)>("set_min_dist", &cv::GeneralizedHough::setMinDist).
    define_method<double(cv::GeneralizedHough::*)() const>("get_min_dist", &cv::GeneralizedHough::getMinDist).
    define_method<void(cv::GeneralizedHough::*)(double)>("set_dp", &cv::GeneralizedHough::setDp).
    define_method<double(cv::GeneralizedHough::*)() const>("get_dp", &cv::GeneralizedHough::getDp).
    define_method<void(cv::GeneralizedHough::*)(int)>("set_max_buffer_size", &cv::GeneralizedHough::setMaxBufferSize).
    define_method<int(cv::GeneralizedHough::*)() const>("get_max_buffer_size", &cv::GeneralizedHough::getMaxBufferSize);
  
  Class rb_cCvGeneralizedHoughBallard = define_class_under<cv::GeneralizedHoughBallard, cv::GeneralizedHough>(rb_mCv, "GeneralizedHoughBallard").
    define_method<void(cv::GeneralizedHoughBallard::*)(int)>("set_levels", &cv::GeneralizedHoughBallard::setLevels).
    define_method<int(cv::GeneralizedHoughBallard::*)() const>("get_levels", &cv::GeneralizedHoughBallard::getLevels).
    define_method<void(cv::GeneralizedHoughBallard::*)(int)>("set_votes_threshold", &cv::GeneralizedHoughBallard::setVotesThreshold).
    define_method<int(cv::GeneralizedHoughBallard::*)() const>("get_votes_threshold", &cv::GeneralizedHoughBallard::getVotesThreshold);
  
  Class rb_cCvGeneralizedHoughGuil = define_class_under<cv::GeneralizedHoughGuil, cv::GeneralizedHough>(rb_mCv, "GeneralizedHoughGuil").
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_xi", &cv::GeneralizedHoughGuil::setXi).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_xi", &cv::GeneralizedHoughGuil::getXi).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_levels", &cv::GeneralizedHoughGuil::setLevels).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_levels", &cv::GeneralizedHoughGuil::getLevels).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_angle_epsilon", &cv::GeneralizedHoughGuil::setAngleEpsilon).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_angle_epsilon", &cv::GeneralizedHoughGuil::getAngleEpsilon).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_min_angle", &cv::GeneralizedHoughGuil::setMinAngle).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_min_angle", &cv::GeneralizedHoughGuil::getMinAngle).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_max_angle", &cv::GeneralizedHoughGuil::setMaxAngle).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_max_angle", &cv::GeneralizedHoughGuil::getMaxAngle).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_angle_step", &cv::GeneralizedHoughGuil::setAngleStep).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_angle_step", &cv::GeneralizedHoughGuil::getAngleStep).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_angle_thresh", &cv::GeneralizedHoughGuil::setAngleThresh).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_angle_thresh", &cv::GeneralizedHoughGuil::getAngleThresh).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_min_scale", &cv::GeneralizedHoughGuil::setMinScale).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_min_scale", &cv::GeneralizedHoughGuil::getMinScale).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_max_scale", &cv::GeneralizedHoughGuil::setMaxScale).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_max_scale", &cv::GeneralizedHoughGuil::getMaxScale).
    define_method<void(cv::GeneralizedHoughGuil::*)(double)>("set_scale_step", &cv::GeneralizedHoughGuil::setScaleStep).
    define_method<double(cv::GeneralizedHoughGuil::*)() const>("get_scale_step", &cv::GeneralizedHoughGuil::getScaleStep).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_scale_thresh", &cv::GeneralizedHoughGuil::setScaleThresh).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_scale_thresh", &cv::GeneralizedHoughGuil::getScaleThresh).
    define_method<void(cv::GeneralizedHoughGuil::*)(int)>("set_pos_thresh", &cv::GeneralizedHoughGuil::setPosThresh).
    define_method<int(cv::GeneralizedHoughGuil::*)() const>("get_pos_thresh", &cv::GeneralizedHoughGuil::getPosThresh);
  
  Class rb_cCvCLAHE = define_class_under<cv::CLAHE, cv::Algorithm>(rb_mCv, "CLAHE").
    define_method<void(cv::CLAHE::*)(const cv::_InputArray &, const cv::_OutputArray &)>("apply", &cv::CLAHE::apply).
    define_method<void(cv::CLAHE::*)(double)>("set_clip_limit", &cv::CLAHE::setClipLimit).
    define_method<double(cv::CLAHE::*)() const>("get_clip_limit", &cv::CLAHE::getClipLimit).
    define_method<void(cv::CLAHE::*)(cv::Size_<int>)>("set_tiles_grid_size", &cv::CLAHE::setTilesGridSize).
    define_method<cv::Size_<int>(cv::CLAHE::*)() const>("get_tiles_grid_size", &cv::CLAHE::getTilesGridSize).
    define_method<void(cv::CLAHE::*)()>("collect_garbage", &cv::CLAHE::collectGarbage);
  
  Class rb_cCvSubdiv2D = define_class_under<cv::Subdiv2D>(rb_mCv, "Subdiv2D").
    define_constructor(Constructor<cv::Subdiv2D>()).
    define_constructor(Constructor<cv::Subdiv2D, cv::Rect_<int>>()).
    define_method<void(cv::Subdiv2D::*)(cv::Rect_<int>)>("init_delaunay", &cv::Subdiv2D::initDelaunay).
    define_method<int(cv::Subdiv2D::*)(cv::Point_<float>)>("insert", &cv::Subdiv2D::insert).
    define_method<void(cv::Subdiv2D::*)(const std::vector<cv::Point_<float>>&)>("insert", &cv::Subdiv2D::insert).
    define_method<int(cv::Subdiv2D::*)(cv::Point_<float>, int&, int&)>("locate", &cv::Subdiv2D::locate).
    define_method<int(cv::Subdiv2D::*)(cv::Point_<float>, cv::Point_<float>*)>("find_nearest", &cv::Subdiv2D::findNearest).
    define_method<void(cv::Subdiv2D::*)(std::vector<cv::Vec<float, 4>>&) const>("get_edge_list", &cv::Subdiv2D::getEdgeList).
    define_method<void(cv::Subdiv2D::*)(std::vector<int>&) const>("get_leading_edge_list", &cv::Subdiv2D::getLeadingEdgeList).
    define_method<void(cv::Subdiv2D::*)(std::vector<cv::Vec<float, 6>>&) const>("get_triangle_list", &cv::Subdiv2D::getTriangleList).
    define_method<void(cv::Subdiv2D::*)(const std::vector<int>&, std::vector<std::vector<cv::Point_<float>>>&, std::vector<cv::Point_<float>>&)>("get_voronoi_facet_list", &cv::Subdiv2D::getVoronoiFacetList).
    define_method<cv::Point_<float>(cv::Subdiv2D::*)(int, int*) const>("get_vertex", &cv::Subdiv2D::getVertex).
    define_method<int(cv::Subdiv2D::*)(int, int) const>("get_edge", &cv::Subdiv2D::getEdge).
    define_method<int(cv::Subdiv2D::*)(int) const>("next_edge", &cv::Subdiv2D::nextEdge).
    define_method<int(cv::Subdiv2D::*)(int, int) const>("rotate_edge", &cv::Subdiv2D::rotateEdge).
    define_method<int(cv::Subdiv2D::*)(int) const>("sym_edge", &cv::Subdiv2D::symEdge).
    define_method<int(cv::Subdiv2D::*)(int, cv::Point_<float>*) const>("edge_org", &cv::Subdiv2D::edgeOrg).
    define_method<int(cv::Subdiv2D::*)(int, cv::Point_<float>*) const>("edge_dst", &cv::Subdiv2D::edgeDst);
  
  Class rb_cCvSubdiv2DVertex = define_class_under<cv::Subdiv2D::Vertex>(rb_cCvSubdiv2D, "Vertex").
    define_constructor(Constructor<cv::Subdiv2D::Vertex>()).
    define_constructor(Constructor<cv::Subdiv2D::Vertex, cv::Point_<float>, bool, int>()).
    define_method<bool(cv::Subdiv2D::Vertex::*)() const>("isvirtual", &cv::Subdiv2D::Vertex::isvirtual).
    define_method<bool(cv::Subdiv2D::Vertex::*)() const>("isfree", &cv::Subdiv2D::Vertex::isfree).
    define_attr("first_edge", &cv::Subdiv2D::Vertex::firstEdge).
    define_attr("type", &cv::Subdiv2D::Vertex::type).
    define_attr("pt", &cv::Subdiv2D::Vertex::pt);
  
  Class rb_cCvSubdiv2DQuadEdge = define_class_under<cv::Subdiv2D::QuadEdge>(rb_cCvSubdiv2D, "QuadEdge").
    define_constructor(Constructor<cv::Subdiv2D::QuadEdge>()).
    define_constructor(Constructor<cv::Subdiv2D::QuadEdge, int>()).
    define_method<bool(cv::Subdiv2D::QuadEdge::*)() const>("isfree", &cv::Subdiv2D::QuadEdge::isfree).
    define_attr("next", &cv::Subdiv2D::QuadEdge::next).
    define_attr("pt", &cv::Subdiv2D::QuadEdge::pt);
  
  
  
  Class rb_cCvLineSegmentDetector = define_class_under<cv::LineSegmentDetector, cv::Algorithm>(rb_mCv, "LineSegmentDetector").
    define_method<void(cv::LineSegmentDetector::*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &)>("detect", &cv::LineSegmentDetector::detect).
    define_method<void(cv::LineSegmentDetector::*)(const cv::_InputOutputArray &, const cv::_InputArray &)>("draw_segments", &cv::LineSegmentDetector::drawSegments).
    define_method<int(cv::LineSegmentDetector::*)(const cv::Size_<int>&, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &)>("compare_segments", &cv::LineSegmentDetector::compareSegments);
  
  rb_mCv.define_module_function<cv::Ptr<cv::LineSegmentDetector>(*)(int, double, double, double, double, double, double, int)>("create_line_segment_detector", &cv::createLineSegmentDetector);
  
  rb_mCv.define_module_function<cv::Mat(*)(int, double, int)>("get_gaussian_kernel", &cv::getGaussianKernel);
  
  rb_mCv.define_module_function<void(*)(const cv::_OutputArray &, const cv::_OutputArray &, int, int, int, bool, int)>("get_deriv_kernels", &cv::getDerivKernels);
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::Size_<int>, double, double, double, double, double, int)>("get_gabor_kernel", &cv::getGaborKernel);
  
  rb_mCv.define_module_function<cv::Mat(*)(int, cv::Size_<int>, cv::Point_<int>)>("get_structuring_element", &cv::getStructuringElement);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("median_blur", &cv::medianBlur);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, double, double, int)>("gaussian_blur", &cv::GaussianBlur);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, int)>("bilateral_filter", &cv::bilateralFilter);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, cv::Size_<int>, cv::Point_<int>, bool, int)>("box_filter", &cv::boxFilter);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, cv::Size_<int>, cv::Point_<int>, bool, int)>("sqr_box_filter", &cv::sqrBoxFilter);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, cv::Point_<int>, int)>("blur", &cv::blur);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>)>("stack_blur", &cv::stackBlur);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, cv::Point_<int>, double, int)>("filter2_d", &cv::filter2D);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, const cv::_InputArray &, cv::Point_<int>, double, int)>("sep_filter2_d", &cv::sepFilter2D);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, int, double, double, int)>("sobel", &cv::Sobel);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int)>("spatial_gradient", &cv::spatialGradient);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int, double, double, int)>("scharr", &cv::Scharr);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, double, double, int)>("laplacian", &cv::Laplacian);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, bool)>("canny", &cv::Canny);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, double, double, bool)>("canny", &cv::Canny);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("corner_min_eigen_val", &cv::cornerMinEigenVal);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, double, int)>("corner_harris", &cv::cornerHarris);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("corner_eigen_vals_and_vecs", &cv::cornerEigenValsAndVecs);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("pre_corner_detect", &cv::preCornerDetect);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, cv::Size_<int>, cv::Size_<int>, cv::TermCriteria)>("corner_sub_pix", &cv::cornerSubPix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, const cv::_InputArray &, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, const cv::_InputArray &, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, const cv::_InputArray &, const cv::_OutputArray &, int, int, bool, double)>("good_features_to_track", &cv::goodFeaturesToTrack);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, double, double, double, double)>("hough_lines", &cv::HoughLines);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, double, double)>("hough_lines_p", &cv::HoughLinesP);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, double, double, double, double, double, double)>("hough_lines_point_set", &cv::HoughLinesPointSet);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, double, double, int, int)>("hough_circles", &cv::HoughCircles);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Point_<int>, int, int, const cv::Scalar_<double>&)>("erode", &cv::erode);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Point_<int>, int, int, const cv::Scalar_<double>&)>("dilate", &cv::dilate);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &, cv::Point_<int>, int, int, const cv::Scalar_<double>&)>("morphology_ex", &cv::morphologyEx);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, double, double, int)>("resize", &cv::resize);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Size_<int>, int, int, const cv::Scalar_<double>&)>("warp_affine", &cv::warpAffine);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, cv::Size_<int>, int, int, const cv::Scalar_<double>&)>("warp_perspective", &cv::warpPerspective);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &, const cv::_InputArray &, int, int, const cv::Scalar_<double>&)>("remap", &cv::remap);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, bool)>("convert_maps", &cv::convertMaps);
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::Point_<float>, double, double)>("get_rotation_matrix2_d", &cv::getRotationMatrix2D);
  
  rb_mCv.define_module_function<cv::Matx<double, 2, 3>(*)(cv::Point_<float>, double, double)>("get_rotation_matrix2_d_", &cv::getRotationMatrix2D_);
  
  rb_mCv.define_module_function<cv::Mat(*)(cv::Point_<float>, double, double)>("get_rotation_matrix2_d", &cv::getRotationMatrix2D);
  
  rb_mCv.define_module_function<cv::Mat(*)(const Point2f[], const Point2f[])>("get_affine_transform", &cv::getAffineTransform);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("invert_affine_transform", &cv::invertAffineTransform);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &, int)>("get_perspective_transform", &cv::getPerspectiveTransform);
  
  rb_mCv.define_module_function<cv::Mat(*)(const Point2f[], const Point2f[], int)>("get_perspective_transform", &cv::getPerspectiveTransform);
  
  rb_mCv.define_module_function<cv::Mat(*)(const cv::_InputArray &, const cv::_InputArray &)>("get_affine_transform", &cv::getAffineTransform);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, cv::Size_<int>, cv::Point_<float>, const cv::_OutputArray &, int)>("get_rect_sub_pix", &cv::getRectSubPix);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Point_<float>, double, int)>("log_polar", &cv::logPolar);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Point_<float>, double, int)>("linear_polar", &cv::linearPolar);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, cv::Size_<int>, cv::Point_<float>, double, int)>("warp_polar", &cv::warpPolar);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int)>("integral", &cv::integral);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("integral", &cv::integral);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int)>("integral", &cv::integral);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputArray &)>("accumulate", &cv::accumulate);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputArray &)>("accumulate_square", &cv::accumulateSquare);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &, const cv::_InputArray &)>("accumulate_product", &cv::accumulateProduct);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, double, const cv::_InputArray &)>("accumulate_weighted", &cv::accumulateWeighted);
  
  rb_mCv.define_module_function<cv::Point_<double>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, double*)>("phase_correlate", &cv::phaseCorrelate);
  
  rb_mCv.define_module_function<void(*)(const cv::_OutputArray &, cv::Size_<int>, int)>("create_hanning_window", &cv::createHanningWindow);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, bool)>("div_spectrums", &cv::divSpectrums);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int)>("threshold", &cv::threshold);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, int, int, int, double)>("adaptive_threshold", &cv::adaptiveThreshold);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::Size_<int>&, int)>("pyr_down", &cv::pyrDown);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::Size_<int>&, int)>("pyr_up", &cv::pyrUp);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("build_pyramid", &cv::buildPyramid);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::_InputArray &, const cv::_OutputArray &, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::_InputArray &, cv::SparseMat&, int, const int*, const float**, bool, bool)>("calc_hist", &cv::calcHist);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<int>&, const cv::_InputArray &, const cv::_OutputArray &, const std::vector<int>&, const std::vector<float>&, bool)>("calc_hist", &cv::calcHist);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::_InputArray &, const cv::_OutputArray &, const float**, double, bool)>("calc_back_project", &cv::calcBackProject);
  
  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, const int*, const cv::SparseMat&, const cv::_OutputArray &, const float**, double, bool)>("calc_back_project", &cv::calcBackProject);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const std::vector<int>&, const cv::_InputArray &, const cv::_OutputArray &, const std::vector<float>&, double)>("calc_back_project", &cv::calcBackProject);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, int)>("compare_hist", &cv::compareHist);
  
  rb_mCv.define_module_function<double(*)(const cv::SparseMat&, const cv::SparseMat&, int)>("compare_hist", &cv::compareHist);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &)>("equalize_hist", &cv::equalizeHist);
  
  rb_mCv.define_module_function<cv::Ptr<cv::CLAHE>(*)(double, cv::Size_<int>)>("create_clahe", &cv::createCLAHE);
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &, int, const cv::_InputArray &, float*, const cv::_OutputArray &)>("emd", &cv::EMD);
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &, int, const cv::_InputArray &, cv::Ptr<float>, const cv::_OutputArray &)>("wrapper_emd", &cv::wrapperEMD);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &)>("watershed", &cv::watershed);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, double, int, cv::TermCriteria)>("pyr_mean_shift_filtering", &cv::pyrMeanShiftFiltering);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputOutputArray &, cv::Rect_<int>, const cv::_InputOutputArray &, const cv::_InputOutputArray &, int, int)>("grab_cut", &cv::grabCut);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int, int)>("distance_transform", &cv::distanceTransform);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("distance_transform", &cv::distanceTransform);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputOutputArray &, const cv::_InputOutputArray &, cv::Point_<int>, cv::Scalar_<double>, cv::Rect_<int>*, cv::Scalar_<double>, cv::Scalar_<double>, int)>("flood_fill", &cv::floodFill);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputOutputArray &, cv::Point_<int>, cv::Scalar_<double>, cv::Rect_<int>*, cv::Scalar_<double>, cv::Scalar_<double>, int)>("flood_fill", &cv::floodFill);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("blend_linear", &cv::blendLinear);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("cvt_color", &cv::cvtColor);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int)>("cvt_color_two_plane", &cv::cvtColorTwoPlane);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("demosaicing", &cv::demosaicing);
  
  rb_mCv.define_module_function<cv::Moments(*)(const cv::_InputArray &, bool)>("moments", &cv::moments);
  
  rb_mCv.define_module_function<void(*)(const cv::Moments&, double[7])>("hu_moments", &cv::HuMoments);
  
  rb_mCv.define_module_function<void(*)(const cv::Moments&, const cv::_OutputArray &)>("hu_moments", &cv::HuMoments);
  
  Enum<cv::TemplateMatchModes> rb_cCvTemplateMatchModes = define_enum<cv::TemplateMatchModes>("TemplateMatchModes", rb_mCv).
    define_value("TM_SQDIFF", cv::TemplateMatchModes::TM_SQDIFF).
    define_value("TM_SQDIFF_NORMED", cv::TemplateMatchModes::TM_SQDIFF_NORMED).
    define_value("TM_CCORR", cv::TemplateMatchModes::TM_CCORR).
    define_value("TM_CCORR_NORMED", cv::TemplateMatchModes::TM_CCORR_NORMED).
    define_value("TM_CCOEFF", cv::TemplateMatchModes::TM_CCOEFF).
    define_value("TM_CCOEFF_NORMED", cv::TemplateMatchModes::TM_CCOEFF_NORMED);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, int, const cv::_InputArray &)>("match_template", &cv::matchTemplate);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, int)>("connected_components", &cv::connectedComponents);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int)>("connected_components", &cv::connectedComponents);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int, int)>("connected_components_with_stats", &cv::connectedComponentsWithStats);
  
  rb_mCv.define_module_function<int(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int)>("connected_components_with_stats", &cv::connectedComponentsWithStats);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_OutputArray &, int, int, cv::Point_<int>)>("find_contours", &cv::findContours);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, int, cv::Point_<int>)>("find_contours", &cv::findContours);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, double, bool)>("approx_poly_dp", &cv::approxPolyDP);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, bool)>("arc_length", &cv::arcLength);
  
  rb_mCv.define_module_function<cv::Rect_<int>(*)(const cv::_InputArray &)>("bounding_rect", &cv::boundingRect);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, bool)>("contour_area", &cv::contourArea);
  
  rb_mCv.define_module_function<cv::RotatedRect(*)(const cv::_InputArray &)>("min_area_rect", &cv::minAreaRect);
  
  rb_mCv.define_module_function<void(*)(cv::RotatedRect, const cv::_OutputArray &)>("box_points", &cv::boxPoints);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, cv::Point_<float>&, float&)>("min_enclosing_circle", &cv::minEnclosingCircle);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_OutputArray &)>("min_enclosing_triangle", &cv::minEnclosingTriangle);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, const cv::_InputArray &, int, double)>("match_shapes", &cv::matchShapes);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, bool, bool)>("convex_hull", &cv::convexHull);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &)>("convexity_defects", &cv::convexityDefects);
  
  rb_mCv.define_module_function<bool(*)(const cv::_InputArray &)>("is_contour_convex", &cv::isContourConvex);
  
  rb_mCv.define_module_function<float(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_OutputArray &, bool)>("intersect_convex_convex", &cv::intersectConvexConvex);
  
  rb_mCv.define_module_function<cv::RotatedRect(*)(const cv::_InputArray &)>("fit_ellipse", &cv::fitEllipse);
  
  rb_mCv.define_module_function<cv::RotatedRect(*)(const cv::_InputArray &)>("fit_ellipse_ams", &cv::fitEllipseAMS);
  
  rb_mCv.define_module_function<cv::RotatedRect(*)(const cv::_InputArray &)>("fit_ellipse_direct", &cv::fitEllipseDirect);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int, double, double, double)>("fit_line", &cv::fitLine);
  
  rb_mCv.define_module_function<double(*)(const cv::_InputArray &, cv::Point_<float>, bool)>("point_polygon_test", &cv::pointPolygonTest);
  
  rb_mCv.define_module_function<int(*)(const cv::RotatedRect&, const cv::RotatedRect&, const cv::_OutputArray &)>("rotated_rectangle_intersection", &cv::rotatedRectangleIntersection);
  
  rb_mCv.define_module_function<cv::Ptr<cv::GeneralizedHoughBallard>(*)()>("create_generalized_hough_ballard", &cv::createGeneralizedHoughBallard);
  
  rb_mCv.define_module_function<cv::Ptr<cv::GeneralizedHoughGuil>(*)()>("create_generalized_hough_guil", &cv::createGeneralizedHoughGuil);
  
  Enum<cv::ColormapTypes> rb_cCvColormapTypes = define_enum<cv::ColormapTypes>("ColormapTypes", rb_mCv).
    define_value("COLORMAP_AUTUMN", cv::ColormapTypes::COLORMAP_AUTUMN).
    define_value("COLORMAP_BONE", cv::ColormapTypes::COLORMAP_BONE).
    define_value("COLORMAP_JET", cv::ColormapTypes::COLORMAP_JET).
    define_value("COLORMAP_WINTER", cv::ColormapTypes::COLORMAP_WINTER).
    define_value("COLORMAP_RAINBOW", cv::ColormapTypes::COLORMAP_RAINBOW).
    define_value("COLORMAP_OCEAN", cv::ColormapTypes::COLORMAP_OCEAN).
    define_value("COLORMAP_SUMMER", cv::ColormapTypes::COLORMAP_SUMMER).
    define_value("COLORMAP_SPRING", cv::ColormapTypes::COLORMAP_SPRING).
    define_value("COLORMAP_COOL", cv::ColormapTypes::COLORMAP_COOL).
    define_value("COLORMAP_HSV", cv::ColormapTypes::COLORMAP_HSV).
    define_value("COLORMAP_PINK", cv::ColormapTypes::COLORMAP_PINK).
    define_value("COLORMAP_HOT", cv::ColormapTypes::COLORMAP_HOT).
    define_value("COLORMAP_PARULA", cv::ColormapTypes::COLORMAP_PARULA).
    define_value("COLORMAP_MAGMA", cv::ColormapTypes::COLORMAP_MAGMA).
    define_value("COLORMAP_INFERNO", cv::ColormapTypes::COLORMAP_INFERNO).
    define_value("COLORMAP_PLASMA", cv::ColormapTypes::COLORMAP_PLASMA).
    define_value("COLORMAP_VIRIDIS", cv::ColormapTypes::COLORMAP_VIRIDIS).
    define_value("COLORMAP_CIVIDIS", cv::ColormapTypes::COLORMAP_CIVIDIS).
    define_value("COLORMAP_TWILIGHT", cv::ColormapTypes::COLORMAP_TWILIGHT).
    define_value("COLORMAP_TWILIGHT_SHIFTED", cv::ColormapTypes::COLORMAP_TWILIGHT_SHIFTED).
    define_value("COLORMAP_TURBO", cv::ColormapTypes::COLORMAP_TURBO).
    define_value("COLORMAP_DEEPGREEN", cv::ColormapTypes::COLORMAP_DEEPGREEN);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, int)>("apply_color_map", &cv::applyColorMap);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputArray &, const cv::_OutputArray &, const cv::_InputArray &)>("apply_color_map", &cv::applyColorMap);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, cv::Point_<int>, const cv::Scalar_<double>&, int, int, int)>("line", &cv::line);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, cv::Point_<int>, const cv::Scalar_<double>&, int, int, int, double)>("arrowed_line", &cv::arrowedLine);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, cv::Point_<int>, const cv::Scalar_<double>&, int, int, int)>("rectangle", &cv::rectangle);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Rect_<int>, const cv::Scalar_<double>&, int, int, int)>("rectangle", &cv::rectangle);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, int, const cv::Scalar_<double>&, int, int, int)>("circle", &cv::circle);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, cv::Size_<int>, double, double, double, const cv::Scalar_<double>&, int, int, int)>("ellipse", &cv::ellipse);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::RotatedRect&, const cv::Scalar_<double>&, int, int)>("ellipse", &cv::ellipse);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, cv::Point_<int>, const cv::Scalar_<double>&, int, int, int, int)>("draw_marker", &cv::drawMarker);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::Scalar_<double>&, int, int)>("fill_convex_poly", &cv::fillConvexPoly);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::Point_<int>*, int, const cv::Scalar_<double>&, int, int)>("fill_convex_poly", &cv::fillConvexPoly);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, const cv::Scalar_<double>&, int, int, cv::Point_<int>)>("fill_poly", &cv::fillPoly);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::Point_<int>**, const int*, int, const cv::Scalar_<double>&, int, int, cv::Point_<int>)>("fill_poly", &cv::fillPoly);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, bool, const cv::Scalar_<double>&, int, int, int)>("polylines", &cv::polylines);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::Point_<int>**, const int*, int, bool, const cv::Scalar_<double>&, int, int, int)>("polylines", &cv::polylines);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const cv::_InputArray &, int, const cv::Scalar_<double>&, int, int, const cv::_InputArray &, int, cv::Point_<int>)>("draw_contours", &cv::drawContours);
  
  rb_mCv.define_module_function<bool(*)(cv::Size_<int>, cv::Point_<int>&, cv::Point_<int>&)>("clip_line", &cv::clipLine);
  
  rb_mCv.define_module_function<bool(*)(cv::Size_<long long>, cv::Point_<long long>&, cv::Point_<long long>&)>("clip_line", &cv::clipLine);
  
  rb_mCv.define_module_function<bool(*)(cv::Rect_<int>, cv::Point_<int>&, cv::Point_<int>&)>("clip_line", &cv::clipLine);
  
  rb_mCv.define_module_function<void(*)(cv::Point_<int>, cv::Size_<int>, int, int, int, int, std::vector<cv::Point_<int>>&)>("ellipse2_poly", &cv::ellipse2Poly);
  
  rb_mCv.define_module_function<void(*)(cv::Point_<double>, cv::Size_<double>, int, int, int, int, std::vector<cv::Point_<double>>&)>("ellipse2_poly", &cv::ellipse2Poly);
  
  rb_mCv.define_module_function<void(*)(const cv::_InputOutputArray &, const std::basic_string<char>&, cv::Point_<int>, int, double, cv::Scalar_<double>, int, int, bool)>("put_text", &cv::putText);
  
  rb_mCv.define_module_function<cv::Size_<int>(*)(const std::basic_string<char>&, int, double, int, int*)>("get_text_size", &cv::getTextSize);
  
  rb_mCv.define_module_function<double(*)(const int, const int, const int)>("get_font_scale_from_height", &cv::getFontScaleFromHeight);
  
  Class rb_cCvLineIterator = define_class_under<cv::LineIterator>(rb_mCv, "LineIterator").
    define_constructor(Constructor<cv::LineIterator, const cv::Mat&, cv::Point_<int>, cv::Point_<int>, int, bool>()).
    define_constructor(Constructor<cv::LineIterator, cv::Point_<int>, cv::Point_<int>, int, bool>()).
    define_constructor(Constructor<cv::LineIterator, cv::Size_<int>, cv::Point_<int>, cv::Point_<int>, int, bool>()).
    define_constructor(Constructor<cv::LineIterator, cv::Rect_<int>, cv::Point_<int>, cv::Point_<int>, int, bool>()).
    define_method<void(cv::LineIterator::*)(const cv::Mat*, cv::Rect_<int>, cv::Point_<int>, cv::Point_<int>, int, bool)>("init", &cv::LineIterator::init).
    define_method<unsigned char*(cv::LineIterator::*)()>("operator*", &cv::LineIterator::operator*).
    define_method<cv::LineIterator&(cv::LineIterator::*)()>("operator++", &cv::LineIterator::operator++).
    define_method<cv::LineIterator(cv::LineIterator::*)(int)>("operator++", &cv::LineIterator::operator++).
    define_method<cv::Point_<int>(cv::LineIterator::*)() const>("pos", &cv::LineIterator::pos).
    define_attr("ptr", &cv::LineIterator::ptr).
    define_attr("ptr0", &cv::LineIterator::ptr0).
    define_attr("step", &cv::LineIterator::step).
    define_attr("elem_size", &cv::LineIterator::elemSize).
    define_attr("err", &cv::LineIterator::err).
    define_attr("count", &cv::LineIterator::count).
    define_attr("minus_delta", &cv::LineIterator::minusDelta).
    define_attr("plus_delta", &cv::LineIterator::plusDelta).
    define_attr("minus_step", &cv::LineIterator::minusStep).
    define_attr("plus_step", &cv::LineIterator::plusStep).
    define_attr("minus_shift", &cv::LineIterator::minusShift).
    define_attr("plus_shift", &cv::LineIterator::plusShift).
    define_attr("p", &cv::LineIterator::p).
    define_attr("ptmode", &cv::LineIterator::ptmode);
}