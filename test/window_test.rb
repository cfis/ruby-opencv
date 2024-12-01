#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')

class WindowTest < OpenCVTestCase
  # def setup
  #   @window1 = Window.new('window1')
  #   @window2 = Window.new('window2', CV_WINDOW_AUTOSIZE)
  #   @window3 = Window.new('window3', 0)
  # end
  #
  # def teardown
  #   Window::destroy_all
  # end

  def test_ui_framework
    assert_equal("WIN32", Cv::current_ui_framework)
  end

  def test_show_image
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    refute(image.empty?)

    window = Cv::named_window("Starry", Cv::WindowFlags::WINDOW_AUTOSIZE)

    input_array = Cv::InputArray.new(image)
    Cv::imshow("Starry", input_array)
    Cv::wait_key(1000)
    destroy_window("Starry")
  end

  # def test_resize
  #   @window1.resize(Cv::Size.new(10, 20))
  #   @window2.resize(100, 200)
  #   assert_raise(ArgumentError) {
  #     @window3.resize
  #   }
  #   # Uncomment the following lines to show the results
  #   # @window1.show(Cv::Mat.new(10, 20))
  #   # @window1.resize(100, 200)
  #   # GUI::wait_key
  # end
  #
  # def test_move
  #   @window1.move(Cv::Point.new(10, 20))
  #   @window2.move(100, 200)
  #   assert_raise(ArgumentError) {
  #     @window3.move
  #   }
  #   # Uncomment the following lines to show the results
  #   # @window1.show(Cv::Mat.new(10, 20))
  #   # @window2.show(Cv::Mat.new(100, 200))
  #   # GUI::wait_key
  # end
  #
  # def test_set_trackbar
  #   tr1 = @window1.set_trackbar('trackbar1', 100) { |value|
  #     puts value
  #   }
  #   assert_equal(Trackbar, tr1.class)
  #   trackbar2 = Trackbar.new('trackbar2', 10, 1) {}
  #   tr2 = @window2.set_trackbar(trackbar2)
  #   assert_equal(Trackbar, tr2.class)
  # end
  #
  # def test_set_mouseevent
  #   @window1.set_mouse_callback { |mouse|
  #     e = "#{mouse.x}, #{mouse.y} : #{mouse.event} : "
  #     e << "<L>" if mouse.left_button?
  #     e << "<R>" if mouse.right_button?
  #     e << "<M>" if mouse.middle_button?
  #     e << "[CTRL]" if mouse.ctrl_key?
  #     e << "[SHIFT]" if mouse.shift_key?
  #     e << "[ALT]" if mouse.alt_key?
  #     puts e
  #   }
  # end
end
