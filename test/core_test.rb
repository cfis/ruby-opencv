# def test_subspace_project
#   w = Cv::Mat.new(10, 20, :cv32f, 1)
#   mean = Cv::Mat.new(w.rows, 1, :cv32f, 1)
#   mat = Cv::Mat.new(w.cols, w.rows, :cv32f, 1)
#   result = mat.1	`(w, mean)
#   assert_equal(Cv::Mat, result.class)
#   assert_equal(w.cols, result.rows)
#   assert_equal(w.cols, result.cols)
# end

# def test_subspace_reconstruct
#   w = Cv::Mat.new(10, 20, :cv32f, 1)
#   mean = Cv::Mat.new(w.rows, 1, :cv32f, 1)
#   mat = Cv::Mat.new(w.cols, w.cols, :cv32f, 1)
#   result = mat.subspace_reconstruct(w, mean)
#   assert_equal(Cv::Mat, result.class)
#   assert_equal(w.cols, result.rows)
#   assert_equal(w.rows, result.cols)
# end
