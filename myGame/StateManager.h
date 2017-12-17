#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class StateManager;

class BaseState
{
	friend class StateManager;
public:
	BaseState(StateManager * l_stateManager) :
		m_stateMgr(l_stateMgr),
		m_transparent(false),
		m_transcendent(false) {}

	virtual ~BaseState() {}

	virtual void OnCreate() = 0;
	virtual void OnDestroy() = 0;

	virtual void Activate() = 0;
	virtual void Deactivate() = 0;

	virtual void Update(sf::Time & l_time) = 0;
	virtual void Draw() = 0;

	void SetTransparent(const bool& l_transparent)
	{
		m_transparent = l_transparent;
	}
	bool IsTransparent()const { return m_transparent; }

	void SetTranscendent(const bool& l_transcendence)
	{
		m_transcendent = l_transcendence;
	}
	bool IsTransparent()const { return m_transcendent; }

protected:
	StateManager * m_stateMgr;
	bool m_transparent;
	bool m_transcendent;
};

enum class StateType
{
	Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext {
	SharedContext() :m_wind(nullptr), m_eventManager(nullptr) {}
	Window* m_wind;
	EventManager* m_eventManager;
};

#endif

