#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Mat
class MatxTest < OpenCVTestCase
  def test_create
    matx = Cv::Matx12f.new([10, 20])
    assert_equal(Cv::Matx12f::Rows, 1)
    assert_equal(Cv::Matx12f::Cols, 2)
    assert_equal(Cv::Matx12f::Channels, 2)
    assert_equal(Cv::Matx12f::Shortdim, 1)
    assert_equal(matx.rows, 1)
    assert_equal(matx.cols, 2)
    assert_equal(matx.channels, 2)
    assert_equal(matx.shortdim, 1)

    assert_equal("[10, 20]", matx.inspect)
    assert_equal("[10, 20]", matx.row(0).inspect)
    assert_equal("[10]", matx.col(0).inspect)
    assert_equal("[20]", matx.col(1).inspect)
  end

  def test_create_multidimension
    matx = Cv::Matx33d.new([10, 20, 30,
                            40, 50, 60,
                            70, 80, 90])
    assert_equal("[10, 20, 30;\n 40, 50, 60;\n 70, 80, 90]", matx.inspect)
    assert_equal("[20;\n 50;\n 80]", matx.col(1).inspect)
    assert_equal("[40, 50, 60]", matx.row(1).inspect)
    assert_equal("[10;\n 50;\n 90]", matx.diag.inspect)
    assert_equal( "[10, 40, 70;\n 20, 50, 80;\n 30, 60, 90]", matx.t.inspect)
  end

  def test_singleton_methods
    assert_equal("[0, 0, 0;\n 0, 0, 0;\n 0, 0, 0]", Cv::Matx33d.zeros.inspect)
    assert_equal("[1, 1, 1;\n 1, 1, 1;\n 1, 1, 1]", Cv::Matx33d.ones.inspect)
    assert_equal("[1, 0, 0;\n 0, 1, 0;\n 0, 0, 1]", Cv::Matx33d.eye.inspect)
    assert_equal("[4, 4, 4;\n 4, 4, 4;\n 4, 4, 4]", Cv::Matx33d.all(4).inspect)
  end

  def test_out_of_bounds
    matx = Cv::Matx12f.new([10, 20])
    exception = assert_raises(RuntimeError) do
      matx.row(1)
    end
    assert_match(/Assertion failed/, exception.to_s)

    exception = assert_raises(RuntimeError) do
      matx.col(2).inspect
    end
    assert_match(/Assertion failed/, exception.to_s)
  end

  def test_dot_product
    m1 = Cv::Matx22f.new
    # (m1.)
    #, :cv32f, 1) { |j, i, c|
    #  Cv::Scalar.new(c * 0.5)
    #}
    m2 = create_cvmat(2, 2, :cv32f, 1) { |j, i, c|
      Cv::Scalar.new(c * 1.5)
    }
    assert_in_delta(10.5, m1.dot_product(m2), 0.001)
    m1 = create_cvmat(2, 2, :cv32f) { |j, i, c|
      Cv::Scalar.new(c * 0.5, c * 0.6, c * 0.7, c * 0.8)
    }
    m2 = create_cvmat(2, 2, :cv32f) { |j, i, c|
      Cv::Scalar.new(c * 1.5, c * 2.0, c * 2.5, c * 3.0)
    }
    assert_in_delta(85.39999, m1.dot_product(m2), 0.001)
    assert_raise(TypeError) {
      m1.dot_product(DUMMY_OBJ)
    }
  end
end
