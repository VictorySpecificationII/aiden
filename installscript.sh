echo "Hey - hi! My name is Aiden."
sleep 1
echo "To live on your system, I depend on some things. I'll sort them out, don't worry. Sit and relax :) "
sleep 1
echo "Taking care of dependencies..."
apt-get update --fix-missing
apt-get install -y libtool automake autoconf gcc bison swig python-dev libpulse-dev
sleep 1
echo "Alrighty, dependencies are taken care off. Now I can live. I need to fetch my base from the internet. Uno momento por favore..."
sleep 1
echo "Done. Unpacking..."
sleep 1
wget http://netassist.dl.sourceforge.net/project/cmusphinx/sphinxbase/5prealpha/sphinxbase-5prealpha.tar.gz
sleep 1
echo"Done. Unpacking..."
sleep 1
tar -xvzf sphinxbase-5prealpha.tar.gz 
"Done. All unpacked. One last thing I need, to fetch pocketsphinx from the internet. Will only take a second..."
sleep 1
wget http://netix.dl.sourceforge.net/project/cmusphinx/pocketsphinx/5prealpha/pocketsphinx-5prealpha.tar.gz
sleep 1
echo "Done. Unpacking..."
sleep 1
tar -xzvf pocketsphinx-5prealpha.tar.gz 
sleep 1
"Done. All unpacked."
echo "Installing..."
sleep 1

#installing sphinxbase
cd sphinxbase-5prealpha
./autogen.sh 
./configure
make
make install
export LD_LIBRARY_PATH=/usr/local/lib
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

#installing pocketsphinx
cd ..
cd /pocketsphinx-5prealpha/
./autogen.sh
./configure
make
make install

sleep 2
"Done, now I can understand you. If you want to try me, type pocketsphinx_continuous -inmic yes . I'll go grab a byte, I'm hungryyy"

