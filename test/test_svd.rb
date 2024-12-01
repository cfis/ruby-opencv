# def test_svd
#   rows = 2
#   cols = 3
#   m0 = create_mat(rows, cols, :cv32f, 1) { |j, i, c|
#     Cv::Scalar.new(c + 1)
#   }
#   [m0.svd, m0.clone.svd(CV_SVD_MODIFY_A)].each { |w, u, v|
#     expected = [0.38632, -0.92237,
#                 0.92237, 0.38632]
#     assert_equal(rows, u.rows)
#     assert_equal(rows, u.cols)
#     expected.each_with_index { |x, i|
#       assert_in_delta(x, u[i][0], 0.0001)
#     }
#     assert_equal(rows, w.rows)
#     assert_equal(cols, w.cols)
#     expected = [9.50803, 0, 0,
#                 0, 0.77287, 0]
#     expected.each_with_index { |x, i|
#       assert_in_delta(x, w[i][0], 0.0001)
#     }
#     assert_equal(cols, v.rows)
#     assert_equal(rows, v.cols)
#     expected = [0.42867, 0.80596,
#                 0.56631, 0.11238,
#                 0.70395, -0.58120]
#
#     expected.each_with_index { |x, i|
#       assert_in_delta(x, v[i][0], 0.0001)
#     }
#   }
#   w, ut, v = m0.svd(CV_SVD_U_T)
#   expected = [0.38632, 0.92237,
#               -0.92237, 0.38632]
#   assert_equal(rows, ut.rows)
#   assert_equal(rows, ut.cols)
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, ut[i][0], 0.0001)
#   }
#   assert_equal(rows, w.rows)
#   assert_equal(cols, w.cols)
#   expected = [9.50803, 0, 0,
#               0, 0.77287, 0]
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, w[i][0], 0.0001)
#   }
#   assert_equal(cols, v.rows)
#   assert_equal(rows, v.cols)
#   expected = [0.42867, 0.80596,
#               0.56631, 0.11238,
#               0.70395, -0.58120]
#
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, v[i][0], 0.0001)
#   }
#   w, u, vt = m0.svd(CV_SVD_V_T)
#   expected = [0.38632, -0.92237,
#               0.92237, 0.38632]
#   assert_equal(rows, u.rows)
#   assert_equal(rows, u.cols)
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, u[i][0], 0.0001)
#   }
#   assert_equal(rows, w.rows)
#   assert_equal(cols, w.cols)
#   expected = [9.50803, 0, 0,
#               0, 0.77287, 0]
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, w[i][0], 0.0001)
#   }
#   assert_equal(rows, vt.rows)
#   assert_equal(cols, vt.cols)
#   expected = [0.42867, 0.56631, 0.70395,
#               0.80596, 0.11238, -0.58120]
#   expected.each_with_index { |x, i|
#     assert_in_delta(x, vt[i][0], 0.0001)
#   }
# end
