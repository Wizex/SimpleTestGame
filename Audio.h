#pragma once

#include <SFML/Audio.h>

#define MAIN_AUDIO_PATH "Audio/main_ost.wav"
#define BEAT_PLAYER_SOUND_PATH "Audio/Entity/beat_player.wav"
#define PLAYER_RUNNING_SOUND_PATH "Audio/Entity/player_running_audio.wav"
#define OPEN_CHEST_SOUND_PATH "Audio/Entity/open_chest.wav"
#define CLOSE_CHEST_SOUND_PATH "Audio/Entity/close_chest.wav"
#define OPEN_CLOSE_BAG_PATH "Audio/UI/open_close_bag.wav"
#define BUTTON_CLICK_PATH "Audio/UI/button_click.wav"
#define SWITCH_CLICK_PATH "Audio/UI/switch_button.wav"

sfMusic* main_audio;

sfSound* beat_player;
sfSound* player_running;
sfSound* open_chest;
sfSound* close_chest;
sfSound* open_close_bag_sound;
sfSound* button_click;
sfSound* switch_click;

static sfSoundBuffer* button_click_buffer;
static sfSoundBuffer* switch_click_buffer;
static sfSoundBuffer* open_close_bag_sound_buffer;
static sfSoundBuffer* beat_player_buffer;
static sfSoundBuffer* player_running_buffer;
static sfSoundBuffer* open_chest_buffer;
static sfSoundBuffer* close_chest_buffer;

float sound_volume;
float music_volume;

void init_audio();
void change_sounds_volume(const unsigned int);
void change_music_volume(const unsigned int);
void destroy_audio();