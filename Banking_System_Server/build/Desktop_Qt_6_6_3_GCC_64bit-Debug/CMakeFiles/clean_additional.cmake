# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Banking_System_Server_autogen"
  "CMakeFiles/Banking_System_Server_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Banking_System_Server_autogen.dir/ParseCache.txt"
  )
endif()
