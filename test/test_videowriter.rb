#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::VideoWriter
class TestVideoWriter < OpenCVTestCase
  OUTPUT_FILENAME = 'videowriter_result.avi'
  
  def test_initialize
    vw = Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(320, 240))
    assert_equal(Cv::VideoWriter, vw.class)
    vw.close
    vw = Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(320, 240), false)
    assert_equal(Cv::VideoWriter, vw.class)
    vw.close
    ## Supported only Windows(?)
    # vw = Cv::VideoWriter.new(OUTPUT_FILENAME, nil, 15, Cv::Size.new(320, 240), false)
    # assert_equal(Cv::VideoWriter, vw.class)
    # vw.close
    Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(320, 240)) { |vw|
      assert_equal(Cv::VideoWriter, vw.class)      
    }
    assert_raise(TypeError) {
      vw = Cv::VideoWriter.new(123, 'MJPG', 15, Cv::Size.new(320, 240), false)
    }
  end

  def test_write
    img = IplImage.load(FILENAME_LENA256x256)
    vw = Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256))
    vw.write img
    vw.close
    Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256)) { |vw|
      vw.write img
    }
    
    assert_raise(TypeError) {
      Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256)) { |vw|
        vw.write DUMMY_OBJ
      }
    }
  end

  def test_close
    vw = Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(320, 240))
    vw.close
  end
end
