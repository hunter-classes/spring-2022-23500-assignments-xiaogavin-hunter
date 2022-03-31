#include "Labyrinth.h"



bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    /* TODO: Delete this comment and the remaining lines, then implement this function. */
    bool found_spell = false;
    bool found_potion = false;
    bool found_wand = false;    

    for(int i = 0; i < moves.length(); i++) {
        switch(moves[i]) { 
            case 'N': 
                start = start->north;
                break;
            case 'E':
                start = start->east;
                break;
            case 'S':
                start = start->south;
                break;
            case 'W':
                start = start->west;
                break;
        }

        if(start->whatsHere != Item::NOTHING) { 
            switch(start->whatsHere) { 
                case Item::POTION:
                    found_potion = true;
                    break;
                case Item::SPELLBOOK:
                    found_spell = true;
                    break;
                case Item::WAND:
                    found_wand = true;
                    break;
            }
        } 
    }

    return found_potion && found_spell && found_wand;
}