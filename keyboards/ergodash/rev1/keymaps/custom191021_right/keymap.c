#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU LALT(KC_GRV)
#define KC_LOWR LT(_LOWER, KC_MHEN)    // タップで無変換     ホールドでLower
#define KC_RASE LT(_RAISE, KC_HENK)    // タップで変換       ホールドでRaise

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* 読み替え
  * Raise/Lower: fn
  * GUI: command
  * ALT: option
  * Ctrl: control
  * EISU: windows???
  */
  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0   |  `  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  | Bksp |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |      |                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |   `  |  Alt |  GUI | Ctrl |||||||| Lower| Space |      ||||||||     | Enter| Raise|||||||| GUI  |   [  |   ]  | Raise|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LBRC,                        KC_RBRC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_BSPC,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                         KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, \
    KC_GRV,  KC_LALT, KC_LGUI, KC_LCTL,          KC_LOWR, KC_SPC,  XXXXXXX,      XXXXXXX, KC_ENT,  RAISE,            KC_LGUI, KC_LBRC, KC_RBRC, RAISE  \
  ),


    /* Lower
     * ,----------------------------------------------------------------------------------------------------------------------.
     * |  Esc |   !  |   @  |   #  |   $  |   %  |  _   |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |  Esc |   !  |   @  |   #  |   $  |   %  |  _   |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
     * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
     * |   ~  |   F1 |   F2 |   F3 |   F4 |   F5 |   {  |                    |   }  | Left | Down |  Up  | Right|   :  |  "   |
     * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
     * | Shift|   F6 |   F7 |   F8 |   F9 |  F10 | Space|                    | Enter|      | Mute |VolDwn|VolUp |   ?  | Shift|
     * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
     * | Ctrl |  F11 |  F12 | EISU |||||||| Lower| Space|Delete|||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
     * ,----------------------------------------------------------------------------------------------------------------------.
     */
  [_LOWER] = LAYOUT(
    KC_ESC,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, KC_UNDS,          KC_PLUS, KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_LPRN,   KC_RPRN, KC_PIPE,
    KC_ESC,  KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC, KC_UNDS,          KC_PLUS, KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_LPRN,   KC_RPRN, KC_PIPE,
    KC_TILD, KC_F1,   KC_F2,  KC_F3,   KC_F4,  KC_F5,   KC_LCBR,          KC_RCBR, KC_LEFT,  KC_DOWN,  KC_UP,       KC_RGHT,   KC_COLN, KC_DQT,
    KC_LSFT, KC_F6,   KC_F7,  KC_F8,   KC_F9,  KC_F10,  KC_SPC,           KC_ENT,  XXXXXXX,  KC__MUTE, KC__VOLDOWN, KC__VOLUP, KC_QUES, KC_RSFT,
    KC_LCTL, KC_F11,  KC_F12, EISU,    LOWER,  KC_SPC,  KC_DEL,           KC_BSPC, KC_ENT,   RAISE,    KC_HOME,     KC_PGDN,   KC_PGUP, KC_END
  ),


  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |  !   |   @  |  #   |  $   |  %   |  `   |                    |  +   |   ^  |  &   |  *   |  (   |  )   |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Esc |  !   |   @  |  #   |  $   |  %   |  `   |                    |  +   |   ^  |  &   |  *   |  (   |  )   |  `   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   1  |   2  |   3  |   4  |  5   |  =   |                    | Bksp |      |      |  Up  |  [   |  ]   |  "   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |  7   |   8  |   9  |  0   |      |                    |      |      | Left | Down |Right |  ?   |Shift |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   | Alt  |  GUI | Ctrl |      |Lower |Space |                    | Enter| Raise|      | Home |PageDn|PageUp| End  |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_ESC , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD,          KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_ESC , KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TILD,          KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV, \
    KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_EQL,           KC_BSPC, XXXXXXX, XXXXXXX, KC_UP,   KC_LBRC, KC_RBRC, KC_DQT, \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_SPC,           XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUES, KC_RSFT, \
    KC_GRV,  KC_LALT, KC_LGUI, KC_LCTL, KC_LOWR, KC_SPC,  XXXXXXX,          XXXXXXX, KC_ENT , RAISE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),


  /* Raise
   * ,------------------------------------------------------------------------------------------------------------.
   * | ESC  |     |  7  |  8  |  9  |  +  |   (   |              |      |      |      |      |      |      |      |
   * |------+-----+-----+-----+-----+-----+-------+---------------------+------+------+------+------+------+------|
   * | Tab  |     |  4  |  5  |  6  |  -  |   )   |              |      |      |      |      |  [   |   ]  |      |
   * |------+-----+-----+-----+-----+-----+-------+---------------------+------+------+------+------+------+------|
   * | Ctrl |     |  1  |  2  |  3  |  /  |  Bksp |              | Bksp | Left | Down |  Up  | Right|      |      |
   * |------+-----+-----+-----+-----+-----+-------+---------------------+------+------+------+------+------+------|
   * | Shift|     |  0  |  .  |  =  |  *  |       |              |      |      | Left | Down | Right|      | Shift|
   * |------+-----+-----+-----+-----+-----+-------+------+------+-------+------+------+------+------+------+------|
   * |  `   | Alt | GUI | Ctrl||||||||Lower| Space|      |||||||| Enter| Raise||||||||  Home |PageDn|PageUp|  End |
   * ,------------------------------------------------------------------------------------------------------------.
  [_RAISE] = LAYOUT(
    KC_ESC,  XXXXXXX, KC_7, KC_8,   KC_9,   KC_PLUS, KC_LPRN,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  \
    KC_TAB,  XXXXXXX, KC_4, KC_5,   KC_6,   KC_MINS, KC_RPRN,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, \
    KC_LCTL, XXXXXXX, KC_1, KC_2,   KC_3,   KC_SLSH, KC_BSPC,                        KC_BSPC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX, \
    KC_LSFT, XXXXXXX, KC_0, KC_DOT, KC_EQL, KC_ASTR, KC_SPC,                          KC_ENT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, KC_RSFT, \
    KC_GRV, KC_LALT, KC_LGUI, KC_LCTL,       KC_LOWR, KC_SPC, XXXXXXX,        XXXXXXX, KC_ENT , RAISE,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),
   */


  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      | BL ON|  BRTG|  INC|   DEC|      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
