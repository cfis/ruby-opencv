#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'
# Tests for OpenCV::IplImage
class TestImageCodes < OpenCVTestCase
  # def test_read
  #   image_path = File.join(SAMPLE_DIR, "starry_night.jpg")
  #   image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
  #
  #   refute(image.empty())
  #   assert_equal(2, image.size.dims)
  #
  #   assert_equal(752, image.cols)
  #   assert_equal(600, image.rows)
  # end
  #
  # def test_write
  #   image_path = File.join(SAMPLE_DIR, "starry_night.jpg")
  #   image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_GRAYSCALE)
  #
  #   data = Cv::InputArray.new(image)
  #   output_image_path = File.join(SAMPLE_DIR, "starry_night_grayscale.jpg")
  #   image = Cv::imwrite(output_image_path, data, [])
  # end

  def test_pixels
    image_path = File.join(SAMPLE_DIR, "starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    refute(image.empty())
    assert_equal(2, image.size.dims)

    assert_equal(752, image.cols)
    assert_equal(600, image.rows)

    pixel= image.at(myRow, myCol)
    #cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;

  end

end