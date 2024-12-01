#include <sstream>
#include <opencv2/core/hal/hal.hpp>
#include "hal-rb.hpp"

using namespace Rice;



void Init_Hal()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvHal = define_module_under(rb_mCv, "Hal");
  
  rb_mCvHal.define_module_function<int(*)(const uchar*, int)>("norm_hamming", &cv::hal::normHamming,
    Arg("a"), Arg("n"));
  
  rb_mCvHal.define_module_function<int(*)(const uchar*, const uchar*, int)>("norm_hamming", &cv::hal::normHamming,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCvHal.define_module_function<int(*)(const uchar*, int, int)>("norm_hamming", &cv::hal::normHamming,
    Arg("a"), Arg("n"), Arg("cell_size"));
  
  rb_mCvHal.define_module_function<int(*)(const uchar*, const uchar*, int, int)>("norm_hamming", &cv::hal::normHamming,
    Arg("a"), Arg("b"), Arg("n"), Arg("cell_size"));
  
  rb_mCvHal.define_module_function<int(*)(float*, ::size_t, int, float*, ::size_t, int)>("lu32f", &cv::hal::LU32f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<int(*)(double*, ::size_t, int, double*, ::size_t, int)>("lu64f", &cv::hal::LU64f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<bool(*)(float*, ::size_t, int, float*, ::size_t, int)>("cholesky32f?", &cv::hal::Cholesky32f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<bool(*)(double*, ::size_t, int, double*, ::size_t, int)>("cholesky64f?", &cv::hal::Cholesky64f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(float*, ::size_t, float*, float*, ::size_t, float*, ::size_t, int, int, int)>("svd32f", &cv::hal::SVD32f,
    Arg("at"), Arg("astep"), Arg("w"), Arg("u"), Arg("ustep"), Arg("vt"), Arg("vstep"), Arg("m"), Arg("n"), Arg("flags"));
  
  rb_mCvHal.define_module_function<void(*)(double*, ::size_t, double*, double*, ::size_t, double*, ::size_t, int, int, int)>("svd64f", &cv::hal::SVD64f,
    Arg("at"), Arg("astep"), Arg("w"), Arg("u"), Arg("ustep"), Arg("vt"), Arg("vstep"), Arg("m"), Arg("n"), Arg("flags"));
  
  rb_mCvHal.define_module_function<int(*)(float*, ::size_t, int, int, int, float*, ::size_t, float*)>("qr32f", &cv::hal::QR32f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("n"), Arg("k"), Arg("b"), Arg("bstep"), Arg("h_factors"));
  
  rb_mCvHal.define_module_function<int(*)(double*, ::size_t, int, int, int, double*, ::size_t, double*)>("qr64f", &cv::hal::QR64f,
    Arg("a"), Arg("astep"), Arg("m"), Arg("n"), Arg("k"), Arg("b"), Arg("bstep"), Arg("h_factors"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float, const float*, ::size_t, float, float*, ::size_t, int, int, int, int)>("gemm32f", &cv::hal::gemm32f,
    Arg("src1"), Arg("src1_step"), Arg("src2"), Arg("src2_step"), Arg("alpha"), Arg("src3"), Arg("src3_step"), Arg("beta"), Arg("dst"), Arg("dst_step"), Arg("m_a"), Arg("n_a"), Arg("n_d"), Arg("flags"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double, const double*, ::size_t, double, double*, ::size_t, int, int, int, int)>("gemm64f", &cv::hal::gemm64f,
    Arg("src1"), Arg("src1_step"), Arg("src2"), Arg("src2_step"), Arg("alpha"), Arg("src3"), Arg("src3_step"), Arg("beta"), Arg("dst"), Arg("dst_step"), Arg("m_a"), Arg("n_a"), Arg("n_d"), Arg("flags"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float, const float*, ::size_t, float, float*, ::size_t, int, int, int, int)>("gemm32fc", &cv::hal::gemm32fc,
    Arg("src1"), Arg("src1_step"), Arg("src2"), Arg("src2_step"), Arg("alpha"), Arg("src3"), Arg("src3_step"), Arg("beta"), Arg("dst"), Arg("dst_step"), Arg("m_a"), Arg("n_a"), Arg("n_d"), Arg("flags"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double, const double*, ::size_t, double, double*, ::size_t, int, int, int, int)>("gemm64fc", &cv::hal::gemm64fc,
    Arg("src1"), Arg("src1_step"), Arg("src2"), Arg("src2_step"), Arg("alpha"), Arg("src3"), Arg("src3_step"), Arg("beta"), Arg("dst"), Arg("dst_step"), Arg("m_a"), Arg("n_a"), Arg("n_d"), Arg("flags"));
  
  rb_mCvHal.define_module_function<int(*)(const uchar*, const uchar*, int)>("norm_l1_", &cv::hal::normL1_,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCvHal.define_module_function<float(*)(const float*, const float*, int)>("norm_l1_", &cv::hal::normL1_,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCvHal.define_module_function<float(*)(const float*, const float*, int)>("norm_l2_sqr_", &cv::hal::normL2Sqr_,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("exp32f", &cv::hal::exp32f,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("exp64f", &cv::hal::exp64f,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("log32f", &cv::hal::log32f,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("log64f", &cv::hal::log64f,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, float*, int, bool)>("cart_to_polar32f", &cv::hal::cartToPolar32f,
    Arg("x"), Arg("y"), Arg("mag"), Arg("angle"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, const double*, double*, double*, int, bool)>("cart_to_polar64f", &cv::hal::cartToPolar64f,
    Arg("x"), Arg("y"), Arg("mag"), Arg("angle"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, int, bool)>("fast_atan32f", &cv::hal::fastAtan32f,
    Arg("y"), Arg("x"), Arg("dst"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, const double*, double*, int, bool)>("fast_atan64f", &cv::hal::fastAtan64f,
    Arg("y"), Arg("x"), Arg("dst"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, int)>("magnitude32f", &cv::hal::magnitude32f,
    Arg("x"), Arg("y"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, const double*, double*, int)>("magnitude64f", &cv::hal::magnitude64f,
    Arg("x"), Arg("y"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, float*, int, bool)>("polar_to_cart32f", &cv::hal::polarToCart32f,
    Arg("mag"), Arg("angle"), Arg("x"), Arg("y"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, const double*, double*, double*, int, bool)>("polar_to_cart64f", &cv::hal::polarToCart64f,
    Arg("mag"), Arg("angle"), Arg("x"), Arg("y"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("sqrt32f", &cv::hal::sqrt32f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("sqrt64f", &cv::hal::sqrt64f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("inv_sqrt32f", &cv::hal::invSqrt32f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("inv_sqrt64f", &cv::hal::invSqrt64f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, uchar**, int, int)>("split8u", &cv::hal::split8u,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ushort**, int, int)>("split16u", &cv::hal::split16u,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, int**, int, int)>("split32s", &cv::hal::split32s,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const int64*, int64**, int, int)>("split64s", &cv::hal::split64s,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar**, uchar*, int, int)>("merge8u", &cv::hal::merge8u,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort**, ushort*, int, int)>("merge16u", &cv::hal::merge16u,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const int**, int*, int, int)>("merge32s", &cv::hal::merge32s,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const int64**, int64*, int, int)>("merge64s", &cv::hal::merge64s,
    Arg("src"), Arg("dst"), Arg("len"), Arg("cn"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("add8u", &cv::hal::add8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("add8s", &cv::hal::add8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("add16u", &cv::hal::add16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("add16s", &cv::hal::add16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("add32s", &cv::hal::add32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("add32f", &cv::hal::add32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("add64f", &cv::hal::add64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("sub8u", &cv::hal::sub8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("sub8s", &cv::hal::sub8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("sub16u", &cv::hal::sub16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("sub16s", &cv::hal::sub16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("sub32s", &cv::hal::sub32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("sub32f", &cv::hal::sub32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("sub64f", &cv::hal::sub64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("max8u", &cv::hal::max8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("max8s", &cv::hal::max8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("max16u", &cv::hal::max16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("max16s", &cv::hal::max16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("max32s", &cv::hal::max32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("max32f", &cv::hal::max32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("max64f", &cv::hal::max64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("min8u", &cv::hal::min8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("min8s", &cv::hal::min8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("min16u", &cv::hal::min16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("min16s", &cv::hal::min16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("min32s", &cv::hal::min32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("min32f", &cv::hal::min32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("min64f", &cv::hal::min64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("absdiff8u", &cv::hal::absdiff8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("absdiff8s", &cv::hal::absdiff8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("absdiff16u", &cv::hal::absdiff16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("absdiff16s", &cv::hal::absdiff16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("absdiff32s", &cv::hal::absdiff32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("absdiff32f", &cv::hal::absdiff32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("absdiff64f", &cv::hal::absdiff64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("and8u", &cv::hal::and8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("or8u", &cv::hal::or8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("xor8u", &cv::hal::xor8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("not8u", &cv::hal::not8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg(""));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp8u", &cv::hal::cmp8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp8s", &cv::hal::cmp8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp16u", &cv::hal::cmp16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp16s", &cv::hal::cmp16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp32s", &cv::hal::cmp32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp32f", &cv::hal::cmp32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, uchar*, ::size_t, int, int, void*)>("cmp64f", &cv::hal::cmp64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_cmpop"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("mul8u", &cv::hal::mul8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("mul8s", &cv::hal::mul8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("mul16u", &cv::hal::mul16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("mul16s", &cv::hal::mul16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("mul32s", &cv::hal::mul32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("mul32f", &cv::hal::mul32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("mul64f", &cv::hal::mul64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("div8u", &cv::hal::div8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("div8s", &cv::hal::div8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("div16u", &cv::hal::div16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("div16s", &cv::hal::div16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("div32s", &cv::hal::div32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("div32f", &cv::hal::div32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("div64f", &cv::hal::div64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("recip8u", &cv::hal::recip8u,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("recip8s", &cv::hal::recip8s,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("recip16u", &cv::hal::recip16u,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("recip16s", &cv::hal::recip16s,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("recip32s", &cv::hal::recip32s,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("recip32f", &cv::hal::recip32f,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("recip64f", &cv::hal::recip64f,
    Arg(""), Arg(""), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scale"));
  
  rb_mCvHal.define_module_function<void(*)(const uchar*, ::size_t, const uchar*, ::size_t, uchar*, ::size_t, int, int, void*)>("add_weighted8u", &cv::hal::addWeighted8u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("_scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const schar*, ::size_t, const schar*, ::size_t, schar*, ::size_t, int, int, void*)>("add_weighted8s", &cv::hal::addWeighted8s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const ushort*, ::size_t, const ushort*, ::size_t, ushort*, ::size_t, int, int, void*)>("add_weighted16u", &cv::hal::addWeighted16u,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const short*, ::size_t, const short*, ::size_t, short*, ::size_t, int, int, void*)>("add_weighted16s", &cv::hal::addWeighted16s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const int*, ::size_t, const int*, ::size_t, int*, ::size_t, int, int, void*)>("add_weighted32s", &cv::hal::addWeighted32s,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, ::size_t, const float*, ::size_t, float*, ::size_t, int, int, void*)>("add_weighted32f", &cv::hal::addWeighted32f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, ::size_t, const double*, ::size_t, double*, ::size_t, int, int, void*)>("add_weighted64f", &cv::hal::addWeighted64f,
    Arg("src1"), Arg("step1"), Arg("src2"), Arg("step2"), Arg("dst"), Arg("step"), Arg("width"), Arg("height"), Arg("scalars"));
  
  rb_mCvHal.define_module_function<void(*)(const cv::hfloat*, float*, int)>("cvt16f32f", &cv::hal::cvt16f32f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, cv::hfloat*, int)>("cvt32f16f", &cv::hal::cvt32f16f,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(float*, const float*, int)>("add_rng_bias32f", &cv::hal::addRNGBias32f,
    Arg("arr"), Arg("scale_bias_pairs"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(double*, const double*, int)>("add_rng_bias64f", &cv::hal::addRNGBias64f,
    Arg("arr"), Arg("scale_bias_pairs"), Arg("len"));
  
  Class rb_cCvHalDFT1D = define_class_under<cv::hal::DFT1D>(rb_mCvHal, "DFT1D").
    define_singleton_function<cv::Ptr<cv::hal::DFT1D>(*)(int, int, int, int, bool*)>("create", &cv::hal::DFT1D::create,
      Arg("len"), Arg("count"), Arg("depth"), Arg("flags"), Arg("use_buffer") = 0).
    define_method<void(cv::hal::DFT1D::*)(const uchar*, uchar*)>("apply", &cv::hal::DFT1D::apply,
      Arg("src"), Arg("dst"));
  
  Class rb_cCvHalDFT2D = define_class_under<cv::hal::DFT2D>(rb_mCvHal, "DFT2D").
    define_singleton_function<cv::Ptr<cv::hal::DFT2D>(*)(int, int, int, int, int, int, int)>("create", &cv::hal::DFT2D::create,
      Arg("width"), Arg("height"), Arg("depth"), Arg("src_channels"), Arg("dst_channels"), Arg("flags"), Arg("nonzero_rows") = 0).
    define_method<void(cv::hal::DFT2D::*)(const uchar*, ::size_t, uchar*, ::size_t)>("apply", &cv::hal::DFT2D::apply,
      Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"));
  
  Class rb_cCvHalDCT2D = define_class_under<cv::hal::DCT2D>(rb_mCvHal, "DCT2D").
    define_singleton_function<cv::Ptr<cv::hal::DCT2D>(*)(int, int, int, int)>("create", &cv::hal::DCT2D::create,
      Arg("width"), Arg("height"), Arg("depth"), Arg("flags")).
    define_method<void(cv::hal::DCT2D::*)(const uchar*, ::size_t, uchar*, ::size_t)>("apply", &cv::hal::DCT2D::apply,
      Arg("src_data"), Arg("src_step"), Arg("dst_data"), Arg("dst_step"));
  
  rb_mCvHal.define_module_function<int(*)(float*, ::size_t, int, float*, ::size_t, int)>("lu", &cv::hal::LU,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<int(*)(double*, ::size_t, int, double*, ::size_t, int)>("lu", &cv::hal::LU,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<bool(*)(float*, ::size_t, int, float*, ::size_t, int)>("cholesky?", &cv::hal::Cholesky,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<bool(*)(double*, ::size_t, int, double*, ::size_t, int)>("cholesky?", &cv::hal::Cholesky,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("exp", &cv::hal::exp,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("exp", &cv::hal::exp,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("log", &cv::hal::log,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("log", &cv::hal::log,
    Arg("src"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, int, bool)>("fast_atan2", &cv::hal::fastAtan2,
    Arg("y"), Arg("x"), Arg("dst"), Arg("n"), Arg("angle_in_degrees"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, const float*, float*, int)>("magnitude", &cv::hal::magnitude,
    Arg("x"), Arg("y"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, const double*, double*, int)>("magnitude", &cv::hal::magnitude,
    Arg("x"), Arg("y"), Arg("dst"), Arg("n"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("sqrt", &cv::hal::sqrt,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("sqrt", &cv::hal::sqrt,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const float*, float*, int)>("inv_sqrt", &cv::hal::invSqrt,
    Arg("src"), Arg("dst"), Arg("len"));
  
  rb_mCvHal.define_module_function<void(*)(const double*, double*, int)>("inv_sqrt", &cv::hal::invSqrt,
    Arg("src"), Arg("dst"), Arg("len"));

}