package com.chess;
import java.util.ArrayList;
import java.util.List;
public class Bishop extends Piece {
     public Bishop(Color color, Position pos) {
        super(color, pos);
    }

    @Override
    public List<Position> possibleMoves(Board board) {
        List<Position> moves = new ArrayList<>();
        int[] dr = {1,1,-1,-1};
        int[] dc = {1,-1,1,-1};
        Position p = getPosition();
        for (int k=0;k<4;k++) {
            int r = p.getRow() + dr[k];
            int c = p.getCol() + dc[k];
            while (r>=0 && r<8 && c>=0 && c<8) {
                Piece piece = board.getPiece(r,c);
                Position np = new Position(r,c);
                if (piece == null) {
                    moves.add(np);
                } else {
                    if (piece.getColor() != getColor()) moves.add(np);
                    break;
                }
                r += dr[k];
                c += dc[k];
            }
        }
        return moves;
    }

    @Override
    public String getSymbol() {
        return getColor() == Color.WHITE ? "♗" : "♝";
    }

    @Override
    public Piece copy() {
        return new Bishop(getColor(), getPosition().copy());
    }
}
