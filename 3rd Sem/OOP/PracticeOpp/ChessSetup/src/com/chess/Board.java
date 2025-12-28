package com.chess;

    public class Board {
    private Piece[][] grid = new Piece[8][8];

    public Board() { }

    public Piece getPiece(int row, int col) {
        if (row < 0 || row >= 8 || col < 0 || col >= 8) return null;
        return grid[row][col];
    }

    public void setPiece(int row, int col, Piece p) {
        grid[row][col] = p;
        if (p != null) p.setPosition(new Position(row, col));
    }

    public void setPiece(Position pos, Piece p) {
        setPiece(pos.getRow(), pos.getCol(), p);
    }

    public void movePiece(Position from, Position to) {
        Piece p = getPiece(from.getRow(), from.getCol());
        setPiece(to.getRow(), to.getCol(), p);
        setPiece(from.getRow(), from.getCol(), null);
        if (p != null) p.setPosition(to);
    }

    public Board copy() {
        Board nb = new Board();
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece p = this.getPiece(r,c);
                if (p != null) nb.setPiece(r, c, p.copy());
            }
        }
        return nb;
    }
}
