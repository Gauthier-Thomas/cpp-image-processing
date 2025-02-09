#include "viewmedianblur.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewMedianBlur::ViewMedianBlur(const std::string& _title, Controller& _controller)
	: View(_title), controller(_controller)
{
	this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewMedianBlur::notify()
{
	if (this->controller.getCurrentScreen() == 2)
		this->display();
}

/**
 * Displays the view
 */
void ViewMedianBlur::display()
{
    std::cout << std::endl << "Merci d'indiquer un entier qui definira l'intensite du filtrage :" << std::endl;
    int c1;
    std::cin >> c1;
    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
	this->controller.getImage()->setMedian(c1);
	this->controller.setScreen(1);
}
