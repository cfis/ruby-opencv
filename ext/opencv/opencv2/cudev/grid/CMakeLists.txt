# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "copy-rb.cpp"
    "histogram-rb.cpp"
    "integral-rb.cpp"
    "pyramids-rb.cpp"
    "reduce-rb.cpp"
    "reduce_to_vec-rb.cpp"
    "split_merge-rb.cpp"
    "transform-rb.cpp"
    "transpose-rb.cpp"
  )
