# -*- mode: ruby; coding: utf-8 -*-
require 'rubygems'
require "rubygems/ext"
require "rubygems/installer"
require 'rake/extensiontask'
require 'fileutils'
require 'yard'
require 'yard/rake/yardoc_task'

SO_FILE = 'opencv.so'

Gem::Specification.new do |spec|
  spec.summary = 'OpenCV wrapper for Ruby'
  spec.description = 'ruby-opencv is a wrapper of OpenCV for Ruby. It helps you to write computer vision programs (e.g. detecting faces from pictures) with Ruby.'
  spec.licenses = ['BSD-3-Clause']
  spec.authors = ['lsxi', 'ser1zw', 'pcting']

#  spec.spec_extras = { :extensions => ['ext/opencv/extconf.rb'] }

  spec.test_files = Dir['test/test_*.rb']
#  spec.urls = ['https://github.com/ruby-opencv/ruby-opencv/']

#  spec.extra_dev_deps << ['rake-compiler', '~> 0'] << ['hoe-gemspec', '~> 0']

  Rake::ExtensionTask.new('opencv', spec) do |ext|
    ext.lib_dir = 'lib'
  end
end

# yard
YARD::Rake::YardocTask.new do |t|
  t.files   = ['lib/**/*.rb', 'ext/**/*.cpp']
end
