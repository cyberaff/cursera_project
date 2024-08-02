#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/**Functin for tokenise a string from csv file */
std::vector<std::string> tokenise(std::string csvLile, char separator)
{
    //Vector for store the tokens */
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    //defining start possision: first character if it is not separator starting from 0
    start = csvLile.find_first_not_of(separator, 0);
    //creating the do-while loop
    do{
        //defining end: separator after start 
        end = csvLile.find_first_of(separator, start);

        //finding a token
        if(start == csvLile.length() || start == end) break;

        if(end >= 0) token = csvLile.substr(start, end - start);

        else 
            token = csvLile.substr(start, csvLile.length() - start);

        //saving tokens in vector
        tokens.push_back(token);

        //creating new start point
        start = end + 1;


    }while(end != std::string::npos); //because find_first_not_of returns std::string::npos if it does not find the search term.


    return tokens;
}


int main()
{
    // std::vector<std::string> tokens;
    // std::string es; // "2020/03/17 17:01:24.884492,ETH/BTC,bid,0.0217499,0.04644343";
    // std::cout << std::endl;
    // std::cout << "Podaj jakis string" << std::endl;
    // std::getline(std::cin, es); //getline is for taking a full string including 
    // std::cout << "=================================" << std::endl;
    // tokens = tokenise(es, ',');
    // std::cout << "Tokeny to: " << std::endl;

    // for(std::string& t : tokens){
    //     std::cout << t << std::endl<< std::endl;
    // }

    //Reading from a file
    std::ifstream csvFile{"exaple_data.csv"}; //open the file in read option by defult
    std::string line;

    //Cheking if the file is opened
    if(csvFile.is_open())
    {
        std::cout << "File is open" << std::endl;
        // std::getline(csvFile, line); // reading single line from file
        
        while (std::getline(csvFile, line)) //reading line by line in file
        {
            std::cout << "Read line: " << line << std::endl;
            std::vector<std::string> tokens;
            //tokenise the lines
            tokens = tokenise(line, ',');
            // checking if tokens vector contains all needed data
            if(tokens.size() != 5){  
                std::cout << "Bad line " << std::endl;
                continue;
            }
            // // converting string to double with stod() function
            // double price = std::stod(tokens[3]);
            // double amount = std::stod(tokens[4]);
            // std::cout <<"Price to amount: " << price << ":" << amount << std::endl;

            // catching the exceptions
            try
            {
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);
                std::cout <<"Price to amount: " << price << ":" << amount << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "Bad float! " << tokens[3] << std::endl;
                std::cout << "Bad float! " << tokens[4] << std::endl;
            }
            
            
            
            // for(std::string& t : tokens){
            //     std::cout << t << std::endl;
            // }

        }
     
        // Always close the file!!!
        csvFile.close();
    }
    else
    {
        std::cout << "Could't open file" << std::endl;
    }



    return 0;
}
