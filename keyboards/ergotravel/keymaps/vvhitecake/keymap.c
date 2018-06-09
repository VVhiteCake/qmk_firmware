#include "ergotravel.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_ADJT ADJUST
#define KC_RST RESET


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
     ESC ,QUOT,COMM,DOT ,  P ,  Y ,LBRC,      RBRC,  F ,  G ,  C ,  R ,  L ,SLSH,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     TAB ,  A ,  O ,  E ,  U ,  I ,MINS,      EQL ,  D ,  H ,  T ,  N ,  S ,ENT ,
  //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
     LSPO,  Z ,  X ,  C ,  V ,  B ,  A ,       SPC,  B ,  M ,  W ,  V ,  Z ,RSPC,
  //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
     LCTL,LALT,LEFT,RIGHT,LOWR,SPC,                BSPC, RASE, UP ,DOWN,RGUI,MOVE
  //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
       DEL ,  1 ,  2 ,  3 ,  4 ,  5 , A,           B,  6  , 7  , 8  , 9  , 0  ,DEL,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       TAB ,  6 ,  7 ,  8 ,  9 ,  0 , F6 ,         D,  Y  ,MINS, EQL,LBRC,RBRC,BSLS,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       LSFT, F7 , F8 , F9 , F10, F11, F12,       SPC,  N  , M ,COMM,DOT ,SLSH,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
       LCTL,LALT,LEFT,RIGHT,LOWR,SPC,                BSPC, RASE, UP ,DOWN,RGUI,MOVE
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
        GRV, 1  , 2  , 3  , 4  , 5  , A,          B,  6  , 7  , 8  , 9  , 0  ,BSPC,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       TAB , Q  , W  , E  , R  , T  , C ,         D,  Y  , U  , I  , O  , P  ,DEL ,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       LSFT, Z  , X  , C  , V  , B  , A,        SPC,  N  , M  ,COMM,DOT ,SLSH,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
       LCTL,LALT,LEFT,RIGHT,LOWR,SPC,                BSPC, RASE, UP ,DOWN,RGUI,MOVE
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
  ),

  [_ADJUST] = KC_KEYMAP(
    //,----+----+----+----+----+----+----.     ,----+----+----+----+----+----+----.
       ESC , F1 , F2 , F3 , F4 , F5 , F6,         F7,  F8, F9 ,F10 , F11, F12,BSPC,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       TAB , Q  , W  , E  , R  , T  , C ,         D,  Y  , U  , I  , O  , P  ,DEL ,
    //|----+----+----+----+----+----+----|     |----+----+----+----+----+----+----|
       LSFT, Z  , X  , C  , V  , B  , A,        SPC,  N  , M  ,COMM,DOT ,SLSH,ENT ,
    //|----+----+----+----+----+----+----.     .----+----+----+----+----+----+----|
       LCTL,LGUI,LALT,ADJT,LOWR,SPC,                 SPC, RASE,LEFT, UP ,DOWN,RIGHT
    //`----+----+----+--+-+----/----/               \----\----+----+----+----+----'
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
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
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
