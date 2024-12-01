require File.join(__dir__, 'ruby-opencv', 'version')

if RUBY_PLATFORM =~ /mingw|mswin/
  major, minor, subminor = RUBY_VERSION.split('.')
  begin
    require "#{major}.#{minor}/ruby_opencv.so"
  rescue LoadError
    require 'ruby_opencv.so'
  end
else
  require 'ruby_opencv.so'
end

require "ruby-opencv/version"
require "ruby-opencv/core/scalar"
require "ruby-opencv/core/mat_size"
require "ruby-opencv/core/mat"
require "ruby-opencv/core/sparse_mat"
