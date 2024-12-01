#include <opencv2/core/ocl.hpp>
#include "ocl-rb.hpp"

using namespace Rice;



extern "C"
void Init_Ocl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOcl = define_module_under(rb_mCv, "Ocl");
  
  rb_mCvOcl.define_module_function<bool(*)()>("have_open_cl", &cv::ocl::haveOpenCL);
  
  rb_mCvOcl.define_module_function<bool(*)()>("use_open_cl", &cv::ocl::useOpenCL);
  
  rb_mCvOcl.define_module_function<bool(*)()>("have_amd_blas", &cv::ocl::haveAmdBlas);
  
  rb_mCvOcl.define_module_function<bool(*)()>("have_amd_fft", &cv::ocl::haveAmdFft);
  
  rb_mCvOcl.define_module_function<void(*)(bool)>("set_use_open_cl", &cv::ocl::setUseOpenCL);
  
  rb_mCvOcl.define_module_function<void(*)()>("finish", &cv::ocl::finish);
  
  rb_mCvOcl.define_module_function<bool(*)()>("have_svm", &cv::ocl::haveSVM);
  
  Class rb_cCvOclDevice = define_class_under<cv::ocl::Device>(rb_mCvOcl, "Device").
    define_constructor(Constructor<cv::ocl::Device>()).
    define_constructor(Constructor<cv::ocl::Device, void*>()).
    define_constructor(Constructor<cv::ocl::Device, const cv::ocl::Device&>()).
    define_method<cv::ocl::Device&(cv::ocl::Device::*)(const cv::ocl::Device&)>("=", &cv::ocl::Device::operator=).
    define_constructor(Constructor<cv::ocl::Device, cv::ocl::Device&&>()).
    define_method<cv::ocl::Device&(cv::ocl::Device::*)(cv::ocl::Device&&) noexcept>("=", &cv::ocl::Device::operator=).
    define_method<void(cv::ocl::Device::*)(void*)>("set", &cv::ocl::Device::set).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("name", &cv::ocl::Device::name).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("extensions", &cv::ocl::Device::extensions).
    define_method<bool(cv::ocl::Device::*)(const std::basic_string<char>&) const>("is_extension_supported", &cv::ocl::Device::isExtensionSupported).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("version", &cv::ocl::Device::version).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("vendor_name", &cv::ocl::Device::vendorName).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("open_cl_c_version", &cv::ocl::Device::OpenCL_C_Version).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("open_cl_version", &cv::ocl::Device::OpenCLVersion).
    define_method<int(cv::ocl::Device::*)() const>("device_version_major", &cv::ocl::Device::deviceVersionMajor).
    define_method<int(cv::ocl::Device::*)() const>("device_version_minor", &cv::ocl::Device::deviceVersionMinor).
    define_method<std::basic_string<char>(cv::ocl::Device::*)() const>("driver_version", &cv::ocl::Device::driverVersion).
    define_method<void*(cv::ocl::Device::*)() const>("ptr", &cv::ocl::Device::ptr).
    define_method<int(cv::ocl::Device::*)() const>("type", &cv::ocl::Device::type).
    define_method<int(cv::ocl::Device::*)() const>("address_bits", &cv::ocl::Device::addressBits).
    define_method<bool(cv::ocl::Device::*)() const>("available", &cv::ocl::Device::available).
    define_method<bool(cv::ocl::Device::*)() const>("compiler_available", &cv::ocl::Device::compilerAvailable).
    define_method<bool(cv::ocl::Device::*)() const>("linker_available", &cv::ocl::Device::linkerAvailable).
    define_method<int(cv::ocl::Device::*)() const>("double_fp_config", &cv::ocl::Device::doubleFPConfig).
    define_method<int(cv::ocl::Device::*)() const>("single_fp_config", &cv::ocl::Device::singleFPConfig).
    define_method<int(cv::ocl::Device::*)() const>("half_fp_config", &cv::ocl::Device::halfFPConfig).
    define_method<bool(cv::ocl::Device::*)() const>("has_fp64", &cv::ocl::Device::hasFP64).
    define_method<bool(cv::ocl::Device::*)() const>("has_fp16", &cv::ocl::Device::hasFP16).
    define_method<bool(cv::ocl::Device::*)() const>("endian_little", &cv::ocl::Device::endianLittle).
    define_method<bool(cv::ocl::Device::*)() const>("error_correction_support", &cv::ocl::Device::errorCorrectionSupport).
    define_method<int(cv::ocl::Device::*)() const>("execution_capabilities", &cv::ocl::Device::executionCapabilities).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("global_mem_cache_size", &cv::ocl::Device::globalMemCacheSize).
    define_method<int(cv::ocl::Device::*)() const>("global_mem_cache_type", &cv::ocl::Device::globalMemCacheType).
    define_method<int(cv::ocl::Device::*)() const>("global_mem_cache_line_size", &cv::ocl::Device::globalMemCacheLineSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("global_mem_size", &cv::ocl::Device::globalMemSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("local_mem_size", &cv::ocl::Device::localMemSize).
    define_method<int(cv::ocl::Device::*)() const>("local_mem_type", &cv::ocl::Device::localMemType).
    define_method<bool(cv::ocl::Device::*)() const>("host_unified_memory", &cv::ocl::Device::hostUnifiedMemory).
    define_method<bool(cv::ocl::Device::*)() const>("image_support", &cv::ocl::Device::imageSupport).
    define_method<bool(cv::ocl::Device::*)() const>("image_from_buffer_support", &cv::ocl::Device::imageFromBufferSupport).
    define_method<unsigned int(cv::ocl::Device::*)() const>("image_pitch_alignment", &cv::ocl::Device::imagePitchAlignment).
    define_method<unsigned int(cv::ocl::Device::*)() const>("image_base_address_alignment", &cv::ocl::Device::imageBaseAddressAlignment).
    define_method<bool(cv::ocl::Device::*)() const>("intel_subgroups_support", &cv::ocl::Device::intelSubgroupsSupport).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image2_d_max_width", &cv::ocl::Device::image2DMaxWidth).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image2_d_max_height", &cv::ocl::Device::image2DMaxHeight).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image3_d_max_width", &cv::ocl::Device::image3DMaxWidth).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image3_d_max_height", &cv::ocl::Device::image3DMaxHeight).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image3_d_max_depth", &cv::ocl::Device::image3DMaxDepth).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image_max_buffer_size", &cv::ocl::Device::imageMaxBufferSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("image_max_array_size", &cv::ocl::Device::imageMaxArraySize).
    define_method<int(cv::ocl::Device::*)() const>("vendor_id", &cv::ocl::Device::vendorID).
    define_method<bool(cv::ocl::Device::*)() const>("is_amd", &cv::ocl::Device::isAMD).
    define_method<bool(cv::ocl::Device::*)() const>("is_intel", &cv::ocl::Device::isIntel).
    define_method<bool(cv::ocl::Device::*)() const>("is_n_vidia", &cv::ocl::Device::isNVidia).
    define_method<int(cv::ocl::Device::*)() const>("max_clock_frequency", &cv::ocl::Device::maxClockFrequency).
    define_method<int(cv::ocl::Device::*)() const>("max_compute_units", &cv::ocl::Device::maxComputeUnits).
    define_method<int(cv::ocl::Device::*)() const>("max_constant_args", &cv::ocl::Device::maxConstantArgs).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("max_constant_buffer_size", &cv::ocl::Device::maxConstantBufferSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("max_mem_alloc_size", &cv::ocl::Device::maxMemAllocSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("max_parameter_size", &cv::ocl::Device::maxParameterSize).
    define_method<int(cv::ocl::Device::*)() const>("max_read_image_args", &cv::ocl::Device::maxReadImageArgs).
    define_method<int(cv::ocl::Device::*)() const>("max_write_image_args", &cv::ocl::Device::maxWriteImageArgs).
    define_method<int(cv::ocl::Device::*)() const>("max_samplers", &cv::ocl::Device::maxSamplers).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("max_work_group_size", &cv::ocl::Device::maxWorkGroupSize).
    define_method<int(cv::ocl::Device::*)() const>("max_work_item_dims", &cv::ocl::Device::maxWorkItemDims).
    define_method<void(cv::ocl::Device::*)(unsigned long long*) const>("max_work_item_sizes", &cv::ocl::Device::maxWorkItemSizes).
    define_method<int(cv::ocl::Device::*)() const>("mem_base_addr_align", &cv::ocl::Device::memBaseAddrAlign).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_char", &cv::ocl::Device::nativeVectorWidthChar).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_short", &cv::ocl::Device::nativeVectorWidthShort).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_int", &cv::ocl::Device::nativeVectorWidthInt).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_long", &cv::ocl::Device::nativeVectorWidthLong).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_float", &cv::ocl::Device::nativeVectorWidthFloat).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_double", &cv::ocl::Device::nativeVectorWidthDouble).
    define_method<int(cv::ocl::Device::*)() const>("native_vector_width_half", &cv::ocl::Device::nativeVectorWidthHalf).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_char", &cv::ocl::Device::preferredVectorWidthChar).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_short", &cv::ocl::Device::preferredVectorWidthShort).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_int", &cv::ocl::Device::preferredVectorWidthInt).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_long", &cv::ocl::Device::preferredVectorWidthLong).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_float", &cv::ocl::Device::preferredVectorWidthFloat).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_double", &cv::ocl::Device::preferredVectorWidthDouble).
    define_method<int(cv::ocl::Device::*)() const>("preferred_vector_width_half", &cv::ocl::Device::preferredVectorWidthHalf).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("printf_buffer_size", &cv::ocl::Device::printfBufferSize).
    define_method<unsigned long long(cv::ocl::Device::*)() const>("profiling_timer_resolution", &cv::ocl::Device::profilingTimerResolution).
    define_singleton_function<const cv::ocl::Device&(*)()>("get_default", &cv::ocl::Device::getDefault).
    define_singleton_function<cv::ocl::Device(*)(void*)>("from_handle", &cv::ocl::Device::fromHandle).
//    define_method<cv::ocl::Device::Impl*(cv::ocl::Device::*)() const>("get_impl", &cv::ocl::Device::getImpl).
    define_method<bool(cv::ocl::Device::*)() const>("empty", &cv::ocl::Device::empty);
  
  
  
  
  
  
  
  
    Class rb_cCvOclContext = define_class_under<cv::ocl::Context>(rb_mCvOcl, "Context").
      define_constructor(Constructor<cv::ocl::Context>()).
      define_constructor(Constructor<cv::ocl::Context, int>()).
      define_constructor(Constructor<cv::ocl::Context, const cv::ocl::Context&>()).
      define_method<cv::ocl::Context & (cv::ocl::Context::*)(const cv::ocl::Context&)>("=", &cv::ocl::Context::operator=).
      define_constructor(Constructor<cv::ocl::Context, cv::ocl::Context&&>()).
      define_method<cv::ocl::Context & (cv::ocl::Context::*)(cv::ocl::Context&&) noexcept>("=", &cv::ocl::Context::operator=).
      define_method<bool(cv::ocl::Context::*)()>("create", &cv::ocl::Context::create).
      define_method<bool(cv::ocl::Context::*)(int)>("create", &cv::ocl::Context::create).
      define_method<unsigned long long(cv::ocl::Context::*)() const>("ndevices", &cv::ocl::Context::ndevices).
      define_method<cv::ocl::Device & (cv::ocl::Context::*)(unsigned long long) const>("device", &cv::ocl::Context::device).
      define_method<cv::ocl::Program(cv::ocl::Context::*)(const cv::ocl::ProgramSource&, const std::basic_string<char>&, std::basic_string<char>&)>("get_prog", &cv::ocl::Context::getProg).
      define_method<void(cv::ocl::Context::*)(cv::ocl::Program&)>("unload_prog", &cv::ocl::Context::unloadProg).
      define_singleton_function<cv::ocl::Context & (*)(bool)>("get_default", &cv::ocl::Context::getDefault).
      define_method<void* (cv::ocl::Context::*)() const>("ptr", &cv::ocl::Context::ptr).
      define_method<void* (cv::ocl::Context::*)(int) const>("get_open_cl_context_property", &cv::ocl::Context::getOpenCLContextProperty).
      define_method<bool(cv::ocl::Context::*)() const>("use_svm", &cv::ocl::Context::useSVM).
      define_method<void(cv::ocl::Context::*)(bool)>("set_use_svm", &cv::ocl::Context::setUseSVM).
      define_singleton_function<cv::ocl::Context(*)(void*)>("from_handle", &cv::ocl::Context::fromHandle).
      define_singleton_function<cv::ocl::Context(*)(const cv::ocl::Device&)>("from_device", &cv::ocl::Context::fromDevice).
      define_singleton_function<cv::ocl::Context(*)(const std::basic_string<char>&)>("create", &cv::ocl::Context::create).
      define_method<void(cv::ocl::Context::*)()>("release", &cv::ocl::Context::release).
      define_method<void(cv::ocl::Context::*)(std::type_index, const std::shared_ptr<cv::ocl::Context::UserContext>&)>("set_user_context", &cv::ocl::Context::setUserContext).
      define_method<std::shared_ptr<cv::ocl::Context::UserContext>(cv::ocl::Context::*)(std::type_index)>("get_user_context", &cv::ocl::Context::getUserContext).
      //define_method<cv::ocl::Context::Impl*(cv::ocl::Context::*)() const>("get_impl", &cv::ocl::Context::getImpl).
      define_method<bool(cv::ocl::Context::*)() const>("empty", &cv::ocl::Context::empty);
    //define_attr("p", &cv::ocl::Context::p);
  
  Class rb_cCvOclContextUserContext = define_class_under<cv::ocl::Context::UserContext>(rb_cCvOclContext, "UserContext").
    define_constructor(Constructor<cv::ocl::Context::UserContext>());
  
  
  Class rb_cCvOclPlatform = define_class_under<cv::ocl::Platform>(rb_mCvOcl, "Platform").
    define_constructor(Constructor<cv::ocl::Platform>()).
    define_constructor(Constructor<cv::ocl::Platform, const cv::ocl::Platform&>()).
    define_method<cv::ocl::Platform&(cv::ocl::Platform::*)(const cv::ocl::Platform&)>("=", &cv::ocl::Platform::operator=).
    define_constructor(Constructor<cv::ocl::Platform, cv::ocl::Platform&&>()).
    define_method<cv::ocl::Platform&(cv::ocl::Platform::*)(cv::ocl::Platform&&) noexcept>("=", &cv::ocl::Platform::operator=).
    define_method<void*(cv::ocl::Platform::*)() const>("ptr", &cv::ocl::Platform::ptr).
    define_singleton_function<cv::ocl::Platform&(*)()>("get_default", &cv::ocl::Platform::getDefault).
//    define_method<cv::ocl::Platform::Impl*(cv::ocl::Platform::*)() const>("get_impl", &cv::ocl::Platform::getImpl).
    define_method<bool(cv::ocl::Platform::*)() const>("empty", &cv::ocl::Platform::empty);
  
  
  rb_mCvOcl.define_module_function<void(*)(const std::basic_string<char>&, void*, void*, void*)>("attach_context", &cv::ocl::attachContext);
  
  rb_mCvOcl.define_module_function<void(*)(void*, unsigned long long, int, int, int, cv::UMat&)>("convert_from_buffer", &cv::ocl::convertFromBuffer);
  
  rb_mCvOcl.define_module_function<void(*)(void*, cv::UMat&)>("convert_from_image", &cv::ocl::convertFromImage);
  
  //rb_mCvOcl.define_module_function<void(*)(cv::ocl::Context&, void*, void*, void*)>("initialize_context_from_handle", &cv::ocl::initializeContextFromHandle);
  
  Class rb_cCvOclQueue = define_class_under<cv::ocl::Queue>(rb_mCvOcl, "Queue").
    define_constructor(Constructor<cv::ocl::Queue>()).
    define_constructor(Constructor<cv::ocl::Queue, const cv::ocl::Context&, const cv::ocl::Device&>()).
    define_constructor(Constructor<cv::ocl::Queue, const cv::ocl::Queue&>()).
    define_method<cv::ocl::Queue&(cv::ocl::Queue::*)(const cv::ocl::Queue&)>("=", &cv::ocl::Queue::operator=).
    define_constructor(Constructor<cv::ocl::Queue, cv::ocl::Queue&&>()).
    define_method<cv::ocl::Queue&(cv::ocl::Queue::*)(cv::ocl::Queue&&) noexcept>("=", &cv::ocl::Queue::operator=).
    define_method<bool(cv::ocl::Queue::*)(const cv::ocl::Context&, const cv::ocl::Device&)>("create", &cv::ocl::Queue::create).
    define_method<void(cv::ocl::Queue::*)()>("finish", &cv::ocl::Queue::finish).
    define_method<void*(cv::ocl::Queue::*)() const>("ptr", &cv::ocl::Queue::ptr).
    define_singleton_function<cv::ocl::Queue&(*)()>("get_default", &cv::ocl::Queue::getDefault).
    define_method<const cv::ocl::Queue&(cv::ocl::Queue::*)() const>("get_profiling_queue", &cv::ocl::Queue::getProfilingQueue).
    //define_method<cv::ocl::Queue::Impl*(cv::ocl::Queue::*)() const>("get_impl", &cv::ocl::Queue::getImpl).
    define_method<bool(cv::ocl::Queue::*)() const>("empty", &cv::ocl::Queue::empty);
  
  
  Class rb_cCvOclKernelArg = define_class_under<cv::ocl::KernelArg>(rb_mCvOcl, "KernelArg").
    define_constructor(Constructor<cv::ocl::KernelArg, int, cv::UMat*, int, int, const void*, unsigned long long>()).
    define_constructor(Constructor<cv::ocl::KernelArg>()).
    define_singleton_function<cv::ocl::KernelArg(*)(unsigned long long)>("local", &cv::ocl::KernelArg::Local).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_write_only", &cv::ocl::KernelArg::PtrWriteOnly).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_read_only", &cv::ocl::KernelArg::PtrReadOnly).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&)>("ptr_read_write", &cv::ocl::KernelArg::PtrReadWrite).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_write", &cv::ocl::KernelArg::ReadWrite).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_write_no_size", &cv::ocl::KernelArg::ReadWriteNoSize).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_only", &cv::ocl::KernelArg::ReadOnly).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("write_only", &cv::ocl::KernelArg::WriteOnly).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("read_only_no_size", &cv::ocl::KernelArg::ReadOnlyNoSize).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::UMat&, int, int)>("write_only_no_size", &cv::ocl::KernelArg::WriteOnlyNoSize).
    define_singleton_function<cv::ocl::KernelArg(*)(const cv::Mat&)>("constant", &cv::ocl::KernelArg::Constant).
    define_attr("flags", &cv::ocl::KernelArg::flags).
    define_attr("m", &cv::ocl::KernelArg::m).
    define_attr("obj", &cv::ocl::KernelArg::obj).
    define_attr("sz", &cv::ocl::KernelArg::sz).
    define_attr("wscale", &cv::ocl::KernelArg::wscale).
    define_attr("iwscale", &cv::ocl::KernelArg::iwscale);
  
  
  Class rb_cCvOclKernel = define_class_under<cv::ocl::Kernel>(rb_mCvOcl, "Kernel").
    define_constructor(Constructor<cv::ocl::Kernel>()).
    define_constructor(Constructor<cv::ocl::Kernel, const char*, const cv::ocl::Program&>()).
    define_constructor(Constructor<cv::ocl::Kernel, const char*, const cv::ocl::ProgramSource&, const std::basic_string<char>&, std::basic_string<char>*>()).
    define_constructor(Constructor<cv::ocl::Kernel, const cv::ocl::Kernel&>()).
    define_method<cv::ocl::Kernel&(cv::ocl::Kernel::*)(const cv::ocl::Kernel&)>("=", &cv::ocl::Kernel::operator=).
    define_constructor(Constructor<cv::ocl::Kernel, cv::ocl::Kernel&&>()).
    define_method<cv::ocl::Kernel&(cv::ocl::Kernel::*)(cv::ocl::Kernel&&) noexcept>("=", &cv::ocl::Kernel::operator=).
    define_method<bool(cv::ocl::Kernel::*)() const>("empty", &cv::ocl::Kernel::empty).
    define_method<bool(cv::ocl::Kernel::*)(const char*, const cv::ocl::Program&)>("create", &cv::ocl::Kernel::create).
    define_method<bool(cv::ocl::Kernel::*)(const char*, const cv::ocl::ProgramSource&, const std::basic_string<char>&, std::basic_string<char>*)>("create", &cv::ocl::Kernel::create).
    define_method<int(cv::ocl::Kernel::*)(int, const void*, unsigned long long)>("set", &cv::ocl::Kernel::set).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::ocl::Image2D&)>("set", &cv::ocl::Kernel::set).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::UMat&)>("set", &cv::ocl::Kernel::set).
    define_method<int(cv::ocl::Kernel::*)(int, const cv::ocl::KernelArg&)>("set", &cv::ocl::Kernel::set).
    define_method<bool(cv::ocl::Kernel::*)(int, unsigned long long[], unsigned long long[], bool, const cv::ocl::Queue&)>("run", &cv::ocl::Kernel::run).
    //define_method<bool(cv::ocl::Kernel::*)(int, unsigned long long[], unsigned long long[], bool, const cv::ocl::Queue&)>("run_", &cv::ocl::Kernel::run_).
    define_method<bool(cv::ocl::Kernel::*)(bool, const cv::ocl::Queue&)>("run_task", &cv::ocl::Kernel::runTask).
    define_method<long long(cv::ocl::Kernel::*)(int, unsigned long long[], unsigned long long[], const cv::ocl::Queue&)>("run_profiling", &cv::ocl::Kernel::runProfiling).
    define_method<unsigned long long(cv::ocl::Kernel::*)() const>("work_group_size", &cv::ocl::Kernel::workGroupSize).
    define_method<unsigned long long(cv::ocl::Kernel::*)() const>("prefered_work_group_size_multiple", &cv::ocl::Kernel::preferedWorkGroupSizeMultiple).
    define_method<bool(cv::ocl::Kernel::*)(unsigned long long[]) const>("compile_work_group_size", &cv::ocl::Kernel::compileWorkGroupSize).
    define_method<unsigned long long(cv::ocl::Kernel::*)() const>("local_mem_size", &cv::ocl::Kernel::localMemSize).
    define_method<void*(cv::ocl::Kernel::*)() const>("ptr", &cv::ocl::Kernel::ptr);
  
  
  Class rb_cCvOclProgram = define_class_under<cv::ocl::Program>(rb_mCvOcl, "Program").
    define_constructor(Constructor<cv::ocl::Program>()).
    define_constructor(Constructor<cv::ocl::Program, const cv::ocl::ProgramSource&, const std::basic_string<char>&, std::basic_string<char>&>()).
    define_constructor(Constructor<cv::ocl::Program, const cv::ocl::Program&>()).
    define_method<cv::ocl::Program&(cv::ocl::Program::*)(const cv::ocl::Program&)>("=", &cv::ocl::Program::operator=).
    define_constructor(Constructor<cv::ocl::Program, cv::ocl::Program&&>()).
    define_method<cv::ocl::Program&(cv::ocl::Program::*)(cv::ocl::Program&&) noexcept>("=", &cv::ocl::Program::operator=).
    define_method<bool(cv::ocl::Program::*)(const cv::ocl::ProgramSource&, const std::basic_string<char>&, std::basic_string<char>&)>("create", &cv::ocl::Program::create).
    define_method<void*(cv::ocl::Program::*)() const>("ptr", &cv::ocl::Program::ptr).
    define_method<void(cv::ocl::Program::*)(std::vector<char>&) const>("get_binary", &cv::ocl::Program::getBinary).
    //define_method<cv::ocl::Program::Impl*(cv::ocl::Program::*)() const>("get_impl", &cv::ocl::Program::getImpl).
    define_method<bool(cv::ocl::Program::*)() const>("empty", &cv::ocl::Program::empty).
    define_method<bool(cv::ocl::Program::*)(const std::basic_string<char>&, const std::basic_string<char>&)>("read", &cv::ocl::Program::read).
    define_method<bool(cv::ocl::Program::*)(std::basic_string<char>&) const>("write", &cv::ocl::Program::write).
    define_method<const cv::ocl::ProgramSource&(cv::ocl::Program::*)() const>("source", &cv::ocl::Program::source).
    define_method<std::basic_string<char>(cv::ocl::Program::*)() const>("get_prefix", &cv::ocl::Program::getPrefix).
    define_singleton_function<std::basic_string<char>(*)(const std::basic_string<char>&)>("get_prefix", &cv::ocl::Program::getPrefix);
  
  
  Class rb_cCvOclProgramSource = define_class_under<cv::ocl::ProgramSource>(rb_mCvOcl, "ProgramSource").
    define_constructor(Constructor<cv::ocl::ProgramSource>()).
    define_constructor(Constructor<cv::ocl::ProgramSource, const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&, const std::basic_string<char>&>()).
    define_constructor(Constructor<cv::ocl::ProgramSource, const std::basic_string<char>&>()).
    define_constructor(Constructor<cv::ocl::ProgramSource, const char*>()).
    define_constructor(Constructor<cv::ocl::ProgramSource, const cv::ocl::ProgramSource&>()).
    define_method<cv::ocl::ProgramSource&(cv::ocl::ProgramSource::*)(const cv::ocl::ProgramSource&)>("=", &cv::ocl::ProgramSource::operator=).
    define_constructor(Constructor<cv::ocl::ProgramSource, cv::ocl::ProgramSource&&>()).
    define_method<cv::ocl::ProgramSource&(cv::ocl::ProgramSource::*)(cv::ocl::ProgramSource&&) noexcept>("=", &cv::ocl::ProgramSource::operator=).
    define_method<const std::basic_string<char>&(cv::ocl::ProgramSource::*)() const>("source", &cv::ocl::ProgramSource::source).
    define_method<unsigned long long(cv::ocl::ProgramSource::*)() const>("hash", &cv::ocl::ProgramSource::hash).
    define_singleton_function<cv::ocl::ProgramSource(*)(const std::basic_string<char>&, const std::basic_string<char>&, const unsigned char*, const unsigned long long, const std::basic_string<char>&)>("from_binary", &cv::ocl::ProgramSource::fromBinary).
    define_singleton_function<cv::ocl::ProgramSource(*)(const std::basic_string<char>&, const std::basic_string<char>&, const unsigned char*, const unsigned long long, const std::basic_string<char>&)>("from_spir", &cv::ocl::ProgramSource::fromSPIR).
    //define_method<cv::ocl::ProgramSource::Impl*(cv::ocl::ProgramSource::*)() const>("get_impl", &cv::ocl::ProgramSource::getImpl).
    define_method<bool(cv::ocl::ProgramSource::*)() const>("empty", &cv::ocl::ProgramSource::empty);
  
  
  Class rb_cCvOclPlatformInfo = define_class_under<cv::ocl::PlatformInfo>(rb_mCvOcl, "PlatformInfo").
    define_constructor(Constructor<cv::ocl::PlatformInfo>()).
    define_constructor(Constructor<cv::ocl::PlatformInfo, void*>()).
    define_constructor(Constructor<cv::ocl::PlatformInfo, const cv::ocl::PlatformInfo&>()).
    define_method<cv::ocl::PlatformInfo&(cv::ocl::PlatformInfo::*)(const cv::ocl::PlatformInfo&)>("=", &cv::ocl::PlatformInfo::operator=).
    define_constructor(Constructor<cv::ocl::PlatformInfo, cv::ocl::PlatformInfo&&>()).
    define_method<cv::ocl::PlatformInfo&(cv::ocl::PlatformInfo::*)(cv::ocl::PlatformInfo&&) noexcept>("=", &cv::ocl::PlatformInfo::operator=).
    define_method<std::basic_string<char>(cv::ocl::PlatformInfo::*)() const>("name", &cv::ocl::PlatformInfo::name).
    define_method<std::basic_string<char>(cv::ocl::PlatformInfo::*)() const>("vendor", &cv::ocl::PlatformInfo::vendor).
    define_method<std::basic_string<char>(cv::ocl::PlatformInfo::*)() const>("version", &cv::ocl::PlatformInfo::version).
    //define_method<int(cv::ocl::PlatformInfo::*)() const>("version_major", &cv::ocl::PlatformInfo::versionMajor).
    //define_method<int(cv::ocl::PlatformInfo::*)() const>("version_minor", &cv::ocl::PlatformInfo::versionMinor).
    //define_method<int(cv::ocl::PlatformInfo::*)() const>("device_number", &cv::ocl::PlatformInfo::deviceNumber).
    define_method<void(cv::ocl::PlatformInfo::*)(cv::ocl::Device&, int) const>("get_device", &cv::ocl::PlatformInfo::getDevice).
    define_method<bool(cv::ocl::PlatformInfo::*)() const>("empty", &cv::ocl::PlatformInfo::empty);
  
  
  rb_mCvOcl.define_module_function<const char*(*)(int, int, int, char*)>("convert_type_str", &cv::ocl::convertTypeStr);
  
  //rb_mCvOcl.define_module_function<const char*(*)(int, int, int, char*, unsigned long long)>("convert_type_str", &cv::ocl::convertTypeStr);
  
  rb_mCvOcl.define_module_function<const char*(*)(int)>("type_to_str", &cv::ocl::typeToStr);
  
  rb_mCvOcl.define_module_function<const char*(*)(int)>("memop_type_to_str", &cv::ocl::memopTypeToStr);
  
  rb_mCvOcl.define_module_function<const char*(*)(int)>("vecop_type_to_str", &cv::ocl::vecopTypeToStr);
  
  rb_mCvOcl.define_module_function<const char*(*)(int)>("get_open_cl_error_string", &cv::ocl::getOpenCLErrorString);
  
  rb_mCvOcl.define_module_function<std::basic_string<char>(*)(const cv::_InputArray &, int, const char*)>("kernel_to_str", &cv::ocl::kernelToStr);
  
  rb_mCvOcl.define_module_function<void(*)(std::vector<cv::ocl::PlatformInfo>&)>("get_platfoms_info", &cv::ocl::getPlatfomsInfo);
  
  Enum<cv::ocl::OclVectorStrategy> rb_cCvOclOclVectorStrategy = define_enum<cv::ocl::OclVectorStrategy>("OclVectorStrategy", rb_mCvOcl).
    define_value("OCL_VECTOR_OWN", cv::ocl::OclVectorStrategy::OCL_VECTOR_OWN).
    define_value("OCL_VECTOR_MAX", cv::ocl::OclVectorStrategy::OCL_VECTOR_MAX).
    define_value("OCL_VECTOR_DEFAULT", cv::ocl::OclVectorStrategy::OCL_VECTOR_DEFAULT);
  
  rb_mCvOcl.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::ocl::OclVectorStrategy)>("predict_optimal_vector_width", &cv::ocl::predictOptimalVectorWidth);
  
  rb_mCvOcl.define_module_function<int(*)(const int*, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, cv::ocl::OclVectorStrategy)>("check_optimal_vector_width", &cv::ocl::checkOptimalVectorWidth);
  
  rb_mCvOcl.define_module_function<int(*)(const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &, const cv::_InputArray &)>("predict_optimal_vector_width_max", &cv::ocl::predictOptimalVectorWidthMax);
  
  rb_mCvOcl.define_module_function<void(*)(std::basic_string<char>&, const std::basic_string<char>&, const cv::_InputArray &)>("build_options_add_matrix_description", &cv::ocl::buildOptionsAddMatrixDescription);
  
  Class rb_cCvOclImage2D = define_class_under<cv::ocl::Image2D>(rb_mCvOcl, "Image2D").
    define_constructor(Constructor<cv::ocl::Image2D>()).
    define_constructor(Constructor<cv::ocl::Image2D, const cv::UMat&, bool, bool>()).
    define_constructor(Constructor<cv::ocl::Image2D, const cv::ocl::Image2D&>()).
    define_method<cv::ocl::Image2D&(cv::ocl::Image2D::*)(const cv::ocl::Image2D&)>("=", &cv::ocl::Image2D::operator=).
    define_constructor(Constructor<cv::ocl::Image2D, cv::ocl::Image2D&&>()).
    define_method<cv::ocl::Image2D&(cv::ocl::Image2D::*)(cv::ocl::Image2D&&) noexcept>("=", &cv::ocl::Image2D::operator=).
    define_singleton_function<bool(*)(const cv::UMat&)>("can_create_alias", &cv::ocl::Image2D::canCreateAlias).
    define_singleton_function<bool(*)(int, int, bool)>("is_format_supported", &cv::ocl::Image2D::isFormatSupported).
    define_method<void*(cv::ocl::Image2D::*)() const>("ptr", &cv::ocl::Image2D::ptr);
  
  
  Class rb_cCvOclTimer = define_class_under<cv::ocl::Timer>(rb_mCvOcl, "Timer").
    define_constructor(Constructor<cv::ocl::Timer, const cv::ocl::Queue&>()).
    define_method<void(cv::ocl::Timer::*)()>("start", &cv::ocl::Timer::start).
    define_method<void(cv::ocl::Timer::*)()>("stop", &cv::ocl::Timer::stop).
    define_method<unsigned long long(cv::ocl::Timer::*)() const>("duration_ns", &cv::ocl::Timer::durationNS);
  
  
  rb_mCvOcl.define_module_function<cv::MatAllocator*(*)()>("get_open_cl_allocator", &cv::ocl::getOpenCLAllocator);
  
  Class rb_cCvOclOpenCLExecutionContext = define_class_under<cv::ocl::OpenCLExecutionContext>(rb_mCvOcl, "OpenCLExecutionContext").
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContext>()).
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContext, const cv::ocl::OpenCLExecutionContext&>()).
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContext, cv::ocl::OpenCLExecutionContext&&>()).
    define_method<cv::ocl::OpenCLExecutionContext&(cv::ocl::OpenCLExecutionContext::*)(const cv::ocl::OpenCLExecutionContext&)>("=", &cv::ocl::OpenCLExecutionContext::operator=).
    define_method<cv::ocl::OpenCLExecutionContext&(cv::ocl::OpenCLExecutionContext::*)(cv::ocl::OpenCLExecutionContext&&)>("=", &cv::ocl::OpenCLExecutionContext::operator=).
    define_method<cv::ocl::Context&(cv::ocl::OpenCLExecutionContext::*)() const>("get_context", &cv::ocl::OpenCLExecutionContext::getContext).
    define_method<cv::ocl::Device&(cv::ocl::OpenCLExecutionContext::*)() const>("get_device", &cv::ocl::OpenCLExecutionContext::getDevice).
    define_method<cv::ocl::Queue&(cv::ocl::OpenCLExecutionContext::*)() const>("get_queue", &cv::ocl::OpenCLExecutionContext::getQueue).
    define_method<bool(cv::ocl::OpenCLExecutionContext::*)() const>("use_open_cl", &cv::ocl::OpenCLExecutionContext::useOpenCL).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)(bool)>("set_use_open_cl", &cv::ocl::OpenCLExecutionContext::setUseOpenCL).
    define_singleton_function<cv::ocl::OpenCLExecutionContext&(*)()>("get_current", &cv::ocl::OpenCLExecutionContext::getCurrent).
    define_singleton_function<cv::ocl::OpenCLExecutionContext&(*)()>("get_current_ref", &cv::ocl::OpenCLExecutionContext::getCurrentRef).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)() const>("bind", &cv::ocl::OpenCLExecutionContext::bind).
    define_method<cv::ocl::OpenCLExecutionContext(cv::ocl::OpenCLExecutionContext::*)(const cv::ocl::Queue&) const>("clone_with_new_queue", &cv::ocl::OpenCLExecutionContext::cloneWithNewQueue).
    define_method<cv::ocl::OpenCLExecutionContext(cv::ocl::OpenCLExecutionContext::*)() const>("clone_with_new_queue", &cv::ocl::OpenCLExecutionContext::cloneWithNewQueue).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const std::basic_string<char>&, void*, void*, void*)>("create", &cv::ocl::OpenCLExecutionContext::create).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const cv::ocl::Context&, const cv::ocl::Device&, const cv::ocl::Queue&)>("create", &cv::ocl::OpenCLExecutionContext::create).
    define_singleton_function<cv::ocl::OpenCLExecutionContext(*)(const cv::ocl::Context&, const cv::ocl::Device&)>("create", &cv::ocl::OpenCLExecutionContext::create).
    define_method<bool(cv::ocl::OpenCLExecutionContext::*)() const>("empty", &cv::ocl::OpenCLExecutionContext::empty).
    define_method<void(cv::ocl::OpenCLExecutionContext::*)()>("release", &cv::ocl::OpenCLExecutionContext::release);
  
  
  Class rb_cCvOclOpenCLExecutionContextScope = define_class_under<cv::ocl::OpenCLExecutionContextScope>(rb_mCvOcl, "OpenCLExecutionContextScope").
    define_constructor(Constructor<cv::ocl::OpenCLExecutionContextScope, const cv::ocl::OpenCLExecutionContext&>());

}