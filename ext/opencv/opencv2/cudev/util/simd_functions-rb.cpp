#include <opencv2/cudev/util/simd_functions.hpp>
#include "simd_functions-rb.hpp"

using namespace Rice;

extern "C"
void Init_SimdFunctions()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vadd2", &cv::cudev::vadd2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsub2", &cv::cudev::vsub2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vabsdiff2", &cv::cudev::vabsdiff2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavg2", &cv::cudev::vavg2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavrg2", &cv::cudev::vavrg2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vseteq2", &cv::cudev::vseteq2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpeq2", &cv::cudev::vcmpeq2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetge2", &cv::cudev::vsetge2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpge2", &cv::cudev::vcmpge2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetgt2", &cv::cudev::vsetgt2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpgt2", &cv::cudev::vcmpgt2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetle2", &cv::cudev::vsetle2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmple2", &cv::cudev::vcmple2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetlt2", &cv::cudev::vsetlt2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmplt2", &cv::cudev::vcmplt2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetne2", &cv::cudev::vsetne2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpne2", &cv::cudev::vcmpne2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmax2", &cv::cudev::vmax2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmin2", &cv::cudev::vmin2);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vadd4", &cv::cudev::vadd4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsub4", &cv::cudev::vsub4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavg4", &cv::cudev::vavg4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vavrg4", &cv::cudev::vavrg4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vseteq4", &cv::cudev::vseteq4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpeq4", &cv::cudev::vcmpeq4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetle4", &cv::cudev::vsetle4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmple4", &cv::cudev::vcmple4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetlt4", &cv::cudev::vsetlt4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmplt4", &cv::cudev::vcmplt4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetge4", &cv::cudev::vsetge4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpge4", &cv::cudev::vcmpge4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetgt4", &cv::cudev::vsetgt4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpgt4", &cv::cudev::vcmpgt4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vsetne4", &cv::cudev::vsetne4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vcmpne4", &cv::cudev::vcmpne4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vabsdiff4", &cv::cudev::vabsdiff4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmax4", &cv::cudev::vmax4);
  
  rb_mCvCudev.define_module_function<unsigned int(*)(unsigned int, unsigned int)>("vmin4", &cv::cudev::vmin4);
}