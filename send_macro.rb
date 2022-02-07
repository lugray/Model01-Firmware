#!/usr/bin/env ruby

require_relative 'focus'

focus = Focus.new

# Pulled from https://github.com/keyboardio/Kaleidoscope/blob/master/plugins/Kaleidoscope-Macros/src/kaleidoscope/plugin/Macros/MacroSteps.h

MACRO_ACTION_END = 0
MACRO_ACTION_STEP_INTERVAL = 1
MACRO_ACTION_STEP_WAIT = 2
MACRO_ACTION_STEP_KEYDOWN = 3
MACRO_ACTION_STEP_KEYUP = 4
MACRO_ACTION_STEP_TAP = 5
MACRO_ACTION_STEP_KEYCODEDOWN = 6
MACRO_ACTION_STEP_KEYCODEUP = 7
MACRO_ACTION_STEP_TAPCODE = 8
MACRO_ACTION_STEP_EXPLICIT_REPORT = 9
MACRO_ACTION_STEP_IMPLICIT_REPORT = 10
MACRO_ACTION_STEP_SEND_REPORT = 11
MACRO_ACTION_STEP_TAP_SEQUENCE = 12
MACRO_ACTION_STEP_TAP_CODE_SEQUENCE = 13

# Pulled from https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs/keyboard.h, https://github.com/keyboardio/Kaleidoscope/blob/ea45b7807164c18b0df28c74c045672d12b50f18/src/kaleidoscope/HIDTables.h
Key_Backspace = 0x2A
Key_Enter = 0x28
Key_Escape = 0x29
Key_Spacebar = 0x2C
SHIFT_HELD = 0b00001000
Key_A = 0x04
Key_1 = 0x1E
Key_Quote = 0x34
Key_Equals = 0x2E
Key_Comma = 0x36
Key_Minus = 0x2D
Key_Period = 0x37
Key_Slash = 0x38
Key_0 = 0x27
Key_Semicolon = 0x33
Key_LeftBracket = 0x2F
Key_Backslash = 0x31
Key_RightBracket = 0x30
Key_Backtick = 0x35

def key_n(n)
  Key_1 - 1 + n
end

# Adapted from
def key_flags_code_from_char(chr)
  flags = 0
  code = 0
  ascii_code = chr.ord

  case ascii_code
  when (0x08..0x09)
    code = Key_Backspace + ascii_code - 0x08
  when 0x0A
    code = Key_Enter
  when 0x1B
    code = Key_Escape
  when 0x20
    code = Key_Spacebar
  when 0x21
    flags = SHIFT_HELD
    code = key_n(1)
  when 0x22
    flags = SHIFT_HELD
    code = Key_Quote
  when 0x23
    flags = SHIFT_HELD
    code = key_n(3)
  when 0x24
    flags = SHIFT_HELD
    code = key_n(4)
  when 0x25
    flags = SHIFT_HELD
    code = key_n(5)
  when 0x26
    flags = SHIFT_HELD
    code = key_n(7)
  when 0x27
    code = Key_Quote
  when 0x28
    flags = SHIFT_HELD
    code = key_n(9)
  when 0x29
    flags = SHIFT_HELD
    code = key_n(0)
  when 0x2A
    flags = SHIFT_HELD
    code = key_n(8)
  when 0x2B
    flags = SHIFT_HELD
    code = Key_Equals
  when 0x2C
    code = Key_Comma
  when 0x2D
    code = Key_Minus
  when 0x2E
      code = Key_Period
  when 0x2F
      code = Key_Slash
  when 0x30
      code = Key_0
  when (0x31..0x39)
    code = Key_1 + ascii_code - 0x31
  when 0x3A
    flags = SHIFT_HELD
    code = Key_Semicolon
  when 0x3B
    code = Key_Semicolon
  when 0x3C
    flags = SHIFT_HELD
    code = Key_Comma
  when 0x3D
    code = Key_Equals
  when 0x3E
    flags = SHIFT_HELD
    code = Key_Period
  when 0x3F
    flags = SHIFT_HELD
    code = Key_Slash
  when 0x40
    flags = SHIFT_HELD
    code = key_n(2)
  when (0x41..0x5A)
    flags = SHIFT_HELD
    code = Key_A + ascii_code - 0x41
  when 0x5B
    code = Key_LeftBracket
  when 0x5C
    code = Key_Backslash
  when 0x5D
    code = Key_RightBracket
  when 0x5E
    flags = SHIFT_HELD
    code = key_n(6)
  when 0x5F
    flags = SHIFT_HELD
    code = Key_Minus
  when 0x60
    code = Key_Backtick
  when (0x61..0x7A)
    code = Key_A + ascii_code - 0x61
  when 0x7B
    flags = SHIFT_HELD
    code = Key_LeftBracket
  when 0x7C
    flags = SHIFT_HELD
    code = Key_Backslash
  when 0x7D
    flags = SHIFT_HELD
    code = Key_RightBracket
  when 0x7E
    flags = SHIFT_HELD
    code = Key_Backtick
  end
  [flags, code]
end

def string_to_macro(str)
  str.each_char.flat_map do |c|
    [MACRO_ACTION_STEP_TAP] + key_flags_code_from_char(c)
  end
end

calculate_size = ARGV.delete('-s')

def macros
  ARGV.flat_map { |str| string_to_macro(str) + [MACRO_ACTION_END] } + [MACRO_ACTION_END]
end

if calculate_size
  puts macros.size
else
  focus.command('macros.map', *macros)
end
