#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ConnectedCompTest < OpenCVTestCase
  def setup
    @connected_comp = Cv::ConnectedComp.new(9216, Cv::Scalar.new(1, 2, 3, 4),
                                          Cv::Rect.new(1, 2, 3, 4), Cv::Seq.new(CV_SEQ_ELTYPE_INDEX))
  end

  
  def test_initialize
    connected_comp = Cv::ConnectedComp.new
    assert_equal(Cv::ConnectedComp, connected_comp.class)
    assert_not_nil(connected_comp.area)
    assert_not_nil(connected_comp.value)
    assert_not_nil(connected_comp.rect)
    assert_not_nil(connected_comp.contour)
    connected_comp = Cv::ConnectedComp.new(100, Cv::Scalar.new(1, 2, 3, 4),
                                         Cv::Rect.new(1, 2, 3, 4), Cv::Seq.new(CV_SEQ_ELTYPE_POINT))
    assert_equal(Cv::ConnectedComp, connected_comp.class)
    assert_not_nil(connected_comp.area)
    assert_not_nil(connected_comp.value)
    assert_not_nil(connected_comp.rect)
    assert_not_nil(connected_comp.contour)
  end

  def test_area
    assert_in_delta(9216.0, @connected_comp.area, 0.01)
  end

  def test_value
    assert_equal(Cv::Scalar, @connected_comp.value.class)
    assert_cvscalar_equal(Cv::Scalar.new(1, 2, 3, 4), @connected_comp.value)
  end

  def test_rect
    assert_equal(Cv::Rect, @connected_comp.rect.class)
    assert_equal(1, @connected_comp.rect.x)
    assert_equal(2, @connected_comp.rect.y)
    assert_equal(3, @connected_comp.rect.width)
    assert_equal(4, @connected_comp.rect.height)
    @connected_comp.rect = Cv::Rect.new(10, 20, 30, 40);
    assert_equal(10, @connected_comp.rect.x)
    assert_equal(20, @connected_comp.rect.y)
    assert_equal(30, @connected_comp.rect.width)
    assert_equal(40, @connected_comp.rect.height)
  end

  def test_contour
    assert_equal(Cv::Contour, @connected_comp.contour.class)
    assert_not_nil(@connected_comp.contour)
  end
end
