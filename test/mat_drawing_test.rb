#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for drawing functions of OpenCV::Cv::Mat
class Mat_drawingTest < OpenCVTestCase
  def test_DRAWING_OPTION
    Cv::Mat::DRAWING_OPTION[:color].to_ary.each { |c|
      assert_in_delta(0, c, 0.01)
    }
    assert_equal(1, Cv::Mat::DRAWING_OPTION[:thickness])
    assert_equal(8, Cv::Mat::DRAWING_OPTION[:line_type])
    assert_equal(0, Cv::Mat::DRAWING_OPTION[:shift])
  end

  def test_FLOOD_FILL_OPTION
    assert_equal(4, Cv::Mat::FLOOD_FILL_OPTION[:connectivity])
    assert((not Cv::Mat::FLOOD_FILL_OPTION[:fixed_range]))
    assert((not Cv::Mat::FLOOD_FILL_OPTION[:mask_only]))
  end

  def test_line
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    m1 = m0.clone
    m2 = m0.line(Cv::Point.new(1, 0), Cv::Point.new(m0.width - 1, m0.height - 1),
                 :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.line!(Cv::Point.new(1, 0), Cv::Point.new(m0.width - 1, m0.height - 1),
             :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    
    # Uncomment the following line to show the image
    # snap(['Line: Blue, thickness = 1', m1], ['Line: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m0.line(DUMMY_OBJ, Cv::Point.new(1, 0))
    }
    assert_raise(TypeError) {
      m0.line(Cv::Point.new(1, 0), DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m0.line(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m0.line(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :thickness => DUMMY_OBJ)
    # }
    # m0.line(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :line_type => DUMMY_OBJ)
  end

  def test_rectangle
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    m1 = m0.clone
    m2 = m0.rectangle(Cv::Point.new(20, 20), Cv::Point.new(m0.width - 20, m0.height - 20),
                      :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.rectangle!(Cv::Point.new(20, 20), Cv::Point.new(m0.width - 20, m0.height - 20),
                  :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    # Uncomment the following line to show the image
    # snap(['Rectangle: Blue, thickness = 1', m1], ['Rectangle: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m0.line(DUMMY_OBJ, Cv::Point.new(1, 0))
    }
    assert_raise(TypeError) {
      m0.rectangle(Cv::Point.new(1, 0), DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m0.rectangle(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m0.rectangle(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :thickness => DUMMY_OBJ)
    # }
    # m0.rectangle(Cv::Point.new(1, 0), Cv::Point.new(1, 1), :line_type => DUMMY_OBJ)
  end

  def test_circle
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    m1 = m0.clone
    m2 = m0.circle(Cv::Point.new(m0.width / 2, m0.height / 2), 80,
                   :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.circle!(Cv::Point.new(m0.width / 2, m0.height / 2), 80,
               :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    # Uncomment the following line to show the image
    # snap(['Circle: Blue, thickness = 1', m1], ['Circle: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m0.circle(DUMMY_OBJ, 10)
    }
    assert_raise(TypeError) {
      m0.circle(Cv::Point.new(1, 0), DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m0.circle(Cv::Point.new(1, 0), 10, :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m0.circle(Cv::Point.new(1, 0), 10, :thickness => DUMMY_OBJ)
    # }
    m0.circle(Cv::Point.new(1, 0), 10, :line_type => DUMMY_OBJ)
  end

  def test_ellipse
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    m1 = m0.clone
    m2 = m0.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, 360,
                    :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.ellipse!(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, 360,
                :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    # Uncomment the following line to show the image
    # snap(['Ellipse: Blue, thickness = 1', m1], ['Ellipse: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m1.ellipse(DUMMY_OBJ, Cv::Size.new(100, 60), 30, 0, 360)
    }
    assert_raise(TypeError) {
      m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), DUMMY_OBJ, 30, 0, 360)
    }
    assert_raise(TypeError) {
      m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), DUMMY_OBJ, 0, 360)
    }
    assert_raise(TypeError) {
      m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, DUMMY_OBJ, 360)
    }
    assert_raise(TypeError) {
      m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, 360,
                 :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, 360,
    #              :thickness => DUMMY_OBJ)
    # }
    m1.ellipse(Cv::Point.new(m0.width / 2, m0.height / 2), Cv::Size.new(100, 60), 30, 0, 360,
               :line_type => DUMMY_OBJ)
  end

  def test_ellipse_box
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    box = Cv::Box2D.new(Cv::Point2D32f.new(m0.width / 2, m0.height / 2), Cv::Size2D32f.new(120, 160), 30)
    m1 = m0.clone
    m2 = m0.ellipse_box(box, :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.ellipse_box!(box, :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    # Uncomment the following line to show the image
    # snap(['Ellipse box: Blue, thickness = 1', m1], ['Ellipse box: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m1.ellipse_box(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m1.ellipse_box(box, :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m1.ellipse_box(box, :thickness => DUMMY_OBJ)
    # }
    m1.ellipse_box(box, :line_type => DUMMY_OBJ)
  end

  def test_fill_poly
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    pt = [[Cv::Point.new(10, 20), Cv::Point.new(10, 150), Cv::Point.new(100, 50)],
          [Cv::Point.new(200, 10), Cv::Point.new(200, 200), Cv::Point.new(170, 200)],
          [Cv::Point.new(30, 10), Cv::Point.new(0, 0), Cv::Point.new(90, 150)]]
    m1 = m0.clone
    m2 = m0.fill_poly(pt, :color => Cv::Color::Red, :line_type => :aa)
    m1.fill_poly!(pt, :color => Cv::Color::Blue, :line_type => :aa)
    # Uncomment the following line to view the image
    # snap(['Fill poly: Blue', m1], ['Fill poly: Red', m2])
    assert_raise(TypeError) {
      m1.fill_poly(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m1.fill_poly([DUMMY_OBJ, DUMMY_OBJ])
    }
    assert_raise(TypeError) {
      m1.fill_poly(pt, :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m1.fill_poly(pt, :thickness => DUMMY_OBJ)
    # }
    # m1.fill_poly(pt, :line_type => DUMMY_OBJ)
  end

  def test_fill_convex_poly
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    pt = [Cv::Point.new(10, 20), Cv::Point.new(10, 150), Cv::Point.new(100, 50)]
    
    m1 = m0.clone
    m2 = m0.fill_convex_poly(pt, :color => Cv::Color::Red, :line_type => :aa)
    m1.fill_convex_poly!(pt, :color => Cv::Color::Blue, :line_type => :aa)
    # Uncomment the following line to view the image
    # snap(['Fill convex poly: Blue', m1], ['Fill convex poly: Red', m2])

    assert_raise(TypeError) {
      m1.fill_convex_poly(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m1.fill_convex_poly([DUMMY_OBJ, DUMMY_OBJ])
    }
    assert_raise(TypeError) {
      m1.fill_convex_poly(pt, :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m1.fill_convex_poly(pt, :thickness => DUMMY_OBJ)
    # }
    # m1.fill_convex_poly(pt, :line_type => DUMMY_OBJ)
  end

  def test_poly_line
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    pt = [[Cv::Point.new(10, 20), Cv::Point.new(10, 150), Cv::Point.new(100, 150), Cv::Point.new(10, 20)],
          [Cv::Point.new(100, 200), Cv::Point.new(200, 190), Cv::Point.new(180, 50), Cv::Point.new(100, 200)]]
    m1 = m0.clone
    m2 = m0.poly_line(pt, :color => Cv::Color::Red, :thickness => 3, :line_type => :aa)
    m1.poly_line!(pt, :color => Cv::Color::Blue, :thickness => 1, :line_type => :aa)
    # Uncomment the following line to view the image
    # snap(['Fill poly line: Blue, thickness = 1', m1], ['Fill poly line: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m1.poly_line(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m1.poly_line([DUMMY_OBJ, DUMMY_OBJ])
    }
    assert_raise(TypeError) {
      m1.poly_line([[DUMMY_OBJ, DUMMY_OBJ], [DUMMY_OBJ, DUMMY_OBJ]])
    }
    assert_raise(TypeError) {
      m1.poly_line(pt, :color => DUMMY_OBJ)
    }
    # assert_raise(Cv::Error) {
    #   m1.poly_line(pt, :thickness => DUMMY_OBJ)
    # }
    # m1.poly_line(pt, :line_type => DUMMY_OBJ)
  end

  def test_draw_contours
    mat0 = Cv::Mat.load(FILENAME_CONTOURS, CV_LOAD_IMAGE_GRAYSCALE)
    mat0 = mat0.threshold(128, 255, CV_THRESH_BINARY)
    contours = mat0.find_contours(:mode => Cv::RetrievalModes::RETR_EXTERNAL_TREE, :method => CV_CHAIN_APPROX_SIMPLE)
    dst0 = mat0.clone.clear
    dst1 = mat0.clone.clear.GRAY2BGR
    begin
      dst0 = dst0.draw_contours!(contours, Cv::Color::Black, Cv::Color::White, -1)
      dst1.draw_contours!(contours, Cv::Color::Red, Cv::Color::Blue, 2,
                          :thickness => -1, :line_type => :aa)
    end while (contours = contours.h_next)
    [dst0, dst1].each { |dst|
      assert_equal(mat0.class, dst.class)
      assert_equal(mat0.rows, dst.rows)
      assert_equal(mat0.cols, dst.cols)
      assert_equal(mat0.depth, dst.depth)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(DUMMY_OBJ, Cv::Color::Black, Cv::Color::White, -1)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(contours, DUMMY_OBJ, Cv::Color::White, -1)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(contours, Cv::Color::Black, DUMMY_OBJ, -1)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(contours, Cv::Color::Black, Cv::Color::White, DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(contours, Cv::Color::Black, Cv::Color::White, -1, :thickness => DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      dst0.draw_contours(contours, Cv::Color::Black, Cv::Color::White, -1, :line_type => DUMMY_OBJ)
    }
    # Uncomment the following line to show the results
    # snap ['src', mat0], ['result0', dst0], ['result1', dst1]
  end

  def test_draw_chessboard_corners
    mat0 = Cv::Mat.load(FILENAME_CHESSBOARD, 1)
    mat1 = mat0.clone
    pattern_size = Cv::Size.new(4, 4)
    gray = mat1.BGR2GRAY
    corners, found = gray.find_chessboard_corners(pattern_size)
    mat2 = mat1.draw_chessboard_corners(pattern_size, corners, found)
    mat1.draw_chessboard_corners!(pattern_size, corners, found)
    [mat1, mat2].each { |dst|
      assert_equal(mat0.class, dst.class)
      assert_equal(mat0.rows, dst.rows)
      assert_equal(mat0.cols, dst.cols)
      assert_equal(mat0.depth, dst.depth)
    }
    assert_raise(TypeError) {
      mat1.draw_chessboard_corners(DUMMY_OBJ, corners, found)
    }
    assert_raise(TypeError) {
      mat1.draw_chessboard_corners(pattern_size, DUMMY_OBJ, found)
    }
    assert_nothing_raised {
      mat1.draw_chessboard_corners(pattern_size, corners, DUMMY_OBJ)
    }
    # Uncomment the following line to show the results
    # snap mat0, mat1, mat2
  end

  def test_put_text
    m0 = create_cvmat(240, 320, :cv8u, 3) { Cv::Color::White }
    m1 = m0.clone
    m1.put_text!('test 1', Cv::Point.new(60, 90), Cv::Font.new(:simplex), Cv::Color::Blue)
    font = Cv::Font.new(:plain, :hscale => 5.0, :vscale => 4.5,
                      :shear => 1.0, :thickness => 3, :line_type => 5, :italic => true)
    m2 = m0.put_text('test 2', Cv::Point.new(30, 80), font, Cv::Color::Red)
    # Uncomment the following lines to view the image
    # snap(['Put text: Blue, thickness = 1', m1], ['Put text: Red, thickness = 3', m2])
    assert_raise(TypeError) {
      m0.put_text(DUMMY_OBJ, Cv::Point.new(60, 90), font)
    }
    assert_raise(TypeError) {
      m0.put_text('test', DUMMY_OBJ, font)
    }
    assert_raise(TypeError) {
      m0.put_text('test', Cv::Point.new(60, 90), DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      m0.put_text('test', Cv::Point.new(60, 90), font, DUMMY_OBJ)
    }
  end
end

