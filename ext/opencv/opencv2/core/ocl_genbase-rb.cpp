#include <sstream>
#include <opencv2/core/ocl_genbase.hpp>
#include "ocl_genbase-rb.hpp"

using namespace Rice;



void Init_OclGenbase()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOcl = define_module_under(rb_mCv, "Ocl");
  
  Module rb_mCvOclInternal = define_module_under(rb_mCvOcl, "Internal");
  

}