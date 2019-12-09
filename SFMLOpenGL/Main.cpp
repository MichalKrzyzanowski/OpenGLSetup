#include <Game.h>

int main(void)
{
	srand(time(nullptr));

	Game& game = Game();
	game.run();
}