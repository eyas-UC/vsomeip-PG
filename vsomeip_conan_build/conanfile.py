#!/usr/bin/env python

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain
from conan.tools.files import collect_libs


class VSomeIPConan(ConanFile):
    name = "vsomeip"
    version = "3.3.0"
    settings = "os", "compiler", "build_type", "arch"
    exports = "*"

    def requirements(self):
        self.requires("boost/1.74.0")

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def source(self):
        self.run("git clone https://github.com/COVESA/vsomeip.git")
        self.run("cd %s && git checkout %s" % (self.name, 'tags/3.3.0'))
        self.run("git restore .")
        self.run("git clean -df")

    def generate(self):
         tc = CMakeToolchain(self)
         tc.cache_variables["Boost_VERSION_MACRO"] = "107400"
         tc.generate()
         deps = CMakeDeps(self)
         deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h",dst="include",src="vsomeip")
        self.copy("*vsomeip.lib", dst="lib",keep_path=False)
        self.copy("*.dll",dst="bin",keep_path=False)
        self.copy("*.so",dst="lib",keep_path=False)
        self.copy("*.dylib",dst="lib",keep_path=False)
        self.copy("*.a",dst="lib",keep_path=False)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = collect_libs(self)

