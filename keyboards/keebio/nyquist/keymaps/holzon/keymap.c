#include QMK_KEYBOARD_H

#include "quantum/keymap_extras/keymap_swedish.h"

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _ADJUST,
    _MOVE,
    _NUMPAD
};

// enum planck_keycodes {
//   LOWER = SAFE_RANGE,
//   RAISE
// };

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOVE MO(_MOVE)
#define NUMPAD MO(_NUMPAD)

// Tap Dance declarations
enum {
    TD_TAB_MOVE
};

// `finished` and `reset` functions for each tapdance keycode
void tab_move_finished(qk_tap_dance_state_t *state, void *user_data);
void tab_move_reset(qk_tap_dance_state_t *state, void *user_data);

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_TAB_MOVE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tab_move_finished, tab_move_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Func |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  `   | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  TD(TD_TAB_MOVE),        KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
  LCTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RCTL_T(KC_QUOT),
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  LCTL_T(KC_LBRACKET), KC_LGUI, KC_LALT, NUMPAD, LOWER,   KC_SPC,  KC_SPC, RAISE, KC_APPLICATION, KC_RALT, KC_RGUI, RCTL_T(KC_RBRACKET)
),

/* TD(TD_ESC_MOVE) */

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      | Mute |      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_TILD,  KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  KC_DEL, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE, _______, _______,
  KC_LEFT_PAREN, KC_LBRACKET, KC_LEFT_CURLY_BRACE, KC_LEFT_ANGLE_BRACKET, _______, _______, _______, _______, KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_CURLY_BRACE, KC_RBRACKET, KC_RIGHT_PAREN

),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   4  |   5  |   6  |   +  |  F5  |  F6  |   -  |   =  |   [  |   ]  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Enter |   7  |   8  |   9  |   -  |  F11 |  F12 |ISO # |ISO / | Mute |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ,  |   0  |  .   |Lower | Bksp | Bksp |Raise | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END, KC_PGUP, KC_PGDN, _______,
    KC_LEFT_PAREN, KC_LBRACKET, KC_LEFT_CURLY_BRACE, KC_LEFT_ANGLE_BRACKET, _______, _______, _______, _______, KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_CURLY_BRACE, KC_RBRACKET, KC_RIGHT_PAREN
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Taskmg|      |      |      |      |      |      |      |      |      |      |caltde|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | RESET|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
  TSKMGR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CALTDEL,
  KC_SYSTEM_SLEEP, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______,
  _______,  MUV_DE, MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  LGUI(KC_PAUS), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET
),

/* Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  Up  |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Caps |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_ortho_4x12(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_MOVE] = LAYOUT_ortho_4x12(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,  KC_F10, KC_F11,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, LCTL(LGUI(KC_LEFT)), _______, _______,  LCTL(LGUI(KC_RIGHT)), _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, SE_ARNG,  SE_ADIA, SE_ODIA, _______
),

[_NUMPAD] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_NUMLOCK, KC_KP_7,  KC_KP_8, KC_KP_9, KC_KP_MINUS,
    _______, _______, _______, _______, _______, _______, _______, KC_INSERT, KC_KP_4,  KC_KP_5, KC_KP_6, KC_KP_PLUS,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_1,  KC_KP_2, KC_KP_3, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_KP_0,  _______, KC_KP_DOT, _______
)

};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case LOWER:
//       if (record->event.pressed) {
//         layer_on(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_LOWER);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//     case RAISE:
//       if (record->event.pressed) {
//         layer_on(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       } else {
//         layer_off(_RAISE);
//         update_tri_layer(_LOWER, _RAISE, _ADJUST);
//       }
//       return false;
//       break;
//   }
//   return true;
// }

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  return state;
}

void matrix_init_user (void) {
  if (!(host_keyboard_leds() & (1<<USB_LED_NUM_LOCK))) {
      register_code(KC_NUMLOCK);
      unregister_code(KC_NUMLOCK);
  }
}

void tab_move_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (!state->pressed) {
    tap_code(KC_TAB);
  } else {
    layer_on(_MOVE);
  }
}

void tab_move_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (layer_state_is(_MOVE)) {
    layer_off(_MOVE);
  }
}
