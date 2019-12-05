#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define NUMB 1 // Numeric
#define USTN 2 // MicroStation
#define MDIA 3 // Typing2
#define MNCF 4 // MineCraft
#define DVRK 5 // Dvorak
#define CLMC 6 // Colemac
#define PRGM 7 // Programming
#define DWRV 8 // Dwarven
#define WGWG 9 // WigWag

uint8_t lock_timer = 0;
uint8_t lock_timer2 = 255;
uint8_t lock_cycle = 0;
uint8_t caps1 = 0;
uint8_t num1 = 0;
uint8_t scroll1 = 0;
uint8_t prev = 0;

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
	set_unicode_input_mode(UC_WINC);
	rgblight_enable();
	rgblight_set_effect_range(0,16);
	rgblight_sethsv(112,255,127);
//	setrgb(0, 0, 255,	(LED_TYPE *)&led[0]);
//	setrgb(0, 0, 255,	(LED_TYPE *)&led[1]);
//	setrgb(127, 255, 255,	(LED_TYPE *)&led[2]);
//	setrgb(127, 255, 255,	(LED_TYPE *)&led[3]);
//	setrgb(127, 255, 255,	(LED_TYPE *)&led[4]);
//	setrgb(127, 255, 255,	(LED_TYPE *)&led[5]);
//	setrgb(127, 255, 255,	(LED_TYPE *)&led[6]);
//	rgblight_set();
	

	
};

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
        KC_GESC,        KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   KC_VOLD,
        KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,   KC_T,   TO(1),
        KC_CLCK,        KC_A,         KC_S,     KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,   KC_B,   KC_MUTE,
        KC_LCTL,        KC_LWIN,      KC_LALT,  KC_F1, KC_F2,
											           KC_F5,   KC_F8,
                                               KC_F3,  KC_F6,   KC_F9,
                                               KC_F4,  KC_F7,   KC_F10,
        // right hand
             KC_VOLU,     KC_6,   KC_7,    KC_8,      KC_9,      KC_0,        KC_BSPC,
             KC_PGUP,     KC_Y,   KC_U,    KC_I,      KC_O,      KC_P,        KC_EQUAL,
                          KC_H,   KC_J,    KC_K,      KC_L,      KC_SCLN,     KC_QUOT,
             KC_PGDN,     KC_N,   KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,     KC_SFTENT,
                                  KC_SPC,  KC_LBRC,   KC_RBRC,   KC_MINS,     KC_DEL,
             KC_F11,     KC_F12,
             KC_HOME,   KC_UP,   KC_END,
             KC_LEFT,   KC_DOWN,   KC_RIGHT
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
 *   |      |      |      |      |      |                                       |   0  |   ,  |   .  |KP Ent|      |
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
       KC_TAB, KC_TRNS, KC_TRNS,  KC_UP, KC_LPRN, KC_RPRN, TO(2),
       KC_CLCK, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_GRV,
       KC_LSFT, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,TO(0),
       LM(3, MOD_LCTL),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
							   KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_INS, KC_SLCK, KC_NLCK, KC_PSLS, KC_PAST,   KC_TRNS, KC_BSPC,
       KC_TRNS, KC_UP,   KC_P7,   KC_P8,    KC_P9,   KC_PMNS, KC_EQUAL,
                KC_DOWN, KC_P4,   KC_P5,    KC_P6,   KC_PPLS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_P1,   KC_P2,    KC_P3,   KC_BSLS, KC_TRNS,
                         KC_P0,   KC_COMM,  KC_PDOT, KC_PENT, KC_DEL,
       KC_TRNS, KC_TRNS,
       RGB_MOD, RGB_RMOD, KC_SCLN,	
       KC_TRNS, KC_TRNS, KC_SPC
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
       KC_TAB, M(0), KC_P7, KC_P8, KC_P9, KC_Z, TO(3),
       KC_CAPS, M(1), KC_P4, KC_P5, KC_P6, KC_Y,
       KC_TRNS, M(2), KC_P1, KC_P2, KC_P3, KC_X, TO(1),
       LM(3, MOD_LCTL), KC_TRNS, KC_P0, KC_COMM, KC_PDOT,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_SPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 3: Composition
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
// Composition
[MDIA] = LAYOUT_ergodox_80(
        // left hand
        KC_GESC,        KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   TO(5),
        KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,   KC_T,   TO(4),
        KC_CLCK,        KC_A,         KC_S,     KC_D,    KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,     KC_C,    KC_V,   KC_B,   TO(2),
        KC_TRNS,        KC_LWIN,      KC_LALT,  KC_F1, KC_F2,
											           KC_F5,   KC_F8,
                                               KC_F3,  KC_F6,   KC_F7,
                                               KC_F4,  KC_F7,   KC_F9,
        // right hand
             KC_VOLU,     KC_6,   KC_7,    KC_8,      KC_9,      KC_0,        KC_BSPC,
             KC_PGUP,     KC_Y,   KC_U,    KC_I,      KC_O,      KC_P,        KC_EQUAL,
                          KC_H,   KC_J,    KC_K,      KC_L,      KC_SCLN,     KC_QUOT,
             KC_PGDN,     KC_N,   KC_M,    KC_COMM,   KC_DOT,    KC_SLSH,     KC_SFTENT,
                                  KC_SPC,  KC_LBRC,   KC_RBRC,   KC_MINS,     KC_DEL,
             KC_F11,     KC_F12,
             KC_HOME,   KC_UP,   KC_END,
             KC_LEFT,   KC_DOWN,   KC_RIGHT
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
 * `--------+------+------+------+------+-------------'           `-------------+------+-----------.       ,-------------.
 *                       
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
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,
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
       KC_TRNS, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, TO(6),
       KC_TRNS, KC_A, KC_O, KC_E, KC_U, KC_I,
       KC_TRNS, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, TO(4),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
	   KC_TRNS,  KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, 
       KC_TRNS,  KC_F, KC_G, KC_C, KC_R, KC_L, KC_SLSH,
                 KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINS,
       KC_TRNS,  KC_B, KC_M, KC_W, KC_V, KC_Z, KC_SFTENT,
                       KC_SPC, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_NO
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
		KC_GESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	TO(0),	
		KC_TAB,		KC_Q,	KC_W,	KC_F,	KC_P,	KC_G,	TO(7),				
		KC_BSPC,	KC_A,	KC_R,	KC_S,	KC_T,	KC_D,	
		KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	TO(5),	
		KC_LCTL,	KC_LGUI,KC_LALT,KC_TRNS,KC_TRNS,					
										KC_NO,	KC_NO,	
								KC_NO,	KC_NO,	KC_NO,	
								KC_NO,	KC_NO,	KC_NO,
				
	// right hand			
		KC_NO,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,	
		KC_NO,	KC_J,	KC_L,	KC_U,	KC_Y,	KC_SCLN,KC_BSLS,	
				KC_H,	KC_N,	KC_E,	KC_I,	KC_O,	KC_QUOT,	
		KC_NO,	KC_K,	KC_M,	KC_COMM,KC_DOT,	KC_SLSH,KC_SFTENT,	
				KC_SPC,	KC_NO,	KC_NO,	KC_NO,	KC_DEL,	
		KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO,	
		KC_NO,	KC_NO,	KC_NO
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
[PRGM] = LAYOUT_ergodox_80(
        // left hand
        KC_GESC,         KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   TO(0),
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

/* Keymap 8: Dwarven
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |  ᛐ    |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  ᚫ   |  ᛩ   |   ᚩ   |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |  ᚱ   |      |           |      |      |      | Prev | Next |      |        |
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
// Dwarven
[DWRV] = LAYOUT_ergodox_80(
       UC_M_WC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0),
       KC_TAB, UC(0x16A9), UC(0x16C8), UC(0x16BA), UC(0X16CF), UC(0x16DA), TO(9),
       KC_CLCK, UC(0x16A2), UC(0x16B2), UC(0x16AB), UC(0x16E9), UC(0x16D5),
       KC_LSFT, UC(0x16DD), UC(0x16F3), UC(0x16B3), UC(0x042F), UC(0x16B1), TO(7),
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
								  KC_TRNS, KC_TRNS, KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  UC(0x16CB), UC(0x16DF), UC(0x16C1), UC(0x2227), UC(0x16B9), KC_TRNS,
	   KC_TRNS,  UC(0x16CB), UC(0x16DF), UC(0x16C1), UC(0x2227), UC(0x16B9), KC_TRNS,
				 UC(0x16D0), UC(0x16B8), UC(0x16B4), UC(0x16C5), UC(0x16E7), KC_TRNS,
       KC_TRNS,  UC(0x16C9), UC(0x16D2), UC(0x16BF), UC(0x16C6), KC_TRNS, KC_MPLY,
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
// Wig Wag
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
        case 1:
        if (record->event.pressed) {
		SEND_STRING ("PULL BOX");

		}
        break;
        case 2:
        if (record->event.pressed) {
		
		SEND_STRING ("LED");

		}
        break;		
				
		
		
		
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void _init_user(void) {

	
};





// 0 default layer
// 1 Numeric
// 2 MicroStation
// 3 Composition
// 4 MineCraft
// 5 Dvorak
// 6 Colemac
// 7 Programming
// 8 Dwarven
// 9 WigWag 



// Runs constantly in the background, in a loop.

// RGB Modes
// 1 = Static
// 2-5 = Breathing
// 6-8 = Rainbow
// 9-14 = Swirl
// 15-20 = Snake
// 21-24 = Nightrider
// 25 = Christmas
// 26-30 = Static Gradient

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);	
	rgblight_set_effect_range(0,16);
  
	switch (layer) {
			
		case 1: //Numeric	
			rgblight_mode(23);
			rgblight_sethsv(170,255,200);			
			break;
        case 2: //MicroStation
			rgblight_mode(18);
			rgblight_sethsv(191,255,255);			
            break;
        case 3: // Composition
			rgblight_mode(5);
			rgblight_sethsv(255,255,225);
            break;			
        case 4: // MineCraft
			rgblight_mode(8);
			rgblight_sethsv(213,255,225);
            break;			
        case 5: //Dvorak
			rgblight_mode(4);
 			rgblight_sethsv(28,255,225);
			break;
        case 6: //Colemak
			rgblight_mode(12);
			rgblight_sethsv(11, 176, 255);
            break;	
        case 7:	
			rgblight_mode(14);
            break;
        case 8: //Dwarven
			rgblight_mode(16);
			rgblight_sethsv(21,193,206);
            break;
        case 9:
			rgblight_mode(5);
			rgblight_sethsv(32,255,255);
			break;
        default:
			rgblight_mode(5);
			rgblight_sethsv(112,255,127);
            break;
			
	}; 
	

	return state;
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
		
		
		case 1:
            ergodox_right_led_2_on();
			ergodox_left_led_2_on();
            break;
        case 2:
            ergodox_right_led_3_on();
            ergodox_right_led_2_on();			
			ergodox_left_led_2_on();
			ergodox_left_led_1_on();
            break;
        case 3:
			ergodox_right_led_2_on();
			ergodox_left_led_1_on();
            break;			
        case 4:
            ergodox_right_led_3_on();
            ergodox_left_led_1_on();			
			ergodox_left_led_2_on();
 			break;
         case 5:
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
			ergodox_right_led_3_on();
            break;	
        case 7:	
            ergodox_left_led_2_on();
            break;
        case 8:
			ergodox_left_led_1_on();
            break;
        case 9:
            ergodox_right_led_2_on();
			ergodox_right_led_3_on();
			break;
		default:
//			rgblight_mode(2);
            break;	
	};	
	
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[16]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[17]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[18]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[19]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[20]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[21]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[22]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[23]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[24]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[25]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[26]);
		setrgb(scroll1, caps1, num1, (LED_TYPE *)&led[27]);


		
	if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
		if (lock_timer < 100 ) {
			ergodox_left_led_3_on();
		} else {
			ergodox_left_led_3_off();
		};
		ergodox_right_led_1_on();
		ergodox_right_led_1_set(lock_timer);
		caps1 = lock_timer;
	
	} else {
		ergodox_right_led_1_off();
		ergodox_left_led_3_off();
		caps1 = 0;
	};	

	// NUM LOCK
	if (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) {
		num1 = 127;
	} else {
		num1 = lock_timer2;
	};	
	
	// SCROLL LOCK
	if (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) {
		scroll1 = lock_cycle;
	} else {
		scroll1 = 0;
	};		
	rgblight_set();
	if (lock_timer < 255) {
		lock_timer = lock_timer + 2;
	} else { 
		lock_timer = 0;
	};
	lock_timer2 = 255 - lock_timer;
	if (lock_timer > 127) {
		lock_cycle = lock_timer * 2;
	} else {
		lock_cycle = 255 - lock_timer * 2;
	};
};

