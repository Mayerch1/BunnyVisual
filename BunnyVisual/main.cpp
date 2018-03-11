#include "BunnyWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BunnyWindow w;
	w.show();
	return a.exec();
}