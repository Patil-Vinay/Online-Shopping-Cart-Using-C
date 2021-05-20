    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<time.h>

    //Initializing all variables
    static int totalCost;
    int i,j,choice_no,s_m,money,c=1,a[20],tc[20],cost[20],discount[20],grocery_no,electronics_no,fashion_no,sportsequipments_no,books_no;
    int ten_pos,unit_pos,hund_pos,thous_pos,ten_thous_pos,lakh_pos,ten_lakhs_pos;
    char str[100];

    // Declaring all functions which we have used in our code
    void greetings();void mainmenu(); void choice();void viewcart(); void deleteitem(); void deleteitem1(); void checkout(); void totalcost(); void saved_money();
    void grocery(); void menugrocery(); void groceryitems();
    void electronics(); void menuelectronics(); void electronicsitems();
    void fashion(); void menufashion(); void fashionitems();
    void sportsequipments(); void menusportsequipments(); void sportsequipmentsitems();
    void books(); void menubooks(); void booksitems();

    //Initializing 1-D array for category, items and price
    char *category[20] = {"Grocery","","","","Electronics","","","","Fashion","","","","Sports Equipments","","","","Books","","",""};
    char *items[20] = {"Amul Milk","Real Fruit Juice","Doritos Chips","Nestle Ketchup","Apple Airpods","Apple iPhone 12","Sony 4K TV","Apple iWatch Series 6","Dior Sunglasses","Addidas Cap/Hat","Nike Shoes","Under Armour Hoodie","Nivia Football","Nike Studs","MRF Bat","Nivia Basketball","Essential C","Let Us C","ANCI C","Modern C"};
    int price[20] = {40,100,50,200,20000,50000,20000,30000,1200,400,20000,6000,400,7000,5000,700,300,460,600,550};
    char *digit_word[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    char *tens_word[8] = {"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    char *ten_nineteen[10] = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};


    int main()
    {
        greetings();//Salutations for the user
        for(i=0;i<20;i++)//Making all the quantities zero of all items
            {
                a[i]=0;
            }

        printf("\nEnter Your Name: ");
        scanf("%s",&str);
        printf("\nHello %s, Welcome to The Digital Outlet.\n",str);

        //Here we will be printing all the categories/items included with price from which user can choose to buy items
        printf("\n                     Items And Category Menu                         \n");
        printf("\n------------------------------------------------------------------");
        printf("\nSr.No.    Category             Items                         Price");
        printf("\n------------------------------------------------------------------");
        int z;
        for(z=0;z<4;z++)
        {
        printf("\n%-10d%-21s%-30s%5d",(z+1),category[z],items[z],price[z]);
        }
        printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        for(z=4;z<8;z++)
        {
        printf("\n%-10d%-21s%-30s%5d",(z+1),category[z],items[z],price[z]);
        }
        printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        for(z=8;z<12;z++)
        {
        printf("\n%-10d%-21s%-30s%5d",(z+1),category[z],items[z],price[z]);
        }
        printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        for(z=12;z<16;z++)
        {
        printf("\n%-10d%-21s%-30s%5d",(z+1),category[z],items[z],price[z]);
        }
        printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        for(z=16;z<20;z++)
        {
        printf("\n%-10d%-21s%-30s%5d",(z+1),category[z],items[z],price[z]);
        }
        printf("\n-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
        mainmenu();

    }

    void greetings() //Reading time from the system and greeting the user according to the time
    {
        //Initializing variable
        time_t s, val;
        struct tm* current_time;
        s = time(NULL);
        current_time = localtime(&s);
        val =(current_time->tm_hour);
        if(6<=val && val<12){
            printf("Good Morning,\n");
        }
        else if(12<=val && val<17){
            printf("Good Afternoon,\n");
        }
        else if(17<=val && val<=23){
            printf("Good Evening,\n");
        }
        else{
            printf("Still Up! Good to see you at this Time!!!\n");
        }
    }

    void viewcart() //This function used to show user the cart in middle of buying items and can check out or delete items after taking a look at it
    {
        if(a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0 || a[4]!=0 || a[5]!=0 || a[6]!=0 || a[7]!=0 || a[8]!=0 || a[9]!=0 || a[10]!=0 || a[11]!=0 || a[12]!=0 || a[13]!=0 || a[14]!=0 || a[15]!=0 || a[16]!=0 || a[17]!=0 || a[18]!=0 || a[19]!=0 ){
                printf("\n%s's cart\n\n",str);
                printf("\n-----------------------------------------------------------------------------------------------------");
                printf("\nId      Items                             Quantity           Rate          Discount             Price");
                printf("\n-----------------------------------------------------------------------------------------------------");
                for(i=0;i<20;i++)
                {
                    if(a[i] != 0){
                        printf("\n%-8d%-34s%-19d%-14d%-4d%%%21d\n",i,items[i],a[i],cost[i],discount[i],tc[i]);
                    }
                }
                totalcost();
                printf("\n");
                printf("                                                                      Total Cost=%20d\n",totalCost);
            }
        else{
                printf("\nYOUR CART IS EMPTY!!!!\n");
            }
        printf("Enter \n1 - Go Back to Category Menu/Main menu\n2 - Delete Item\n3 - Check Out\n");
        printf("\nEnter number from above menu wherever you want to go: ");
        scanf("%d",&c);
        if(c==1){
            mainmenu();
        }
        else if(c==2){
            deleteitem1();
        }
        else if(c==3){
            checkout();
            }
        else{
            printf("\nInvalid Input!!\n");
            mainmenu();
        }

    }

    void mainmenu() //Main menu where all categories are listed and to view cart,delete item and check out
    {
        printf("\n\nCategories:\n1 - Grocery\n2 - Electronics\n3 - Fashion\n4 - Sports Equipments\n5 - Books\n\nHead Out towards View Cart/Check Out:\n6 - View Cart\n7 - Delete Item\n8 - Check Out\n");
        printf("\nEnter number where you want to be navigated: ");
        scanf("%d",&choice_no);
        choice();
    }
    void choice(){ //Choice function is used to navigate the user to specific category
        switch(choice_no)
        {
            case 1://User chose 1 he will be navigated to grocery category
                {
                    groceryitems(); //Grocery function which contains all grocery items
                    break;
                }
            case 2://User chose 2 he will be navigated to electronics category
                {
                    electronicsitems();
                    break;
                }
            case 3://User chose 3 he will be navigated to fashion category
                {
                    fashionitems();
                    break;
                }
            case 4://User chose 4 he will be navigated to sports equipment category
                {
                    sportsequipmentsitems();
                    break;
                }
            case 5://User chose 5 he will be navigated to books category
                {
                    booksitems();
                    break;
                }
            case 6://User chose 6 he will be navigated to view cart
                {
                    viewcart(); //View cart function which will show all the items in cart and its total cost
                    break;
                }
            case 7://User chose 7 for check out
                {
                    deleteitem(); //checkout function which will show the items list and final cost with offers and discounts
                    break;
                }
            case 8://User chose 7 for check out
                {
                    checkout(); //checkout function which will show the items list and final cost with offers and discounts
                    break;
                }
            default:{
                printf("\nEnter Valid Categories Choice\n"); //If user give different number this statement will be printed
                mainmenu();
                break;
                }
        }

    }

    void deleteitem()//Here we will check the quantity if the quantity is zero it will show your cart is empty, if items are present it will show the id of items and items with total cost and price
    {
        for(i=0;i<20;i++)
            {
                if(a[i]!=0)
                    {
                        printf("\n");
                        printf("%s's cart\n",str);
                        printf("\n");
                        printf("\n-----------------------------------------------------------------------------------------------------");
                        printf("\nId      Items                             Quantity           Rate          Discount             Price");
                        printf("\n-----------------------------------------------------------------------------------------------------");
                        for(i=0;i<20;i++)
                        {
                            if(a[i] != 0){
                                printf("\n%-8d%-34s%-19d%-14d%-4d%%%21d\n",i,items[i],a[i],cost[i],discount[i],(cost[i]*a[i])-(cost[i]*a[i]*discount[i]/100));
                            }

                        }
                        totalcost();
                        printf("\n");
                        printf("                                                                      Total Cost=%20d\n",totalCost);
                        deleteitem1();

                    }
                else if(a[i]== 0)
                    {
                        printf("\nCART IS EMPTY!!!\n");
                        mainmenu();
                    }
        }
    }
    void deleteitem1()//Function to delete item one by one and show the total cost after deleting an item
    {
        int id;
        for(i=0;i<20;i++){
                if(a[i]>0){
                    printf("\nEnter id to delete item\n");
                    scanf("%d",&id);
                    if(id<20&&id>=0)
                        {
                            totalcost();
                            totalCost=totalCost-(tc[id]);
                            a[id]=0;
                        }
                    else
                    {
                        printf("\nEnter Valid id\n");
                    }
                    printf("\nRevised Items \n");
                    printf("\n-----------------------------------------------------------------------------------------------------");
                    printf("\nId      Items                             Quantity           Rate          Discount             Price");
                    printf("\n-----------------------------------------------------------------------------------------------------");
                    for(i=0;i<20;i++)
                    {
                        if(a[i]!=0)
                            {
                                printf("\n%-8d%-34s%-19d%-14d%-4d%%%21d\n",i,items[i],a[i],cost[i],discount[i],(cost[i]*a[i])-(cost[i]*a[i]*discount[i]/100));
                            }
                    }
                    totalcost();
                    totalCost= totalCost-tc[id];
                    printf("\n");
                    printf("                                                                      Total Cost=%20d\n",totalCost);
                    printf("\n");
                    printf("Enter \n1 - Go Back to Category Menu/Main menu\n2 - Delete Item\n3 - Check Out\n");
                    scanf("%d",&c);
                    if(c==1){
                        mainmenu();
                    }
                    else if(c==2){
                        deleteitem1();
                    }
                    else if(c==3){
                        checkout();
                        }
                    else{
                        printf("\nInvalid Input!!\n");
                        mainmenu();
                    }
                    }
        }
        for(i=0;i<20;i++)
            {
                if(a[i]== 0)
                    {
                        printf("\nCART IS EMPTY!!!\n");
                    }
                mainmenu();
            }

    }
    void totalcost()//To calculate the total cost of items we buy
    {
        totalCost=tc[0]+tc[1]+tc[2]+tc[3]+tc[4]+tc[5]+tc[6]+tc[7]+tc[8]+tc[9]+tc[10]+tc[11]+tc[12]+tc[13]+tc[14]+tc[15]+tc[16]+tc[17]+tc[18]+tc[19];
    }

    void totalcost_in_word()//To show the total cost of items we buy in words while checking out
    {
        if (totalCost>=0 && totalCost<=9999999)
        {
            ten_pos = (totalCost/10)%10;
            unit_pos = totalCost % 10;
            hund_pos = (totalCost/100)%10;
            thous_pos = (totalCost/1000)%10;
            ten_thous_pos = (totalCost/10000)%10;
            lakh_pos = (totalCost/100000)%10;
            ten_lakhs_pos = totalCost/1000000;

            if(ten_lakhs_pos != 0)
            {
                if(ten_lakhs_pos == 1)
                    {
                  printf("%s",ten_nineteen[lakh_pos]);
                    }
                else{
                    if(ten_lakhs_pos >= 2)
                        {
                            printf("%s ",tens_word[ten_lakhs_pos-2]);
                        }
                    if(lakh_pos != 0)
                    {
                      printf("%s",digit_word[lakh_pos]);
                    }
                }
                printf(" lakhs ");
            }
            else{
                    if(lakh_pos != 0)
                        {
                            if(lakh_pos == 1){
                                printf("%s",digit_word[lakh_pos]);
                                printf(" lakh");
                            }
                            else{
                                printf("%s",digit_word[lakh_pos]);
                                printf(" lakhs ");
                            }
                        }
                    }
            if(ten_thous_pos != 0)
            {
                if(ten_thous_pos == 1)
              {
                  printf(" %s ",ten_nineteen[thous_pos]);
              }
              else
              {
                  if(ten_thous_pos >= 2)
                  {
                      printf(" %s ",tens_word[ten_thous_pos-2]);
                  }
                  if(thous_pos != 0)
                  {
                      printf(" %s ",digit_word[thous_pos]);
                  }
              }
              printf("thousand ");
            }
            if(thous_pos != 0 && ten_thous_pos == 0)
              {
                  printf("%s thousand ",digit_word[thous_pos]);
              }

            if(hund_pos != 0)
            {
                printf("%s hundred ",digit_word[hund_pos]);
            }

            if(ten_pos == 1)
            {
                printf("%s",ten_nineteen[unit_pos]);
            }
            else
            {
                if(ten_pos >= 2)
                {
                    printf("%s ",tens_word[ten_pos-2]);
                }
                if(unit_pos != 0)
                {
                    printf("%s ",digit_word[unit_pos]);
                }
            }
        }

    }

    void checkout()//Function where the user will be showed the list of items he/she purchased
    {
        totalcost();
        if(totalCost>=2000){
            if(a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0 || a[4]!=0 || a[5]!=0 || a[6]!=0 || a[7]!=0 || a[8]!=0 || a[9]!=0 || a[10]!=0 || a[11]!=0 || a[12]!=0 || a[13]!=0 || a[14]!=0 || a[15]!=0 || a[16]!=0 || a[17]!=0 || a[18]!=0 || a[19]!=0 )
                    {
                        printf("\n");
                        printf("%s's cart\n",str);
                        printf("\n");
                        printf("\n-----------------------------------------------------------------------------------------------------");
                        printf("\nId      Items                             Quantity           Rate          Discount             Price");
                        printf("\n-----------------------------------------------------------------------------------------------------");
                        for(i=0;i<20;i++)
                        {
                            if(a[i] != 0){
                                printf("\n%-8d%-34s%-19d%-14d%-4d%%%21d\n",i,items[i],a[i],cost[i],discount[i],(cost[i]*a[i])-(cost[i]*a[i]*discount[i]/100));
                            }

                        }
                        totalcost();
                        printf("\n");
                        printf("                                                                   Total Cost=   %20d\n",totalCost);
                        printf("\n                                                                   Final Cost=   %20d\n",totalCost);
                    }
            printf("\nYou Are Eligible For Free Delivery !!!\n");
            printf("\nYour Final Cost is Rs.%d\n",totalCost);
            printf("\nFinal Cost in words: ");
            totalcost_in_word();
            printf("Rupees only\n");
            saved_money();
            if(s_m != 0){
                        printf("\nYou saved Rs.%d\n",s_m);
                    }
            printf("\nThanks %s for Choosing Us and Visit us again.\n",str);
            }
        else if(0<totalCost && totalCost<2000){
            if(a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0 || a[4]!=0 || a[5]!=0 || a[6]!=0 || a[7]!=0 || a[8]!=0 || a[9]!=0 || a[10]!=0 || a[11]!=0 || a[12]!=0 || a[13]!=0 || a[14]!=0 || a[15]!=0 || a[16]!=0 || a[17]!=0 || a[18]!=0 || a[19]!=0 )
                {
                    printf("\n");
                    printf("%s's cart\n",str);
                    printf("\n");
                    printf("\n-----------------------------------------------------------------------------------------------------");
                    printf("\nId      Items                             Quantity           Rate          Discount             Price");
                    printf("\n-----------------------------------------------------------------------------------------------------");
                    for(i=0;i<20;i++)
                    {
                        if(a[i] != 0){
                            printf("\n%-8d%-34s%-19d%-14d%-4d%%%21d\n",i,items[i],a[i],cost[i],discount[i],(cost[i]*a[i])-(cost[i]*a[i]*discount[i]/100));
                        }

                    }
                    totalcost();
                    printf("\n");
                    printf("                                                                      Total Cost=%20d",totalCost);
                    printf("\n                                                                      Delivery Charges=           100\n");
                    printf("\n                                                                      Final Cost=%20d\n",totalCost+100);
                    printf("\nYour Final Cost is Rs.%d\n",totalCost+100);
                    totalCost=totalCost+100;
                    printf("\nFinal Cost in words: ");
                    totalcost_in_word();
                    printf("Rupees only\n");
                    saved_money();
                    if(s_m != 0){
                        printf("\nYou saved Rs.%d\n",s_m);
                    }
                    printf("\nThanks %s for Choosing Us and Visit us again.\n",str);
                }
        }
        else if(totalCost == 0){
            printf("\nYOUR CART IS EMPTY!!!!\n");
            printf("\nThanks %s for Choosing Us and Visit us again.\n",str);

        }
        exit(0);
    }

    void saved_money()
    {
        for(i=0;i<20;i++)
        {
            money += cost[i]*a[i];
        }
        totalcost();
        s_m = money - totalCost;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    void menugrocery() //Menu which will appear after buying each item for navigating anywhere user wants to go
    {
        printf("\nEnter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - View Cart\n5 - Check Out\n",category[0]); //Menu to go to navigate to Items Menu or Categories menu
        printf("\nEnter number from above menu, you want to do: ");
        scanf("%d",&c); //Taking user input where he wants to get navigated
        if(c==1){ //If users choose 1 he will be navigated to the list of items in grocery
            groceryitems(); //Grocery function where all items are listed of grocery
        }
        else if(c==2){ //If users choose 2 he will be navigated to the main menu i.e category menu
            mainmenu(); //Main menu where all categories are listed
        }
        else if(c==3){ //If users choose 3 he will be navigated to delete item function
            deleteitem(); //Delete Item function where we can delete specific items from cart
        }
        else if(c==4){ //If users choose 4 he will be navigated to the main menu i.e category menu
            viewcart(); //View cart function which will show all the items in cart and its total cost

            printf("Enter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - Check Out\n",category[0]); //Menu to go to navigate to Items Menu, Categories menu, delete item or check out
            scanf("%d",&c);
            if(c==1){
                groceryitems();
            }
            else if(c==2){
                mainmenu();
            }
            else if(c==3){
                deleteitem();
            }
            else if(c==4){
                checkout();
            }
            else{
                    printf("\nInvalid Input\n");
                    mainmenu();
            }
        }
        else if(c==5){
            checkout();
        }
        else{
            printf("\nInvalid Input\n");
            mainmenu();
        }
    }

    void menuelectronics() //Menu which will appear after buying each item for navigating anywhere user wants to go
    {
        printf("\nEnter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - View Cart\n5 - Check Out\n",category[4]); //Menu to go to navigate to Items Menu or Categories menu
        printf("\nEnter number from above menu, you want to do: ");
        scanf("%d",&c); //Taking user input where he wants to get navigated
        if(c==1){ //If users choose 1 he will be navigated to the list of items in electronics
            electronicsitems(); //Electronics function where all items are listed of electronics
        }
        else if(c==2){ //If users choose 2 he will be navigated to the main menu i.e category menu
            mainmenu(); //Main menu where all categories are listed
        }
        else if(c==3){ //If users choose 3 he will be navigated to delete item function
            deleteitem(); //Delete Item function where we can delete specific items from cart
        }
        else if(c==4){ //If users choose 4 he will be navigated to the main menu i.e category menu
            viewcart(); //View cart function which will show all the items in cart and its total cost

            printf("Enter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - Check Out\n",category[4]); //Menu to go to navigate to Items Menu, Categories menu, delete item or check out
            scanf("%d",&c);
            if(c==1){
                    electronicsitems();
            }
            else if(c==2){
                    mainmenu();
            }
            else if(c==3){
                    deleteitem();
            }
            else if(c==4){
                    checkout();
            }
            else{
                    printf("\nInvalid Input\n");
                    mainmenu();
            }
        }
        else if(c==5){
            checkout();
        }
        else{
            printf("\nInvalid Input\n");
            mainmenu();
        }

    }

    void menufashion() //Menu which will appear after buying each item for navigating anywhere user wants to go
    {
        printf("\nEnter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - View Cart\n5 - Check Out\n",category[8]); //Menu to go to navigate to Items Menu or Categories menu
        printf("\nEnter number from above menu, you want to do: ");
        scanf("%d",&c); //Taking user input where he wants to get navigated
        if(c==1){ //If users choose 1 he will be navigated to the list of items in fashion
            fashionitems(); //Fashion function where all items are listed of fashion
        }
        else if(c==2){ //If users choose 2 he will be navigated to the main menu i.e category menu
            mainmenu(); //Main menu where all categories are listed
        }
        else if(c==3){ //If users choose 3 he will be navigated to delete item function
            deleteitem(); //Delete Item function where we can delete specific items from cart
        }
        else if(c==4){ //If users choose 4 he will be navigated to the main menu i.e category menu
            viewcart(); //View cart function which will show all the items in cart and its total cost

            printf("Enter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - Check Out\n",category[8]); //Menu to go to navigate to Items Menu, Categories menu, delete item or check out
            scanf("%d",&c);
            if(c==1){
                fashionitems();
            }
            else if(c==2){
                mainmenu();
            }
            else if(c==3){
                deleteitem();
            }
            else if(c==4){
                checkout();
            }
            else{
                    printf("\nInvalid Input\n");
                    mainmenu();
            }
        }
        else if(c==5){
            checkout();
        }
        else{
            printf("\nInvalid Input\n");
            mainmenu();
        }
    }

    void menusportsequipments() //Menu which will appear after buying each item for navigating anywhere user wants to go
    {
        printf("\nEnter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - View Cart\n5 - Check Out\n",category[12]); //Menu to go to navigate to Items Menu or Categories menu
        printf("\nEnter number from above menu, you want to do: ");
        scanf("%d",&c); //Taking user input where he wants to get navigated
        if(c==1){ //If users choose 1 he will be navigated to the list of items in sport equipments
            sportsequipmentsitems(); //Sports Equipments function where all items are listed of sports equipments
        }
        else if(c==2){ //If users choose 2 he will be navigated to the main menu i.e category menu
            mainmenu(); //Main menu where all categories are listed
        }
        else if(c==3){ //If users choose 3 he will be navigated to delete item function
            deleteitem(); //Delete Item function where we can delete specific items from cart
        }
        else if(c==4){ //If users choose 4 he will be navigated to the main menu i.e category menu
            viewcart(); //View cart function which will show all the items in cart and its total cost

            printf("Enter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - Check Out\n",category[12]); //Menu to go to navigate to Items Menu, Categories menu, delete item or check out
            scanf("%d",&c);
            if(c==1){
                sportsequipmentsitems();
            }
            else if(c==2){
                mainmenu();
            }
            else if(c==3){
                deleteitem();
            }
            else if(c==4){
                checkout();
            }
            else{
                    printf("\nInvalid Input\n");
                    mainmenu();
            }
        }
        else if(c==5){
            checkout();
        }
        else{
            printf("\nInvalid Input\n");
            mainmenu();
        }
    }

    void menubooks() //Menu which will appear after buying each item for navigating anywhere user wants to go
    {
        printf("\nEnter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - View Cart\n5 - Check Out\n",category[16]); //Menu to go to navigate to Items Menu or Categories menu
        printf("\nEnter number from above menu, you want to do: ");
        scanf("%d",&c); //Taking user input where he wants to get navigated
        if(c==1){ //If users choose 1 he will be navigated to the list of items in books
            booksitems(); //Books function where all items are listed of books
        }
        else if(c==2){ //If users choose 2 he will be navigated to the main menu i.e category menu
            mainmenu(); //Main menu where all categories are listed
        }
        else if(c==3){ //If users choose 3 he will be navigated to delete item function
            deleteitem(); //Delete Item function where we can delete specific items from cart
        }
        else if(c==4){ //If users choose 4 he will be navigated to the main menu i.e category menu
            viewcart(); //View cart function which will show all the items in cart and its total cost

            printf("Enter \n1 - Add Item from %s category\n2 - Go Back to Category Menu/Main menu\n3 - Delete Item\n4 - Check Out\n",category[16]); //Menu to go to navigate to Items Menu, Categories menu, delete item or check out
            scanf("%d",&c);
            if(c==1){
                booksitems();
            }
            else if(c==2){
                mainmenu();
            }
            else if(c==3){
                deleteitem();
            }
            else if(c==4){
                checkout();
            }
            else{
                    printf("\nInvalid Input\n");
                    mainmenu();
            }
        }
        else if(c==5){
            checkout();
        }
        else{
            printf("\nInvalid Input\n");
            mainmenu();
        }
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Grocery Items function where list of items is displayed and taking user input what he wants to choose or go back to category menu
    void groceryitems()
    {
        printf("\nGrocery:\n1 - Amul Milk - Rs.40\n2 - Real Fruit Juice - Rs.100\n3 - Doritos Chips - Rs.50\n4 - Nestle Ketchup - Rs.200\n");
        printf("\nEnter the item number in grocery you want orelse enter 5 to exit to Category Menu/main menu: ");
        scanf("%d",&grocery_no); //User input to choose which item he wants to buy

        //Cost for respective items such as "0" index determines Milk over here and so on
        cost[0]=40;
        cost[1]=100;
        cost[2]=50;
        cost[3]=200;
        grocery();
    }

    void electronicsitems()
    {
        printf("\nElectronics:\n1 - Apple Airpods - Rs.20000\n2 - Apple iPhone 12 Pro - Rs.50000\n3 - Sony 4K TV - Rs.20000\n4 - Apple iWatch Series 6 - Rs.30000\n");
        printf("\nEnter the item number in electronics you want orelse enter 5 to exit to Category Menu/main menu: ");
        scanf("%d",&electronics_no); //User input to choose which item he wants to buy

        //Discount and cost for respective items such as "4" index determines Headphone over here and so on
        cost[4]=20000;
        cost[5]=50000;
        cost[6]=20000;
        cost[7]=30000;
        electronics();
    }

    void fashionitems()
    {
        printf("\nFashion:\n1 - Dior Sunglasses - Rs.1200\n2 - Addidas Cap/Hat - Rs.400\n3 - Nike Shoes - Rs.20000\n4 - Under Armour Hoodie - Rs.6000\n");
        printf("\nEnter the item number in electronics you want orelse enter 5 to exit to Category Menu/main menu: ");
        scanf("%d",&fashion_no); //User input to choose which item he wants to buy

        //Discount and cost for respective items such as "8" index determines Sunglasses over here and so on
        cost[8]=1200;
        cost[9]=400;
        cost[10]=20000;
        cost[11]=6000;
        fashion();
    }
    void sportsequipmentsitems()
    {
        printf("\nSports Equipments:\n1 - Nivia Football - Rs.400\n2 - Nike Studs - Rs.7000\n3 - MRF Bat - Rs.5000\n4 - Nivia Basketball - Rs.700\n");
        printf("\nEnter the item number in electronics you want orelse enter 5 to exit to Category Menu/main menu: ");
        scanf("%d",&sportsequipments_no); //User input to choose which item he wants to buy

        //Discount and cost for respective items such as "12" index determines football over here and so on
        cost[12]=400;
        cost[13]=7000;
        cost[14]=5000;
        cost[15]=700;
        sportsequipments();
    }

    void booksitems()
    {
        printf("\nBooks:\n1 - Essential C - Rs.300\n2 - Let Us C - Rs.460\n3 - ANCI C - Rs.600\n4 - Modern C - Rs.550\n");
        printf("\nEnter the item number in electronics you want orelse enter 5 to exit to Category Menu/main menu: ");
        scanf("%d",&books_no); //User input to choose which item he wants to buy

        //Discount and cost for respective items such as "16" index determines Essential C over here and so on
        cost[16]=300;
        cost[17]=460;
        cost[18]=600;
        cost[19]=550;
        books();
    }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Grocery function where user choose some item from the item list and will be navigated to specific switch case for buying
    void grocery()
    {
        switch(grocery_no)
        {
            //User chose 1 i.e he wants to buy milk
            case 1:
                {
                    int num,q0; //Initializing integers for user input and quantity
                    printf("\nYou chose Amul Milk.Are you sure you want to buy?"); //Taking confirmation from the user whether he wants to buy the item
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);//Taking user input for confirmation
                    //If he choose 1, will take how much quantity he wants and show offers
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 2 QUANTITY AND GET FLAT 10%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Amul Milk: ");
                            scanf("%d",&q0); //Taking user input for quantity of milk
                            a[0]+=q0; //Incrementing the quantity with previous one if user repeats or buy same item again (a+=b is a=a+b)

                            //Calculate the cost of items on the basis of quantity and offers
                            if(a[0]>=3){
                                    discount[0]=10;
                                    tc[0]=((cost[0]*a[0])-(cost[0]*a[0]*0.1));
                            }
                            else if(a[0]<=2 && a[0]>0){
                                discount[0]=0;
                                tc[0]=cost[0]*a[0];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                groceryitems();
                            }
                        }
                        //If user says 0 at the time of confirming to buy milk user will be navigated back to grocery items menu
                    else if(num==0){
                            groceryitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            mainmenu();
                        }
                        //Calculating total cost and displaying the cost of items in cart
                        totalcost();
                        printf("\nTotal Cost of items in cart: %d\n",totalCost);
                        //Navigating user back to grocery menu where he can add item of grocery or go to different category
                        menugrocery();
                    break;
                }
            //User chose 1 i.e he wants to buy real fruit juice
            case 2:
                {
                    int num,q1;
                    printf("\nYou chose Real fruit Juice.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 3 QUANTITY AND GET FLAT 15%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Real Fruit Juice: ");
                            scanf("%d",&q1);
                            a[1]+=q1;
                            if(a[1]>3)
                            {
                                discount[1]=15;
                                tc[1]=((cost[1]*a[1])-(cost[1]*a[1]*0.15));
                            }
                            else if(a[1]<=3 && a[1]>0){
                                discount[1]=0;
                                tc[1]=cost[1]*a[1];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                groceryitems();
                            }
                        }
                    else if(num==0){
                            groceryitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            mainmenu();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart: %d\n",totalCost);
                        menugrocery();
                    break;
                }
            case 3:
                {
                    int num,q2;
                    printf("\n");
                    printf("You chose Chips.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 4 QUANTITY AND GET FLAT 10%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Chips: ");
                            scanf("%d",&q2);
                            a[2]+=q2;

                            if(a[2]>=5)
                            {
                                discount[2]=10;
                                tc[2]=((cost[2]*a[2])-(cost[2]*a[2]*0.1));
                            }
                            else if(a[2]<=4 && a[2]>0){
                                discount[2]=0;
                                tc[2]=cost[2]*a[2];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                groceryitems();
                            }
                        }
                    else if(num==0){
                            groceryitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            groceryitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart: %d\n",totalCost);
                        menugrocery();
                    break;
                }
            case 4:
                {
                    int num,q3;
                    printf("\n");
                    printf("You chose Ketchup.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 1 QUANTITY AND GET FLAT 10%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Ketchup: ");
                            scanf("%d",&q3);
                            a[3]+=q3;

                            if(a[3]>=2)
                            {
                                discount[3]=15;
                                tc[3]=((cost[3]*a[3])-(cost[3]*a[3]*0.15));
                            }
                            else if(a[3]==1){
                                discount[3]=0;
                                tc[3]=cost[3]*a[3];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                groceryitems();
                            }
                        }
                    else if(num==0){
                            groceryitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            mainmenu();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart: %d\n",totalCost);
                        menugrocery();
                    break;
                }
            case 5:
                {
                    printf("\nGoing back to the main menu.");
                    mainmenu();
                }
            default:{
                printf("\nInvalid Input!!!\n");
                groceryitems();
                break;
                }
                }
    }


    // Electronics function where user choose some item from the item list and will be navigated to specific switch case for buying
    void electronics()
    {
        switch(electronics_no)
        {
            //User chose 1 i.e he wants to buy apple airpods
            case 1:
                {
                    int num,q4; //Initializing integers for user input and quantity
                    printf("\nYou chose Apple Airpods.Are you sure you want to buy?"); //Taking confirmation from the user
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    //If he choose 1, will take how much quantity he wants and show offers
                    if(num==1)
                        {
                            printf("\n ************************************************************");
                            printf("\n  *                                                        *");
                            printf("\n   $ BUY 2 AND GET 50% OFF OR BUY MORE THAN 2 GET 55%% OFF $");
                            printf("\n  *                                                        *");
                            printf("\n ************************************************************");
                            printf("\n\nEnter Quantity for Apple Airpods: ");
                            scanf("%d",&q4); //Taking quantity and incrementing it if user repeats or buy same item again (a+=b is a=a+b)
                            a[4]+=q4;

                            //Calculate the cost of items on the basis of quantity and offers
                            if(a[4]>2){
                                    discount[4]=55;
                                    tc[4]=((cost[4]*a[4])-(cost[4]*a[4]*0.55));
                            }
                            else if(a[4]==2){
                                discount[4]=50;
                                tc[4]=((cost[4]*a[4])-(cost[4]*a[4]*0.5));
                            }
                            else if(a[4]==1){
                                discount[4]=0;
                                tc[4]=(cost[4]*a[4]);
                            }

                            else{
                                printf("Invalid Quantity!!!");
                                electronicsitems();
                            }
                        }
                    else if(num==0){
                            electronicsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            electronicsitems();
                        }
                        //Calculating total cost and displaying the cost of items in cart
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        //Navigating user back to electronics menu where he can add item of elsectronics or go to different category
                        menuelectronics();
                    break;
                }
            //User chose 1 i.e he wants to buy real fruit juice
            case 2:
                {
                    int num,q5;
                    printf("\nYou chose Apple iPhone 12 Pro.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n **********************************************************");
                            printf("\n  *                                                      *");
                            printf("\n   $ BUY 1 OR MORE THAN 1 QUANTITY AND GET FLAT 30%% OFF $");
                            printf("\n  *                                                      *");
                            printf("\n **********************************************************");
                            printf("\n\nEnter Quantity for Apple iPhone 12 Pro: ");
                            scanf("%d",&q5);
                            a[5]+=q5;
                            if(a[5]>=1)
                                {
                                    discount[5]=30;
                                    tc[5]=((cost[5]*a[5])-(cost[5]*a[5]*0.3));
                                }
                            else{
                                printf("Invalid Quantity!!!");
                                electronicsitems();
                            }
                        }
                    else if(num==0){
                            electronicsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            electronicsitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menuelectronics();
                    break;
                }
            case 3:
                {
                    int num,q6;
                    printf("\n");
                    printf("You chose Sony 4K TV.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n **********************************************************");
                            printf("\n  *                                                      *");
                            printf("\n   $ BUY 1 OR MORE THAN 1 QUANTITY AND GET FLAT 30%% OFF $");
                            printf("\n  *                                                      *");
                            printf("\n **********************************************************");
                            printf("\n\nEnter Quantity for Sony 4K TV: ");
                            scanf("%d",&q6);
                            a[6]+=q6;

                            if(a[6]>=1)
                            {
                                discount[6]=30;
                                tc[6]=((cost[6]*a[6])-(cost[6]*a[6]*0.3));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                electronicsitems();
                            }
                        }
                    else if(num==0){
                            electronicsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            electronicsitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menuelectronics();
                    break;
                }
            case 4:
                {
                    int num,q7;
                    printf("\n");
                    printf("You chose Apple iWatch Series 6.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ************************************************************");
                            printf("\n  *                                                        *");
                            printf("\n   $ BUY 2 AND GET 50% OFF OR BUY MORE THAN 2 GET 55%% OFF $");
                            printf("\n  *                                                        *");
                            printf("\n ************************************************************");
                            printf("\n\nEnter Quantity for Apple iWatch Series 6: ");
                            scanf("%d",&q7);
                            a[7]+=q7;

                            if(a[7]==2)
                            {
                                discount[7]=50;
                                tc[7]=((cost[7]*a[7])-(cost[7]*a[7]*0.5));
                            }
                            else if(a[7]>2){
                                discount[7]=55;
                                tc[7]=((cost[7]*a[7])-(cost[7]*a[7]*0.55));
                            }
                            else if( a[7]==1){
                                discount[7]=0;
                                tc[7]=cost[7]*a[7];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                electronicsitems();
                            }
                        }
                    else if(num==0){
                            electronicsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            electronicsitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menuelectronics();
                    break;
                }
            case 5:
                {
                    printf("\nGoing back to the main menu.");
                    mainmenu();
                }
            default:{
                printf("\nInvalid Input!!!\n");
                electronicsitems();
                break;
                }
                }
    }

    // Fashion function where user choose some item from the item list and will be navigated to specific switch case for buying
    void fashion()
    {
        switch(fashion_no)
        {
            //User chose 1 i.e he wants to buy Dior Sunglasses
            case 1:
                {
                    int num,q8; //Initializing integers for user input and quantity
                    printf("\nYou chose Dior Sunglasses.Are you sure you want to buy?"); //Taking confirmation from the user
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    //If he choose 1, will take how much quantity he wants and show offers
                    if(num==1)
                        {
                            printf("\n ************************************************************");
                            printf("\n  *                                                        *");
                            printf("\n   $ BUY 2 AND GET 50% OFF OR BUY MORE THAN 2 GET 55%% OFF $");
                            printf("\n  *                                                        *");
                            printf("\n ************************************************************");
                            printf("\n\nEnter Quantity for Dior Sunglasses: ");
                            scanf("%d",&q8); //Taking quantity and incrementing it if user repeats or buy same item again (a+=b is a=a+b)
                            a[8]+=q8;

                            //Calculate the cost of items on the basis of quantity and offers
                            if(a[8]>2){
                                    discount[8]=55;
                                    tc[8]=((cost[8]*a[8])-(cost[8]*a[8]*0.55));
                            }
                            else if(a[8]==2){
                                discount[8]=50;
                                tc[8]=((cost[8]*a[8])-(cost[8]*a[8]*0.5));
                            }
                            else if(a[8]==1){
                                discount[8]=0;
                                tc[8]=(cost[8]*a[8]);
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                fashionitems();
                            }
                        }
                    else if(num==0){
                            fashionitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            fashionitems();
                        }
                        //Calculating total cost and displaying the cost of items in cart
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        //Navigating user back to fashion menu where he can add item of fashion or go to different category
                        menufashion();
                    break;
                }
            //User chose 1 i.e he wants to buy real fruit juice
            case 2:
                {
                    int num,q9;
                    printf("\nYou chose Addidas Cap/Hat.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 1 QUANTITY AND GET FLAT 15%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Addidas Cap/Hat: ");
                            scanf("%d",&q9);
                            a[9]+=q9;
                            if(a[9]>1)
                            {
                                discount[5]=15;
                                tc[9]=((cost[9]*a[9])-(cost[9]*a[9]*0.15));
                            }
                            else if(a[9]==1)
                                {
                                    discount[5]=0;
                                    tc[9]=cost[9]*a[9];
                                }
                            else{
                                printf("Invalid Quantity!!!");
                                fashionitems();
                            }
                        }
                    else if(num==0){
                            fashionitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            fashionitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menufashion();
                    break;
                }
            case 3:
                {
                    int num,q10;
                    printf("\n");
                    printf("You chose Nike Shoes.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 25%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Nike Shoes: ");
                            scanf("%d",&q10);
                            a[10]+=q10;

                            if(a[10]>=1)
                            {
                                discount[10]=25;
                                tc[10]=((cost[10]*a[10])-(cost[10]*a[10]*0.25));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                fashionitems();
                            }
                        }
                    else if(num==0){
                            fashionitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            fashionitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menufashion();
                    break;
                }
            case 4:
                {
                    int num,q11;
                    printf("\n");
                    printf("You chose Under Armour Hoodie.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *********************************************");
                            printf("\n  *                                         *");
                            printf("\n   $ BUY 2 OR MORE THAN 2 GET FLAT 25%% OFF $");
                            printf("\n  *                                         *");
                            printf("\n *********************************************");
                            printf("\n\nEnter Quantity for Under Armour Hoodie: ");
                            scanf("%d",&q11);
                            a[11]+=q11;

                            if(a[11]>=2)
                            {
                                discount[11]=25;
                                tc[11]=((cost[11]*a[11])-(cost[11]*a[11]*0.25));
                            }
                            else if( a[11]==1){
                                discount[11]=0;
                                tc[11]=cost[11]*a[11];
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                fashionitems();
                            }
                        }
                    else if(num==0){
                            fashionitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            fashionitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menufashion();
                    break;
                }
            case 5:
                {
                    printf("\nGoing back to the main menu.");
                    mainmenu();
                }
            default:{
                printf("\nInvalid Input!!!\n");
                fashionitems();
                break;
                }
                }
    }

    // Sports equipments function where user choose some item from the item list and will be navigated to specific switch case for buying
    void sportsequipments()
    {
        switch(sportsequipments_no)
        {
            //User chose 1 i.e he wants to buy Dior Sunglasses
            case 1:
                {
                    int num,q12; //Initializing integers for user input and quantity
                    printf("\nYou chose Nivia Football.Are you sure you want to buy?"); //Taking confirmation from the user
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    //If he choose 1, will take how much quantity he wants and show offers
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 55%% OFF $");
                            printf("\n                   *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Nivia Football : ");
                            scanf("%d",&q12); //Taking quantity and incrementing it if user repeats or buy same item again (a+=b is a=a+b)
                            a[12]+=q12;

                            //Calculate the cost of items on the basis of quantity and offers
                            if(a[12]>=1){
                                    discount[12]=55;
                                    tc[12]=((cost[12]*a[12])-(cost[12]*a[12]*0.55));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                sportsequipmentsitems();
                            }
                        }
                    else if(num==0){
                            sportsequipmentsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            sportsequipmentsitems();
                        }
                    //Calculating total cost and displaying the cost of items in cart
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    //Navigating user back to sports equipments menu where he can add item of sports equipments or go to different category
                    menusportsequipments();
                    break;
                }
            //User chose 1 i.e he wants to buy real fruit juice
            case 2:
                {
                    int num,q13;
                    printf("\nYou chose Nike Studs.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n *****************************************************");
                            printf("\n  *                                                 *");
                            printf("\n   $ BUY MORE THAN 1 QUANTITY AND GET FLAT 15%% OFF $");
                            printf("\n  *                                                 *");
                            printf("\n *****************************************************");
                            printf("\n\nEnter Quantity for Nike Studs: ");
                            scanf("%d",&q13);
                            a[13]+=q13;
                            if(a[13]>1)
                            {
                                discount[13]=15;
                                tc[13]=((cost[13]*a[13])-(cost[13]*a[13]*0.15));
                            }
                            else if(a[13]==1)
                                {
                                    discount[13]=0;
                                    tc[13]=cost[13]*a[13];
                                }
                            else{
                                printf("Invalid Quantity!!!");
                                sportsequipmentsitems();
                            }
                        }
                    else if(num==0){
                            sportsequipmentsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            sportsequipmentsitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menusportsequipments();
                    break;
                }
            case 3:
                {
                    int num,q14;
                    printf("\n");
                    printf("You chose MRF Bat.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 50%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for MRF Bat: ");
                            scanf("%d",&q14);
                            a[14]+=q14;

                            if(a[14]>=1)
                            {
                                discount[14]=50;
                                tc[14]=((cost[14]*a[14])-(cost[14]*a[14]*0.5));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                sportsequipmentsitems();
                            }
                        }
                    else if(num==0){
                            sportsequipmentsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            sportsequipmentsitems();
                        }
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    menusportsequipments();
                    break;
                }
            case 4:
                {
                    int num,q15;
                    printf("\n");
                    printf("You chose Nivia Basketball.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 50%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Nivia Basketball: ");
                            scanf("%d",&q15);
                            a[15]+=q15;

                            if(a[15]>=1)
                            {
                                discount[15]=50;
                                tc[15]=((cost[15]*a[15])-(cost[15]*a[15]*0.5));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                sportsequipmentsitems();
                            }
                        }
                    else if(num==0){
                            sportsequipmentsitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            sportsequipmentsitems();
                        }
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    menusportsequipments();
                    break;
                }
            case 5:
                {
                    printf("\nGoing back to the main menu.");
                    mainmenu();
                }
            default:{
                printf("\nInvalid Input!!!\n");
                sportsequipmentsitems();
                break;
                }
                }
    }
    // Books function where user choose some item from the item list and will be navigated to specific switch case for buying
    void books()
    {
        switch(books_no)
        {
            //User chose 1 i.e he wants to buy Essential C
            case 1:
                {
                    int num,q16; //Initializing integers for user input and quantity
                    printf("\nYou chose Essential C.Are you sure you want to buy?"); //Taking confirmation from the user
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    //If he choose 1, will take how much quantity he wants and show offers
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 10%% OFF $");
                            printf("\n                   *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Essential C : ");
                            scanf("%d",&q16); //Taking quantity and incrementing it if user repeats or buy same item again (a+=b is a=a+b)
                            a[16]+=q16;

                            //Calculate the cost of items on the basis of quantity and offers
                            if(a[16]>=1){
                                    discount[16]=10;
                                    tc[16]=((cost[16]*a[16])-(cost[16]*a[16]*0.1));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                booksitems();
                            }
                        }
                    else if(num==0){
                            booksitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            booksitems();
                        }
                    //Calculating total cost and displaying the cost of items in cart
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    //Navigating user back to books menu where he can add item of books or go to different category
                    menubooks();
                    break;
                }
            //User chose 1 i.e he wants to buy real fruit juice
            case 2:
                {
                    int num,q17;
                    printf("\nYou chose Let Us C.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 10%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Let Us C: ");
                            scanf("%d",&q17);
                            a[17]+=q17;

                            if(a[17]>=1)
                            {
                                discount[17]=10;
                                tc[17]=((cost[17]*a[17])-(cost[17]*a[17]*0.1));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                booksitems();
                            }
                        }
                    else if(num==0){
                            booksitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            booksitems();
                        }
                        totalcost();
                        printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                        menubooks();
                    break;
                }
            case 3:
                {
                    int num,q18;
                    printf("\n");
                    printf("You chose ANCI C.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 10%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for ANCI C: ");
                            scanf("%d",&q18);
                            a[18]+=q18;

                            if(a[18]>=1)
                            {
                                discount[18]=10;
                                tc[18]=((cost[18]*a[18])-(cost[18]*a[18]*0.1));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                booksitems();
                            }
                        }
                    else if(num==0){
                            booksitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            booksitems();
                        }
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    menubooks();
                    break;
                }
            case 4:
                {
                    int num,q19;
                    printf("\n");
                    printf("You chose Modern C.Are you sure you want to buy?");
                    printf("\nIf 'Yes' Enter 1 \nIf 'No' Enter 0\n");
                    scanf("%d",&num);
                    if(num==1)
                        {
                            printf("\n ********************");
                            printf("\n  *                *");
                            printf("\n   $ FLAT 10%% OFF $");
                            printf("\n  *                *");
                            printf("\n ********************");
                            printf("\n\nEnter Quantity for Modern C: ");
                            scanf("%d",&q19);
                            a[19]+=q19;

                            if(a[19]>=1)
                            {
                                discount[19]=10;
                                tc[19]=((cost[19]*a[19])-(cost[19]*a[19]*0.1));
                            }
                            else{
                                printf("Invalid Quantity!!!");
                                booksitems();
                            }
                        }
                    else if(num==0){
                            booksitems();
                        }
                    else{
                            printf("\nInvalid Input\n");
                            booksitems();
                        }
                    totalcost();
                    printf("\nTotal Cost of items in cart:Rs. %d\n",totalCost);
                    menubooks();
                    break;
                }
            case 5:
                {
                    printf("\nGoing back to the main menu.");
                    mainmenu();
                }
            default:{
                printf("\nInvalid Input!!!\n");
                booksitems();
                break;
                }
                }
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
