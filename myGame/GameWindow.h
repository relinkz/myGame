#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H


class GameWindow
{
public:
	GameWindow();
	GameWindow(const std::string& l_title, const sf::Vector2u& l_size);
	~GameWindow();

	void BeginDraw();
	void EndDraw();

	void Update();

	bool IsDone();
	bool isFullscreen();
	sf::Vector2u GetWindowSize();

	void ToggleFullscreen();

	void Draw(sf::Drawable& l_drawable);

private:
	void Setup(const std::string& l_title, const sf::Vector2u& l_size);
	void Destroy();
	void Create();

	sf::RenderWindow m_window;
	sf::Vector2u m_windowSize;
	std::string m_windowTitle;
	bool m_isDone;
	bool m_isFullscreen;
};
#endif

