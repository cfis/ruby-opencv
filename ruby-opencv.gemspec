# -*- encoding: utf-8 -*-
# stub: ruby-opencv 0.0.18.20170306223602 ruby lib
# stub: ext/opencv/extconf.rb

Gem::Specification.new do |spec|
  spec.name = "ruby-opencv"
  spec.summary = "Ruby bindingds for OpenCV library"
  spec.version = "1.0"
  spec.require_paths = ["lib"]
  spec.authors = ["lsxi", "ser1zw", "pcting", "Charlie Savage"]
  spec.date = "2025-05-25"
  spec.description = "ruby-opencv provides Ruby bindings for the OpenCV library."
  spec.email = ["masakazu.yonekura@gmail.com", "azariahsawtikes@gmail.com", "pcting@gmail.com"]
  spec.extensions = ["ext/CMakeLists.txt"]
  spec.extra_rdoc_files = ["DEVELOPERS_NOTE.md", "History.txt", "License.txt", "README.md", "examples/facerec/readme.md"]

  spec.homepage = "https://github.com/ruby-opencv/ruby-opencv/"
  spec.licenses = ["BSD-3-Clause"]
  spec.rdoc_options = ["--main", "README.md"]
  spec.required_ruby_version = Gem::Requirement.new(">= 3.2")

  spec.files = Dir.glob([".gitignore",
                         ".yardopts",
                         "DEVELOPERS_NOTE.md",
                         "Gemfile",
                         "History.txt",
                         "License.txt",
                         "Manifest.txt",
												 "Rakefile",
                         "README.md",
                         "config.yml",
                         "examples/**/*.rb",
                         "ext/CMakeLists.txt",
                         "ext/CMakePresets.json",
                         "ext/ruby_opencv.def",
                         "ext/ruby_opencv-rb.cpp",
                         "ext/ruby_opencv-rb.hpp",
                         "ext/opencv2/**/*.*",
                         "ext/rice/*.hpp",
                         "test/*.rb"])

	spec.add_runtime_dependency('rice', '>= 4.6')
	spec.add_development_dependency('minitest')
	spec.add_development_dependency('rake')
	spec.add_development_dependency('yard')
end
