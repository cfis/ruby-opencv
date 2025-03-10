#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class PointSetTest < OpenCVTestCase
  def setup
    mat0 = create_mat(128, 128, CV_8UC1) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    @contour1 = mat0.find_contours
    @contour2 = Cv::Contour.new
  end

  def test_contour_area
    assert_equal(3118, @contour1.contour_area.to_i)
    
    s = Cv::Slice.new(0, @contour1.size / 2)
    assert_equal(1527, @contour1.contour_area(s).to_i)
    assert_raise(TypeError) {
      @contour1.contour_area(DUMMY_OBJ)
    }
    assert_raise(Cv::StsBadArg) {
      @contour2.contour_area
    }
  end

  def test_fit_ellipse2
    box = @contour1.fit_ellipse2
    center = box.center
    assert_equal(64, center.x.to_i)
    assert_equal(64, center.y.to_i)
    size = box.size
    assert_in_delta(63, size.width, 1.0)
    assert_in_delta(63, size.height, 1.0)
    angle = [box.angle, 180 - box.angle].min
    assert_in_delta(0, angle, 0.1)
    assert_raise(Cv::StsBadSize) {
      @contour2.fit_ellipse2
    }
  end

  def test_convex_hull2
    [@contour1.convex_hull2, @contour1.convex_hull2(true)].each { |hull|
      assert_equal(36, hull.size)
      assert_equal(Cv::Contour, hull.class)
      assert_equal(Cv::Point, hull[0].class)
      assert_equal(32, hull[0].x)
      assert_equal(64, hull[0].y)
    }
    hull = @contour1.convex_hull2(false)
    assert_equal(36, hull.size)
    assert_equal(Cv::Contour, hull.class)
    assert_equal(Cv::Point, hull[0].class)
    assert_equal(96, hull[0].x)
    assert_equal(64, hull[0].y)
    @contour1.convex_hull2(DUMMY_OBJ)
  end

  def test_check_contour_convexity
    assert_false(@contour1.check_contour_convexity)
  end

  def test_convexity_defects
    hull = @contour1.convex_hull2(true, false)
    defects = @contour1.convexity_defects(hull)
    assert_equal(Cv::Seq, defects.class)
    assert_equal(Cv::ConvexityDefect, defects[0].class)
    assert_equal(32, defects.size)
    d = defects[0]
    assert_equal(33, d.start.x)
    assert_equal(57, d.start.y)
    assert_equal(33, d.depth_point.x)
    assert_equal(63, d.depth_point.y)
    assert_equal(32, d.end.x)
    assert_equal(64, d.end.y)
    assert_in_delta(0.8485, d.depth, 0.001)
    assert_raise(TypeError) {
      @contour1.convexity_defects(DUMMY_OBJ)
    }
  end

  def test_min_area_rect2
    box = @contour1.min_area_rect2
    assert_equal(Cv::Box2D, box.class)
    center = box.center
    assert_equal(64, center.x.to_i)
    assert_equal(64, center.y.to_i)
    size = box.size
    assert_in_delta(63.356, size.width, 0.001)
    assert_in_delta(63.356, size.height, 0.001)
    assert_in_delta(-81.30, box.angle, 1.0)
    flunk('FIXME: Currently PointSet#min_area_rect2 causes segmentation fault when "self" is invalid.')    
    assert_raise(Cv::StsBadSize) {
      @contour2.min_area_rect2
    }
  end

  def test_min_enclosing_circle
    circle = @contour1.min_enclosing_circle
    assert_equal(Cv::Circle32f, circle.class)
    center = circle.center
    assert_equal(64, center.x.to_i)
    assert_equal(64, center.y.to_i)
    assert_in_delta(32.959, circle.radius, 0.001)
    assert_raise(Cv::StsBadSize) {
      @contour2.min_enclosing_circle
    }
  end
end
