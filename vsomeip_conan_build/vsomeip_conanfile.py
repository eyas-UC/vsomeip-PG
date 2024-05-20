from conans import ConanFile, Cmake


class VsomeipConan(ConanFile):
    name = "vsomeip"
    version = "1.0.0"
    settings = "os", "compiler", "build_type", "arch"
    generator = "cmake"
    requires = "boost/1.74.0"


    def build(self):
        cmake = Cmake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        self.copy("*.h",dst="include",src="")