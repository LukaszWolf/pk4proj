#ifndef GAME_STATE_H
#define GAME_STATE_H

// Definicja `enum class` wewn¹trz klasy Game
// Bezpieczeñstwo typów – GameState::MENU nie konwertuje siê automatycznie na int, co zapobiega b³êdom.
// Brak zanieczyszczania przestrzeni nazw – wartoœci s¹ wewn¹trz GameState, nie globalnie.
enum class GameState
{
	PLAYER_CREATOR,
	LOGIN_PAGE,
	MENU,
	TAVERN,
	ARENA,
	BARN,
	SHOP_MAGIC,
	SHOP_WEAPONS,
	DUNGEONS,
	PLAYER_MENU
};

#endif 
