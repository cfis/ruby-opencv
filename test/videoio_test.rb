#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoIoTest < OpenCVTestCase
  def test_camera
    camera = Cv::VideoCapture.new
    camera.open(0)
    assert(camera.opened?)

    width = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    assert(width > 0)

    height = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)
    assert(height > 0)

    camera.release
  end

  def test_grab_frame
    camera = Cv::VideoCapture.new
    camera.open(0)

    frame = Cv::Mat.new
    camera >> frame
    refute(frame.empty?)

    Cv::named_window("Video", Cv::WindowFlags::WINDOW_AUTOSIZE)
    Cv::imshow("Video", frame.input_array)
    Cv::wait_key
  end
end
