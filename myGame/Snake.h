#ifndef SNAKE_H
#define SNAKE_H

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x,y){}
	sf::Vector2i position;
};

enum class Direction { None, Up, Down, Left, Right };

using SnakeContainer = std::vector<SnakeSegment>;



class Snake
{
public:
	Snake(int blockSize);
	~Snake();

	void SetDirection(Direction new_dir);
	Direction GetDirection() const;
	int getSpeed() const;
	void setSpeed(int new_speed);

	sf::Vector2i GetPosition();
	int GetLife() const { return m_lives; }
	int GetScore() const { return m_score; }
	void AddScore() { m_score += 10; }
	bool HastLost() { return m_lost; }

	void Lose() { m_lost = true; }
	void ToggleLost() { m_lost = !m_lost; }
	
	void Extend();
	void Reset();

	void Move();
	void Tick(); //Update Method
	void Cut(int nrOfSegments);
	void Render(sf::RenderWindow& window);

private:
	void CheckCollision();
	
	SnakeContainer m_snakeBody;
	int m_size;
	Direction m_dir;
	sf::Vector2i m_startPos;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;
	sf::RectangleShape m_bodyRect;
};

#endif

