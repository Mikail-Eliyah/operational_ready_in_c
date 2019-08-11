#!/bin/sh
# version: 2019-06-09_1156hr_48sec

# include configuration file (containing variables)
dos2unix "./config.sh"
source "./config.sh"

# dos2unix "./scripts/cipher_utility.sh"
# source "./scripts/cipher_utility.sh" # 

function print_menu() {
	echo "Press 1 : make_clean"
	echo "Press 2 : compile"
	echo "Press 3 : compile_and_run"
	echo "Press 4 : instruction_for_users"	
	
	echo "Press 'x' or 'X' to exit the script"
}

function make_clean(){
	echo $demarcator
	make clean;
	echo $demarcator
}

function compile_and_run(){
	echo $demarcator
	make clean;
	make run;
	echo $demarcator
}

function compile(){
	echo $demarcator
	make;
	echo $demarcator
}

function instruction_for_users(){
	echo "
	=================== INSTRUCTION START ===================
	[Caveat]: For reference purposes only.
	
	[Notes]:
	1. block_function_from_proceding() is a function to disable function. Comment it to deactivate / unblock it.
	2. Do update config.sh to ensure you have all the supporting parameters.
	3. Usage : semi-automate make clean, compile, and run.
	
	=================== INSTRUCTION END ===================
	"
}

function block_function_from_proceding(){
	echo "This function is prohibited for now."
	exit;
	echo 'If you are seeing this line. The exit() is not working.'
}

function exit_program() {
	printf "\n quit.\n"
	echo 'X' : quitprogram
}

function default_action() {
    echo "You have entered an invallid selection!"
    echo "Please try again!"
    echo ""
    echo "Press any key to continue..."
    read -n 1
    clear
	set -u # force it to treat unset variables as an error 
	unset mainmenuinput
	#echo $mainmenuinput 
    main
}