#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::Circle32f
class TestCircle32f < OpenCVTestCase
  def setup
    @circle = Cv::Circle32f.new
  end

  
  def test_initialize
    assert_equal(Cv::Circle32f, @circle.class)
  end

  def test_center
    assert_equal(Cv::Point2D32f, @circle.center.class)
  end

  def test_radius
    assert_equal(Float, @circle.radius.class)
  end

  def test_aref
    assert_equal(Float, @circle[0].class)
    assert_equal(Float, @circle[1].class)
    assert_equal(Float, @circle[2].class)
    assert_raise(IndexError) {
      @circle[3]
    }
  end

  def test_to_ary
    assert_equal(Array, @circle.to_ary.class)
    assert_equal(2, @circle.to_ary.size)
  end
end
