#include QMK_KEYBOARD_H
#include "audio.h"
#include "action_layer.h"
#include "config.h"
#include "custom_shift_keys.h"
#include "keycodes.h"
#include "quantum_keycodes.h"
#include "user_song_list.h"

enum planck_layers {
    _BASE,
    _NAV,
    _SYM,
    _ADJUST,
    _CP77,
    _CS2,
};
enum planck_keycodes {
    BASE = SAFE_RANGE,
    NAV,
    SYM,
    ADJUST,
};

#define CP77 TO(_CP77)
#define CS2 TO(_CS2)

float tone_startup[][2]    = SONG(STARTUP_SOUND);
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float cp_song[][2]    = SONG(CP2077_SOUND);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      /* Default Base Layer 0 to be _BASE */
    [_BASE] = LAYOUT_planck_2x2u(
          QK_GESC,  KC_Q,         KC_W,     KC_E,     KC_R,            KC_T,  KC_Y,    KC_U,     KC_I,     KC_O,          KC_P,     KC_BSPC,
          KC_LCTL,  KC_A,         KC_S,     KC_D,     KC_F,            KC_G,  KC_H,    KC_J,     KC_K,     KC_L,          KC_SCLN,  KC_QUOT,
          KC_LSFT,   KC_Z,         KC_X,     KC_C,     KC_V,            KC_B,  KC_N,    KC_M,     KC_COMM,  KC_DOT,        KC_SLSH, RSFT_T(KC_ENT) ,
          NAV,    LCA(KC_DEL),  KC_LGUI,  KC_LALT,  KC_TAB,                          KC_SPC,  KC_LEFT,  KC_DOWN,  KC_UP,    LT(_SYM,KC_RGHT)
    ),
      /* MO1 Nav, Numbers */
    [_NAV] = LAYOUT_planck_2x2u(
          KC_TRNS,  KC_1,         KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL,
          KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS,  KC_TRNS,
          KC_TRNS,  KC_TRNS,      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_BSLS,  KC_TRNS,
          NAV,  LCA(KC_DEL),  KC_LGUI,  KC_LALT,  KC_LSFT,                              KC_ENT,   KC_TRNS,  KC_TRNS,  KC_TRNS,   SYM
    ),
      /* MO2 Symbols, Numbers */
    [_SYM] = LAYOUT_planck_2x2u(
          KC_TRNS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_TRNS,
          KC_TRNS,  KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_PIPE,  KC_LT,    KC_GT,    KC_SLSH,  KC_MINS,  KC_LBRC,  KC_RBRC,  KC_TRNS,
          KC_TRNS,  KC_TRNS,  KC_DOT,   KC_PPLS,  KC_LPRN,  KC_SCLN,  KC_COLN,  KC_RPRN,  KC_PMNS,  KC_EQL,  KC_TRNS,  KC_TRNS,
          NAV,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LSFT,  KC_ENT,   KC_TRNS,  KC_TRNS,  KC_TRNS,   SYM
    ),
      /* Settings */
    [_ADJUST] = LAYOUT_planck_2x2u(
          _______, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL ,
          _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______, _______,   KC_NO,  _______,
          _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, CS2, CP77,  BASE,
          NAV,   KC_NO,  KC_NO,     KC_NO,  KC_NO,                     KC_NO,   KC_NO,  KC_NO,  KC_NO, SYM
     ),
      /* CyberPunk 2077 */
    [_CP77] = LAYOUT_planck_2x2u(
          KC_ESC,  KC_NO,    QK_GESC,  KC_2,  KC_3,    KC_4,  KC_5,   KC_6,   KC_NO,  KC_NO,  KC_NO,    BASE,
          KC_NO,   KC_G,     KC_B,     KC_Q,  KC_W,    KC_E,  KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,   KC_O,
          KC_NO,   KC_LCTL,  KC_Z,     KC_A,  KC_S,    KC_D,  KC_R,   KC_NO,  KC_NO,  KC_NO, KC_TRNS, KC_TRNS,
          NAV,     KC_LSFT,  KC_NO,    KC_X,  KC_SPC,                         KC_C,   KC_NO,  KC_NO,  KC_NO, SYM
     ),
    [_CS2] = LAYOUT_planck_2x2u(
      /* CS2 */
          KC_ESC,  KC_NO,    QK_GESC,  KC_NO, KC_1,  KC_2,    KC_3,  KC_4,    KC_NO,  KC_NO,  KC_NO,  BASE,
          KC_NO,   KC_G,     KC_B,     KC_Q,  KC_W,    KC_E,  KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,
          KC_NO,   KC_LCTL,  KC_Z,     KC_A,  KC_S,    KC_D,  KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_TRNS,
          NAV,     KC_LSFT,  KC_NO,    KC_X,  KC_SPC,  KC_C,  KC_NO,  KC_NO,  KC_NO,   SYM
    )
};


const custom_shift_key_t custom_shift_keys[] = {
  {KC_LPRN ,  KC_RPRN}, // Shift ( is )
  {KC_LCBR ,  KC_RCBR}, // Shift { is }
  {KC_LBRC ,  KC_RBRC}, // Shift [ is ]
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        layer_move(_BASE);
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
      }
      break;
    case NAV:
      if (record->event.pressed) {
        layer_on(_NAV);
        update_tri_layer(_NAV, _SYM, _ADJUST);
      } else {
        layer_off(_NAV);
        update_tri_layer(_NAV, _SYM, _ADJUST);
      }
      break;
    case SYM:
      if (record->event.pressed) {
        layer_on(_SYM);
        update_tri_layer(_NAV, _SYM, _ADJUST);
      } else {
        layer_off(_SYM);
        update_tri_layer(_NAV, _SYM, _ADJUST);
      }
      break;
    case CS2:
      if (record->event.pressed) {
      }
      break;
    case CP77:
      if (record->event.pressed) {
        PLAY_SONG(cp_song);
      }
       return true;
    default:
      return true;
  }
  return true;
}


