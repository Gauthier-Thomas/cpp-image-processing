#include "viewgradient.h"
#include <iostream>
#include <string>

/**
 * Constructor
 * @param _controller: Application controller
 */
ViewGradient::ViewGradient(const std::string& _title, Controller& _controller)
    : View(_title), controller(_controller)
{
    this->controller.addObserver(this);
}

/**
 * Notification function of the view
 */
void ViewGradient::notify()
{
    if (this->controller.getCurrentScreen() == 4)
        this->display();
}

/**
 * Displays the view
 */
void ViewGradient::display()
{
    std::cout << std::endl << "Application du filtre en cours..." << std::endl;
    this->controller.getImage()->setGradient();
    this->controller.setScreen(1);
}
