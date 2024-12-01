#include <opencv2/core/cuda/scan.hpp>
#include "scan-rb.hpp"

using namespace Rice;

extern "C"
void Init_Scan()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");
  
  Enum<cv::cuda::device::ScanKind> rb_cCvCudaDeviceScanKind = define_enum<cv::cuda::device::ScanKind>("ScanKind", rb_mCvCudaDevice).
    define_value("EXCLUSIVE", cv::cuda::device::ScanKind::EXCLUSIVE).
    define_value("INCLUSIVE", cv::cuda::device::ScanKind::INCLUSIVE);
}