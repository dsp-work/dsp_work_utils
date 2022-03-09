find_program(CLANG_FORMAT_EXE clang-format)

file(GLOB_RECURSE project_sources CONFIGURE_DEPENDS "[a-zA-Z]*.cpp" "[a-zA-Z]*.hpp")
list(FILTER project_sources EXCLUDE REGEX "build/*")

# add build target (clang-format lints)
# In use,
# `cmake --build . --target ${PROJECT_NAME}-format --verbose`
add_custom_target("${PROJECT_NAME}-format"
  COMMAND ${CLANG_FORMAT_EXE} --style=file --dry-run ${project_sources}
  COMMENT "Running clang-format(lints)"
  VERBATIM
  )

# add build target (clang-format warning overwrite)
# In use,
# `cmake --build . --target ${PROJECT_NAME}-format-fix`
add_custom_target("${PROJECT_NAME}-format-fix"
  COMMAND ${CLANG_FORMAT_EXE} --style=file -i ${project_sources}
  COMMENT "Running clang-format(overwrite)"
  VERBATIM
  )