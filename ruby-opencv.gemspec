# -*- encoding: utf-8 -*-
# stub: ruby-opencv 0.0.18.20170306223602 ruby lib
# stub: ext/opencv/extconf.rb

Gem::Specification.new do |spec|
  spec.name = "ruby-opencv"
  spec.summary = "OpenCV wrapper for Ruby"
  spec.version = "1.0"
  spec.require_paths = ["lib"]
  spec.authors = ["lsxi", "ser1zw", "pcting", "Charlie Savage"]
  #spec.date = "2017-03-06"
  #spec.description = "ruby-opencv is a wrapper of OpenCV for Ruby. It helps you to write computer vision programs (e.g. detecting faces from pictures) with Ruby."
  #spec.email = ["masakazu.yonekura@gmail.com", "azariahsawtikes@gmail.com", "pcting@gmail.com"]
  #spec.extensions = ["ext/opencv/extconf.rb"]
  spec.extensions = ["ext/opencv/CMakeLists.txt"]
  #spec.extra_rdoc_files = ["DEVELOPERS_NOTE.md", "History.txt", "License.txt", "Manifest.txt", "README.md", "examples/facerec/readme.md"]

  spec.homepage = "https://github.com/ruby-opencv/ruby-opencv/"
  spec.licenses = ["BSD-3-Clause"]
  #spec.rdoc_options = ["--main", "README.md"]
  spec.required_ruby_version = Gem::Requirement.new(">= 3.3")

  spec.files = Dir.glob([".gitignore",
                         ".yardopts",
                         "DEVELOPERS_NOTE.md",
                         "Gemfile",
                         "History.txt",
                         "License.txt",
                         "Manifest.txt",
                         "README.md", "Rakefile",
                         "config.yml",
                         "examples/**/*.rb",
                         "ext/opencv/**/*.*",
                         "test/*.rb"])

  spec.add_development_dependency('minitest')
  #  spec.add_development_dependency("rice")
  #spec.add_development_dependency("base64")
  #spec.add_development_dependency('rake-compiler')
  #spec.add_development_dependency('logger')
  #spec.add_development_dependency('mutex_m')
end
