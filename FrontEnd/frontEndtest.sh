#!/bin/bash

# make all scripts executable
echo $'\n'
echo "**********RUNNING ALL FRONT END TESTS**********"
echo $'\n'
# test login test cases
echo "RUNNING login_first_transaction TO GENERATE A SUCCESSFUL LOGIN"
./inputs/login_testscripts/login_first_transaction.sh

echo $'\n'
echo "RUNNING login_first_transaction TO GENERATE AN ERROR"
./inputs/login_testscripts/login_first_transaction_error.sh

echo $'\n'
echo "RUNNING login_sublogin TO GENERATE AND ERROR IN TRYING TO LOGIN AGAIN"
./inputs/login_testscripts/login_sublogin.sh

echo $'\n'
echo "RUNNING login_unpriv TO PERFORM PRIVILAGED TRANSACTION ON UNPRIVILAGED USERNAME"
./inputs/login_testscripts/login_unpriv.sh

echo $'\n'
echo "RUNNING login_priv TO PERFORM PRIVILAGED TRANSACTION ON PRIVILAGED USERNAME"
./inputs/login_testscripts/login_priv.sh


# Test logout test cases
echo $'\n'
echo "RUNNING login_valid TO GENERATE ERROR WHEN LOGOUT IS FIRST COMMAND"
./inputs/logout_testscripts/logout_valid.sh

echo $'\n'
echo "RUNNING login_no_transactions TO TEST THAT NO TRANSACTIONS ARE ACCEPTED AFTER logout"
./inputs/logout_testscripts/logout_no_transactions.sh
