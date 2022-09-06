cmake_minimum_required(VERSION 3.8)

# Project
project(win32_gui VERSION 1.0.0)
set(INCLUDES
  src/win32/include/application.h
  src/win32/include/bounds_specified.h
  src/win32/include/button.h
  src/win32/include/color.h
  src/win32/include/control.h
  src/win32/include/create_params.h
  src/win32/include/debug.h
  src/win32/include/delegate.h
  src/win32/include/dialog_result.h
  src/win32/include/event.h
  src/win32/include/event_args.h
  src/win32/include/event_handler.h
  src/win32/include/form.h
  src/win32/include/forms.h
  src/win32/include/iwin32_window.h
  src/win32/include/label.h
  src/win32/include/message.h
  src/win32/include/string.h
  src/win32/include/window_messages.h
)
set(SOURCES
  src/win32/src/application.cpp
  src/win32/src/button.cpp
  src/win32/src/control.cpp
  src/win32/src/debug.cpp
  src/win32/src/form.cpp
  src/win32/src/label.cpp
  src/win32/src/Program.cpp
)
source_group(src/win32/include FILES ${INCLUDES})
source_group(src/win32/src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_definitions(-DUNICODE)

# Application properties
add_executable(${PROJECT_NAME} WIN32 ${INCLUDES} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC UxTheme)