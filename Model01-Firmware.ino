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

enum { MACRO_NOP, TOGGLE_QUINN }; // Macros
enum { DM_A, DM_B, DM_C }; // Dynamic Macros
#define KNOP M(MACRO_NOP)
#define STL(l) ShiftToLayer(L_ ## l)

enum { L_PRIMARY, L_FN, L_DM, L_QUINN, L_QFN }; // layers

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
#define Up Key_UpArrow
#define Down Key_DownArrow
#define Left Key_LeftArrow
#define Right Key_RightArrow
#define Key_Colon TOPSY(Semicolon)
#define Underscore TOPSY(Minus)

KEYMAPS(
  [L_PRIMARY] = KEYMAP(

    Key_Escape,   Key_1, Key_2, Key_3, Key_4, Key_5, LEDNext, Sleep,      Key_6, Key_7,  Key_8,     Key_9,      Key_0,     Key_Backslash,
    Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab, Key_Enter,  Key_Y, Key_U,  Key_I,     Key_O,      Key_P,     Key_Equals,
    Key_Home,     Key_A, Key_S, Key_D, Key_F, Key_G, /**/     /**/        Key_H, Key_J,  Key_K,     Key_L,      Key_Colon, Key_Quote,
    Key_End,      Key_Z, Key_X, Key_C, Key_V, Key_B, LAlt,    Underscore, Key_N, Key_M,  Key_Comma, Key_Period, Key_Slash, Key_Minus,
    /**/          /**/   /**/   LCtrl, BkSpc, LCmd,  LShift,  RShift,     RCmd,  SpcBar, RCtrl,     /**/        /**/       /**/
    /**/          /**/   /**/   /**/   /**/   /**/   STL(FN), STL(FN)     /**/   /**/    /**/       /**/        /**/       /**/

  ), [L_FN] = KEYMAP(

    ___,          Key_F1,  Key_F2,  Key_F3,   Key_F4,     Key_F5, M(TOGGLE_QUINN), ___, Key_F6, Key_F7,    Key_F8,  Key_F9, Key_F10,       Key_F11,
    ___,          ___,     WinUp,   ___,      ___,        ___,    ___,             WinMax,     ___,    ___,       ___,     ___,    ___,           Key_F12,
    Key_PageUp,   WinLeft, WinDown, WinRight, ___,        ___,    /**/             /**/        Left,   Down,      Up,      Right,  Key_Semicolon, TOPSY(Quote),
    Key_PageDown, ___,     ___,     ___,      ___,        ___,    ___,             Key_Minus,  ___,    Mute,      VolDown, VolUp,  TOPSY(Slash),  STL(DM),
    /**/          /**/     /**/     ___,      Key_Delete, ___,    ___,             ___,        ___,    Key_Enter, ___,     /**/    /**/           /**/
    /**/          /**/     /**/     /**/      /**/        /**/    ___,      ___, /**/    /**/       /**/     /**/    /**/           /**/

  ), [L_DM] =  KEYMAP(

    DM(DM_A), DM(DM_B), DM(DM_C), ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___,      ___,      ___,      ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    ___,      ___,      ___,      ___, ___, ___, /**/ /**/ ___, ___, ___, ___, ___, ___,
    ___,      ___,      ___,      ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___,
    /**/      /**/      /**/      ___, ___, ___, ___, ___, ___, ___, ___, /**/ /**/ /**/
    /**/      /**/      /**/      /**/ /**/ /**/ ___, ___  /**/ /**/ /**/ /**/ /**/ /**/

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

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return MACRO_NONE;
  }
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
  DynamicMacros.reserve_storage(256);
}

void loop() {
  Kaleidoscope.loop();
}
