#!/bin/bash

# make all scripts executable
echo "Running all front end tests"

echo $'\n'
echo "Running login_first_transaction"
./login_first_transaction.sh
echo $'\n'
echo "Running login_first_transaction to generate an error"
./login_first_transaction_error.sh
echo $'\n'
echo "Running login_sublogin to generate an error"
./login_sublogin.sh