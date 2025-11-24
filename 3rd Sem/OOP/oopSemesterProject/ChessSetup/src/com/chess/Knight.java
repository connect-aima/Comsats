package com.chess;
import java.util.ArrayList;
import java.util.List;
public class Knight extends Piece {
    public Knight(Color color, Position pos) {
        super(color, pos);
    }

    @Override
    public List<Position> possibleMoves(Board board) {
        List<Position> moves = new ArrayList<>();
        int[] dr = {2,2,-2,-2,1,-1,1,-1};
        int[] dc = {1,-1,1,-1,2,2,-2,-2};
        Position p = getPosition();
        for (int k=0;k<8;k++) {
            int r = p.getRow() + dr[k];
            int c = p.getCol() + dc[k];
            Position np = new Position(r,c);
            if (!np.isValid()) continue;
            Piece t = board.getPiece(r,c);
            if (t == null || t.getColor() != getColor()) moves.add(np);
        }
        return moves;
    }

    @Override
    public String getSymbol() {
        return getColor() == Color.WHITE ? "♘" : "♞";
    }

    @Override
    public Piece copy() {
        return new Knight(getColor(), getPosition().copy());
    }
}
