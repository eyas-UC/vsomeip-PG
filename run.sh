mkdir -p build
cd build

conan profile new  --detect --force my_conan_profile
conan profile update  settings.compiler.libcxx=libstdc++11 my_conan_profile
# conan install  .. -pr=my_conan_profile --build=boost --build=vsomeip
conan install  .. -pr:b=default --build=missing
conan build ..