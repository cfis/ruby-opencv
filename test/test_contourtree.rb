#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::ContourTree
class TestContourTree < OpenCVTestCase
  def setup
    @tree = Cv::ContourTree.new(CV_SEQ_ELTYPE_POINT)
  end

  def test_initialize
    tree = Cv::ContourTree.new(CV_SEQ_ELTYPE_POINT)
    assert_equal(Cv::ContourTree, tree.class)
    assert(tree.is_a? Cv::Seq)
  end

  def test_p1
    assert_equal(Cv::Point, @tree.p1.class)
  end

  def test_p2
    assert_equal(Cv::Point, @tree.p2.class)
  end

  def test_contour
    mat0 = create_cvmat(128, 128, :cv8u, 1) { |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? Cv::Color::White : Cv::Color::Black
    }
    contour = mat0.find_contours
    tree = contour.create_tree
    contour = tree.contour(Cv::TermCriteria.new(100, 0.01))
    assert_equal(Cv::Contour, contour.class)
    assert_raise(Cv::StsBadArg) {
      tree.contour(Cv::TermCriteria.new(0, 0))
    }
  end
end
