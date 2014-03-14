#!/bin/bash

# make all scripts executable
chmod +x ./login_testscripts/'*'.sh 
echo "RUNNING ALL FRONT END TESTS"
echo $'\n'
echo "RUNNING login_first_transaction TO GENERATE A SUCCESSFUL LOGIN"
./login_testscripts/login_first_transaction.sh
echo $'\n'
echo "RUNNING login_first_transaction TO GENERATE AN ERROR"
./login_testscripts/login_first_transaction_error.sh
echo $'\n'
echo "RUNNING login_sublogin TO GENERATE AND ERROR IN TRYING TO LOGIN AGAIN"
./login_testscripts/login_sublogin.sh
echo $'\n'
echo "RUNNING login_unpriv TO PERFORM PRIVILAGED TRANSACTION ON UNPRIVILAGED USERNAME"
./login_testscripts/login_unpriv.sh