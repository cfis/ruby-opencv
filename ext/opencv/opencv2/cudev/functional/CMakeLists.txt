# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "color_cvt-rb.cpp"
    "functional-rb.cpp"
    "tuple_adapter-rb.cpp"
  )
