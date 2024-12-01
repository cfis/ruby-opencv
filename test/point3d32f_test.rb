#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Point3D32f
class Point3D32fTest < OpenCVTestCase
  class MyPoint; end

  def test_x
    point = Cv::Point3D32f.new
    point.x = 1.1
    assert_in_delta(1.1, point.x, 0.001)
    point.x = 2.2
    assert_in_delta(2.2, point.x, 0.001)
  end

  def test_y
    point = Cv::Point3D32f.new
    point.y = 1.1
    assert_in_delta(1.1, point.y, 0.001)
    point.y = 2.2
    assert_in_delta(2.2, point.y, 0.001)
  end

  def test_z
    point = Cv::Point3D32f.new
    point.z = 1.1
    assert_in_delta(1.1, point.z, 0.001)
    point.z = 2.2
    assert_in_delta(2.2, point.z, 0.001)
  end

  
  def test_compatible
    assert(!(Cv::Point3D32f.compatible? MyPoint.new))
    MyPoint.class_eval { def x; end }
    assert(!(Cv::Point3D32f.compatible? MyPoint.new))
    MyPoint.class_eval { def y; end }
    assert(!(Cv::Point3D32f.compatible? MyPoint.new))
    MyPoint.class_eval { def z; end }
    assert(Cv::Point3D32f.compatible? MyPoint.new)
    assert(Cv::Point3D32f.compatible? Cv::Point3D32f.new)
  end

  def test_initialize
    point = Cv::Point3D32f.new
    assert_in_delta(0, point.x, 0.001)
    assert_in_delta(0, point.y, 0.001)
    assert_in_delta(0, point.z, 0.001)
    point = Cv::Point3D32f.new(1.1, 2.2, 3.3)
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)
    assert_in_delta(3.3, point.z, 0.001)
    point = Cv::Point3D32f.new(Cv::Point3D32f.new(1.1, 2.2, 3.3))
    assert_in_delta(1.1, point.x, 0.001)
    assert_in_delta(2.2, point.y, 0.001)
    assert_in_delta(3.3, point.z, 0.001)
    assert_raise(TypeError) {
      Cv::Point3D32f.new(DUMMY_OBJ)
    }
    assert_raise(ArgumentError) {
      Cv::Point3D32f.new(1, 2)
    }
    assert_raise(ArgumentError) {
      Cv::Point3D32f.new(1, 2, 3, 4)
    }
  end

  def test_to_s
    point = Cv::Point3D32f.new(1.1, 2.2, 3.3)
    assert_equal('<OpenCV::Cv::Point3D32f:(1.1,2.2,3.3)>', point.to_s)
  end

  def test_to_ary
    a = Cv::Point3D32f.new(1.1, 2.2, 3.3).to_ary
    assert_in_delta(1.1, a[0], 0.001)
    assert_in_delta(2.2, a[1], 0.001)
    assert_in_delta(3.3, a[2], 0.001)
    # Alias
    a = Cv::Point3D32f.new(1.1, 2.2, 3.3).to_a
    assert_in_delta(1.1, a[0], 0.001)
    assert_in_delta(2.2, a[1], 0.001)
    assert_in_delta(3.3, a[2], 0.001)
  end
end

