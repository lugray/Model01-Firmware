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
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-TopsyTurvy.h"
#include "Kaleidoscope-Ranges.h"
#include "StackArray.h"

enum { E_A, E_C, E_E, E_F, E_G, E_H, E_I, E_J, E_L, E_M, E_P, E_PLUS, E_S, E_T, E_U, E_W, E_Y }; // Emoji Keys
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;
#define E(n) Key(n|EMOJI, KEY_FLAGS | SYNTHETIC | IS_MACRO)
#define R(n) Key(n|REACT, KEY_FLAGS | SYNTHETIC | IS_MACRO)

enum { PRIMARY, L_FN, L_EMOJI, L_REACT, STOCK_QW, STOCK_FN }; // layers

#define Key_Sleep LCTRL(LSHIFT(LALT(LGUI(Key_S))))

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    ___,          Key_1, Key_2, Key_3,           Key_4,         Key_5,       ___,
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_Home,     Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_End,      Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_LeftAlt,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         ShiftToLayer(L_FN),

    Key_Sleep,         Key_6,        Key_7,        Key_8,            Key_9,      Key_0,            LockLayer(STOCK_QW),
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

    ___,                    Key_F6,        Key_F7,        Key_F8,                   Key_F9,                   Key_F10,       Key_F11,
    LCTRL(LALT(Key_Enter)), ___,           ___,           ___,                      ___,                      ___,           Key_F12,
    /**/                    Key_LeftArrow, Key_DownArrow, Key_UpArrow,              Key_RightArrow,           ___,           ___,
    ShiftToLayer(L_REACT),  ___,           Consumer_Mute, Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash, Key_Pipe,
    ___,                    ___,           Key_Enter,     ___,                      /**/                      /**/           /**/
    ShiftToLayer(L_EMOJI),  /**/           /**/           /**/                      /**/                      /**/           /**/

  ), [L_EMOJI] = KEYMAP_STACKED(

    ___, ___, ___,    ___,    ___,    ___,    ___,
    ___, ___, E(E_W), E(E_E), ___,    E(E_T), ___,
    ___, E(E_A), E(E_S), ___,    E(E_F), E(E_G), /**/
    ___, ___, ___,    E(E_C), ___,    ___,    ___,
    /**/ /**/ /**/    ___,    ___,    ___,    ___,
    /**/ /**/ /**/    /**/    /**/    /**/    ShiftToLayer(L_REACT),

    ___,                  ___,    ___,    ___,    ___,    ___,    ___,
    ___,                  E(E_Y), E(E_U), E(E_I), ___,    E(E_P), E(E_PLUS),
    /**/                  E(E_H), E(E_J), ___,    E(E_L), ___,    ___,
    ___,                  ___,    E(E_M), ___,    ___,    ___,    ___,
    ___,                  ___,    ___,    ___,    /**/    /**/    /**/
    ShiftToLayer(L_REACT) /**/    /**/    /**/    /**/    /**/    /**/

  ), [L_REACT] = KEYMAP_STACKED(

    ___, ___, ___,    ___,    ___,    ___,    ___,
    ___, ___, R(E_W), R(E_E), ___,    R(E_T), ___,
    ___, R(E_A), R(E_S), ___,    R(E_F), R(E_G), /**/
    ___, ___, ___,    R(E_C), ___,    ___,    ___,
    /**/ /**/ /**/    ___,    ___,    ___,    ___,
    /**/ /**/ /**/    /**/    /**/    /**/    ___,

    ___, ___,    ___,    ___,    ___,    ___,    ___,
    ___, R(E_Y), R(E_U), R(E_I), ___,    R(E_P), R(E_PLUS),
    /**/ R(E_H), R(E_J), ___,    R(E_L), ___,    ___,
    ___, ___,    R(E_M), ___,    ___,    ___,    ___,
    ___, ___,    ___,    ___,    /**/    /**/    /**/
    ___  /**/    /**/    /**/    /**/    /**/    /**/

  ), [STOCK_QW] = KEYMAP_STACKED(

    ___,          Key_1, Key_2, Key_3,           Key_4,         Key_5,       Key_LeftAlt,
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_PageUp,   Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_PageDown, Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_Escape,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         ShiftToLayer(STOCK_FN),

    ___,                   Key_6,       Key_7,        Key_8,            Key_9,      Key_0,         ___,
    Key_Enter,             Key_Y,       Key_U,        Key_I,            Key_O,      Key_P,         Key_Equals,
    /**/                   Key_H,       Key_J,        Key_K,            Key_L,      Key_Semicolon, Key_Quote,
    Key_RightAlt,          Key_N,       Key_M,        Key_Comma,        Key_Period, Key_Slash,     Key_Minus,
    Key_RightShift,        Key_RightAlt, Key_Spacebar, Key_RightControl, /**/        /**/           /**/
    ShiftToLayer(STOCK_FN) /**/         /**/          /**/              /**/        /**/           /**/

  ), [STOCK_FN] =  KEYMAP_STACKED(

    ___,      Key_F1,          Key_F2,     Key_F3, Key_F4,     Key_F5, Key_CapsLock,
    Key_Tab,  ___,             ___,        ___,    ___,        ___,    ___,
    Key_Home, ___,             ___,        ___,    ___,        ___,    /**/
    Key_End,  Key_PrintScreen, Key_Insert, ___,    ___,        ___,    ___,
    /**/      /**/             /**/        ___,    Key_Delete, ___,    ___,
    /**/      /**/             /**/        /**/    /**/        /**/    ___,

    Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
    Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
     /**/                       Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
    Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
    ___,                        ___,                    Key_Enter,                ___,                      /**/             /**/              /**/
    ___                         /**/                    /**/                      /**/                      /**/             /**/              /**/

  )
)


static const char* emojiPstr(int emojiIndex) {
  switch(emojiIndex) {
    case E_A: return PSTR("blobaww");
    case E_C: return PSTR("claps");
    case E_E: return PSTR("eyes");
    case E_F: return PSTR("picard2");
    case E_G: return PSTR("galaxy");
    case E_H: return PSTR("purple_heart");
    case E_I: return PSTR("incredulous_angry_woman");
    case E_J: return PSTR("joy");
    case E_L: return PSTR("iamlooking");
    case E_M: return PSTR("thanks-2");
    case E_P: return PSTR("point_up");
    case E_PLUS: return PSTR("wizard-thumb");
    case E_S: return PSTR("shrug");
    case E_T: return PSTR("trollface");
    case E_U: return PSTR("dancing_unicorn");
    case E_W: return PSTR("blobwave");
    case E_Y: return PSTR("tada");
  }
  return PSTR("");
}

static void slackReactMacro(int emojiIndex, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.play(MACRO(D(LeftGui), D(LeftShift), T(Backslash), U(LeftShift), U(LeftGui)));
    Macros.play(MACRO(W(255)));
    Macros.type(emojiPstr(emojiIndex));
    Macros.play(MACRO(W(255), T(Enter)));
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

cRGB overrideColors[LED_COUNT];
bool overrideColor[LED_COUNT];

#define TK(rv, cv) (r==rv && c == cv) ||

class : public kaleidoscope::plugin::LEDMode {
  public:
    kaleidoscope::EventHandlerResult afterEachCycle() {
      // partially-borrowed from
      //  - https://github.com/bjc/Kaleidoscope-LayerHighlighter
      //  - https://github.com/burke/dotfiles/blob/master/Documents/Arduino/Model01-Firmware/firmware.ino
      uint8_t layer = Layer.top();
      if (layer == PRIMARY) {
        return kaleidoscope::EventHandlerResult::OK;
      }
      cRGB off = CRGB(0, 0, 0);
      cRGB blue = CRGB(0, 0, 255);
      cRGB red = CRGB(255, 0, 0);
      for (uint8_t r = 0; r < ROWS; r++) {
        for (uint8_t c = 0; c < COLS; c++) {
          if (Layer.isActive(STOCK_QW)) {
            if (TK(0, 2) TK(0, 4) TK(0, 11) TK(0, 13) false) {
              LEDControl.setCrgbAt(KeyAddr(r, c), blue);
            } else if (TK(3, 1) TK(2, 2) TK(2, 3) TK(2, 4) TK(3, 5) TK(3, 10) TK(2, 11) TK(2, 12) TK(2, 13) TK(3, 14) false) {
              LEDControl.setCrgbAt(KeyAddr(r, c), red);
            } else {
              LEDControl.setCrgbAt(KeyAddr(r, c), off);
            }
          } else {
            Key k = Layer.lookupOnActiveLayer(KeyAddr(r, c));
            Key layer_key = Layer.getKey(layer, KeyAddr(r, c));
            // r:0;c:0 is program, which we don't want to show as a layer key really.
            if ((k != layer_key) || (k == Key_NoKey) || (r == 0 && c == 0)) {
              LEDControl.setCrgbAt(KeyAddr(KeyAddr(r, c)), off);
            }
          }
        }
      }
      return kaleidoscope::EventHandlerResult::OK;
    }
    void setValue(byte v) {
      rainbow_value = v;
    }

    void resetValue() {
      rainbow_value = default_value;
    }

  protected:
    void onActivate(void) {
      activate_millis = Kaleidoscope.millisAtCycleStart();
    }

    void update(void) {
      for (uint8_t i = 0; i < LED_COUNT; i++) {
        if (overrideColor[i]) {
          ::LEDControl.setCrgbAt(i, overrideColors[i]);
        } else {
          uint8_t color_index = i / 4;
          if (i > 36) {
            color_index -= 2;
          } else if (i > 26) {
            color_index -= 1;
          }

          uint32_t delta = Kaleidoscope.millisAtCycleStart() - activate_millis;
          uint8_t rainbow_range = rainbow_end_hue - rainbow_start_hue;
          uint8_t key_hue = (rainbow_start_hue + rainbow_range * delta / cycle_time + rainbow_range / 14 * color_index) % 255;

          byte value;
          if (delta > ramp_time) {
            value = rainbow_value;
          } else {
            if (KeyboardHardware.isKeyswitchPressed(R0C6)) { // LED
              default_value = 80;
              rainbow_value = 80;
            }
            value = rainbow_value * delta / ramp_time;
          }

          cRGB rainbow = hsvToRgb(key_hue, rainbow_saturation, value);
          ::LEDControl.setCrgbAt(i, rainbow);
        }
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

} ledRainbowStaticEffect;

namespace kaleidoscope {
  class FocusLedCommand : public Plugin {
   public:
    FocusLedCommand() {}

    EventHandlerResult onFocusEvent(const char *command) {
      if (strcmp_P(command, PSTR("led.set")) == 0) {
        uint8_t position;
        cRGB color;

        Focus.read(position);
        Focus.read(color);

        overrideColors[position] = color;
        overrideColor[position] = true;

        ::Focus.send(F("Set led"), position, F("to"), color);
        return EventHandlerResult::EVENT_CONSUMED;
      } else if (strcmp_P(command, PSTR("led.setrc")) == 0) {
        uint8_t position;
        byte r;
        byte c;
        cRGB color;

        Focus.read(r);
        Focus.read(c);
        Focus.read(color);

        position = KeyboardHardware.getLedIndex(KeyAddr(r, c));
        overrideColors[position] = color;
        overrideColor[position] = true;

        ::Focus.send(F("Set led"), position, F("to"), color);
        return EventHandlerResult::EVENT_CONSUMED;
      } else if (strcmp_P(command, PSTR("led.value")) == 0) {
        byte value;

        Focus.read(value);

        ledRainbowStaticEffect.setValue(value);

        ::Focus.send(F("Set base led value to"), value);
        return EventHandlerResult::EVENT_CONSUMED;
       } else if (strcmp_P(command, PSTR("led.unset")) == 0) {
        uint8_t position;

        Focus.read(position);

        overrideColor[position] = false;

        ::Focus.send(F("Unset led"), position);
        return EventHandlerResult::EVENT_CONSUMED;
      } else if (strcmp_P(command, PSTR("led.unset-all")) == 0) {
        for (uint8_t i = 0; i < LED_COUNT; i++) {
          overrideColor[i] = false;
        }
        ledRainbowStaticEffect.resetValue();

        ::Focus.send(F("Unset all leds"));
        return EventHandlerResult::EVENT_CONSUMED;
      }
      return EventHandlerResult::OK;
    }
  };
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

kaleidoscope::FocusLedCommand FocusLedCommand;

KALEIDOSCOPE_INIT_PLUGINS(
  SpaceCadet,
  Focus,
  FocusLedCommand,
  LEDControl,
  ledRainbowStaticEffect,
  TopsyTurvy,
  Macros
);

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.map = spaceCadetMap;
  ledRainbowStaticEffect.activate();
}

void loop() {
  Kaleidoscope.loop();
}
