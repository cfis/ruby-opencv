# Subdirectories
add_subdirectory ("hal")

# Sources
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    "affine-rb.cpp"
    "base-rb.cpp"
    "bufferpool-rb.cpp"
    "check-rb.cpp"
    "cuda-rb.cpp"
    "mat-rb.cpp"
    "matx-rb.cpp"
    "ocl-rb.cpp"
    "opengl-rb.cpp"
    "persistence-rb.cpp"
    "types-rb.cpp"
    "version-rb.cpp"
)
