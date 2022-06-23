# Annual-Compound-Interest-Calculator
CS210_Project2
<br>
<br>
What did you do particularly well?<br>
Successful in creating working code that calculates interest based on user input.<br><br>
Where could you enhance your code?<br>
Code enhancement will be on going.  Code standardization will be an area of improvement.<br>
<br>
Which pieces of the code did you find most challenging to write, and how did you overcome this?<br>
Most challenging would be using the differnt loops. <br>
I was able to overcome the challenge of using different loops to display calculations and print statements. <br>
<br>
What skills from this project will be particularly transferable to other projects or course work?<br>
Continuing to work on foundation skills from this project will be particularly transferable to other projects and course work.<br>
<br>
The program is maintainable, readable, and adaptable through the use of in-line comments.<br>
<br>



=========================================================================
<br>
Project Description
<br>=========================================================================
Airgead Banking wants a screen to display with the following information:

• Initial Investment Amount: The starting amount of your investment (a positive real number) <br>
• Monthly Deposit: The amount you plan to contribute to the growth of your investment each month (a positive real number)<br>
• Annual Interest (Compounded): Interest that is added to the principal sum of your investment and its previously accumulated interest (interest on interest and principal)<br>
• Number of Years: The number of years your investment has to grow <br>
• A way to see the data (for example: “Press any key to continue…”)<br>


When the user continues, the console should display two static reports. One should show the <br>
year-end balances and year-end earned interest if no additional monthly deposits are made. The <br>
second should show the year-end balances and year-end earned interest based on the monthly <br>
deposit value that was input by the user ($50.00 in this example). The following is an example of <br>
what your interface might look like. It is in no way representative of what it must look like. Be <br>
creative and keep the user experience in mind when designing your solution<br>


code will need to account for the following:<br>
a. <b>Month:</b> The number of months based on user input in the “Number of Years” field<br>
b. <b>Opening Amount:</b> The initial investment amount as well as the opening balance each <br>
month, which includes interest<br>
c. <b>Deposited Amount:</b> The dollar amount the user plans to deposit each month. This value <br>
will be the same every month for the duration of the investment. <br>
d. <b>Total:</b> The sum of the opening and deposited amounts<br>
e. <b>Interest:</b> Money earned based on the “annual interest” rate input by the user. The <br>
interest based on an opening amount of $1 and a deposited amount of $50 with an<br> 
interest rate of 5% compounded monthly is:<br>
<br>
(Opening Amount + Deposited Amount) * ((Interest Rate/100)/12) <br>OR <br>(1 + 50) * ((5/100)/12) <br>
<br>
  <b>Note:</b> Dividing by 100 converts the interest rate percentage to a decimal.<br>
<br>
  <b>Note:</b> 12 is the number of months in a year. Dividing the yearly amount by twelve gives <br>
monthly compounded interest.<br>
<br>
f. <b>Closing Balance:</b> The sum of the total and interest amounts<br>
