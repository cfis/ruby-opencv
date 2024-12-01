#include <opencv2/ccalib/randpattern.hpp>
#include "randpattern-rb.hpp"

using namespace Rice;

extern "C"
void Init_Randpattern()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvRandpattern = define_module_under(rb_mCv, "Randpattern");
  
  Class rb_cCvRandpatternRandomPatternCornerFinder = define_class_under<cv::randpattern::RandomPatternCornerFinder>(rb_mCvRandpattern, "RandomPatternCornerFinder").
    define_constructor(Constructor<cv::randpattern::RandomPatternCornerFinder, float, float, int, int, int, int, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::DescriptorMatcher>>()).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(const cv::Mat&)>("load_pattern", &cv::randpattern::RandomPatternCornerFinder::loadPattern).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(const cv::Mat&, const std::vector<cv::KeyPoint>&, const cv::Mat&)>("load_pattern", &cv::randpattern::RandomPatternCornerFinder::loadPattern).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(std::vector<cv::Mat>)>("compute_object_image_points", &cv::randpattern::RandomPatternCornerFinder::computeObjectImagePoints).
    define_method<std::vector<cv::Mat>(cv::randpattern::RandomPatternCornerFinder::*)(cv::Mat)>("compute_object_image_points_for_single", &cv::randpattern::RandomPatternCornerFinder::computeObjectImagePointsForSingle).
    define_method<const std::vector<cv::Mat>&(cv::randpattern::RandomPatternCornerFinder::*)()>("get_object_points", &cv::randpattern::RandomPatternCornerFinder::getObjectPoints).
    define_method<const std::vector<cv::Mat>&(cv::randpattern::RandomPatternCornerFinder::*)()>("get_image_points", &cv::randpattern::RandomPatternCornerFinder::getImagePoints);
  
  Class rb_cCvRandpatternRandomPatternGenerator = define_class_under<cv::randpattern::RandomPatternGenerator>(rb_mCvRandpattern, "RandomPatternGenerator").
    define_constructor(Constructor<cv::randpattern::RandomPatternGenerator, int, int>()).
    define_method<void(cv::randpattern::RandomPatternGenerator::*)()>("generate_pattern", &cv::randpattern::RandomPatternGenerator::generatePattern).
    define_method<cv::Mat(cv::randpattern::RandomPatternGenerator::*)()>("get_pattern", &cv::randpattern::RandomPatternGenerator::getPattern);
}