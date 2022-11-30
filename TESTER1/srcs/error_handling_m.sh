# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_handling_m.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsmitsom <nsmitsom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 14:44:56 by ael-bekk          #+#    #+#              #
#    Updated: 2022/10/25 13:00:06 by nsmitsom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

l1="======================================================================================="
l2="---------------------------------------------------------------------------------------"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
WHITE="\033[1;37m"
RESET="\033[0m"


echo -e "\n\n\n\n${GREEN}test error handling on one pipe :${RESET}"
echo -e "$RED$l2$RESET"

make fclean -C ..

echo -e "${YELLOW}[make] :${RESET} your pipex : ${PURPLE}Mandatory${RESET}"
make -C ../
echo -e "$RED$l2$RESET"

if ! [ -f "$1" ]
then
	echo -e "${YELLOW}Error :${RESET} No such file or directory: ${PURPLE}pipex${RESET}\n" >&2 ; exit
fi

echo -e "sgfefeqd qwdqwdddafasd s+64 65 30 9 2 92 ad asd asd as d asd\n asdasd a dasd sd \n asdasd asdasd asd asd\n asdqpkqwd ew eqckqwxqwx qw \n qfqwodeqm domw	m	\tefeqc eqew cewx ewc ewc ewc wc ew" > in_file

timeout() {
    ( $1 "$2" "$3" "$4" "$5" ) 2> my_error & pid=$!
    ( sleep 3 && kill -HUP $pid ) 2>/dev/null & watcher=$!
    if wait $pid 2>/dev/null; then
        status_code=$?
        status="finished"
        pkill -HUP -P $watcher
        wait $watcher
    else
        status_code=$?
        status="interrupted"
    fi
}

timeout2() {
    ( $1 "$2" "$3" "$4" "$5" ) 2> my_error & pid=$!
    ( sleep 12 && kill -HUP $pid ) 2>/dev/null & watcher=$!
    if wait $pid 2>/dev/null; then
        status_code=$?
        status="finished"
        pkill -HUP -P $watcher
        wait $watcher
    else
        status_code=$?
        status="interrupted"
    fi
}

touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 1${RESET}"
printf "${WHITE}\t< non_exist_input cat /dev/random | wc                                           : ${RESET}"
timeout "$1" "in_filewgwg" "cat /dev/random" "wc" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory"`
if [ "$status" = "finished" ] && [ "$find_smae_err" != "" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7
touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 2${RESET}"
printf "${WHITE}\t< exist_input catds /dev/random | ls                                             : ${RESET}"
timeout "$1" "in_file" "catds /dev/random" "ls" "outfile"
find_smae_err=`cat my_error | grep -a "command not found\|Command not found" | wc -l`
ls > outfile2
different=`diff outfile outfile2`
if [ "$status" = "finished" ] && [ "$find_smae_err" -eq "1" ] && [ "$different" = "" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7
touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 3${RESET}"
printf "${WHITE}\t< non_exist_input ls | wc                                                        : ${RESET}"
timeout "$1" "/in_filedfsddsf" "ls" "wc" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory"`
#printf "" > vide
#< vide wc > outfile2
< /dev/null wc > outfile2 
different=`diff outfile outfile2`
if [ "$status" = "finished" ] && [ "$find_smae_err" != "" ] && [ "$different" = "" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7
touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 4${RESET}"
printf "${WHITE}\t< exist_input csdfat | wsdfc -cl                                                 : ${RESET}"
timeout "$1" "in_file" "cafat" "sdfwc -cl" "outfile"
find_smae_err=`cat my_error | grep -a "command not found\|Command not found" | wc -l`
if [ "$status" = "interrupted" ] && [ "$find_smae_err" -eq "2" ]  && [ "$status_code" -eq "127" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n" "$status" y "$status_code" x "$find_smae_err"
fi
sleep 0.7
touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 5${RESET}"
printf "${WHITE}\t< non_exist_input /bin/catsdc | wcss -cl                                         : ${RESET}"
timeout "$1" "in_fisdle" "/bin/catsdc" "wcss -cl" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
find_smae_err2=`cat my_error | grep "command not found\|Command not found" | wc -l`
if [ "$status" = "interrupted" ] && [ "$find_smae_err" -eq "1" ] && [ "$find_smae_err2" -eq "1" ] && [ "$status_code" -eq "127" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7
touch in_file1
touch outfile2
echo -e "${PURPLE}==============>Test 6${RESET}"
printf "${WHITE}\t< non_exist_input sleep 9 | sleep 4                                              : ${RESET}"
SECONDS=0;
timeout2 "$1" "in_ffdgile" "sleep 9" "sleep 4" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
if [ "$status" = "finished" ] && [ "$SECONDS" -ge "4" ] && [ "$SECONDS" -le "5" ] && [ "$find_smae_err" -eq "1" ]
then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n" "$SECONDS"
fi
sleep 0.7


touch outfile2
echo -e "${PURPLE}==============>Test 7${RESET}"
printf "${WHITE}\t< exist_input /bin/caqwdt  | /bin/lsqwd -ls                                      : ${RESET}"
timeout "$1" "in_file" "/bin/caqwdt" "/bin/lsqwd -ls ../" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
if [ "$status" = "interrupted" ] && [ "$find_smae_err" -eq "2" ] && [ "$status_code" -eq "127" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7

touch outfile2
echo -e "${PURPLE}==============>Test 8${RESET}"
printf "${WHITE}\t< exist_input /srcs/a.out  | ls                                                  : ${RESET}"
timeout "$1" "in_file" /srcs/a.out "ls" "outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
ls > outfile2
different=`diff outfile outfile2`
if [ "$status" = "finished" ] && [ "$find_smae_err" -eq "1" ] && [ "$different" = "" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7

touch outfile2
echo -e "${PURPLE}==============>Test 9${RESET}"
printf "${WHITE}\t< exist_input /bin/caqwdt  | /bin/lsqwd -ls > nodir/outfiile                     : ${RESET}"
timeout "$1" "in_file" "/bin/caqwdt" "/bin/lsqwd -ls ../" "nodir/outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
find_smae_err2=`cat my_error | grep "command not found\|Command not found" | wc -l`
if [ "$status" = "interrupted" ] && [ "$find_smae_err" -eq "2" ]  && [ "$find_smae_err2" -eq "0" ] && [ "$status_code" -eq "1" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7

touch outfile2
echo -e "${PURPLE}==============>Test 10${RESET}"
printf "${WHITE}\t< exist_input caqwdt  | lsqwd -ls ../ > nodir/outfiile                           : ${RESET}"
timeout "$1" "in_file" "caqwdt" "lsqwd -ls ../" "nodir/outfile"
find_smae_err=`cat my_error | grep -a "no such file or directory\|No such file or directory" | wc -l`
find_smae_err2=`cat my_error | grep "command not found\|Command not found" | wc -l`
if [ "$status" = "interrupted" ] && [ "$find_smae_err" -eq "1" ]  && [ "$find_smae_err2" -eq "1" ] && [ "$status_code" -eq "1" ]
    then
    echo -e "${GREEN}[OK]${RESET}\n"
else
    echo -e "${RED}[KO]${RESET}\n"
fi
sleep 0.7
