# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\park1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\park1_autogen.dir\\ParseCache.txt"
  "park1_autogen"
  )
endif()
