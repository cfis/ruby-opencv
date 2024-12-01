#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Font
class FontTest < OpenCVTestCase
  def test_FACE
    assert_equal(0, Cv::Font::FACE[:simplex])
    assert_equal(1, Cv::Font::FACE[:plain])
    assert_equal(2, Cv::Font::FACE[:duplex])
    assert_equal(4, Cv::Font::FACE[:triplex])
    assert_equal(5, Cv::Font::FACE[:complex_small])
    assert_equal(6, Cv::Font::FACE[:script_simplex])
    assert_equal(7, Cv::Font::FACE[:script_complex])
  end

  def test_FONT_OPTION
    assert_equal(1.0, Cv::Font::FONT_OPTION[:hscale])
    assert_equal(1.0, Cv::Font::FONT_OPTION[:vscale])
    assert_equal(0, Cv::Font::FONT_OPTION[:shear])
    assert_equal(1, Cv::Font::FONT_OPTION[:thickness])
    assert_equal(8, Cv::Font::FONT_OPTION[:line_type])
  end

  def test_initialize
    font = Cv::Font.new(:simplex)
    assert_equal(0, font.face)
    assert_equal(1.0, font.hscale)
    assert_equal(1.0, font.vscale)
    assert_equal(0, font.shear)
    assert_equal(1, font.thickness)
    assert_equal(8, font.line_type)
    assert_false(font.italic)
    font = Cv::Font.new(:plain, :hscale => 2.5, :vscale => 3.5,
                      :shear => 0.5, :thickness => 3, :line_type => 2, :italic => false)
    assert_equal(1, font.face)
    assert_equal(2.5, font.hscale)
    assert_equal(3.5, font.vscale)
    assert_equal(0.5, font.shear)
    assert_equal(3, font.thickness)
    assert_equal(2, font.line_type)
    assert_false(font.italic)
    font = Cv::Font.new(:simplex, :italic => true)
    assert_equal(16, font.face)
    assert(font.italic)
    assert_raise(ArgumentError) {
      Cv::Font.new(:foo)
    }
  end
end
