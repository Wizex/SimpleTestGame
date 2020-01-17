#include "Audio.h"

void init_audio(){

	main_audio = sfMusic_createFromFile(MAIN_AUDIO_PATH);

	beat_player_buffer = sfSoundBuffer_createFromFile(BEAT_PLAYER_SOUND_PATH);
	player_running_buffer = sfSoundBuffer_createFromFile(PLAYER_RUNNING_SOUND_PATH);
	open_chest_buffer = sfSoundBuffer_createFromFile(OPEN_CHEST_SOUND_PATH);
	close_chest_buffer = sfSoundBuffer_createFromFile(CLOSE_CHEST_SOUND_PATH);

	beat_player = sfSound_create();
	player_running = sfSound_create();
	open_chest = sfSound_create();
	close_chest = sfSound_create();

	sfSound_setBuffer(beat_player, beat_player_buffer);
	sfSound_setBuffer(player_running, player_running_buffer);
	sfSound_setBuffer(open_chest, open_chest_buffer);
	sfSound_setBuffer(close_chest, close_chest_buffer);

	sfSound_setLoop(player_running, sfTrue);
	
	open_close_bag_sound_buffer = sfSoundBuffer_createFromFile(OPEN_CLOSE_BAG_PATH);

	open_close_bag_sound = sfSound_create();

	sfSound_setBuffer(open_close_bag_sound, open_close_bag_sound_buffer);

	button_click_buffer = sfSoundBuffer_createFromFile(BUTTON_CLICK_PATH);
	switch_click_buffer = sfSoundBuffer_createFromFile(SWITCH_CLICK_PATH);

	button_click = sfSound_create();
	switch_click = sfSound_create();

	sfSound_setBuffer(button_click, button_click_buffer);
	sfSound_setBuffer(switch_click, switch_click_buffer);

	sound_volume = 100.0;
	music_volume = 100.0;

}

void change_sounds_volume(const unsigned int volume) {

	sfSound_setVolume(beat_player, volume);
	sfSound_setVolume(player_running, volume);
	sfSound_setVolume(open_chest, volume);
	sfSound_setVolume(close_chest, volume);
	sfSound_setVolume(open_close_bag_sound, volume);
	sfSound_setVolume(button_click, volume);
	sfSound_setVolume(switch_click, volume);

}

void change_music_volume(const unsigned int volume) {

	sfMusic_setVolume(main_audio, volume);

}

void destroy_audio(){

	sfMusic_destroy(main_audio);

	sfSound_destroy(button_click);
	sfSound_destroy(switch_click);

	sfSoundBuffer_destroy(button_click_buffer);
	sfSoundBuffer_destroy(switch_click_buffer);

	sfSound_destroy(open_close_bag_sound);

	sfSoundBuffer_destroy(open_close_bag_sound_buffer);

	sfSound_destroy(beat_player);
	sfSound_destroy(player_running);
	sfSound_destroy(open_chest);
	sfSound_destroy(close_chest);

	sfSoundBuffer_destroy(beat_player_buffer);
	sfSoundBuffer_destroy(player_running_buffer);
	sfSoundBuffer_destroy(open_chest_buffer);
	sfSoundBuffer_destroy(close_chest_buffer);

}
