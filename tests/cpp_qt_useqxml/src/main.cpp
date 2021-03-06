
#include <QObject>
#include <QMap>
#include <QFile>
#include <QDateTime>
#include <iostream>

#include "example.h"


// ---------------------------------------------------------------------------
int main(int argc, char *argv[] )
{
	if(argc < 2)
	{
		std::cout << "usage: " << argv[0] << " <xmlfilename>\r\n";
		return -1;
	};

	QString filename(argv[1]);
	
	if(!QFile(filename).exists())
	{
		std::cout << argv[1] << " - file not found\r\n";
		return -2;
	};

	example::Objects *pObjects = new example::Objects();
	QFile file(filename);
	if (pObjects->fromFile(file)) {
		
	}
	
	std::cout << pObjects->nameOfElement().toStdString() << std::endl;
	
	
	/*
	if(root == NULL)
	{
		std::cout << argv[1] << " - could not readed\r\n";	
		return -3;
	};
	std::cout << "root->id = [" << root->id.toStdString() << "]\r\n";
	*/
	std::cout << "\r\n";
	return 0;
};
