#include "BunnyWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setWindowIcon(QIcon("Resources/rabbit.ico"));
	BunnyWindow w;
	w.setWindowIcon(QIcon("Resources/rabbit.ico"));
	w.show();
	return a.exec();
}