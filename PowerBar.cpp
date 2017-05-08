#include "PowerBar.h"

PowerBar::PowerBar()
{
}

void PowerBar::display()
{
	ofLine((ofGetWidth()/2), 600, ((ofGetWidth()/2)-100), 600);
}

