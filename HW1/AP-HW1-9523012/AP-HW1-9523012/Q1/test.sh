#!/bin/sh

#Getting username
read -p "Username: " user

while [ 1 ]
do
     #Getting password
     read -p "Password: " pass
     #Checking if password is APNew or not
    if [ $pass = "APNew" ]
     then
	 echo -n "Thank you $user we now have your login details\n"
	 break
     else
	 echo -n "Wrong password!\n"
     fi
done

#Getting 1 or 2
echo  Hi, $user
read -p "Please Enter 1 or 2: " ch
#Checking if it's 1 or 2

while [ 1 ]
do
    if [ $ch = '1' ]
    then
	#Making folder and cpp file in it
	mkdir AP2018
	cd AP2018
	touch Hello.cpp
fi

    #Exit from terminal if ch is 1 or 2
    if [ $ch = '1' ] || [ $ch = '2' ]
    then
	exit
    else
	read -p "Wrong character! Please Enter 1 or 2: " ch
    fi
done

