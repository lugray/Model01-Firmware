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
enum { CYCLE_LED_MODE, TOGGLE_QUINN }; // Macros
enum { CYCLING_RAINBOW, STATIC_RAINBOW, OFF, LED_MODE_COUNT }; // LED Modes
enum { DM_ANY }; // Dynamic Macros
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;
#define E(n) M(n|EMOJI)
#define R(n) M(n|REACT)

enum { PRIMARY, L_FN, L_EMOJI, L_REACT, QUINN }; // layers

#define Key_Sleep LCTRL(LGUI(Key_Q))

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    ___,          Key_1, Key_2, Key_3,           Key_4,         Key_5,       M(TOGGLE_QUINN),
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_Home,     Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_End,      Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_LeftAlt,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         ShiftToLayer(L_FN),

    Key_Sleep,         Key_6,        Key_7,        Key_8,            Key_9,      Key_0,            ___,
    Key_Enter,         Key_Y,        Key_U,        Key_I,            Key_O,      Key_P,            Key_Equals,
    /**/               Key_H,        Key_J,        Key_K,            Key_L,      TOPSY(Semicolon), Key_Quote,
    TOPSY(Minus),      Key_N,        Key_M,        Key_Comma,        Key_Period, Key_Slash,        Key_Minus,
    Key_RightShift,    Key_RightGui, Key_Spacebar, Key_RightControl, /**/        /**/              /**/
    ShiftToLayer(L_FN) /**/          /**/          /**/              /**/        /**/              /**/

  ), [L_FN] = KEYMAP_STACKED (

    ___,          Key_F1,                     Key_F2,                     Key_F3,                      Key_F4,     Key_F5, Key_CapsLock,
    Key_Tab,      ___,                        LCTRL(LALT(Key_UpArrow)),   ___,                         ___,        ___,    ___,
    Key_PageUp,   LCTRL(LALT(Key_LeftArrow)), LCTRL(LALT(Key_DownArrow)), LCTRL(LALT(Key_RightArrow)), ___,        ___,    /**/
    Key_PageDown, Key_PrintScreen,            Key_Insert,                 ___,                         ___,        ___,    ___,
    /**/          /**/                        /**/                        ___,                         Key_Delete, ___,    ___,
    /**/          /**/                        /**/                        /**/                         /**/        /**/    ShiftToLayer(L_EMOJI),

    DM(DM_ANY),             Key_F6,        Key_F7,        Key_F8,                   Key_F9,                   Key_F10,       Key_F11,
    LCTRL(LALT(Key_Enter)), ___,           ___,           ___,                      ___,                      ___,           Key_F12,
    /**/                    Key_LeftArrow, Key_DownArrow, Key_UpArrow,              Key_RightArrow,           ___,           ___,
    ShiftToLayer(L_REACT),  ___,           Consumer_Mute, Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash, Key_Pipe,
    ___,                    ___,           Key_Enter,     ___,                      /**/                      /**/           /**/
    ShiftToLayer(L_EMOJI),  /**/           /**/           /**/                      /**/                      /**/           /**/

  ), [L_EMOJI] = KEYMAP_STACKED(

    ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, E(E_Q), E(E_W), E(E_E), E(E_R), E(E_T), ___,
    ___, E(E_A), E(E_S), E(E_D), E(E_F), E(E_G), /**/
    ___, E(E_Z), E(E_X), E(E_C), E(E_V), E(E_B), ___,
    /**/ /**/    /**/    ___,    ___,    ___,    ___,
    /**/ /**/    /**/    /**/    /**/    /**/    ShiftToLayer(L_REACT),

    ___,                  ___,    ___,    ___,    ___,    ___,    ___,
    ___,                  E(E_Y), E(E_U), E(E_I), E(E_O), E(E_P), E(E_PLUS),
    /**/                  E(E_H), E(E_J), E(E_K), E(E_L), ___,    ___,
    ___,                  E(E_N), E(E_M), ___,    ___,    ___,    ___,
    ___,                  ___,    ___,    ___,    /**/    /**/    /**/
    ShiftToLayer(L_REACT) /**/    /**/    /**/    /**/    /**/    /**/

  ), [L_REACT] = KEYMAP_STACKED(

    ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, R(E_Q), R(E_W), R(E_E), R(E_R), R(E_T), ___,
    ___, R(E_A), R(E_S), R(E_D), R(E_F), R(E_G), /**/
    ___, R(E_Z), R(E_X), R(E_C), R(E_V), R(E_B), ___,
    /**/ /**/    /**/    ___,    ___,    ___,    ___,
    /**/ /**/    /**/    /**/    /**/    /**/    ___,

    ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, R(E_Y), R(E_U), R(E_I), R(E_O), R(E_P), R(E_PLUS),
    /**/ R(E_H), R(E_J), R(E_K), R(E_L), ___,    ___,
    ___, R(E_N), R(E_M), ___,    ___,    ___,    ___,
    ___, ___,    ___,    ___,    /**/    /**/    /**/
    ___  /**/    /**/    /**/    /**/    /**/    /**/

  ), [QUINN] =  KEYMAP_STACKED(

    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, M(TOGGLE_QUINN),
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, /**/
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    /**/                       /**/                       /**/                       Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    /**/                       /**/                       /**/                       /**/                       /**/                       /**/                       Consumer_ChannelIncrement,

    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
     /**/                      Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement,
    Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, Consumer_ChannelIncrement, /**/                       /**/                       /**/
    Consumer_ChannelIncrement  /**/                       /**/                       /**/                       /**/                       /**/                       /**/

  )
)

#define TK(rv, cv) (r==rv && c == cv) ||

class : public kaleidoscope::plugin::LEDMode {
  public:
    void setValue(byte v) {
      rainbow_value = v;
    }

    void resetValue() {
      rainbow_value = default_value;
    }

    void cycle() {
      led_mode = (led_mode + 1) % LED_MODE_COUNT;
    }

  protected:
    void onActivate(void) {
      activate_millis = Kaleidoscope.millisAtCycleStart();
    }

    void update(void) {
      for (uint8_t i = 0; i < Kaleidoscope.device().led_count; i++) {
        uint8_t color_index = i / 4;
        if (i > 36) {
          color_index -= 2;
        } else if (i > 26) {
          color_index -= 1;
        }

        uint32_t delta = Kaleidoscope.millisAtCycleStart() - activate_millis;
        uint8_t rainbow_range = rainbow_end_hue - rainbow_start_hue;
        uint32_t offset = 0;
        if (led_mode == CYCLING_RAINBOW) {
          offset = rainbow_range * delta / cycle_time;
        }
        uint8_t key_hue = (rainbow_start_hue + offset + rainbow_range / 14 * color_index) % 255;

        byte value;
        if (delta > ramp_time) {
          value = rainbow_value;
        } else {
          value = rainbow_value * delta / ramp_time;
        }

        cRGB rainbow = hsvToRgb(key_hue, rainbow_saturation, value);
        if (led_mode == OFF) {
          rainbow = CRGB(0, 0, 0);
        }
        ::LEDControl.setCrgbAt(i, rainbow);
      }
    }

  private:
    uint16_t rainbow_start_hue = 0;  //  stores 0 to 614
    uint16_t rainbow_end_hue = 255;  //  stores 0 to 614

    byte rainbow_saturation = 255;
    byte default_value = 200;
    byte rainbow_value = default_value;
    uint32_t activate_millis = 0;
    uint16_t ramp_time = 1000;
    uint16_t cycle_time = 10000;
    byte led_mode = CYCLING_RAINBOW;

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
      case CYCLE_LED_MODE: ledRainbowEffect.cycle(); break;
      case TOGGLE_QUINN:
        if (Layer.mostRecent() == PRIMARY) {
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
