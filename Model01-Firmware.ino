// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-NumPad.h"
#include "Kaleidoscope-Model01-TestMode.h"
#include "Kaleidoscope-MagicCombo.h"
#include "Kaleidoscope-USB-Quirks.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "LEDEffect-RainbowStatic.h"

enum { E_T, E_H, E_J, E_E, E_W, E_P, E_Y, E_G, E_M }; // Emoji Keys
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;

enum { PRIMARY, NUMPAD, FUNCTION, BUTTERFLY, BUTTERFLY_FN, EMPTY }; // layers

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    ___,                    Key_1,         Key_2,       Key_3,         Key_4, Key_5, ___,
    Key_Backtick,           Key_Q,         Key_W,       Key_E,         Key_R, Key_T, Key_Tab,
    Key_PageUp,             Key_A,         Key_S,       Key_D,         Key_F, Key_G, /**/
    Key_PageDown,           Key_Z,         Key_X,       Key_C,         Key_V, Key_B, Key_Escape,
    Key_LeftControl,        Key_Backspace, Key_LeftGui, Key_LeftShift, /**/   /**/   /**/
    ShiftToLayer(FUNCTION), /**/           /**/         /**/           /**/   /**/   /**/

    LCTRL(LSHIFT(LALT(LGUI(Key_S)))), Key_6,       Key_7,        Key_8,            Key_9,      Key_0,         LockLayer(NUMPAD),
    Key_Enter,                        Key_Y,       Key_U,        Key_I,            Key_O,      Key_P,         Key_Equals,
    /**/                              Key_H,       Key_J,        Key_K,            Key_L,      Key_Semicolon, Key_Quote,
    ShiftToLayer(BUTTERFLY),          Key_N,       Key_M,        Key_Comma,        Key_Period, Key_Slash,     Key_Minus,
    Key_RightShift,                   Key_LeftAlt, Key_Spacebar, Key_RightControl, /**/        /**/           /**/
    ShiftToLayer(FUNCTION)            /**/         /**/          /**/              /**/        /**/           /**/

  ), [NUMPAD] = KEYMAP_STACKED(

    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, /**/
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, /**/ /**/ /**/
    ___, /**/ /**/ /**/ /**/ /**/ /**/

    ___, ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
    ___, ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
    /**/ ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         ___,
    ___, ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
    ___, ___, ___,         ___,           /**/                /**/                /**/
    ___  /**/ /**/         /**/           /**/                /**/                /**/

  ), [FUNCTION] = KEYMAP_STACKED (

    ___,      Key_F1,          Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_CapsLock,
    Key_Tab,  ___,             Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
    Key_Home, Key_mouseL,      Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,  /**/
    Key_End,  Key_PrintScreen, Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
    ___,      Key_Delete,      ___,         ___,        /**/           /**/              /**/
    ___,      /**/             /**/         /**/        /**/           /**/              /**/

    Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
    Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
    /**/                        Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
    ShiftToLayer(BUTTERFLY_FN), Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
    ___,                        ___,                    Key_Enter,                ___,                      /**/             /**/              /**/
    ___                         /**/                    /**/                      /**/                      /**/             /**/              /**/

  ), [BUTTERFLY] = KEYMAP_STACKED(

    ___,                        ___, ___,          ___,          ___, ___,          ___,
    ___,                        ___, M(E_W|EMOJI), M(E_E|EMOJI), ___, M(E_T|EMOJI), ___,
    ___,                        ___, ___,          ___,          ___, M(E_G|EMOJI), /**/
    ___,                        ___, ___,          ___,          ___, ___,          ___,
    ___,                        ___, ___,          ___,          /**/ /**/          /**/
    ShiftToLayer(BUTTERFLY_FN), /**/ /**/          /**/          /**/ /**/          /**/

    ___,                       ___,          ___,          ___, ___, ___,          ___,
    ___,                       M(E_Y|EMOJI), ___,          ___, ___, M(E_P|EMOJI), ___,
    /**/                       M(E_H|EMOJI), M(E_J|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          M(E_M|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          ___,          ___, /**/ /**/          /**/
    ShiftToLayer(BUTTERFLY_FN) /**/          /**/          /**/ /**/ /**/          /**/

  ), [BUTTERFLY_FN] = KEYMAP_STACKED(

    ___, ___, ___,          ___,          ___, ___,          ___,
    ___, ___, M(E_W|REACT), M(E_E|REACT), ___, M(E_T|REACT), ___,
    ___, ___, ___,          ___,          ___, M(E_G|REACT), /**/
    ___, ___, ___,          ___,          ___, ___,          ___,
    ___, ___, ___,          ___,          /**/ /**/          /**/
    ___, /**/ /**/          /**/          /**/ /**/          /**/

    ___, ___,          ___,          ___, ___, ___,          ___,
    ___, M(E_Y|REACT), ___,          ___, ___, M(E_P|REACT), ___,
    /**/ M(E_H|REACT), M(E_J|REACT), ___, ___, ___,          ___,
    ___, ___,          M(E_M|REACT), ___, ___, ___,          ___,
    ___, ___,          ___,          ___, /**/ /**/          /**/
    ___  /**/          /**/          /**/ /**/ /**/          /**/

  ), [EMPTY] = KEYMAP_STACKED(

    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, /**/
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, /**/ /**/ /**/
    ___, /**/ /**/ /**/ /**/ /**/ /**/

    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    /**/ ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, /**/ /**/ /**/
    ___  /**/ /**/ /**/ /**/ /**/ /**/

  )
)

static const int spaceCadetTimeout = 250;
static kaleidoscope::plugin::SpaceCadet::KeyBinding spaceCadetMap[] = {
  {Key_LeftShift,    Key_LeftParen,         spaceCadetTimeout},
  {Key_RightShift,   Key_RightParen,        spaceCadetTimeout},
  {Key_LeftGui,      Key_LeftCurlyBracket,  spaceCadetTimeout},
  {Key_LeftAlt,      Key_RightCurlyBracket, spaceCadetTimeout},
  {Key_LeftControl,  Key_LeftBracket,       spaceCadetTimeout},
  {Key_RightControl, Key_RightBracket,      spaceCadetTimeout},
  SPACECADET_MAP_END
};


static const char* emojiPstr(int emojiIndex) {
  switch(emojiIndex) {
  case E_T:
    return PSTR("thumbsup");
  case E_H:
    return PSTR("heart");
  case E_J:
    return PSTR("joy");
  case E_E:
    return PSTR("eyes");
  case E_W:
    return PSTR("wave");
  case E_P:
    return PSTR("point_up");
  case E_Y:
    return PSTR("tada");
  case E_G:
    return PSTR("galaxy");
  case E_M:
    return PSTR("mirror");
  }
  return PSTR("");
}

static void slackReactMacro(int emojiIndex, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.play(MACRO(D(LeftGui), D(LeftShift), T(Backslash), U(LeftShift), U(LeftGui)));
    Macros.type(emojiPstr(emojiIndex));
    Macros.play(MACRO(W(255), W(255), T(Enter)));
  }
}

static void typeEmjoiMacro(int emojiIndex, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR(":"));
    Macros.type(emojiPstr(emojiIndex));
    Macros.type(PSTR(":"));
  }
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  // 11xxxxxx => Emoji Reaction
  // 10xxxxxx => Emoji In-line
  // 0xxxxxxx => Other Macros
  if ((macroIndex & EMOJI) == EMOJI) {
    if ((macroIndex & REACT) == REACT) {
      slackReactMacro(macroIndex & (~REACT), keyState);
    } else {
      typeEmjoiMacro(macroIndex & (~EMOJI), keyState);
    }
  }
  return MACRO_NONE;
}

enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE
};

static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
  EEPROMKeymap,
  Focus,
  FocusSettingsCommand,
  FocusEEPROMCommand,
  TestMode,
  LEDControl,
  LEDRainbowStaticEffect,
  SpaceCadet,
  NumPad,
  Macros,
  MouseKeys,
  MagicCombo,
  USBQuirks
);

void setup() {
  Kaleidoscope.setup();
  NumPad.numPadLayer = NUMPAD;
  LEDRainbowStaticEffect.brightness(150);
  LEDRainbowStaticEffect.start_hue(0);
  LEDRainbowStaticEffect.end_hue(230);
  LEDRainbowStaticEffect.activate();
  SpaceCadet.map = spaceCadetMap;
  EEPROMKeymap.setup(5, EEPROMKeymap.Mode::EXTEND);
}

void loop() {
  Kaleidoscope.loop();
}
