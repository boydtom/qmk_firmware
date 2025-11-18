#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "audio.h"
#include "user_song_list.h"

enum planck_layers {
    _BASE,
    _NUM,
    _SYM,
    _NAV,
    _ADJUST,
    _CP77,
    _CS2,
};
enum planck_keycodes {
    BASE = SAFE_RANGE,
    NUM,
    SYM,
    NAV,
    ADJUST,
    CP77,
    CS2,
};

#define CTRL_LEFT  LCTL(KC_LEFT)
#define CTRL_RGHT  LCTL(KC_RIGHT)
#define CTRL_UP    LCTL(KC_UP)
#define CTRL_DOWN  LCTL(KC_DOWN)
#define NAVIGATE   MO(_NAVIGATE)
#define CT_GRVES  LCTL_T(QK_GRAVE_ESCAPE)

#ifdef AUDIO_ENABLE
float tone_startup[][2] = SONG(STARTUP_SOUND);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_goodbye[][2] = SONG(GOODBYE_SOUND);
float cp_song[85][2]     = SONG(CP2077_SOUND);
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

      /* Default Base Layer 0 to be _BASE */
    [_BASE] = LAYOUT_planck_grid(
        KC_TAB, KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,            KC_BSPC,
        CTL_T(KC_ESC), KC_A,  KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN,         KC_QUOT,
        KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,         KC_RSFT,
        NAV,     KC_NO, KC_LGUI, KC_LALT, NUM,     KC_SPC, KC_SPC, SYM,     KC_LEFT, KC_DOWN, KC_UP,    LT(NAV,KC_RGHT)
    ),
    [_NUM] = LAYOUT_planck_grid(
        KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_BSPC,
        KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_TRNS,
        KC_TRNS,  KC_MINUS, KC_EQUAL, KC_GRAVE, KC_BSLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,  KC_RBRC,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ENT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_SYM] = LAYOUT_planck_grid(
        KC_TRNS,  KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_BSPC,
        KC_TRNS,  S(KC_1),  S(KC_2),  S(KC_3),  S(KC_4),  S(KC_5),  S(KC_6),  S(KC_7),  S(KC_8),  S(KC_9),  S(KC_0),  KC_TRNS,
        KC_TRNS,  KC_UNDS,  KC_PLUS,  KC_TILDE, KC_PIPE,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ENT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_NAV] = LAYOUT_planck_grid(
        KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
        KC_TRNS,  CTRL_LEFT, CTRL_DOWN,CTRL_UP,  CTRL_RGHT,KC_TRNS,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS, KC_NO,
        KC_TRNS,  KC_MPRV,   KC_MUTE,  KC_MPLY,  KC_MNXT,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_DEL, KC_NO,
        KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
    ),
    [_ADJUST] = LAYOUT_planck_grid(
        KC_TRNS, QK_BOOT, DB_TOGG, UG_TOGG, UG_NEXT, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_SPDU, UG_SPDD, KC_DEL,
        KC_TRNS, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_TRNS,
        KC_TRNS, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_TRNS, KC_TRNS, CS2,     CP77,    KC_NO,
        KC_TRNS,     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_SPC, KC_ENT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS
    ),
    [_CP77] = LAYOUT_planck_grid(
        KC_ESC, QK_GESC, KC_1,    KC_2,    KC_B,    KC_3, KC_4,   KC_5,  KC_4,  KC_5,  KC_6,    BASE,
        KC_M,   KC_P,    KC_G,    KC_TAB,  KC_Q,    KC_W, KC_E,   KC_R,  KC_NO, KC_NO, KC_NO,   KC_NO,
        KC_O,   KC_K,    KC_T,    KC_RSFT, KC_A,    KC_S, KC_D,   KC_F,  KC_V,  KC_NO, CP77, KC_NO,
                NAV,     KC_LCTL, KC_X,    KC_RCTL, KC_Y, KC_SPC, KC_ENT, KC_SPC, KC_NO, KC_NO, KC_NO, SYM
    ),
      /* CS2 */
    [_CS2] = LAYOUT_planck_grid(
        KC_ESC, KC_NO,   QK_GESC, KC_NO, KC_1, KC_2,   KC_3, KC_4,  KC_NO, KC_NO, KC_NO, BASE,
        KC_NO,  KC_G,    KC_B,    KC_Q,  KC_W, KC_E,   KC_R, KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,
        KC_NO,  KC_LCTL, KC_Z,    KC_A,  KC_S, KC_D,   KC_F, KC_G,  KC_H,  KC_J,  KC_K,  KC_TRNS,
                NAV,     KC_LSFT, KC_NO, KC_X, KC_SPC, KC_SPC, KC_ENT,KC_C, KC_NO, KC_NO, KC_NO, SYM
    )
};


/*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 * switch (keycode) {
 *   case BASE:
 *     if (record->event.pressed) {
 *       layer_move(_BASE);
 *       #ifdef AUDIO_ENABLE
 *         PLAY_SONG(tone_qwerty);
 *       #endif
 *     }
 *     break;
 *   case NAV:
 *     if (record->event.pressed) {
 *       layer_on(_NAV);
 *       update_tri_layer(_NAV, _SYM, _ADJUST);
 *     } else {
 *       layer_off(_NAV);
 *       update_tri_layer(_NAV, _SYM, _ADJUST);
 *     }
 *     break;
 *   case SYM:
 *     if (record->event.pressed) {
 *       layer_on(_SYM);
 *       update_tri_layer(_NAV, _SYM, _ADJUST);
 *     } else {
 *       layer_off(_SYM);
 *       update_tri_layer(_NAV, _SYM, _ADJUST);
 *     }
 *     break;
 *   default:
 *     return true;
 * }
 * return true;
 *}
 *
 *
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE:
            if (record->event.pressed) {
             #ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(tone_qwerty);
             #endif
              layer_move(_BASE);
            }
            return false;
            break;
        case NUM:
            if (record->event.pressed) {
                layer_on(_NUM);
                update_tri_layer(_NUM, _SYM, _ADJUST);
            } else {
                layer_off(_NUM);
                update_tri_layer(_NUM, _SYM, _ADJUST);
            }
            return false;
            break;
        case SYM:
            if (record->event.pressed) {
                layer_on(_SYM);
                update_tri_layer(_NUM, _SYM, _ADJUST);
            } else {
                layer_off(_SYM);
                update_tri_layer(_NUM, _SYM, _ADJUST);
            }
            return false;
            break;
        case CS2:
            if (record->event.pressed) {
                layer_move(_CS2);
            }
            return false;
            break;
        case CP77:
            if (record->event.pressed) {
                layer_move(_CP77);
            }
            return false;
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _BASE:
            rgblight_setrgb(0xFF, 0x00, 0x00);
            break;
        case _CP77:
            rgblight_setrgb(0x00, 0xFF, 0x00);
            break;
        case _CS2:
            rgblight_setrgb(0x7A, 0x00, 0xFF);
            break;
        default: //  for any other layers, or the default layer
            rgblight_setrgb(0x00, 0xFF, 0xFF);
            break;
    }
    return state;
}

