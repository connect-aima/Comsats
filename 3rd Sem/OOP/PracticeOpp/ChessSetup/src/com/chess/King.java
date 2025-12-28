package com.chess;
import java.util.ArrayList;
import java.util.List;
public class King extends Piece {
    public King(Color color, Position pos) {
        super(color, pos);
    }

    @Override
    public List<Position> possibleMoves(Board board) {
        List<Position> moves = new ArrayList<>();
        Position p = getPosition();
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int r = p.getRow() + dr;
                int c = p.getCol() + dc;
                Position np = new Position(r, c);
                if (!np.isValid()) continue;
                Piece t = board.getPiece(r, c);
                if (t == null || t.getColor() != getColor()) {
                    moves.add(np);
                }
            }
        }
        // (castling omitted)
        return moves;
    }

    @Override
    public String getSymbol() {
        return getColor() == Color.WHITE ? "♔" : "♚";
    }

    @Override
    public Piece copy() {
        return new King(getColor(), getPosition().copy());
    }
}
