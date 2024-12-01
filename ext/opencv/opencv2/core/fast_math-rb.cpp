#include <sstream>
#include <opencv2/core/fast_math.hpp>
#include "fast_math-rb.hpp"

using namespace Rice;



void Init_FastMath()
{
  Class(rb_cObject).define_constant("OPENCV_USE_FASTMATH_BUILTINS", OPENCV_USE_FASTMATH_BUILTINS);
}