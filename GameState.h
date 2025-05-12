#ifndef GAME_STATE_H
#define GAME_STATE_H

// Definicja `enum class` wewn�trz klasy Game
// Bezpiecze�stwo typ�w � GameState::MENU nie konwertuje si� automatycznie na int, co zapobiega b��dom.
// Brak zanieczyszczania przestrzeni nazw � warto�ci s� wewn�trz GameState, nie globalnie.
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
