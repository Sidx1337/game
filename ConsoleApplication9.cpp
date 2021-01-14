#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
//#include "map.h"
//#include "view.h"
//#include "player.h"
#include <sstream>
using namespace sf;

int ground = 800;
float offsetX = 0, offsetY = 0;

bool gameOver = false;
const int H = 46;
const int W = 240;
String TileMap[H] = {
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                                       B",
"B                   BBB                                B                                                                                                                                                                               WWWWWWWWB",
"B                   BBB                                B                                                                                                                                                                               WWWWWWWWB",
"B                   BBB 0                              B         0                                                                                                                                                                     WWWWWWWWB",
"B                   BBB                                B                                                                                                                                                                               WWWWWWWWB",
"B                   BBB                                B                                                                                                                                                                               WWWWWWWWB",
"B                   BBBBBB                             BBBBBBBBBBBBBBBBBBBBBB                                                                                                                                                          WWWWWWWWB",
"B                                      BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                                                                                          WWWWWWWWB",
"B                                      BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                                                               BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                      BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                               BBBBBBBBBBBBBBBBBBBBB             BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                                      BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                                      BBBBBBBBBBBBBB               BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                  BBBBBBBB            BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBBB                                                                                                     BBBBBBBBBBBBBB                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                    BBBBBB            BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                                      BBBBBBBBBBBBBB                   BBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"B                    BBBBBB            BBBBBBBB        BBBBBBBBBBBBBBBBBBBBBB                                                                                                      BBBBBBBBBBBBBB                     BBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBB                 BBBBBB            BBBBBBBB                                                                                                                                    BBBBBBBBBBBBBB                       BBBBBBBBBBBBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBB                                                                                                                                    BBBBBBBBBBBBBB                         BBBBBBBBBBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBB                                                                                                                             BBBBBBBBBBBBBBBBBBBBB                           BBBBBBBBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBB                                                                                                                             BBBBBBBBBBBBBBBBBBBBB                             BBBBBBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBB       BBBBBBBBBBBBBBBBBBBBBBBBBB                                                                                            BBBBBBBBBBBBBBBBBBBBB                               BBBBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBBAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBB                                                                                            BBBBBBBBBBBBBBBBBBBBB                                 BBBBBBBBBBBBBB",
"B                    BBBBBBAAAAAAAAAAAABBBBBBBBAAAAAAABBBBBBBBBBBBBBBBBBBBBBBBBB                                                                     BBBBBBB                BBBBBBBBBBBBBBBBBBBBB                                   BBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAABBB                                                                                            BBBBBBB                BBBBBBBBBBBBBBBBBBBBB                                     BBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAABBB                                                                   BBBBBBB                  BBBBBBB                BBBBBBBBBBBBBBBBBBBBB                                       BBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB     0                                                             BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                          BBBBBBB                  BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                                          BBBBBBB                  BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                  BBBBBBB                  BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                  BBBBBBB                  BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB                  BBBBBBB                  BBBBBBB                  BBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAAAABBBBBBBAAAAAAAAAAAAAAAABBBBBBBBBBBBBBBBBBBBBAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	bool life;
	int score = 0, speed = 0;
	int health = 100;
	Sprite sprite;
	float currentFrame;

	PLAYER(Texture& image)
	{
		life = true;
		sprite.setTexture(image);
		rect = FloatRect(7 * 32, 9 * 32, 108, 120);
		dx = dy = 0.1;
		currentFrame = 0;
	}

	//void centerTextAt(Text* text, float x, float y) {
		//FloatRect textRect = text->getLocalBounds();
		//text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		//text->setPosition(Vector2f(x, y));
	//}


	void update(float time)
	{
		rect.left += dx * time;
		Collision(0);
		if (!onGround) dy = dy + 0.005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);
		currentFrame += 0.0069 * time;
		if (currentFrame > 8) currentFrame -= 8;
		if (dx > 0) sprite.setTextureRect(IntRect(108 * int(currentFrame) + 108, 140, -108, 140));
		if (dx < 0) sprite.setTextureRect(IntRect(108 * int(currentFrame), 140, 108, 140));
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
		if (health <= 0)
		{
			life = false;
		}
	}
	void Collision(int dir)
	{
		for (int i = rect.top / 32; i < (rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j < (rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == 'B')
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * 32 - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * 32 + 32;
					if ((dy > 0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
				}

				if (TileMap[i][j] == '0')
				{
					TileMap[i][j] = ' ';
					score = score + 1;
				}
				if (TileMap[i][j] == 'A')
				{
					health = health - 100;
				    gameOver = true;
				}
			}

	}
};

int main()
{
	RenderWindow window(VideoMode(1920, 1200), "Test!");
	Texture t;
	t.loadFromFile("hero.png");
	Image map_image;
	map_image.loadFromFile("fon.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);
	float currentFrame = 0;
	PLAYER p(t);
	Clock clock;
	RectangleShape rectangle(Vector2f(32, 32));

	//Text gameOverText;
	//gameOverText.setString("GameOver");
	//gameOverText.setFillColor(Color::Blue);
	//centerTextAt(&gameOverText, W / 2, H / 2 - 200);

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time ;
		if (time > 20) time = 20;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (p.life == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				p.dx = -0.3;

			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				p.dx = 0.3;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (p.onGround) { p.dy = -0.5; p.onGround = false; }
			}
		}
		p.update(time);
		if (p.rect.left > 960) offsetX = p.rect.left - 960;
		offsetY = p.rect.top - 900;
		window.clear();
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B')  s_map.setTextureRect(IntRect(556, 0, 161, 168));
				if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(364, 0, 168, 168));
				if (TileMap[i][j] == 'A')  s_map.setTextureRect(IntRect(168, 0, 161, 168));
				if (TileMap[i][j] == 'W')  s_map.setTextureRect(IntRect(0, 180, 0, 0));
				if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 161, 168));
				s_map.setPosition(j * 32 - offsetX, i * 32 - offsetY);
				window.draw(s_map);
			}
		//std::ostringstream playerHealthString, gameTimeString;  
		//playerHealthString << p.health; gameTimeString << gameTime;		
		//text.setString("Здоровье: " + playerHealthString.str() + "\nВремя игры: " + gameTimeString.str());

		//text.setPosition(view.getCenter().x - 165, view.getCenter().y - 200);
		//window.draw(text);
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}




