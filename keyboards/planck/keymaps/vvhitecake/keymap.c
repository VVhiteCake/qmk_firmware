/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _DVORAK,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOVE
};

enum planck_keycodes {
  DVORAK = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  MOVE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  Ent |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Left | Right|Lower |Space | Bksp |Raise | Down |  Up  | GUI  | MOVE |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
  {KC_ESC,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH},
  {KC_TAB,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT },
  {KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC},
  {KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_DOWN, KC_UP,   KC_LGUI, TG(MOVE)}
},

/* Game
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   "  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  Ent |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | Left | Right|Lower |Space | Bksp |Raise | Down |  Up  | GUI  | MOVE |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC },
  {KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_DOWN, KC_UP,   KC_RGUI, TG(MOVE)}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   /  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |   |  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   _  |   +  |   {  |   }  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */ 
[_RAISE] = {
  {KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_SLSH},
  {_______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, KC_MINS,  KC_EQL ,  KC_LBRC, KC_RBRC, KC_PIPE},
  {_______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_UNDS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_BSLS},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT ,  KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Del |   6  |   7  |   8  |   9  |   0  |      |   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |      |   1  |   2  |   3  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |Pg Up |Pg Dn | Home | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV ,  KC_1  ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,   KC_6 ,   KC_7 ,   KC_8 ,  KC_9 ,   KC_0 , _______},
  {KC_DEL ,  KC_6  ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , _______,   KC_4 ,   KC_5 ,  KC_6 , _______, _______},
  {_______, KC_UNDO, KC_CUT , KC_COPY,KC_PASTE, _______, _______,   KC_1 ,   KC_2 ,  KC_3 , _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP,KC_PGDOWN, KC_HOME, KC_END}
  
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Dvorak| Game |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {_______, RESET,   DEBUG,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,  AG_SWAP,  DVORAK,  GAME  , _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}

/* Move
 * ,-----------------------------------------------------------------------------------.
 * |      |      | MsUp |      |      |Accel0|Accel1|Accel2|      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MsLt |MsDown| MsRt |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |      |      |      |  Up  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Btn 1 |Btn 2 |Btn 3 |      | Left | Down | Right|      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOVE] = {
  {_______, _______, KC_MS_U, _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, _______, _______},
  {_______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_UNDO, KC_CUT , KC_COPY,KC_PASTE, _______, _______, _______, _______, KC_UP  , _______, _______},
  {_______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, KC_LEFT, KC_DOWN, KG_RGHT, _______}
}

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        print("Dvorak\n");
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
      break;
      
    case GAME:
      if (record->event.pressed) {
        print("Game\n");
        set_single_persistent_default_layer(_GAME);
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
      
      case MOVE:
      if (record->event.pressed) {
        layer_on(_MOVE);
      } else {
        layer_off(_MOVE);
      }
      return false;
      break;
      
  }
  return true;
}
