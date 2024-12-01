require File.join(__dir__, 'helper')

class Calib3dTest < OpenCVTestCase
	FILENAME_CHESSBOARD = self.sample_path('chessboard.jpg')

	def test_find_chessboard_corners
	  mat = Cv::imread(FILENAME_CHESSBOARD, Cv::ImreadModes::IMREAD_GRAYSCALE)
	  pattern_size = Cv::Size.new(4, 4)
	  corners1, found1 = mat.find_chessboard_corners(pattern_size)
	  corners2, found2 = mat.find_chessboard_corners(pattern_size, Cv::CALIB_CB_ADAPTIVE_THRESH)
	  corners3, found3 = mat.find_chessboard_corners(pattern_size, Cv::CALIB_CB_NORMALIZE_IMAGE)
	  corners4, found4 = mat.find_chessboard_corners(pattern_size, Cv::CALIB_CB_FILTER_QUADS)
	  corners5, found5 = mat.find_chessboard_corners(pattern_size, Cv::CALIB_CB_FAST_CHECK)

		assert([found1, found2, found3, found4, found5].all?(true))

	  expected = [[39, 39], [79, 39], [119, 39], [159, 39], [39, 79], [79, 79],
	              [119, 79], [159, 78], [38, 119], [79, 119], [119, 119], [158, 118],
	              [39, 159], [79, 159], [119, 159], [159, 159]]

	  [corners1, corners2, corners3, corners4, corners5].each do |corners|
	    assert_equal(Cv::Size.new(1, 16), corners.size.to_size)
	    expected.zip(corners).each do |e, corner|
	      assert_in_delta(e[0], corner[0], 3.0)
	      assert_in_delta(e[1], corner[1], 3.0)
 		  end
		end
	end

	def test_find_corner_sub_pix
	  mat = Cv::imread(FILENAME_CHESSBOARD, Cv::ImreadModes::IMREAD_GRAYSCALE)
	  pattern_size = Cv::Size.new(4, 4)
	  corners, found = mat.find_chessboard_corners(pattern_size)
		assert(found)
		assert_equal(Cv::Size.new(1, 16), corners.size.to_size)

		mat.corner_sub_pix(corners.input_output_array, Cv::Size.new(3, 3), Cv::Size.new(-1, -1),
		 							    Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT, 20, 0.03))

	  expected = [[39, 39], [79, 39], [119, 39], [159, 39], [39, 79], [79, 79],
	              [119, 79], [159, 78], [38, 119], [79, 119], [119, 119], [158, 118],
	              [39, 159], [79, 159], [119, 159], [159, 159]]

		expected.zip(corners).each do |e, corner|
	    assert_in_delta(e[0], corner[0], 3.0)
	    assert_in_delta(e[1], corner[1], 3.0)
		end
	end

	# def test_compute_correspond_epilines
	#   test_func = lambda { |mat1, mat2, f_mat_arr, num_points|
	#     f_mat = Cv::Mat.new(3, 3, CV_64F, 1)
	#     f_mat_arr.each_with_index { |a, i|
	#       f_mat[i] = Cv::Scalar.new(a)
	#     }
	#
	#     line = Cv::Mat.compute_correspond_epilines(mat1, 1, f_mat)
	#     assert_equal(num_points, line.rows)
	#     assert_equal(3, line.cols)
	#
	#     expected = [[-0.221257, -0.975215, 6.03758],
	#                 [0.359337, -0.933208, -3.61419],
	#                 [0.958304, -0.28575, -15.0573],
	#                 [0.73415, -0.678987, -10.4037],
	#                 [0.0208539, -0.999783, 2.11625],
	#                 [0.284451, -0.958691, -2.31993],
	#                 [0.624647, -0.780907, -8.35208],
	#                 [0.618494, -0.785789, -8.23888],
	#                 [0.766694, -0.642012, -11.0298],
	#                 [0.700293, -0.713855, -9.76109]]
	#
	#     expected.size.times { |i|
	#       assert_in_delta(expected[i][0], line[i, 0][0], 1.0e-3)
	#       assert_in_delta(expected[i][1], line[i, 1][0], 1.0e-3)
	#       assert_in_delta(expected[i][2], line[i, 2][0], 1.0e-3)
	#     }
	#     assert_raise(ArgumentError) {
	#       mat = Cv::Mat.new(10, 10, CV_32F, 1)
	#       Cv::Mat.compute_correspond_epilines(mat, 1, f_mat)
	#     }
	#   }
	#   num_points = 10
	#   # input points are Nx2 matrix
	#   points1 =[[17, 175],
	#             [370, 24],
	#             [192, 456],
	#             [614, 202],
	#             [116, 111],
	#             [305, 32],
	#             [249, 268],
	#             [464, 157],
	#             [259, 333],
	#             [460, 224]]
	#   points2 = [[295, 28],
	#              [584, 221],
	#              [67, 172],
	#              [400, 443],
	#              [330, 9],
	#              [480, 140],
	#              [181, 140],
	#              [350, 265],
	#              [176, 193],
	#              [333, 313]]
	#   mat1 = Cv::Mat.new(num_points, 2, CV_64F, 1)
	#   mat2 = Cv::Mat.new(num_points, 2, CV_64F, 1)
	#   points1.flatten.each_with_index { |pt, i|
	#     mat1[i] = Cv::Scalar.new(pt)
	#   }
	#   points2.flatten.each_with_index { |pt, i|
	#     mat2[i] = Cv::Scalar.new(pt)
	#   }
	#   # pre computed f matrix from points1, points2
	#   # f_mat = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS)
	#   f_mat_arr = [0.000266883, 0.000140277, -0.0445223,
	#                -0.00012592, 0.000245543, -0.108868,
	#                -0.00407942, -0.00291097, 1]
	#   test_func.call(mat1, mat2, f_mat_arr, num_points)
	#   # input points are 2xN matrix
	#   points1 = [[17, 370, 192, 614, 116, 305, 249, 464, 259, 460],
	#              [175, 24, 456, 202, 111, 32, 268, 157, 333, 224]]
	#   points2 = [[295, 584, 67, 400, 330, 480, 181, 350, 176, 333],
	#              [28, 221, 172, 443, 9, 140, 140, 265, 193, 313]]
	#   mat1 = Cv::Mat.new(2, num_points, CV_64F, 1)
	#   mat2 = Cv::Mat.new(2, num_points, CV_64F, 1)
	#   points1.flatten.each_with_index { |pt, i|
	#     mat1[i] = Cv::Scalar.new(pt)
	#   }
	#   points2.flatten.each_with_index { |pt, i|
	#     mat2[i] = Cv::Scalar.new(pt)
	#   }
	#   test_func.call(mat1, mat2, f_mat_arr, num_points)
	#
	#   f_mat = Cv::Mat.new(3, 3, CV_64F, 1)
	#   f_mat_arr.each_with_index { |a, i|
	#     f_mat[i] = Cv::Scalar.new(a)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.compute_correspond_epilines(DUMMY_OBJ, 1, f_mat)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.compute_correspond_epilines(mat1, DUMMY_OBJ, f_mat)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.compute_correspond_epilines(mat1, 1, DUMMY_OBJ)
	#   }
	# end
	#
	# def test_find_fundamental_mat
	#   points1 = [[488.362, 169.911],
	#              [449.488, 174.44],
	#              [408.565, 179.669],
	#              [364.512, 184.56],
	#              [491.483, 122.366],
	#              [451.512, 126.56],
	#              [409.502, 130.342],
	#              [365.5, 134.0],
	#              [494.335, 74.544],
	#              [453.5, 76.5],
	#              [411.646, 79.5901],
	#              [366.498, 81.6577],
	#              [453.5, 76.5],
	#              [411.646, 79.5901],
	#              [366.498, 81.6577]]
	#
	#   points2 =  [[526.605, 213.332],
	#               [470.485, 207.632],
	#               [417.5, 201.0],
	#               [367.485, 195.632],
	#               [530.673, 156.417],
	#               [473.749, 151.39],
	#               [419.503, 146.656],
	#               [368.669, 142.565],
	#               [534.632, 97.5152],
	#               [475.84, 94.6777],
	#               [421.16, 90.3223],
	#               [368.5, 87.5],
	#               [475.84, 94.6777],
	#               [421.16, 90.3223],
	#               [368.5, 87.5]]
	#   # 7 point
	#   num_points = 7
	#   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   points1[0...num_points].each_with_index { |pt, i|
	#     mat1[i, 0] = Cv::Scalar.new(pt[0])
	#     mat1[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   points2[0...num_points].each_with_index { |pt, i|
	#     mat2[i, 0] = Cv::Scalar.new(pt[0])
	#     mat2[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   f_mat1 = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_7POINT)
	#   f_mat2, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_7POINT, :with_status => true)
	#   expected = [0.000009, 0.000029, -0.010343,
	#               -0.000033, 0.000000, 0.014590,
	#               0.004415, -0.013420, 1.000000,
	#               0.000000, 0.000001, -0.000223,
	#               -0.000001, 0.000036, -0.005309,
	#               -0.000097, -0.006463, 1.000000,
	#               0.000002, 0.000005, -0.001621,
	#               -0.000005, 0.000031, -0.002559,
	#               0.000527, -0.007424, 1.000000]
	#   [f_mat1, f_mat2].each { |f_mat|
	#     assert_equal(9, f_mat.rows)
	#     assert_equal(3, f_mat.cols)
	#     expected.each_with_index { |val, i|
	#       assert_in_delta(val, f_mat[i][0], 1.0e-5)
	#     }
	#   }
	#   assert_equal(num_points, status.cols)
	#   num_points.times { |i|
	#     assert_in_delta(1, status[i][0], 1.0e-5)
	#   }
	#   # 8 point
	#   num_points = 8
	#   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   points1[0...num_points].each_with_index { |pt, i|
	#     mat1[i, 0] = Cv::Scalar.new(pt[0])
	#     mat1[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   points2[0...num_points].each_with_index { |pt, i|
	#     mat2[i, 0] = Cv::Scalar.new(pt[0])
	#     mat2[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   f_mat1 = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_8POINT)
	#   f_mat2, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_8POINT, :with_status => true)
	#   expected = [0.000001, 0.000004, -0.001127,
	#               -0.000005, 0.000038, -0.003778,
	#               0.000819, -0.008325, 1.000000]
	#   [f_mat1, f_mat2].each { |f_mat|
	#     assert_equal(3, f_mat.rows)
	#     assert_equal(3, f_mat.cols)
	#     expected.each_with_index { |val, i|
	#       assert_in_delta(val, f_mat[i][0], 1.0e-5)
	#     }
	#   }
	#   assert_equal(num_points, status.cols)
	#   num_points.times { |i|
	#     assert_in_delta(1, status[i][0], 1.0e-5)
	#   }
	#   # RANSAC default
	#   num_points = points1.size
	#   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   points1[0...num_points].each_with_index { |pt, i|
	#     mat1[i, 0] = Cv::Scalar.new(pt[0])
	#     mat1[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   points2[0...num_points].each_with_index { |pt, i|
	#     mat2[i, 0] = Cv::Scalar.new(pt[0])
	#     mat2[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   [Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC, :with_status => false,
	#                               :maximum_distance => 1.0, :desirable_level => 0.99),
	#    Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC)].each { |f_mat|
	#     assert_equal(3, f_mat.rows)
	#     assert_equal(3, f_mat.cols)
	#     expected = [0.000010, 0.000039, -0.011141,
	#                 -0.000045, -0.000001, 0.019631,
	#                 0.004873, -0.017604, 1.000000]
	#     expected.each_with_index { |val, i|
	#       assert_in_delta(val, f_mat[i][0], 1.0e-5)
	#     }
	#   }
	#
	#   # RANSAC with options
	#   f_mat, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_RANSAC, :with_status => true,
	#                                              :maximum_distance => 2.0, :desirable_level => 0.8)
	#   assert_equal(3, f_mat.rows)
	#   assert_equal(3, f_mat.cols)
	#   assert_equal(1, status.rows)
	#   assert_equal(num_points, status.cols)
	#   expected_f_mat = [0.000009, 0.000030, -0.010692,
	#                     -0.000039, 0.000000, 0.020567,
	#                     0.004779, -0.018064, 1.000000]
	#   expected_f_mat.each_with_index { |val, i|
	#     assert_in_delta(val, f_mat[i][0], 1.0e-5)
	#   }
	#   expected_status = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
	#   expected_status.each_with_index { |val, i|
	#     assert_in_delta(val, status[i][0], 1.0e-5)
	#   }
	#   # LMedS default
	#   num_points = 12
	#   mat1 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   mat2 = Cv::Mat.new(num_points, 2, :cv64f, 1)
	#   points1[0...num_points].each_with_index { |pt, i|
	#     mat1[i, 0] = Cv::Scalar.new(pt[0])
	#     mat1[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   points2[0...num_points].each_with_index { |pt, i|
	#     mat2[i, 0] = Cv::Scalar.new(pt[0])
	#     mat2[i, 1] = Cv::Scalar.new(pt[1])
	#   }
	#   [Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS, :with_status => false,
	#                               :maximum_distance => 1.0, :desirable_level => 0.99),
	#    Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS)].each { |f_mat|
	#     assert_equal(3, f_mat.rows)
	#     assert_equal(3, f_mat.cols)
	#     expected = [0.0, 0.0, 0.0,
	#                 0.0, 0.0, 0.0,
	#                 0.0, 0.0, 1.0]
	#     expected.each_with_index { |val, i|
	#       assert_in_delta(val, f_mat[i][0], 0.1)
	#     }
	#   }
	#
	#   # LMedS with options
	#   f_mat, status = Cv::Mat.find_fundamental_mat(mat1, mat2, CV_FM_LMEDS, :with_status => true,
	#                                              :desirable_level => 0.8)
	#   assert_equal(3, f_mat.rows)
	#   assert_equal(3, f_mat.cols)
	#   assert_equal(1, status.rows)
	#   assert_equal(num_points, status.cols)
	#   expected_fmat = [0.0, 0.0, 0.0,
	#                    0.0, 0.0, 0.0,
	#                    0.0, 0.0, 1.0]
	#   expected_f_mat.each_with_index { |val, i|
	#     assert_in_delta(val, f_mat[i][0], 0.1)
	#   }
	#   expected_status = [0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1]
	#   expected_status.each_with_index { |val, i|
	#     assert_equal(val, status[i][0].to_i)
	#   }
	#   [CV_FM_7POINT, CV_FM_8POINT, CV_FM_RANSAC, CV_FM_LMEDS].each { |method|
	#     assert_raise(TypeError) {
	#       Cv::Mat.find_fundamental_mat(DUMMY_OBJ, mat2, method, :with_status => true)
	#     }
	#     assert_raise(TypeError) {
	#       Cv::Mat.find_fundamental_mat(mat1, DUMMY_OBJ, method, :with_status => true)
	#     }
	#     assert_raise(TypeError) {
	#       Cv::Mat.find_fundamental_mat(mat1, mat2, method, DUMMY_OBJ)
	#     }
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.find_fundamental_mat(mat1, mat2, DUMMY_OBJ, :with_status => true)
	#   }
	# end
	#
	# def test_find_homography
	#   # Nx2
	#   src = Cv::Mat.new(4, 2, :cv32f, 1)
	#   dst = Cv::Mat.new(4, 2, :cv32f, 1)
	#   # Nx3 (Homogeneous coordinates)
	#   src2 = Cv::Mat.new(4, 3, :cv32f, 1)
	#   dst2 = Cv::Mat.new(4, 3, :cv32f, 1)
	#
	#   # Homography
	#   #   <src>     =>    <dst>
	#   # (0, 0)      =>  (50, 0)
	#   # (255, 0)    =>  (205, 0)
	#   # (255, 255)  =>  (255, 220)
	#   # (0, 255)    =>  (0, 275)
	#   [[0, 0], [255, 0], [255, 255], [0, 255]].each_with_index { |coord, i|
	#     src[i, 0] = coord[0]
	#     src[i, 1] = coord[1]
	#     src2[i, 0] = coord[0] * 2
	#     src2[i, 1] = coord[1] * 2
	#     src2[i, 2] = 2
	#   }
	#   [[50, 0], [205, 0], [255, 220], [0, 275]].each_with_index { |coord, i|
	#     dst[i, 0] = coord[0]
	#     dst[i, 1] = coord[1]
	#     dst2[i, 0] = coord[0] * 2
	#     dst2[i, 1] = coord[1] * 2
	#     dst2[i, 2] = 2
	#   }
	#   mat1 = Cv::Mat.find_homography(src, dst)
	#   mat2 = Cv::Mat.find_homography(src, dst, :all)
	#   mat3 = Cv::Mat.find_homography(src, dst, :ransac)
	#   mat4 = Cv::Mat.find_homography(src, dst, :lmeds)
	#   mat5, status5 = Cv::Mat.find_homography(src, dst, :ransac, 5, true)
	#   mat6, status6 = Cv::Mat.find_homography(src, dst, :ransac, 5, true)
	#   mat7 = Cv::Mat.find_homography(src, dst, :ransac, 5, false)
	#   mat8 = Cv::Mat.find_homography(src, dst, :ransac, 5, nil)
	#   mat9 = Cv::Mat.find_homography(src, dst, :all, 5, true)
	#   mat10, status10 = Cv::Mat.find_homography(src2, dst2, :ransac, 5, true)
	#   [mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10].each { |mat|
	#     assert_equal(3, mat.rows)
	#     assert_equal(3, mat.cols)
	#     assert_equal(:cv32f, mat.depth)
	#     assert_equal(1, mat.channel)
	#     [0.72430, -0.19608, 50.0,
	#      0.0, 0.62489, 0.0,
	#      0.00057, -0.00165, 1.0].each_with_index { |x, i|
	#       assert_in_delta(x, mat[i][0], 0.0001)
	#     }
	#   }
	#
	#   [status5, status6, status10].each { |status|
	#     assert_equal(1, status.rows)
	#     assert_equal(4, status.cols)
	#     assert_equal(:cv8u, status.depth)
	#     assert_equal(1, status.channel)
	#     4.times { |i|
	#       assert_in_delta(1.0, status[i][0], 0.0001)
	#     }
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.find_homography(DUMMY_OBJ, dst, :ransac, 5, true)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.find_homography(src, DUMMY_OBJ, :ransac, 5, true)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.find_homography(src, dst, DUMMY_OBJ, 5, true)
	#   }
	#   assert_raise(TypeError) {
	#     Cv::Mat.find_homography(src, dst, :ransac, DUMMY_OBJ, true)
	#   }
	#   Cv::Mat.find_homography(src, dst, :ransac, 5, DUMMY_OBJ)
	# end
	#

end
