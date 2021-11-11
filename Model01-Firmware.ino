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
#include "Kaleidoscope-LED-Wavepool.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-TopsyTurvy.h"
#include "Kaleidoscope-Ranges.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-DynamicMacros.h"

enum { E_A, E_B, E_C, E_D, E_E, E_F, E_G, E_H, E_I, E_J, E_K, E_L, E_M, E_N, E_O, E_P, E_Q, E_R, E_S, E_T, E_U, E_V, E_W, E_X, E_Y, E_Z, E_PLUS }; // Emoji Keys
enum { MACRO_NOP, CYCLE_LED_MODE, TOGGLE_QUINN }; // Macros
enum { DM_ANY }; // Dynamic Macros
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;
#define E(n) M(n|EMOJI)
#define R(n) M(n|REACT)
#define Key_NOP M(MACRO_NOP)
#define STL(n) ShiftToLayer(n)

enum { PRIMARY, L_FN, L_EMOJI, L_REACT, QUINN, Q_FN }; // layers

#define Sleep LCTRL(LGUI(Key_Q))
#define WinUp LCTRL(LALT(Key_UpArrow))
#define WinDown LCTRL(LALT(Key_DownArrow))
#define WinLeft LCTRL(LALT(Key_LeftArrow))
#define WinRight LCTRL(LALT(Key_RightArrow))
#define WinMax LCTRL(LALT(Key_Enter))
#define Mute Consumer_Mute
#define VolDown Consumer_VolumeDecrement
#define VolUp Consumer_VolumeIncrement

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    STL(L_REACT), Key_1, Key_2, Key_3,           Key_4,         Key_5,       Key_LEDEffectNext,
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_Home,     Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_End,      Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_LeftAlt,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         STL(L_FN),

    Sleep,          Key_6,        Key_7,        Key_8,            Key_9,      Key_0,            ___,
    Key_Enter,      Key_Y,        Key_U,        Key_I,            Key_O,      Key_P,            Key_Equals,
    /**/            Key_H,        Key_J,        Key_K,            Key_L,      TOPSY(Semicolon), Key_Quote,
    TOPSY(Minus),   Key_N,        Key_M,        Key_Comma,        Key_Period, Key_Slash,        Key_Minus,
    Key_RightShift, Key_RightGui, Key_Spacebar, Key_RightControl, /**/        /**/              /**/
    STL(L_FN)       /**/          /**/          /**/              /**/        /**/              /**/

  ), [L_FN] = KEYMAP_STACKED (

    ___,          Key_F1,  Key_F2,     Key_F3,   Key_F4,     Key_F5, M(TOGGLE_QUINN),
    Key_Tab,      ___,     WinUp,      ___,      ___,        ___,    ___,
    Key_PageUp,   WinLeft, WinDown,    WinRight, ___,        ___,    /**/
    Key_PageDown, ___,     Key_Insert, ___,      ___,        ___,    ___,
    /**/          /**/     /**/        ___,      Key_Delete, ___,    ___,
    /**/          /**/     /**/        /**/      /**/        /**/    STL(L_EMOJI),

    DM(DM_ANY),   Key_F6,        Key_F7,        Key_F8,      Key_F9,         Key_F10,       Key_F11,
    WinMax,       ___,           ___,           ___,         ___,            ___,           Key_F12,
    /**/          Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow, ___,           ___,
    ___,          ___,           Mute,          VolDown,     VolUp,          Key_Backslash, Key_Pipe,
    ___,          ___,           Key_Enter,     ___,         /**/            /**/           /**/
    STL(L_EMOJI), /**/           /**/           /**/         /**/            /**/           /**/

  ), [L_EMOJI] = KEYMAP(

    ___, ___,    ___,    ___,    ___,    ___,    ___, ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, E(E_Q), E(E_W), E(E_E), E(E_R), E(E_T), ___, ___, E(E_Y), E(E_U), E(E_I), E(E_O), E(E_P), E(E_PLUS),
    ___, E(E_A), E(E_S), E(E_D), E(E_F), E(E_G), /**/ /**/ E(E_H), E(E_J), E(E_K), E(E_L), ___,    ___,
    ___, E(E_Z), E(E_X), E(E_C), E(E_V), E(E_B), ___, ___, E(E_N), E(E_M), ___,    ___,    ___,    ___,
    /**/ /**/    /**/    ___,    ___,    ___,    ___, ___, ___,    ___,    ___,    /**/    /**/    /**/
    /**/ /**/    /**/    /**/    /**/    /**/    ___, ___  /**/    /**/    /**/    /**/    /**/    /**/

  ), [L_REACT] = KEYMAP(

    ___, ___,    ___,    ___,    ___,    ___,    ___, ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, R(E_Q), R(E_W), R(E_E), R(E_R), R(E_T), ___, ___, R(E_Y), R(E_U), R(E_I), R(E_O), R(E_P), R(E_PLUS),
    ___, R(E_A), R(E_S), R(E_D), R(E_F), R(E_G), /**/ /**/ R(E_H), R(E_J), R(E_K), R(E_L), ___,    ___,
    ___, R(E_Z), R(E_X), R(E_C), R(E_V), R(E_B), ___, ___, R(E_N), R(E_M), ___,    ___,    ___,    ___,
    /**/ /**/    /**/    ___,    ___,    ___,    ___, ___, ___,    ___,    ___,    /**/    /**/    /**/
    /**/ /**/    /**/    /**/    /**/    /**/    ___, ___  /**/    /**/    /**/    /**/    /**/    /**/

  ), [QUINN] =  KEYMAP(

    Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,   Key_NOP,  Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,
    Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,   Key_NOP,  Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,
    Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, /**/       /**/      Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,
    Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,   Key_NOP,  Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP, Key_NOP,
    /**/     /**/     /**/     Key_NOP, Key_NOP, Key_NOP, Key_NOP,   Key_NOP,  Key_NOP, Key_NOP, Key_NOP, /**/     /**/     /**/
    /**/     /**/     /**/     /**/     /**/     /**/     STL(Q_FN), STL(Q_FN) /**/     /**/     /**/     /**/     /**/     /**/

  ), [Q_FN] =  KEYMAP(

    ___, ___, ___, ___, ___, ___, M(TOGGLE_QUINN), ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,             ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, /**/             /**/ ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,             ___, ___, ___, ___, ___, ___, ___,
    /**/ /**/ /**/ ___, ___, ___, ___,             ___, ___, ___, ___, /**/ /**/ /**/
    /**/ /**/ /**/ /**/ /**/ /**/ ___,             ___  /**/ /**/ /**/ /**/ /**/ /**/

  )
)

class : public kaleidoscope::plugin::LEDMode {
  protected:
    void onActivate(void) {
      activate_millis = Kaleidoscope.millisAtCycleStart();
    }

    void update(void) {
      for (uint8_t i = 0; i < Kaleidoscope.device().led_count; i++) {
        uint8_t color_index = i / 4;
        if (i > 36) color_index -= 2;
        else if (i > 26) color_index -= 1;

        uint32_t delta = Kaleidoscope.millisAtCycleStart() - activate_millis;
        uint32_t offset = max_hue * delta / cycle_time;
        uint8_t key_hue = (offset + max_hue * color_index / 14) % 255;

        ::LEDControl.setCrgbAt(i, hsvToRgb(key_hue, saturation, value));
      }
    }

  private:
    uint16_t max_hue = 255;
    byte saturation = 255;
    byte value = 200;
    uint32_t activate_millis = 0;
    uint16_t cycle_time = 10000;
} ledRainbowEffect;

static const char* emojiPstr(int emojiIndex) {
  switch(emojiIndex) {
    case E_A: return PSTR(":blobaww:");
    case E_E: return PSTR(":eyes:");
    case E_F: return PSTR(":facepalm:");
    case E_H: return PSTR(":purple_heart:");
    case E_J: return PSTR(":joy:");
    case E_L: return PSTR(":lololol:");
    case E_N: return PSTR(":noprobllama:");
    case E_PLUS: return PSTR(":wizard-thumb:");
    case E_S: return PSTR(":woman-shrugging:");
    case E_T: return PSTR(":thanks-2:");
    case E_U: return PSTR(":dancing_unicorn:");
    case E_W: return PSTR(":thunkface:");
    case E_Y: return PSTR(":this:");
  }
  return PSTR("");
}

static void slackReactMacro(int emojiIndex) {
  Macros.type(PSTR("+"));
  Macros.type(emojiPstr(emojiIndex));
  Macros.play(MACRO(T(Enter)));
}

static void typeEmojiMacro(int emojiIndex) {
  Macros.type(emojiPstr(emojiIndex));
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return MACRO_NONE;
  }
  if ((macroIndex & REACT) == REACT) {        // 11xxxxxx => Emoji Reaction
    slackReactMacro(macroIndex & (~REACT));
  } else if ((macroIndex & EMOJI) == EMOJI) { // 10xxxxxx => Emoji In-line
    typeEmojiMacro(macroIndex & (~EMOJI));
  } else {                                    // 0xxxxxxx => Other Macros
    switch(macroIndex) {
      case TOGGLE_QUINN:
        if (Layer.mostRecent() == L_FN) {
          Layer.move(QUINN);
          WavepoolEffect.activate();
        } else {
          Layer.move(PRIMARY);
          ledRainbowEffect.activate();
        }
        break;
    }
  }
  return MACRO_NONE;
}

static const int spaceCadetTimeout = 250;
static kaleidoscope::plugin::SpaceCadet::KeyBinding spaceCadetMap[] = {
  {Key_LeftShift,    Key_LeftParen,         spaceCadetTimeout},
  {Key_RightShift,   Key_RightParen,        spaceCadetTimeout},
  {Key_LeftGui,      Key_LeftCurlyBracket,  spaceCadetTimeout},
  {Key_RightGui,     Key_RightCurlyBracket, spaceCadetTimeout},
  {Key_LeftControl,  Key_LeftBracket,       spaceCadetTimeout},
  {Key_RightControl, Key_RightBracket,      spaceCadetTimeout},
  {Key_LeftAlt,      Key_Escape,            spaceCadetTimeout},
  SPACECADET_MAP_END
};

KALEIDOSCOPE_INIT_PLUGINS(
  SpaceCadet,
  Focus,
  LEDControl,
  LEDOff,
  ledRainbowEffect,
  WavepoolEffect,
  TopsyTurvy,
  Macros,
  EEPROMSettings,
  DynamicMacros
);

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.map = spaceCadetMap;
  WavepoolEffect.idle_timeout = 0;
  ledRainbowEffect.activate();
  DynamicMacros.reserve_storage(128);
}

void loop() {
  Kaleidoscope.loop();
}
