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

enum { E_T, E_H, E_J, E_E, E_W, E_P, E_Y, E_G, E_M, E_F, E_PLUS }; // Emoji Keys
static const int EMOJI = 128;
static const int REACT = EMOJI | 64;
enum { RPN_TOGGLE }; // Non-emoji macros

enum { PRIMARY, NUMPAD, FUNCTION, BUTTERFLY, BUTTERFLY_FN, STOCK_QW, STOCK_FN }; // layers

#define Key_CalcRPN Key(kaleidoscope::ranges::SAFE_START + 1)

KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED(

    ___,          Key_1, Key_2, Key_3,           Key_4,         Key_5,       Key_LeftAlt,
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_Home,     Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_End,      Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_Escape,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         ShiftToLayer(FUNCTION),

    LCTRL(LSHIFT(LALT(LGUI(Key_S)))), Key_6,        Key_7,        Key_8,            Key_9,      Key_0,            LockLayer(NUMPAD),
    Key_Enter,                        Key_Y,        Key_U,        Key_I,            Key_O,      Key_P,            Key_Equals,
    /**/                              Key_H,        Key_J,        Key_K,            Key_L,      TOPSY(Semicolon), Key_Quote,
    ShiftToLayer(BUTTERFLY),          Key_N,        Key_M,        Key_Comma,        Key_Period, Key_Slash,        Key_Minus,
    Key_RightShift,                   Key_RightGui, Key_Spacebar, Key_RightControl, /**/        /**/              /**/
    ShiftToLayer(FUNCTION)            /**/          /**/          /**/              /**/        /**/              /**/

  ), [NUMPAD] = KEYMAP_STACKED(

    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, /**/
    ___, ___, ___, ___, ___, ___, ___,
    /**/ /**/ /**/ ___, ___, ___, ___,
    /**/ /**/ /**/ /**/ /**/ /**/ ___,

    ___, ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
    ___, ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
    /**/ ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,
    ___, ___, Key_0, Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
    ___, ___, ___,   ___,        /**/                /**/                /**/
    ___  /**/ /**/   /**/        /**/                /**/                /**/

  ), [FUNCTION] = KEYMAP_STACKED (

    ___,          Key_F1,                     Key_F2,                     Key_F3,                      Key_F4,     Key_F5, Key_CapsLock,
    Key_Tab,      ___,                        LCTRL(LALT(Key_UpArrow)),   ___,                         ___,        ___,    ___,
    Key_PageUp,   LCTRL(LALT(Key_LeftArrow)), LCTRL(LALT(Key_DownArrow)), LCTRL(LALT(Key_RightArrow)), ___,        ___,    /**/
    Key_PageDown, Key_PrintScreen,            Key_Insert,                 ___,                         ___,        ___,    Key_CalcRPN,
    /**/          /**/                        /**/                        ___,                         Key_Delete, ___,    ___,
    /**/          /**/                        /**/                        /**/                         /**/        /**/    ShiftToLayer(BUTTERFLY),

    Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,               Key_F8,                   Key_F9,                   Key_F10,          Key_F11,
    LCTRL(LALT(Key_Enter)),     Consumer_ScanNextTrack, Key_LeftCurlyBracket, Key_RightCurlyBracket,    Key_LeftBracket,          Key_RightBracket, Key_F12,
    /**/                        Key_LeftArrow,          Key_DownArrow,        Key_UpArrow,              Key_RightArrow,           ___,              ___,
    ShiftToLayer(BUTTERFLY_FN), ___,                    Consumer_Mute,        Consumer_VolumeDecrement, Consumer_VolumeIncrement, Key_Backslash,    Key_Pipe,
    ___,                        ___,                    Key_Enter,            ___,                      /**/                      /**/              /**/
    ShiftToLayer(BUTTERFLY),    /**/                    /**/                  /**/                      /**/                      /**/              /**/

  ), [BUTTERFLY] = KEYMAP_STACKED(

    ___, ___, ___,          ___,          ___,          ___,          ___,
    ___, ___, M(E_W|EMOJI), M(E_E|EMOJI), ___,          M(E_T|EMOJI), ___,
    ___, ___, ___,          ___,          M(E_F|EMOJI), M(E_G|EMOJI), /**/
    ___, ___, ___,          ___,          ___,          ___,          ___,
    /**/ /**/ /**/          ___,          ___,          ___,          ___,
    /**/ /**/ /**/          /**/          /**/          /**/          ShiftToLayer(BUTTERFLY_FN),

    ___,                       ___,          ___,          ___, ___, ___,          ___,
    ___,                       M(E_Y|EMOJI), ___,          ___, ___, M(E_P|EMOJI), M(E_PLUS|EMOJI),
    /**/                       M(E_H|EMOJI), M(E_J|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          M(E_M|EMOJI), ___, ___, ___,          ___,
    ___,                       ___,          ___,          ___, /**/ /**/          /**/
    ShiftToLayer(BUTTERFLY_FN) /**/          /**/          /**/ /**/ /**/          /**/

  ), [BUTTERFLY_FN] = KEYMAP_STACKED(

    ___, ___, ___,          ___,          ___,          ___,          ___,
    ___, ___, M(E_W|REACT), M(E_E|REACT), ___,          M(E_T|REACT), ___,
    ___, ___, ___,          ___,          M(E_F|REACT), M(E_G|REACT), /**/
    ___, ___, ___,          ___,          ___,          ___,          ___,
    /**/ /**/ /**/          ___,          ___,          ___,          ___,
    /**/ /**/ /**/          /**/          /**/          /**/          ___,

    ___, ___,          ___,          ___, ___, ___,          ___,
    ___, M(E_Y|REACT), ___,          ___, ___, M(E_P|REACT), M(E_PLUS|REACT),
    /**/ M(E_H|REACT), M(E_J|REACT), ___, ___, ___,          ___,
    ___, ___,          M(E_M|REACT), ___, ___, ___,          ___,
    ___, ___,          ___,          ___, /**/ /**/          /**/
    ___  /**/          /**/          /**/ /**/ /**/          /**/

  ), [STOCK_QW] = KEYMAP_STACKED(

    ___,          Key_1, Key_2, Key_3,           Key_4,         Key_5,       Key_LeftAlt,
    Key_Backtick, Key_Q, Key_W, Key_E,           Key_R,         Key_T,       Key_Tab,
    Key_PageUp,   Key_A, Key_S, Key_D,           Key_F,         Key_G,       /**/
    Key_PageDown, Key_Z, Key_X, Key_C,           Key_V,         Key_B,       Key_Escape,
    /**/          /**/   /**/   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
    /**/          /**/   /**/   /**/             /**/           /**/         ShiftToLayer(STOCK_FN),

    ___,                   Key_6,       Key_7,        Key_8,            Key_9,      Key_0,         LockLayer(NUMPAD),
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

static const int spaceCadetTimeout = 250;
static kaleidoscope::plugin::SpaceCadet::KeyBinding spaceCadetMap[] = {
  {Key_LeftShift,    Key_LeftParen,         spaceCadetTimeout},
  {Key_RightShift,   Key_RightParen,        spaceCadetTimeout},
  {Key_LeftGui,      Key_LeftCurlyBracket,  spaceCadetTimeout},
  {Key_RightGui,     Key_RightCurlyBracket, spaceCadetTimeout},
  {Key_RightAlt,     Key_RightCurlyBracket, spaceCadetTimeout},
  {Key_LeftControl,  Key_LeftBracket,       spaceCadetTimeout},
  {Key_RightControl, Key_RightBracket,      spaceCadetTimeout},
  {Key_LeftAlt,      LockLayer(STOCK_QW),   spaceCadetTimeout},
  SPACECADET_MAP_END
};

#define DIGIT(digit, key_state) \
  if (mapped_key == (Key_ ## digit)) { \
    if (keyToggledOn(key_state)) { \
      handleDigit(digit); \
    } \
    return EventHandlerResult::EVENT_CONSUMED; \
  }

#define CASETYPE(ch) \
  case ' ## ch ## ': \
    Macros.type(PSTR(" ## ch ## ")); \
    break;

namespace kaleidoscope {
  class CalcRPN: public kaleidoscope::Plugin {
    public:
      EventHandlerResult onKeyswitchEvent(Key &mapped_key, byte row, byte col, uint8_t key_state) {
        if (mapped_key == Key_CalcRPN) {
          if (keyToggledOn(key_state)) {
            toggle();
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if (!active) {
          return EventHandlerResult::OK;
        }
        if (mapped_key == Key_LeftShift || mapped_key == Key_RightShift) {
          is_shifted_ = keyIsPressed(key_state);
        }
        if (!is_shifted_) {
          DIGIT(0, key_state)
          DIGIT(1, key_state)
          DIGIT(2, key_state)
          DIGIT(3, key_state)
          DIGIT(4, key_state)
          DIGIT(5, key_state)
          DIGIT(6, key_state)
          DIGIT(7, key_state)
          DIGIT(8, key_state)
          DIGIT(9, key_state)
        }
        if ((mapped_key == Key_Equals && is_shifted_) || mapped_key == Key_KeypadAdd) {
          if (keyToggledOn(key_state)) {
            commit();
            if (s.count() >= 2) {
              int64_t a = s.pop();
              int64_t b = s.pop();
              s.push(b+a);
            }
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if ((mapped_key == Key_Minus && !is_shifted_) || mapped_key == Key_KeypadSubtract) {
          if (keyToggledOn(key_state)) {
            commit();
            if (s.count() >= 2) {
              int64_t a = s.pop();
              int64_t b = s.pop();
              s.push(b-a);
            }
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if ((mapped_key == Key_8 && is_shifted_) || mapped_key == Key_KeypadMultiply) {
          if (keyToggledOn(key_state)) {
            commit();
            if (s.count() >= 2) {
              int64_t a = s.pop();
              int64_t b = s.pop();
              s.push(b*a);
            }
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if ((mapped_key == Key_Slash && !is_shifted_) || mapped_key == Key_KeypadDivide) {
          if (keyToggledOn(key_state)) {
            commit();
            if (s.count() >= 2) {
              int64_t a = s.pop();
              int64_t b = s.pop();
              s.push(b/a);
            }
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if (mapped_key == Key_Enter) {
          if (keyToggledOn(key_state)) {
            commit();
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        if (mapped_key == Key_Equals && !is_shifted_) {
          if (keyToggledOn(key_state)) {
            commit();
            if (!s.isEmpty()) {
              output(s.pop());
            }
          }
          return EventHandlerResult::EVENT_CONSUMED;
        }
        return EventHandlerResult::OK;
      }

      void toggle() {
        active = !active;
        commit();
        if (!active && !s.isEmpty()) {
          output(s.pop());
        }
      }

    private:
      void handleDigit(int n) {
        current *= 10;
        current += n;
        in_progress = true;
      }

      void commit() {
        if (in_progress) {
          s.push(current);
          current = 0;
          in_progress = false;
        }
      }

      void output(int64_t n) {
        bool old_active = active;
        active = false;
        if (n < 0) {
          Macros.type(PSTR("-"));
          n = -n;
        }
        int64_t div = 1;
        while (div <= n) {
          div *= 10;
        }
        div /= 10;
        while (div > 0) {
          int d = (n / div) % 10;
          div /= 10;
          switch(d) {
            case 0:
              Macros.type(PSTR("0"));
              break;
            case 1:
              Macros.type(PSTR("1"));
              break;
            case 2:
              Macros.type(PSTR("2"));
              break;
            case 3:
              Macros.type(PSTR("3"));
              break;
            case 4:
              Macros.type(PSTR("4"));
              break;
            case 5:
              Macros.type(PSTR("5"));
              break;
            case 6:
              Macros.type(PSTR("6"));
              break;
            case 7:
              Macros.type(PSTR("7"));
              break;
            case 8:
              Macros.type(PSTR("8"));
              break;
            case 9:
              Macros.type(PSTR("9"));
              break;
          }
        }
        active = old_active;
      }

      bool active = false;
      bool is_shifted_ = false;
      bool in_progress = false;
      int64_t current = 0;
      StackArray <int64_t> s;
  };
}
kaleidoscope::CalcRPN CalcRPN;

static const char* emojiPstr(int emojiIndex) {
  switch(emojiIndex) {
  case E_PLUS:
    return PSTR("+1");
  case E_T:
    return PSTR("trollface");
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
  switch(macroIndex) {
    case RPN_TOGGLE:
      CalcRPN.toggle();
      break;
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
              LEDControl.setCrgbAt(r, c, blue);
            } else if (TK(3, 1) TK(2, 2) TK(2, 3) TK(2, 4) TK(3, 5) TK(3, 10) TK(2, 11) TK(2, 12) TK(2, 13) TK(3, 14) false) {
              LEDControl.setCrgbAt(r, c, red);
            } else {
              LEDControl.setCrgbAt(r, c, off);
            }
          } else {
            Key k = Layer.lookupOnActiveLayer(r, c);
            Key layer_key = Layer.getKey(layer, r, c);
            // r:0;c:0 is program, which we don't want to show as a layer key really.
            if ((k != layer_key) || (k == Key_NoKey) || (r == 0 && c == 0)) {
              LEDControl.setCrgbAt(r, c, off);
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
      rainbow_value = 180;
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

          uint8_t key_hue = (rainbow_start_hue + (rainbow_end_hue - rainbow_start_hue) / 14 * color_index) % 255;

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
    }

  private:
    uint16_t rainbow_start_hue = 0;  //  stores 0 to 614
    uint16_t rainbow_end_hue = 230;  //  stores 0 to 614

    byte rainbow_saturation = 255;
    byte rainbow_value = 180;
    uint32_t activate_millis = 0;
    uint16_t ramp_time = 1000;

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

        position = KeyboardHardware.getLedIndex(r, c);
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

kaleidoscope::FocusLedCommand FocusLedCommand;

KALEIDOSCOPE_INIT_PLUGINS(
  Focus,
  FocusLedCommand,
  LEDControl,
  ledRainbowStaticEffect,
  SpaceCadet,
  TopsyTurvy,
  CalcRPN,
  Macros
);

void setup() {
  Kaleidoscope.setup();
  ledRainbowStaticEffect.activate();
  SpaceCadet.map = spaceCadetMap;
}

void loop() {
  Kaleidoscope.loop();
}
