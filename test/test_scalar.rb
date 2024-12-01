#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::Scalar
class TestScalar < OpenCVTestCase
  def test_initialize
    s = Cv::Scalar.new
    assert_in_delta([0, 0, 0, 0], s, 0.01)
    s = Cv::Scalar.new(1.1)
    assert_in_delta([1.1, 0, 0, 0], s, 0.01)
    s = Cv::Scalar.new(1.1, 2.2)
    assert_in_delta([1.1, 2.2, 0, 0], s, 0.01)
    s = Cv::Scalar.new(1.1, 2.2, 3.3)
    assert_in_delta([1.1, 2.2, 3.3, 0], s, 0.01)
    s = Cv::Scalar.new(1.1, 2.2, 3.3, 4.4)
    assert_in_delta([1.1, 2.2, 3.3, 4.4], s, 0.01)
  end

  
  def test_aref
    assert_in_delta([0, 0, 0, 0], Cv::Scalar.new, 0.01)
    assert_in_delta([10, 20, 30, 40], Cv::Scalar.new(10, 20, 30, 40), 0.01)
    assert_in_delta([0.1, 0.2, 0.3, 0.4], Cv::Scalar.new(0.1, 0.2, 0.3, 0.4), 0.01)
  end

  def test_aset
    s = Cv::Scalar.new
    [10, 20, 30, 40].each_with_index { |x, i|
      s[i] = x
    }
    assert_in_delta([10, 20, 30, 40], s, 0.01)
    s = Cv::Scalar.new
    [0.1, 0.2, 0.3, 0.4].each_with_index { |x, i|
      s[i] = x
    }
    assert_in_delta([0.1, 0.2, 0.3, 0.4], s, 0.01)
  end

  def test_sub
    s1 = Cv::Scalar.new(10, 20, 30, 40)
    s2 = Cv::Scalar.new(2, 4, 6, 8)
    [s1.sub(s2), s1 - s2].each { |s|
      assert_in_delta([8, 16, 24, 32], s, 0.01)
    }
    s3 = Cv::Scalar.new(0.2, 0.4, 0.6, 0.8)
    [s2.sub(s3), s2 - s3].each { |s|
      assert_in_delta([1.8, 3.6, 5.4, 7.2], s, 0.01)
    }
    mat = Cv::Mat.new(5, 5)
    mask = Cv::Mat.new(5, 5, :cv8u, 1)
    mat.height.times { |j|
      mat.width.times { |i|
        mat[i, j] = Cv::Scalar.new(1.5)
        mask[i, j] = (i < 2 and j < 3) ? 1 : 0
      }
    }
    mat = Cv::Scalar.new(0.1).sub(mat, mask)
    [Cv::Mat.new(5, 5, :cv16u, 1), Cv::Mat.new(5, 5, :cv8u, 3)].each { |msk|
      assert_raise(TypeError) {
        Cv::Scalar.new.sub(mat, msk)
      }
    }
  end

  def test_to_s
    assert_equal("<OpenCV::Cv::Scalar:10,20,30,40>", Cv::Scalar.new(10, 20, 30, 40).to_s)
    assert_equal("<OpenCV::Cv::Scalar:0.1,0.2,0.3,0.4>", Cv::Scalar.new(0.1, 0.2, 0.3, 0.4).to_s)
  end

  def test_to_ary
    [[10, 20, 30, 40], [0.1, 0.2, 0.3, 0.4]].each { |a|
      s = Cv::Scalar.new(*a)
      b = s.to_ary
      c = s.to_a # Alias
      [b, c].each { |x|
        assert_equal(Array, x.class)
        assert_in_delta(a, x, 0.01)
      }
    }
  end

  def test_cvcolor
    assert_cvscalar_equal(Cv::Color::Black, Cv::Scalar.new(0x0, 0x0, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Silver, Cv::Scalar.new(0x0c, 0x0c, 0x0c, 0))
    assert_cvscalar_equal(Cv::Color::Gray, Cv::Scalar.new(0x80, 0x80, 0x80, 0))
    assert_cvscalar_equal(Cv::Color::White, Cv::Scalar.new(0xff, 0xff, 0xff, 0))
    assert_cvscalar_equal(Cv::Color::Maroon, Cv::Scalar.new(0x0, 0x0, 0x80, 0))
    assert_cvscalar_equal(Cv::Color::Red, Cv::Scalar.new(0x0, 0x0, 0xff, 0))
    assert_cvscalar_equal(Cv::Color::Purple, Cv::Scalar.new(0x80, 0x0, 0x80, 0))
    assert_cvscalar_equal(Cv::Color::Fuchsia, Cv::Scalar.new(0xff, 0x0, 0xff, 0))
    assert_cvscalar_equal(Cv::Color::Green, Cv::Scalar.new(0x0, 0x80, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Lime, Cv::Scalar.new(0x0, 0xff, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Olive, Cv::Scalar.new(0x0, 0x80, 0x80, 0))
    assert_cvscalar_equal(Cv::Color::Yellow, Cv::Scalar.new(0x0, 0xff, 0xff, 0))
    assert_cvscalar_equal(Cv::Color::Navy, Cv::Scalar.new(0x80, 0x0, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Blue, Cv::Scalar.new(0xff, 0x0, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Teal, Cv::Scalar.new(0x80, 0x80, 0x0, 0))
    assert_cvscalar_equal(Cv::Color::Aqua, Cv::Scalar.new(0xff, 0xff, 0x0, 0))
  end
end
