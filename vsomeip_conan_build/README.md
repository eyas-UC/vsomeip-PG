run:

`conan install conanfile.py --build=missing`

` git clone git clone -b 3.3.0 https://github.com/COVESA/vsomeip.git`

` conan build ../conanfile.py`

`conan export-pkg .. vsomeip_pkg/3.3.0`

under vsomeip_conan_build
to create a vsomeip package