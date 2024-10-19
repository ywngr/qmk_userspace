# MCU name

# Bootloader selection

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = yes

# LTO must be disabled for RP2040 builds

SWAP_HANDS_ENABLE = yes

# PIO serial/WS2812 drivers must be used on RP2040

#SPACE SAVING
EXTRAKEY_ENABLE = no
AUDIO_ENABLE = no
MUSIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no

