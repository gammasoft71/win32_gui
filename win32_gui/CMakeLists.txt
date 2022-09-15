cmake_minimum_required(VERSION 3.8)

# Project
project(win32_gui VERSION 1.0.0)
set(INCLUDES
  src/win32_gui/include/win32_gui.h
  src/win32_gui/include/win32_gui
)
set(WIN32_INCLUDES
  src/win32_gui/include/win32/object.h
  src/win32_gui/include/win32/delegate.h
  src/win32_gui/include/win32/event.h
  src/win32_gui/include/win32/event_args.h
  src/win32_gui/include/win32/event_handler.h
  src/win32_gui/include/win32/string.h
)
set(WIN32_DIAGNOSTICS_INCLUDES
  src/win32_gui/include/win32/diagnostics/debug.h
)

set(WIN32_DRAWING_INCLUDES
  src/win32_gui/include/win32/drawing/color.h
  src/win32_gui/include/win32/drawing/system_colors.h
)
set(WIN32_FORMS_INCLUDES
  src/win32_gui/include/win32/forms/application.h
  src/win32_gui/include/win32/forms/bounds_specified.h
  src/win32_gui/include/win32/forms/button.h
  src/win32_gui/include/win32/forms/component.h
  src/win32_gui/include/win32/forms/control.h
  src/win32_gui/include/win32/forms/control_styles.h
  src/win32_gui/include/win32/forms/create_params.h
  src/win32_gui/include/win32/forms/dark_mode.h
  src/win32_gui/include/win32/forms/dialog_result.h
  src/win32_gui/include/win32/forms/form.h
  src/win32_gui/include/win32/forms/help_event_args.h
  src/win32_gui/include/win32/forms/help_event_handler.h
  src/win32_gui/include/win32/forms/iwin32_window.h
  src/win32_gui/include/win32/forms/key_event_args.h
  src/win32_gui/include/win32/forms/key_event_handler.h
  src/win32_gui/include/win32/forms/key_press_event_args.h
  src/win32_gui/include/win32/forms/key_press_event_handler.h
  src/win32_gui/include/win32/forms/label.h
  src/win32_gui/include/win32/forms/message.h
  src/win32_gui/include/win32/forms/mouse_buttons.h
  src/win32_gui/include/win32/forms/mouse_event_args.h
  src/win32_gui/include/win32/forms/mouse_event_handler.h
  src/win32_gui/include/win32/forms/timer.h
  src/win32_gui/include/win32/forms/virtual_key_codes.h
  src/win32_gui/include/win32/forms/window_messages.h
)
set(WIN32_SOURCES
)
set(WIN32_DIAGNOSTICS_SOURCES
  src/win32_gui/src/win32/diagnostics/debug.cpp
)
set(WIN32_DRAWING_SOURCES
  src/win32_gui/src/win32/drawing/color.cpp
  src/win32_gui/src/win32/drawing/system_colors.cpp
)
set(WIN32_FORMS_SOURCES
  src/win32_gui/src/win32/forms/application.cpp
  src/win32_gui/src/win32/forms/button.cpp
  src/win32_gui/src/win32/forms/component.cpp
  src/win32_gui/src/win32/forms/control.cpp
  src/win32_gui/src/win32/forms/dark_mode.cpp
  src/win32_gui/src/win32/forms/form.cpp
  src/win32_gui/src/win32/forms/label.cpp
  src/win32_gui/src/win32/forms/timer.cpp
)
set(SOURCES 
  src/win32_gui/src/Program.cpp
)
source_group(src/win32_gui/include FILES ${INCLUDES})
source_group(src/win32_gui/include/win32 FILES ${WIN32_INCLUDES})
source_group(src/win32_gui/include/win32/diagnostics FILES ${WIN32_DIAGNOSTICS_INCLUDES})
source_group(src/win32_gui/include/win32/drawing FILES ${WIN32_DRAWING_INCLUDES})
source_group(src/win32_gui/include/win32/forms FILES ${WIN32_FORMS_INCLUDES})
source_group(src/win32_gui/src/win32 FILES ${SWIN32_SOURCES})
source_group(src/win32_gui/src/win32/diagnostics FILES ${WIN32_DIAGNOSTICS_SOURCES})
source_group(src/win32_gui/src/win32/drawing FILES ${WIN32_DRAWING_SOURCES})
source_group(src/win32_gui/src/win32/forms FILES ${WIN32_FORMS_SOURCES})
source_group(src/win32_gui/src FILES ${SOURCES})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:wmainCRTStartup")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_definitions(-DUNICODE)

# Application properties
add_executable(${PROJECT_NAME} WIN32 
  ${INCLUDES} 
  ${WIN32_INCLUDES} 
  ${WIN32_DIAGNOSTICS_INCLUDES}
  ${WIN32_DRAWING_INCLUDES}
  ${WIN32_FORMS_INCLUDES}
  ${SOURCES}
  ${WIN32_SOURCES}
  ${WIN32_DIAGNOSTICS_SOURCES}
  ${WIN32_DRAWING_SOURCES}
  ${WIN32_FORMS_SOURCES}
)
target_link_libraries(${PROJECT_NAME} PUBLIC UxTheme)
