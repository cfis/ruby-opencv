#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Line
class LineTest < OpenCVTestCase
  def setup
    @line = Cv::Line.new
  end

  
  def test_initialize
    assert_not_nil(@line)
    assert_equal(Cv::Line, @line.class)
  end

  def test_rho
    @line.rho = 0.0
    assert_in_delta(0.0, @line.rho, 0.001)
    @line.rho = 3.14
    assert_in_delta(3.14, @line.rho, 0.001)
  end

  def test_theta
    @line.theta = 0.0
    assert_in_delta(0.0, @line.theta, 0.001)
    @line.theta = 3.14
    assert_in_delta(3.14, @line.theta, 0.001)
  end

  def test_aref_aset
    @line[0] = 0.0
    @line[1] = 0.0
    assert_in_delta(0.0, @line[0], 0.001)
    assert_in_delta(0.0, @line[1], 0.001)
    @line[0] = 3.14
    @line[1] = 2.71
    assert_in_delta(3.14, @line[0], 0.001)
    assert_in_delta(2.71, @line[1], 0.001)
    assert_raise(IndexError) {
      @line[2] = 1
    }
  end
end
