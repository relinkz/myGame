#include "stdafx.h"
#include "Game.h"


Game::Game() : m_window("Chapter 2", sf::Vector2u(800, 600))
{
	if (!m_text.loadFromFile(ASSETS_PATH + "test.png"))
		std::printf("Error reading texture from file");
	/*
	m_sprite = sf::Sprite(m_text);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 150, 200));
	m_sprite.setPosition(400, 400);
	m_increment = sf::Vector2i(-4, -4);
	*/
}


Game::~Game()
{
}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update();
	//MoveSpite();
}

void Game::Render()
{
	m_window.BeginDraw(); //Clear
	m_window.Draw(m_sprite); 
	m_window.EndDraw(); //Display
}

GameWindow * Game::GetWindow()
{
	return &this->m_window;
}

sf::Time Game::getElapsed() const
{
	return m_elapsed;
}

void Game::restartClock()
{
	m_elapsed += m_clock.restart();
}

void Game::MoveSpite()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_sprite.getTexture()->getSize();
	sf::Vector2f dPos = m_sprite.getPosition();

	if ((dPos.x > l_windSize.x - l_textSize.x &&m_increment.x > 0) ||
		(dPos.x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}

	if ((dPos.y > l_windSize.y - l_textSize.y &&m_increment.y > 0) ||
		(dPos.y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}

	float frametime = 1.0f / 60.0f;
	float dt = m_elapsed.asSeconds();

	//sleep if this condition is not met
	if (dt >= frametime)
	{
		//do something every 60 times a secound
		m_elapsed -= sf::seconds(frametime); //subtract
	}

	m_sprite.setPosition(dPos.x + (m_increment.x * dt), dPos.y + (m_increment.y * dt));
}
