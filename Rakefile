# -*- mode: ruby; coding: utf-8 -*-
require "rubygems/package_task"
require "rake/testtask"
require "yarn"

# Read the spec file
spec = Gem::Specification.load("ruby-opencv.gemspec")

# Setup generic gem
Gem::PackageTask.new(spec) do |pkg|
  pkg.package_dir = "pkg"
  pkg.need_tar    = false
end

# Setup Windows Gem
if RUBY_PLATFORM.match(/mswin|mingw/)
  binaries = (FileList["lib/**/*.so",
                       "lib/**/*dll"])

  # Windows specification
  win_spec = spec.clone
  win_spec.platform = Gem::Platform::CURRENT
  win_spec.files += binaries.to_a
  win_spec.instance_variable_set(:@cache_file, nil)

  # Unset extensions
  win_spec.extensions = nil

  # Rake task to build the windows package
  Gem::PackageTask.new(win_spec) do |pkg|
    pkg.package_dir = "pkg"
    pkg.need_tar = false
  end
end

# yard
YARD::Rake::YardocTask.new do |t|
  t.files   = ["lib/**/*.rb", "ext/**/*.cpp"]
end
