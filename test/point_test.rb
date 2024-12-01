#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Point
class PointTest < OpenCVTestCase
  class MyPoint; end

  def test_x
    point = Cv::Point.new
    point.x = 100
    assert_equal(100, point.x)
    point.x = 200
    assert_equal(200, point.x)
  end

  def test_y
    point = Cv::Point.new
    point.y = 100
    assert_equal(100, point.y)
    point.y = 200
    assert_equal(200, point.y)
  end

  
  def test_compatible
    assert(!(Cv::Point.compatible? MyPoint.new))
    MyPoint.class_eval { def x; end }
    assert(!(Cv::Point.compatible? MyPoint.new))
    MyPoint.class_eval { def y; end }
    assert(Cv::Point.compatible? MyPoint.new)
    assert(Cv::Point.compatible? Cv::Point.new)
  end

  def test_initialize
    point = Cv::Point.new
    assert_equal(0, point.x)
    assert_equal(0, point.y)
    point = Cv::Point.new(10, 20)
    assert_equal(10, point.x)
    assert_equal(20, point.y)
    point = Cv::Point.new(Cv::Point.new(10, 20))
    assert_equal(10, point.x)
    assert_equal(20, point.y)
    assert_raise(TypeError) {
      Cv::Point.new(DUMMY_OBJ)
    }
    assert_raise(ArgumentError) {
      Cv::Point.new(1, 2, 3)
    }
  end

  def test_to_s
    point = Cv::Point.new(10, 20)
    assert_equal('<OpenCV::Cv::Point:(10,20)>', point.to_s)
  end

  def test_to_ary
    a = Cv::Point.new(10, 20).to_ary
    assert_equal(10, a[0])
    assert_equal(20, a[1])
    # Alias
    a = Cv::Point.new(10, 20).to_a
    assert_equal(10, a[0])
    assert_equal(20, a[1])
  end
end

