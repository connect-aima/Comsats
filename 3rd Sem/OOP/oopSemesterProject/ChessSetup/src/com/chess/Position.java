package com.chess;

public class Position {
    private int row; // 0..7, 0 is top (black's back rank)
    private int col; // 0..7, 0 is 'a' file

    public Position(int row, int col) {
        this.row = row;
        this.col = col;
    }

    public int getRow() { return row; }
    public int getCol() { return col; }

    public boolean equals(Position o) {
        if (o == null) return false;
        return this.row == o.row && this.col == o.col;
    }

    public boolean isValid() {
        return row >= 0 && row < 8 && col >= 0 && col < 8;
    }

    public Position copy() {
        return new Position(row, col);
    }

    public static Position fromAlgebraic(String s) {
        if (s == null || s.length() != 2) return null;
        int col = s.charAt(0) - 'a';
        int row = 8 - Character.getNumericValue(s.charAt(1)); // '1' -> row 7
        Position p = new Position(row, col);
        return p.isValid() ? p : null;
    }

    public String toAlgebraic() {
        char file = (char) ('a' + col);
        int rank = 8 - row;
        return "" + file + rank;
    }
}
