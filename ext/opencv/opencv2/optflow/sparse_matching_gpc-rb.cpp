#include <opencv2/optflow/sparse_matching_gpc.hpp>
#include "sparse_matching_gpc-rb.hpp"

using namespace Rice;

extern "C"
void Init_SparseMatchingGpc()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");
  
  Class rb_cCvOptflowGPCPatchDescriptor = define_class_under<cv::optflow::GPCPatchDescriptor>(rb_mCvOptflow, "GPCPatchDescriptor").
    define_attr("feature", &cv::optflow::GPCPatchDescriptor::feature).
    define_method<double(cv::optflow::GPCPatchDescriptor::*)(const cv::Vec<double, 18>&) const>("dot", &cv::optflow::GPCPatchDescriptor::dot).
    define_method<void(cv::optflow::GPCPatchDescriptor::*)()>("mark_as_separated", &cv::optflow::GPCPatchDescriptor::markAsSeparated).
    define_method<bool(cv::optflow::GPCPatchDescriptor::*)() const>("is_separated", &cv::optflow::GPCPatchDescriptor::isSeparated);
  
  Class rb_cCvOptflowGPCPatchSample = define_class_under<cv::optflow::GPCPatchSample>(rb_mCvOptflow, "GPCPatchSample").
    define_attr("ref", &cv::optflow::GPCPatchSample::ref).
    define_attr("pos", &cv::optflow::GPCPatchSample::pos).
    define_attr("neg", &cv::optflow::GPCPatchSample::neg).
    define_method<void(cv::optflow::GPCPatchSample::*)(bool&, bool&, bool&, const cv::Vec<double, 18>&, double) const>("get_directions", &cv::optflow::GPCPatchSample::getDirections);
  
  Enum<cv::optflow::GPCDescType> rb_cCvOptflowGPCDescType = define_enum<cv::optflow::GPCDescType>("GPCDescType", rb_mCvOptflow).
    define_value("GPC_DESCRIPTOR_DCT", cv::optflow::GPCDescType::GPC_DESCRIPTOR_DCT).
    define_value("GPC_DESCRIPTOR_WHT", cv::optflow::GPCDescType::GPC_DESCRIPTOR_WHT);
  
  Class rb_cCvOptflowGPCTrainingSamples = define_class_under<cv::optflow::GPCTrainingSamples>(rb_mCvOptflow, "GPCTrainingSamples").
    define_singleton_function<cv::Ptr<cv::optflow::GPCTrainingSamples>(*)(const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, int)>("create", &cv::optflow::GPCTrainingSamples::create).
    define_singleton_function<cv::Ptr<cv::optflow::GPCTrainingSamples>(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, int)>("create", &cv::optflow::GPCTrainingSamples::create).
    define_method<unsigned long long(cv::optflow::GPCTrainingSamples::*)() const>("size", &cv::optflow::GPCTrainingSamples::size).
    define_method<int(cv::optflow::GPCTrainingSamples::*)() const>("type", &cv::optflow::GPCTrainingSamples::type);
  
  Class rb_cCvOptflowGPCTrainingParams = define_class_under<cv::optflow::GPCTrainingParams>(rb_mCvOptflow, "GPCTrainingParams").
    define_attr("max_tree_depth", &cv::optflow::GPCTrainingParams::maxTreeDepth).
    define_attr("min_number_of_samples", &cv::optflow::GPCTrainingParams::minNumberOfSamples).
    define_attr("descriptor_type", &cv::optflow::GPCTrainingParams::descriptorType).
    define_attr("print_progress", &cv::optflow::GPCTrainingParams::printProgress).
    define_constructor(Constructor<cv::optflow::GPCTrainingParams, unsigned int, int, cv::optflow::GPCDescType, bool>()).
    define_method<bool(cv::optflow::GPCTrainingParams::*)() const>("check", &cv::optflow::GPCTrainingParams::check);
  
  Class rb_cCvOptflowGPCMatchingParams = define_class_under<cv::optflow::GPCMatchingParams>(rb_mCvOptflow, "GPCMatchingParams").
    define_attr("use_open_cl", &cv::optflow::GPCMatchingParams::useOpenCL).
    define_constructor(Constructor<cv::optflow::GPCMatchingParams, bool>()).
    define_constructor(Constructor<cv::optflow::GPCMatchingParams, const cv::optflow::GPCMatchingParams&>());
  
  Class rb_cCvOptflowGPCTree = define_class_under<cv::optflow::GPCTree, cv::Algorithm>(rb_mCvOptflow, "GPCTree").
    define_method<void(cv::optflow::GPCTree::*)(cv::optflow::GPCTrainingSamples&, const cv::optflow::GPCTrainingParams)>("train", &cv::optflow::GPCTree::train).
    define_method<void(cv::optflow::GPCTree::*)(cv::FileStorage&) const>("write", &cv::optflow::GPCTree::write).
    define_method<void(cv::optflow::GPCTree::*)(const cv::FileNode&)>("read", &cv::optflow::GPCTree::read).
    define_method<unsigned int(cv::optflow::GPCTree::*)(const cv::optflow::GPCPatchDescriptor&) const>("find_leaf_for_patch", &cv::optflow::GPCTree::findLeafForPatch).
    define_singleton_function<cv::Ptr<cv::optflow::GPCTree>(*)()>("create", &cv::optflow::GPCTree::create).
    define_method<bool(cv::optflow::GPCTree::*)(const cv::optflow::GPCTree&) const>("operator==", &cv::optflow::GPCTree::operator==).
    define_method<int(cv::optflow::GPCTree::*)() const>("get_descriptor_type", &cv::optflow::GPCTree::getDescriptorType);
  
  Class rb_cCvOptflowGPCTreeNode = define_class_under<cv::optflow::GPCTree::Node>(rb_cCvOptflowGPCTree, "Node").
    define_attr("coef", &cv::optflow::GPCTree::Node::coef).
    define_attr("rhs", &cv::optflow::GPCTree::Node::rhs).
    define_attr("left", &cv::optflow::GPCTree::Node::left).
    define_attr("right", &cv::optflow::GPCTree::Node::right).
    define_method<bool(cv::optflow::GPCTree::Node::*)(const cv::optflow::GPCTree::Node&) const>("operator==", &cv::optflow::GPCTree::Node::operator==);
  
  Class rb_cCvOptflowGPCDetails = define_class_under<cv::optflow::GPCDetails>(rb_mCvOptflow, "GPCDetails").
    define_singleton_function<void(*)(std::vector<std::pair<cv::Point_<int>, cv::Point_<int>>>&)>("drop_outliers", &cv::optflow::GPCDetails::dropOutliers).
    define_singleton_function<void(*)(const cv::Mat*, std::vector<cv::optflow::GPCPatchDescriptor>&, const cv::optflow::GPCMatchingParams&, int)>("get_all_descriptors_for_image", &cv::optflow::GPCDetails::getAllDescriptorsForImage).
    define_singleton_function<void(*)(unsigned long long, cv::Size_<int>, int&, int&)>("get_coordinates_from_index", &cv::optflow::GPCDetails::getCoordinatesFromIndex);
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::basic_string<char>&, const cv::optflow::GPCTree::Node&)>("write", &cv::write);
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::optflow::GPCTree::Node&, cv::optflow::GPCTree::Node)>("read", &cv::read);
}