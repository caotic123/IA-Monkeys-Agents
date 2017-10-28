#include "agent.h"

#include "interface.h"
#include "AI.H"

int main(int argc, char** argv)
{
    char cons_[1000] = "";
    srand(time(NULL));
    int x = 100;
    int i = 0;
    std::string __, conf;
    int a___ = 0, agents__ = 0, predator____ = 0, rb____ = 16, ra____ = 10,
        it____ = 0;
    bool graph;
    interface_* screen;
    AI* ___AI;

    printf("                            AI - Intelligent Agents\n");
    std::cout << "This project of IA and principally intelligent agents has the "
                 "purpose of\nto study the factors, standards, math calcs, "
                 "behavior and logic in imperative language of programming."
              << std::endl;

    printf("What configuration you want? \"normal\" or \"higher\"\n");
    std::cin >> conf;
    if (conf == "higher" or conf == "HIGHER") {
        printf("Set area of precision of monkey vision!(only intenger number)\n");
        while (!getInt_Input(rb____)) {
            printf("Please digit one new valid number (intenger) \n");
        }
        printf("Set area of precision of monkey alert!(only intenger number)\n");
        while (!getInt_Input(ra____)) {
            printf("Please digit one new valid number (intenger) \n");
        }
    }

    printf(
        "Please define the area of your agents will be to insired (only one "
        "intenger number)");
    while (!getInt_Input(a___)) {
        printf("Please digit one new valid number (intenger) \n");
    }
    printf(
        "Please define the number of agents will be to insired its strongly "
        "recommend one number in between (1 and 10)\nCase number its higher of "
        "10 the mini-display don't show all monkeys only of\n firsts ten (only "
        "one intenger number)");

    while (!getInt_Input(agents__)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf(
        "Please define the number of predators will be to insired its strongly "
        "recommend one number in between (1 and 10) (only one intenger number)");

    while (!getInt_Input(predator____)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf("Please define the number of iterations\n");

    while (!getInt_Input(it____)) {
        printf("Please digit one new valid number (intenger) \n");
    }

    printf("Active mode graphical?\n");
    std::cin >> __;
    if (__ == "true" || __ == "TRUE" || __ == "YES" || __ == "yes") {
        graph = true;
        printf("Mode graphical actived\n");
    }
    else {
        graph = false;
        printf("Mode graphical OFF\n");
    }

    screen = new interface_;
    ___AI = new AI;
    if (graph) {
        ___AI->set___graphics_(screen);
    }
    ___AI->init___p(a___, agents__, ra____, rb____, predator____, graph);
    for (i = 0; i < it____;) {
        ___AI->interact___();
        i++;
    }
    ___AI->_statistics(cons_, true);
    printf("%s\n", cons_);

    if (graph) {
        screen->close___();
    }

    printf("Enter whatever key of to continue\n");
    delete ___AI;
    system("pause");

    return 0;
}
