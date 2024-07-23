#include <iostream>

using namespace std;
// funkcja wyswietlania opcji
void printMenu(){
    // 1 printing help
        cout << "1: Print help." << endl;
        // 2 printing exchange stats
        cout << "2: print exchange stats" << endl;
        // 3 make an offer
        cout << "3: Make an offer" << endl;
        // 4 make a bid
        cout << "4: Make a bid" << endl;
        // print wallet
        cout << "5: Print wallet" << endl;
        // 6 continue
        cout << "6: Continue" << endl;
        // 9 exit
        cout <<"9: EXIT See you next time" << endl
             << endl;

        cout << "================================" << endl;
}
// funkcja interakcji z użytkownikiem
int getUserOption(){
    cout << "Select option 1 -6" << endl << endl;

    int userOption;
    cin >> userOption;
    cout << "You chose: " << userOption << endl << endl;
    return userOption;
}
// funkcja warunków
void processUserOptions(int userOption){
    if (userOption == 0){
            cout << "Invalid choose, please select 1-6" << endl << endl;
        }
        if (userOption == 1)
        {
            cout << "Help - yor=ur aim is to make money. Analyse the market and make bids and offers" << endl
                << endl;
        }
        if (userOption == 2)
        {
            cout << "Market looks good" << endl << endl;
        }
        if (userOption == 3)
        {
            cout << "Mark an offer" << endl
                << endl;
        }
        if (userOption == 4)
        {
            cout << "Make a bid - enter an amount" << endl
                << endl;
        }
        if (userOption == 5)
        {
            cout << "Your wallet is empty. " << endl
                << endl;
        }
        if (userOption == 6)
        {
            cout << "Going to next time frame" << endl
                << endl;
        }
        if (6 > userOption < 9 and userOption >= 10)
        {
            cout << "Invalid choose, please select 1-6" << endl
                << endl;
        }
};
int main(){
    // tworzymy pętle dla interakcji z uzytkownikiem
    while (true){
    // opcje:
        printMenu();
        int userOption = getUserOption();
        processUserOptions(userOption);

    // wychodzimy z pętli po klawiszu 9
        if (userOption == 9){
            cout << " See you next time" << endl;
            break;
        }
        
    }
    return 0;
}
