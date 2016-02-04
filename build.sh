#!/bin/sh
#set -e
# Any subsequent commands which fail will cause the shell script to exit immediately

EPICS_ROOT=/usr/local/epics

# get your distro
printf " _____________________________________\n"
printf "| please choose your GNU/Linux Distro |\n"
printf "|_____________________________________|\n"
printf "1-Ubuntu \n2-Centos/Fedora \n3-Debian \n4-Install without packages\n"
printf "****************************\n"
read DISTRO

if [ $DISTRO -eq 1 ]; then
	echo "UBUNTU"
	echo "first build packages"
	sudo apt-get install gcc libreadline-dev g++ libperl libperl-dev

elif [ $DISTRO -eq 2 ]; then
	echo "centos / fedora"
	
	echo -e "first build packages"
	sudo yum install gcc gcc-c++ readline-devel
	sudo yum install perl-devel perl-Pod-Checker
	sudo rpm -ivh http://pkgs.repoforge.org/re2c/re2c-0.13.5-1.el6.rf.x86_64.rpm

elif [ $DISTRO -eq 3 ]; then
	echo "debian"
	echo "first build packages"
	sudo apt-get install gcc gcc-c++ libreadline-dev
elif [ $DISTRO -eq 4 ]; then
        echo "compiling without distro packages"
else 
	echo "i didnt get it what you mean"
fi




printf "*************** BUILDING EPICS BASE ***************\n"
read -p "Do you want install base? " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]] 
then

	printf " Choose EPICS Base Version\n"
	printf "1 - Base 3.15.2 \n2 - Base R3.14.12.4 \n"
	read BASE_VER

		if [ $BASE_VER -eq 1 ]; then
			rm -rf base
			sudo ln -s base-3.15.2/ base

		elif [ $BASE_VER -eq 2 ]; then
			rm -rf base
			sudo ln -s base-3.14.12.4/ base
	
		else 
			echo "i didnt get it what you mean\n"
		fi

	cd base
	sudo make
fi

echo "build modules..."

printf "*******************  VDCT  ************************\n"
read -p "Do you want install VDCT? " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]] 
then

	cd $EPICS_ROOT
	cd modules/vdct
	sudo chmod +x vdct
	sudo cp vdct /usr/bin/
	cd $EPICS_ROOT
fi
#echo $(tput setaf 1)"CSS"$(tput sgr 0)
#sudo chmod +x css
#sudo cp css /usr/bin/

printf "*******************  SEQUENCER  ************************\n"
read -p "Do you want install SEQUENCER? " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]] 
then
	cd $EPICS_ROOT
	cd modules/seq-2.1.10
	sudo make
	cd $EPICS_ROOT
fi

printf "*******************  ASYN  ************************\n"
read -p "Do you want install ASYN? " -n 1 -r
echo

if [[ $REPLY =~ ^[Yy]$ ]] 
then
	cd $EPICS_ROOT
	cd modules/asyn4-23
	sudo make
	cd $EPICS_ROOT
fi

echo "all done!\n"



