#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Vector.h";
#include "Matrix.h";


using namespace sf;

const float PI = 3.1415;

float dist(std::vector<float> c1, std::vector<float> c2) {
	float d = 0;
	d = sqrt(pow(c1[0] - c2[0], 2) + pow(c1[1] - c2[1], 2));
	return d;
}

bool intersect(CircleShape c1, CircleShape c2) {
	std::vector<float> center1 = { c1.getPosition().x, c1.getPosition().y },
		center2 = { c2.getPosition().x, c2.getPosition().y };

	if (dist(center1, center2) < c1.getRadius() + c2.getRadius()) {
		return 1;
	}

	else return 0;

}


class Bounce {
	float R = 0;
	CircleShape circle;
	float x;
	float y;
	float angle = 0;
	Vector dP = std::vector<float>{ 0.1f, 0.1f };
public:
	Bounce(float r, float start_x, float start_y) {
		R = r;
		circle.setRadius(R);
		x = start_x;
		y = start_y;
		circle.setPosition(x, y);
	}

	void update(float t) {
		move(t);
		circle.setPosition(x, y);
		Collision();
	}

	void move(float t) {
		x += t*dP.X();
		y += t*dP.Y();
	}

	void Collision()
	{
		if (x + R + dP.X() >= 1350) {
			dP = ((dP * MProj()) * 2 + dP * (-1)) * (-1);
		}
		if (x + dP.X() <= 0) {
			dP = ((dP * MProj()) * 2 + dP * (-1)) * (-1);

		}
		if (y + dP.Y() <= 0) {
			dP = ((dP * MProj()) * 2 + dP * (-1));

		}
		if (y + dP.Y() + R >= 650) {
			dP = ((dP * MProj()) * 2 + dP * (-1));

		}
	}

	void BounceCollision(Bounce b2) {
		if (intersect(circle, b2.getSprite())) {
			Vector Normal({ circle.getPosition().x - b2.getSprite().getPosition().x,
							circle.getPosition().y - b2.getSprite().getPosition().y });

			float angle = acos(dP * Normal / (Normal.norma() * dP.norma()));

			dP = dP * MRotate(2 * PI - 2 * angle);

		}
	}

	Vector getVector() {
		return dP;
	}

	void SetVector(Vector dS) {
		dP = (dP + dS);
	}

	CircleShape getSprite() {
		return circle;
	}
	void setColor(Color color) {
		circle.setFillColor(color);
	}
};




int main() {
	RenderWindow window(VideoMode(1400, 700), "Window");

	Bounce b1(50.f, 700, 300), b2(50.f, 1000, 44);


	Clock time;
	float dt = 0;

	//window.setFramerateLimit(60);

	while (window.isOpen()) {

		dt = time.getElapsedTime().asMilliseconds();
		dt = dt / 1000;

		std::cout << dt <<std::endl;
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		b1.update(dt);
		b2.update(dt);
		b1.BounceCollision(b2);
		b2.BounceCollision(b1);
		if (intersect(b1.getSprite(), b2.getSprite())) {
			b1.setColor(Color::Red);
			b2.setColor(Color::Red);
		}
		else {
			b1.setColor(Color::White);
			b2.setColor(Color::White);
		}
		window.clear();

		window.draw(b1.getSprite());
		window.draw(b2.getSprite());

		window.display();
	}


}