package com.chess;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.Color;
public class ChessUI extends JFrame {
    private Game game;
    private JButton[][] squares = new JButton[8][8];
    private Position selected = null;
    private JLabel statusLabel = new JLabel("Welcome to Chess. White to move.");
    private JTextArea historyArea = new JTextArea(8, 20);

    public ChessUI() {
        super("Java Chess - Swing");
        game = new Game();
        initUI();
        refreshBoard();
    }

    private void initUI() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(800, 600);
        setLayout(new BorderLayout());

        JPanel boardPanel = new JPanel(new GridLayout(8,8));
        boardPanel.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        for (int r=0;r<8;r++) {
            for (int c=0;c<8;c++) {
                JButton btn = new JButton();
                btn.setFont(new Font("SansSerif", Font.PLAIN, 36));
                btn.setFocusPainted(false);
                final int rr = r, cc = c;
                btn.addActionListener(e -> onSquareClick(rr, cc));
                Color bg = ((r + c) % 2 == 0) ? new Color(240, 217, 181) : new Color(181, 136, 99);
                btn.setBackground(bg);
                squares[r][c] = btn;
                boardPanel.add(btn);
            }
        }
        add(boardPanel, BorderLayout.CENTER);

        JPanel right = new JPanel(new BorderLayout());
        JPanel topRight = new JPanel(new GridLayout(3,1));
        topRight.add(statusLabel);
        JButton newBtn = new JButton("New Game");
        newBtn.addActionListener(e -> {
            game.newGame();
            selected = null;
            refreshBoard();
            statusLabel.setText("New game. White to move.");
            historyArea.setText("");
        });
        topRight.add(newBtn);
        topRight.add(new JLabel("Move History:"));
        right.add(topRight, BorderLayout.NORTH);

        historyArea.setEditable(false);
        JScrollPane sp = new JScrollPane(historyArea);
        right.add(sp, BorderLayout.CENTER);

        add(right, BorderLayout.EAST);

        setVisible(true);
    }


    private void onSquareClick(int r, int c) {
        if (game.isGameOver()) {
            JOptionPane.showMessageDialog(this, "Game over. Start a new game.");
            return;
        }
        Position pos = new Position(r, c);
        Piece p = game.getBoard().getPiece(r, c);

        // CASE 1: No piece is currently selected
        if (selected == null) {
            if (p == null) {
                statusLabel.setText("Select a piece to move.");
                return;
            }
            if (p.getColor() != game.getTurn()) {
                statusLabel.setText("It's " + game.getTurn() + "'s turn.");
                return;
            }

            // 1. Select the piece
            selected = pos;
            statusLabel.setText("Selected " + p.getSymbol() + " at " + pos.toAlgebraic());

            // 2. Highlight the piece itself (Yellow)
            squares[r][c].setBackground(Color.YELLOW);

            // 3. Highlight LEGAL moves (Green)
            // We iterate through the piece's possible moves
            for (Position move : p.possibleMoves(game.getBoard())) {
                // Optional: You could check here if the move puts king in check
                // to only highlight strictly legal moves.
                squares[move.getRow()][move.getCol()].setBackground(new Color(144, 238, 144)); // Light Green
            }

        } else {
            // CASE 2: A piece is already selected, so this click is the destination
            Move mv = new Move(selected, pos);
            String msg = game.makeMove(mv);

            selected = null;
            clearHighlights(); // This cleans up the Green/Yellow squares
            refreshBoard();
            updateHistory();

            if (msg != null) {
                statusLabel.setText(msg);
                if (msg.startsWith("Checkmate") || msg.contains("Stalemate")) {
                    JOptionPane.showMessageDialog(this, msg);
                }
            } else {
                statusLabel.setText(game.getTurn() + " to move.");
            }
        }
    }

    private void highlightSelected(int r, int c, boolean on) {
        if (on) {
            squares[r][c].setBackground(Color.YELLOW);
        } else {
            Color bg = ((r + c) % 2 == 0) ? new Color(240, 217, 181) : new Color(181, 136, 99);
            squares[r][c].setBackground(bg);
        }
    }

    private void clearHighlights() {
        for (int r=0;r<8;r++) for (int c=0;c<8;c++) highlightSelected(r,c,false);
    }

    // Update this method in ChessUI.java
    private void refreshBoard() {
        Board b = game.getBoard();
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                Piece p = b.getPiece(r, c);
                JButton btn = squares[r][c];

                // Clear previous content
                btn.setText("");
                btn.setIcon(null);

                if (p != null) {
                    // Determine the image file name based on color and type
                    String fileName = getPieceImageName(p);

                    // Load the image
                    // NOTE: This assumes you have a 'resources' folder in your classpath
                    java.net.URL imgURL = getClass().getResource("/resources/" + fileName);

                    if (imgURL != null) {
                        ImageIcon icon = new ImageIcon(imgURL);
                        // Scale image to fit button (optional but recommended)
                        Image img = icon.getImage().getScaledInstance(60, 60, Image.SCALE_SMOOTH);
                        btn.setIcon(new ImageIcon(img));
                    } else {
                        // Fallback to text if image is missing (Robustness)
                        btn.setText(p.getSymbol());
                        btn.setForeground(p.getColor() == com.chess.Color.WHITE ? Color.WHITE : Color.BLACK);
                    }
                }
            }
        }
        updateHistory();
    }

    // Add this HELPER method to ChessUI.java
// This converts the Object data into a filename string
    private String getPieceImageName(Piece p) {
        // We use 'com.chess.Color' to be specific
        String colorPrefix = (p.getColor() == com.chess.Color.WHITE) ? "w" : "b";
        String pieceType = "";

        // We use 'instanceof' to determine the specific subclass
        if (p instanceof Pawn) pieceType = "pawn";
        else if (p instanceof Rook) pieceType = "rook";
        else if (p instanceof Knight) pieceType = "knight";
        else if (p instanceof Bishop) pieceType = "bishop";
        else if (p instanceof Queen) pieceType = "queen";
        else if (p instanceof King) pieceType = "king";

        return colorPrefix + "-" + pieceType + ".png";
    }

    private void updateHistory() {
        StringBuilder sb = new StringBuilder();
        for (String s : game.getMoveHistory()) {
            sb.append(s).append("\n");
        }
        historyArea.setText(sb.toString());
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new ChessUI());
    }
}

// javac -d out src\com\chess\*.java
// java -cp out com.chess.ChessUI