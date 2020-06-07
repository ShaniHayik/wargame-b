#include "Board.hpp"
#include <iostream>
using namespace std;

namespace WarGame {

    Soldier *&Board::operator[](pair<int, int> location) {
        return board[location.first][location.second];
    }

    Soldier *Board::operator[](pair<int, int> location) const {
        return board[location.first][location.second];
    }



    void Board::move(uint player_number, pair<int, int> source, MoveDIR direction) {
        if(source.first<0 || source.first>=board.size()|| source.second<0 || source.second>=board[source.first].size()) {
            throw invalid_argument("Action is forbidden,out of Board");
        }
        Soldier* toMove = (*this)[source];
        std::pair<int,int> target;
        if(target.first<0 || target.first>=board.size()|| target.second<0 || target.second>=board[target.first].size()) {
            throw invalid_argument("Action is forbidden,out of Board");
        }
        if(toMove == nullptr || toMove->get_player_number()!=player_number || (*this)[target]!= nullptr){

            throw invalid_argument("Action is forbidden a");
        }
    }



//        if(source.first >= board.size() || source.first < 0 || source.second >= board.size() || source.second < 0) {
//            throw invalid_argument("Outside of the board");
//        }
//
//
//        Soldier *solider = (*this)[source];
//        pair<int, int> new_place;
//
//        if (solider==nullptr || solider->get_player_number() != player_number)
//            throw invalid_argument(" player number not found ");
////
////        if (direction == Up) {
////            new_place = make_pair(source.first + 1, source.second);
////        }
////
////        if (direction == Left) {
////            new_place = make_pair(source.first, source.second - 1);
////        }
////
////        if (direction == Right) {
////            new_place = make_pair(source.first, source.second + 1);
////        }
////        if (direction == Down) {
////            new_place = make_pair(source.first - 1, source.second);
////        }
////
//        if (new_place.first >= board.size() || new_place.first < 0 || new_place.second >= board.size() || new_place.second < 0)
//            throw invalid_argument("Outside of the board");	(*this)[source] = nullptr;
////
////
////        (*this)[source] = nullptr;
////        (*this)[new_place] = solider;
////        solider->playS(board, new_place);
//    }


    bool Board::has_soldiers(uint player_number) const {
        for(int i= 0; i< board.size(); ++i){
            for(int j=0; j< board[i].size(); ++j) {
                Soldier* s = (*this)[{i, j}];
                if (s != nullptr && s->get_player_number() == player_number)
                    return true;
            }
        }
        return false;
    }

}



