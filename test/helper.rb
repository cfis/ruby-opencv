#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
# To make testing/debugging easier test within this source tree versus an installed gem
require 'bundler/setup'

# Add ext directory to load path to make it easier to test locally built extensions
ext_path = File.expand_path(File.join(__dir__, '..', 'ext', 'opencv', 'out', 'build', 'x64-Debug'))
#ext_path = File.expand_path(File.join(__dir__, '..', 'ext', 'opencv', 'cmake-build-debug-mingw'))
#ext_path = File.expand_path(File.join(__dir__, '..', 'ext', 'opencv', 'cmake-build-debug-visual-studio'))
$LOAD_PATH.unshift(ext_path)

# Now load code
require 'ruby-opencv'
require 'minitest/autorun'

class OpenCVTestCase < Minitest::Test
  SAMPLE_DIR = File.expand_path(File.dirname(__FILE__)) + '/samples/'
  FILENAME_CAT = SAMPLE_DIR + 'cat.jpg'
  FILENAME_LENA256x256 = SAMPLE_DIR + 'lena-256x256.jpg'
  FILENAME_LENA32x32 = SAMPLE_DIR + 'lena-32x32.jpg'
  FILENAME_LENA_EYES = File.expand_path(File.dirname(__FILE__)) + '/samples/lena-eyes.jpg'
  FILENAME_FRUITS = SAMPLE_DIR + 'fruits.jpg'
  FILENAME_CONTOURS = File.expand_path(File.dirname(__FILE__)) + '/samples/contours.jpg'
  FILENAME_CHESSBOARD = SAMPLE_DIR + 'chessboard.jpg'
  FILENAME_LINES = SAMPLE_DIR + 'lines.jpg'
  HAARCASCADE_FRONTALFACE_ALT = SAMPLE_DIR + 'haarcascade_frontalface_alt.xml.gz'
  AVI_SAMPLE = SAMPLE_DIR + 'movie_sample.avi'
  #DUMMY_OBJ = Digest::MD5.new # dummy object for argument type check test
  def snap(*images)
    n = -1
    images.map! { |val|
      n += 1
      if val.is_a? Hash
        val
      elsif val.is_a? Array
        {:title => val[0], :image => val[1] }
      else
        {:title => "snap-#{n}", :image => val }
      end
    }
    pos = Cv::Point.new(0, 0)
    images.each { |img|
      w = GUI::Window.new(img[:title])
      w.show(img[:image])
      w.move(pos)
      pos.x += img[:image].width
      if pos.x > 800
        pos.y += img[:image].height
        pos.x = 0
      end
    }
    
    GUI::wait_key
    GUI::Window::destroy_all
  end

  def hash_img(img)
    # Compute a hash for an image, useful for image comparisons
    Digest::MD5.hexdigest(img.data)
  end

  def assert_cvscalar_equal(expected, actual, message = nil)
    assert_equal(Cv::Scalar, actual.class, message)
    assert_array_equal(expected.to_ary, actual.to_ary, message)
  end

  def assert_array_equal(expected, actual, message = nil)
    assert_equal(expected.size, actual.size, message)
    expected.zip(actual) { |e, a|
      assert_equal(e, a, message)
    }
  end

  def create_cvmat(height, width, depth = CV_8U, channel = 4, &block)
    type = "#{depth}C#{channel}"
    mat = Cv::Mat.new(height, width, type)

    block = lambda do |row, column, count|
      Cv::Scalar.new(*([count + 1] * channel))
    end unless block_given?

    count = 0
    height.times do |row|
      width.times do |column|
        mat[row, column] = block.call(row, column, count)
        count += 1
      end
    end
    mat
  end

  def create_iplimage(width, height, depth = CV_8U, channel = 4, &block)
    m = IplImage.new(width, height, depth, channel)
    block = lambda { |j, i, c| Cv::Scalar.new(*([c + 1] * channel)) } unless block_given?
    count = 0
    height.times { |j|
      width.times { |i|
        m[j, i] = block.call(j, i, count)
        count += 1
      }
    }
    m
  end

  def assert_each_cvscalar(actual, delta = 0, &block)
    raise unless block_given?
    count = 0
    actual.height.times { |j|
      actual.width.times { |i|
        expected = block.call(j, i, count)
        if delta == 0
          expected = expected.to_ary if expected.is_a? Cv::Scalar
          assert_array_equal(expected, actual[j, i].to_ary)
        else
          assert_in_delta(expected, actual[j, i], delta)
        end
        count += 1
      }
    }
  end

  def print_cvmat(mat)
    s = []
    mat.height.times { |j|
      a = []
      mat.width.times { |i|
        tmp = mat[j, i].to_ary.map {|m| m.to_f.round(2) }.join(',')
        a << "[#{tmp}]"
      }
      s << a.join(' ')
    }
    puts s.join("\n")
  end

  def count_threshold(mat, threshold, &block)
    n = 0
    block = lambda { |a, b| a > b } unless block_given?
    (mat.rows * mat.cols).times { |i|
      n += 1 if block.call(mat[i][0], threshold)
    }
    n
  end

  def color_hists(mat)
    hists = [0] * mat.channel
    (mat.rows * mat.cols).times { |i|
      hists.size.times { |c|
        hists[c] += mat[i][c]
      }
    }
    hists
  end
end
