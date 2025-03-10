#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ContourTest < OpenCVTestCase
  def test_initialize
    contour = Cv::Contour.new
    assert_not_nil(contour)
    assert_equal(Cv::Contour, contour.class)
    assert(contour.is_a? Cv::Seq)
  end

  def test_rect
    contour = Cv::Contour.new
    assert_not_nil(contour.rect)
    assert_equal(Cv::Rect, contour.rect.class)
  end

  def test_color
    contour = Cv::Contour.new
    assert_equal(0, contour.color)
    contour.color = 1
    assert_equal(1, contour.color)
  end

  def test_reserved
    reserved = Cv::Contour.new.reserved
    assert_equal(Array, reserved.class)
    assert_equal(3, reserved.size)
  end

  def test_approx_poly
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contours = mat0.find_contours(:mode => Cv::RetrievalModes::RETR_EXTERNAL_EXTERNAL)
    poly = contours.approx_poly
    assert_equal(Cv::Contour, poly.class)
    assert(poly.size > 0)
    assert(poly.all? { |c| c.class == Cv::Point })
    poly = contours.approx_poly(:method => :dp)
    assert_equal(Cv::Contour, poly.class)
    assert(poly.size > 0)
    assert(poly.all? { |c| c.class == Cv::Point })
    poly = contours.approx_poly(:accuracy => 2.0)
    assert_equal(Cv::Contour, poly.class)
    assert(poly.size > 0)
    assert(poly.all? { |c| c.class == Cv::Point })
    [true, false, 1, 0].each { |recursive|
      poly = contours.approx_poly(:recursive => recursive)
      assert_equal(Cv::Contour, poly.class)
      assert(poly.size > 0)
      assert(poly.all? { |c| c.class == Cv::Point })
    }
    poly = contours.approx_poly(:method => :dp, :accuracy => 2.0, :recursive => false)
    assert_equal(Cv::Contour, poly.class)
    assert(poly.size > 0)
    assert(poly.all? { |c| c.class == Cv::Point })
    # Uncomment the following lines to show the result
    # poly = contours.approx_poly(:accuracy => 3.0)
    # dst = mat0.clone.zero
    # begin
    #   dst.draw_contours!(poly, Cv::Color::White, Cv::Color::Black, 2,
    #                      :thickness => 1, :line_type => :aa)
    # end while (poly = poly.h_next)
    # snap dst
  end

  
  def test_bounding_rect
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contours = mat0.find_contours
    rect = contours.bounding_rect
    assert_equal(Cv::Rect, rect.class)
    assert_equal(32, rect.x)
    assert_equal(32, rect.y)
    assert_equal(65, rect.width)
    assert_equal(65, rect.height)
  end

  def test_create_tree
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contour = mat0.find_contours
    tree = contour.create_tree
    assert_equal(Cv::ContourTree, tree.class)
    assert_equal(34, tree.p1.x)
    assert_equal(53, tree.p1.y)
    assert_equal(0, tree.p2.x)
    assert_equal(0, tree.p2.y)
  end

  def test_in
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contour = mat0.find_contours
    assert(contour.in? Cv::Point.new(64, 64))
    assert_false(contour.in? Cv::Point.new(0, 0))
    assert_nil(contour.in? Cv::Point.new(64, 32))
  end

  def test_measure_distance
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contour = mat0.find_contours
    assert_in_delta(-0.7071, contour.measure_distance(Cv::Point.new(63, 32)), 0.01)
    assert_in_delta(31.01, contour.measure_distance(Cv::Point.new(64, 64)), 0.01)
  end

  def test_point_polygon_test
    mat0 = create_mat(128, 128, Cv::Mat1b) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contour = mat0.find_contours
    assert_equal(1, contour.point_polygon_test(Cv::Point.new(64, 64), 0))
    assert_equal(1, contour.point_polygon_test(Cv::Point.new(64, 64), false))
    assert_equal(-1, contour.point_polygon_test(Cv::Point.new(0, 0), 0))
    assert_equal(-1, contour.point_polygon_test(Cv::Point.new(0, 0), false))
    assert_equal(0, contour.point_polygon_test(Cv::Point.new(64, 32), 0))
    assert_equal(0, contour.point_polygon_test(Cv::Point.new(64, 32), false))
    assert_in_delta(-0.7071, contour.point_polygon_test(Cv::Point.new(63, 32), 1), 0.01)
    assert_in_delta(-0.7071, contour.point_polygon_test(Cv::Point.new(63, 32), true), 0.01)
    assert_in_delta(31.01, contour.point_polygon_test(Cv::Point.new(64, 64), 1), 0.01)
    assert_in_delta(31.01, contour.point_polygon_test(Cv::Point.new(64, 64), true), 0.01)
  end

  def test_match_shapes
    img1 = Cv::Mat.load(FILENAME_CONTOURS, CV_LOAD_IMAGE_GRAYSCALE).threshold(127, 255, CV_THRESH_BINARY)
    img2 = Cv::Mat.load(FILENAME_LINES, CV_LOAD_IMAGE_GRAYSCALE).threshold(127, 255, CV_THRESH_BINARY)
    c1 = img1.find_contours(mode: Cv::RetrievalModes::RETR_EXTERNAL_EXTERNAL)
    c2 = img2.find_contours(mode: Cv::RetrievalModes::RETR_EXTERNAL_EXTERNAL)
    [CV_CONTOURS_MATCH_I1, CV_CONTOURS_MATCH_I2, CV_CONTOURS_MATCH_I3].each { |method|
      assert_in_delta(0, c1.match_shapes(c1, method), 0.01)
      assert_in_delta(0, c1.match_shapes(c1, method, nil), 0.01)
      assert(c1.match_shapes(c2, method) > 0)
      assert(c1.match_shapes(c2, method, nil) > 0)
    }
    assert_raise(TypeError) {
      c1.match_shapes(DUMMY_OBJ, CV_CONTOURS_MATCH_I1)
    }
    assert_raise(TypeError) {
      c1.match_shapes(c2, DUMMY_OBJ)
    }
  end
end
