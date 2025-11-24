package com.chess;
import java.util.List;
public abstract class Piece {
    private Color color;
    private Position position;

    public Piece(Color color, Position position) {
        this.color = color;
        this.position = position;
    }

    public Color getColor() { return color; }
    public Position getPosition() { return position; }
    public void setPosition(Position pos) { this.position = pos; }

    // Each piece defines legal moves disregarding king self-check (validated later)
    public abstract List<Position> possibleMoves(Board board);

    // Symbol for display in Swing
    public abstract String getSymbol();

    // Used for cloning the board
    public abstract Piece copy();

    // Helper: same color?
    public boolean isOpponent(Piece other) {
        return other != null && other.getColor() != this.color;
    }
}
