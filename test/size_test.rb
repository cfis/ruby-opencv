#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Size
class SizeTest < OpenCVTestCase
  class MySize; end

  def test_width
    size = Cv::Size.new
    size.width = 100
    assert_equal(100, size.width)
    size.width = 200
    assert_equal(200, size.width)
  end

  def test_height
    size = Cv::Size.new
    size.height = 100
    assert_equal(100, size.height)
    size.height = 200
    assert_equal(200, size.height)
  end

  def test_compatible
    assert(!(Cv::Size.compatible? MySize.new))
    MySize.class_eval { def width; end }
    assert(!(Cv::Size.compatible? MySize.new))
    MySize.class_eval { def height; end }
    assert(Cv::Size.compatible? MySize.new)
    assert(Cv::Size.compatible? Cv::Size.new)
  end

  def test_initialize
    size = Cv::Size.new
    assert_equal(0, size.width)
    assert_equal(0, size.height)
    size = Cv::Size.new(10, 20)
    assert_equal(10, size.width)
    assert_equal(20, size.height)
    size = Cv::Size.new(Cv::Size.new(10, 20))
    assert_equal(10, size.width)
    assert_equal(20, size.height)
    assert_raise(TypeError) {
      Cv::Size.new(DUMMY_OBJ)
    }
    assert_raise(ArgumentError) {
      Cv::Size.new(1, 2, 3)
    }
  end

  def test_to_s
    size = Cv::Size.new(10, 20)
    assert_equal('<OpenCV::Cv::Size:10x20>', size.to_s)
  end

  def test_to_ary
    a = Cv::Size.new(10, 20).to_ary
    assert_equal(10, a[0])
    assert_equal(20, a[1])
    # Alias
    a = Cv::Size.new(10, 20).to_a
    assert_equal(10, a[0])
    assert_equal(20, a[1])
  end
end
