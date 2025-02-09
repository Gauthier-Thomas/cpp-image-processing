#include <string>
#include <iostream>
#include "viewmenu.h"

ViewMenu::ViewMenu(const std::string& _title, Controller* _controller): View(_title)
{
	this->controller = _controller;
	this->controller->addObserver(this);
}

void ViewMenu::notify()
{
	if (this->controller->getCurrentScreen() == 1)
		this->display();
}

void ViewMenu::display()
{
	std::string command = "TITLE ";
	std::string titleCommand = command + this->getTitle();
	system(titleCommand.c_str());
	int choice = 0;
	while (choice != 12) {
		while (choice < 1 || choice > 12) {
			this->displayMenu();
			std::string input;
			std::cin >> input;
			try {
				choice = std::stoi(input);
			}
			catch (std::exception e) {
				choice = 0;
			}
		}
		this->displayMenu();
		if (choice != 12)
			this->controller->setScreen(choice + 1);
	}
	exit(0);
}

void ViewMenu::displayMenu()
{
	this->clear();
	std::cout << "\t\tMenu" << std::endl << std::endl;
	std::cout << "1.  Filtre Median" << std::endl;
	std::cout << "2.  Filtre Gausien" << std::endl << std::endl;
	std::cout << "3.  Calcul du gradient dans une image" << std::endl << std::endl;
	std::cout << "4.  Dilatation" << std::endl;
	std::cout << "5.  Erosion" << std::endl << std::endl;
	std::cout << "6.  Application d'un detecteur de contours" << std::endl << std::endl;
	std::cout << "7.  Operations de seuillages" << std::endl;
	std::cout << "8.  Segmentation par croissance de region" << std::endl << std::endl;
	std::cout << "9.  Apercu de l'image" << std::endl << std::endl;
	std::cout << "10. Annuler la derniere operation" << std::endl << std::endl;
	std::cout << "11. Sauvegarder" << std::endl;
	std::cout << "12. Quitter" << std::endl;
}