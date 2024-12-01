#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class SparseMatTest < OpenCVTestCase
	# def test_initialize
	# 	mat = Cv::SparseMat.new
	# 	assert_equal(CV_8U, mat.depth)
	# 	assert_equal(CV_8U, mat.type)
	# 	assert_equal(1, mat.channels)
	# 	assert_nil(mat.size)
	# 	assert_equal(0, mat.dims)
	# 	assert_equal(0, mat.nzcount)
	# end

	def test_initialize_with_sizes
		sizes = [10, 10]
		mat = Cv::SparseMat.new(sizes.count, sizes, CV_32FC1)
		#assert_equal(0, mat.size)
		assert_equal(CV_32FC1, mat.depth)
		assert_equal(CV_32FC1, mat.type)
		assert_equal(1, mat.channels)
		assert_equal(2, mat.dims)
		assert_equal(0, mat.nzcount)
	end
end
