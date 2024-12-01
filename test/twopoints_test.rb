#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class TwoPointsTest < OpenCVTestCase
  def setup
    @twopoints = Cv::TwoPoints.new
  end

  
  def test_initialize
    assert_not_nil(@twopoints)
    assert_equal(Cv::TwoPoints, @twopoints.class)
  end

  def test_point
    assert_not_nil(@twopoints.point1)
    assert_not_nil(@twopoints.point2)
    assert_equal(Cv::Point, @twopoints.point1.class)
    assert_equal(Cv::Point, @twopoints.point2.class)
  end

  def test_aref
    assert_not_nil(@twopoints[0])
    assert_not_nil(@twopoints[1])
    assert_equal(Cv::Point, @twopoints[0].class)
    assert_equal(Cv::Point, @twopoints[1].class)
  end

  def test_to_ary
    assert_equal(Array, @twopoints.to_ary.class)
    assert_equal(2, @twopoints.to_ary.size)
    assert_equal(2, @twopoints.to_a.size)
  end
end
