#include "catch.hpp"
#include <vector>

class Piece {}; // minimal stub

int findPieceIndex(std::vector<Piece*> Pieces, Piece* piece) {
    int count = 0;
    for (int i = 0; i < (int)Pieces.size(); i++) {
        if (piece == Pieces[i]) {
            return count;
        }
        count++;
    }
    return -1; // updated behavior
}

TEST_CASE(test_find_existing_piece) {
    Piece a, b, c;
    std::vector<Piece*> pieces = { &a, &b, &c };
    REQUIRE(findPieceIndex(pieces, &b) == 1);
}

TEST_CASE(test_find_missing_piece) {
    Piece a, b, c, d;
    std::vector<Piece*> pieces = { &a, &b, &c };
    REQUIRE(findPieceIndex(pieces, &d) == -1);
}

CATCH_CONFIG_MAIN
