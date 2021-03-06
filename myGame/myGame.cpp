#include "stdafx.h"
#include "Game.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Game game; //gameobj

	while (!game.GetWindow()->IsDone())
	{
		//game loop
		game.HandleInput();
		game.Update();
		game.Render();
		game.restartClock();
	}
	return 0;
}

