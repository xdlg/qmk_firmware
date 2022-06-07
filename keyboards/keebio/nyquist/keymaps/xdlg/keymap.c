#include QMK_KEYBOARD_H

#define DVO 0
#define SYM 1
#define FUN 2

#define OSLS OSM(MOD_LSFT)
#define OSRS OSM(MOD_RSFT)

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
};

bool is_alt_tab_active = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FUN  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |      | Alt  |    Space    |    Enter    | SYM  |AltTab| Del  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[DVO] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_SLSH, \
  OSL(FUN),KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS, \
  OSLS,    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    OSRS,    \
  KC_LCTL, KC_LCMD, XXXXXXX, KC_LALT, KC_SPC,  KC_SPC,  KC_ENT,  KC_ENT,  OSL(SYM),ALT_TAB, KC_DEL,  KC_RCTL  \
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |      |   [  |   ]  |   {  |   }  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |   `  |      |      |      |      |      |      |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ~  |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[SYM] = LAYOUT( \
  _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_GRV,  _______, _______, _______, _______, _______, _______, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______,_______ , _______, _______, _______, KC_EQL , \
  _______, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Functions/navigation
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |  F13 |  F14 |  F15 |      | PgUp |  Up  | PgDn |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Home | Left | Down | Right| End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Mute | Vol- | Vol+ | Bts- | Bts- |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUN] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
  _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______, \
  _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)

/* Empty
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |             |             |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [XXX] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)
*/

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Functionality is the following (basically the same thing as a normal Alt + Tab but without having
// to leave Alt pressed):
// - On pressing ALT_TAB, the window switch menu pops up.
// - While the menu is visible, it's possible to cycle through the selection by pressing ALT_TAB
//   again, or Shift + ALT_TAB, or the arrow keys.
// - The selected window can be brought up by pressing Enter, which also closes the menu.
//   Alternatively, pressing Escape closes the menu without selecting anything.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case KC_ENTER:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          unregister_code(KC_LALT);
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    case KC_ESCAPE:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          register_code(KC_ESCAPE);
          unregister_code(KC_LALT);
          unregister_code(KC_ESCAPE);
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    default:
      return true;
  }
}
