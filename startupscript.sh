#!/bin/bash

echo "Hello! I'm Aiden! How are you?"
#run voice recognition in the background

export LD_LIBRARY_PATH=/usr/local/lib
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig

pocketsphinx_continuous -inmic yes&
#wake up Aiden and run him as a background process
Aiden -handler Andrew -password INSERTPASSWORD
#INSERTPASSWORD TO BE CHANGED WHEN YOU ACTUALLY IMPLEMENT PASSWORD PROTECTION
