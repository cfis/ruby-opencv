#include <opencv2/core/opengl.hpp>
#include "opengl-rb.hpp"

using namespace Rice;

extern "C"
void Init_Opengl()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvOgl = define_module_under(rb_mCv, "Ogl");
  
  Class rb_cCvOglBuffer = define_class_under<cv::ogl::Buffer>(rb_mCvOgl, "Buffer").
    define_constructor(Constructor<cv::ogl::Buffer>()).
    define_constructor(Constructor<cv::ogl::Buffer, int, int, int, unsigned int, bool>()).
    define_constructor(Constructor<cv::ogl::Buffer, cv::Size_<int>, int, unsigned int, bool>()).
    define_constructor(Constructor<cv::ogl::Buffer, int, int, int, cv::ogl::Buffer::Target, bool>()).
    define_constructor(Constructor<cv::ogl::Buffer, cv::Size_<int>, int, cv::ogl::Buffer::Target, bool>()).
    define_constructor(Constructor<cv::ogl::Buffer, const cv::_InputArray &, cv::ogl::Buffer::Target, bool>());
  
  
  Enum<cv::ogl::Buffer::Target> rb_cCvOglBufferTarget = define_enum<cv::ogl::Buffer::Target>("Target", rb_cCvOglBuffer).
    define_value("ARRAY_BUFFER", cv::ogl::Buffer::Target::ARRAY_BUFFER).
    define_value("ELEMENT_ARRAY_BUFFER", cv::ogl::Buffer::Target::ELEMENT_ARRAY_BUFFER).
    define_value("PIXEL_PACK_BUFFER", cv::ogl::Buffer::Target::PIXEL_PACK_BUFFER).
    define_value("PIXEL_UNPACK_BUFFER", cv::ogl::Buffer::Target::PIXEL_UNPACK_BUFFER);
  
  Enum<cv::ogl::Buffer::Access> rb_cCvOglBufferAccess = define_enum<cv::ogl::Buffer::Access>("Access", rb_cCvOglBuffer).
    define_value("READ_ONLY", cv::ogl::Buffer::Access::READ_ONLY).
    define_value("WRITE_ONLY", cv::ogl::Buffer::Access::WRITE_ONLY).
    define_value("READ_WRITE", cv::ogl::Buffer::Access::READ_WRITE);
  
  Class rb_cCvOglTexture2D = define_class_under<cv::ogl::Texture2D>(rb_mCvOgl, "Texture2D").
    define_constructor(Constructor<cv::ogl::Texture2D>()).
    define_constructor(Constructor<cv::ogl::Texture2D, int, int, cv::ogl::Texture2D::Format, unsigned int, bool>()).
    define_constructor(Constructor<cv::ogl::Texture2D, cv::Size_<int>, cv::ogl::Texture2D::Format, unsigned int, bool>()).
    define_constructor(Constructor<cv::ogl::Texture2D, int, int, cv::ogl::Texture2D::Format, bool>()).
    define_constructor(Constructor<cv::ogl::Texture2D, cv::Size_<int>, cv::ogl::Texture2D::Format, bool>()).
    define_constructor(Constructor<cv::ogl::Texture2D, const cv::_InputArray &, bool>());
  
  
  Enum<cv::ogl::Texture2D::Format> rb_cCvOglTexture2DFormat = define_enum<cv::ogl::Texture2D::Format>("Format", rb_cCvOglTexture2D).
    define_value("NONE", cv::ogl::Texture2D::Format::NONE).
    define_value("DEPTH_COMPONENT", cv::ogl::Texture2D::Format::DEPTH_COMPONENT).
    define_value("RGB", cv::ogl::Texture2D::Format::RGB).
    define_value("RGBA", cv::ogl::Texture2D::Format::RGBA);
  
  Class rb_cCvOglArrays = define_class_under<cv::ogl::Arrays>(rb_mCvOgl, "Arrays").
    define_constructor(Constructor<cv::ogl::Arrays>());
  
  Enum<cv::ogl::RenderModes> rb_cCvOglRenderModes = define_enum<cv::ogl::RenderModes>("RenderModes", rb_mCvOgl).
    define_value("POINTS", cv::ogl::RenderModes::POINTS).
    define_value("LINES", cv::ogl::RenderModes::LINES).
    define_value("LINE_LOOP", cv::ogl::RenderModes::LINE_LOOP).
    define_value("LINE_STRIP", cv::ogl::RenderModes::LINE_STRIP).
    define_value("TRIANGLES", cv::ogl::RenderModes::TRIANGLES).
    define_value("TRIANGLE_STRIP", cv::ogl::RenderModes::TRIANGLE_STRIP).
    define_value("TRIANGLE_FAN", cv::ogl::RenderModes::TRIANGLE_FAN).
    define_value("QUADS", cv::ogl::RenderModes::QUADS).
    define_value("QUAD_STRIP", cv::ogl::RenderModes::QUAD_STRIP).
    define_value("POLYGON", cv::ogl::RenderModes::POLYGON);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Texture2D&, cv::Rect_<double>, cv::Rect_<double>)>("render", &cv::ogl::render);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Arrays&, int, cv::Scalar_<double>)>("render", &cv::ogl::render);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Arrays&, const cv::_InputArray &, int, cv::Scalar_<double>)>("render", &cv::ogl::render);
  
  Module rb_mCvOglOcl = define_module_under(rb_mCvOgl, "Ocl");
  
  rb_mCvOglOcl.define_module_function<cv::ocl::Context&(*)()>("initialize_context_from_gl", &cv::ogl::ocl::initializeContextFromGL);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::_InputArray &, cv::ogl::Texture2D&)>("convert_to_gl_texture2_d", &cv::ogl::convertToGLTexture2D);
  
  rb_mCvOgl.define_module_function<void(*)(const cv::ogl::Texture2D&, const cv::_OutputArray &)>("convert_from_gl_texture2_d", &cv::ogl::convertFromGLTexture2D);
  
  rb_mCvOgl.define_module_function<cv::UMat(*)(const cv::ogl::Buffer&, cv::AccessFlag)>("map_gl_buffer", &cv::ogl::mapGLBuffer);
  
  rb_mCvOgl.define_module_function<void(*)(cv::UMat&)>("unmap_gl_buffer", &cv::ogl::unmapGLBuffer);
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_mCvCuda.define_module_function<void(*)(int)>("set_gl_device", &cv::cuda::setGlDevice);
}