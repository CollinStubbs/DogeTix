#!/bin/bash

# make all scripts executable
echo $'\n'
echo "**********RUNNING ALL FRONT END TESTS**********"
echo $'\n'
# test login test cases
echo "RUNNING login_first_transaction TO GENERATE A SUCCESSFUL LOGIN"
./inputs/login_testscripts/login_first_transaction.sh > ./outputs/actual_login_test_outputs/login_first_transaction.txt

clear
echo "RUNNING login_first_transaction TO GENERATE AN ERROR"
./inputs/login_testscripts/login_first_transaction_error.sh > ./outputs/actual_login_test_outputs/login_first_transaction_error.txt

clear 
echo "RUNNING login_sublogin TO GENERATE AND ERROR IN TRYING TO LOGIN AGAIN"
./inputs/login_testscripts/login_sublogin.sh > ./outputs/actual_login_test_outputs/login_sublogin.txt

clear
echo "RUNNING login_unpriv TO PERFORM PRIVILAGED TRANSACTION ON UNPRIVILAGED USERNAME"
./inputs/login_testscripts/login_unpriv.sh > ./outputs/actual_login_test_outputs/login_unpriv.txt

clear
echo "RUNNING login_priv TO PERFORM PRIVILAGED TRANSACTION ON PRIVILAGED USERNAME"
./inputs/login_testscripts/login_priv.sh > ./outputs/actual_login_test_outputs/login_priv.txt


# Test logout test cases
clear
echo "RUNNING login_valid TO GENERATE ERROR WHEN LOGOUT IS FIRST COMMAND"
./inputs/logout_testscripts/logout_valid.sh > ./outputs/actual_logout_test_outputs/logout_valid.txt

clear
echo "RUNNING login_no_transactions TO TEST THAT NO TRANSACTIONS ARE ACCEPTED AFTER logout"
./inputs/logout_testscripts/logout_no_transactions.sh > ./outputs/actual_logout_test_outputs/logout_no_transactions.txt

clear 
echo "RUNNING COMPARISONS TO CHECK EXPECTED OUTPUT VS ACTUAL OUTPUT"
for f in /expectedOutputs/expected_login_test_outputs/*.txt ; do echo "Comparison test for $f"; diff /expectedOutputs/expected_login_test_outputs/$f /outputs/actual_login_test_outputs/$f; done