#!/usr/bin/env ruby
require 'digest/md5'
require File.join(__dir__, 'helper')

# Tests to run first; check the handful of basic operations that the later tests rely on
class PreliminaryTest < OpenCVTestCase
  def test_assert_array_equal
    assert_array_equal([1, 2, 3, 4], [1, 2, 3, 4])
    # Uncomment the following line to check the fail case
    # assert_array_equal([1, 2, 3, 4], [1, 2, 3, 0])
  end

  def test_assert_cvscalar_equal
    assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), Cv::Scalar.new(1, 2, 3, 4))
    assert_cvscalar_equal(Cv::Scalar.new(0.1, 0.2, 0.3, 0.4), Cv::Scalar.new(0.1, 0.2, 0.3, 0.4))
    # Uncomment the following lines to check the fail cases
    # assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), Cv::Scalar.new(1, 2, 3, 0))
    # assert_cvscalar_equal(Cv::Scalar.new(0.1, 0.2, 0.3, 0.4), Cv::Scalar.new(0.1, 0.2, 0.3, 0.0))
  end

  
  def test_assert_in_delta
    assert_in_delta(1, 0.9999, 0.1)
    assert_in_delta(Cv::Scalar.new(1, 2, 3, 4), Cv::Scalar.new(1.01, 2.01, 3.01, 4.01), 0.1)
    assert_in_delta(Cv::Scalar.new(1, 2, 3, 4), [1.01, 2.01, 3.01, 4.01], 0.1)
    assert_in_delta([1, 2, 3, 4], Cv::Scalar.new(1.01, 2.01, 3.01, 4.01), 0.1)
    assert_in_delta([1, 2, 3, 4], [1.01, 2.01, 3.01, 4.01], 0.1)
    # Uncomment the following lines to check the fail cases
    # assert_in_delta(1, 0.009, 0.1)
    # assert_in_delta(Cv::Scalar.new(1, 2, 3, 4), Cv::Scalar.new(1.01, 2.01, 3.01, 4.01), 0.001)
    # assert_in_delta(Cv::Scalar.new(1, 2, 3, 4), [1.01, 2.01, 3.01, 4.01], 0.001)
    # assert_in_delta([1, 2, 3, 4], Cv::Scalar.new(1.01, 2.01, 3.01, 4.01), 0.001)
    # assert_in_delta([1, 2, 3, 4], [1.01, 2.01, 3.01, 4.01], 0.001)
  end

  def test_assert_each_element
    mat1 = Cv::Mat.new(5, 5, :cv32f, 4)
    mat2 = Cv::Mat.new(5, 5, :cv32f, 4)
    c = 0
    mat1.height.times { |j|
      mat1.width.times { |i|
        mat1[j, i] = Cv::Scalar.new(c * 0.1, c * 0.2, c * 0.3, c * 0.4)
        mat2[j, i] = Cv::Scalar.new(c, c, c, c)
        c += 1
      }
    }
    
    assert_each_element(mat1, 0.001) { |j, i, n|
      Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, n * 0.4)
    }
    assert_each_element(mat2) { |j, i, n|
      Cv::Scalar.new(n, n, n, n)
    }
    
    # Uncomment the following lines to check the fail cases
    # assert_each_element(mat1, 0.001) { |j, i, n|
    #   Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, 0)
    # }
    # assert_each_element(mat1, 0.001) { |j, i, n|
    #   Cv::Scalar.new(1, 2, 3, 4)
    # }
    # assert_each_element(mat2) { |j, i, n|
    #   Cv::Scalar.new(n * 0.1, n * 0.2, n * 0.3, 0)
    # }
    # assert_each_element(mat2) { |j, i, n|
    #   Cv::Scalar.new(1, 2, 3, 0)
    # }
  end

  def test_create_mat
    mat = create_mat(3, 4)
    assert_equal(3, mat.rows)
    assert_equal(4, mat.cols)
    assert_equal(CV_8U, mat.depth)
    assert_equal(4, mat.channels)
    c = 0
    mat.rows.times { |j|
      mat.cols.times { |i|
        s = Cv::Scalar.new(c + 1, c + 1, c + 1, c + 1)
        assert_cvscalar_equal(s, mat[j, i])
        c += 1
      }
    }
    mat = create_mat(2, 3, CV_16SC2)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_16S, mat.depth)
    assert_equal(2, mat.channels)
    c = 0
    mat.rows.times { |j|
      mat.cols.times { |i|
        s = Cv::Scalar.new(c + 1, c + 1, 0, 0)
        assert_cvscalar_equal(s, mat[j, i])
        c += 1
      }
    }
    mat = create_mat(2, 3, CV_16UC3) { |j, i, cnt|
      n = j + i + cnt
      Cv::Scalar.new(n, n, n, 0)
    }
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(:cv16u, mat.depth)
    assert_equal(3, mat.channels)
    c = 0
    mat.rows.times { |j|
      mat.cols.times { |i|
        n = j + i + c
        assert_cvscalar_equal(Cv::Scalar.new(n, n, n, 0), mat[j, i])
        c += 1
      }
    }
  end
end
