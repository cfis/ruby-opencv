# Subdirectories
  add_subdirectory ("detail")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "reduce-rb.cpp"
    "scan-rb.cpp"
    "shuffle-rb.cpp"
    "warp-rb.cpp"
  )
