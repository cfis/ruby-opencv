# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "atomic-rb.cpp"
    "limits-rb.cpp"
    "saturate_cast-rb.cpp"
    "simd_functions-rb.cpp"
    "tuple-rb.cpp"
    "type_traits-rb.cpp"
    "vec_math-rb.cpp"
    "vec_traits-rb.cpp"
  )
