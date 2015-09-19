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
 *   (bottom led)
 * – poor man’s Bone ((partial) Bone with QWERTZ active on the host system)
 *   (middle and bottom led)
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
		NO,     C,   T,   I,   E,   O,
		LSFT, 	F, 	 V,LBRC,QUOT,SCLN, NO,
		NO,  PSCR,  NO,LCTL, FN3,
									   NO, NO,
										   NO,
								 MINS,LALT,NO,
		// right hand
			 NO,    6,   7,   8,   9,   0,SLSH,
			 DEL,   P,   H,   L,   M,   W,   Q,
					B,   N,   R,   S,   G,  NO,
			 ENT,   Y,   Z,COMM, DOT,   K,RSFT,
					   FN3,RCTL,NUBS,  NO, EQL,
		NO,NO,
		NO,
		NO,RALT,SPC
	),
		//NUHS→#,NUBS→<,

    /* Keymap 3:
     *
     * hardware Bone layer 4
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
     *                                 |      |      | LAlt |       | RCtrl|      |      |
     *                                 | LSft |      |------|       |------|      |   0  |
     *                                 |      |      | LGui |       | RGui |      |      |
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
     * special keys
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * | Power  |      |      |      |      |      |Teensy|           |      |      |      |      |      |      | Teensy |
     * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           | Ins  | Vol+ |  App |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |------|           |------| Mute | Last | Pl/Ps| Next | Stop |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |  KVM |           |      | Vol- |      |      |      |      |        |
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

	//KEYMAP(
		//// left hand
		 //PWR,  NO,  NO,  NO,  NO,  NO,  NO,
		  //NO,  NO,  NO,  NO,  NO,  NO,  NO,
		  //NO,  NO,  NO,  NO,  NO,  NO,
		  //NO,  NO,  NO,  NO,  NO,  NO,  NO,
		  //NO,  NO,  NO,  NO,  NO,
										//NO,  NO,
											 //NO,
								   //NO,  NO,  NO,
		//// right hand
			   //NO,  NO,  NO,  NO,  NO,  NO,  NO,
			  //INS,VOLU, APP,  NO,  NO,  NO,  NO,
				  //MUTE,MPRV,MPLY,MNXT,MSTP,  NO,
			 //TRNS,VOLD,  NO,  NO,  NO,  NO,  NO,
						 //NO,  NO,  NO,  NO,  NO,
		  //NO,  NO,
		  //NO,
		  //NO,  NO,  NO
	//),

	// empty keymap for debugging
	KEYMAP(NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO),
};

/* id for user defined functions */
enum function_id {
    LAYER0,
    LAYER1,
    LAYER2,
};

/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
	[0] = ACTION_FUNCTION(LAYER0),
	[1] = ACTION_FUNCTION(LAYER1),
	[2] = ACTION_FUNCTION(LAYER2),
	[3] = ACTION_LAYER_MOMENTARY(3),
	[4] = ACTION_LAYER_MOMENTARY(4),
};

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
