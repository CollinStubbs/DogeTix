DogeTix
=========

A ticket selling service developed using Extreme Programming methods for our Software Quality Assurance Course

Project Details

Front End:
- built in C++
- reads in a file of tickets available for purchase and file containing info with current user accounts in the system
- process a stream of ticket purchases and sale transactions at one time
- writes out a file of ticket purchase and sale transactions at the end of the sessions

Back End:
- built in Java
- reads in the previous day's user accounts file and available tickets file and then applies all of the daily transactions from a merged set of daily transaction files to these files
- this produces a new Current User Accounts file and a new Available Tickets File for tomorrow's Front End Runs

How to use:

Compile and run using make

      $ make 
      $ make run
      
How to test properly:

      $ make test

How to contribute:
- If you would like to add a feature create a branch from master and develop on that branch
- test it before merging with master this ensures that there won't be any errors with the master branch
     

