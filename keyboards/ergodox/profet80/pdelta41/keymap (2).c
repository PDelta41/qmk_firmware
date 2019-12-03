#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define NUMB 1 // Numeric
#define USTN 2 // MicroStation
#define MDIA 3 // Media
#define MNCF 4 // MineCraft
#define DVRK 5 // Dvorak
#define CLMC 6 // Colemac
#define SPRC 7 // Programming
#define SPRD 8 // Dwarven
#define WGWG 9 // WigWag

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 *   ,------------------------------------------------.           ,-------------------------------------------------.
 *   | Esc  |   1  |   2  |   3  |   4  |   5  |VOLDN |           | VOLUP|   6  |   7  |   8  |   9  |   0  |  BkSP |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+-------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           | PgUp |   Y  |   U  |   I  |   O  |   P  |   \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '   |
 * |--------+------+------+------+------+------| MUTE |           | PgDn |------+------+------+------+------+-------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RS/Ent|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+-------'
 *   |LCtrl|  Win  | LAlt |  F1  |  F2  |                                       | Space|   [  |   ]  |   -  |  Del |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F8  |       |  F12 |  Up  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |  F3  |  F6  |  F9  |       | Right| Down | Left |
 *                                 |------|------|------|       |------|------|------|
 *                                 |  F4  |  F7  |  F10 |       | Home |  F11 | End  |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox_80(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   KC_VOLD,
        KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,   KC_T,   TO(1),
        KC_CLCK,        KC_A,         KC_S,     KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,   KC_B,   KC_MUTE,
        KC_LCTL,        KC_LWIN,      KC_LALT,  KC_F1, KC_F2,
											           KC_F5,   KC_F8,
                                               KC_F3,  KC_F6,   KC_F7,
                                               KC_F4,  KC_F7,   KC_F9,
        // right hand
             KC_VOLU,     KC_6,   KC_7,    KC_8,      KC_9,      KC_0,        KC_BSPC,
             KC_PGUP,     KC_Y,   KC_U,    KC_I,      KC_O,      KC_P,        KC_BSLS,
                          KC_H,   KC_J,    KC_K,      KC_L,      KC_SCLN,     KC_QUOT,
             KC_PGDN,     KC_N,   KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,     KC_SFTENT,
                                  KC_SPC,  KC_LBRC,   KC_RBRC,   KC_MINS,     KC_DEL,
             KC_F12,     KC_UP,
             KC_LEFT,   KC_DOWN,   KC_RIGHT,
             KC_HOME,    KC_F11,    KC_END
    ),


/* Keymap 1: Numeric
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  A   |  B   |  C   |  D   |  E   |  F   |           |      |      |NumLck|   /  |   *  |      | BckSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   !  |      |  Up  |   (  |   )  |  L2  |           |      |   Up |   7  |   8  |   9  |   -  |    =   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock|      | Left | Down | Right|   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|  L0  |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |      |   .  |KP Ent|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NUMERIC
[NUMB] = LAYOUT_ergodox_80(
       // left hand
       KC_TRNS,   KC_A,  KC_B,  KC_C,  KC_D,  KC_E,  KC_F,
       KC_TRNS, KC_TRNS, KC_TRNS,  KC_UP, KC_LPRN, KC_RPRN, TO(2),
       KC_TAB, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_GRV,
       KC_CLCK, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,TO(0),
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS,   KC_NLCK, KC_PSLS, KC_PAST,   KC_TRNS, KC_BSPC,
       KC_TRNS, KC_UP,   KC_P7,   KC_P8,    KC_P9,    KC_PMNS, KC_PEQL,
                KC_DOWN, KC_P4,   KC_P5,    KC_P6,    KC_PPLS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_P1,   KC_P2,    KC_P3,    KC_BSLS, KC_TRNS,
                         KC_P0,   KC_DOT,  KC_PDOT,   KC_PENT,  KC_DEL,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: MicroStation
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ESC  |  Q   |  W   |  E   |  R   |  T   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   TAB  |PullBx|  7   |  8   |  9   |  (   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |CapsLock| Pole |  4   |  5   |  6   |  )   |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |      |  1   |  2   |  3   |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MicroStation
[USTN] = LAYOUT_ergodox_80(
       KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, TO(0),
       KC_TAB, KC_M(0), KC_P7, KC_P8, KC_P9, KC_TRNS, TO(3),
       KC_CAPS, KC_M(0), KC_P4, KC_P5, KC_P6, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P6, KC_TRNS, TO(1),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),


/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, TO(4),
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(2),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 4: MineCraft
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |  3   |  4   |   5  |Layer0|           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   Q  |  W   |  E   |   R  |Layer |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  5   |           |      |------+------+------+------+------+--------|
 * |        |      |   A  |  S   |  D   |   F  |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|Layer |           |      |------+------+------+------+------+--------|
 * |        |LShift|   Z  |  X   |  C   |   V  |  3   |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MINECRAFT
[MNCF] = LAYOUT_ergodox_80(
       KC_ESC,  KC_1,    KC_2, KC_3, KC_4, KC_5, TO(0),
       KC_TRNS, KC_TRNS, KC_Q, KC_W, KC_E, KC_R, TO(5),
       KC_TRNS, KC_TRNS, KC_A, KC_S, KC_D, KC_F,
       KC_TRNS, KC_TRNS, KC_Z, KC_X, KC_C, KC_V, TO(3),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_LSFT,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 5: Dvorak
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   | BckSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | " '  |  <   |  >   |  P   |  Y   |      |           |      |  F   |  G   |  C   |  R   |  L   |  / ?   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  A   |  O   |  E   |  U   |  I   |------|           |------|  D   |  H   |  T   |  N   |  S   |  - _   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  :   |  Q   |  J   |  K   |  X   |      |           |      |  B   |  M   |  W   |  V   |  Z   | RS/Ent |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | Win  | Alt  |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |          |
 *                                 `--------------------'       `------------------------'
 */
// Dvorak
[DVRK] = LAYOUT_ergodox_80(
       KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, TO(0),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_P, KC_Y, TO(6),
       KC_TRNS, KC_A, KC_O, KC_E, KC_U, KC_I,
       KC_TRNS, KC_TRNS, KC_Q, KC_J, KC_K, KC_X, TO(4),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 6: Colemac
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |      |           |      |  6   |  7   |  8   |  9   |  0   | BckSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  Q   |  W   |  F   |  P   |  G   |      |           |      |  J   |  L   |  U   |  Y   |  ;   |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  A   |  R   |  S   |  T   |  D   |------|           |------|  H   |  N   |  E   |  I   |  O   |   "    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  V   |  B   |      |           |      |  K   |  M   |  ,   |  .   |  /   |RS/Enter|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// Colemac
[CLMC] = LAYOUT_ergodox_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, TO(7),
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(5),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 7: Programming
 *
 *   ,------------------------------------------------.           ,-------------------------------------------------.
 *   | Esc  |   1  |   2  |   3  |   4  |   5  |  L0  |           | RESET|   6  |   7  |   8  |   9  |   0  |  BkSP |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+-------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L8  |           | PgUp |   Y  |   U  |   I  |   O  |   P  |   \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+-------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '   |
 * |--------+------+------+------+------+------|  L9  |           | PgDn |------+------+------+------+------+-------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RS/Ent|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+-------'
 *   |LCtrl|  Win  | LAlt |  F1  |  F2  |                                       | Space|   [  |   ]  |   -  |  Del |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |  F8  |       |  F12 |  Up  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |  F3  |  F6  |  F9  |       | Right| Down | Left |
 *                                 |------|------|------|       |------|------|------|
 *                                 |  F4  |Insert|  F10 |       | Home |  F11 | End  |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox_80(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   TO(0),
        KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,   KC_T,   TO(8),
        KC_CLCK,        KC_A,         KC_S,     KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,   KC_B,   TO(6),
        KC_LCTL,        KC_LWIN,      KC_LALT,  KC_F1, KC_F2,
											           KC_F5,   KC_F8,
                                               KC_F3,  KC_F6,   KC_F7,
                                               KC_F4,  KC_F7,   KC_F9,
        // right hand
             RESET,     KC_6,   KC_7,    KC_8,      KC_9,      KC_0,        KC_BSPC,
             KC_PGUP,     KC_Y,   KC_U,    KC_I,      KC_O,      KC_P,        KC_BSLS,
                          KC_H,   KC_J,    KC_K,      KC_L,      KC_SCLN,     KC_QUOT,
             KC_PGDN,     KC_N,   KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,     KC_SFTENT,
                                  KC_SPC,  KC_LBRC,   KC_RBRC,   KC_MINS,     KC_DEL,
             KC_F12,     KC_UP,
             KC_LEFT,   KC_DOWN,   KC_RIGHT,
             KC_HOME,    KC_F11,    KC_END

),

/* Keymap 8: Spare D
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MEDIA AND MOUSE
[SPRD] = LAYOUT_ergodox_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, TO(9),
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(7),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),

/* Keymap 9: WigWag
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+----------.
 *                                 |      |      |      |       |      |      |          |
 *                                 |------|------|------|       |------|------|----------|
 *                                 |      |      |      |       |      |      |BrwserBack|
 *                                 `--------------------'       `------------------------'
 */
// MEDIA AND MOUSE
[WGWG] = LAYOUT_ergodox_80(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, TO(8),
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(8),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           RGB_MOD, RGB_M_B,
								  RGB_TOG, RGB_RMOD, KC_TRNS,
                                  KC_TRNS, RGB_M_T, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),



};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_left_led_1_off();	 
	ergodox_left_led_2_off();
	
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_2_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            break;
        case 3:
            ergodox_left_led_1_on();
            break;			
        case 4:
            ergodox_left_led_2_on();
            break;			
        case 5:
			ergodox_right_led_2_on();	
			ergodox_right_led_3_on();
            break;
        case 6:
			ergodox_right_led_2_on();	
			ergodox_left_led_1_on();
            break;	
        case 7:
			ergodox_right_led_2_on();	
			ergodox_left_led_2_on();
            break;
        case 8:
			ergodox_right_led_3_on();
			ergodox_left_led_1_on();
            break;
        case 9:
			ergodox_right_led_3_on();
 			ergodox_left_led_1_on();
			ergodox_left_led_2_on();
			ergodox_left_led_3_on();			
			_delay_ms(50);
			ergodox_right_led_3_off();
			_delay_ms(50);
 			ergodox_right_led_1_on();
			_delay_ms(50);
			ergodox_right_led_1_off();
			_delay_ms(50);
			ergodox_right_led_3_on();
			_delay_ms(50);
			ergodox_right_led_3_off();
			_delay_ms(50);
 			ergodox_right_led_1_on();
			_delay_ms(50);
			ergodox_right_led_1_off();
			_delay_ms(50);			
 			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
			ergodox_right_led_3_on();			
			_delay_ms(50);	
			ergodox_right_led_1_off();
			ergodox_right_led_2_off();
			ergodox_right_led_3_off();
			_delay_ms(50);			
 			ergodox_right_led_1_on();
			ergodox_right_led_2_on();
			ergodox_right_led_3_on();			
			_delay_ms(50);
 			ergodox_left_led_1_off();
			ergodox_left_led_2_off();
			ergodox_left_led_3_off();
			ergodox_right_led_1_off();
			ergodox_right_led_2_off();
			ergodox_right_led_3_off();
			_delay_ms(250);


        default:
            // none
            break;
    }
};
// Runs constantly in the background, in a loop.
void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
		ergodox_right_led_1_on();		
		ergodox_left_led_3_on();		
		_delay_ms(100);
		ergodox_right_led_1_off();
		ergodox_left_led_3_off();																										
		_delay_ms(100);
		ergodox_right_led_1_on();
		ergodox_left_led_3_on();
		_delay_ms(100);
		ergodox_right_led_1_off();
		ergodox_left_led_3_off();																										
		_delay_ms(100);
		ergodox_right_led_1_on();
		ergodox_left_led_3_on();			
	
    } else {
        ergodox_right_led_1_off();
		ergodox_left_led_3_off();
		
    }

};
