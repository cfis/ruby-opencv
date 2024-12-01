#include <opencv2/core/ocl_genbase.hpp>
#include "ocl_genbase-rb.hpp"

using namespace Rice;

extern "C"
void Init_OclGenbase()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOcl = define_module_under(rb_mCv, "Ocl");
  
  Module rb_mCvOclInternal = define_module_under(rb_mCvOcl, "Internal");
  
  Class rb_cCvOclInternalProgramEntry = define_class_under<cv::ocl::internal::ProgramEntry>(rb_mCvOclInternal, "ProgramEntry").
    define_attr("module", &cv::ocl::internal::ProgramEntry::module).
    define_attr("name", &cv::ocl::internal::ProgramEntry::name).
    define_attr("program_code", &cv::ocl::internal::ProgramEntry::programCode).
    define_attr("program_hash", &cv::ocl::internal::ProgramEntry::programHash).
    define_attr("p_program_source", &cv::ocl::internal::ProgramEntry::pProgramSource);
}