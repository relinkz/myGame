#ifndef GAME_H
#define GAME_H
#include "GameWindow.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();

	GameWindow* GetWindow();

	sf::Time getElapsed() const;
	void restartClock();

private:
	void MoveSpite();
	GameWindow m_window;

	sf::Texture m_text;
	sf::Sprite m_sprite;
	sf::Vector2i m_increment;

	sf::Clock m_clock;
	sf::Time m_elapsed;
};

#endif // !GAME_H