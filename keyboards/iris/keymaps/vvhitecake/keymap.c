#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _GAME 1
#define _LOWER 2
#define _RAISE 3
#define _MOVE 4
#define _ADJUST 16
//#define UNDO LCTL(KC_Z)
//#define CUT LCTL(KC_X)
//#define COPY LCTL(KC_C)
//#define PSTE LCTL(KC_V)

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  GAME,
  LOWER,
  RAISE,
  MOVE,
  ADJUST,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_MOVE MOVE
#define KC_GAME GAME
#define KC_RST RESET
#define KC_BL_S BL_STEP
#define KC_DVRK DVORAK
#define UNDO LCTL(KC_Z)
#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define FIND LCTL(KC_F)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,QUOT,COMM,DOT , P  , Y  ,                F  , G  , C  , R  , L  ,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , A  , O  , E  , U  , I  ,                D  , H  , T  , N  , S  ,ENT ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSPO,SCLN, Q  , J  , K  , X  ,                B  , M  , W  , V  , Z  ,RSPC,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,LALT,LGUI,LEFT,RGHT,    ,SPC ,     BSPC,    ,DOWN, UP ,LBRC,RBRC,MOVE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LOWR,SPC ,         BSPC,RASE,LSFT
  //                  `----+----+----'        `----+----+----'
  ),

    [_GAME] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,QUOT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,ENT ,
  //|----+----+----+----+----+----+              |----+----+----+----+----+----|
     LSPO, Z  , X  , C  , V  , B  ,               N  , M  ,COMM,DOT ,SLSH,RSPC,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LCTL,LALT,LGUI,LEFT,RGHT,    ,SPC ,     BSPC,    ,DOWN, UP ,LBRC,RBRC,MOVE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LOWR,SPC ,         BSPC,RASE,LSFT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD, 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DEL , 6  , 7  , 8  , 9  , 0  ,                   , 4  , 5  , 6  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,UNDO,CUT ,COPY,PASTE,FIND,                   , 1  , 2  , 3  ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    , 0  ,PGUP,PGDN,HOME,END ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,SLSH,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , F1 , F2 , F3 , F4 , F5 ,                F6 ,MINS,PLUS,LBRC,RBRC,PIPE,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         , F7 , F8 , F9 ,F10 ,F11 ,               F12 ,UNDS,EQL ,LCBR,RCBR,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,VOLD,VOLU,MPLY,MSTP,MUTE,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

    [_ADJUST] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,RST ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,DVRK,GAME,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

    [_MOVE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,MS_U,    ,    ,    ,               ACL0,ACL1,ACL2,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MS_L,MS_D,MS_R,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    , UP ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,    ,         ,    ,    ,LEFT,DOWN,RGHT,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       BTN1,BTN2,BTN3,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
      case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAME);
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
