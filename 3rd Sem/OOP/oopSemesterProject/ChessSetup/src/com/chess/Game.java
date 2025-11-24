package com.chess;
import java.util.ArrayList;
import java.util.List;
public class Game {
    private Board board;
    private Color turn;
    private boolean gameOver;
    private Color winner; // null if none yet
    private List<String> moveHistory = new ArrayList<>();

    public Game() {
        newGame();
    }

    public void newGame() {
        board = new Board();
        turn = Color.WHITE;
        gameOver = false;
        winner = null;
        moveHistory.clear();
        setupInitialPosition();
    }

    private void setupInitialPosition() {
        // Black back rank (row 0)
        board.setPiece(0, 0, new Rook(Color.BLACK, new Position(0,0)));
        board.setPiece(0, 1, new Knight(Color.BLACK, new Position(0,1)));
        board.setPiece(0, 2, new Bishop(Color.BLACK, new Position(0,2)));
        board.setPiece(0, 3, new Queen(Color.BLACK, new Position(0,3)));
        board.setPiece(0, 4, new King(Color.BLACK, new Position(0,4)));
        board.setPiece(0, 5, new Bishop(Color.BLACK, new Position(0,5)));
        board.setPiece(0, 6, new Knight(Color.BLACK, new Position(0,6)));
        board.setPiece(0, 7, new Rook(Color.BLACK, new Position(0,7)));
        // Black pawns row 1
        for (int c=0;c<8;c++) board.setPiece(1, c, new Pawn(Color.BLACK, new Position(1,c)));
        // Empty rows 2..5 implicit
        // White pawns row 6
        for (int c=0;c<8;c++) board.setPiece(6, c, new Pawn(Color.WHITE, new Position(6,c)));
        // White back rank row 7
        board.setPiece(7, 0, new Rook(Color.WHITE, new Position(7,0)));
        board.setPiece(7, 1, new Knight(Color.WHITE, new Position(7,1)));
        board.setPiece(7, 2, new Bishop(Color.WHITE, new Position(7,2)));
        board.setPiece(7, 3, new Queen(Color.WHITE, new Position(7,3)));
        board.setPiece(7, 4, new King(Color.WHITE, new Position(7,4)));
        board.setPiece(7, 5, new Bishop(Color.WHITE, new Position(7,5)));
        board.setPiece(7, 6, new Knight(Color.WHITE, new Position(7,6)));
        board.setPiece(7, 7, new Rook(Color.WHITE, new Position(7,7)));
    }

    public Board getBoard() { return board; }
    public Color getTurn() { return turn; }
    public boolean isGameOver() { return gameOver; }
    public Color getWinner() { return winner; }
    public List<String> getMoveHistory() { return moveHistory; }

    // Attempt a move, returns message (null if success)
    public String makeMove(Move move) {
        if (gameOver) return "Game is over.";

        Position from = move.getFrom();
        Position to = move.getTo();
        if (from == null || to == null) return "Invalid coordinates.";

        Piece p = board.getPiece(from.getRow(), from.getCol());
        if (p == null) return "No piece at source.";
        if (p.getColor() != turn) return "It's " + turn + "'s turn.";

        // Does piece have that target in its possible moves?
        boolean allowed = false;
        for (Position pos : p.possibleMoves(board)) {
            if (pos.getRow() == to.getRow() && pos.getCol() == to.getCol()) { allowed = true; break; }
        }
        if (!allowed) return "Piece cannot move like that.";

        // Simulate move on a copy to check if king would be in check after move
        Board copy = board.copy();
        copy.movePiece(from, to);
        if (isKingInCheck(turn, copy)) {
            return "Illegal move: would leave king in check.";
        }

        // Apply the move to real board
        Piece captured = board.getPiece(to.getRow(), to.getCol());
        board.movePiece(from, to);
        // Pawn promotion (auto-queen) if reached last rank
        Piece moved = board.getPiece(to.getRow(), to.getCol());
        if (moved instanceof Pawn) {
            int lastRow = (moved.getColor() == Color.WHITE) ? 0 : 7;
            if (to.getRow() == lastRow) {
                board.setPiece(to.getRow(), to.getCol(), new Queen(moved.getColor(), to));
            }
        }

        moveHistory.add(p.getSymbol() + from.toAlgebraic() + "-" + to.toAlgebraic());

        // Check for checkmate after turn switch
        turn = turn.opposite();
        if (isKingInCheck(turn, board)) {
            if (isCheckmate(turn)) {
                gameOver = true;
                winner = turn.opposite();
                return "Checkmate! " + winner + " wins.";
            } else {
                return "Check!";
            }
        } else {
            // if no legal moves and not in check => stalemate (we'll treat as draw and game over)
            if (!hasAnyLegalMove(turn)) {
                gameOver = true;
                winner = null;
                return "Stalemate. Draw.";
            }
        }

        return null; // success, no special message
    }

    // is the color's king in check on the given board
    public boolean isKingInCheck(Color color, Board brd) {
        Position kingPos = findKing(color, brd);
        if (kingPos == null) return false; // shouldn't happen
        // for each opponent piece, see if it can move to king
        for (int r=0;r<8;r++) {
            for (int c=0;c<8;c++) {
                Piece p = brd.getPiece(r,c);
                if (p != null && p.getColor() != color) {
                    for (Position mv : p.possibleMoves(brd)) {
                        if (mv.getRow()==kingPos.getRow() && mv.getCol()==kingPos.getCol()) return true;
                    }
                }
            }
        }
        return false;
    }

    private Position findKing(Color color, Board brd) {
        for (int r=0;r<8;r++) for (int c=0;c<8;c++) {
            Piece p = brd.getPiece(r,c);
            if (p != null && p instanceof King && p.getColor() == color) return new Position(r,c);
        }
        return null;
    }

    // does the player have any legal move?
    public boolean hasAnyLegalMove(Color color) {
        for (int r=0;r<8;r++) for (int c=0;c<8;c++) {
            Piece p = board.getPiece(r,c);
            if (p != null && p.getColor() == color) {
                for (Position to : p.possibleMoves(board)) {
                    Board copy = board.copy();
                    copy.movePiece(p.getPosition(), to);
                    if (!isKingInCheck(color, copy)) return true;
                }
            }
        }
        return false;
    }

    // checkmate detection: color is in check and has no legal moves
    public boolean isCheckmate(Color color) {
        if (!isKingInCheck(color, board)) return false;
        return !hasAnyLegalMove(color);
    }
}
