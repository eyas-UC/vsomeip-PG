rm -rf build
mkdir -p build
cd build
git clone -b 3.3.0 https://github.com/COVESA/vsomeip.git
conan install ../conanfile.py  -pr:b=default --build=missing



conan build ../conanfile.py
conan export-pkg .. rem/dev --force