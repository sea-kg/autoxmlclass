#!/bin/bash

URL="http://localhost/autoxmlclass/"

# refresh example.xml
if [ -f "example.xml" ]; then
	rm example.xml
fi
wget $URL/example.xml

cd cpp_qt_useqxml
./run_test.sh
cd ..
