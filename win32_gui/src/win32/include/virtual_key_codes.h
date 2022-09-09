#pragma once
#include <Windows.h>

constexpr UINT VK_ALT = VK_MENU;

/// @brief The CMD key.
constexpr UINT VK_COMMAND = 0x00000100;
/// @brief The left CMD key.
constexpr UINT VK_LCOMMAND = 0x00000101;
/// @brief The right CMD key.
constexpr UINT VK_RCOMMAND = 0x00000102;
/// @brief The FUNCTION key.
constexpr UINT VK_FUNCTION = 0x00000104;

/// @brief The SHIFt modifier key.
constexpr UINT VK_SHIFT_MODIFIER = 0x00010000;
/// @brief The CTRL modifier key.
constexpr UINT VK_CONTROL_MODIFIER = 0x00020000;
/// @brief The ALT modifier key.
constexpr UINT VK_ALT_MODIFIER = 0x00040000;
/// @brief The CMD modifier key.
constexpr UINT VK_COMMAND_MODIFIER = 0x00080000;
/// @brief The METTA modifier key.
constexpr UINT VK_META_MODIFIER = 0x00100000;
/// @brief The FUNCTION modifier key.
constexpr UINT VK_FUNCTION_MODIFIER = 0x00200000;

/// @brief The bitmask to extract a key code from a key value.
constexpr UINT VK_KEY_CODE_MASK = 0x0000FFFF;
/// @brief The bitmask to extract modifiers from a key value.
constexpr UINT VK_MODIFIERS_MASK = 0xFFFF0000;
