# Subdirectories
  add_subdirectory ("block")
  add_subdirectory ("expr")
  add_subdirectory ("functional")
  add_subdirectory ("grid")
  add_subdirectory ("ptr2d")
  add_subdirectory ("util")
  add_subdirectory ("warp")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "common-rb.cpp"
  )
