#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MomentsTest < OpenCVTestCase
  # def setup
  #   @mat = create_mat(128, 128, CV_8UC1) do |j, i|
  #     if j >= 32 and j < 96 and i >= 16 and i < 112
  #       0
  #     elsif j >= 16 and j < 112 and i >= 16 and i < 112
  #       128
  #     else
  #       255
  #     end
  #   end
  #   @moment1 = Cv::Moments.new
  #   @moment2 = Cv::Moments.new(nil, true)
  #   @moment3 = Cv::Moments.new(@mat)
  #   @moment4 = Cv::Moments.new(@mat, true)
  # end

  def test_initialize
    moment = Cv::Moments.new
    assert_in_delta(0, moment.m00, 0.001)
    assert_in_delta(0, moment.m10, 0.001)
    assert_in_delta(0, moment.m01, 0.001)
    assert_in_delta(0, moment.m20, 0.001)
    assert_in_delta(0, moment.m11, 0.001)
    assert_in_delta(0, moment.m02, 0.001)
    assert_in_delta(0, moment.m30, 0.001)
    assert_in_delta(0, moment.m21, 0.001)
    assert_in_delta(0, moment.m12, 0.001)
    assert_in_delta(0, moment.m03, 0.001)
    assert_in_delta(0, moment.mu20, 0.001)
    assert_in_delta(0, moment.mu11, 0.001)
    assert_in_delta(0, moment.mu02, 0.001)
    assert_in_delta(0, moment.mu30, 0.001)
    assert_in_delta(0, moment.mu21, 0.001)
    assert_in_delta(0, moment.mu12, 0.001)
    assert_in_delta(0, moment.mu03, 0.001)
    assert_in_delta(0, moment.nu20, 0.001)
    assert_in_delta(0, moment.nu11, 0.001)
    assert_in_delta(0, moment.nu02, 0.001)
    assert_in_delta(0, moment.nu30, 0.001)
    assert_in_delta(0, moment.nu21, 0.001)
    assert_in_delta(0, moment.nu12, 0.001)
    assert_in_delta(0, moment.nu03, 0.001)
  end

  def test_spatial
    assert_in_delta(0, @moment1.spatial(0, 0), 0.1)
    assert_in_delta(0, @moment2.spatial(0, 0), 0.1)
    assert_in_delta(2221056, @moment3.spatial(0, 0), 0.1)
    assert_in_delta(10240, @moment4.spatial(0, 0), 0.1)
  end

  def test_central
    assert_in_delta(0, @moment1.central(0, 0), 0.1)
    assert_in_delta(0, @moment2.central(0, 0), 0.1)
    assert_in_delta(2221056, @moment3.central(0, 0), 0.1)
    assert_in_delta(10240, @moment4.central(0, 0), 0.1)
  end

  def test_normalized_central
    assert_in_delta(0, @moment1.normalized_central(0, 0), 0.1)
    assert_in_delta(0, @moment2.normalized_central(0, 0), 0.1)
    assert_in_delta(1, @moment3.normalized_central(0, 0), 0.1)
    assert_in_delta(1, @moment4.normalized_central(0, 0), 0.1)
  end

  def test_hu
    hu_moments = @moment1.hu
    assert_equal(Cv::HuMoments, hu_moments.class)
    hu_moments.to_a.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    hu_moments = @moment2.hu
    assert_equal(Cv::HuMoments, hu_moments.class)
    hu_moments.to_a.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    
    hu_moments = @moment3.hu
    assert_equal(Cv::HuMoments, hu_moments.class)
    assert_in_delta(0.001771, hu_moments.hu1, 0.000001)
    hu_moments.to_a[1..7].each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    hu_moments = @moment4.hu
    assert_equal(Cv::HuMoments, hu_moments.class)
    assert_in_delta(0.361650, hu_moments.hu1, 0.000001)
    assert_in_delta(0.000625, hu_moments.hu2, 0.000001)
    hu_moments.to_a[2..7].each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
  end

  def test_gravity_center
    center = @moment1.gravity_center
    assert_equal(Cv::Point2D32f, center.class)
    assert(center.x.nan?)
    assert(center.y.nan?)
    center = @moment2.gravity_center
    assert_equal(Cv::Point2D32f, center.class)
    assert(center.x.nan?)
    assert(center.y.nan?)
    center = @moment3.gravity_center
    assert_equal(Cv::Point2D32f, center.class)
    assert_in_delta(63.5, center.x, 0.001)
    assert_in_delta(63.5, center.y, 0.001)
    center = @moment4.gravity_center
    assert_equal(Cv::Point2D32f, center.class)
    assert_in_delta(63.5, center.x, 0.001)
    assert_in_delta(63.5, center.y, 0.001)
  end

  def test_angle
    [@moment1, @moment2].each { |m|
      assert_nil(m.angle)
    }
    [@moment3, @moment4].each { |m|
      assert_in_delta(0, m.angle, 0.001)
    }
  end

  def test_mXX
    [@moment1, @moment2].each { |m|
      assert_in_delta(0, m.m00, 0.001)
      assert_in_delta(0, m.m10, 0.001)
      assert_in_delta(0, m.m01, 0.001)
      assert_in_delta(0, m.m20, 0.001)
      assert_in_delta(0, m.m11, 0.001)
      assert_in_delta(0, m.m02, 0.001)
      assert_in_delta(0, m.m30, 0.001)
      assert_in_delta(0, m.m21, 0.001)
      assert_in_delta(0, m.m12, 0.001)
      assert_in_delta(0, m.m03, 0.001)
      assert_in_delta(0, m.mu20, 0.001)
      assert_in_delta(0, m.mu11, 0.001)
      assert_in_delta(0, m.mu02, 0.001)
      assert_in_delta(0, m.mu30, 0.001)
      assert_in_delta(0, m.mu21, 0.001)
      assert_in_delta(0, m.mu12, 0.001)
      assert_in_delta(0, m.mu03, 0.001)
      assert_in_delta(0, m.inv_sqrt_m00, 0.001)
    }
    assert_in_delta(2221056, @moment3.m00, 0.001)
    assert_in_delta(141037056, @moment3.m10, 0.001)
    assert_in_delta(141037056, @moment3.m01, 0.001)
    assert_in_delta(13157049856, @moment3.m20, 0.001)
    assert_in_delta(8955853056, @moment3.m11, 0.001)
    assert_in_delta(13492594176, @moment3.m02, 0.001)
    assert_in_delta(1369024659456, @moment3.m30, 0.001)
    assert_in_delta(835472665856, @moment3.m21, 0.001)
    assert_in_delta(856779730176, @moment3.m12, 0.001)
    assert_in_delta(1432945852416, @moment3.m03, 0.001)
    assert_in_delta(4201196800, @moment3.mu20, 0.001)
    assert_in_delta(0, @moment3.mu11, 0.001)
    assert_in_delta(4536741120, @moment3.mu02, 0.001)
    assert_in_delta(0, @moment3.mu30, 0.001)
    assert_in_delta(0, @moment3.mu21, 0.001)
    assert_in_delta(0, @moment3.mu12, 0.001)
    assert_in_delta(0, @moment3.mu03, 0.001)
    assert_in_delta(0.000671, @moment3.inv_sqrt_m00, 0.000001)
    assert_in_delta(10240, @moment4.m00, 0.001)
    assert_in_delta(650240, @moment4.m10, 0.001)
    assert_in_delta(650240, @moment4.m01, 0.001)
    assert_in_delta(58940416, @moment4.m20, 0.001)
    assert_in_delta(41290240, @moment4.m11, 0.001)
    assert_in_delta(61561856, @moment4.m02, 0.001)
    assert_in_delta(5984288768, @moment4.m30, 0.001)
    assert_in_delta(3742716416, @moment4.m21, 0.001)
    assert_in_delta(3909177856, @moment4.m12, 0.001)
    assert_in_delta(6483673088, @moment4.m03, 0.001)
    assert_in_delta(17650176, @moment4.mu20, 0.001)
    assert_in_delta(0, @moment4.mu11, 0.001)
    assert_in_delta(20271616, @moment4.mu02, 0.001)
    assert_in_delta(0, @moment4.mu30, 0.001)
    assert_in_delta(0, @moment4.mu21, 0.001)
    assert_in_delta(0, @moment4.mu12, 0.001)
    assert_in_delta(0, @moment4.mu03, 0.001)
    assert_in_delta(0.009882, @moment4.inv_sqrt_m00, 0.000001)
  end
end
