#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "TGUI::TGUI" for configuration "Release"
set_property(TARGET TGUI::TGUI APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(TGUI::TGUI PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/libtgui.a"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/tgui.dll"
  )

list(APPEND _cmake_import_check_targets TGUI::TGUI )
list(APPEND _cmake_import_check_files_for_TGUI::TGUI "${_IMPORT_PREFIX}/lib/libtgui.a" "${_IMPORT_PREFIX}/bin/tgui.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
