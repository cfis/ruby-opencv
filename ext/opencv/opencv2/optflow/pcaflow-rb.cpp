#include <opencv2/optflow/pcaflow.hpp>
#include "pcaflow-rb.hpp"

using namespace Rice;

extern "C"
void Init_Pcaflow()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");
  
  Class rb_cCvOptflowPCAPrior = define_class_under<cv::optflow::PCAPrior>(rb_mCvOptflow, "PCAPrior").
    define_constructor(Constructor<cv::optflow::PCAPrior, const char*>()).
    define_method<int(cv::optflow::PCAPrior::*)() const>("get_padding", &cv::optflow::PCAPrior::getPadding).
    define_method<int(cv::optflow::PCAPrior::*)() const>("get_basis_size", &cv::optflow::PCAPrior::getBasisSize).
    define_method<void(cv::optflow::PCAPrior::*)(float*, float*, float*, float*) const>("fill_constraints", &cv::optflow::PCAPrior::fillConstraints);
  
  Class rb_cCvOptflowOpticalFlowPCAFlow = define_class_under<cv::optflow::OpticalFlowPCAFlow, cv::DenseOpticalFlow>(rb_mCvOptflow, "OpticalFlowPCAFlow").
    define_constructor(Constructor<cv::optflow::OpticalFlowPCAFlow, cv::Ptr<const cv::optflow::PCAPrior>, const cv::Size_<int>, float, float, float, float, float>()).
    define_method<void(cv::optflow::OpticalFlowPCAFlow::*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputOutputArray &)>("calc", &cv::optflow::OpticalFlowPCAFlow::calc).
    define_method<void(cv::optflow::OpticalFlowPCAFlow::*)()>("collect_garbage", &cv::optflow::OpticalFlowPCAFlow::collectGarbage);
  
  rb_mCvOptflow.define_module_function<cv::Ptr<cv::DenseOpticalFlow>(*)()>("create_opt_flow_pca_flow", &cv::optflow::createOptFlow_PCAFlow);
}