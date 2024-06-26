# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BonusOhneQtMitQt_autogen"
  "CMakeFiles/BonusOhneQtMitQt_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/BonusOhneQtMitQt_autogen.dir/ParseCache.txt"
  )
endif()
