#include <opencv2/core/directx.hpp>
#include "directx-rb.hpp"

using namespace Rice;

extern "C"
void Init_Directx()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDirectx = define_module_under(rb_mCv, "Directx");
  
  Module rb_mCvDirectxOcl = define_module_under(rb_mCvDirectx, "Ocl");
  
  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(ID3D11Device*)>("initialize_context_from_d3_d11_device", &cv::directx::ocl::initializeContextFromD3D11Device);
  
  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(ID3D10Device*)>("initialize_context_from_d3_d10_device", &cv::directx::ocl::initializeContextFromD3D10Device);
  
  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(IDirect3DDevice9Ex*)>("initialize_context_from_direct3_d_device9_ex", &cv::directx::ocl::initializeContextFromDirect3DDevice9Ex);
  
  rb_mCvDirectxOcl.define_module_function<cv::ocl::Context&(*)(IDirect3DDevice9*)>("initialize_context_from_direct3_d_device9", &cv::directx::ocl::initializeContextFromDirect3DDevice9);
  
  rb_mCvDirectx.define_module_function<void(*)(const cv::_InputArray &, ID3D11Texture2D*)>("convert_to_d3_d11_texture2_d", &cv::directx::convertToD3D11Texture2D);
  
  rb_mCvDirectx.define_module_function<void(*)(ID3D11Texture2D*, const cv::_OutputArray &)>("convert_from_d3_d11_texture2_d", &cv::directx::convertFromD3D11Texture2D);
  
  rb_mCvDirectx.define_module_function<void(*)(const cv::_InputArray &, ID3D10Texture2D*)>("convert_to_d3_d10_texture2_d", &cv::directx::convertToD3D10Texture2D);
  
  rb_mCvDirectx.define_module_function<void(*)(ID3D10Texture2D*, const cv::_OutputArray &)>("convert_from_d3_d10_texture2_d", &cv::directx::convertFromD3D10Texture2D);
  
  rb_mCvDirectx.define_module_function<void(*)(const cv::_InputArray &, IDirect3DSurface9*, void*)>("convert_to_direct3_d_surface9", &cv::directx::convertToDirect3DSurface9);
  
  rb_mCvDirectx.define_module_function<void(*)(IDirect3DSurface9*, const cv::_OutputArray &, void*)>("convert_from_direct3_d_surface9", &cv::directx::convertFromDirect3DSurface9);
  
  rb_mCvDirectx.define_module_function<int(*)(const int)>("get_type_from_dxgi_format", &cv::directx::getTypeFromDXGI_FORMAT);
  
  rb_mCvDirectx.define_module_function<int(*)(const int)>("get_type_from_d3_dformat", &cv::directx::getTypeFromD3DFORMAT);
}