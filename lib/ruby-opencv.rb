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
