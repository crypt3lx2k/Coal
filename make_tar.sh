#! /bin/bash

autoreconf -fi &&
./configure &&
make distcheck &&
make distclean &&
env rm -rf `xargs < .gitignore` &&
cd m4/ &&
env rm -rf `xargs < .gitignore` &&
cd ..
