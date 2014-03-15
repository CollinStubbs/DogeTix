#!/bin/bash

# make all scripts executable
echo $'\n'
echo "**********RUNNING ALL FRONT END TESTS**********"
echo $'\n'
# test login test cases
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
echo $'\n'
# Test logout test cases
echo "RUNNING login_valid TO GENERATE ERROR WHEN LOGOUT IS FIRST COMMAND"
./logout_testscripts/logout_valid.sh
echo $'\n'
echo "RUNNING login_no_transactions TO TEST THAT NO TRANSACTIONS ARE ACCEPTED AFTER logout"
./logout_testscripts/logout_no_transactions.sh
