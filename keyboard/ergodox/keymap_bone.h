/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Bone layout for Ergodox
 *
 * The general idea is to have three layers that can be toggled in order:
 *
 * – standard Bone
 *   (no led)
 * – poor man’s QWERTZ ((partial) QWERTZ with Bone active on the host system)
 *   (middle led)
 * – poor man’s Bone ((partial) Bone with QWERTZ active on the host system)
 *   (bottom led)
 *
 */

static const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Keymap 0: Default Layer
     *
     * Bone
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  |  L1  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |    ß   |   J  |   D  |   U  |   A  |   X  |  UP  |           | DEL  |   P  |   H  |   L  |   M  |   W  |   Q    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  M3l   |   C  |   T  |   I  |   E  |   O  |------|           |------|   B  |   N  |   R  |   S  |   G  |  M3r   |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LSft  |   F  |   V  |   Ü  |   Ä  |   Ö  | DOWN |           | RET  |   Y  |   Z  |   ,  |   .  |   K  |  RSft  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |  ♫   | Prnt |      | LCtl |  M4l |                                       |  M4r | RCtl |  T1  |  T2  |  T3  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | ??   |       | RGui |      |      |
     *                                 |   ß  | LAlt |------|       |------| RAlt | Space|
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

    KEYMAP(
        // left hand
         ESC,  1,   2,    3,   4, 5,  FN1,
		SLSH,  Q,   W,    E,   R, T,  TAB,
        LSFT,  A,   S,    D,   F, G,
        LCTRL, Z,   X,    C,   V, B, BSPC,
        NUHS,PSCR, NO, HOME, END,
                                         NO,   NO,
                                             LGUI,
                                 SLSH,  ENT,   NO,
        // right hand
               NO,   6,    7,    8,   9,   0, MINS,
              DEL,   Y,    U,    I,   O,   P, LBRC,
                     H,    J,    K,   L,SCLN, RSFT,
             LGUI,   N,    M, COMM, DOT,QUOT,RCTRL,
                        LEFT, RGHT,NUBS, EQL, RBRC,
          NO, NO,
        RGUI,
          NO, ENT, SPC
    ),

    /* Keymap 1:
     *
     * Poor man’s QWERTZ
     *
     * This layer is designed for applications that really can‘t ever stand
     * anything else than QWERT[ZY]. With Bone active as the OS’ keyboard
     * layout, it builds a virtual QWERTZ on the board.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  | F13  |           | F14  |   6  |   7  |   8  |   9  |   0  |   ß    |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |  Tab   |   Q  |   W  |   E  |   R  |   T  | BKSP |           |  F1  |   Z  |   U  |   I  |   O  |   P  |   Ü    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  Del   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LSft  |   Y  |   X  |   C  |   V  |   B  | RET  |           |  F2  |   N  |   M  |   ,  |   .  |   -  | RSft   |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LCtl |  L0  |  L2  |  F3  |  L4  |                                       |  L4  |  F10 |  F11 | F12  | RCtl |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |  F5  |  F6  |       |  F7  |  F8  |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | LAlt |       | RCtrl|      |      |
     *                                 | Space|  F4  |------|       |------|  M3r | Space|
     *                                 |      |      | LGui |       | RGui |      |      |
     *                                 `--------------------'       `--------------------'
     */

	KEYMAP(
		// left hand
		ESC,   1,   2,   3,   4,   5,  FN2,
		TAB,   P,   T,   F,   K,   L, BSPC,
		DEL,   D,   H,SCLN,   O,   I,
		LSFT,QUOT,  Q,   R,   W,   N,  ENT,
		LCTRL, NO, NO,  NO, FN3,
										NO,  NO,
										   LALT,
								  SPC,  F4,LGUI,
		// right hand
			 NO,   6,   7,   8,   9,   0, LBRC,
			 NO,    B,   A,   S,   G,   V,    Z,
					U,SLSH,   Y,   E,   X,    C,
			 NO,  J,   M,COMM, DOT,MINS, RSFT,
					   FN3,  NO,  NO,  NO, RCTL,
		  NO, NO,
		LCTRL,
		RGUI, NUHS, SPC
	),

    /* Keymap 2:
     *
     * poor man’s Bone
     *
     * For the rare occasions when you have to work on a computer that has no
     * way of installing Neo2 in the OS, you can make do with this layer and
     * QWERTZ configured on the computer. That as close as possible resembles
     * Bone. Of course, the Shift layer still is as it is in QWERTZ and Bone
     * Layer3 is not possible¹. Layer 4 is again implemented in hardware as far
     * as possible.
     *
     * ¹ Pull requests welcome.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |   1  |   2  |   3  |   4  |   5  |  L0  |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |   ß    |   J  |   D  |   U  |   A  |   X  |      |           | Del  |   P  |   H  |   L  |   M  |   W  |   Q    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |   C  |   T  |   I  |   E  |   O  |------|           |------|   B  |   N  |   R  |   S  |   G  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |  LSft  |   F  |   V  |   Ü  |   Ä  |   Ö  |      |           | Ent  |   Y  |   Z  |   ,  |   .  |   K  |  RSft  |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      | Prnt |      | LCtl |  L4  |                                       |  L4  | RCtl |  T1  |      |  T3  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |  ß   | Lalt |------|       |------| RAlt | Space|
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

	KEYMAP(
		// left hand
		ESC,    1,   2,   3,   4,   5,FN0,
		MINS,   J,   D,   U,   A,   X, NO,
		FN4,    C,   T,   I,   E,   O,
		LSFT, 	F, 	 V,LBRC,QUOT,SCLN, NO,
		NO,  PSCR,  NO,LCTL, FN3,
									   NO, NO,
										   NO,
								 MINS,LALT,NO,
		// right hand
			 NO,    6,   7,   8,   9,   0,SLSH,
			 DEL,   P,   H,   L,   M,   W,   Q,
					B,   N,   R,   S,   G, FN4,
			 ENT,   Z,   Y,COMM, DOT,   K,RSFT,
					   FN3,RCTL,NUBS,  NO, EQL,
		NO,NO,
		NO,
		NO,RALT,SPC
	),

    /* Keymap 3:
     *
     * hardware bone layer 4
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |        | PgUp | BSpc |  Up  |  Del | PgDn |      |           |      |      |   7  |   8  |   9  |   +  |   -    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        | Home | Left | Down | Right|  End |------|           |------|      |   4  |   5  |   6  |   ,  |   .    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  Esc |  Tab |  Ins |  Ret | Undo |      |           |      |      |   1  |   2  |   3  |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

	KEYMAP(
		// left hand
		  NO,  NO,  NO,  NO,  NO,  NO, FN0,
		  NO,PGUP,BSPC,  UP, DEL,PGDN,  NO,
		  NO,HOME,LEFT,DOWN,RGHT, END,
		  NO, ESC, TAB, INS, ENT,UNDO,  NO,
		  NO,  NO,  NO,  NO,TRNS,
										NO,  NO,
										   NO,
								 NO,NO,NO,
		// right hand
			   NO,  NO,  NO,  NO,  NO,  NO,  NO,
			   NO,  NO,   7,   8,   9,RBRC,MINS,
					NO,   4,   5,   6,COMM, DOT,
			   NO,  NO,   1,   2,   3,  NO,  NO,
					   TRNS,  NO,  NO,  NO,  NO,
		  NO,  NO,
		NO,
		NO,  NO,   0
	),

    /* Keymap 4:
     *
     * hardware bone layer 3
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |        |      |  _   |  [   |  ]   |  ^   |      |           |      |  !   |  <   |  >   |  =   |  &   |   @    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  \   |  /   |  {   |  }   |  *   |------|           |------|  ?   |  (   |  )   |  -   |  :   |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |  #   |  $   |  |   |  ~   |  `   |      |           |      |  +   |  %   |  "   |  '   |  '   |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      |      |      |                                       |      |      |      |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |      |
     *                                 |      |      |------|       |------|      |      |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */

	KEYMAP(
		// left hand
		  NO,  NO,  NO,  NO,  NO,  NO,  NO,
		  NO,  NO,FN21,FN28,FN29, FN7,  NO,
		TRNS,FN25,FN17,FN27,FN30,FN31,
		  NO,NUHS,FN14,FN25,FN9,  FN6,  NO,
		  NO,  NO,  NO,  NO,  NO,
										NO,  NO,
											 NO,
								   NO,  NO,  NO,
		// right hand
			   NO,  NO,  NO,  NO,  NO,  NO,  NO,
			   NO,FN11,NUBS,FN24,FN20,FN16, FN8,
				  FN10,FN18,FN19,SLSH,FN23,TRNS,
			   NO,RBRC,FN15,FN12,FN26,FN22,  NO,
						 NO,  NO,  NO,  NO,  NO,
		  NO,  NO,
		  NO,
		  NO,  NO,  NO
	),

	// empty keymap for debugging
	KEYMAP(NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO),
};

/* id for user defined functions */
enum function_id {
    LAYER0,
    LAYER1,
    LAYER2,
};

enum macro_id {
    GRAVE_MACRO,
	BACKTICK_MACRO,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(LAYER0), /* bone */
	[1] = ACTION_FUNCTION(LAYER1), /* poor mans QWERTZ */
	[2] = ACTION_FUNCTION(LAYER2),/* poor mans bone */
	[3] = ACTION_LAYER_MOMENTARY(3),/* poor mans bone layer 3 */
	[4] = ACTION_LAYER_MOMENTARY(4),/* poor mans bone layer 4 */

	[10] = ACTION_MODS_KEY(MOD_LSFT, KC_MINUS), /* ? */
	[11] = ACTION_MODS_KEY(MOD_LSFT, KC_1), /* ! */
	[12] = ACTION_MODS_KEY(MOD_LSFT, KC_2), /* " */
	[13] = ACTION_MODS_KEY(MOD_LSFT, KC_3), /* § */
	[14] = ACTION_MODS_KEY(MOD_LSFT, KC_4), /* $ */
	[15] = ACTION_MODS_KEY(MOD_LSFT, KC_5), /* % */
	[16] = ACTION_MODS_KEY(MOD_LSFT, KC_6), /* & */
	[17] = ACTION_MODS_KEY(MOD_LSFT, KC_7), /* / */
	[18] = ACTION_MODS_KEY(MOD_LSFT, KC_8), /* ( */
	[19] = ACTION_MODS_KEY(MOD_LSFT, KC_9), /* ) */
	[20] = ACTION_MODS_KEY(MOD_LSFT, KC_0), /* = */
	[21] = ACTION_MODS_KEY(MOD_LSFT, KC_SLASH), /* _ */
	[22] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA), /* ; */
	[23] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT), /* : */
	[24] = ACTION_MODS_KEY(MOD_LSFT, KC_NONUS_BSLASH), /* > */
	[25] = ACTION_MODS_KEY(MOD_RALT, KC_NONUS_BSLASH), /* | */
	[26] = ACTION_MODS_KEY(MOD_LSFT, KC_NONUS_HASH), /* ' */
	[27] = ACTION_MODS_KEY(MOD_RALT, KC_7), /* { */
	[28] = ACTION_MODS_KEY(MOD_RALT, KC_8), /* [ */
	[29] = ACTION_MODS_KEY(MOD_RALT, KC_9), /* ] */
	[30] = ACTION_MODS_KEY(MOD_RALT, KC_0), /* } */
	[31] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET), /* * */
	[9] = ACTION_MODS_KEY(MOD_RALT, KC_RBRACKET), /* ~ */
	[8] = ACTION_MODS_KEY(MOD_RALT, KC_Q), /* @ */
	[7] = ACTION_MACRO(GRAVE_MACRO), /* ^ */
	[6] = ACTION_MACRO(BACKTICK_MACRO), /* ` */

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;
    switch (id) {
        case GRAVE_MACRO:
            return (event.pressed ?
					MACRO(T(GRAVE), T(SPACE), END) : MACRO_NONE);
            break;
        case BACKTICK_MACRO:
            return (event.pressed ?
					MACRO(D(LSHIFT), T(EQUAL), U(LSHIFT), T(SPACE), END) : MACRO_NONE);
            break;
        default:
            return MACRO_NONE;
    }
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	print("action_function called\n");
	print("id  = "); phex(id); print("\n");
	print("opt = "); phex(opt); print("\n");
	if (record->event.pressed) {
		if (id == LAYER0) {
			// led off
			ergodox_led_all_off();
			// layer 0
			layer_clear();
		} else if (id == LAYER1) {
			// led 2 on
			ergodox_led_all_off();
			ergodox_right_led_2_on();
			// layer 1
			layer_on(1);
		} else if (id == LAYER2) {
			// led 3 on
			ergodox_led_all_off();
			ergodox_right_led_3_on();
			// layer 2
			layer_on(2);
		}
	}
}
