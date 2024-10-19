#include QMK_KEYBOARD_H
#include <stdio.h>
#include "totem.h"

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                       │
// └─────────────────────────────────────────────────┘ 

enum layer_names {
    _APTv3,
    _QWERTY,
    _SYM,
    _MOUSE_FUN,
    _NUM_NAV,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘


// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   t a p - d a n c e                 │
// └─────────────────────────────────────────────────┘

enum tap_dances {
  TD_SPACE_DOT,
  TD_DOT_COMMA,
  TD_SLASH_BSLASH,
  TD_COLON_SEMICOLON,
  TD_QWERTY,
  TD_COMM_ENT,
  TD_P_ENT,
  TD_V_ENT,
  TD_M_ENT,
  TD_PLUS_MINUS,
  TD_MPLY_DIVIDE,
  TD_01,
  TD_02,
  TD_03,
  TD_04,
  TD_05,
  TD_06,
  TD_07,
  TD_08,
  TD_09,
  TD_10,
  TD_11,
  TD_12,
  TD_13,
  TD_14,
  TD_15,
  TD_16,
  TD_17,
  TD_18,
  TD_19,
  TD_20,
  TD_21,
  TD_22,
  TD_23,
  TD_24,
  TD_25,
  TD_26,
  TD_27,
  TD_28,
  TD_29,
  TD_30,
  TD_31,
  TD_32,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_SPACE_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_DOT),
    [TD_DOT_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
    [TD_SLASH_BSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BACKSLASH),
    [TD_COLON_SEMICOLON] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SEMICOLON),
    [TD_QWERTY] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ASTR, _QWERTY),
    [TD_COMM_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_ENT),
    [TD_P_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_ENT),
    [TD_V_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_V, KC_ENT),
    [TD_M_ENT] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_ENT),
    [TD_PLUS_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_PLUS, KC_MINS),
    [TD_MPLY_DIVIDE] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR, KC_SLSH),
    [TD_02] = ACTION_TAP_DANCE_DOUBLE(KC_G,KC_GRV),
    [TD_03] = ACTION_TAP_DANCE_DOUBLE(KC_D,KC_LT),
    [TD_04] = ACTION_TAP_DANCE_DOUBLE(KC_F,KC_GT),
    [TD_05] = ACTION_TAP_DANCE_DOUBLE(KC_B,KC_PLUS),
    [TD_06] = ACTION_TAP_DANCE_DOUBLE(KC_Q,KC_PERC),
    [TD_07] = ACTION_TAP_DANCE_DOUBLE(KC_L,KC_LBRC),
    [TD_08] = ACTION_TAP_DANCE_DOUBLE(KC_U,KC_RBRC),
    [TD_09] = ACTION_TAP_DANCE_DOUBLE(KC_O,KC_AT),
    [TD_10] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_Y, _QWERTY),
    [TD_15] = ACTION_TAP_DANCE_DOUBLE(KC_K,KC_MINS),
    [TD_16] = ACTION_TAP_DANCE_DOUBLE(KC_J,KC_PIPE),
    [TD_21] = ACTION_TAP_DANCE_DOUBLE(KC_COLON,KC_ESC),
    [TD_24] = ACTION_TAP_DANCE_DOUBLE(KC_M,KC_LPRN),
    [TD_25] = ACTION_TAP_DANCE_DOUBLE(KC_P,KC_RPRN),
    [TD_26] = ACTION_TAP_DANCE_DOUBLE(KC_V,KC_HASH),
    [TD_27] = ACTION_TAP_DANCE_DOUBLE(KC_Z,KC_AMPR),
    [TD_28] = ACTION_TAP_DANCE_DOUBLE(KC_COMM,KC_LCBR),
    [TD_29] = ACTION_TAP_DANCE_DOUBLE(KC_DOT,KC_RCBR),
    [TD_30] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE,KC_DQUO),
    [TD_31] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_CIRC),
    [TD_32] = ACTION_TAP_DANCE_DOUBLE(KC_ASTR,KC_TILD),
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// HOME ROW
#define HOME_R LALT_T(KC_R)

// ┌─────────────────────────────────────────────────┐
// │ c o m b o s                                     │
// └─────────────────────────────────────────────────┘
const uint16_t PROGMEM _3_4[] = {TD(TD_03), TD(TD_04), COMBO_END};
const uint16_t PROGMEM _24_25[] = {TD(TD_24), TD(TD_25), COMBO_END};
const uint16_t PROGMEM _7_8[] = {TD(TD_07), TD(TD_08), COMBO_END};
const uint16_t PROGMEM _28_29[] = {TD(TD_28), TD(TD_29), COMBO_END};
const uint16_t PROGMEM _21_32[] = {TD(TD_21), TD(TD_32), COMBO_END};
combo_t key_combos[] = {
    COMBO(_3_4, KC_DLR),
    COMBO(_24_25, KC_EXLM),
    COMBO(_7_8, KC_UNDS),
    COMBO(_28_29, KC_EQL),
    COMBO(_21_32, TG(_QWERTY)),
};
// ┌───────────────┐
// │ K E Y M A P S │
// └───────────────┘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
   ┌─────────────────────────────────────────────────┐
   │ A P T v 3                                       │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─1───────┬─2───────┬─3───────┬─4───────┬─5────╨──┐┌─6╨──────┬─7───────┬─8───────┬─9───────┬─10──────┐
     ╌┄┈┈───═╡    W    │    G    │    D    │    F    │    B    ││    Q    │    L    │    U    │    O    │    Y    │
             ├─11──────┼─12──────┼─13──────┼─14──────┼─15──────┤├─16──────┼─17──────┼─18──────┼─19──────┼─20──────┤
             │  ◆ R    │  ⌥ S    │  ⇧ T    │  ⎈ H    │    K    ││    J    │    N ⎈  │    E ⇧  │    A ⌥  │    I ◆  │
   ┌─21──────┼─22──────┼─23──────┼─24──────┼─25──────┼─26──────┤├─27──────┼─28──────┼─29──────┼─30──────┼─31──────┼─32──────┐
   │  : esc  │    X    │    C    │    M    │    P    │    V    ││    Z    │    .    │    ,    │    '    │    /    │    *    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   esc   │    ⇥    │    ␣    ││    ⌫    │    ↵    │    ⌦    │
                                 | mouse fn| num nav |   sym   ||   sym   | num nav | mouse fn|
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘
*/
   [_APTv3] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
                KC_W,     KC_G,     KC_D,     KC_F,     KC_B,       KC_Q,    KC_L,      KC_U,    KC_O,      KC_Y,  
          LGUI_T(KC_R),LALT_T(KC_S),LSFT_T(KC_T),LCTL_T(KC_H),KC_K,KC_J, LCTL_T(KC_N),RSFT_T(KC_E),LALT_T(KC_A),LGUI_T(KC_I),  
      TD(TD_21),   KC_X,    KC_C,     KC_M,     KC_P,     KC_V,       KC_Z,   KC_DOT,   KC_COMM,  KC_QUOTE, KC_SLSH, KC_ASTR,
    LT(_MOUSE_FUN,KC_ESC), LT(_NUM_NAV, KC_TAB), LT(_SYM, KC_SPC), LT(_SYM,KC_BSPC),LT(_NUM_NAV,KC_ENT), LT(_MOUSE_FUN,KC_DEL)
 ),
  /*   
   ┌─────────────────────────────────────────────────┐
   │ s y m  B E A K L 15                             │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │    <    │    $    │    >    │         ││         │    [    │    _    │    ]    │    @    │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤─────────┐
   │    -    │    \    │    (    │    "    │    )    │    #    ││    |    │    {    │    =    │    }    │    %    │    ;    │
   └─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┘
             │         │    `    │    !    │    +    │         ││         │    &    │    ^    │    ~    │         │
             └─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┘
                                 │         │         │         ││         │         │         │  
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */ 

   [_SYM] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,   KC_LT,   KC_DLR,     KC_GT,   _______,   _______,  KC_LBRC,  KC_UNDS,  KC_RBRC,   KC_AT,
              KC_BSLS,  KC_LPRN,   KC_DQUO,  KC_RPRN,  KC_HASH,   KC_PIPE,  KC_LCBR,   KC_EQL,  KC_RCBR,  KC_PERC,  
    KC_MINS,  _______,  KC_GRV,   KC_EXLM,   KC_PLUS,  _______,   _______,  KC_AMPR,   KC_CIRC,  KC_TILD, _______,  KC_SCLN,
                                   _______,  _______,  _______,   _______,  _______,   _______
 ),
 /*
   ┌─────────────────────────────────────────────────┐
   │ q w e r t y                                     │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │   
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  ◆ A    │  ⌥ S    │  ⇧ D    │  ⎈ F    │    G    ││    H    │   ⎈ J   │   ⇧ K   │   ⌥ L   │   ◆ ;   │    
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    :    │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    *    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   Esc   │   Tab   │  SPACE  ││  SPACE  │   BSPC  │   Del   │  
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/ 

   [_QWERTY] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
                 KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,      KC_U,     KC_I,     KC_O,  KC_P,  
       LGUI_T(KC_A),LALT_T(KC_S), LSFT_T(KC_D),LCTL_T(KC_F), KC_G, KC_H,  LCTL_T(KC_J),RSFT_T(KC_K),LALT_T(KC_L),  LGUI_T(KC_SCLN),    
KC_COLON,     KC_Z,     KC_X,     KC_C, TD(TD_V_ENT), KC_B,     KC_N,  TD(TD_M_ENT),KC_COMM,  KC_DOT, KC_SLSH, TD(TD_QWERTY),
    LT(_MOUSE_FUN,KC_ESC), LT(_NUM_NAV, KC_TAB), LT(_SYM, KC_SPC), LT(_SYM,KC_SPC),LT(_NUM_NAV,KC_BSPC), LT(_MOUSE_FUN,KC_DEL)
 ),
 /*   
   ┌─────────────────────────────────────────────────┐
   │ m o u s e  +  f u n                             │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    F9   │   F10   │   F11   │   F12   │         ││         │   WHLU  │    UP   │  WHLD   │         │   
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  ◆ F5   │  ⌥ F6   │  ⇧ F7   │  ⎈ F8   │  Vol +  ││ Pla/Pau │   LEFT  │   DOWN  │  RIGHT  │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │    F1   │    F2   │    F3   │    F4   │  Vol -  ││   MUTE  │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││  L_BTN  │  R_BTN  │  M_BTN  │  
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */ 

   [_MOUSE_FUN] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
               KC_F9,    KC_F10,    KC_F11,   KC_F12,  XXXXXXX,   _______,  MS_WHLU,   MS_UP,   MS_WHLD,  _______,
LGUI_T(KC_F5),LALT_T(KC_F6),LSFT_T(KC_F7),LCTL_T(KC_F8),   KC_VOLU,   KC_MPLY,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______, 
   XXXXXXX,    KC_F1,    KC_F2,     KC_F3,    KC_F4,   KC_VOLD,   KC_MUTE,  _______,  _______,  _______,  _______,  _______, 
                                   _______,  _______,  _______,   MS_BTN1,  MS_BTN2,  MS_BTN3
 ),
 /*   
   ┌─────────────────────────────────────────────────┐
   │ n u m  +  n a v                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │    7    │    8    │    9    │   + -   ││  PASTE  │   HOME  │    ↑    │   PGUP  │  SHIFT  │   
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │  ◆ 0    │  ⌥ 4    │  ⇧ 5    │  ⎈ 6    │   * /   ││   CUT   │    ←    │    ↓    │    →    │ CONTROL │   
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │    1    │    2    │    3    │   . ,   ││   COPY  │   END   │   UNDO  │   PGDN  │   INS   │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │  
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ */ 

   [_NUM_NAV] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,    KC_7,     KC_8,    KC_9,TD(TD_PLUS_MINUS),   KC_PSTE,  KC_HOME,  KC_UP,    KC_PGUP,  KC_LSFT,   
LGUI_T(KC_0),LALT_T(KC_4),LSFT_T(KC_5),LCTL_T(KC_6),TD(TD_MPLY_DIVIDE),KC_CUT,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_LCTL,
   XXXXXXX,   _______,    KC_1,     KC_2,      KC_3,TD(TD_DOT_COMMA),KC_COPY,  KC_END,   KC_UNDO,  KC_PGDN,  KC_INS,  XXXXXXX,
                               _______,     _______,  _______,   _______,  _______,  _______  
 ),
/*
   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │         │         │         │         ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │         │         │         │         │         ││         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 |         |         |         ||         |         |         |
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘ 

   [_TEMPLATE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,  
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______, _______,
                                  _______,  _______,   _______,  _______,  _______,  _______,
 ),
*/
};


// ┌────────────────────┐
// │ M A C R O S        │
// └────────────────────┘

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {

        // case OS_SWAP: 
        //     if (record->event.pressed) {
        //         if (!keymap_config.swap_lctl_lgui) {
        //           keymap_config.swap_lctl_lgui = true;  // ─── MAC
        //         }
        //         else {
        //           keymap_config.swap_lctl_lgui = false; // ─── WIN
        //         }
        //     eeconfig_update_keymap(keymap_config.raw);
        //     clear_keyboard();  // ──── clear to prevent stuck keys    
        //     return false;
        //   }


// ┌─────────────────────────────────────────────────┐
// │ l a y e r                                       │
// └─────────────────────────────────────────────────┘

        // case COLEMAK:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_COLEMAK);
        //     }
        //     return false;
        // case QWERTY:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_QWERTY);
        //     }
        //     return false;


// ┌─────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                         │
// └─────────────────────────────────────────────────┘

    //   case SNAP:
    //       if (record->event.pressed) {
    //         if (keymap_config.swap_lctl_lgui) {
    //           SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC           
    //         } else {
    //           SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
    //         }
    //       }
    //       break;
//     }
//     return true;
// }

// https://docs.qmk.fm/features/os_detection
// https://www.monotux.tech/posts/2024/05/qmk-os-detection/
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_IOS:
        case OS_MACOS:
            keymap_config.swap_lalt_lgui = true;
            keymap_config.swap_ralt_rgui = true;
            break;
        case OS_WINDOWS:
            break;
        case OS_LINUX:
            break;
        case OS_UNSURE:
            break;
    }
    return true;
}


