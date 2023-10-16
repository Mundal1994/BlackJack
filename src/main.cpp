#include "BlackJack.hpp"

int main(void) {
    BlackJack game {BlackJack()};
    bool keepPlaying = true;

    while (keepPlaying) {
        game.start();
        bool decide = false;
        while (!decide) {
            std::cout << "Play again? (a = again, q = quit):" << std::endl;
            std::string playAgain;
            std::cin >> playAgain;
            if (playAgain == "a") {
                decide = true;
                game.restart();
            } else if (playAgain == "q") {
                decide = true;
                keepPlaying = false;
            }
        }
    }
    return 0;
}
