#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class CurveTest < OpenCVTestCase
  def setup
    @contour1 = Cv::Contour.new
    
    mat0 = create_mat(128, 128, CV_8UC1) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    @contour2 = mat0.find_contours
  end

  def test_closed
    assert_false(@contour1.closed?)
    assert(@contour2.closed?)
  end

  def test_convex
    assert_false(@contour1.convex?)
  end

  def test_hole
    assert_false(@contour1.hole?)
  end

  def test_simple
    assert(@contour1.simple?)
  end

  def test_arc_length
    assert_in_delta(211.480, @contour2.arc_length, 0.001)
    assert_in_delta(32.181, @contour2.arc_length(Cv::Slice.new(0, 9), true), 0.001)
    assert_in_delta(32.181, @contour2.arc_length(0..10, true), 0.001)
  end
end
