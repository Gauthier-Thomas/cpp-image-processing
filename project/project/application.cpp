#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Traitement d'image", this->controller);
	this->viewPathInput = new ViewPathInput("Selection de l'image", this->controller);
	this->viewMedianBlur = new ViewMedianBlur("Filtre median", *this->controller);
	this->viewGaussianBlur = new ViewGaussianBlur("Filtre gaussien", *this->controller);
}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
