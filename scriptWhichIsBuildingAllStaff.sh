#!/bin/sh
set -e
# Any subsequent commands which fail will cause the shell script to exit immediately

# get your distro
echo "please enter your GNU/Linux Distro"
echo "1-ubuntu 2-centos 3-debian"
read DISTRO

if [ $DISTRO -eq 1 ]; then
	echo "UBUNTU"
	echo "first build packages"
	sudo apt-get install gcc libreadline-dev g++ libperl libperl-dev

elif [ $DISTRO -eq 2 ]; then
	echo "centos"
	
	echo -e "first build packages"
	sudo yum install gcc gcc-c++ readline-devel
	sudo rpm -ivh http://pkgs.repoforge.org/re2c/re2c-0.13.5-1.el6.rf.x86_64.rpm

elif [ $DISTRO -eq 3 ]; then
	echo "debian"
	echo "first build packages"
	sudo apt-get install gcc gcc-c++ libreadline-dev
else 
	echo "i didnt get it what you mean"
fi





echo "build epics base"
cd base
sudo make

echo "build modules..."

echo "vdct"
cd ..
cd modules/vdct
sudo chmod +x vdct
sudo cp vdct /usr/bin/
cd ..

#echo $(tput setaf 1)"CSS"$(tput sgr 0)
#sudo chmod +x css
#sudo cp css /usr/bin/

echo "sequencer"
cd seq-2.1.10
sudo make
cd ..

echo "asyn"
cd asyn4-23
sudo make

echo "all done!"



