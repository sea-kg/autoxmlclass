#!/bin/bash

# xml_input=fromfile
# data_xml=filename == text.xml
# lang=cpp_qt_useqxml
# outputtype=zipfile
# outputfilename='autocode'
#	-o temp.txt

echo ""
# URL="http://192.168.0.227/autoxmlclass/generate.php"
URL="http://localhost/autoxmlclass/generate.php"
FILENAME_XML=`pwd`"/../example.xml"

echo "URL: " $URL
echo "XML: " $FILENAME_XML
echo "";

# cleanup
echo -n "Remove old zip file ... "
if [ -f src/temp.zip ]; then
	rm src/temp.zip
fi
echo "[OK]";

# download
echo -n "Download sources ... ";
curl -X POST \
	--no-progress-bar \
	-o src/temp.zip \
	-F input_xml=@$FILENAME_XML \
	-F namespace=example \
	-F output_lang=cpp_qt_useqxml \
	$URL 2> /dev/null
if [ ! -f src/temp.zip ]; then
	echo "[FAIL]"
	exit
fi
echo "[OK]";

# cleanup
echo -n "Remove old source files ... "
if [ -f src/example.h ]; then 
	rm src/example.h 
fi

if [ -f src/example.cpp ]; then 
	rm src/example.cpp 
fi
echo "[OK]";

# unpack
echo -n "Unpack zip-file ... "
cd src
unzip temp.zip > /dev/null
rm temp.zip
cd ..
echo "[OK]";



echo -n "Cleanup binary 'autoxmlclass' ... "
if [ -f autoxmlclass ]; then 
	rm autoxmlclass
fi
if [ -f Makefile ]; then 
	rm Makefile
fi
echo "[OK]";

echo -n "Compile ... "
qmake autoxmlclass.pro
make > compile.log 2> error.log

if [ ! -f autoxmlclass ]; then
	echo "[FAIL]";
	cat error.log
	exit;
fi
echo "[OK]";

echo -n "Run app ... "
./autoxmlclass ../example.xml
echo "[OK]";
