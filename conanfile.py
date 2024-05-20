from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain

class vsomeip_project(ConanFile):
   name="vsomeip-pg"
   version="1.0.0"
   settings = "os", "compiler", "build_type", "arch"
   # requires = "vsomeip/3.3.0@rem/dev"
   generators = "cmake_find_package"
   default_options = {"poco:shared": True, "openssl:shared": True}

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin") # From bin to bin
      self.copy("*.dylib*", dst="bin", src="lib") # From lib to bin


   def requirements(self):
         self.requires("vsomeip/3.3.0@rem/dev")
         pass


   def generate(self):
         tc = CMakeToolchain(self)
         tc.generate()
         deps = CMakeDeps(self)
         deps.generate()
   def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
