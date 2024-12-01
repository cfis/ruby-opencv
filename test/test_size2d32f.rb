#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::Size2D32f
class TestSize2D32f < OpenCVTestCase
  class MySize; end

  def test_width
    size = Cv::Size2D32f.new
    size.width = 1.1
    assert_in_delta(1.1, size.width, 0.001)
    size.width = 2.2
    assert_in_delta(2.2, size.width, 0.001)
  end

  def test_height
    size = Cv::Size2D32f.new
    size.height = 1.1
    assert_in_delta(1.1, size.height, 0.001)
    size.height = 2.2
    assert_in_delta(2.2, size.height, 0.001)
  end

  def test_compatible
    assert(!(Cv::Size2D32f.compatible? MySize.new))
    MySize.class_eval { def width; end }
    assert(!(Cv::Size2D32f.compatible? MySize.new))
    MySize.class_eval { def height; end }
    assert(Cv::Size2D32f.compatible? MySize.new)
    assert(Cv::Size2D32f.compatible? Cv::Size2D32f.new)
  end

  def test_initialize
    size = Cv::Size2D32f.new
    assert_in_delta(0, size.width, 0.001)
    assert_in_delta(0, size.height, 0.001)
    size = Cv::Size2D32f.new(1.1, 2.2)
    assert_in_delta(1.1, size.width, 0.001)
    assert_in_delta(2.2, size.height, 0.001)
    size = Cv::Size2D32f.new(Cv::Size2D32f.new(1.1, 2.2))
    assert_in_delta(1.1, size.width, 0.001)
    assert_in_delta(2.2, size.height, 0.001)
    assert_raise(TypeError) {
      Cv::Size2D32f.new(DUMMY_OBJ)
    }
    assert_raise(ArgumentError) {
      Cv::Size2D32f.new(1, 2, 3)
    }
  end

  def test_to_s
    size = Cv::Size2D32f.new(1.1, 2.2)
    assert_equal('<OpenCV::Cv::Size2D32f:1.1x2.2>', size.to_s)
  end

  def test_to_ary
    a = Cv::Size2D32f.new(1.1, 2.2).to_ary
    assert_in_delta(1.1, a[0], 0.001)
    assert_in_delta(2.2, a[1], 0.001)
    # Alias
    a = Cv::Size2D32f.new(1.1, 2.2).to_a
    assert_in_delta(1.1, a[0], 0.001)
    assert_in_delta(2.2, a[1], 0.001)
  end
end
