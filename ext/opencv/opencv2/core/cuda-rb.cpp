#include <sstream>
#include <opencv2/core/cuda.hpp>
#include "cvstd_wrapper-rb.hpp"
#include "cuda-rb.hpp"

using namespace Rice;



void Init_Cuda()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  Class rb_cCvCudaGpuMat = define_class_under<cv::cuda::GpuMat>(rb_mCvCuda, "GpuMat").
    define_singleton_function<cv::cuda::GpuMat::Allocator*(*)()>("default_allocator", &cv::cuda::GpuMat::defaultAllocator).
    define_singleton_function<void(*)(cv::cuda::GpuMat::Allocator*)>("set_default_allocator", &cv::cuda::GpuMat::setDefaultAllocator,
      Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::cuda::GpuMat::Allocator*>(),
      Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, cv::cuda::GpuMat::Allocator*>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, cv::cuda::GpuMat::Allocator*>(),
      Arg("size"), Arg("type"), Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("s"), Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, cv::Scalar, cv::cuda::GpuMat::Allocator*>(),
      Arg("size"), Arg("type"), Arg("s"), Arg("allocator")).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&>(),
      Arg("m")).
    define_constructor(Constructor<cv::cuda::GpuMat, int, int, int, void*, ::size_t>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("data"), Arg("step")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::Size, int, void*, ::size_t>(),
      Arg("size"), Arg("type"), Arg("data"), Arg("step")).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&, cv::Range, cv::Range>(),
      Arg("m"), Arg("row_range"), Arg("col_range")).
    define_constructor(Constructor<cv::cuda::GpuMat, const cv::cuda::GpuMat&, cv::Rect>(),
      Arg("m"), Arg("roi")).
    define_constructor(Constructor<cv::cuda::GpuMat, cv::InputArray, cv::cuda::GpuMat::Allocator*>(),
      Arg("arr"), Arg("allocator")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(const cv::cuda::GpuMat&)>("=", &cv::cuda::GpuMat::operator=,
      Arg("m")).
    define_method<void(cv::cuda::GpuMat::*)(int, int, int)>("create", &cv::cuda::GpuMat::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::cuda::GpuMat::*)(cv::Size, int)>("create", &cv::cuda::GpuMat::create,
      Arg("size"), Arg("type")).
    define_method<void(cv::cuda::GpuMat::*)()>("release", &cv::cuda::GpuMat::release).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&)>("swap", &cv::cuda::GpuMat::swap,
      Arg("mat")).
    define_method<void(cv::cuda::GpuMat::*)(cv::InputArray)>("upload", &cv::cuda::GpuMat::upload,
      Arg("arr")).
    define_method<void(cv::cuda::GpuMat::*)(cv::InputArray, cv::cuda::Stream&)>("upload", &cv::cuda::GpuMat::upload,
      Arg("arr"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray) const>("download", &cv::cuda::GpuMat::download,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::cuda::Stream&) const>("download", &cv::cuda::GpuMat::download,
      Arg("dst"), Arg("stream")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)() const>("clone", &cv::cuda::GpuMat::clone).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::InputArray) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, cv::InputArray, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::Stream&) const>("copy_to", &cv::cuda::GpuMat::copyTo,
      Arg("dst"), Arg("mask"), Arg("stream")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::cuda::Stream&)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("stream")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::InputArray)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("mask")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(cv::Scalar, cv::InputArray, cv::cuda::Stream&)>("set_to", &cv::cuda::GpuMat::setTo,
      Arg("s"), Arg("mask"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, double) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta") = 0.0).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, double, double) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha") = 1.0, Arg("beta") = 0.0).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::OutputArray, int, double, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int, double, double, cv::cuda::Stream&) const>("convert_to", &cv::cuda::GpuMat::convertTo,
      Arg("dst"), Arg("rtype"), Arg("alpha"), Arg("beta"), Arg("stream")).
    define_method<void(cv::cuda::GpuMat::*)(cv::cuda::GpuMat&, int) const>("assign_to", &cv::cuda::GpuMat::assignTo,
      Arg("m"), Arg("type") = -1).
    define_method<uchar*(cv::cuda::GpuMat::*)(int)>("ptr", &cv::cuda::GpuMat::ptr,
      Arg("y") = 0).
    define_method<const uchar*(cv::cuda::GpuMat::*)(int) const>("ptr", &cv::cuda::GpuMat::ptr,
      Arg("y") = 0).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int) const>("row", &cv::cuda::GpuMat::row,
      Arg("y")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int) const>("col", &cv::cuda::GpuMat::col,
      Arg("x")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int, int) const>("row_range", &cv::cuda::GpuMat::rowRange,
      Arg("startrow"), Arg("endrow")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range) const>("row_range", &cv::cuda::GpuMat::rowRange,
      Arg("r")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int, int) const>("col_range", &cv::cuda::GpuMat::colRange,
      Arg("startcol"), Arg("endcol")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range) const>("col_range", &cv::cuda::GpuMat::colRange,
      Arg("r")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Range, cv::Range) const>("()", &cv::cuda::GpuMat::operator(),
      Arg("row_range"), Arg("col_range")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(cv::Rect) const>("()", &cv::cuda::GpuMat::operator(),
      Arg("roi")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMat::*)(int, int) const>("reshape", &cv::cuda::GpuMat::reshape,
      Arg("cn"), Arg("rows") = 0).
    define_method<void(cv::cuda::GpuMat::*)(cv::Size&, cv::Point&) const>("locate_roi", &cv::cuda::GpuMat::locateROI,
      Arg("whole_size"), Arg("ofs")).
    define_method<cv::cuda::GpuMat&(cv::cuda::GpuMat::*)(int, int, int, int)>("adjust_roi", &cv::cuda::GpuMat::adjustROI,
      Arg("dtop"), Arg("dbottom"), Arg("dleft"), Arg("dright")).
    define_method<bool(cv::cuda::GpuMat::*)() const>("is_continuous?", &cv::cuda::GpuMat::isContinuous).
    define_method<::size_t(cv::cuda::GpuMat::*)() const>("elem_size", &cv::cuda::GpuMat::elemSize).
    define_method<::size_t(cv::cuda::GpuMat::*)() const>("elem_size1", &cv::cuda::GpuMat::elemSize1).
    define_method<int(cv::cuda::GpuMat::*)() const>("type", &cv::cuda::GpuMat::type).
    define_method<int(cv::cuda::GpuMat::*)() const>("depth", &cv::cuda::GpuMat::depth).
    define_method<int(cv::cuda::GpuMat::*)() const>("channels", &cv::cuda::GpuMat::channels).
    define_method<::size_t(cv::cuda::GpuMat::*)() const>("step1", &cv::cuda::GpuMat::step1).
    define_method<cv::Size(cv::cuda::GpuMat::*)() const>("size", &cv::cuda::GpuMat::size).
    define_method<bool(cv::cuda::GpuMat::*)() const>("empty?", &cv::cuda::GpuMat::empty).
    define_method<void*(cv::cuda::GpuMat::*)() const>("cuda_ptr", &cv::cuda::GpuMat::cudaPtr).
    define_method<void(cv::cuda::GpuMat::*)()>("update_continuity_flag", &cv::cuda::GpuMat::updateContinuityFlag).
    define_attr("flags", &cv::cuda::GpuMat::flags).
    define_attr("rows", &cv::cuda::GpuMat::rows).
    define_attr("cols", &cv::cuda::GpuMat::cols).
    define_attr("step", &cv::cuda::GpuMat::step).
    define_attr("data", &cv::cuda::GpuMat::data).
    define_attr("refcount", &cv::cuda::GpuMat::refcount).
    define_attr("datastart", &cv::cuda::GpuMat::datastart).
    define_attr("dataend", &cv::cuda::GpuMat::dataend).
    define_attr("allocator", &cv::cuda::GpuMat::allocator);
  
  Class rb_cCvCudaGpuMatAllocator = define_class_under<cv::cuda::GpuMat::Allocator>(rb_cCvCudaGpuMat, "Allocator").
    define_method<bool(cv::cuda::GpuMat::Allocator::*)(cv::cuda::GpuMat*, int, int, ::size_t)>("allocate?", &cv::cuda::GpuMat::Allocator::allocate,
      Arg("mat"), Arg("rows"), Arg("cols"), Arg("elem_size")).
    define_method<void(cv::cuda::GpuMat::Allocator::*)(cv::cuda::GpuMat*)>("free", &cv::cuda::GpuMat::Allocator::free,
      Arg("mat"));
  
  Class rb_cCvCudaGpuData = define_class_under<cv::cuda::GpuData>(rb_mCvCuda, "GpuData").
    define_constructor(Constructor<cv::cuda::GpuData, ::size_t>(),
      Arg("_size")).
    define_attr("data", &cv::cuda::GpuData::data).
    define_attr("size", &cv::cuda::GpuData::size);
  
  Class rb_cCvCudaGpuMatND = define_class_under<cv::cuda::GpuMatND>(rb_mCvCuda, "GpuMatND").
    define_constructor(Constructor<cv::cuda::GpuMatND>()).
    define_constructor(Constructor<cv::cuda::GpuMatND, cv::cuda::GpuMatND::SizeArray, int>(),
      Arg("size"), Arg("type")).
    define_constructor(Constructor<cv::cuda::GpuMatND, cv::cuda::GpuMatND::SizeArray, int, void*, cv::cuda::GpuMatND::StepArray>(),
      Arg("size"), Arg("type"), Arg("data"), Arg("step")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND::SizeArray, int)>("create", &cv::cuda::GpuMatND::create,
      Arg("size"), Arg("type")).
    define_method<void(cv::cuda::GpuMatND::*)()>("release", &cv::cuda::GpuMatND::release).
    define_method<void(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND&) noexcept>("swap", &cv::cuda::GpuMatND::swap,
      Arg("m")).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)() const>("clone", &cv::cuda::GpuMatND::clone).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)(cv::cuda::Stream&) const>("clone", &cv::cuda::GpuMatND::clone,
      Arg("stream")).
    define_method<cv::cuda::GpuMatND(cv::cuda::GpuMatND::*)(const std::vector<cv::Range>&) const>("()", &cv::cuda::GpuMatND::operator(),
      Arg("ranges")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND::IndexArray, cv::Range, cv::Range) const>("create_gpu_mat_header", &cv::cuda::GpuMatND::createGpuMatHeader,
      Arg("idx"), Arg("row_range"), Arg("col_range")).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)() const>("create_gpu_mat_header", &cv::cuda::GpuMatND::createGpuMatHeader).
    define_method<cv::cuda::GpuMat(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND::IndexArray, cv::Range, cv::Range) const>("()", &cv::cuda::GpuMatND::operator(),
      Arg("idx"), Arg("row_range"), Arg("col_range")).
    define_method("to_gpu_mat", [](const cv::cuda::GpuMatND& self) -> cv::cuda::GpuMat
    {
      return self;
    }).
    define_constructor(Constructor<cv::cuda::GpuMatND, const cv::cuda::GpuMatND&>(),
      Arg("")).
    define_method<cv::cuda::GpuMatND&(cv::cuda::GpuMatND::*)(const cv::cuda::GpuMatND&)>("=", &cv::cuda::GpuMatND::operator=,
      Arg("")).
    define_constructor(Constructor<cv::cuda::GpuMatND, cv::cuda::GpuMatND&&>(),
      Arg("")).
    define_method<cv::cuda::GpuMatND&(cv::cuda::GpuMatND::*)(cv::cuda::GpuMatND&&) noexcept>("=", &cv::cuda::GpuMatND::operator=,
      Arg("")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::InputArray)>("upload", &cv::cuda::GpuMatND::upload,
      Arg("src")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::InputArray, cv::cuda::Stream&)>("upload", &cv::cuda::GpuMatND::upload,
      Arg("src"), Arg("stream")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::OutputArray) const>("download", &cv::cuda::GpuMatND::download,
      Arg("dst")).
    define_method<void(cv::cuda::GpuMatND::*)(cv::OutputArray, cv::cuda::Stream&) const>("download", &cv::cuda::GpuMatND::download,
      Arg("dst"), Arg("stream")).
    define_method<bool(cv::cuda::GpuMatND::*)() const>("is_continuous?", &cv::cuda::GpuMatND::isContinuous).
    define_method<bool(cv::cuda::GpuMatND::*)() const>("is_submatrix?", &cv::cuda::GpuMatND::isSubmatrix).
    define_method<::size_t(cv::cuda::GpuMatND::*)() const>("elem_size", &cv::cuda::GpuMatND::elemSize).
    define_method<::size_t(cv::cuda::GpuMatND::*)() const>("elem_size1", &cv::cuda::GpuMatND::elemSize1).
    define_method<bool(cv::cuda::GpuMatND::*)() const>("empty?", &cv::cuda::GpuMatND::empty).
    define_method<bool(cv::cuda::GpuMatND::*)() const>("external?", &cv::cuda::GpuMatND::external).
    define_method<uchar*(cv::cuda::GpuMatND::*)() const>("get_device_ptr", &cv::cuda::GpuMatND::getDevicePtr).
    define_method<::size_t(cv::cuda::GpuMatND::*)() const>("total", &cv::cuda::GpuMatND::total).
    define_method<::size_t(cv::cuda::GpuMatND::*)() const>("total_mem_size", &cv::cuda::GpuMatND::totalMemSize).
    define_method<int(cv::cuda::GpuMatND::*)() const>("type", &cv::cuda::GpuMatND::type).
    define_attr("flags", &cv::cuda::GpuMatND::flags).
    define_attr("dims", &cv::cuda::GpuMatND::dims).
    define_attr("size", &cv::cuda::GpuMatND::size).
    define_attr("step", &cv::cuda::GpuMatND::step);
  
  rb_mCvCuda.define_module_function<void(*)(int, int, int, cv::OutputArray)>("create_continuous", &cv::cuda::createContinuous,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("arr"));
  
  rb_mCvCuda.define_module_function<void(*)(int, int, int, cv::OutputArray)>("ensure_size_is_enough", &cv::cuda::ensureSizeIsEnough,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("arr"));
  
  rb_mCvCuda.define_module_function<cv::cuda::GpuMat(*)(int, int, int, ::size_t, ::size_t)>("create_gpu_mat_from_cuda_memory", &cv::cuda::createGpuMatFromCudaMemory,
    Arg("rows"), Arg("cols"), Arg("type"), Arg("cuda_memory_address"), Arg("step"));
  
  rb_mCvCuda.define_module_function<cv::cuda::GpuMat(*)(cv::Size, int, ::size_t, ::size_t)>("create_gpu_mat_from_cuda_memory", &cv::cuda::createGpuMatFromCudaMemory,
    Arg("size"), Arg("type"), Arg("cuda_memory_address"), Arg("step"));
  
  Class rb_cCvCudaBufferPool = define_class_under<cv::cuda::BufferPool>(rb_mCvCuda, "BufferPool").
    define_constructor(Constructor<cv::cuda::BufferPool, cv::cuda::Stream&>(),
      Arg("stream")).
    define_method<cv::cuda::GpuMat(cv::cuda::BufferPool::*)(int, int, int)>("get_buffer", &cv::cuda::BufferPool::getBuffer,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<cv::cuda::GpuMat(cv::cuda::BufferPool::*)(cv::Size, int)>("get_buffer", &cv::cuda::BufferPool::getBuffer,
      Arg("size"), Arg("type")).
    define_method<cv::Ptr<cv::cuda::GpuMat::Allocator>(cv::cuda::BufferPool::*)() const>("get_allocator", &cv::cuda::BufferPool::getAllocator);
  
  rb_mCvCuda.define_module_function<void(*)(bool)>("set_buffer_pool_usage", &cv::cuda::setBufferPoolUsage,
    Arg("on"));
  
  rb_mCvCuda.define_module_function<void(*)(int, ::size_t, int)>("set_buffer_pool_config", &cv::cuda::setBufferPoolConfig,
    Arg("device_id"), Arg("stack_size"), Arg("stack_count"));
  
  Class rb_cCvCudaHostMem = define_class_under<cv::cuda::HostMem>(rb_mCvCuda, "HostMem").
    define_singleton_function<cv::MatAllocator*(*)(cv::cuda::HostMem::AllocType)>("get_allocator", &cv::cuda::HostMem::getAllocator,
      Arg("alloc_type")).
    define_constructor(Constructor<cv::cuda::HostMem, cv::cuda::HostMem::AllocType>(),
      Arg("alloc_type")).
    define_constructor(Constructor<cv::cuda::HostMem, const cv::cuda::HostMem&>(),
      Arg("m")).
    define_constructor(Constructor<cv::cuda::HostMem, int, int, int, cv::cuda::HostMem::AllocType>(),
      Arg("rows"), Arg("cols"), Arg("type"), Arg("alloc_type")).
    define_constructor(Constructor<cv::cuda::HostMem, cv::Size, int, cv::cuda::HostMem::AllocType>(),
      Arg("size"), Arg("type"), Arg("alloc_type")).
    define_constructor(Constructor<cv::cuda::HostMem, cv::InputArray, cv::cuda::HostMem::AllocType>(),
      Arg("arr"), Arg("alloc_type")).
    define_method<cv::cuda::HostMem&(cv::cuda::HostMem::*)(const cv::cuda::HostMem&)>("=", &cv::cuda::HostMem::operator=,
      Arg("m")).
    define_method<void(cv::cuda::HostMem::*)(cv::cuda::HostMem&)>("swap", &cv::cuda::HostMem::swap,
      Arg("b")).
    define_method<cv::cuda::HostMem(cv::cuda::HostMem::*)() const>("clone", &cv::cuda::HostMem::clone).
    define_method<void(cv::cuda::HostMem::*)(int, int, int)>("create", &cv::cuda::HostMem::create,
      Arg("rows"), Arg("cols"), Arg("type")).
    define_method<void(cv::cuda::HostMem::*)(cv::Size, int)>("create", &cv::cuda::HostMem::create,
      Arg("size"), Arg("type")).
    define_method<cv::cuda::HostMem(cv::cuda::HostMem::*)(int, int) const>("reshape", &cv::cuda::HostMem::reshape,
      Arg("cn"), Arg("rows") = 0).
    define_method<void(cv::cuda::HostMem::*)()>("release", &cv::cuda::HostMem::release).
    define_method<cv::Mat(cv::cuda::HostMem::*)() const>("create_mat_header", &cv::cuda::HostMem::createMatHeader).
    define_method<cv::cuda::GpuMat(cv::cuda::HostMem::*)() const>("create_gpu_mat_header", &cv::cuda::HostMem::createGpuMatHeader).
    define_method<bool(cv::cuda::HostMem::*)() const>("is_continuous?", &cv::cuda::HostMem::isContinuous).
    define_method<::size_t(cv::cuda::HostMem::*)() const>("elem_size", &cv::cuda::HostMem::elemSize).
    define_method<::size_t(cv::cuda::HostMem::*)() const>("elem_size1", &cv::cuda::HostMem::elemSize1).
    define_method<int(cv::cuda::HostMem::*)() const>("type", &cv::cuda::HostMem::type).
    define_method<int(cv::cuda::HostMem::*)() const>("depth", &cv::cuda::HostMem::depth).
    define_method<int(cv::cuda::HostMem::*)() const>("channels", &cv::cuda::HostMem::channels).
    define_method<::size_t(cv::cuda::HostMem::*)() const>("step1", &cv::cuda::HostMem::step1).
    define_method<cv::Size(cv::cuda::HostMem::*)() const>("size", &cv::cuda::HostMem::size).
    define_method<bool(cv::cuda::HostMem::*)() const>("empty?", &cv::cuda::HostMem::empty).
    define_attr("flags", &cv::cuda::HostMem::flags).
    define_attr("rows", &cv::cuda::HostMem::rows).
    define_attr("cols", &cv::cuda::HostMem::cols).
    define_attr("step", &cv::cuda::HostMem::step).
    define_attr("data", &cv::cuda::HostMem::data).
    define_attr("refcount", &cv::cuda::HostMem::refcount).
    define_attr("datastart", &cv::cuda::HostMem::datastart).
    define_attr("dataend", &cv::cuda::HostMem::dataend).
    define_attr("alloc_type", &cv::cuda::HostMem::alloc_type);
  
  Enum<cv::cuda::HostMem::AllocType> rb_cCvCudaHostMemAllocType = define_enum_under<cv::cuda::HostMem::AllocType>("AllocType", rb_cCvCudaHostMem).
    define_value("PAGE_LOCKED", cv::cuda::HostMem::AllocType::PAGE_LOCKED).
    define_value("SHARED", cv::cuda::HostMem::AllocType::SHARED).
    define_value("WRITE_COMBINED", cv::cuda::HostMem::AllocType::WRITE_COMBINED);
  
  rb_mCvCuda.define_module_function<void(*)(cv::Mat&)>("register_page_locked", &cv::cuda::registerPageLocked,
    Arg("m"));
  
  rb_mCvCuda.define_module_function<void(*)(cv::Mat&)>("unregister_page_locked", &cv::cuda::unregisterPageLocked,
    Arg("m"));
  
  Class rb_cCvCudaStream = define_class_under<cv::cuda::Stream>(rb_mCvCuda, "Stream").
    define_constructor(Constructor<cv::cuda::Stream>()).
    define_constructor(Constructor<cv::cuda::Stream, const cv::Ptr<cv::cuda::GpuMat::Allocator>&>(),
      Arg("allocator")).
    define_constructor(Constructor<cv::cuda::Stream, const ::size_t>(),
      Arg("cuda_flags")).
    define_method<bool(cv::cuda::Stream::*)() const>("query_if_complete?", &cv::cuda::Stream::queryIfComplete).
    define_method<void(cv::cuda::Stream::*)()>("wait_for_completion", &cv::cuda::Stream::waitForCompletion).
    define_method<void(cv::cuda::Stream::*)(const cv::cuda::Event&)>("wait_event", &cv::cuda::Stream::waitEvent,
      Arg("event")).
//    define_method<void(cv::cuda::Stream::*)(cv::cuda::Stream::StreamCallback, void*)>("enqueue_host_callback", &cv::cuda::Stream::enqueueHostCallback,
  //    Arg("callback"), Arg("user_data")).
    define_singleton_function<cv::cuda::Stream&(*)()>("null", &cv::cuda::Stream::Null).
 /*   define_method("to_void (cv/cuda/stream/*)() const", [](const cv::cuda::Stream& self) -> cv::cuda::Stream::bool_type
    {
      return self;
    }).*/
    define_method<void*(cv::cuda::Stream::*)() const>("cuda_ptr", &cv::cuda::Stream::cudaPtr);
  
  
  rb_mCvCuda.define_module_function<cv::cuda::Stream(*)(::size_t)>("wrap_stream", &cv::cuda::wrapStream,
    Arg("cuda_stream_memory_address"));
  
  Class rb_cCvCudaEvent = define_class_under<cv::cuda::Event>(rb_mCvCuda, "Event").
    define_constructor(Constructor<cv::cuda::Event, const cv::cuda::Event::CreateFlags>(),
      Arg("flags")).
    define_method<void(cv::cuda::Event::*)(cv::cuda::Stream&)>("record", &cv::cuda::Event::record,
      Arg("stream")).
    define_method<bool(cv::cuda::Event::*)() const>("query_if_complete?", &cv::cuda::Event::queryIfComplete).
    define_method<void(cv::cuda::Event::*)()>("wait_for_completion", &cv::cuda::Event::waitForCompletion).
    define_singleton_function<float(*)(const cv::cuda::Event&, const cv::cuda::Event&)>("elapsed_time", &cv::cuda::Event::elapsedTime,
      Arg("start"), Arg("end"));
  
  
  Enum<cv::cuda::Event::CreateFlags> rb_cCvCudaEventCreateFlags = define_enum_under<cv::cuda::Event::CreateFlags>("CreateFlags", rb_cCvCudaEvent).
    define_value("DEFAULT", cv::cuda::Event::CreateFlags::DEFAULT).
    define_value("BLOCKING_SYNC", cv::cuda::Event::CreateFlags::BLOCKING_SYNC).
    define_value("DISABLE_TIMING", cv::cuda::Event::CreateFlags::DISABLE_TIMING).
    define_value("INTERPROCESS", cv::cuda::Event::CreateFlags::INTERPROCESS);
  
  rb_mCvCuda.define_module_function<int(*)()>("get_cuda_enabled_device_count", &cv::cuda::getCudaEnabledDeviceCount);
  
  rb_mCvCuda.define_module_function<void(*)(int)>("set_device", &cv::cuda::setDevice,
    Arg("device"));
  
  rb_mCvCuda.define_module_function<int(*)()>("get_device", &cv::cuda::getDevice);
  
  rb_mCvCuda.define_module_function<void(*)()>("reset_device", &cv::cuda::resetDevice);
  
  Enum<cv::cuda::FeatureSet> rb_cCvCudaFeatureSet = define_enum_under<cv::cuda::FeatureSet>("FeatureSet", rb_mCvCuda).
    define_value("FEATURE_SET_COMPUTE_10", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_10).
    define_value("FEATURE_SET_COMPUTE_11", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_11).
    define_value("FEATURE_SET_COMPUTE_12", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_12).
    define_value("FEATURE_SET_COMPUTE_13", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_13).
    define_value("FEATURE_SET_COMPUTE_20", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_20).
    define_value("FEATURE_SET_COMPUTE_21", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_21).
    define_value("FEATURE_SET_COMPUTE_30", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_30).
    define_value("FEATURE_SET_COMPUTE_32", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_32).
    define_value("FEATURE_SET_COMPUTE_35", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_35).
    define_value("FEATURE_SET_COMPUTE_50", cv::cuda::FeatureSet::FEATURE_SET_COMPUTE_50).
    define_value("GLOBAL_ATOMICS", cv::cuda::FeatureSet::GLOBAL_ATOMICS).
    define_value("SHARED_ATOMICS", cv::cuda::FeatureSet::SHARED_ATOMICS).
    define_value("NATIVE_DOUBLE", cv::cuda::FeatureSet::NATIVE_DOUBLE).
    define_value("WARP_SHUFFLE_FUNCTIONS", cv::cuda::FeatureSet::WARP_SHUFFLE_FUNCTIONS).
    define_value("DYNAMIC_PARALLELISM", cv::cuda::FeatureSet::DYNAMIC_PARALLELISM);
  
  rb_mCvCuda.define_module_function<bool(*)(cv::cuda::FeatureSet)>("device_supports?", &cv::cuda::deviceSupports,
    Arg("feature_set"));
  
  Class rb_cCvCudaTargetArchs = define_class_under<cv::cuda::TargetArchs>(rb_mCvCuda, "TargetArchs").
    define_constructor(Constructor<cv::cuda::TargetArchs>()).
    define_singleton_function<bool(*)(cv::cuda::FeatureSet)>("built_with?", &cv::cuda::TargetArchs::builtWith,
      Arg("feature_set")).
    define_singleton_function<bool(*)(int, int)>("has?", &cv::cuda::TargetArchs::has,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_ptx?", &cv::cuda::TargetArchs::hasPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_bin?", &cv::cuda::TargetArchs::hasBin,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_equal_or_less_ptx?", &cv::cuda::TargetArchs::hasEqualOrLessPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_equal_or_greater?", &cv::cuda::TargetArchs::hasEqualOrGreater,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_equal_or_greater_ptx?", &cv::cuda::TargetArchs::hasEqualOrGreaterPtx,
      Arg("major"), Arg("minor")).
    define_singleton_function<bool(*)(int, int)>("has_equal_or_greater_bin?", &cv::cuda::TargetArchs::hasEqualOrGreaterBin,
      Arg("major"), Arg("minor"));
  
  Class rb_cCvCudaDeviceInfo = define_class_under<cv::cuda::DeviceInfo>(rb_mCvCuda, "DeviceInfo").
    define_constructor(Constructor<cv::cuda::DeviceInfo>()).
    define_constructor(Constructor<cv::cuda::DeviceInfo, int>(),
      Arg("device_id")).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("device_id", &cv::cuda::DeviceInfo::deviceID).
    define_method<const char*(cv::cuda::DeviceInfo::*)() const>("name", &cv::cuda::DeviceInfo::name).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("total_global_mem", &cv::cuda::DeviceInfo::totalGlobalMem).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("shared_mem_per_block", &cv::cuda::DeviceInfo::sharedMemPerBlock).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("regs_per_block", &cv::cuda::DeviceInfo::regsPerBlock).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("warp_size", &cv::cuda::DeviceInfo::warpSize).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("mem_pitch", &cv::cuda::DeviceInfo::memPitch).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_threads_per_block", &cv::cuda::DeviceInfo::maxThreadsPerBlock).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_threads_dim", &cv::cuda::DeviceInfo::maxThreadsDim).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_grid_size", &cv::cuda::DeviceInfo::maxGridSize).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("clock_rate", &cv::cuda::DeviceInfo::clockRate).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("total_const_mem", &cv::cuda::DeviceInfo::totalConstMem).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("major_version", &cv::cuda::DeviceInfo::majorVersion).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("minor_version", &cv::cuda::DeviceInfo::minorVersion).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("texture_alignment", &cv::cuda::DeviceInfo::textureAlignment).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("texture_pitch_alignment", &cv::cuda::DeviceInfo::texturePitchAlignment).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("multi_processor_count", &cv::cuda::DeviceInfo::multiProcessorCount).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("kernel_exec_timeout_enabled?", &cv::cuda::DeviceInfo::kernelExecTimeoutEnabled).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("integrated?", &cv::cuda::DeviceInfo::integrated).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("can_map_host_memory?", &cv::cuda::DeviceInfo::canMapHostMemory).
    define_method<cv::cuda::DeviceInfo::ComputeMode(cv::cuda::DeviceInfo::*)() const>("compute_mode", &cv::cuda::DeviceInfo::computeMode).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_texture1_d", &cv::cuda::DeviceInfo::maxTexture1D).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_texture1_d_mipmap", &cv::cuda::DeviceInfo::maxTexture1DMipmap).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_texture1_d_linear", &cv::cuda::DeviceInfo::maxTexture1DLinear).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_texture2_d", &cv::cuda::DeviceInfo::maxTexture2D).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_texture2_d_mipmap", &cv::cuda::DeviceInfo::maxTexture2DMipmap).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_texture2_d_linear", &cv::cuda::DeviceInfo::maxTexture2DLinear).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_texture2_d_gather", &cv::cuda::DeviceInfo::maxTexture2DGather).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_texture3_d", &cv::cuda::DeviceInfo::maxTexture3D).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_texture_cubemap", &cv::cuda::DeviceInfo::maxTextureCubemap).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_texture1_d_layered", &cv::cuda::DeviceInfo::maxTexture1DLayered).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_texture2_d_layered", &cv::cuda::DeviceInfo::maxTexture2DLayered).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_texture_cubemap_layered", &cv::cuda::DeviceInfo::maxTextureCubemapLayered).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_surface1_d", &cv::cuda::DeviceInfo::maxSurface1D).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_surface2_d", &cv::cuda::DeviceInfo::maxSurface2D).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_surface3_d", &cv::cuda::DeviceInfo::maxSurface3D).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_surface1_d_layered", &cv::cuda::DeviceInfo::maxSurface1DLayered).
    define_method<cv::Vec3i(cv::cuda::DeviceInfo::*)() const>("max_surface2_d_layered", &cv::cuda::DeviceInfo::maxSurface2DLayered).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_surface_cubemap", &cv::cuda::DeviceInfo::maxSurfaceCubemap).
    define_method<cv::Vec2i(cv::cuda::DeviceInfo::*)() const>("max_surface_cubemap_layered", &cv::cuda::DeviceInfo::maxSurfaceCubemapLayered).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("surface_alignment", &cv::cuda::DeviceInfo::surfaceAlignment).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("concurrent_kernels?", &cv::cuda::DeviceInfo::concurrentKernels).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("ecc_enabled?", &cv::cuda::DeviceInfo::ECCEnabled).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("pci_bus_id", &cv::cuda::DeviceInfo::pciBusID).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("pci_device_id", &cv::cuda::DeviceInfo::pciDeviceID).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("pci_domain_id", &cv::cuda::DeviceInfo::pciDomainID).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("tcc_driver?", &cv::cuda::DeviceInfo::tccDriver).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("async_engine_count", &cv::cuda::DeviceInfo::asyncEngineCount).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("unified_addressing?", &cv::cuda::DeviceInfo::unifiedAddressing).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("memory_clock_rate", &cv::cuda::DeviceInfo::memoryClockRate).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("memory_bus_width", &cv::cuda::DeviceInfo::memoryBusWidth).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("l2_cache_size", &cv::cuda::DeviceInfo::l2CacheSize).
    define_method<int(cv::cuda::DeviceInfo::*)() const>("max_threads_per_multi_processor", &cv::cuda::DeviceInfo::maxThreadsPerMultiProcessor).
    define_method<void(cv::cuda::DeviceInfo::*)(::size_t&, ::size_t&) const>("query_memory", &cv::cuda::DeviceInfo::queryMemory,
      Arg("total_memory"), Arg("free_memory")).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("free_memory", &cv::cuda::DeviceInfo::freeMemory).
    define_method<::size_t(cv::cuda::DeviceInfo::*)() const>("total_memory", &cv::cuda::DeviceInfo::totalMemory).
    define_method<bool(cv::cuda::DeviceInfo::*)(cv::cuda::FeatureSet) const>("supports?", &cv::cuda::DeviceInfo::supports,
      Arg("feature_set")).
    define_method<bool(cv::cuda::DeviceInfo::*)() const>("is_compatible?", &cv::cuda::DeviceInfo::isCompatible);
  
  Enum<cv::cuda::DeviceInfo::ComputeMode> rb_cCvCudaDeviceInfoComputeMode = define_enum_under<cv::cuda::DeviceInfo::ComputeMode>("ComputeMode", rb_cCvCudaDeviceInfo).
    define_value("ComputeModeDefault", cv::cuda::DeviceInfo::ComputeMode::ComputeModeDefault).
    define_value("ComputeModeExclusive", cv::cuda::DeviceInfo::ComputeMode::ComputeModeExclusive).
    define_value("ComputeModeProhibited", cv::cuda::DeviceInfo::ComputeMode::ComputeModeProhibited).
    define_value("ComputeModeExclusiveProcess", cv::cuda::DeviceInfo::ComputeMode::ComputeModeExclusiveProcess);
  
  rb_mCvCuda.define_module_function<void(*)(int)>("print_cuda_device_info", &cv::cuda::printCudaDeviceInfo,
    Arg("device"));
  
  rb_mCvCuda.define_module_function<void(*)(int)>("print_short_cuda_device_info", &cv::cuda::printShortCudaDeviceInfo,
    Arg("device"));
  
  //rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("convert_fp16", &cv::cuda::convertFp16,
   // Arg("_src"), Arg("_dst"), Arg("stream"));

}