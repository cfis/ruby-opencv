#!/usr/bin/env ruby
require File.join(__dir__, 'helper')
include GUI
class TrackbarTest < OpenCVTestCase
  def setup
    @trackbar1 = Trackbar.new('trackbar1', 100) {}
    @trackbar2 = Trackbar.new('trackbar1', 100, 1) {}
  end

  
  def test_initialize
    assert_not_nil(Trackbar.new('trackbar', 100, 1) {})
    assert_not_nil(Trackbar.new('trackbar', 100) {})
    block = proc {}
    assert_not_nil(Trackbar.new('trackbar', 100, 1, &block))
    assert_not_nil(Trackbar.new('trackbar', 100, &block))
    assert_raise(TypeError) {
      Trackbar.new(123, 100, 1) {}
    }
    assert_raise(ArgumentError) {
      Trackbar.new('trackbar', 100, 1)
    }
  end

  def test_name
    assert_equal('trackbar1', @trackbar1.name)
  end

  def test_max
    assert_equal(100, @trackbar1.max)
  end

  def test_value
    assert_equal(0, @trackbar1.value)
    assert_equal(1, @trackbar2.value)
    @trackbar1.value = 50
    assert_equal(50, @trackbar1.value)
  end
end
