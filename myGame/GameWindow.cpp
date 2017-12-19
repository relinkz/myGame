#include "stdafx.h"
#include "GameWindow.h"


GameWindow::GameWindow()
{
	Setup("Window", sf::Vector2u(640, 480));
}

GameWindow::GameWindow(const std::string & l_title, const sf::Vector2u & l_size)
{
	Setup(l_title, l_size);
}

GameWindow::~GameWindow()
{
	Destroy();
}

void GameWindow::BeginDraw()
{
	m_window.clear(sf::Color::Black);
}

void GameWindow::EndDraw()
{
	m_window.display();
}

void GameWindow::Update()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_isDone = true;
		else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F5)
			ToggleFullscreen();
	}
}

bool GameWindow::IsDone()
{
	return m_isDone;
}

bool GameWindow::isFullscreen()
{
	return m_isFullscreen;
}

sf::Vector2u GameWindow::GetWindowSize()
{
	return m_windowSize;
}

void GameWindow::ToggleFullscreen()
{
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void GameWindow::Draw(sf::Drawable & l_drawable)
{
	m_window.draw(l_drawable);
}

void GameWindow::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
	m_windowTitle = l_title;
	m_windowSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;

	Create();
}

void GameWindow::Destroy()
{
	m_window.close();
}

void GameWindow::Create()
{
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}


