#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class CaptureTest < OpenCVTestCase
  def setup
    @cap = Cv::Capture.open(AVI_SAMPLE)
    @cap.query
  end

  def teardown
    @cap = nil
  end

  def test_INTERFACE
    assert_equal(Cv::Capture::INTERFACE[:any], 0)
    assert_equal(Cv::Capture::INTERFACE[:mil], 100)
    assert_equal(Cv::Capture::INTERFACE[:vfw], 200)
    assert_equal(Cv::Capture::INTERFACE[:v4l], 200)
    assert_equal(Cv::Capture::INTERFACE[:v4l2], 200)
    assert_equal(Cv::Capture::INTERFACE[:fireware], 300)
    assert_equal(Cv::Capture::INTERFACE[:ieee1394], 300)
    assert_equal(Cv::Capture::INTERFACE[:dc1394], 300)
    assert_equal(Cv::Capture::INTERFACE[:cmu1394], 300)
    assert_equal(Cv::Capture::INTERFACE[:stereo], 400)
    assert_equal(Cv::Capture::INTERFACE[:tyzx], 400)
    assert_equal(Cv::Capture::INTERFACE[:tyzx_left], 400)
    assert_equal(Cv::Capture::INTERFACE[:tyzx_right], 401)
    assert_equal(Cv::Capture::INTERFACE[:tyzx_color], 402)
    assert_equal(Cv::Capture::INTERFACE[:tyzx_z], 403)
    assert_equal(Cv::Capture::INTERFACE[:qt], 500)
    assert_equal(Cv::Capture::INTERFACE[:quicktime], 500)
  end

  def test_open
    cap1 = Cv::Capture.open(AVI_SAMPLE)
    assert_equal(Cv::Capture, cap1.class)
    # Uncomment the following lines to test capturing from camera
    # cap2 = Cv::Capture.open(0)
    # assert_equal(Cv::Capture, cap2.class)
    # Cv::Capture::INTERFACE.each { |k, v|
    #   cap3 = Cv::Capture.open(k)
    #   assert_equal(Cv::Capture, cap3.class)
    # }
  end

  def test_close
    cap1 = Cv::Capture.open(AVI_SAMPLE)
    cap1.close
    assert_raise(IOError) do
      cap1.query
    end
  end

  def test_grab
    assert(@cap.grab)
  end

  def test_retrieve
    @cap.grab
    img = @cap.retrieve
    assert_equal(IplImage, img.class)
  end

  def test_query
    img = @cap.query
    assert_equal(IplImage, img.class)
  end

  def test_millisecond
    @cap.millisecond = 10
    assert(@cap.millisecond.is_a? Numeric)
    # assert_equal(10, @cap.millisecond)
    @cap.millisecond = 20
    assert(@cap.millisecond.is_a? Numeric)
    # assert_equal(20, @cap.millisecond)
  end

  def test_frames
    @cap.frames = 10
    assert(@cap.frames.is_a? Numeric)
    # assert_equal(10, @cap.frames)
    @cap.frames = 20
    assert(@cap.frames.is_a? Numeric)
    # assert_equal(20, @cap.frames)
  end

  def test_avi_ratio
    @cap.avi_ratio = 0.1
    assert(@cap.avi_ratio.is_a? Numeric)
    # assert_equal(0.1, @cap.avi_ratio)
    @cap.avi_ratio = 0.8
    assert(@cap.avi_ratio.is_a? Numeric)
    # assert_equal(0.8, @cap.avi_ratio)
  end

  def test_size
    @cap.size = Cv::Size.new(320, 240)
    assert_equal(Cv::Size, @cap.size.class)
    # assert_equal(320, @cap.size.width)
    # assert_equal(240, @cap.size.height)
    @cap.size = Cv::Size.new(640, 480)
    assert_equal(Cv::Size, @cap.size.class)
    # assert_equal(640, @cap.size.width)
    # assert_equal(480, @cap.size.height)
  end

  def test_width
    @cap.width = 320
    assert(@cap.width.is_a? Numeric)
    # assert_equal(320, @cap.width)
    @cap.width = 640
    assert(@cap.width.is_a? Numeric)
    # assert_equal(640, @cap.width)
  end

  def test_height
    @cap.height = 240
    assert(@cap.height.is_a? Numeric)
    # assert_equal(240, @cap.height)
    @cap.height = 480
    assert(@cap.height.is_a? Numeric)
    # assert_equal(480, @cap.height)
  end

  def test_fps
    @cap.fps = 15
    assert(@cap.fps.is_a? Numeric)
    # assert_equal(15, @cap.fps)
    @cap.fps = 30
    assert(@cap.fps.is_a? Numeric)
    # assert_equal(30, @cap.fps)
  end

  def test_fourcc
    assert_equal(String, @cap.fourcc.class)
  end

  def test_frame_count
    assert(@cap.frame_count.is_a? Numeric)
  end

  def test_format
    assert(@cap.format.is_a? Numeric)
  end

  def test_mode
    assert(@cap.mode.is_a? Numeric)
  end

  def test_brightness
    assert(@cap.brightness.is_a? Numeric)
  end

  def test_contrast
    assert(@cap.contrast.is_a? Numeric)
  end

  def test_saturation
    assert(@cap.saturation.is_a? Numeric)
  end

  def test_hue
    assert(@cap.hue.is_a? Numeric)
  end

  def test_gain
    assert(@cap.gain.is_a? Numeric)
  end

  def test_exposure
    assert(@cap.exposure.is_a? Numeric)
  end

  def test_convert_rgb
    assert((@cap.convert_rgb == true) ||
           (@cap.convert_rgb == false))
  end

  def test_rectification
    assert(@cap.rectification.is_a? Numeric)
  end
end
