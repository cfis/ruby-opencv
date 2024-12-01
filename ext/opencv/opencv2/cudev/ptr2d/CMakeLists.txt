# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "constant-rb.cpp"
    "deriv-rb.cpp"
    "extrapolation-rb.cpp"
    "glob-rb.cpp"
    "gpumat-rb.cpp"
    "interpolation-rb.cpp"
    "lut-rb.cpp"
    "mask-rb.cpp"
    "remap-rb.cpp"
    "resize-rb.cpp"
    "texture-rb.cpp"
    "traits-rb.cpp"
    "transform-rb.cpp"
    "warping-rb.cpp"
    "zip-rb.cpp"
  )
