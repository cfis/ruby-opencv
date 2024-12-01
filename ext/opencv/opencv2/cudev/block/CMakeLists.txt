# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "block-rb.cpp"
    "dynamic_smem-rb.cpp"
    "reduce-rb.cpp"
    "scan-rb.cpp"
    "vec_distance-rb.cpp"
  )
