#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')
# Tests for OpenCV::IplImage
class ImageCodesTest < OpenCVTestCase
  def test_read
    image_path = File.join(SAMPLE_DIR, "starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    refute(image.empty?)
    assert_equal(2, image.size.dims)

    assert_equal(752, image.cols)
    assert_equal(600, image.rows)
  end
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

    refute(image.empty?)
    assert_equal(2, image.size.dims)

    assert_equal(752, image.cols)
    assert_equal(600, image.rows)

    pixel= image.at(myRow, myCol)
    #cout << "Pixel value (B,G,R): (" << (int)pixel[0] << "," << (int)pixel[1] << "," << (int)pixel[2] << ")" << endl;
  end

  def test_load
    mat = Cv::Mat.load(FILENAME_CAT)
    assert_equal(Cv::Mat, mat.class)
    assert_equal(375, mat.cols)
    assert_equal(500, mat.rows)
    assert_equal(:cv8u, mat.depth)
    assert_equal(3, mat.channel)
    assert_equal('ebc0b85d3ac44ea60181c997f35d13df', hash_img(mat))
    mat = Cv::Mat.load(FILENAME_CAT, CV_LOAD_IMAGE_GRAYSCALE)
    assert_equal(Cv::Mat, mat.class)
    assert_equal(375, mat.cols)
    assert_equal(500, mat.rows)
    assert_equal(:cv8u, mat.depth)
    assert_equal(1, mat.channel)
    assert_equal('f0ae1d7f2d6b3a64d093e3181361f3a4', hash_img(mat))
    mat = Cv::Mat.load(FILENAME_CAT, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR)
    assert_equal(Cv::Mat, mat.class)
    assert_equal(375, mat.cols)
    assert_equal(500, mat.rows)
    assert_equal(:cv8u, mat.depth)
    assert_equal(3, mat.channel)
    assert_equal('ebc0b85d3ac44ea60181c997f35d13df', hash_img(mat))
    assert_raise(ArgumentError) {
      Cv::Mat.load
    }
    assert_raise(TypeError) {
      Cv::Mat.load(DUMMY_OBJ)
    }
    assert_raise(TypeError) {
      Cv::Mat.load(FILENAME_CAT, DUMMY_OBJ)
    }
    assert_raise(StandardError) {
      Cv::Mat.load('file/does/not/exist')
    }
  end
  #
  # def test_save_image
  #   filename_jpg = 'save_image_test.jpg'
  #   filename_png = 'save_image_test.png'
  #   mat = Cv::Mat.new(20, 20, :cv8u, 1)
  #
  #   File.delete filename_jpg if File.exists? filename_jpg
  #   mat.save_image filename_jpg
  #   assert(File.exists? filename_jpg)
  #   File.delete filename_jpg if File.exists? filename_jpg
  #   mat.save_image(filename_jpg, CV_IMWRITE_JPEG_QUALITY => 10)
  #   assert(File.exists? filename_jpg)
  #   File.delete filename_png if File.exists? filename_png
  #   mat.save_image(filename_png, CV_IMWRITE_PNG_COMPRESSION => 9)
  #   assert(File.exists? filename_png)
  #   # Alias
  #   File.delete filename_jpg if File.exists? filename_jpg
  #   mat.save filename_jpg
  #   assert(File.exists? filename_jpg)
  #
  #   assert_raise(TypeError) {
  #     mat.save_image(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     mat.save_image(filename_jpg, DUMMY_OBJ)
  #   }
  #   File.delete filename_jpg if File.exists? filename_jpg
  #   File.delete filename_png if File.exists? filename_png
  # end
  #
  # def test_encode
  #   mat = Cv::Mat.load(FILENAME_CAT);
  #   jpg = mat.encode('.jpg')
  #   assert_equal('JFIF', jpg[6, 4].map(&:chr).join) # Is jpeg format?
  #   jpg = mat.encode('.jpg', CV_IMWRITE_JPEG_QUALITY => 10)
  #   assert_equal('JFIF', jpg[6, 4].map(&:chr).join)
  #   png = mat.encode('.png')
  #   assert_equal('PNG', png[1, 3].map(&:chr).join) # Is png format?
  #   png = mat.encode('.png', CV_IMWRITE_PNG_COMPRESSION => 9)
  #   assert_equal('PNG', png[1, 3].map(&:chr).join)
  #   assert_raise(TypeError) {
  #     mat.encode(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     mat.encode('.jpg', DUMMY_OBJ)
  #   }
  #   # Uncomment the following lines to see the result images
  #   #
  #   # open('test-jpeg.jpg', 'wb') { |f|
  #   #   f.write jpg.pack("c*")
  #   # }
  #   # open('test-png.png', 'wb') { |f|
  #   #   f.write png.pack("c*")
  #   # }
  # end
  #
  # def test_decode
  #   data = nil
  #   open(FILENAME_CAT, 'rb') { |f|
  #     data = f.read
  #   }
  #   data_ary = data.unpack("c*")
  #   data_mat = Cv::Mat.new(1, data_ary.size).set_data(data_ary)
  #   expected = Cv::Mat.load(FILENAME_CAT)
  #   mat1 = Cv::Mat.decode(data)
  #   mat2 = Cv::Mat.decode(data_ary)
  #   mat3 = Cv::Mat.decode(data_mat)
  #   mat4 = Cv::Mat.decode(data, CV_LOAD_IMAGE_COLOR)
  #   mat5 = Cv::Mat.decode(data_ary, CV_LOAD_IMAGE_COLOR)
  #   mat6 = Cv::Mat.decode(data_mat, CV_LOAD_IMAGE_COLOR)
  #   expected_hash = hash_img(expected)
  #   [mat1, mat2, mat3, mat4, mat5, mat6].each { |mat|
  #     assert_equal(Cv::Mat, mat.class)
  #     assert_equal(expected.rows, mat.rows)
  #     assert_equal(expected.cols, mat.cols)
  #     assert_equal(expected.channel, mat.channel)
  #     assert_equal(expected_hash, hash_img(mat))
  #   }
  #   expected_c1 = Cv::Mat.load(FILENAME_CAT, CV_LOAD_IMAGE_GRAYSCALE)
  #   mat1c1 = Cv::Mat.decode(data, CV_LOAD_IMAGE_GRAYSCALE)
  #   mat2c1 = Cv::Mat.decode(data_ary, CV_LOAD_IMAGE_GRAYSCALE)
  #   mat3c1 = Cv::Mat.decode(data_mat, CV_LOAD_IMAGE_GRAYSCALE)
  #   expected_hash_c1 = hash_img(expected_c1)
  #   [mat1c1, mat2c1, mat3c1].each { |mat|
  #     assert_equal(Cv::Mat, mat.class)
  #     assert_equal(expected_c1.rows, mat.rows)
  #     assert_equal(expected_c1.cols, mat.cols)
  #     assert_equal(expected_c1.channel, mat.channel)
  #     assert_equal(expected_hash_c1, hash_img(mat))
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.decode(DUMMY_OBJ)
  #   }
  #   assert_raise(TypeError) {
  #     Cv::Mat.decode(data, DUMMY_OBJ)
  #   }
  #   # Uncomment the following line to show the result images
  #   # snap mat1, mat2, mat3
  # end

  def test_FIND_CONTOURS_OPTION
    assert_equal(1, Cv::Mat::FIND_CONTOURS_OPTION[:mode])
    assert_equal(2, Cv::Mat::FIND_CONTOURS_OPTION[:method])
    assert_equal(0, Cv::Mat::FIND_CONTOURS_OPTION[:offset].x)
    assert_equal(0, Cv::Mat::FIND_CONTOURS_OPTION[:offset].y)
  end


end