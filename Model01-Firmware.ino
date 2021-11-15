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
enum { MACRO_NOP, TOGGLE_QUINN }; // Macros
enum { DM_ANY }; // Dynamic Macros
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;
#define E(k) M(E_ ## k|EMOJI)
#define R(k) M(E_ ## k|REACT)
#define KNOP M(MACRO_NOP)
#define STL(l) ShiftToLayer(L_ ## l)

enum { L_PRIMARY, L_FN, L_EMOJI, L_REACT, L_QUINN, L_QFN }; // layers

#define Sleep LCTRL(LGUI(Key_Q))
#define WinUp LCTRL(LALT(Key_UpArrow))
#define WinDown LCTRL(LALT(Key_DownArrow))
#define WinLeft LCTRL(LALT(Key_LeftArrow))
#define WinRight LCTRL(LALT(Key_RightArrow))
#define WinMax LCTRL(LALT(Key_Enter))
#define Mute Consumer_Mute
#define VolDown Consumer_VolumeDecrement
#define VolUp Consumer_VolumeIncrement
#define LEDNext Key_LEDEffectNext
#define LAlt Key_LeftAlt
#define LCtrl Key_LeftControl
#define RCtrl Key_RightControl
#define LCmd Key_LeftGui
#define RCmd Key_RightGui
#define LShift Key_LeftShift
#define RShift Key_RightShift
#define BkSpc Key_Backspace
#define SpcBar Key_Spacebar

KEYMAPS(
  [L_PRIMARY] = KEYMAP_STACKED(

    STL(REACT),   Key_1, Key_2, Key_3, Key_4, Key_5, LEDNext,
    Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
    Key_Home,     Key_A, Key_S, Key_D, Key_F, Key_G, /**/
    Key_End,      Key_Z, Key_X, Key_C, Key_V, Key_B, LAlt,
    /**/          /**/   /**/   LCtrl, BkSpc, LCmd,  LShift,
    /**/          /**/   /**/   /**/   /**/   /**/   STL(FN),

    Sleep,        Key_6, Key_7,  Key_8,     Key_9,      Key_0,            Key_Backslash,
    Key_Enter,    Key_Y, Key_U,  Key_I,     Key_O,      Key_P,            Key_Equals,
    /**/          Key_H, Key_J,  Key_K,     Key_L,      TOPSY(Semicolon), Key_Quote,
    TOPSY(Minus), Key_N, Key_M,  Key_Comma, Key_Period, Key_Slash,        Key_Minus,
    RShift,       RCmd,  SpcBar, RCtrl,     /**/        /**/              /**/
    STL(FN)       /**/   /**/    /**/       /**/        /**/              /**/

  ), [L_FN] = KEYMAP_STACKED (

    ___,          Key_F1,  Key_F2,  Key_F3,   Key_F4,     Key_F5, M(TOGGLE_QUINN),
    ___,          ___,     WinUp,   ___,      ___,        ___,    ___,
    Key_PageUp,   WinLeft, WinDown, WinRight, ___,        ___,    /**/
    Key_PageDown, ___,     ___,     ___,      ___,        ___,    ___,
    /**/          /**/     /**/     ___,      Key_Delete, ___,    ___,
    /**/          /**/     /**/     /**/      /**/        /**/    STL(EMOJI),

    DM(DM_ANY), Key_F6,        Key_F7,        Key_F8,      Key_F9,         Key_F10,       Key_F11,
    WinMax,     ___,           ___,           ___,         ___,            ___,           Key_F12,
    /**/        Key_LeftArrow, Key_DownArrow, Key_UpArrow, Key_RightArrow, Key_Semicolon, TOPSY(Quote),
    Key_Minus,  ___,           Mute,          VolDown,     VolUp,          TOPSY(Slash),  Key_Backslash,
    ___,        ___,           Key_Enter,     ___,         /**/            /**/           /**/
    STL(EMOJI), /**/           /**/           /**/         /**/            /**/           /**/

  ), [L_EMOJI] = KEYMAP(

    ___, ___,  ___,  ___,  ___,  ___,  ___, ___, ___,  ___,  ___,  ___,  ___,  ___,
    ___, E(Q), E(W), E(E), E(R), E(T), ___, ___, E(Y), E(U), E(I), E(O), E(P), E(PLUS),
    ___, E(A), E(S), E(D), E(F), E(G), /**/ /**/ E(H), E(J), E(K), E(L), ___,  ___,
    ___, E(Z), E(X), E(C), E(V), E(B), ___, ___, E(N), E(M), ___,  ___,  ___,  ___,
    /**/ /**/  /**/  ___,  ___,  ___,  ___, ___, ___,  ___,  ___,  /**/  /**/  /**/
    /**/ /**/  /**/  /**/  /**/  /**/  ___, ___  /**/  /**/  /**/  /**/  /**/  /**/

  ), [L_REACT] = KEYMAP(

    ___, ___,  ___,  ___,  ___,  ___,  ___, ___, ___,  ___,  ___,  ___,  ___,  ___,
    ___, R(Q), R(W), R(E), R(R), R(T), ___, ___, R(Y), R(U), R(I), R(O), R(P), R(PLUS),
    ___, R(A), R(S), R(D), R(F), R(G), /**/ /**/ R(H), R(J), R(K), R(L), ___,  ___,
    ___, R(Z), R(X), R(C), R(V), R(B), ___, ___, R(N), R(M), ___,  ___,  ___,  ___,
    /**/ /**/  /**/  ___,  ___,  ___,  ___, ___, ___,  ___,  ___,  /**/  /**/  /**/
    /**/ /**/  /**/  /**/  /**/  /**/  ___, ___  /**/  /**/  /**/  /**/  /**/  /**/

  ), [L_QUINN] =  KEYMAP(

    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,     KNOP,    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,
    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,     KNOP,    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,
    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP, /**/      /**/     KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,
    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,     KNOP,    KNOP, KNOP, KNOP, KNOP, KNOP, KNOP,
    /**/  /**/  /**/  KNOP, KNOP, KNOP, KNOP,     KNOP,    KNOP, KNOP, KNOP, /**/  /**/  /**/
    /**/  /**/  /**/  /**/  /**/  /**/  STL(QFN), STL(QFN) /**/  /**/  /**/  /**/  /**/  /**/

  ), [L_QFN] =  KEYMAP(

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
          Layer.move(L_QUINN);
          WavepoolEffect.activate();
        } else {
          Layer.move(L_PRIMARY);
          ledRainbowEffect.activate();
        }
        break;
    }
  }
  return MACRO_NONE;
}

static kaleidoscope::plugin::SpaceCadet::KeyBinding spaceCadetMap[] = {
  {Key_LeftShift,    Key_LeftParen},
  {Key_RightShift,   Key_RightParen},
  {Key_LeftGui,      Key_LeftCurlyBracket},
  {Key_RightGui,     Key_RightCurlyBracket},
  {Key_LeftControl,  Key_LeftBracket},
  {Key_RightControl, Key_RightBracket},
  {Key_LeftAlt,      Key_Escape},
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
  SpaceCadet.time_out = 250;
  SpaceCadet.map = spaceCadetMap;
  WavepoolEffect.idle_timeout = 0;
  ledRainbowEffect.activate();
  DynamicMacros.reserve_storage(128);
}

void loop() {
  Kaleidoscope.loop();
}
