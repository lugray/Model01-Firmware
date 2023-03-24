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
#include "Kaleidoscope-TopsyTurvy.h"
#include "Kaleidoscope-Ranges.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-DynamicMacros.h"
#include <Kaleidoscope-Qukeys.h>
#include "macros.h"

#include "kaleidoscope/KeyAddr.h"               // for KeyAddr
#include "kaleidoscope/KeyEvent.h"              // for KeyEvent
#include "kaleidoscope/KeyEventTracker.h"       // for KeyEventTracker
#include "kaleidoscope/event_handler_result.h"  // for EventHandlerResult
#include "kaleidoscope/plugin.h"                // for Plugin

enum { MACRO_NOP, QUINN, M_ESC, M_1, M_2, M_O }; // Macros
#define KNOP M(MACRO_NOP)
#define STL(l) ShiftToLayer(L_ ## l)

enum { L_PRIMARY, L_FN, L_M, L_QUINN, L_QFN }; // layers

#define Sleep LCTRL(LGUI(Key_Q))
#define WinUp LCTRL(LALT(Key_UpArrow))
#define WinDown LCTRL(LALT(Key_DownArrow))
#define WinLeft LCTRL(LALT(Key_LeftArrow))
#define WinRight LCTRL(LALT(Key_RightArrow))
#define WinMax LCTRL(LALT(Key_Enter))
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
#define CSA(key) LCTRL(LSHIFT(LALT(Key_ ## key)))
#define HYPER LGUI(LCTRL(LSHIFT(Key_LeftAlt)))
#define LParen Key_LeftParen
#define RParen Key_RightParen
#define LBrace TOPSY(LeftBracket)
#define RBrace TOPSY(RightBracket)
#define LBracket Key_LeftBracket
#define RBracket Key_RightBracket

KEYMAPS(
  [L_PRIMARY]=KEYMAP(
    Key_Escape,   Key_1,   Key_2,  Key_3,    Key_4,      Key_5,  HYPER,    Sleep,      Key_6,  Key_7,     Key_8,     Key_9,      Key_0,         Key_Backslash,
    Key_Backtick, Key_Q,   Key_W,  Key_E,    Key_R,      Key_T,  Key_Tab,  Key_Enter,  Key_Y,  Key_U,     Key_I,     Key_O,      Key_P,         Key_Equals,
    Key_Home,     Key_A,   Key_S,  Key_D,    Key_F,      Key_G,  /**/      /**/        Key_H,  Key_J,     Key_K,     Key_L,      Key_Colon,     Key_Quote,
    Key_End,      Key_Z,   Key_X,  Key_C,    Key_V,      Key_B,  LAlt,     Underscore, Key_N,  Key_M,     Key_Comma, Key_Period, Key_Slash,     Key_Minus,
    /**/          /**/     /**/    LCtrl,    BkSpc,      LCmd,   LShift,   RShift,     RCmd,   SpcBar,    RCtrl,     /**/        /**/           /**/
    /**/          /**/     /**/    /**/      /**/        /**/    STL(FN),  STL(FN)     /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_FN]=KEYMAP(
    ___,          Key_F1,  Key_F2, Key_F3,   Key_F4,     Key_F5, M(QUINN), ___,        Key_F6, Key_F7,    Key_F8,    Key_F9,     Key_F10,       Key_F11,
    ___,          ___,     ___,    ___,      ___,        CSA(T), ___,      WinMax,     ___,    ___,       ___,       ___,        ___,           Key_F12,
    Key_PageUp,   WinLeft, CSA(S), WinRight, ___,        ___,    /**/      /**/        Left,   Down,      Up,        Right,      Key_Semicolon, TOPSY(Quote),
    Key_PageDown, ___,     ___,    CSA(C),   ___,        CSA(B), ___,      Key_Minus,  ___,    Mute,      VolDown,   VolUp,      Pipe,          STL(M),
    /**/          /**/     /**/    ___,      Key_Delete, ___,    ___,      ___,        ___,    Key_Enter, ___,       /**/        /**/           /**/
    /**/          /**/     /**/    /**/      /**/        /**/    ___,      ___         /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_M]=KEYMAP(
    M(M_ESC),     M(M_1),  M(M_2), ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       M(M_O),     ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    /**/      /**/        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       ___,        ___,           ___,
    /**/          /**/     /**/    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       /**/        /**/           /**/
    /**/          /**/     /**/    /**/      /**/        /**/    ___,      ___         /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_QUINN]=KEYMAP(
    KNOP,         KNOP,    KNOP,   KNOP,     KNOP,       KNOP,   KNOP,     KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,    KNOP,   KNOP,     KNOP,       KNOP,   KNOP,     KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,    KNOP,   KNOP,     KNOP,       KNOP,   /**/      /**/        KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    KNOP,         KNOP,    KNOP,   KNOP,     KNOP,       KNOP,   KNOP,     KNOP,       KNOP,   KNOP,      KNOP,      KNOP,       KNOP,          KNOP,
    /**/          /**/     /**/    KNOP,     KNOP,       KNOP,   KNOP,     KNOP,       KNOP,   KNOP,      KNOP,      /**/        /**/           /**/
    /**/          /**/     /**/    /**/      /**/        /**/    STL(QFN), STL(QFN)    /**/    /**/       /**/       /**/        /**/           /**/
  ),[L_QFN]=KEYMAP(
    ___,          ___,     ___,    ___,      ___,        ___,    M(QUINN), ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    /**/      /**/        ___,    ___,       ___,       ___,        ___,           ___,
    ___,          ___,     ___,    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       ___,        ___,           ___,
    /**/          /**/     /**/    ___,      ___,        ___,    ___,      ___,        ___,    ___,       ___,       /**/        /**/           /**/
    /**/          /**/     /**/    /**/      /**/        /**/    ___,      ___         /**/    /**/       /**/       /**/        /**/           /**/
  )
)
namespace kaleidoscope {
  namespace plugin {
    class Chord : public Plugin {
      public:
        uint16_t timeout = 50;
            
        EventHandlerResult onKeyswitchEvent(KeyEvent &event) {
          if (event_tracker_.shouldIgnore(event)) {
            return EventHandlerResult::OK;
          }

          if(event.key == Key_J || event.key == Key_K || event.key == Key_D || event.key == Key_F) {
            if(keyToggledOn(event.state) && !has_queued_event_()) {
              queued_event_ = event;
              start_time_ = Runtime.millisAtCycleStart();
              return EventHandlerResult::ABORT;
            } else if (keyToggledOn(event.state) && has_queued_event_() && queued_event_.key != event.key) {
              Key target_key = getChord(queued_event_.key, event.key);
              if(target_key != Key_NoKey) {
                KeyEvent new_event = KeyEvent(KeyAddr::none(), INJECTED | IS_PRESSED, target_key);
                Runtime.handleKeyEvent(new_event);
                new_event.state = INJECTED | WAS_PRESSED;
                Runtime.handleKeyEvent(new_event);
                queued_event_.key = Key_NoKey;
                return EventHandlerResult::ABORT;
              }
            }
          }

          if (has_queued_event_()) {
            sendQueuedEvent();
          }

          return EventHandlerResult::OK;
        }

        EventHandlerResult afterEachCycle() {
          if (Runtime.hasTimeExpired(start_time_, timeout) && has_queued_event_()) {
            sendQueuedEvent();
          }
          return EventHandlerResult::OK;
        }

        template<uint8_t _chords_size>
        void configure(Key const (&chords)[_chords_size]) {
          chords_ = chords;
          chords_size_ = _chords_size;
        }

      private:
        Key getChord(Key key1, Key key2) {
          if(key1 == Key_J && key2 == Key_K) {
            return Key_Escape;
          } else if(key1 == Key_K && key2 == Key_J) {
            return Key_Escape;
          } else if(key1 == Key_D && key2 == Key_F) {
            return LCTRL(Key_RightBracket);
          } else if(key1 == Key_F && key2 == Key_D) {
            return LCTRL(Key_RightBracket);
          } else {
            return Key_NoKey;
          }
        }
        void sendQueuedEvent() {
          KeyEventId stored_id = queued_event_.id();
          KeyEvent restored_event = KeyEvent(queued_event_.addr, queued_event_.state | INJECTED, queued_event_.key, stored_id);
          Runtime.handleKeyEvent(restored_event);
          queued_event_.key = Key_NoKey;
        }
        KeyEventTracker event_tracker_;
        KeyEvent queued_event_ = KeyEvent(KeyAddr::none(), INJECTED | IS_PRESSED, Key_NoKey);
        bool has_queued_event_() {
          return queued_event_.key != Key_NoKey;
        }
        uint16_t start_time_;
        Key const *chords_{nullptr};
        uint8_t chords_size_{0};
    };
  }
}
kaleidoscope::plugin::Chord Chord;

#define CHORDS(chord_defs...) {                        \
  static Key const chord_def[] PROGMEM = {chord_defs}; \
  Chord.configure(chord_def);                          \
}
#define CHORD(chord_keys...) chord_keys, Key_NoKey


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
    case M_ESC: MACRO_ESC;
    case M_1: MACRO_1;
    case M_2: MACRO_2;
    case M_O: MACRO_O;
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
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 7), LBracket),   // Left Thumb 0
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 7), LBrace),    // Left Thumb 2
    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 7), LParen),  // Left Thumb 3

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 8), RParen),  // Right Thumb 3
    kaleidoscope::plugin::Qukey(0, KeyAddr(2, 8), RBrace),    // Right Thumb 2
    kaleidoscope::plugin::Qukey(0, KeyAddr(0, 8), RBracket),   // Right Thumb 0

    kaleidoscope::plugin::Qukey(0, KeyAddr(3, 9), Key_Semicolon), // Right Palm
  )

  CHORDS(
    CHORD(Key_J, Key_K), Key_Escape,
    CHORD(Key_D, Key_F), LCTRL(Key_RightBracket),
  )

  Kaleidoscope.setup();
  WavepoolEffect.idle_timeout = 0;
  ledRainbowEffect.activate();
}

void loop() {
  Kaleidoscope.loop();
}
