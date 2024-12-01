#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::AvgComp
class AvgCompTest < OpenCVTestCase
  def setup
    @avgcomp = Cv::AvgComp.new
  end

  def test_initialize
    assert_equal(Cv::AvgComp, @avgcomp.class)
    assert(@avgcomp.is_a? Cv::Rect)
  end

  def test_neighbors
    assert_kind_of(Integer, @avgcomp.neighbors)
  end
end
