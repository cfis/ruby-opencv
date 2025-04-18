#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class HaarClassifierCascadeTest < OpenCVTestCase
  def setup
    @cascade = Cv::HaarClassifierCascade.load(HAARCASCADE_FRONTALFACE_ALT)
  end

  def test_load
    assert_equal(Cv::HaarClassifierCascade, @cascade.class)
    assert_raise(ArgumentError) {
      Cv::HaarClassifierCascade.load('not/exist.xml')
    }
  end

  
  def test_detect_objects
    img = Cv::Mat.load(FILENAME_LENA256x256)
    detected = @cascade.detect_objects(img)
    assert_equal(Cv::Seq, detected.class)
    assert_equal(1, detected.size)
    assert_equal(Cv::AvgComp, detected[0].class)
    assert_equal(106, detected[0].x)
    assert_equal(100, detected[0].y)
    assert_equal(89, detected[0].width)
    assert_equal(89, detected[0].height)
    assert_equal(48, detected[0].neighbors)
    detected = @cascade.detect_objects(img) { |face|
      assert_equal(106, face.x)
      assert_equal(100, face.y)
      assert_equal(89, face.width)
      assert_equal(89, face.height)
      assert_equal(48, face.neighbors)
    }
    assert_equal(Cv::Seq, detected.class)
    assert_equal(1, detected.size)
    assert_equal(Cv::AvgComp, detected[0].class)
    detected = @cascade.detect_objects(img, :scale_factor => 2.0, :flags => CV_HAAR_DO_CANNY_PRUNING,
                                       :min_neighbors => 5, :min_size => Cv::Size.new(10, 10),
                                       :max_size => Cv::Size.new(100, 100))
    assert_equal(Cv::Seq, detected.class)
    assert_equal(1, detected.size)
    assert_equal(Cv::AvgComp, detected[0].class)
    assert_equal(109, detected[0].x)
    assert_equal(102, detected[0].y)
    assert_equal(80, detected[0].width)
    assert_equal(80, detected[0].height)
    assert_equal(7, detected[0].neighbors)
    assert_raise(TypeError) {
      @cascade.detect_objects('foo')
    }
  end
end
