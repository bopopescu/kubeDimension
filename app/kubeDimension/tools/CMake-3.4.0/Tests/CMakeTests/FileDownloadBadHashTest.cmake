set(url "file:///src/app/kubeDimension/tools/CMake-3.4.0/Tests/CMakeTests/FileDownloadInput.png")
set(dir "/src/app/kubeDimension/tools/CMake-3.4.0/Tests/CMakeTests/downloads")

file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA1=5555555555555555555555555555555555555555
  )
