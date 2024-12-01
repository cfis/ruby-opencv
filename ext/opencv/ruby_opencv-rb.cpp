#include "ruby_opencv-rb.hpp"

#include "opencv2/core/cuda-rb.hpp"
#include "opencv2/core/ocl-rb.hpp"
#include "opencv2/core/opengl-rb.hpp"
#include "opencv2/core/types-rb.hpp"
#include "opencv2/core/bufferpool-rb.hpp"
#include "opencv2/core/mat-rb.hpp"
#include "opencv2/core/matx-rb.hpp"
#include "opencv2/imgcodecs-rb.hpp"

extern "C"
void Init_ruby_opencv()
{
  return Rice::detail::cpp_protect([]
  {
      Init_Cuda();
      Init_Ocl();
      Init_Opengl();
      Init_Types();
      Init_Bufferpool();
      Init_Mat();
      Init_Matx();
      Init_Imgcodecs();
    });
}