/// <summary>
/// Change 1 Add GL.H and Glu.h 
/// This hooks up OpenGL with our Game 
/// </summary>
#include <Game.h>


int main(void)
{
	Game& game = Game();
	game.run();
}