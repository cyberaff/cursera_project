
//Utworzenie klasy głównej

class MerkleMain
{
    public:
        MerkleMain();
        /**Call this to start the sim */
        void init();
        void printMenu();
        void printHelp();
        void printStats();
        void makeOffer();
        void makeBid();
        void printWallet();
        void goToNextTimeFrame();
        // funkcja interakcji z użytkownikiem
        int getUserOption();
        /**  funkcja warunków */
        void processUserOptions(int userOption);
};


