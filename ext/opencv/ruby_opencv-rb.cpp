#include "ruby_opencv-rb.hpp"

#include "opencv2/core/affine-rb.hpp"
#include "opencv2/core/base-rb.hpp"
#include "opencv2/core/bufferpool-rb.hpp"
#include "opencv2/core/check-rb.hpp"
#include "opencv2/core/cuda-rb.hpp"
#include "opencv2/core/hal/interface-rb.hpp"
#include "opencv2/core/mat-rb.hpp"
#include "opencv2/core/matx-rb.hpp"
#include "opencv2/core/ocl-rb.hpp"
#include "opencv2/core/opengl-rb.hpp"
#include "opencv2/core/persistence-rb.hpp"
#include "opencv2/core/types-rb.hpp"
#include "opencv2/core/version-rb.hpp"
#include "opencv2/core-rb.hpp"
#include "opencv2/imgcodecs-rb.hpp"

extern "C"
void Init_ruby_opencv()
{
  return Rice::detail::cpp_protect([]
  {
      // HAL
      Init_Interface();

      // Core
      Init_Affine();
      Init_Base();
      Init_Bufferpool();
      Init_Check();
      Init_Cuda();
      Init_Mat();
      Init_Matx();
      Init_Ocl();
      Init_Persistence();
      Init_Opengl();
      Init_Types();
      Init_Version();

      // Top level
      Init_Core();
      Init_Imgcodecs();

      // Validate types
      Rice::detail::Registries::instance.types.validateTypes();
    });
}