#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.expand_path(File.dirname(__FILE__)) + '/helper'

# Tests for OpenCV::Cv::HuMoment
class TestHuMoments < OpenCVTestCase
  def setup
    @mat = create_cvmat(128, 128, :cv8u, 1) { |j, i|
      if j >= 32 and j < 96 and i >= 16 and i < 112
        Cv::Scalar.new(0)
      elsif j >= 16 and j < 112 and i >= 16 and i < 112
        Cv::Scalar.new(128)
      else
        Cv::Scalar.new(255)
      end
    }
    @moment1 = Cv::Moments.new
    @moment2 = Cv::Moments.new(nil, true)
    @moment3 = Cv::Moments.new(@mat)
    @moment4 = Cv::Moments.new(@mat, true)
    @hu_moments1 = Cv::HuMoments.new(@moment1)
    @hu_moments2 = Cv::HuMoments.new(@moment2)
    @hu_moments3 = Cv::HuMoments.new(@moment3)
    @hu_moments4 = Cv::HuMoments.new(@moment4)
  end

  
  def test_initialize
    [@hu_moments1, @hu_moments2, @hu_moments3, @hu_moments4].each { |m|
      assert_not_nil(m)
      assert_equal(Cv::HuMoments, m.class)
    }
    assert_raise(TypeError) {
      Cv::HuMoments.new('foo')
    }
  end

  def test_huX
    hu_moments = [@hu_moments1.hu1, @hu_moments1.hu2, @hu_moments1.hu3, @hu_moments1.hu4,
                  @hu_moments1.hu5, @hu_moments1.hu6, @hu_moments1.hu7]
    hu_moments.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    hu_moments = [@hu_moments2.hu1, @hu_moments2.hu2, @hu_moments2.hu3, @hu_moments2.hu4,
                  @hu_moments2.hu5, @hu_moments2.hu6, @hu_moments2.hu7]
    hu_moments.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    
    hu_moments = [@hu_moments3.hu2, @hu_moments3.hu3, @hu_moments3.hu4,
                  @hu_moments3.hu5, @hu_moments3.hu6, @hu_moments3.hu7]
    assert_in_delta(0.001771, @hu_moments3.hu1, 0.000001)
    hu_moments.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
    hu_moments = [@hu_moments4.hu3, @hu_moments4.hu4,
                  @hu_moments4.hu5, @hu_moments4.hu6, @hu_moments4.hu7]
    assert_in_delta(0.361650, @hu_moments4.hu1, 0.000001)
    assert_in_delta(0.000625, @hu_moments4.hu2, 0.000001)
    hu_moments.each { |hu|
      assert_in_delta(0.0, hu, 0.000001)
    }
  end

  def test_to_ary
    [@hu_moments4.to_ary, @hu_moments4.to_a].each { |hu_moments|
      assert_equal(7, hu_moments.size)
      assert_in_delta(0.361650, hu_moments[0], 0.000001)
      assert_in_delta(0.000625, hu_moments[1], 0.000001)
      hu_moments[2..7].each { |hu|
        assert_in_delta(0.0, hu, 0.000001)
      }
    }
  end
end
