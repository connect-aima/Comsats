package com.chess;
import java.util.ArrayList;
import java.util.List;
public class Pawn extends Piece{
    public Pawn(Color color, Position pos) {
        super(color, pos);
    }

    @Override
    public List<Position> possibleMoves(Board board) {
        List<Position> moves = new ArrayList<>();
        int dir = (getColor() == Color.WHITE) ? -1 : 1;
        Position p = getPosition();
        int r = p.getRow();
        int c = p.getCol();

        // one step forward
        Position p1 = new Position(r + dir, c);
        if (p1.isValid() && board.getPiece(p1.getRow(), p1.getCol()) == null) {
            moves.add(p1);
            // two steps from starting row
            int startRow = (getColor() == Color.WHITE) ? 6 : 1;
            Position p2 = new Position(r + 2 * dir, c);
            if (r == startRow && p2.isValid() && board.getPiece(p2.getRow(), p2.getCol()) == null) {
                moves.add(p2);
            }
        }

        // captures
        Position capL = new Position(r + dir, c - 1);
        Position capR = new Position(r + dir, c + 1);
        if (capL.isValid()) {
            Piece t = board.getPiece(capL.getRow(), capL.getCol());
            if (t != null && t.getColor() != getColor()) moves.add(capL);
        }
        if (capR.isValid()) {
            Piece t = board.getPiece(capR.getRow(), capR.getCol());
            if (t != null && t.getColor() != getColor()) moves.add(capR);
        }
        return moves;
    }

    @Override
    public String getSymbol() {
        return getColor() == Color.WHITE ? "♙" : "♟";
    }

    @Override
    public Piece copy() {
        return new Pawn(getColor(), getPosition().copy());
    }
}
