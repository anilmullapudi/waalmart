# waalmart
This application is for sharing waalmart bill among roomates.

usage:
1) Add the roommate names in the conf/Names.text
   for example: 
	Anurag
	Anil
	Abhinay
	Bhushan
	Srikesh

2) go to cloned directory that waalmart and compile using the following command.

   g++ Waalmart_Client.cpp Waalmart.cpp waalmart.h -std=c++11

3) run the app using ./a.out

   now you can enter the price value that you want to share between roommates.
   and provide the roomate numbers for the roommates who involved in that billing.
   
   enter price of item or -99:rollback -100:quit
   
   300
   
   Enter roomate id's  1-Anurag, 2-Anil, 3-Abhinay, 4-Bhushan, 5-Srikesh
   a-all
   
   123   #That's it, the price is now shared between Anurag, Ani, and Abhinay.
