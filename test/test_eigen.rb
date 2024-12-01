# def test_eigenvv
#   elems = [6, -2, -3, 7]
#   m0 = create_mat(2, 2, :cv32f, 1) { |j, i, c|
#     Cv::Scalar.new(elems[c])
#   }
#   v1 = m0.eigenvv
#   v2 = m0.eigenvv(10 ** -15)
#   v3 = m0.eigenvv(10 ** -15, 1, 1)
#   [v1, v2].each { |vec, val|
#     assert_in_delta(-0.615, vec[0, 0][0], 0.01)
#     assert_in_delta(0.788, vec[0, 1][0], 0.01)
#     assert_in_delta(0.788, vec[1, 0][0], 0.01)
#     assert_in_delta(0.615, vec[1, 1][0], 0.01)
#     assert_in_delta(8.562, val[0][0], 0.01)
#     assert_in_delta(4.438, val[1][0], 0.01)
#   }
#   vec3, val3 = v3
#   assert_in_delta(-0.615, vec3[0, 0][0], 0.01)
#   assert_in_delta(0.788, vec3[0, 1][0], 0.01)
#   assert_in_delta(8.562, val3[0][0], 0.01)
#   assert_raise(TypeError) {
#     m0.eigenvv(DUMMY_OBJ)
#   }
#   assert_raise(TypeError) {
#     m0.eigenvv(nil, DUMMY_OBJ)
#   }
#   assert_raise(TypeError) {
#     m0.eigenvv(nil, nil, DUMMY_OBJ)
#   }
# end
#
