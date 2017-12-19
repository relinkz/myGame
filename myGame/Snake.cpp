#include "stdafx.h"
#include "Snake.h"


Snake::Snake(int blockSize)
{
	m_size = blockSize;
	//"seperate" the snakesegments with one pixel string
	m_bodyRect.setSize(sf::Vector2f(m_size - 1, m_size - 1));
	m_startPos = sf::Vector2i(5, 7);
	Reset();
}


Snake::~Snake()
{
}

void Snake::SetDirection(Direction new_dir)
{
}

void Snake::Extend()
{
	if (m_snakeBody.empty())
		return;
	SnakeSegment& tail_head = m_snakeBody[m_snakeBody.size() - 1];

	if (m_snakeBody.size() > 1)
	{
		SnakeSegment& tail_bone = m_snakeBody[m_snakeBody.size() - 2];
		
		if (tail_head.position.x == tail_bone.position.x)
		{
			if (tail_head.position.y > tail_bone.position.y)
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
			else
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		}
		else if (tail_head.position.y == tail_bone.position.y)
		{
			if (tail_head.position.x > tail_bone.position.x)
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
			else
				m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
		}
	}
	else
	{
		if (m_dir == Direction::Up)
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y + 1));
		else if (m_dir == Direction::Down)
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x, tail_head.position.y - 1));
		else if (m_dir == Direction::Left)
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x + 1, tail_head.position.y));
		else if (m_dir == Direction::Right)
			m_snakeBody.push_back(SnakeSegment(tail_head.position.x - 1, tail_head.position.y));
	}
}

void Snake::Reset()
{
	m_snakeBody.clear();

	int startX = m_startPos.x;
	int startY = m_startPos.y;

	m_snakeBody.push_back(SnakeSegment(startX, startY--));
	m_snakeBody.push_back(SnakeSegment(startX, startY--));
	m_snakeBody.push_back(SnakeSegment(startX, startY));

	SetDirection(Direction::None);
	m_speed = 15;
	m_lives = 3;
	m_score = 0;
	m_lost = false;
}

void Snake::Move()
{
	for (int i = m_snakeBody.size(); i > 0; --i)
	{
		if (m_dir == Direction::Up)
			--m_snakeBody.at(i).position.y;
		else if (m_dir == Direction::Down)
			++m_snakeBody.at(i).position.y;
		else if (m_dir == Direction::Left)
			--m_snakeBody.at(i).position.x;
		else if (m_dir == Direction::Right)
			++m_snakeBody.at(i).position.y;
	}
}

void Snake::Tick()
{
	if (m_snakeBody.empty())
		return;
	if ( m_dir == Direction::None)
		return;

	Move();
	CheckCollision();
}

void Snake::Cut(int nrOfSegments)
{
	for (int i = 0; i < nrOfSegments; ++i)
		m_snakeBody.pop_back();
	--m_lives;

	if (m_lives == 0)
		Lose();
	return;
}

void Snake::Render(sf::RenderWindow & window)
{
	if (m_snakeBody.empty())
		return;
	auto head = m_snakeBody.begin();
	m_bodyRect.setFillColor(sf::Color::Yellow);
	m_bodyRect.setPosition(head->position.x * m_size, head->position.y * m_size);

	window.draw(m_bodyRect);

	m_bodyRect.setFillColor(sf::Color::Green);
	for (auto itr = m_snakeBody.begin() + 1; itr != m_snakeBody.end(); ++itr)
	{
		m_bodyRect.setPosition(itr->position.x * m_size, itr->position.y * m_size);
		window.draw(m_bodyRect);
	}

}

void Snake::CheckCollision()
{
	if (m_snakeBody.size() < 5)
		return;
	SnakeSegment& head = m_snakeBody.front();
	for (auto itr = m_snakeBody.begin() + 1; m_snakeBody.begin() != m_snakeBody.end(); ++itr)
	{
		if (itr->position == head.position)
		{
			int segments = m_snakeBody.end() - itr;
			Cut(segments);
			break;
		}
	}
}
