#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-
require File.join(__dir__, 'helper')
include GUI
# Tests for OpenCV::MouseEvent
class MouseEventTest < OpenCVTestCase
  def test_initialize
    assert_not_nil(MouseEvent.new)
    assert_equal(MouseEvent, MouseEvent.new.class)
  end
end
