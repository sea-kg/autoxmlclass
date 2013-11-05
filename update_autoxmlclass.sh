if [ ! -d "autoxmlclass.git" ]; then
   git clone https://github.com/sea-kg/autoxmlclass.git autoxmlclass.git
fi

if [ -d "autoxmlclass.git" ]; then
   cd autoxmlclass.git
   git checkout .
   git pull
   cd ..
fi

# update php
if [ -f "autoxmlclass.git/update.sh" ]; then
   cd autoxmlclass.git
   ./update.sh
fi

