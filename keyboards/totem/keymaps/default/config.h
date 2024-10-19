#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_LEFT

#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_ACTION_ONESHOT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 5000  // 5 seconds.

#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 1
#define MOUSEKEY_MAX_SPEED 2
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 50