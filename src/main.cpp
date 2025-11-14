#include <print>
#include <memory>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

int main(int argc, char* argv[])
{
	const int wWidth = 1280;
	const int wHeight = 720;
	auto window = sf::RenderWindow(sf::VideoMode({ wWidth, wHeight }), "Assignment 1 | SFML + ImGui");
	window.setFramerateLimit(165);

	if (!ImGui::SFML::Init(window))
		return -1;

	sf::Clock clock;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		ImGui::SFML::Update(window, clock.restart());

		ImGui::Begin("Hello world");
		ImGui::Button("pretty button");
		ImGui::End();

		window.clear();
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();
}