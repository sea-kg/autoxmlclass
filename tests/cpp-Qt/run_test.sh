#!/bin/bash

# xml_input=fromfile
# data_xml=filename == text.xml
# lang=cpp_qt_useqxml
# outputtype=zipfile
# outputfilename='autocode'
#	-o temp.txt

URL="http://localhost/autoxmlclass/index.php"

echo ">>>>>>> start test <<<<<<<<";

FILENAME_XML=`pwd`"/../example.xml"

echo "+++++++ fullpath to xmlfile: "
echo "    " $FILENAME_XML

if [ -f src/temp.zip ]; then
	rm src/temp.zip
fi

echo "";
echo "";
echo "";

echo -n "Download sources ... ";

curl -X POST \
	--no-progress-bar \
	-o src/temp.zip \
	-F xml_input=fromfile \
	-F data_xml=@$FILENAME_XML \
	-F output_filename=testObject \
	-F output_lang=cpp_qt_useqxml \
	-F output_type=zipfile \
	$URL > /dev/null

if [ ! -f src/temp.zip ]; then
	echo "[FAIL]"
	exit
fi
echo "[OK]";

exit;

echo "";
echo "";
echo "";

echo "+++++ unpack zipfile: "
cd src

if [ -f testObject.h ]; then 
	rm testObject.h 
fi

if [ -f testObject.cpp ]; then 
	rm testObject.cpp 
fi

unzip temp.zip
rm temp.zip
cd ..

echo "";

echo "------- start compile -------";

if [ -f autoxmlclass ]; then 
	rm autoxmlclass
fi

qmake autoxmlclass.pro
make

echo "------- end compile -------";

echo "";
echo "";
echo "";
echo "------- start program -------";

if [ -f autoxmlclass ]; then 
  ./autoxmlclass ../object.xml	
fi

echo "------- end program -------";
echo ">>>>>>> end test <<<<<<<<";
