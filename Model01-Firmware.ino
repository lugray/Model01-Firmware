// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-LED-Wavepool.h"
#include "Kaleidoscope-TopsyTurvy.h"
#include "Kaleidoscope-Ranges.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-DynamicMacros.h"
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope-Chord.h>
#include "macros.h"

enum { MACRO_NOP, QUINN, M_ESC, M_1, M_2, M_F, M_G, M_UP }; // Macros
#define KNOP M(MACRO_NOP)
#define STL(l) ShiftToLayer(L_ ## l)
#define MTL(l) MoveToLayer(L_ ## l)

enum { L_PRIMARY, L_FN, L_M, L_QUINN, L_QFN }; // layers

#define Sleep LCTRL(LGUI(Key_Q))
#define Mute Consumer_Mute
#define VolDown Consumer_VolumeDecrement
#define VolUp Consumer_VolumeIncrement
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
#define Pipe TOPSY(Backslash)
#define HYPER LGUI(LCTRL(LSHIFT(Key_LeftAlt)))
#define LParen Key_LeftParen
#define RParen Key_RightParen
#define LBrace TOPSY(LeftBracket)
#define RBrace TOPSY(RightBracket)
#define LBracket Key_LeftBracket
#define RBracket Key_RightBracket
#define LEDNext Key_LEDEffectNext
#define TabRight LCTRL(Key_Tab)
#define TabLeft LCTRL(LSHIFT(Key_Tab))
#define SpaceRight LCTRL(Right)
#define SpaceLeft LCTRL(Left)
#define AM(x) LALT(LSHIFT(Key_ ## x))
#define AM2(x) LCTRL(LALT(LSHIFT(Key_ ## x))
#define AM_MAKE_MAIN AM(Enter)
#define AM_NEXT AM(J)
#define AM_PREV AM(K)

constexpr Key KMod{kaleidoscope::ranges::SAFE_START};

KEYMAPS(
  [L_PRIMARY]=KEYMAP(
    Sleep,        Key_1,  Key_2,  Key_3,  Key_4,      Key_5,  AM_PREV,   AM_NEXT,    Key_6,  Key_7,     Key_8,     Key_9,      Key_0,         Key_Backslash,
    Key_Backtick, Key_Q,  Key_W,  Key_E,  Key_R,      Key_T,  SpaceLeft, SpaceRight, Key_Y,  Key_U,     Key_I,     Key_O,      Key_P,         Key_Equals,
    Key_Home,     Key_A,  Key_S,  Key_D,  Key_F,      Key_G,  /**/       /**/        Key_H,  Key_J,     Key_K,     Key_L,      Key_Colon, Key_Quote,
    Key_End,      Key_Z,  Key_X,  Key_C,  Key_V,      Key_B,  LAlt,      Underscore, Key_N,  Key_M,     Key_Comma, Key_Period, Key_Slash,     Key_Minus,
    /**/          /**/    /**/    LCtrl,  BkSpc,      LCmd,   LShift,    RShift,     RCmd,   SpcBar,    RCtrl,     /**/        /**/           /**/
    /**/          /**/    /**/    /**/    /**/        /**/    STL(FN),   STL(FN)     /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_FN]=KEYMAP(
    Key_NoKey,    Key_F1, Key_F2, Key_F3, Key_F4,     Key_F5, M(QUINN),  LEDNext,    Key_F6, Key_F7,    Key_F8,    Key_F9,     Key_F10,       Key_F11,
    ___,          ___,    ___,    ___,    ___,        ___,    TabLeft,   TabRight,   ___,    AM_NEXT,   AM_PREV,   ___,        ___,           Key_F12,
    Key_PageUp,   ___,    ___,    ___,    ___,        ___,    /**/       /**/        Left,   Down,      Up,        Right,      ___,           TOPSY(Quote),
    Key_PageDown, ___,    ___,    ___,    ___,        ___,    ___,       Key_Minus,  ___,    Mute,      VolDown,   VolUp,      Pipe,          STL(M),
    /**/          /**/    /**/    ___,    Key_Delete, ___,    ___,       ___,        ___,    Key_Enter, ___,       /**/        /**/           /**/
    /**/          /**/    /**/    /**/    /**/        /**/    ___,       ___,        /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_M]=KEYMAP(
    M(M_ESC),     M(M_1), M(M_2), ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    M(M_F),     M(M_G), /**/       /**/        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       ___,        KMod,          ___,
    /**/          /**/    /**/    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       /**/        /**/           /**/
    /**/          /**/    /**/    /**/    /**/        /**/    ___,       ___         /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_QUINN]=KEYMAP(
    KNOP,         KNOP,   KNOP,   KNOP,   KNOP,       KNOP,   KNOP,      KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,   KNOP,   KNOP,   KNOP,       KNOP,   KNOP,      KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,   KNOP,   KNOP,   KNOP,       KNOP,   /**/       /**/        KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,   KNOP,   KNOP,   KNOP,       KNOP,   KNOP,      KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    /**/          /**/    /**/    KNOP,   KNOP,       KNOP,   KNOP,      KNOP,       KNOP,   KNOP,      KNOP,      /**/        /**/           /**/
    /**/          /**/    /**/    /**/    /**/        /**/    STL(QFN),  STL(QFN)    /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_QFN]=KEYMAP(
    ___,          ___,    ___,    ___,    ___,        ___,    M(QUINN),  ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    ___,        ___,    /**/       /**/        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,    ___,    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       ___,        ___,           ___,
    /**/          /**/    /**/    ___,    ___,        ___,    ___,       ___,        ___,    ___,       ___,       /**/        /**/           /**/
    /**/          /**/    /**/    /**/    /**/        /**/    ___,       ___         /**/    /**/       /**/       /**/        /**/           /**/
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

bool isKModHeld() {
  for (Key key : kaleidoscope::live_keys.all()) {
    if (key == KMod) {
      return true;
    }
  }
  return false;
}

#define MAYBE_ENTER if (!isKModHeld()) { Macros.type(PSTR("\n")); } break;

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (!keyToggledOn(event.state)) {
    return MACRO_NONE;
  }
  switch(macro_id) {
    case QUINN:
      if (Layer.mostRecent() == L_FN) {
        Layer.move(L_QUINN);
        WavepoolEffect.activate();
      } else {
        Layer.move(L_PRIMARY);
        ledRainbowEffect.activate();
      }
      break;
    case M_ESC: MACRO_ESC; MAYBE_ENTER;
    case M_1: MACRO_1; MAYBE_ENTER;
    case M_2: MACRO_2; MAYBE_ENTER;
    case M_F: MACRO_F; MAYBE_ENTER;
    case M_G: MACRO_G; MAYBE_ENTER;
    case M_UP: Macros.type(PSTR("../")); break;
  }
  return MACRO_NONE;
}

KALEIDOSCOPE_INIT_PLUGINS(
  TopsyTurvy,
  Qukeys,
  Chord,
  LEDControl,
  LEDOff,
  ledRainbowEffect,
  WavepoolEffect,
  Macros,
  EEPROMSettings
);

void setup() {
  QUKEYS(
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 7), LBracket), // Left Thumb 0
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), LBrace),   // Left Thumb 2
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), LParen),   // Left Thumb 3

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), RParen),   // Right Thumb 3
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 8), RBrace),   // Right Thumb 2
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 8), RBracket), // Right Thumb 0
  )

  CHORDS(
    CHORD(Up, Right),           AM_MAKE_MAIN, // Fn + J + K = Fn + Enter

    CHORD(Key_J, Key_K),        Key_Escape,
    CHORD(Key_K, Key_L),        Key_Enter,
    CHORD(Key_D, Key_F),        Key_Tab,
    CHORD(Key_S, Key_D),        M(M_UP),
    CHORD(Key_S, Key_D, Key_F), LCTRL(RBracket),
    CHORD(BkSpc, SpcBar),       LALT(LShift), 
  )

  Kaleidoscope.setup();
  WavepoolEffect.idle_timeout = 0;
  ledRainbowEffect.activate();
  Chord.setTimeout(30);
}

void loop() {
  Kaleidoscope.loop();
}
