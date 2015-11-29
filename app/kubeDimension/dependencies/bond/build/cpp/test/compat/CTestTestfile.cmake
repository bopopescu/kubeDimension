# CMake generated Testfile for 
# Source directory: /src/app/find-object/dependencies/bond/cpp/test/compat
# Build directory: /src/app/find-object/dependencies/bond/build/cpp/test/compat
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(compatibility_compact "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "compact" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.compact.dat" "expected.cpp.compact" "deserialized.cpp.compact")
set_tests_properties(compatibility_compact PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_compact2 "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "compact2" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.compact2.dat" "expected.cpp.compact2" "deserialized.cpp.compact2")
set_tests_properties(compatibility_compact2 PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_fast "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "fast" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.fast.dat" "expected.cpp.fast" "deserialized.cpp.fast")
set_tests_properties(compatibility_fast PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_json "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "json" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.json.dat" "expected.cpp.json" "deserialized.cpp.json")
set_tests_properties(compatibility_json PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_simple "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "simple" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.simple.dat" "expected.cpp.simple" "deserialized.cpp.simple")
set_tests_properties(compatibility_simple PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_simple2 "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "simple2" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.simple2.dat" "expected.cpp.simple2" "deserialized.cpp.simple2")
set_tests_properties(compatibility_simple2 PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
add_test(compatibility_schema "/src/app/find-object/dependencies/bond/build/cpp/test/compat/compatibility_test" "schema" "-d" "/src/app/find-object/dependencies/bond/test/compat/data/compat.schema.dat" "expected.cpp.schema" "deserialized.cpp.schema")
set_tests_properties(compatibility_schema PROPERTIES  WORKING_DIRECTORY "/src/app/find-object/dependencies/bond/build/cpp/test/compat")
