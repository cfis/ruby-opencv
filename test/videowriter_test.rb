#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoWriterTest < OpenCVTestCase
  OUTPUT_FILENAME = 'videowriter_result.avi'

  def test_initialize
    fourcc = Cv::VideoWriter.fourcc("M", "J", "P", "G")
    vw = Cv::VideoWriter.new(OUTPUT_FILENAME, fourcc, 15, Cv::Size.new(320, 240))
    assert_kind_of(Cv::VideoWriter, vw)
    vw.release
  end

  # def test_write
  #   img = IplImage.load(FILENAME_LENA256x256)
  #   vw = Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256))
  #   vw.write img
  #   vw.close
  #   Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256)) { |vw|
  #     vw.write img
  #   }
  #
  #   assert_raise(TypeError) {
  #     Cv::VideoWriter.new(OUTPUT_FILENAME, 'MJPG', 15, Cv::Size.new(256, 256)) { |vw|
  #       vw.write DUMMY_OBJ
  #     }
  #   }
  # end
end
