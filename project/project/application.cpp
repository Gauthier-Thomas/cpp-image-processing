#include "application.h"

/**
 * Constructor
 */
Application::Application()
{
	this->controller = new Controller();
	this->viewMenu = new ViewMenu("Traitement d'image", this->controller);
	this->viewPathInput = new ViewPathInput("S�lection de l'image", this->controller);
	this->viewMedianBlur = new ViewMedianBlur("Filtre m�dian", *this->controller);
}

/**
 * Runs the application
 */
void Application::run()
{
	this->controller->notify();
}
