
#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

// Override base class with your custom functionality
class PixelRTS : public olc::PixelGameEngine
{
public:
	PixelRTS()
	{
		// Name you application
		sAppName = "Pixel RTS";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame, draws random coloured pixels
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				Draw(x, y, olc::Pixel(rand() % 256, rand() % 256, rand() % 256));
		return true;
	}
};

int main()
{
	PixelRTS game;
	if (game.Construct(256, 240, 4, 4))
		game.Start();
	return 0;
}