// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#include "Kaleidoscope.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-NumPad.h"
#include "Kaleidoscope-SpaceCadet.h"

enum { E_T, E_H, E_J, E_E, E_W, E_P, E_Y, E_G, E_M, E_F }; // Emoji Keys
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;

enum { PRIMARY, NUMPAD, FUNCTION, BUTTERFLY, BUTTERFLY_FN, EMPTY }; // layers

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    ___,                    Key_1,         Key_2,       Key_3,         Key_4, Key_5, Key_LeftAlt,
    Key_Backtick,           Key_Q,         Key_W,       Key_E,         Key_R, Key_T, Key_Tab,
    Key_Home,               Key_A,         Key_S,       Key_D,         Key_F, Key_G, /**/
    Key_End,                Key_Z,         Key_X,       Key_C,         Key_V, Key_B, Key_Escape,
    Key_LeftControl,        Key_Backspace, Key_LeftGui, Key_LeftShift, /**/   /**/   /**/
    ShiftToLayer(FUNCTION), /**/           /**/         /**/           /**/   /**/   /**/

    LCTRL(LSHIFT(LALT(LGUI(Key_S)))), Key_6,        Key_7,        Key_8,            Key_9,      Key_0,         LockLayer(NUMPAD),
    Key_Enter,                        Key_Y,        Key_U,        Key_I,            Key_O,      Key_P,         Key_Equals,
    /**/                              Key_H,        Key_J,        Key_K,            Key_L,      Key_Semicolon, Key_Quote,
    ShiftToLayer(BUTTERFLY),          Key_N,        Key_M,        Key_Comma,        Key_Period, Key_Slash,     Key_Minus,
    Key_RightShift,                   Key_RightGui, Key_Spacebar, Key_RightControl, /**/        /**/           /**/
    ShiftToLayer(FUNCTION)            /**/          /**/          /**/              /**/        /**/           /**/

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

    ___,          Key_F1,          Key_F2,     Key_F3, Key_F4, Key_F5, Key_CapsLock,
    Key_Tab,      ___,             ___,        ___,    ___,    ___,    ___,
    Key_PageUp,   ___,             ___,        ___,    ___,    ___,    /**/
    Key_PageDown, Key_PrintScreen, Key_Insert, ___,    ___,    ___,    ___,
    ___,          Key_Delete,      ___,        ___,    /**/    /**/    /**/
    ___,          /**/             /**/        /**/    /**/    /**/    /**/

    Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,               Key_F8,                   Key_F9,                   Key_F10,          Key_F11,
    Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket, Key_RightCurlyBracket,    Key_LeftBracket,          Key_RightBracket, Key_F12,
    /**/                        Key_LeftArrow,          Key_DownArrow,        Key_UpArrow,              Key_RightArrow,           ___,              ___,
    ShiftToLayer(BUTTERFLY_FN), ___,                    Consumer_Mute,        Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash,    Key_Pipe,
    ___,                        ___,                    Key_Enter,            ___,                      /**/                      /**/              /**/
    ___                         /**/                    /**/                  /**/                      /**/                      /**/              /**/

  ), [BUTTERFLY] = KEYMAP_STACKED(

    ___,                        ___, ___,          ___,          ___,          ___,          ___,
    ___,                        ___, M(E_W|EMOJI), M(E_E|EMOJI), ___,          M(E_T|EMOJI), ___,
    ___,                        ___, ___,          ___,          M(E_F|EMOJI), M(E_G|EMOJI), /**/
    ___,                        ___, ___,          ___,          ___,          ___,          ___,
    ___,                        ___, ___,          ___,          /**/          /**/          /**/
    ShiftToLayer(BUTTERFLY_FN), /**/ /**/          /**/          /**/          /**/          /**/

    ___,                       ___,          ___,          ___, ___, ___,          ___,
    ___,                       M(E_Y|EMOJI), ___,          ___, ___, M(E_P|EMOJI), ___,
    /**/                       M(E_H|EMOJI), M(E_J|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          M(E_M|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          ___,          ___, /**/ /**/          /**/
    ShiftToLayer(BUTTERFLY_FN) /**/          /**/          /**/ /**/ /**/          /**/

  ), [BUTTERFLY_FN] = KEYMAP_STACKED(

    ___, ___, ___,          ___,          ___,          ___,          ___,
    ___, ___, M(E_W|REACT), M(E_E|REACT), ___,          M(E_T|REACT), ___,
    ___, ___, ___,          ___,          M(E_F|REACT), M(E_G|REACT), /**/
    ___, ___, ___,          ___,          ___,          ___,          ___,
    ___, ___, ___,          ___,          /**/          /**/          /**/
    ___, /**/ /**/          /**/          /**/          /**/          /**/

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
  {Key_RightGui,     Key_RightCurlyBracket, spaceCadetTimeout},
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
    return PSTR("thanks-2");
  case E_F:
    return PSTR("facepalm");
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

class : public kaleidoscope::plugin::LEDMode {
  protected:
    void onActivate(void) {
      activate_millis = Kaleidoscope.millisAtCycleStart();
    }

    void update(void) {
      for (int8_t i = 0; i < LED_COUNT; i++) {
        uint16_t key_hue = rainbow_start_hue + (rainbow_end_hue * 4 / LED_COUNT) * (i / 4);
        if (key_hue >= 255)          {
          key_hue -= 255;
        }

        uint32_t delta = Kaleidoscope.millisAtCycleStart() - activate_millis;
        byte value;
        if (delta > ramp_time) {
          value = rainbow_value;
        } else {
          value = rainbow_value * delta / ramp_time;
        }

        cRGB rainbow = hsvToRgb(key_hue, rainbow_saturation, value);
        ::LEDControl.setCrgbAt(i, rainbow);
      }
    }

  private:
    uint16_t rainbow_start_hue = 0;  //  stores 0 to 614
    uint16_t rainbow_end_hue = 230;  //  stores 0 to 614

    byte rainbow_saturation = 255;
    byte rainbow_value = 180;
    uint32_t activate_millis = 0;
    uint16_t ramp_time = 1000;

} ledRainbowStaticEffect;

KALEIDOSCOPE_INIT_PLUGINS(
  Focus,
  LEDControl,
  ledRainbowStaticEffect,
  SpaceCadet,
  NumPad,
  Macros
);

void setup() {
  Kaleidoscope.setup();
  NumPad.numPadLayer = NUMPAD;
  ledRainbowStaticEffect.activate();
  SpaceCadet.map = spaceCadetMap;
}

void loop() {
  Kaleidoscope.loop();
}
