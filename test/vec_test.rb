#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

# Tests for OpenCV::Cv::Vector
class VecTest < OpenCVTestCase
  CLASSES = [Cv::Vec2b, Cv::Vec3b, Cv::Vec4b,
             Cv::Vec2s, Cv::Vec3s, Cv::Vec4s,
             Cv::Vec2w, Cv::Vec3w, Cv::Vec4w,
             Cv::Vec2f, Cv::Vec3f, Cv::Vec4f, Cv::Vec6f,
             Cv::Vec2d, Cv::Vec3d, Cv::Vec4d, Cv::Vec6d,
             Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i,
             Cv::Vec2l]

  def test_initialize_binary
    alphabet = ("A".."Z").to_a
    [Cv::Vec2b, Cv::Vec3b, Cv::Vec4b].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i
      # Get some characters based on the size
      characters = alphabet[0..size-1].join("")
      bytes = characters.bytes[0..size-1]

      # Send in unsigned characters
      vector = klass.new(characters)
      assert_equal(bytes, vector.to_a)

      # And now the same but bytes
      vector = klass.new(bytes)
      assert_equal(bytes, vector.to_a)
    end
  end

  def test_initialize_signed_short
    [Cv::Vec2s, Cv::Vec3s, Cv::Vec4s].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(-128..127)
      end

      # And now the same but bytes
      vector = klass.new(values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_unsigned_short
    [Cv::Vec2w, Cv::Vec3w, Cv::Vec4w].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(0..255)
      end

      # And now the same but bytes
      vector = klass.new(values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_float
    [Cv::Vec2f, Cv::Vec3f, Cv::Vec4f, Cv::Vec6f].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(1.0e-38..1.0e38)
      end

      vector = klass.new(values)
      assert_in_delta_array(values, vector.to_a, 0.000001)
    end
  end

  def test_initialize_double
    [Cv::Vec2d, Cv::Vec3d, Cv::Vec4d, Cv::Vec6d].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      values = size.times.map do
        rand(-Float::MAX..Float::MAX)
      end

      vector = klass.new(values)
      assert_in_delta_array(values, vector.to_a, 0.000001)
    end
  end

  def test_initialize_signed_integer
    [Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      # Get some random integers that are 0 to 255
      values = size.times.map do
        rand(-2_147_483_648..2_147_483_647)
      end

      vector = klass.new(values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_signed_integer
    [Cv::Vec2i, Cv::Vec3i, Cv::Vec4i, Cv::Vec6i, Cv::Vec8i].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      # Get some random integers that are 0 to 255
      values = size.times.map do
        rand(-2_147_483_648..2_147_483_647)
      end

      vector = klass.new(values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_initialize_signed_long
    [Cv::Vec2l].each do |klass|
      # Get the vector size
      size = klass.name.match(/\d/)[0].to_i

      # Get some random integers that are 0 to 255
      values = size.times.map do
        rand(-9_223_372_036_854_775_808..9_223_372_036_854_775_807)
      end

      vector = klass.new(values)
      assert_equal(values, vector.to_a)
    end
  end

  def test_all
    vector = Cv::Vec4i.all(5)
    assert_equal([5, 5, 5, 5], vector.to_a)

    vector = Cv::Vec4f.all(4.44)
    assert_in_delta_array([4.44, 4.44, 4.44, 4.44], vector.to_a, 0.0001)
  end

  def test_ones
    vector = Cv::Vec3s.ones
    assert_equal([1, 1, 1], vector.to_a)

    vector = Cv::Vec4f.ones
    assert_in_delta_array([1.0, 1.0, 1.0, 1.0], vector.to_a, 0.0001)
  end

  def test_clone
    vector_original = Cv::Vec4f.new([1.1, 2.2, 3.3, 4.4])
    vector_clone = vector_original.clone
    refute_same(vector_original, vector_clone)
    assert_equal(vector_original.to_a, vector_clone.to_a)
  end

  def test_aref
    vector = Cv::Vec4f.new([10, 20.2, 0.31, 40])
    assert_in_delta(10, vector[0])
    assert_in_delta(20.2, vector[1])
    assert_in_delta(0.31, vector[2])
    assert_in_delta(40, vector[3])
  end

  def test_aset
    vector = Cv::Vec4f.new

    expected = [10, 20, 30.3, 0.4]
    expected.each.with_index do |x, i|
      vector[i] = x
    end
    assert_in_delta_array(expected, vector.to_a)
  end

  # def test_sub
  #   s1 = Cv::Vector.new(10, 20, 30, 40)
  #   s2 = Cv::Vector.new(2, 4, 6, 8)
  #   [s1.sub(s2), s1 - s2].each { |vector|
  #     assert_equal([8, 16, 24, 32], vector, 0.01)
  #   }
  #   s3 = Cv::Vector.new(0.2, 0.4, 0.6, 0.8)
  #   [s2.sub(s3), s2 - s3].each { |vector|
  #     assert_equal([1.8, 3.6, 5.4, 7.2], vector, 0.01)
  #   }
  #   mat = Cv::Mat.new(5, 5)
  #   mask = Cv::Mat.new(5, 5, :cv8u, 1)
  #   mat.height.times { |j|
  #     mat.width.times { |i|
  #       mat[i, j] = Cv::Vector.new(1.5)
  #       mask[i, j] = (i < 2 and j < 3) ? 1 : 0
  #     }
  #   }
  #   mat = Cv::Vector.new(0.1).sub(mat, mask)
  #   [Cv::Mat.new(5, 5, :cv16u, 1), Cv::Mat.new(5, 5, :cv8u, 3)].each { |msk|
  #     assert_raise(TypeError) {
  #       Cv::Vector.new.sub(mat, msk)
  #     }
  #   }
  # end
  #
  # def test_to_s
  #   assert_equal("<Cv::Vector:[10.0,20.0,30.0,40.0]>", Cv::Vec4i.new([10, 20, 30, 40]).to_s)
  #   assert_equal("<Cv::Vector:[0.1,0.2,0.3,0.4]>", Cv::Vec4f.new([0.1, 0.2, 0.3, 0.4]).to_s)
  # end
end
