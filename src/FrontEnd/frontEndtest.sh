#!/bin/bash

#########################################
# HARDCODING FTW!
# -hardcoded testing and comparing for now
# -will change this later 
#########################################

# make all scripts executable
echo $'\n'"**********RUNNING ALL FRONT END TESTS**********"
# make all scripts executable
chmod +x inputs/login_testscripts/*.sh
chmod +x inputs/logout_testscripts/*.sh

# test login test cases
echo "RUNNING login TESTS"
./inputs/login_testscripts/login_first_transaction.sh > ./outputs/actual_login_test_outputs/login_first_transaction.txt
./inputs/login_testscripts/login_first_transaction_error.sh > ./outputs/actual_login_test_outputs/login_first_transaction_error.txt
./inputs/login_testscripts/login_sublogin.sh > ./outputs/actual_login_test_outputs/login_sublogin.txt
./inputs/login_testscripts/login_unpriv.sh > ./outputs/actual_login_test_outputs/login_unpriv.txt
./inputs/login_testscripts/login_priv.sh > ./outputs/actual_login_test_outputs/login_priv.txt
# Test logout test cases
echo "RUNNING logout TESTS"
./inputs/logout_testscripts/logout_valid.sh > ./outputs/actual_logout_test_outputs/logout_valid.txt
./inputs/logout_testscripts/logout_no_transactions.sh > ./outputs/actual_logout_test_outputs/logout_no_transactions.txt
./inputs/logout_testscripts/logout_successful.sh > ./outputs/actual_logout_test_outputs/logout_successful.txt
# Test buy test cases
echo "RUNNING buy TESTS"
./inputs/buy_testscripts/buy_event_check.sh > ./outputs/actual_buy_test_outputs/buy_event_check.txt
./inputs/buy_testscripts/buy_transaction_check.sh > ./outputs/actual_buy_test_outputs/buy_transaction_check.txt
# Test create test cases
echo "RUNNING create TESTS"
./inputs/create_testscripts/create_admin_only.sh > ./outputs/actual_create_test_outputs/create_admin_only.txt
./inputs/create_testscripts/create_all_user_types.sh > ./outputs/actual_create_test_outputs/create_all_user_types.txt
./inputs/create_testscripts/create_new_length.sh > ./outputs/actual_create_test_outputs/create_new_length.txt
./inputs/create_testscripts/create_new_unique.sh > ./outputs/actual_create_test_outputs/create_new_unique.txt
# Test delete test cases
echo "RUNNING delete TESTS"
./inputs/delete_testscripts/delete_not_current_user.sh > ./outputs/actual_delete_test_outputs/delete_not_current_user.txt
./inputs/delete_testscripts/delete_success.sh > ./outputs/actual_delete_test_outputs/delete_success.txt
./inputs/delete_testscripts/delete_test_if_admin.sh > ./outputs/actual_delete_test_outputs/delete_test_if_admin.txt
./inputs/delete_testscripts/delete_valid_username.sh > ./outputs/actual_delete_test_outputs/delete_valid_username.txt
# Test sell test cases
echo "RUNNING sell TESTS"
./inputs/sell_testscripts/sell_event_check.sh > ./outputs/actual_sell_test_outputs/sell_event_check.txt
./inputs/sell_testscripts/sell_event_length.sh > ./outputs/actual_sell_test_outputs/sell_event_length.txt
./inputs/sell_testscripts/sell_ticket_validamount.sh > ./outputs/actual_sell_test_outputs/sell_ticket_validamount.txt
./inputs/sell_testscripts/sell_ticket_validprice.sh > ./outputs/actual_sell_test_outputs/sell_ticket_validprice.txt
./inputs/sell_testscripts/sell_user_check.sh > ./outputs/actual_sell_test_outputs/sell_user_check.txt
# Test refund test cases
echo "RUNNING refund TESTS"
./inputs/refund_testscripts/refund_creditamount_check.sh > ./outputs/actual_refund_test_outputs/refund_creditamount_check.txt
./inputs/refund_testscripts/refund_transaction_check.sh > ./outputs/actual_refund_test_outputs/refund_transaction_check.txt
./inputs/refund_testscripts/refund_transaction_max.sh > ./outputs/actual_refund_test_outputs/refund_transaction_max.txt
./inputs/refund_testscripts/refund_users_check.sh > ./outputs/actual_refund_test_outputs/refund_users_check.txt
# Test addcredit Test cases
echo "RUNNING addCredit TESTS"
./inputs/addCredit_testscripts/addcredit_maxadd_check.sh > ./outputs/actual_addcredit_test_outputs/addcredit_maxadd_check.txt
./inputs/addCredit_testscripts/addcredit_transaction_check.sh > ./outputs/actual_addcredit_test_outputs/addcredit_transaction_check
./inputs/addCredit_testscripts/addcredit_user_check.sh > ./outputs/actual_addcredit_test_outputs/addcredit_user_check
echo $'\n'"TESTING COMPLETE"
#compare logout 
diff outputs/actual_logout_test_outputs/logout_no_transactions.txt expectedOutputs/expected_logout_test_outputs/logout_no_transactions.txt
diff outputs/actual_logout_test_outputs/logout_valid.txt expectedOutputs/expected_logout_test_outputs/logout_valid.txt
diff outputs/actual_logout_test_outputs/logout_successful.txt expectedOutputs/expected_logout_test_outputs/logout_successful.txt
#compare login
diff outputs/actual_login_test_outputs/login_first_transaction_error.txt expectedOutputs/expected_login_test_outputs/login_first_transaction_error.txt
diff outputs/actual_login_test_outputs/login_first_transaction.txt expectedOutputs/expected_login_test_outputs/login_first_transaction.txt
diff outputs/actual_login_test_outputs/login_priv.txt expectedOutputs/expected_login_test_outputs/login_priv.txt
diff outputs/actual_login_test_outputs/login_unpriv.txt expectedOutputs/expected_login_test_outputs/login_unpriv.txt
diff outputs/actual_login_test_outputs/login_sublogin.txt expectedOutputs/expected_login_test_outputs/login_sublogin.txt
#compare buy
diff outputs/actual_buy_test_outputs/buy_event_check.txt expectedOutputs/expected_buy_test_outputs/buy_event_check.txt
diff outputs/actual_buy_test_outputs/buy_transaction_check.txt expectedOutputs/expected_buy_test_outputs/buy_transaction_check.txt
#compare create
diff outputs/actual_create_test_outputs/create_admin_only.txt expectedOutputs/expected_create_test_outputs/create_admin_only.txt
diff outputs/actual_create_test_outputs/create_all_user_types.txt expectedOutputs/expected_create_test_outputs/create_all_user_types.txt
diff outputs/actual_create_test_outputs/create_new_length.txt expectedOutputs/expected_create_test_outputs/create_new_length.txt
diff outputs/actual_create_test_outputs/create_new_unique.txt expectedOutputs/expected_create_test_outputs/create_new_unique.txt
#compare delete
diff outputs/actual_delete_test_outputs/delete_not_current_user.txt expectedOutputs/expected_delete_test_outputs/delete_not_current_user.txt
diff outputs/actual_delete_test_outputs/delete_success.txt expectedOutputs/expected_delete_test_outputs/delete_success.txt
diff outputs/actual_delete_test_outputs/delete_test_if_admin.txt expectedOutputs/expected_delete_test_outputs/delete_test_if_admin.txt
diff outputs/actual_delete_test_outputs/delete_valid_username.txt expectedOutputs/expected_delete_test_outputs/delete_valid_username.txt
#compare sell
diff outputs/actual_sell_test_outputs/sell_event_check.txt expectedOutputs/expected_sell_test_outputs/sell_event_check.txt
diff outputs/actual_sell_test_outputs/sell_event_length.txt expectedOutputs/expected_sell_test_outputs/sell_event_length.txt
diff outputs/actual_sell_test_outputs/sell_ticket_validamount.txt expectedOutputs/expected_sell_test_outputs/sell_ticket_validamount.txt
diff outputs/actual_sell_test_outputs/sell_ticket_validprice.txt expectedOutputs/expected_sell_test_outputs/sell_ticket_validprice.txt
diff outputs/actual_sell_test_outputs/sell_user_check.txt expectedOutputs/expected_sell_test_outputs/sell_user_check.txt
#compare refund
diff outputs/actual_refund_test_outputs/refund_creditamount_check.txt expectedOutputs/expected_refund_test_outputs/refund_creditamount_check.txt
diff outputs/actual_refund_test_outputs/refund_transaction_check.txt expectedOutputs/expected_refund_test_outputs/refund_transaction_check.txt
diff outputs/actual_refund_test_outputs/refund_transaction_max.txt expectedOutputs/expected_refund_test_outputs/refund_transaction_max.txt
diff outputs/actual_refund_test_outputs/refund_users_check.txt expectedOutputs/expected_refund_test_outputs/refund_users_check.txt
#compare addCredit
diff outputs/actual_addcredit_test_outputs/addcredit_maxadd_check.txt expectedOutputs/expected_addcredit_test_outputs/addcredit_maxadd_check.txt
diff outputs/actual_addcredit_test_outputs/addcredit_transaction_check.txt expectedOutputs/expected_addcredit_test_outputs/addcredit_transaction_check.txt
diff outputs/actual_addcredit_test_outputs/addcredit_user_check.txt expectedOutputs/expected_addcredit_test_outputs/addcredit_user_check.txt

