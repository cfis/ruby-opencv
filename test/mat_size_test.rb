#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MatSizeTest < OpenCVTestCase
	def test_mat_size
		mat = Cv::Mat.new(2, 3, CV_32FC4)

		mat_size = mat.size
		assert_kind_of(Cv::MatSize, mat_size)
		assert_equal(2, mat_size[0])
		assert_equal(3, mat_size[1])
		assert_raises(Cv::StsAssert) do
			mat_size[2]
		end
	end

	def test_dims
		mat = Cv::Mat.new(4, 3, CV_32FC4)
		mat_size = mat.size
		dims = mat_size.dims
		assert_equal(2, dims)
	end

	def test_p
		mat = Cv::Mat.new(5, 3, CV_32FC4)
		mat_size = mat.size

		buffer = mat_size.p.buffer(0, 1)
		assert_equal("\x05\x00\x00\x00", buffer)

		array = mat_size.p.to_array(0, 1)
		assert_equal([5], array)
	end
end
