#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::TermCriteria
class TermCriteriaTest < OpenCVTestCase
  def setup
    @criteria1 = Cv::TermCriteria.new
    @criteria2 = Cv::TermCriteria.new(100)
    @criteria3 = Cv::TermCriteria.new(nil, 0.01)
    @criteria4 = Cv::TermCriteria.new(100, 0.01)
  end

  
  def test_initialize
    assert_not_nil(@criteria1)
    assert_equal(Cv::TermCriteria, @criteria1.class)
    assert_not_nil(@criteria2)
    assert_equal(Cv::TermCriteria, @criteria2.class)
    assert_not_nil(@criteria3)
    assert_equal(Cv::TermCriteria, @criteria3.class)
    assert_not_nil(@criteria4)
    assert_equal(Cv::TermCriteria, @criteria4.class)
  end

  def test_type
    assert_equal(0, @criteria1.type)
    assert_equal(CV_TERMCRIT_ITER, @criteria2.type)
    assert_equal(CV_TERMCRIT_EPS, @criteria3.type)
    assert_equal(CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, @criteria4.type)
  end

  def test_max
    assert_nil(@criteria1.max)
    assert_equal(100, @criteria2.max)
    assert_nil(@criteria3.max)
    assert_equal(100, @criteria4.max)
    @criteria1.max = 999
    assert_equal(999, @criteria1.max)
  end

  def test_eps
    assert_nil(@criteria1.eps)
    assert_nil(@criteria2.eps)
    assert_in_delta(0.01, @criteria3.eps, 0.001)
    assert_in_delta(0.01, @criteria4.eps, 0.001)
    @criteria1.eps = 3.14
    assert_in_delta(3.14, @criteria1.eps, 0.001)
  end
end
